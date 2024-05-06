package sixth;

public class Test_1 {
	public static void main(String[] args) {
		//比较pattern模式串与主串是否完全相同，返回布尔值
		System.out.println("Hi, ABC, good".matches("ABC "));
		//此处.*表示有一个或多个字符，故只要主串中出现ABC即可匹配上
		System.out.println("Hi, ABC, good".matches(".*ABC.*"));
		//replaceAll()方法中的两个参数
		//第一个参数需要用[]括起来，表示被替换的字符
		//第二个参数为替换的字符。返回替换后的字符串
		System.out.println("A,B;C".replaceAll(",;","#"));
		System.out.println("A,B;C".replaceAll("[,;]","#"));
		//split()方法将字符串按照传入的用[]包含的字符进行分解
		String[] token = "A,B;C".split("[,;]");
		//分解后存入字符串数组中，最后用for循环将数组循环输出
		for(int i = 0;i<token.length;i++)
			System.out.print(token[i]+" ");
	}
}
