import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.FileInputStream;
import java.io.InputStream;
import java.net.ServerSocket;
import java.net.Socket;

public class HW03_Server {
    public static void main(String[] args) throws Exception {
        //1.监听 9999端口 等待客户端连接，读取下载文件的名字
        ServerSocket serverSocket = new ServerSocket(9999);

        //2.等待客户端连接
        System.out.println("服务端。在9999端口监听，等待下载文件");
        Socket socket = serverSocket.accept();

        //3.读取 客户端发送的要下载的文件名
        //这里使用的while循环读取文件名，是考虑将来客户端发送数据较大的情况
        InputStream inputStream = socket.getInputStream();
        byte[] b = new byte[1024];
        int len = 0;
        String downLoadFileName = "";
        while((len = inputStream.read(b))!=-1){
            downLoadFileName += new String(b,0,len);
        }
        System.out.println("客户端希望下载的文件名 = "+downLoadFileName);

        //如果下载的是 /Users/hengchangqi/Downloads/TW Formula Sheet for Final 2023.pdf 就返回该文件；
        //否则 返回 /Users/hengchangqi/Downloads/bomb3.png

        String resFileName = "";
        if("bomb3".equals(downLoadFileName)){
            resFileName = "bomb3.png";
        } else{
            resFileName = "bomb2.png";
        }

        //4.创建一个输入流，读取文件
        BufferedInputStream bis = new BufferedInputStream(new FileInputStream(resFileName));

        //5.使用工具类StreamUtils，读取文件到一个字节数组
        byte[] bytes = StreamUtils.streamToByteArray(bis);

        //6.得到Socket关联的输出流
        BufferedOutputStream bos = new BufferedOutputStream(socket.getOutputStream());

        //7.写入到数据通道，返回给客户端
        bos.write(bytes);
        socket.shutdownOutput(); //很关键，要不然客户端不知道啥时候结束，会有等待

        //8.关闭相关的资源
        bos.close();
        bis.close();
        inputStream.close();
        socket.close();
        serverSocket.close();
        System.out.println("服务端退出...");

    }
}
