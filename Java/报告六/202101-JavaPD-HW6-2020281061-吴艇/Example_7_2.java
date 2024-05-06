package sixth;

import java.util.*;
public class Example_7_2 {
	public static void main(String[] args) {
		TreeMap<Nation_2,Integer> nation = new TreeMap<Nation_2,Integer>(
				new java.util.Comparator<Nation_2>(){
					public int compare(Nation_2 o1, Nation_2 o2) {
						return (o1.COVID19 - o2.COVID19);
					}
				}
			);		
		nation.put(new Nation_2("美国",20932750,44918565),44918565);
		nation.put(new Nation_2("中华人民共和国",14722837,124924),124924);
		nation.put(new Nation_2("日本",5048688,1706675),1706675);
		nation.put(new Nation_2("德国",3803014,4284354),4284354);
		nation.put(new Nation_2("英国",2710970,8006660),8006660);
		nation.put(new Nation_2("印度",2708770,33893002),33893002);
		nation.put(new Nation_2("法国",2598907,7038701),7038701);
		nation.put(new Nation_2("意大利",1884935,4689341),4689341);
		nation.put(new Nation_2("加拿大",1643408,1647142),1647142);
		nation.put(new Nation_2("韩国",1630871,323379),323379);
		for(Nation_2 i :nation.keySet()) {
			System.out.println(i.name+"GDP2020:"+i.GDP2020+",COVID19:"+i.COVID19);
		}
	}
}
