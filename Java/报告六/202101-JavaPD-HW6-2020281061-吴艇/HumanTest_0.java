package sixth;

public class HumanTest_0 {
	public static void main(String[] args) {
		//�ֱ�ʵ������������
		Chinese_0 aa = new Chinese_0("aa");
		Japanese_0 bb = new Japanese_0("bb");
		English_0 cc = new English_0("cc");
		//����human������������飬�������������������
		Human_0 humans[] = {aa,bb,cc};
		//ѭ�����������ж���sayHi()����
		for(int i = 0;i<3;i++) {
			humans[i].sayHi();
		}
	}
}
