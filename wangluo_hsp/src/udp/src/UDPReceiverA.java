import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

public class UDPReceiverA {
    public static void main(String[] args) throws IOException {
        //1.创建一个DatagramSocket对象，准备在9999端口接收数据
        DatagramSocket socket = new DatagramSocket(9999);

        //2.构建一个DatagramPacket对象，准备接收数据
        //UDP协议->一个数据包最大是64K
        byte[] buf = new byte[1024];
        DatagramPacket packet = new DatagramPacket(buf,buf.length);

        //3.调用接收方法
        //将网络传输的DatagramPacket对象，填充到packet对象
        //有数据发送到9999端口时，会接收到数据；如没有，就阻塞等待
        System.out.println("接收端A 等待接收数据...");
        socket.receive(packet);

        //4.可以把packet 进行拆包，取出数据，并显示
        int length = packet.getLength(); //实际接收到的数据长度
        byte[] data = packet.getData();
        String s = new String(data,0,length);
        System.out.println(s);

        //===回复信息给B端
        data = "好的，明天见".getBytes();
        packet = new DatagramPacket(data, data.length, InetAddress.getByName("192.168.96.144"),9998); //也可getLocalHost()
        socket.send(packet);

        //5.关闭资源
        socket.close();
        System.out.println("A端退出...");



    }
}
