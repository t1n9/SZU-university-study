package sixth;

public class HumanTest {
	public static void main(String[] args) {
		//�ֱ�ʵ������������
		Chinese aa = new Chinese("aa");
		Japanese bb = new Japanese("bb");
		English cc = new English("cc");
		//����human������������飬�������������������
		Human humans[] = {aa,bb,cc};
		//ѭ�����������ж���sayHi()����
		for(int i = 0;i<3;i++) {
			humans[i].sayHi();
		}
	}
}
