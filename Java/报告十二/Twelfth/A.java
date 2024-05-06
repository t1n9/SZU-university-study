package Twelfth;

import java.awt.BorderLayout;
import java.awt.Container;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;

public class A extends JFrame implements Runnable,ActionListener{
	public static void main(String[] args) {
		new A();
	}
	
	JTextField outMessage = new JTextField(25);
	JTextArea inMessage = new JTextArea(12,20);
	JButton b = new JButton("����");
	
	A(){
		super("A");
		setSize(600,400);
		setVisible(true);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		validate();
		
		b.addActionListener(this);
		JPanel p = new JPanel();
		p.add(new JLabel("��������"));
		p.add(outMessage);
		p.add(b);
		
		Container con = getContentPane();
		con.add(p,BorderLayout.NORTH);
		con.add(new JScrollPane(inMessage),BorderLayout.CENTER);
		
		Thread thread = new Thread(this);
		thread.start();
	}
	

	@Override
	public void actionPerformed(ActionEvent event) {
		byte b[] = ("A"+(outMessage.getText())).trim().getBytes();
		try {
			InetAddress address = InetAddress.getByName("127.0.0.1");
			// A���Ͷ˿�1234
			DatagramPacket data = new DatagramPacket(b,b.length,address,1234);
			DatagramSocket mail = new DatagramSocket();
			// ������ͺ���UDP���ݰ�
			mail.send(data);
			System.out.println("A�ѷ���");
			mail.close();
		}
		catch(Exception e) {
			System.out.println("����ʧ��"+e);
		}
	}

	@SuppressWarnings("resource")
	@Override
	
	public void run() {
		// ��������
		DatagramPacket pack = null;
		DatagramSocket mail = null;
		byte b[] = new byte[8192];
		try {
			pack = new DatagramPacket(b,b.length);
			// A���ն˿�1111
			mail = new DatagramSocket(1111);
		}
		catch(Exception e) {
			System.out.println("A����ʧ��"+e);
		}
		while(true) {
			try {
				mail.receive(pack);
				String message = new String(pack.getData(),0,pack.getLength());
				inMessage.append(message+"\n");
				inMessage.setCaretPosition(inMessage.getText().length());
			}
			catch(Exception e) {
				System.out.println("A����ʧ��"+e);
			}
		}
	}
}