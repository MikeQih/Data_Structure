import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.util.Scanner;


public class HW02_SenderB {
    public static void main(String[] args) throws IOException {
        //1.创建DatagramSocket对象，准备在9998端口发送数据 (发送端和接收端 一台机器上，最好在不同端口)
        DatagramSocket socket = new DatagramSocket(9998);

        //2.将需要发送的数据，封装到DatagramPacket对象
        Scanner scanner = new Scanner(System.in);
        System.out.println("请输入你的问题：");
        String question = scanner.next();
        byte[] data = question.getBytes();
        DatagramPacket packet = new DatagramPacket(data, data.length, InetAddress.getByName("192.168.96.144"),8888); //也可getLocalHost()
        socket.send(packet);

        //3.===接收从A端回复的信息
        //(1)构建一个DatagramPacket对象，准备接收数据
        //UDP协议->一个数据包最大是64K
        byte[] buf = new byte[1024];
        packet = new DatagramPacket(buf,buf.length);

        //(2)调用接收方法
        //将网络传输的DatagramPacket对象，填充到packet对象
        //有数据发送到9998端口时，会接收到数据；如没有，就阻塞等待
        socket.receive(packet);

        //(3)可以把packet 进行拆包，取出数据，并显示
        int length = packet.getLength(); //实际接收到的数据长度
        data = packet.getData();
        String s = new String(data,0,length);
        System.out.println(s);

        //关闭资源
        socket.close();
        System.out.println("B端退出");

    }
}
