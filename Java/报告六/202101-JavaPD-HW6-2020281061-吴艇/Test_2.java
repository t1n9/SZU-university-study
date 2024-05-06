package sixth;

public class Test_2 {
	public static void main(String[] args) {
		//定义一个字符串
		String s = "Hi, Good Morning";
		System.out.println(m(s));
	}
	public static int m(String s) {
		int count = 0;
		for(int i = 0;i<s.length();i++) {
			//charAt()方法获取s字符串中以i下标位的字符
			//Character.isUpperCase判断字符是否为大写
			if(Character.isUpperCase(s.charAt(i)))
				//如果是大写，count自增
				count++;
		}
		return count;
	}
}
