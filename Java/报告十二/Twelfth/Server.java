package Twelfth;

import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

public class Server implements Runnable{
	public static void main(String []args) {
		new Server();
	}
	
	Server(){
		Thread thread = new Thread(this);
		thread.start();
	}
	
	@Override
	public void run() {
		System.out.println("服务端已启动");
		DatagramPacket pack = null;
		DatagramSocket mail = null;
		DatagramSocket mail1 = null;
		String message = null;
		byte b[] = new byte[8192];
		while(true) {
			try {
				pack = new DatagramPacket(b,b.length);
				// 服务端接收端口1234
				mail = new DatagramSocket(1234);

				mail.receive(pack);
				message = new String(pack.getData(),0,pack.getLength());
				/**
				 * 在这中间可以对message进行处理
				 * 如屏蔽关键词等
				 */
				System.out.println("服务端收到"+message);
				char from = message.charAt(0);
				message = "来自"+from+"：\n"+message.substring(1, message.length());
				byte b0[] = message.trim().getBytes();
				InetAddress address = InetAddress.getByName("127.0.0.1");
				DatagramPacket data;
				mail1 = new DatagramSocket();
				
				if(from == 'A') {		// A发送信息
					// 将信息转发给B
					data = new DatagramPacket(b0,b0.length,address,2222);
					mail1.send(data);
					System.out.println("服务端已发送给B");
				}else if(from == 'B') {	// B发送信息
					// 将信息转发给A
					data = new DatagramPacket(b0,b0.length,address,1111);
					mail1.send(data);
					System.out.println("服务端已发送给A");
				}
				mail.close();
				mail1.close();
			} catch (Exception e) {
				continue;
			}
		}
	}
}
