package QQServer.qqserver.service;

import java.util.HashMap;
import java.util.Iterator;

/**
 * 该类用于 管理与客户端通讯 的线程
 */
public class ManageClientThreads {
    private static HashMap<String,ServerConnectClientThread> hm = new HashMap<>();
    
    //返回hm
    public static HashMap<String,ServerConnectClientThread> getHm(){
        return hm;
    }
    
    //添加线程对象到hm集合
    public static void addClientThread(String userId,ServerConnectClientThread serverConnectClientThread){
        hm.put(userId, serverConnectClientThread);

    }

    //根据userId返回ServerConnectClientThread线程 (传一个userId，返回该userId对应的和客户端保持通讯的线程)
    public static ServerConnectClientThread getServerConnectClientThread(String userId){
        return hm.get(userId);
    }

    //从集合中移除某个线程对象
    public static void removeServerConnectClientThread(String userId){
        hm.remove(userId);
    }

    //返回在线用户列表(空格隔开)
    public static String getOnlineUser(){
        //集合遍历，遍历hashmap的key
        Iterator<String> iterator = hm.keySet().iterator();
        String onlineUserList = "";
        while(iterator.hasNext()){
            onlineUserList += iterator.next().toString()+" ";
        }
        return onlineUserList;
    }
}
