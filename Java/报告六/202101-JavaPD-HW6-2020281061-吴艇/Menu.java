package sixth;

import java.util.*;

public class Menu {
	public static void main(String[] args) {
		String menu = "北京烤鸭：199.1元；西芹炒肉：11.8元；酸菜鱼：59.1元；铁板牛柳：32.1元";
		double sum = 0;
		Scanner scanner = new Scanner(menu);
		//调用useDelimiter()方法将正则表达式
		scanner.useDelimiter("[^0123456789.^]+");
		while(scanner.hasNext()) {
			try {
				//此时scanner对象中就只有字符串中的double值了
				double price = scanner.nextDouble();
				sum+=price;
			}
			catch(InputMismatchException exp) {
				String t = scanner.next();
			}
		}
		System.out.println("四道菜的总价："+sum+"元");
	}
}