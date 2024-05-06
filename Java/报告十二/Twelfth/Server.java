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
		System.out.println("�����������");
		DatagramPacket pack = null;
		DatagramSocket mail = null;
		DatagramSocket mail1 = null;
		String message = null;
		byte b[] = new byte[8192];
		while(true) {
			try {
				pack = new DatagramPacket(b,b.length);
				// ����˽��ն˿�1234
				mail = new DatagramSocket(1234);

				mail.receive(pack);
				message = new String(pack.getData(),0,pack.getLength());
				/**
				 * �����м���Զ�message���д���
				 * �����ιؼ��ʵ�
				 */
				System.out.println("������յ�"+message);
				char from = message.charAt(0);
				message = "����"+from+"��\n"+message.substring(1, message.length());
				byte b0[] = message.trim().getBytes();
				InetAddress address = InetAddress.getByName("127.0.0.1");
				DatagramPacket data;
				mail1 = new DatagramSocket();
				
				if(from == 'A') {		// A������Ϣ
					// ����Ϣת����B
					data = new DatagramPacket(b0,b0.length,address,2222);
					mail1.send(data);
					System.out.println("������ѷ��͸�B");
				}else if(from == 'B') {	// B������Ϣ
					// ����Ϣת����A
					data = new DatagramPacket(b0,b0.length,address,1111);
					mail1.send(data);
					System.out.println("������ѷ��͸�A");
				}
				mail.close();
				mail1.close();
			} catch (Exception e) {
				continue;
			}
		}
	}
}
