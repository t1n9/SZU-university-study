package sixth;

import java.util.*;

public class Example_6 {
	public static void main(String[] args) {
		//定义两个HashSet，作为两个社团集合
		HashSet<String> a = new HashSet<String>();
		HashSet<String> b = new HashSet<String>();
		//在集合中添加社员
		a.add("张三");
		a.add("李四");
		b.add("李四");
		b.add("王五");
		//输出社员名字
		System.out.println("A社团的成员有：");
		for(String i :a) {
			System.out.print(i+" ");
		}
		System.out.println();
		System.out.println("B社团的成员有：");
		for(String i :b) {
			System.out.print(i+" ");
		}
		//将两个社团求交集，并且改变于a集合
		a.retainAll(b);
		System.out.println();
		System.out.println("两个社团同时参加的成员有：");
		for(String i :a) {
			System.out.print(i);
		}
	}
}
