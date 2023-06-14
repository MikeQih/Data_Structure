package QQClient.qqclient.service;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.ObjectOutputStream;

import QQClient.qqcommon.Message;
import QQClient.qqcommon.MessageType;

/**
 * 该类/对象 完成 文件传输服务
 */
public class FileClientService {
    /**
     * 
     * @param src 源文件
     * @param dest 把文件传送到对方的对应目录
     * @param senderId
     * @param getterId
     */
    public void sendFileToOne(String src, String dest, String senderId, String getterId){
        //读取src文件 --> message
        Message message = new Message();
        message.setMesType(MessageType.MESSAGE_FILE_MES);
        message.setSender(senderId);
        message.setGetter(getterId);
        message.setSrc(src);
        message.setDest(dest);

        //需要将文件读取
        FileInputStream fileInputStream = null;
        byte[] fileBytes = new byte[(int) new File(src).length()];
        try {
            fileInputStream = new FileInputStream(src);
            fileInputStream.read(fileBytes); //将src文件读入到程序的字节数组
            //将文件对应的字节数组设置到message
            message.setFileBytes(fileBytes);
        } catch (Exception e) {
            e.printStackTrace();
        } finally{
            if(fileInputStream!=null){
                try {
                    fileInputStream.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }

        //提示信息
        System.out.println("\n"+senderId+" 给 "+getterId+" 发送文件："+src+" 到对方电脑的目录 "+dest);

        //发送
        try {
            ObjectOutputStream oos = new ObjectOutputStream(ManageClientConnectServiceThread.getClientConnectServerThread(senderId).getSocket().getOutputStream());
            oos.writeObject(message);
        } catch (IOException e) {
            e.printStackTrace();
        }


    }
}
