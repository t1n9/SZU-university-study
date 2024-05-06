package sixth;

public class English implements Human{
	String name;
	English(String _name){
		name = _name;
	}
	public double sayHi() {
		System.out.println("Hello!");
		return 0;
	}
}
