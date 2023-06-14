import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

public class HW02_ReceiverA {
    public static void main(String[] args) throws IOException {
        //1.创建一个DatagramSocket对象，准备在8888端口接收数据
        DatagramSocket socket = new DatagramSocket(8888);

        //2.构建一个DatagramPacket对象，准备接收数据
        //UDP协议->一个数据包最大是64K
        byte[] buf = new byte[1024];
        DatagramPacket packet = new DatagramPacket(buf,buf.length);

        //3.调用接收方法
        //将网络传输的DatagramPacket对象，填充到packet对象
        System.out.println("接收端 等待接收问题：");
        socket.receive(packet);

        //4.可以把packet 进行拆包，取出数据，并显示
        int length = packet.getLength(); //实际接收到的数据长度
        byte[] data = packet.getData();
        String s = new String(data,0,length);

        //判断接收到的信息，然后做相应反馈
        String answer = "";
        if("四大名著有哪些".equals(s)){
            answer = "四大名著：《红楼梦》《三国演义》《西游记》《水浒传》";
        } else{
            answer = "what???";
        }

        //===回复信息给B端
        data = answer.getBytes();
        packet = new DatagramPacket(data, data.length, InetAddress.getByName("192.168.96.144"),9998); //也可getLocalHost()
        socket.send(packet);

        //5.关闭资源
        socket.close();
        System.out.println("A端退出...");



    }
}
