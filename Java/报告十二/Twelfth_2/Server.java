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
		System.out.println("服务端开始运行");
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
	                System.out.println("收到请求："+info);
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
	
	
	
	static int st = 0;		//单类型出题数
	static int jt = 0;
	static int mt = 0;
	
	static String type[] = {"单选题：","判断题：","多选题："};
	static Single s = new Single();
	static Judge j = new Judge();
	static Multi m = new Multi();
	static String getQuestions() {
		String Q = null;
		int k = 0;		//单类型题号
		int i = 0;		//题目类型
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





// 题库
class Single{
	// 单选题
		String single[]= {
				"变量命名规范说法正确的是（）\n"		//1
				+ "A、 变量由字母、下划线、数字、$符号随意组成；\n"
				+ "B、 变量不能以数字作为开头；\n"
				+ "C、 A和a在java中是同一个变量；\n"
				+ "D、 不同类型的变量，可以起相同的名字；",
				"下列javaDoc注释正确的是（）\n"		//2
				+ "A、 /*我爱北京天安门*/\n"
				+ "B、 //我爱北京天安门*/\n"
				+ "C、 /**我爱北京天安门*/\n"
				+ "D、 /*我爱北京天安门**/",
				"为一个boolean类型变量赋值时，可以使用()方式\n"		//3
				+ "A、 boolean = 1;\n"
				+ "B、 boolean a = (9 >= 10);\n"
				+ "C、 boolean a=\"真\";\n"
				+ "D、 boolean a = = false;",
				"以下()不是合法的标识符\n"		//4
				+ "A、 STRING\n"
				+ "B、 x3x;\n"
				+ "C、 void\n"
				+ "D、 de$f",
				"（）表达式不可以作为循环条件\n"		//5
				+ "A、 i++;\n"
				+ "B、 i>5;\n" 
				+ "C、 bEqual = str.equals(\"q\");\n" 
				+ "D、 count = = i;",
				"下列值不为true的表达式有（）。\n" 		//6
				+ "A、 \"john\" = = \"john\"\n" 
				+ "B、 \"john\".equals(\"john\")\n" 
				+ "C、 \"john\" = \"john\"\n" 
				+ "D、 \"john\".equals(new String(\"john\"))",
				"对象的特征在类中表示为变量，称为类的（）。\n"		//7
				+ "A、 对象\n"
				+ "B、 属性\n"
				+ "C、 方法\n"
				+ "D、 数据类型",
				"在Java中,关于构造方法，下列说法错误的是( )\n"		//8
				+ "A、 构造方法的名称必须与类名相同\n"
				+ "B、 构造方法可以带参数\n" 
				+ "C、 构造方法不可以重载\n" 
				+ "D、 构造方法绝对不能有返回值",
				"在JAVA的异常处理模型中，能单独和finally语句一起使用的块是（）。\n"		//9
				+ "A、 try\n"
				+ "B、 catch\n"
				+ "C、 throw\n"
				+ "D、 throws",
				"String s = JOptionPane.showInputDialog(frame,\"请输入您所在城市名称：\");上面的代码执行后，会弹出一个输入对话框，如果用户点击对话框右上角上的“X”图标（关闭按钮），那么返回值s是：\n"		//10
				+ "A.\"\"\n"
				+ "B.null\r\n"
				+ "C.NULL\r\n"
				+ "D.false"
		};
		int flag[] = {0,0,0,0,0,0,0,0,0,0};
		String answer[] = {"B   ","C   ","B   ","C   ","A   ","C   ","B   ","C   ","A   ","B   "};
		int getran() {
			// 获取未出过的题目序号
			int num;
			do {
				num = (int)(Math.random()*10);
			}while(flag[num]!=0);
			flag[num] = 1;
			return num;
		}
}

class Judge {
	// 判断题
	String judge[]= {
			"为了实现复杂的界面布局，JFrame的内容区可以设置多个Layout。",		//1
			"密码框类JPasswordField是文本框类\nJTextField的子类。文本框用JTextField.getText()获取文本内容，密码框可以使用JPasswordField.getText()获取密码文本",		//2
			"快捷键是为了提升效率而设，菜单项一定要设置快捷键。",		//3
			"一个类实现一个接口，则该类必须实现接口中的所有方法。",	//4
			"在Java的方法中定义一个常量要用const关键字"	,		//5
			"用final修饰的变量叫常量。",					//6
			"一个类可以实现多接口。",					//7
			"Unicode码与ASCII码相同。",				//8
			"抽象方法没有方法体。",						//9
			"Java中，一个类可以有多个直接父类。",			//10
	};
	int flag[] = {0,0,0,0,0,0,0,0,0,0};
	String answer[] = {"N   ","N   ","N   ","Y   ","N   ","Y   ","Y   ","N   ","N   ","N   "};
	int getran() {
		// 获取未出过的题目序号
		int num;
		do {
			num = (int)(Math.random()*10);
		}while(flag[num]!=0);
		flag[num] = 1;
		return num;
	}
}

class Multi {
	// 多选题
	String multi[]= {
			"下列（）属于引用数据类型（）\n"		//1
			+ "A、 String\n"
			+ "B、 char\n"
			+ "C、 用户自定义的Student类类型\n"
			+ "D、 int",		
			"以下用于创建容器对象的类是（）\n"		//2
			+ "A、 Frame\n"
			+ "B、 Checkbox\n"
			+ "C、 Panel\n"
			+ "D、 TextField)",
			"下面哪些是正确的？()\n"			//3
			+ "A.MouseAdapter是一个类\n"
			+ "B.MouseAdapter是一个接口\n"
			+ "C.MouseListener是一个类\n"
			+ "D.MouseListener是一个接口",
			"以下属于面向对象的特征的是（）。\n"		//4
			+ "A.重载\n"
			+ "B.重写\n"
			+ "C.封装\n"
			+ "D.继承",
			"接口和抽象类描述正确的有（）\n"		//5	
			+ "A) 抽象类没有构造函数\n"			
			+ "B) 接口没有构造函数\n"
			+ "C) 抽象类不允许多继承\n"
			+ "D) 接口中的方法可以有方法体",
			"在Java接口中，下列选项中有效的方法声明是（）。\n"		//6
			+ "A、 public void aMethod();\n"
			+ "B、 void aMethod();\n"
			+ "C、 protected void aMethod();\n"
			+ "D、 private void aMethod();",
			"下面哪些不是java的简单数据类型?()\n"				//7
			+ "A. short\n"
			+ "B. Boolean\n"
			+ "C. Double\n"
			+ "D. float\n",
			"下列说法错误的有()\n"						//8
			+ "A． 数组是一种对象\n"
			+ "B． 数组属于一种原生类\n"
			+ "C． int number=[]={31,23,33,43,35,63}\n"
			+ "D． 数组的大小可以任意改变",
			"下列标识符不合法的有？()\n"						//9
			+ "A．new\n"
			+ "B．$Usdollars\n"
			+ "C．1234\n"
			+ "D．car.taxi",
			"不能用来修饰interface的有()\n"				//10
			+ "A．private\n"
			+ "B．public\n"
			+ "C．protected\n"
			+ "D．static\r\n"
			};

	// 0表示还没出过题
	int flag[] = {0,0,0,0,0,0,0,0,0,0};
	String answer[] = {"AC  ","AC  ","AD  ","CD  ","BC  ","AB  ","BC  ","BCD ","ACD ","ACD "};
	int getran() {
		// 获取未出过的题目序号
		int num;
		do {
			num = (int)(Math.random()*10);
		}while(flag[num]!=0);
		flag[num] = 1;
		return num;
	}
}
