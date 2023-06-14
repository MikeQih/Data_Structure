/*
网络通信
1.概念：两台设备间通过网络实现数据传输
2.网络通信：将数据通过网络从一台设备传输到另一台设备
3.java.net包下提供了一系列的类或接口，供程序员使用，完成网络通信

网络
1.概念：两台或多台设备通过一定物理设备连接起来构成了网络
2.根据网络覆盖范围不同，分为：局域网(仅覆盖一个教师或机房)，城域网(一个城市)，广域网(全国，甚至全球 eg.万维网)

ip地址
1.概念：用于唯一标识网络中的每台计算机/主机
2.查看ip地址：ifconfig (本机：192.168.97.150，由网络地址(前三个数字)+主机地址(最后一个数字)组成)
3.ip地址表示形式：点分十进制 xx.xx.xx.xx
4.每个十进制范围 0～255
5.IPv6(16个字节)是互联网工程任务组设计的用于替代IPv4(4个字节)的下一代IP协议，地址数量号称可以为全世界每粒沙子编上地址
6.IPv4最大问题在于网络地址资源有限，严重制约互联网的应用和发展。IPv6的使用，不仅能解决网络地址资源数量的问题，而且也解决了多种接入设备连入互联网的障碍

域名：
1. eg.www.baidu.com
2.好处：方便记忆，解决记ip的困难
3.概念：将ip地址映射成域名(HTTP协议 以后学？)

端口号
1.概念：用于标识计算机上某个特定的网络程序
2.表示形式：以整数形式，端口范围0～65535
3.0～1024已经被占用，eg.ssh 22, ftp 21, smtp 25, http 80
常见的网络程序端口号：tomcat：8080，mysql：3306，oracle：1521，sqlserver：1433

协议：(本身)就是数据的组织形式
TCP/IP(Transimission Control Protocol / Internet Protocol) 传输控制协议/因特网互联协议，又叫网络通讯协议 
(Internet最基本的协议，Internet国际互联网络的基础)(由网络层的IP协议 和 传输层的TCP协议组成)

TCP/IP有两种模型：
1.OSI模型(理论，现实中并没有) 
2.TCP/IP模型 -> 把前三层简化成应用层，然后传输层，网络层，物理+数据链路层

TCP协议 传输控制协议：三次握手，可靠的；适合大数据量传输；传输完毕需释放连接，效率低
UDP协议 用户数据协议：无需连接，不可靠；每个数据包大小限制在64K内；无需释放资源，速度快
(TCP和UDP都会用到 Socket->客户端和服务器通常情况，在不同的主机)

netstat指令
1.netstat -an：查看当前主机网络情况，包括端口监听和网络连接 情况
2.netstat -an | more：可分页显示
(3.要求在dos控制台下执行win+r，windows的操作)
说明：1.Listening表示某个端口在监听 2.如果有一个外部程序(客户端)连接到该窗口，就会显示一条连接信息。3.windows上ctrl+c可退出指令

TCP秘密：
当客户端连接到服务端后，实际上客户端也是通过一个端口和服务端进行通讯的，这个端口是TCP/IP来分配的，是不确定且随机的

UDP说明：
1.无需建立发送端和接收端的连接
2.无明确的服务端和客户端
3.接收/发送数据 通过DatagramSocket对象完成
4.将数据封装到DatagramPacket对象/装包，发送
5.接收到传送的DatagramPacket对象时，需要拆包，取出数据
6.DatagramSocket可以指定在哪个端口接收数据

UDP流程：
1.建立发送端，接收端
2.发送数据前，建立数据包/报，DatagramPacket对象
3.调用DatagramSocket的发送，接收方法
4.关闭DatagramSocket

看到p710
15:04
*/