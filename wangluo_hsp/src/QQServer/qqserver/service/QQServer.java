package QQServer.qqserver.service;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.concurrent.ConcurrentHashMap;

import QQClient.qqcommon.MessageType;
import QQClient.qqcommon.User;
import QQServer.qqcommon.Message;

/**
 * 服务器，监听9999，等待客户端的连接，并保持通信
 */
public class QQServer {
    private ServerSocket ss = null;
    //创建一个集合，存放多个用户，如果是这些用户登陆，就认为是合法的
    //也可以使用ConcurrentHashMap，可以处理并发的集合
    //HashMap没有处理线程安全，因此在多线程情况下不安全
    //ConcurrentHashMap处理的线程安全，即线程同步处理，在多线程下是安全的
    private static ConcurrentHashMap<String,User> validUsers = new ConcurrentHashMap<>();
    // private static ConcurrentHashMap<String,ArrayList<Message>> offlineDb = new ConcurrentHashMap<>(); //离线发消息需要的


    static { //在静态代码块，初始化validUsers
        validUsers.put("100", new User("100","123"));
        validUsers.put("200", new User("200","123"));
        validUsers.put("mike", new User("mike","123"));
        validUsers.put("david", new User("david","123"));
        validUsers.put("lucas", new User("lucas","123"));

    }

    //验证用户是否有效的方法
    private boolean checkUser(String userId,String passwd){

        User user = validUsers.get(userId);
        //过关的验证方式
        if(userId == null){ //说明userId不存在
            return false;
        }
        if(!(user.getPasswd().equals(passwd))){ //userId正确，密码错误
            return false;
        }
        return true;
    }
    
    public QQServer(){
        try {
            System.out.println("服务端在9999端口监听");

            //启动推送新闻的线程
            new Thread(new SendNewsToAllService()).start();

            ss = new ServerSocket(9999);
            while(true){//当和某个客户端连接后，会继续监听，因此while
                Socket socket = ss.accept();
                //得到socket关联的对象输入流
                ObjectInputStream ois = new ObjectInputStream(socket.getInputStream());
                
                //得到socket关联的对象输出流
                ObjectOutputStream oos = new ObjectOutputStream(socket.getOutputStream());
                User u = (User) ois.readObject();//读取客户端发送的User对象
                //创建一个Messgae对象，准备回复客户端
                Message message = new Message();                
                //验证
                if(checkUser(u.getUserId(), u.getPasswd())){ //合法
                    message.setMesType(MessageType.MESSAGE_LOGIN_SUCCEED);
                    //将message对象回复客户端
                    oos.writeObject(message);

                    //创建一个线程，和客户端保持通信，该线程需要持有socket对象
                    ServerConnectClientThread serverConnectClientThread = new ServerConnectClientThread(socket,u.getUserId());
                    //启动该线程
                    serverConnectClientThread.start();
                    //把该线程对象，放入集合中，进行管理
                    ManageClientThreads.addClientThread(u.getUserId(),serverConnectClientThread);

                } else { //登陆失败
                    System.out.println("用户 id="+u.getUserId()+" pwd="+u.getPasswd()+" 验证失败");
                    message.setMesType(MessageType.MESSAGE_LOGIN_Fail);
                    oos.writeObject(message);
                    //关闭socket
                    socket.close();
                }

            }

        } catch (Exception e) {
            
            e.printStackTrace();
        } finally{
            //如果服务端退出了while，说明服务器端不再监听，因此需要关闭ServerSocket
            try {
                ss.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }

    }
}