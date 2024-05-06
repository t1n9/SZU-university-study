#include<stdio.h>
#include<string.h>

//��ͨ�û��ṹ����
typedef struct {
	char users[21];			//ͨ���� 
	char name[21];     		//�û���
	char mobileNumber[12];  //�ֻ�����
	char password[21];		//����
	float balance;			//���
	int memberType;		 	//��Ա���ͣ�0��ʾ��ͨ��Ա��1��ʾ������Ա��2��ʾ�𿨻�Ա
	float discount;    		//��ͨ��Աû�ۿۣ�������Ա9�ۣ��𿨻�Ա8��
	int userState;			//�˺�״̬��0��ʾ������1��ʾ����
}Members;

//����Ա�ṹ����
typedef struct {
	char chg_name[21];
	char chg_password[21];
}administrator;

administrator c = { "admin", "admin" };

//��Ʒ�ṹ����
typedef struct {
	char name[21];		//����
	int number;			//���
	float price;		//����
	int inventory;		//���
	float sum;			//������ƷӪҵ��
	int frequency;		//�������
}Goods;

//����������Ʒ����
Goods apple = { "apple",11111, 0.7, 1000, 0, 0 };
Goods banana = { "banana", 22222,3.5, 1000, 0, 0 };
Goods pineapple = { "pineapple",33333, 4.2, 1000, 0, 0 };

Members a, b;		//������������һ��������¼�û���Ϣ��һ��������½��ʱ��Ա�
int log = 0;		//������¼��½״̬��0��ʾδ��¼��1��ʾ�ѵ�¼��2��ʾ����Ա״̬

//Ϊ�˱����ظ�������������Ϊȫ�ֱ���
int number;	//��Ʒ���
int jin;	//��
float sum = 0; //��Ӫҵ��
int n;
int i;		//����for�ۼ�
int l;		//�ж��û��������볤��
int t;		//�����ֵϵͳ����ʾһ�λ�Ա���
char temp;
char temparr[] = "\0";

//״̬��ʾ
void state() {
	printf("�����û����ǣ�%s����ĵ绰�����ǣ�%s����%.2f��", a.name, a.mobileNumber, a.balance);
	if (a.memberType == 0) {
		printf("��ͨ��Ա��");
	}
	else if (a.memberType == 1) {
		printf("������Ա��");
	}
	else if (a.memberType == 2) {
		printf("�𿨻�Ա��");
	}

	if (a.userState == 0) {
		printf("�û�״̬����\n");
	}
	else {
		printf("�û�������\n");
	}
}

//ע���û�������
void chargeName() {
	printf("�������û���\n");
	scanf_s("%s", &a.name, 50);
	l = strlen(a.name);
	if (l > 20) {
		printf("�û������ó���20λ��");
		chargeName();
	}
	for (i = 0; i < l; i++) {
		temp = a.name[i];
		if (!(temp >= '0' && temp <= '9' || temp >= 'a' && temp <= 'z' || temp >= 'A' && temp <= 'Z')) {
			printf("�û������Ƿ��ַ���");
			chargeName();
		}
	}
}

//ע��ʱ�ֻ��������
void phoneNumber() {
	printf("�����������ֻ�����\n");
	scanf_s("%s", &a.mobileNumber, 50);
	l= strlen(a.mobileNumber);

	for (i = 0; i < l; i++) {
		temp = a.mobileNumber[i];
		if (!(temp >= '0' && temp <= '9')) {
			printf("�ֻ����뺬�Ƿ��ַ���");
			phoneNumber();
		}
	}
	if (l != 11) {
		printf("������11λ�ֻ����룡");
		phoneNumber();
	}
}

//ע�Ṧ��
void registers() {
	//�û�������
	chargeName();
	//�ֻ��������
	phoneNumber();
	//�������	
	while (1) {
		printf("��������������\n");
		scanf_s("%s", &a.password , 21);
		if (strlen(a.password) < 6 || strlen(a.password) > 20) {
			printf("���벻�Ϸ���");
			continue;				//�ٴ�ѭ��while
		}
		printf("���ٴ�ȷ����������\n");
		scanf_s("%s", &b.password , 21);
		if (strcmp(a.password, b.password) != 0) {
			printf("������������벻һ�£����������룡\n");
		}
		else {
			printf("ע��ɹ������½��\n");
			break;
		}
	}
	//��ʼ���û���Ϣ
	a.userState = 0;
	a.discount = 1;
	a.balance = 100;
	a.memberType = 0;
}

//����Ա��½ϵͳ
void administrator_signin() {
	int n = 5;
	printf("��Ϊ����Աϵͳ�����������Ա�˺�");
	while (1) {
		scanf_s("%s", &b.name,21);
		if (strcmp(b.name,c.chg_name)!=0) {
			printf("���޴˹���Ա��");
			continue;
		}
		else {
			break;
		}
	}
	while (1) {
		printf("���������Ա����");
		scanf_s("%s", &b.password,21);
		if (strcmp(b.password,c.chg_password)!=0) {
			printf("�������");
			continue;
		}
		else {
			log = 2;
			return;
		}
	}
}

//����Ա�޸���Ϣ
void modify() {
	while (1) {
		printf("��������Ʒ��ţ�����0�˳�����ϵͳ");
		scanf_s("%d", &number);
		if (number == apple.number) {
			printf("����1�޸ĵ��ۣ�����2�޸Ŀ��");
			scanf_s("%d", &n);
			//�޸ĵ���
			if (n == 1) {
				printf("ԭ����Ϊ%f\n�������޸ĺ�ĵ���", apple.price);
				scanf_s("%f", &apple.price);
				printf("�޸ĳɹ����ٴ��޸�");
			}
			//�޸Ŀ��
			else if (n == 2) {
				printf("ԭ���Ϊ%d\n�������޸ĺ�Ŀ��", apple.inventory);
				scanf_s("%d", &apple.inventory);
				printf("�޸ĳɹ����ٴ��޸�");
			}
		}
		else if (banana.number == number) {
			printf("����1�޸ĵ��ۣ�����2�޸Ŀ��");
			scanf_s("%d", &n);
			//�޸ĵ���
			if (n == 1) {
				printf("ԭ����Ϊ%f\n�������޸ĺ�ĵ���", banana.price);
				scanf_s("%f", &banana.price);
				printf("�޸ĳɹ����ٴ��޸�");
			}
			//�޸Ŀ��
			else if (n == 2) {
				printf("ԭ���Ϊ%d\n�������޸ĺ�Ŀ��", banana.inventory);
				scanf_s("%d", &banana.inventory);
				printf("�޸ĳɹ����ٴ��޸�");
			}
		}
		else if (pineapple.number == number) {
			printf("����1�޸ĵ��ۣ�����2�޸Ŀ��");
			scanf_s("%d", &n);
			//�޸ĵ���
			if (n == 1) {
				printf("ԭ����Ϊ%f\n�������޸ĺ�ĵ���", pineapple.price);
				scanf_s("%f", &pineapple.price);
				printf("�޸ĳɹ����ٴ��޸�");
			}
			//�޸Ŀ��
			else if (n == 2) {
				printf("ԭ���Ϊ%d\n�������޸ĺ�Ŀ��", pineapple.inventory);
				scanf_s("%d", &pineapple.inventory);
				printf("�޸ĳɹ����ٴ��޸�");
			}
		}
		else if (number == 0) {
			log = 0;
			//�˳�����ϵͳ
			printf("��ӭ������������ƽ̨��ע��������1����½������2������������9���˳��밴0\n");
			return;
		}
	}	
}

//����Ա�鿴��Ϣ
void check() {
	printf("��Ӫҵ�%f\n", sum);
	printf("���У�ƻ��Ӫҵ��Ϊ%f���㽶��Ӫҵ��Ϊ%f�����ܵ�Ӫҵ��Ϊ%f��",apple.sum,banana.sum,pineapple.sum);
	//�Ƚ�Ӫҵ��
	if (apple.sum > banana.sum && apple.sum > pineapple.sum) {
		printf("ƻ��Ӫҵ�����\n");
	}
	else if (banana.sum > pineapple.sum) {
		printf("�㽶��Ӫҵ�����\n");
	}
	else {
		printf("���ܵ�Ӫҵ�����\n");
	}
	printf("�ܹ��������%d\n", apple.frequency + banana.frequency + pineapple.frequency);
	printf("���У�ƻ����������%d���㽶��������%d��������������%d��", apple.frequency, banana.frequency, pineapple.frequency);
	//�ȽϹ������
	if (apple.frequency > banana.frequency && apple.frequency > pineapple.frequency) {
		printf("ƻ���������������\n");
	}
	else if (banana.frequency > pineapple.frequency) {
		printf("�㽶�����������\n");
	}
	else {
		printf("���������������\n");
	}
}

//����Աɾ���û�
void usersDelete() {
	printf("������Ҫɾ���û����û������ֻ���");
	scanf_s("%s", &b.users, 21);
	if (strcmp(a.mobileNumber, b.users) == 0 || strcmp(a.name, b.users) == 0) {
		printf("ɾ�����û�������Ϣ���㣬ȷ��������1");
		scanf_s("%d", &n);
		if (n == 1) {
			printf("ɾ����...\nɾ���ɹ���");
			a.balance = 0;
			a.discount = 1;
			a.memberType = 0;
			a.userState = 0;
			for (i = 0; a.name[i] != 0; i++) {
				a.name[i] = 0;
			}
			for (i = 0; a.users[i] != 0; i++) {
				a.users[i] = 0;
			}
			for (i = 0; a.mobileNumber[i] != 0; i++) {
				a.mobileNumber[i] = 0;
			}
			for (i = 0; a.password[i] != 0; i++) {
				a.password[i] = 0;
			}
			return;
		}
	}
}

//��½����
void login() {
	int n = 5;
	while (1) {				//�����û������ֻ��� 
		printf("�����������û������ֻ����룬ע��������0\n");
		scanf_s("%s", &b.users , 21);
		if (strcmp(a.mobileNumber,b.users) == 0 || strcmp(a.name,b.users) == 0) {
			if (a.userState == 0) {
				break;		//˵���˺�������������һ���������� 
			}
			else {
				printf("�˺�������������ϵ����Ա����\n");
			}
		}
		else if (strcmp("0", b.users) == 0) {
			printf("������ת��ע��ϵͳ...\n");
			registers();
		}
		else{
			printf("���޴��˺���Ϣ�����������룡\n");
		}
	}
	while (1) {				//�������� 
		if (n == 0) {			//���ж��˺��Ƿ����� 
			printf("�˺�������������ϵ����Ա����\n");
			a.userState = 1;
			login();
		}
		printf("����������\n");
		scanf_s("%s", b.password , 21);
		if (strcmp(a.password, b.password) == 0) {
			printf("��½�ɹ���\n");
			log = 1;
			state();
			break;
		}
		else {
			printf("�������������%d�λ�����������\n", --n);
		}
	}
}

//��ֵ����
void recharge() {
	if (log == 0) {
		printf("�û�δ��¼��������ת����½ҳ��...\n");
		login();
	}
	float n;					//��ֵ���
	t = 0;
	while (1) {
		if (t == 0) {
			printf("***********************************************\n");
			printf("*��ֵ10000����������Ա\t��ֵ50000�����𿨻�Ա*\n");
			printf("*������Ա���������\t   �𿨻�Ա���������*\n");
			printf("***********************************************\n");
		}
		t = 1;
		printf("�������Ϊ��%.2f���������ֵ���˳�������0\n", a.balance);
		scanf_s("%f", &n);
		if (n == 0) {
			state();
			return;
		}
		else if (n == 10000) {			//����
			a.balance += n;
			if (a.discount == 1) {
				a.memberType = 1;
				a.discount = 0.9;
				printf("��ϲ�����ѳ�Ϊ������Ա�����о����Żݣ�\n");
			}
		}
		else if (n == 50000) {			//��
			a.balance += n;
			if(a.memberType != 2){
				a.discount = 0.8;
				a.memberType = 2;
				printf("��ϲ�����ѳ�Ϊ�𿨻�Ա�����а����Żݣ�\n");
			}
		}
		else {							//����
			a.balance += n;
			printf("��ֵ�ɹ���\n");
		}
	}
}

//���﹦��
void shopping() {
	if (a.memberType == 0) {
		printf("����������ͨ��Ա��ף��������죡\n");
	}
	else if (a.memberType == 1) {
		printf("��������������Ա��������Żݣ�ף��������죡\n");
	}
	else if (a.memberType == 2) {
		printf("�������ǽ𿨻�Ա��������Żݣ�ף��������죡\n");
	}
	while (1) {
		printf("������Ҫ�������Ʒ��ţ�����0�˳��������");
		scanf_s("%d", &number);
		if (number == 0) {
			break;
		}
		else if (number == apple.number) {
			printf("ƻ������%f��������Ҫ������ٽ��أ�", apple.price);
			scanf_s("%d", &jin);
			if ((a.balance - apple.price * jin * a.discount) > 0 && apple.inventory > 0) {
				a.balance -= apple.price * jin * a.discount;
				printf("����ɹ�����Ʒ���������ʹ������ջ���ַ��\n");
				sum += apple.price * jin * a.discount;
				apple.sum += apple.price * jin * a.discount;
				apple.frequency += 1;
				apple.inventory -= jin;
			}
			else if (apple.inventory <= 0) {
				printf("�ܱ�Ǹ����Ʒ��治�㣬��ȴ�����...");
			}
			else {
				printf("���㣡������ת����ֵҳ��...\n");
				recharge();
			}
		}
		else if (number == banana.number) {
			printf("�㽶����%f��������Ҫ������ٽ��أ�", banana.price);
			scanf_s("%d", &jin);
			if ((a.balance - banana.price * jin * a.discount) > 0 && banana.inventory > 0) {
				a.balance -= banana.price * jin * a.discount;
				printf("����ɹ�����Ʒ���������ʹ������ջ���ַ��\n");
				sum += banana.price * jin * a.discount;
				banana.sum += banana.price * jin * a.discount;
				banana.frequency += 1;
				banana.inventory -= jin;
			}
			else if (banana.inventory <= 0) {
				printf("�ܱ�Ǹ����Ʒ��治�㣬��ȴ�����...");
			}
			else {
				printf("���㣡������ת����ֵҳ��...\n");
				recharge();
			}
		}
		else if (number == pineapple.number) {
			printf("���ܵ���%f��������Ҫ������ٽ��أ�", pineapple.price);
			scanf_s("%d", &jin);
			if ((a.balance - pineapple.price * jin * a.discount) > 0 && pineapple.inventory > 0) {
				a.balance -= pineapple.price * jin * a.discount;
				printf("����ɹ�����Ʒ���������ʹ������ջ���ַ��\n");
				sum += pineapple.price * jin * a.discount;
				pineapple.sum += pineapple.price * jin * a.discount;
				pineapple.frequency += 1;
				pineapple.inventory -= jin;
			}
			else if (pineapple.inventory <= 0) {
				printf("�ܱ�Ǹ����Ʒ��治�㣬��ȴ�����...");
			}
			else {
				printf("���㣡������ת����ֵҳ��...\n");
				recharge();
			}
		}
	}
	
}

//������
int main() {
	while (1) {
		if (log == 0) {
			printf("��ӭ������������ƽ̨��ע��������1����½������2������������9���˳��밴0\n");
		}
		else if (log == 2) {
			printf("�޸���Ʒ��Ϣ�밴1���鿴��̨�����밴2��ɾ���û��밴3���˳��밴0\n");
			scanf_s("%d", &n);
			if (n == 1) {
				modify();
			}
			else if (n == 2) {
				check();
				continue;
			}
			else if (n == 3) {
				usersDelete();
			}
			else if (n == 0) {
				log = 0;
				continue;
			}
		}
		else {				//��ֵ�͹��﹦���ڵ�½��ſɿ���
			printf("��ֵ�밴3�������밴4���˳��밴0\n");
		}
		scanf_s("%d", &n);
		if (n == 1) {
			registers();
		}
		else if (n == 2) {
			login();
		}
		else if (n == 3) {
			recharge();
		}
		else if (n == 4) {
			shopping();
		}
		else if (n == 9) {
			administrator_signin();
		}
		else if (n == 0) {
			printf("��ӭ�´ι��٣�\n");
			return 0;
		}
	}
}