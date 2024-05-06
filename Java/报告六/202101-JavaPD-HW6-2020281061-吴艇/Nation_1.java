package sixth;

import java.util.*;

//用comparable接口，定义compareTo()实现排序
public class Nation_1 implements Comparable<Nation_1>{

	public String name;
	public int GDP2020,COVID19;
	Nation_1(String name,int GDP2020,int COVID19){
		this.name = name;
		this.GDP2020 = GDP2020;
		this.COVID19 = COVID19;
	}
	
	public int compareTo(Nation_1 o) {
		return (this.COVID19 - o.COVID19);
	}
}
