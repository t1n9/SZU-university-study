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
		//�ڴ˷����У������sΪֵ������resource
		//�ʸı�s֮���������е�s��û���ܵ�Ӱ��
		s = s + " and HTML";
		//append�������Խ��ַ���׷�ӵ�StringBuilder������
		builder.append(" and HTML");
	}
}
