package sixth;

import java.util.*;

public class Out {
	//����д
	public static void upper(Scanner scanner) {
		scanner.useDelimiter("[^A-Z.]+");
		while(scanner.hasNext()){
			try {
				System.out.print(scanner.next());
			}
			catch(InputMismatchException exp){
				String t = scanner.next();
			}
		}
		System.out.println();
	}
	//���Сд
	public static void lower(Scanner scanner) {
		scanner.useDelimiter("[^a-z.]+");
		while(scanner.hasNext()){
			try {
				System.out.print(scanner.next());
			}
			catch(InputMismatchException exp){
				String t = scanner.next();
			}
		}
		System.out.println();
	}
	//�������
	public static void num(Scanner scanner) {
		scanner.useDelimiter("[^0-9.]+");
		while(scanner.hasNext()){
			try {
				System.out.print(scanner.next());
			}
			catch(InputMismatchException exp){
				String t = scanner.next();
			}
		}
		System.out.println();
	}
	public static void main(String[] args) {
		//�����ַ���
		String str = "Aa123bEFGaaa49023";
		//ѭ����������10��
		for(int j = 0;j < 10;j++) {
			Scanner scanner = new Scanner(str);
			upper(scanner);
		}for(int j = 0;j < 10;j++) {
			Scanner scanner = new Scanner(str);
			lower(scanner);
		}for(int j = 0;j < 10;j++) {
			Scanner scanner = new Scanner(str);
			num(scanner);
		}
	}
}
