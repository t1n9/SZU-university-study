package Twelfth_2;

import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.ObjectInputStream;
import java.io.ObjectOutput;
import java.io.ObjectOutputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;

public class Server {

	public static void main(String[] args) {
		System.out.println("����˿�ʼ����");
		while(true) {
			try {
				ServerSocket serverSocket = new ServerSocket(8080);
				Socket socket = serverSocket.accept();
				InputStream is = socket.getInputStream();
				BufferedReader br = new BufferedReader(new InputStreamReader(is));
				OutputStream os = socket.getOutputStream();
				PrintWriter pw = new PrintWriter(os);
			
				String info=null;
	            while(!((info=br.readLine())==null)){
	                System.out.println("�յ�����"+info);
	            }
	            String reply=getQuestions();
	            pw.write(reply);
	            pw.flush();
	            pw.close();
	            os.close();
	            br.close();
	            is.close();
	            socket.close();
	            serverSocket.close();
				
				
			}catch(Exception e) {
				System.out.println(e);
			}
		}
		
	}
	
	
	
	static int st = 0;		//�����ͳ�����
	static int jt = 0;
	static int mt = 0;
	
	static String type[] = {"��ѡ�⣺","�ж��⣺","��ѡ�⣺"};
	static Single s = new Single();
	static Judge j = new Judge();
	static Multi m = new Multi();
	static String getQuestions() {
		String Q = null;
		int k = 0;		//���������
		int i = 0;		//��Ŀ����
		while(Q == null) {
			i = (int)(Math.random()*3);
			if(i == 0 && st <5) {
				k = s.getran();
				st++;
				Q = s.answer[k]+type[i]+s.single[k];
			}
			if(i == 1 && jt<5) {
				k = j.getran();
				jt++;
				Q = j.answer[k]+type[i]+j.judge[k];
			}
			if(i == 2 && mt<5) {
				k = m.getran();
				mt++;
				Q = m.answer[k]+type[i]+m.multi[k];
			}
		}
		System.out.println(type[i]+k);
		return (Q);
	}
}





// ���
class Single{
	// ��ѡ��
		String single[]= {
				"���������淶˵����ȷ���ǣ���\n"		//1
				+ "A�� ��������ĸ���»��ߡ����֡�$����������ɣ�\n"
				+ "B�� ����������������Ϊ��ͷ��\n"
				+ "C�� A��a��java����ͬһ��������\n"
				+ "D�� ��ͬ���͵ı�������������ͬ�����֣�",
				"����javaDocע����ȷ���ǣ���\n"		//2
				+ "A�� /*�Ұ������찲��*/\n"
				+ "B�� //�Ұ������찲��*/\n"
				+ "C�� /**�Ұ������찲��*/\n"
				+ "D�� /*�Ұ������찲��**/",
				"Ϊһ��boolean���ͱ�����ֵʱ������ʹ��()��ʽ\n"		//3
				+ "A�� boolean = 1;\n"
				+ "B�� boolean a = (9 >= 10);\n"
				+ "C�� boolean a=\"��\";\n"
				+ "D�� boolean a = = false;",
				"����()���ǺϷ��ı�ʶ��\n"		//4
				+ "A�� STRING\n"
				+ "B�� x3x;\n"
				+ "C�� void\n"
				+ "D�� de$f",
				"�������ʽ��������Ϊѭ������\n"		//5
				+ "A�� i++;\n"
				+ "B�� i>5;\n" 
				+ "C�� bEqual = str.equals(\"q\");\n" 
				+ "D�� count = = i;",
				"����ֵ��Ϊtrue�ı��ʽ�У�����\n" 		//6
				+ "A�� \"john\" = = \"john\"\n" 
				+ "B�� \"john\".equals(\"john\")\n" 
				+ "C�� \"john\" = \"john\"\n" 
				+ "D�� \"john\".equals(new String(\"john\"))",
				"��������������б�ʾΪ��������Ϊ��ģ�����\n"		//7
				+ "A�� ����\n"
				+ "B�� ����\n"
				+ "C�� ����\n"
				+ "D�� ��������",
				"��Java��,���ڹ��췽��������˵���������( )\n"		//8
				+ "A�� ���췽�������Ʊ�����������ͬ\n"
				+ "B�� ���췽�����Դ�����\n" 
				+ "C�� ���췽������������\n" 
				+ "D�� ���췽�����Բ����з���ֵ",
				"��JAVA���쳣����ģ���У��ܵ�����finally���һ��ʹ�õĿ��ǣ�����\n"		//9
				+ "A�� try\n"
				+ "B�� catch\n"
				+ "C�� throw\n"
				+ "D�� throws",
				"String s = JOptionPane.showInputDialog(frame,\"�����������ڳ������ƣ�\");����Ĵ���ִ�к󣬻ᵯ��һ������Ի�������û�����Ի������Ͻ��ϵġ�X��ͼ�꣨�رհ�ť������ô����ֵs�ǣ�\n"		//10
				+ "A.\"\"\n"
				+ "B.null\r\n"
				+ "C.NULL\r\n"
				+ "D.false"
		};
		int flag[] = {0,0,0,0,0,0,0,0,0,0};
		String answer[] = {"B   ","C   ","B   ","C   ","A   ","C   ","B   ","C   ","A   ","B   "};
		int getran() {
			// ��ȡδ��������Ŀ���
			int num;
			do {
				num = (int)(Math.random()*10);
			}while(flag[num]!=0);
			flag[num] = 1;
			return num;
		}
}

class Judge {
	// �ж���
	String judge[]= {
			"Ϊ��ʵ�ָ��ӵĽ��沼�֣�JFrame���������������ö��Layout��",		//1
			"�������JPasswordField���ı�����\nJTextField�����ࡣ�ı�����JTextField.getText()��ȡ�ı����ݣ���������ʹ��JPasswordField.getText()��ȡ�����ı�",		//2
			"��ݼ���Ϊ������Ч�ʶ��裬�˵���һ��Ҫ���ÿ�ݼ���",		//3
			"һ����ʵ��һ���ӿڣ���������ʵ�ֽӿ��е����з�����",	//4
			"��Java�ķ����ж���һ������Ҫ��const�ؼ���"	,		//5
			"��final���εı����г�����",					//6
			"һ�������ʵ�ֶ�ӿڡ�",					//7
			"Unicode����ASCII����ͬ��",				//8
			"���󷽷�û�з����塣",						//9
			"Java�У�һ��������ж��ֱ�Ӹ��ࡣ",			//10
	};
	int flag[] = {0,0,0,0,0,0,0,0,0,0};
	String answer[] = {"N   ","N   ","N   ","Y   ","N   ","Y   ","Y   ","N   ","N   ","N   "};
	int getran() {
		// ��ȡδ��������Ŀ���
		int num;
		do {
			num = (int)(Math.random()*10);
		}while(flag[num]!=0);
		flag[num] = 1;
		return num;
	}
}

class Multi {
	// ��ѡ��
	String multi[]= {
			"���У������������������ͣ���\n"		//1
			+ "A�� String\n"
			+ "B�� char\n"
			+ "C�� �û��Զ����Student������\n"
			+ "D�� int",		
			"�������ڴ���������������ǣ���\n"		//2
			+ "A�� Frame\n"
			+ "B�� Checkbox\n"
			+ "C�� Panel\n"
			+ "D�� TextField)",
			"������Щ����ȷ�ģ�()\n"			//3
			+ "A.MouseAdapter��һ����\n"
			+ "B.MouseAdapter��һ���ӿ�\n"
			+ "C.MouseListener��һ����\n"
			+ "D.MouseListener��һ���ӿ�",
			"�����������������������ǣ�����\n"		//4
			+ "A.����\n"
			+ "B.��д\n"
			+ "C.��װ\n"
			+ "D.�̳�",
			"�ӿںͳ�����������ȷ���У���\n"		//5	
			+ "A) ������û�й��캯��\n"			
			+ "B) �ӿ�û�й��캯��\n"
			+ "C) �����಻�����̳�\n"
			+ "D) �ӿ��еķ��������з�����",
			"��Java�ӿ��У�����ѡ������Ч�ķ��������ǣ�����\n"		//6
			+ "A�� public void aMethod();\n"
			+ "B�� void aMethod();\n"
			+ "C�� protected void aMethod();\n"
			+ "D�� private void aMethod();",
			"������Щ����java�ļ���������?()\n"				//7
			+ "A. short\n"
			+ "B. Boolean\n"
			+ "C. Double\n"
			+ "D. float\n",
			"����˵���������()\n"						//8
			+ "A�� ������һ�ֶ���\n"
			+ "B�� ��������һ��ԭ����\n"
			+ "C�� int number=[]={31,23,33,43,35,63}\n"
			+ "D�� ����Ĵ�С��������ı�",
			"���б�ʶ�����Ϸ����У�()\n"						//9
			+ "A��new\n"
			+ "B��$Usdollars\n"
			+ "C��1234\n"
			+ "D��car.taxi",
			"������������interface����()\n"				//10
			+ "A��private\n"
			+ "B��public\n"
			+ "C��protected\n"
			+ "D��static\r\n"
			};

	// 0��ʾ��û������
	int flag[] = {0,0,0,0,0,0,0,0,0,0};
	String answer[] = {"AC  ","AC  ","AD  ","CD  ","BC  ","AB  ","BC  ","BCD ","ACD ","ACD "};
	int getran() {
		// ��ȡδ��������Ŀ���
		int num;
		do {
			num = (int)(Math.random()*10);
		}while(flag[num]!=0);
		flag[num] = 1;
		return num;
	}
}
