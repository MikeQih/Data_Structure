import java.io.IOException;
import java.io.InputStream;
import java.net.ServerSocket;
import java.net.Socket;

public class eg1_Server  {
    public static void main(String[] args) throws IOException {
        //思路：
        //1.在本机的9999端口监听，等待连接
        //(要求在本机没有其他服务在监听9999；ServerSocket可以通过accept() 返回多个Socket -> 多个客户端连接服务器的并发)
        ServerSocket serverSocket = new ServerSocket(9999);
        System.out.println("服务器，在9999端口监听，等待连接。。。");

        //2.当没有客户端连接9999端口时，程序会阻塞，等待连接
        //如果有客户端连接，则会返回Socket对象，程序继续
        Socket socket = serverSocket.accept();
        System.out.println("服务端 socket = "+socket.getClass());

        //3.通过socket.getInputStreeam()读取客户端写入到数据通道的数据，显示
        InputStream inputStream = socket.getInputStream();

        //4.IO读取
        byte[] buf = new byte[1024];
        int readLen = 0;
        while((readLen = inputStream.read(buf)) != -1){
            System.out.println(new String(buf,0,readLen)); //根据读到的实际长度，显示内容
        }

        //5.关闭流和socket
        inputStream.close();
        socket.close();
        serverSocket.close(); //serverSocket可以创建很多socket
    }
}
//服务端

//网络编程 server端先跑起来
//(难点：同时写客户端和服务端两头，IO流)
