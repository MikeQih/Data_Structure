package QQServer.qqserver.service;

import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;
import java.util.HashMap;
import java.util.Iterator;

import QQClient.qqcommon.MessageType;
import QQClient.qqcommon.Message;
// import QQClient.qqcommon.Message;

/**
 * 该类的一个对象和某个客户端保持通讯
 */
public class ServerConnectClientThread extends Thread{
    private Socket socket;
    private String userId; //连接到服务端的用户id

    public ServerConnectClientThread(Socket socket, String userId) {
        this.socket = socket;
        this.userId = userId;
    }

    public Socket getSocket() {
        return socket;
    }
    
    @Override
    public void run() { //这里线程处于run的状态，可以发送/接收消息
        while(true){
            try {
                System.out.println("服务端和客户端"+userId+" 保持通讯，读取数据...");
                ObjectInputStream ois = new ObjectInputStream(socket.getInputStream());
                Message message = (Message) ois.readObject();
                if(message.getMesType().equals(MessageType.MESSAGE_GET_ONLINE_FRIEND)){
                    //客户端要在线用户列表
                    /*
                     * 形式 eg：100 200 mike
                     */
                    System.out.println(message.getSender()+" 要在线用户列表");
                    String onlineUser = ManageClientThreads.getOnlineUser();
                    //构建一个Message对象，返回客户端
                    Message message2 = new Message();
                    message2.setMesType(MessageType.MESSAGE_RET_ONLINE_FRIEND);
                    message2.setContent(onlineUser);
                    message2.setGetter((message.getSender()));
                    //返回给客户端
                    ObjectOutputStream oos = new ObjectOutputStream(socket.getOutputStream());
                    oos.writeObject(message2);


                } else if(message.getMesType().equals(MessageType.MESSAGE_COMM_MES)){
                    //根据message获取getterid，再得到对应的线程
                    ServerConnectClientThread serverConnectClientThread = ManageClientThreads.getServerConnectClientThread(message.getGetter());
                    ObjectOutputStream oos = new ObjectOutputStream(serverConnectClientThread.getSocket().getOutputStream());
                    oos.writeObject(message); //如果客户不在线，可以保存到数据库，就可实现离线留言
                } else if(message.getMesType().equals(MessageType.MESSAGE_TO_ALL_MES)){
                    //需要遍历管理线程的集合，把所有线程的socket得到，再把message进行转发即可
                    HashMap<String,ServerConnectClientThread> hm = ManageClientThreads.getHm();
                    Iterator<String> iterator = hm.keySet().iterator();
                    while(iterator.hasNext()){
                        //取出在线用户id
                        String onlineUserId = iterator.next().toString();
                        if(!onlineUserId.equals(message.getSender())){ //排除群发消息的用户本人
                            ObjectOutputStream oos = new ObjectOutputStream(hm.get(onlineUserId).getSocket().getOutputStream());
                            oos.writeObject(message);
                        }

                    }
                } else if(message.getMesType().equals(MessageType.MESSAGE_FILE_MES)){
                    //根据getterid 获取到对应的线程，将message对象转发
                    ServerConnectClientThread serverConnectClientThread = ManageClientThreads.getServerConnectClientThread(message.getGetter());
                    ObjectOutputStream oos = new ObjectOutputStream(serverConnectClientThread.getSocket().getOutputStream());
                    //转发
                    oos.writeObject(message);

                } else if(message.getMesType().equals(MessageType.MESSAGE_CLIENT_EXIT)){ //客户端退出
                    System.out.println(message.getSender()+" 退出");
                    //将客户端对应线程，从集合中删除
                    ManageClientThreads.removeServerConnectClientThread(message.getSender());
                    socket.close(); //关闭连接
                    break; //退出线程(循环)

                } else{
                    System.out.println("其他类型的message，暂时不处理");
                }


            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }
}
