package sixth;

public class Test_3 {

	public static void main(String[] args) {
		String s = "Java";
		StringBuilder builder = new StringBuilder(s);
		change(s,builder);

		System.out.println(s);
		System.out.println(builder);
	}
	private static void change(String s,StringBuilder builder) {
		//在此方法中，传入的s为值而不是resource
		//故改变s之后，主方法中的s并没有受到影响
		s = s + " and HTML";
		//append方法可以将字符串追加到StringBuilder对象中
		builder.append(" and HTML");
	}
}
