package sixth;

import java.util.*;

public class Example_6 {
	public static void main(String[] args) {
		//��������HashSet����Ϊ�������ż���
		HashSet<String> a = new HashSet<String>();
		HashSet<String> b = new HashSet<String>();
		//�ڼ����������Ա
		a.add("����");
		a.add("����");
		b.add("����");
		b.add("����");
		//�����Ա����
		System.out.println("A���ŵĳ�Ա�У�");
		for(String i :a) {
			System.out.print(i+" ");
		}
		System.out.println();
		System.out.println("B���ŵĳ�Ա�У�");
		for(String i :b) {
			System.out.print(i+" ");
		}
		//�����������󽻼������Ҹı���a����
		a.retainAll(b);
		System.out.println();
		System.out.println("��������ͬʱ�μӵĳ�Ա�У�");
		for(String i :a) {
			System.out.print(i);
		}
	}
}
