package sixth;

public class Test_1 {
	public static void main(String[] args) {
		//�Ƚ�patternģʽ���������Ƿ���ȫ��ͬ�����ز���ֵ
		System.out.println("Hi, ABC, good".matches("ABC "));
		//�˴�.*��ʾ��һ�������ַ�����ֻҪ�����г���ABC����ƥ����
		System.out.println("Hi, ABC, good".matches(".*ABC.*"));
		//replaceAll()�����е���������
		//��һ��������Ҫ��[]����������ʾ���滻���ַ�
		//�ڶ�������Ϊ�滻���ַ��������滻����ַ���
		System.out.println("A,B;C".replaceAll(",;","#"));
		System.out.println("A,B;C".replaceAll("[,;]","#"));
		//split()�������ַ������մ������[]�������ַ����зֽ�
		String[] token = "A,B;C".split("[,;]");
		//�ֽ������ַ��������У������forѭ��������ѭ�����
		for(int i = 0;i<token.length;i++)
			System.out.print(token[i]+" ");
	}
}
