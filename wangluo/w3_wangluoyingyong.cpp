/*
1.网络应用体系结构：
客户机/服务器结构(Client-Server, C/S) 客户机使用服务器提供的服务
点对点结构(Peer-to-peer, P2P) 高度可伸缩，但难于管理
混合结构(Hybrid) 文件传输用P2P，文件搜索用C/S

进程间通信(利用socket发送/接收消息实现)：
进程：主机上运行的程序
同一主机上运行的进程间如何通信？进程间通信机制，操作系统提供
不同主机上运行的进程间，通过消息交换 通信

网络应用需遵循 应用层 协议
公开协议：1.由RFC(Request For Comments)定义 2.允许互操作 3.HTTP,SMTP... 
私有协议：多数P2P文件共享应用
应用层协议内容：1.消息的类型(type) 2.消息的语法(syntax)/格式 3.字段的语义(semantics) 4.规则(rules)



2.网络应用的服务需求：
数据丢失(data loss)/可靠性(reliability)
时间(timing)/延迟(delay)
带宽(bandwidth)

TCP服务(Transmission Control Protocol，传输控制协议)：
1.面向连接(客户机/服务器进程间需建立连接) 2.可靠的传输 3.流量控制(发送方不会发送速度过快，超过接收方处理能力) 
4.拥塞控制(网络负载过重时，限制发送方的发送速度) 5.不提供时间/延迟保障 6.不提供最小带宽保障

UDP服务(User Datagram Protocol，用户数据报协议)：
1.无连接 2.不可靠的数据传输 3.不提供：可靠性保障，流量控制，拥塞控制，延迟保障，带宽保障

HTTP(HyperText Transfer Protocol)协议(超文本传输协议)，使用的传输层协议是TCP传输服务。
HTTP应用是个无状态协议(stateless) 服务器不维护任何有关客户端过去所发请求的信息
HTTP连接分为：
1.非持久性连接(Nonpersistent HTTP)：每个TCP连接最多允许传输一个对象 1.0版本使用
2.持久性连接(Persistent HTTP)：每个TCP连接允许传输多个对象 1.1版本默认使用

RTT(Round Trip Time)：从客户端发送一个很小的数据包道服务器并返回所经历的时间
Total = 2RTT+文件发送时间
持久性HTTP需要了解吗？问

HTTP协议有两类消息：请求消息(request)，响应消息(response)
上传输入的方法：POST方法，URL方法；HTTP/1.0：GET,POST,HEAD；HTTP/1.1:GET,POST,HEAD,PUT,DELETE
HTTP响应代码：响应消息的第一行 eg.200 OK, 404 Not Found...
(怎样用telnet体验http 输入请求)

Cookie技术：某些网站为了辨别用户身份，进行session追踪而储存在用户本地终端上的数据(通常进行加密) (RFC6265，RFC编号6265)
Cookie能用于：身份认证，购物车，推荐，Web e-mail... 缺点：隐私问题

Web缓存/代理服务器技术 -> 性能优化技术：在不访问服务器的前提下满足客户端的HTTP请求
发明此技术的原因：缩短客户请求的响应时间，减少机构/组织的流量，在大范围内(Internet)实现有效的内容分发

DNS(Domain Name System，域名解析系统)：
1.域名向IP地址的翻译
2.主机别名
3.邮件服务器别名
4.负载均衡：Web服务器
(用分布式；而不使用集中式DNS，因为单点失败/流量/距离/维护性 问题)

分布式
最上层：DNS根域名服务器：本地域名解析服务器无法解析域名时，访问根域名服务器
第二层：顶级域名服务器(TLD,top-level domain)：负责com,org,net,edu等顶级域名和国家顶级域名
三：权威域名服务器(Authoritative)：组织的域名解析服务器，提供组织内部服务器的解析服务











3.Internet传输层服务模型：

4.特定网络应用及协议：

5.Socket编程：



看到w4 2.7 Socket编程
*/
