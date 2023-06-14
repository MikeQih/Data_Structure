import java.net.InetAddress;
import java.net.UnknownHostException;

import org.junit.Test;

public class API_ {

    @Test
    public static void main(String[] args) throws UnknownHostException {
        //1.获取本机的InetAddress对象
        InetAddress localHost = InetAddress.getLocalHost();
        System.out.println(localHost); //damai.local/127.0.0.1

        //2.根据指定主机名，获取InetAddress对象
        InetAddress host1 = InetAddress.getByName("damai.local");
        System.out.println("host1 = "+host1); //和上面一样

        //3.根据域名返回 InetAddress对象，eg.www.baidu.com 对应
        InetAddress host2 = InetAddress.getByName("www.baidu.com");
        System.out.println("host2 = "+host2); //www.baidu.com/14.119.104.189

        //4.根据InetAddress对象，获取对应的地址
        String hostAddress = host2.getHostAddress();
        System.out.println("host2 对应的ip = "+hostAddress);

        //5.根据InetAddress对象，获取对应的主机名/域名
        String hostName = host2.getHostName();
        System.out.println("host2对应的主机名/域名 = "+hostName); //www.baidu.com
        
    }
}
/*
192.168.96.144
*/
