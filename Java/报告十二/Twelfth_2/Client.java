package Twelfth_2;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.GraphicsEnvironment;
import java.awt.GridLayout;
import java.awt.Panel;
import java.awt.Rectangle;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.ObjectOutputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;

import javax.swing.ButtonGroup;
import javax.swing.JButton;
import javax.swing.JCheckBox;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JRadioButton;
import javax.swing.JTextArea;

public class Client {
	public static void main(String[] args){
		System.out.println("客户端运行");
		Window w = new Window();
		
	}

}

class Window extends JFrame implements ActionListener{
	
	// 答题系统需要倒计时、题目区域、计分区域
	// 这里用BorderLayout布局
	String AA = null;	// 答案
	String QQ = null; 	// 题目
	int flag = 0;		// 判断用户是否按了提交按钮
	int question_num = 0;
	int countdown = 20;	// 倒计时
	int _single = 0;	// 已出题目数
	int _judge = 0;
	int _multi = 0;
	int score = 0;		// 总分数
	int r_single = 0;	// 正确题目数
	int r_judge = 0;
	int r_multi = 0;
	static String type[] = {"单选题：","判断题：","多选题："};
	
	// component
	JTextArea CountDown;
	JTextArea Score;
	JTextArea Questions;
	JPanel Pan = new JPanel();
	JRadioButton s_aAnswer = new JRadioButton("A");		// 单选
	JRadioButton s_bAnswer = new JRadioButton("B");
	JRadioButton s_cAnswer = new JRadioButton("C");
	JRadioButton s_dAnswer = new JRadioButton("D");
	JCheckBox m_aAnswer = new JCheckBox("A");			// 多选
	JCheckBox m_bAnswer = new JCheckBox("B");
	JCheckBox m_cAnswer = new JCheckBox("C");
	JCheckBox m_dAnswer = new JCheckBox("D");
	JRadioButton j_yAnswer = new JRadioButton("正确");	// 判断
	JRadioButton j_nAnswer = new JRadioButton("错误");
	JButton handle = new JButton("提交");				// 提交按钮
	
	String FontName = "Dialog.plain";					// 字体名称(事先用控制台获取)
	
	Window(){
		// 倒计时
		CountDown = new JTextArea(1,20);
		CountDown.setText("倒计时：" +countdown+"s");
		CountDown.setFont(new Font(FontName,Font.BOLD,18));
		CountDown.setEditable(false);
		CountDown.setBackground(new Color(207,207,207));
		
		// 题目区域
			// 题目
		String question = null;
		Questions = new JTextArea(22,27);
		Questions.setLineWrap(true);
		Questions.setWrapStyleWord(true);
//		Questions.setText(type[0]+new Single().single[]);
		Questions.setFont(new Font(FontName,Font.BOLD,18));
		Questions.setEditable(false);
		
			// 选项
		Pan.setBounds(0,0,80,80);
		Pan.setLayout(new GridLayout(4,1));
		ButtonGroup group1 = new ButtonGroup();
		ButtonGroup group2 = new ButtonGroup();
		j_yAnswer.setFont(new Font(FontName,Font.BOLD,15));
		j_nAnswer.setFont(new Font(FontName,Font.BOLD,15));
		group1.add(s_aAnswer);
		group1.add(s_bAnswer);
		group1.add(s_cAnswer);
		group1.add(s_dAnswer);
		group2.add(j_yAnswer);
		group2.add(j_nAnswer);
			
			// 提交按钮
		handle.setBounds(0,0,80,80);
		handle.addActionListener(this);
		
		// 计分区域
		Score = new JTextArea(3,10);
		Score.setText(
				"答题情况："+" 单选"+_single+" 判断"+_judge+" 多选"+_multi+"\n正确情况："
				+" 单选"+r_single+" 判断"+r_judge+" 多选"+r_multi+"\n分数："+score
				);
		Score.setFont(new Font(FontName,Font.BOLD,18));
		Score.setEditable(false);
		
		// BorderLayout布局
		this.add(CountDown,BorderLayout.NORTH);
		this.add(Score,BorderLayout.SOUTH);
		this.add(Questions,BorderLayout.WEST);
		this.add(Pan,BorderLayout.CENTER);
		this.add(handle,BorderLayout.EAST);
		
		// 窗体设置
		setLocationRelativeTo(null);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);		
		setTitle("Java答题系统");
		validate();
		setBounds(120,125,600,400);
		setVisible(true);
		
		// 线程
		new Thread(new Runnable() {
			int sum = 0;
			@SuppressWarnings("deprecation")
			public void run() {

				System.out.println("线程开始");
				long startTime=System.currentTimeMillis(); 
				
				while(sum<=15) {
					sum++;
					String q = null;
					if(sum == 16) {		// 答题结束
						long endTime=System.currentTimeMillis();
						Questions.setText("答题结束\n总共用时："+(int)((endTime-startTime)/1000)+"秒");
						Questions.setFont(new Font(FontName,Font.BOLD,50));
						break;
					}else {
						// 与服务端建立连接
						try {
							Socket socket = new Socket("localhost",8080);
							OutputStream os = socket.getOutputStream();
							PrintWriter pw = new PrintWriter(os);
							InputStream is = socket.getInputStream();
							BufferedReader br = new BufferedReader(new InputStreamReader(is));
							System.out.println("发送获取题目请求");
							//
							String info="1";
				            pw.write(info);
				            pw.flush();
				            socket.shutdownOutput();
				            String reply=null;
				            String get = "";
				            while(!((reply=br.readLine())==null)){
				            	get+=(reply+"\n");
				                System.out.println(reply);
				            }
				            String A = get.substring(0, 4);
				            AA = "";
				            for(int i = 0;i<4;i++) {
				            	if(A.charAt(i)!=' ') {
				            		AA+=A.charAt(i);
				            	}
				            }

				            System.out.println("答案"+AA);
				            q = get.substring(4);
				            Questions.setText(q);
							br.close();
				            is.close();
				            pw.close();
				            os.close();
				            socket.close();
						}
						catch(IOException e) {
							System.out.println(e);
						}
					}
					Pan.setVisible(true);
					handle.setVisible(true);
					flag = 0;
					Pan.removeAll();
					countdown = 20;
					// 三种类型的选项
					if(q.substring(0, 4).compareTo(type[0]) == 0) {
						Pan.add(s_aAnswer);
						Pan.add(s_bAnswer);
						Pan.add(s_cAnswer);
						Pan.add(s_dAnswer);
					}else if(q.substring(0, 4).compareTo(type[1]) == 0) {
						Pan.add(j_yAnswer);
						Pan.add(j_nAnswer);
					}else {
						Pan.add(m_aAnswer);
						Pan.add(m_bAnswer);
						Pan.add(m_cAnswer);
						Pan.add(m_dAnswer);
					}
					while(countdown!=0) {
						try {
							Thread.sleep(1000);
							countdown--;
							CountDown.setText("倒计时：" +countdown+"s");
						} catch (InterruptedException e) {
							e.printStackTrace();
						}
					}
					
					if(flag == 0) {			//倒计时结束，答案自动提交
						Pan.setVisible(false);
						handle.setVisible(false);
						countdown = 3;
						showAnswer();
						while(countdown!=0) {
							try {
								Thread.sleep(1000);
								countdown--;
								CountDown.setText("倒计时：" +countdown+"s");
							} catch (InterruptedException e) {
								e.printStackTrace();
							}
						}
					}
					Pan.removeAll();
					// 提交之后，检查结果
					int i = 0 ;
					String handin = "";
					if(q.substring(0, 4).compareTo(type[0]) == 0) {		// 单选
						_single++;
						if(s_aAnswer.isSelected()) {	//获取提交值
							handin += "A";
						}
						if(s_bAnswer.isSelected()) {
							handin += "B";
						}
						if(s_cAnswer.isSelected()) {
							handin += "C";
						}
						if(s_dAnswer.isSelected()) {
							handin += "D";
						}
						System.out.println("提交"+handin);
						group1.clearSelection();
						if(AA.compareTo(handin) == 0) {
							r_single++;
							score+=1;
							System.out.println("s_yes!");
						}
					}else if(q.substring(0, 4).compareTo(type[1]) == 0) {	// 判断
						_judge++;
						if(j_yAnswer.isSelected()) {
							handin+="Y";
						}else if(j_nAnswer.isSelected()) {
							handin+="N";
						}
						group2.clearSelection();
						if(AA.compareTo(handin) == 0) {
							r_judge++;
							score+=1;
							System.out.println("j_yes!");
						}
					}else {		// 多选
						_multi++;
						if(m_aAnswer.isSelected()) {
							handin+="A";
							m_aAnswer.setSelected(false);
						}
						if(m_bAnswer.isSelected()) {
							handin+="B";
							m_bAnswer.setSelected(false);
						}
						if(m_cAnswer.isSelected()) {
							handin+="C";
							m_cAnswer.setSelected(false);
						}
						if(m_dAnswer.isSelected()) {
							handin+="D";
							m_dAnswer.setSelected(false);
						}
						System.out.println(handin);
						if(AA.compareTo(handin) == 0) {
							r_multi++;
							score+=2;
							System.out.println("m_yes!");
						}
						
					}
					
					Score.setText(
							"答题情况："+" 单选"+_single+" 判断"+_judge+" 多选"+_multi
							+"\n正确情况："+" 单选"+r_single+" 判断"+r_judge+" 多选"+r_multi+"\n分数："+score
							);
					
				}
				
			}
		}).start();
	}
	
	
	
	void showAnswer() {
		if(AA.compareTo("Y") == 0) {
			Score.setText("本题答案：正确");
		}else if(AA.compareTo("N") == 0){
			Score.setText("本题答案：错误");
		}else {
			Score.setText("本题答案："+AA);
		}
	}
	
	@Override
	public void actionPerformed(ActionEvent e) {
		Pan.setVisible(false);
		handle.setVisible(false);
		countdown = 3;
		flag = 1;		// 用户按了提交
		showAnswer();
	}
	
}


