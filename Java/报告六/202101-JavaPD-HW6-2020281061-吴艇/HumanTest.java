package sixth;

public class HumanTest {
	public static void main(String[] args) {
		//分别实例化三个对象
		Chinese aa = new Chinese("aa");
		Japanese bb = new Japanese("bb");
		English cc = new English("cc");
		//创建human抽象类对象数组，并将上面三个对象存入
		Human humans[] = {aa,bb,cc};
		//循环调用数组中对象sayHi()方法
		for(int i = 0;i<3;i++) {
			humans[i].sayHi();
		}
	}
}
