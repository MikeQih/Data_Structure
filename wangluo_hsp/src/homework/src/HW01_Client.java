import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.net.InetAddress;
import java.net.Socket;
import java.util.Scanner;

//扩展出去就是聊天系统

//使用字符流方式读写
public class HW01_Client {
    public static void main(String[] args) throws IOException {
        //思路
        //1.连接服务端(ip，端口)
        //连接本机的9999端口，如果连接成功，返回Socket对象
        Socket socket = new Socket(InetAddress.getLocalHost(),9999); //测试时用的主机，所以getLocalHost()。连接本机的9999端口
        System.out.println("客户端 socket返回 = "+socket.getClass());

        //2.连接上后，生成Socket，通过socket.getOutputStream() 得到和socket对象关联的输出流对象
        OutputStream outputStream = socket.getOutputStream();

        //3.通过输出流，写入数据到 数据通道，使用字符流
        BufferedWriter bufferedWriter = new BufferedWriter(new OutputStreamWriter(outputStream));
        
        //从键盘读取用户的问题
        Scanner scanner = new Scanner(System.in);
        System.out.println("请输入你的问题");
        String question = scanner.next();
        
        bufferedWriter.write(question);
        bufferedWriter.newLine(); //插入一个换行符，表示写入的内容结束。(要求对方使用readLine()来读)
        bufferedWriter.flush(); //如果使用的字符流，需要手动刷新，否则数据不会写入数据通道

        //4.获取和socket关联的输入流。读取数据(字节)，并显示
        InputStream inputStream = socket.getInputStream();
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(inputStream));
        String s = bufferedReader.readLine();
        System.out.println(s);

        //5.关闭流对象和socket，否则造成资源浪费
        bufferedReader.close(); //关闭外层流
        bufferedWriter.close();
        socket.close();
        System.out.println("客户端退出。。。");
    }
}

