import java.io.IOException;
import java.io.OutputStream;
import java.net.InetAddress;
import java.net.Socket;

public class eg1_Client {
    public static void main(String[] args) throws IOException {
        //思路
        //1.连接服务端(ip，端口)
        //连接本机的9999端口，如果连接成功，返回Socket对象
        Socket socket = new Socket(InetAddress.getLocalHost(),9999); //测试时用的主机，所以getLocalHost()。连接本机的9999端口
        System.out.println("客户端 socket返回 = "+socket.getClass());


        //2.连接上后，生成Socket，通过socket.getOutputStream() 得到和socket对象关联的输出流对象
        OutputStream outputStream = socket.getOutputStream();

        //3.通过输出流，写入数据到 数据通道
        outputStream.write("hello, server".getBytes());

        //4.关闭流对象和socket，否则造成资源浪费
        outputStream.close();
        socket.close();
        System.out.println("客户端退出。。。");
    }
}
//客户端
//(先split一对。再看一个新的zsh，再split，把新的其中一个删掉，在正常运行，就两个CODE了)

/*直接 split window 运行路径：
java /Users/hengchangqi/c_vscode/Data_Structure/wangluo_hsp/src/socket/src/eg1_Client.java
*/
