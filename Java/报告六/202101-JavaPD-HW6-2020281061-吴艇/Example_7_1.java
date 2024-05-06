package sixth;

import java.util.*;
public class Example_7_1 {
	public static void main(String[] args) {
		TreeMap<Nation_1,Integer> nation = new TreeMap<Nation_1,Integer>();		
		nation.put(new Nation_1("美国",20932750,44918565),44918565);
		nation.put(new Nation_1("中华人民共和国",14722837,124924),124924);
		nation.put(new Nation_1("日本",5048688,1706675),1706675);
		nation.put(new Nation_1("德国",3803014,4284354),4284354);
		nation.put(new Nation_1("英国",2710970,8006660),8006660);
		nation.put(new Nation_1("印度",2708770,33893002),33893002);
		nation.put(new Nation_1("法国",2598907,7038701),7038701);
		nation.put(new Nation_1("意大利",1884935,4689341),4689341);
		nation.put(new Nation_1("加拿大",1643408,1647142),1647142);
		nation.put(new Nation_1("韩国",1630871,323379),323379);
		for(Nation_1 i :nation.keySet()) {
			System.out.println(i.name+"GDP2020:"+i.GDP2020+",COVID19:"+i.COVID19);
		}
	}
}
