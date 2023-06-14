import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.net.ServerSocket;
import java.net.Socket;

public class HW01_Server  {
    public static void main(String[] args) throws IOException {
        //思路：
        //1.在本机的9999端口监听，等待连接
        //(要求在本机没有其他服务在监听9999；ServerSocket可以通过accept() 返回多个Socket -> 多个客户端连接服务器的并发)
        ServerSocket serverSocket = new ServerSocket(9999);
        System.out.println("服务器，在9999端口监听，等待连接。。。");

        //2.当没有客户端连接9999端口时，程序会阻塞，等待连接
        //如果有客户端连接，则会返回Socket对象，程序继续
        Socket socket = serverSocket.accept();


        //3.通过socket.getInputStreeam()读取客户端写入到数据通道的数据，显示
        InputStream inputStream = socket.getInputStream();

        //4.IO读取 使用字符流，使用 InputStreamReader 将 inputStream 转成字符流
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(inputStream));
        String s = bufferedReader.readLine();
        
        String answer = "";
        if("name".equals(s)){
            answer = "我是mike";
        } else if("hobby".equals(s)){
            answer = "编写java程序";
        } else{
            answer = "你说的什么？";
        }

        //5.获取socket相关联的输出流
        OutputStream outputStream = socket.getOutputStream();
        //使用字符输出流 回复信息
        BufferedWriter bufferedWriter = new BufferedWriter(new OutputStreamWriter(outputStream));
        bufferedWriter.write(answer);
        bufferedWriter.newLine(); //插入一个换行符，表示回复内容的结束
        bufferedWriter.flush(); //需要手动flush

        //6.关闭流和socket
        bufferedWriter.close();
        bufferedReader.close();
        socket.close();
        serverSocket.close(); //serverSocket可以创建很多socket
    }
}
