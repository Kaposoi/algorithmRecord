# Socket

>import socket
>
>socket.socket(AddressFamily, Type)

说明:

>参数一: AddressFamily(地址簇)
>
>socket.AF_INET IPv4(defaule)
>
>socket.AF_INET6 IPv6
>
>socket.AF_UNIX 只能用于单一的Unix系统
>
> 
>
>参数二: Type
>
>socket.SOCK_STREAM
>
>流式socket, for TCP(default)
>
>socket.SOCK_DGRAM 
>
>数据报 for UDP
>
>socket.SOCK_RAW 原始套接字， 可以处理ICMP， IGMP 也可以处理特殊的IPv4， 也可以通过IP_HDRINCL套接字选项构造ip头
>
> 
>
>socket.SOCK_RDM 是一种可靠的udp， 保证交付， 但是不保证顺序



## UDP连接

socket的sendto方法能够发送数据， encode方法可以设置发送数据的编码

>socket.sendto(..1, (..2))
>
>参数说明:
>
>1. 要发送的二进制数据
>2. 元组类型， (ip地址字符串， 端口) 指定发送数据给谁
>
> 
>
>udp_socket.sendto("你好".encode(), ("127.0.0.1", 8000))
>
> 
>
>注: 通信链路中数据流是二进制形式传输的



socket的recvfrom方法可以接受数据

decode方法可以对接受到的数据进行编码

>data = socket.recvfrom(..1)
>
>..1 缓存区大小(每次接收多少个字节)
>
>此方法会阻塞程序运行， 当对方发送数据后， 会接受数据
>
>接受到的数据是一个元组，(发送数据的二进制形式, 发送方的ip地址和端口号)
>
>data[0] -> 数据
>
>data[1] -> 元组(ip和端口)
>
>注: 在发送信息后才可以调用sendto方法





编码和解码

>编码就是 str -> bytes
>
>而解码是 bytes -> str
>
>
>
>解码方法.decode(encoding = 'utf-8', errors = 'strict | ignores')
>
>encoding用于指定解码格式， 而errors为ignores会忽视解码中产生的错误
>
>不指定解码格式默认按utf-8解码



udp发送端口绑定

>每次运行时系统会为socket随机分配一个未被使用的接口
>
>socket.build() 方法将socket对象绑定到一个地址， 一般是一个ip， port对
>
> 
>
>attr = ('192.168.150.25', 8888)
>
>socket.build(attr)
>
>注: 第一个必须绑定自己的地址， ip一般是不用写的



udp接收端口绑定

>.bind() 方法， 传入一个元组， 第一个是ip地址， 第二个是端口
>
>注: ip地址最好写为""， 好处是当计算机有不同网卡时， 也可以接收数据， 这个ip和端口也是本地的信息



udp广播

>ip为255.255.255.255的地址可以向工作站中的所有网络边缘发送信息
>
>套接字默认不允许发送广播
>
>.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, True)
>
>开启权限， 发送广播



## TCP连接

初始化连接

>.connect((..1, ..2))
>
>参数是元组
>
>..1: 目的ip地址
>
>..2: 目的端口



发送信息

>.send(..1)
>
>..1 要发送的信息， 是二进制形式



接收信息

>.recv(..1)
>
>..1 缓冲区大小(一次性最大接收的数量)
>
>此方法接收到的只有数据
>
>判断接收是否完毕时， 可以判断数据的长度是否为0
>
>注: 当客户端断开连接时， 会向服务器发送一个__空包__， 也就是说接收到的数据的长度为__0__， 因此当接收到空包时应该断开连接



### TCP服务端

设置监听

>.listen(..1)
>
>设置套接字为被动接收模式， 主动发送数据将会被禁用
>
>..1 允许搭建的最大连接数
>
>在windows 128有效， 而在linux 128无效



接收客户端连接

>.accpet()
>
>开始接收客户端连接， 程序会进入阻塞状态而等待客户端连接
>
>返回值是一个元组， (客户端的套接字， (客户端的ip， 客户端的端口))
>
>然后调用客户端的recv方法接收和发送信息
>
>注: 不用此方法的话直接使用tcp连接套接字进行收发
>
>**请求行里包含了请求地址， 且地址不含域名， 只含'/'和后面的地址**



### 地址重用

>client_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, True)
>
>True表示可以重用， False表示不可重用
>
>重用就是让套接字连接断开后依然可以使用那个套接字的端口
