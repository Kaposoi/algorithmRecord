# udp简易聊天器

```python
import socket


def send_msg(udp_socket) -> None:
	ipaddr = input('请输入接收方的ip地址:\n')
	port = input('请输入接收方的端口:\n')
	content = input('请输入要发送的内容:\n')
	udp_socket.sendto(content.encode(), (ipaddr, int(port)))


def recv_msg(udp_socket):
	recv_data, ip_port = udp_socket.recvfrom(1024)
	print("接收到{0}的信息:{1}".format(ip_port, recv_data.decode(encoding='utf-8', errors='ignore')))


def main():
	udp_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
	udp_socket.bind(("", 8080))

	while True:
		print('***********************')
		print('****** 1.发送信息 ******')
		print('****** 2.接收信息 ******')
		print('****** 3.退出系统 ******')
		print('***********************')
		sel_num = int(input('请输入选项:\n'))

		if sel_num == 1:
			print('您的选择是发送信息')
			send_msg(udp_socket)
		elif sel_num == 2:
			print('您的选择是接收信息')
			recv_msg(udp_socket)
		elif sel_num == 3:
			print('系统即将退出...')
			break

	udp_socket.close()


if __name__ == '__main__':
	main()

```

