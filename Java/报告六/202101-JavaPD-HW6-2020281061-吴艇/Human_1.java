package sixth;

public abstract class Human {
	//变量name
	String name;
	//构造函数获取变量值
	Human(String _name){
		name = _name;
	}
	//抽象方法
	public abstract double sayHi();
}