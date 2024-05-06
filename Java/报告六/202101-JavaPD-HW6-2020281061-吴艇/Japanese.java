package sixth;

public class Japanese implements Human{
	String name;
	Japanese(String _name){
		name = _name;
	}
	public double sayHi() {
		System.out.println("kon ni chi wa!");
		return 0;
	}
}
