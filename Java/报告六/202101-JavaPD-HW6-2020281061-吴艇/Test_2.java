package sixth;

public class Test_2 {
	public static void main(String[] args) {
		//����һ���ַ���
		String s = "Hi, Good Morning";
		System.out.println(m(s));
	}
	public static int m(String s) {
		int count = 0;
		for(int i = 0;i<s.length();i++) {
			//charAt()������ȡs�ַ�������i�±�λ���ַ�
			//Character.isUpperCase�ж��ַ��Ƿ�Ϊ��д
			if(Character.isUpperCase(s.charAt(i)))
				//����Ǵ�д��count����
				count++;
		}
		return count;
	}
}
