#include<stdio.h>
#include<string.h>
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

Members a, b;
int log = 0;				//������¼��½״̬��0��ʾδ��¼��1��ʾ�ѵ�¼

//Ϊ�˱����ظ�������������Ϊȫ�ֱ���
int n;
int i;		//����for�ۼ�
int l;		//�ж��û��������볤��
int t;		//�����ֵϵͳ����ʾһ�λ�Ա���
char temp;

void state() {		//״̬��ʾ
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
char chargeName() {
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
int phoneNumber() {
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

void registers() {			//ע�Ṧ��
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

void login() {				//��½����
	int n = 5;
	while (1) {				//�����û������ֻ��� 
		printf("�����������û������ֻ�����\n");
		scanf_s("%s", &b.users , 21);
		if (strcmp(a.mobileNumber,b.users) == 0 || strcmp(a.name,b.users) == 0) {
			if (a.userState == 0) {
				break;		//˵���˺�������������һ���������� 
			}
			else {
				printf("�˺�������������ϵ����Ա����\n");
			}
		}
		else {
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

void recharge() {				//��ֵ����
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

void shopping() {				//���﹦�ܣ���δ����
	if (a.memberType == 0) {
		printf("����������ͨ��Ա��ף��������죡\n");
	}
	else if (a.memberType == 1) {
		printf("��������������Ա��������Żݣ�ף��������죡\n");
	}
	else if (a.memberType == 2) {
		printf("�������ǽ𿨻�Ա��������Żݣ�ף��������죡\n");
	}

	printf("���̻���װ����...�����ڴ�Ŷ!\n");
}

int main() {
	while (1) {
		if (log == 0) {
			printf("��ӭ������������ƽ̨��ע��������1����½������2���˳��밴0\n");
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
		else if (n == 0) {
			printf("��ӭ�´ι��٣�\n");
			return 0;
		}
	}
}