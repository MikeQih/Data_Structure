package QQClient.qqclient.service;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.InetAddress;
import java.net.Socket;

import QQClient.qqcommon.User;

import QQServer.qqcommon.Message;
// import QQClient.qqcommon.Message;
import QQServer.qqcommon.MessageType;

/**
 * 该类完成用户登录验证和用户注册等功能
 */
public class UserClientService {
    //可能在其他地方需使用user信息，因此作成成员属性
    private User u = new User();
    private Socket socket;

    //根据userId和pwd到服务器验证该用户是否合法
    public boolean checkUser(String userId,String pwd){
        boolean b = false;
        //创建User对象
        u.setUserId(userId);
        u.setPasswd(pwd);
        //连接到服务端，发送u对象
        try{
            socket = new Socket(InetAddress.getByName("127.0.0.1"), 9999); //本地 127.0.0.1
            //得到ObjectOutputStream对象
            ObjectOutputStream oos = new ObjectOutputStream(socket.getOutputStream());
            oos.writeObject(u); //发送user对象(这一步是把User对象发给服务端)

            //读取从服务端回复的Messgae对象
            ObjectInputStream ois = new ObjectInputStream(socket.getInputStream());
            Message ms = (Message) ois.readObject();
            // QQClient.qqcommon.Message ms = (QQClient.qqcommon.Message) ois.readObject();
            if(ms.getMesType().equals(MessageType.MESSAGE_LOGIN_SUCCEED)){ //登陆成功

                //创建一个和服务器端保持通信的线程->创建一个类 ClientConnectServerThread 
                ClientConnectServerThread clientConnectServerThread = new ClientConnectServerThread(socket);
                //启动客户端的线程
                clientConnectServerThread.start();
                //这里为了后面客户端的扩展，将线程放入一个集合管理

                ManageClientConnectServiceThread.addClientConnectServerThread(userId, clientConnectServerThread);
                b = true;

            } else {
                //如果登陆失败，就不能启动和服务器通信的线程，关闭socket
                socket.close();
            }
        
        } catch(Exception e){
            e.printStackTrace();
        }
        return b;

    }
    
    //向服务器端请求在线用户列表
    public void onlineFriendList(){
        //发送一个Message，类型MESSAGE_GET_ONLINE_FRIEND
        Message message = new Message();
        message.setMesType(MessageType.MESSAGE_GET_ONLINE_FRIEND);
        message.setSender(u.getUserId());

        //发送给服务器
        try {
            //应得到当前线程的Socket对应的ObjectOutputStream对象 (从线程集合拿到对应线程，然后拿到socket，再拿到outputstream)
            ObjectOutputStream oos = new ObjectOutputStream(ManageClientConnectServiceThread.getClientConnectServerThread(u.getUserId()).getSocket().getOutputStream());
            oos.writeObject(message); //发送一个Message对象，向服务端要在线用户列表
        
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    //编写方法，退出客户端，并给服务端发送一个退出系统的message对象
    public void logout(){
        Message message = new Message();
        message.setMesType(MessageType.MESSAGE_CLIENT_EXIT);
        message.setSender(u.getUserId()); //要指定我是哪个客户端id

        //发送message
        try {
            // ObjectOutputStream oos = new ObjectOutputStream(socket.getOutputStream()); //m1
            ObjectOutputStream oos = new ObjectOutputStream(ManageClientConnectServiceThread.getClientConnectServerThread(u.getUserId()).getSocket().getOutputStream());
            oos.writeObject(message);
            System.out.println(u.getUserId()+" 退出系统 ");
            System.exit(0); //结束进程
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    
}
