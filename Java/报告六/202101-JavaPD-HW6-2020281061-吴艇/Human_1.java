package sixth;

public abstract class Human {
	//����name
	String name;
	//���캯����ȡ����ֵ
	Human(String _name){
		name = _name;
	}
	//���󷽷�
	public abstract double sayHi();
}