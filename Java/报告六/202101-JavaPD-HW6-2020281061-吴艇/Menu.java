package sixth;

import java.util.*;

public class Menu {
	public static void main(String[] args) {
		String menu = "������Ѽ��199.1Ԫ�����۳��⣺11.8Ԫ������㣺59.1Ԫ������ţ����32.1Ԫ";
		double sum = 0;
		Scanner scanner = new Scanner(menu);
		//����useDelimiter()������������ʽ
		scanner.useDelimiter("[^0123456789.^]+");
		while(scanner.hasNext()) {
			try {
				//��ʱscanner�����о�ֻ���ַ����е�doubleֵ��
				double price = scanner.nextDouble();
				sum+=price;
			}
			catch(InputMismatchException exp) {
				String t = scanner.next();
			}
		}
		System.out.println("�ĵ��˵��ܼۣ�"+sum+"Ԫ");
	}
}