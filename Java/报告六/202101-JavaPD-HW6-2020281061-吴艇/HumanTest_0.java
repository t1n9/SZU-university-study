package sixth;

public class HumanTest_0 {
	public static void main(String[] args) {
		//分别实例化三个对象
		Chinese_0 aa = new Chinese_0("aa");
		Japanese_0 bb = new Japanese_0("bb");
		English_0 cc = new English_0("cc");
		//创建human抽象类对象数组，并将上面三个对象存入
		Human_0 humans[] = {aa,bb,cc};
		//循环调用数组中对象sayHi()方法
		for(int i = 0;i<3;i++) {
			humans[i].sayHi();
		}
	}
}
