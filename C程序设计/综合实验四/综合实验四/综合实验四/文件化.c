#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//��ͨ�û��ṹ����
typedef struct users{
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
	float inventory;	//���
	float sum;			//������ƷӪҵ��
	int frequency;		//�������
}Goods;
//����������Ʒ����o��ŵ�ǰ����kΪ�հ׶���
Goods  o, k;
Goods apple = { "apple",11111,0.75,1000,0,0 };
Goods banana = { "banana",22222,3.5,1000,0,0 };
Goods pineapple = { "pineapple",33333,4.2,1000,0,0};

//�����嵥�ṹ����
typedef struct {
	float appleNumber;
	float bananaNumber;
	float pineappleNumber;
	float listsum;
}shoppingList;
//list1��ŵ�ǰ�嵥��kongbai��������嵥
shoppingList list1 = { 0,0,0,0 };
shoppingList kongbaiList = { 0,0,0,0 };

//a�����ݴ�ע����Ϣ��b�����ݴ��½д����Ϣ��m������ȡ�û���Ϣ��d�ڸ��ǵ�ʱ���ã�kongbaiһֱ���ǿհ�
Members a, b, d, m;
Members kongbai = { "","","","",0,3,0,3 };
int log = 0;		//������¼��½״̬��0��ʾδ��¼��1��ʾ�ѵ�¼��2��ʾ����Ա״̬

//Ϊ�˱����ظ�������������Ϊȫ�ֱ���
int number;	//��Ʒ���
float jin;	//��
float sum = 0; //��Ӫҵ��
int n;
int i;		//����for�ۼ�
int l;		//�ж��û��������볤��
int t;		//�����ֵϵͳ����ʾһ�λ�Ա���
char temp;

//����ԭ�û�����
void reWriteUsers() {
	FILE* fp = fopen("users.txt", "r+");
	//d�հ׶���mΪ�û����ݶ�����ͬ�ṹ��
	while (fread(&d, sizeof(Members), 1, fp) == 1) {
		if (strcmp(d.name, m.name) == 0 || strcmp(d.mobileNumber,m.mobileNumber) == 0) {
			fseek(fp, -(int)sizeof(Members), SEEK_CUR);	//ָ�������޸�Ŀ��ǰ
			fwrite(&m, sizeof(Members), 1, fp);		//д���µ�m����ԭm
			break;
		}
	}
	fclose(fp);
}

//����ԭ��Ʒ���ݣ�������Ʒ��
void reWriteGoods() {
	//oΪ��ǰ�޸ĵ���Ʒ
	FILE* fp = fopen("goods.txt", "r+");
	while (fread(&k, sizeof(Goods), 1, fp) == 1) {
		if (strcmp(k.name, o.name) == 0) {
			fseek(fp, -(int)sizeof(Goods), SEEK_CUR);	//ָ�������޸�Ŀ��ǰ
			fwrite(&o, sizeof(Goods), 1, fp);
			break;
		}
	}
	fclose(fp);
}

//״̬��ʾ
void state() {
	printf("�����û����ǣ�%s����ĵ绰�����ǣ�%s����%.2f��", m.name, m.mobileNumber, m.balance);
	if (m.memberType == 0) {
		printf("��ͨ��Ա��");
	}
	else if (m.memberType == 1) {
		printf("������Ա��");
	}
	else if (m.memberType == 2) {
		printf("�𿨻�Ա��");
	}

	if (m.userState == 0) {
		printf("�û�״̬����\n");
	}
	else {
		printf("�û�������\n");
	}
}

//ע���û�������(�û����Ѳ���)
void chargeName() {
	while (1) {
		FILE* fp = fopen("users.txt", "a+");
		printf("�������û���\n");
		scanf_s("%s", &a.name, 50);
		fread(&d, sizeof(Members), 1, fp);
		while (1) {
			if (strcmp(d.name, a.name) == 0) {
				printf("�û����Ѵ��ڣ�������ע�ᣡ\n");
				i = 0;
				fclose(fp);
				return;
			}
			else {
				if (!feof(fp)) {
					fread(&d, sizeof(Members), 1, fp);
				}
				else {
					//�û�����δ���ڣ��������һ��
					fclose(fp);
					i = 1;
					break;
				}
			}
		}
		l = strlen(a.name);
		if (l > 20) {
			printf("�û������ó���20λ��\n�����������û���\n");
			continue;
		}
		for (i = 0; i < l; i++) {
			temp = a.name[i];
			if (!(temp >= '0' && temp <= '9' || temp >= 'a' && temp <= 'z' || temp >= 'A' && temp <= 'Z')) {
				printf("�û������Ƿ��ַ���\n�����������û���\n");
				continue;
			}
		}
		//����if�����˾�break����
		i = 1;
		break;
	}
	
}

//ע��ʱ�ֻ��������(�ֻ����Ѳ���)
void phoneNumber() {
	while (1) {
		FILE* fp = fopen("users.txt", "r+");
		printf("�����������ֻ�����\n");
		scanf_s("%s", &a.mobileNumber, 50);
		fread(&d, sizeof(Members), 1, fp);
		while (1) {
			if (strcmp(d.mobileNumber, a.mobileNumber) == 0) {
				printf("�ֻ����Ѵ��ڣ�������ע�ᣡ\n");
				i = 0;
				fclose(fp);
				return;
			}
			else {
				if (!feof(fp)) {
					fread(&d, sizeof(Members), 1, fp);
				}
				else {
					//�ֻ����뻹δ���ڣ��������һ��
					fclose(fp);
					i = 1;
					break;
				}
			}
		}
		l = strlen(a.mobileNumber);
		for (i = 0; i < l; i++) {
			temp = a.mobileNumber[i];
			if (!(temp >= '0' && temp <= '9')) {
				printf("�ֻ����뺬�Ƿ��ַ���");
				continue;
			}
		}
		if (l != 11) {
			printf("�ֻ����볤��ӦΪ11λ");
			continue;
		}
		//����if�����ͳɹ�
		i = 1;
		break;
	}
}

//ע�Ṧ��
void registers() {
	//�û�������
	chargeName();
	//�û����ظ�������ע��
	if (i == 0) return;
	//�ֻ��������
	phoneNumber();
	//�ֻ����ظ�������ע��
	if (i == 0) return;
	//�������	
	while (1) {
		printf("��������������\n");
		scanf_s("%s", &a.password, 21);
		if (strlen(a.password) < 6 || strlen(a.password) > 20) {
			printf("���벻�Ϸ�������Ӧ����6λ���ϣ�");
			continue;				//�ٴ�ѭ��while
		}
		printf("���ٴ�ȷ����������\n");
		scanf_s("%s", &b.password, 21);
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
	FILE* fp = fopen("users.txt", "a+");
	fwrite( &a, sizeof(struct users), 1, fp);
	fclose(fp);
}

//����Ա��½ϵͳ
void administrator_signin() {
	int n = 5;
	printf("��Ϊ����Աϵͳ�����������Ա�˺�");
	while (1) {
		scanf_s("%s", &b.name, 21);
		if (strcmp(b.name, c.chg_name) != 0) {
			printf("���޴˹���Ա��");
			continue;
		}
		else {
			break;
		}
	}
	while (1) {
		printf("���������Ա����");
		scanf_s("%s", &b.password, 21);
		if (strcmp(b.password, c.chg_password) != 0) {
			printf("�������");
			continue;
		}
		else {
			log = 2;
			return;
		}
	}
}

//����Ա�޸���Ϣ(��Ʒ�����Ѹ���)
void modify() {
	while (1) {
		printf("��������Ʒ��ţ�����0����");
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
				printf("ԭ���Ϊ%.2f\n�������޸ĺ�Ŀ��", apple.inventory);
				scanf_s("%f", &apple.inventory);
				printf("�޸ĳɹ����ٴ��޸�");
			}
			o = apple;
			reWriteGoods();
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
				printf("ԭ���Ϊ%.2f\n�������޸ĺ�Ŀ��", banana.inventory);
				scanf_s("%f", &banana.inventory);
				printf("�޸ĳɹ����ٴ��޸�");
			}
			o = banana;
			reWriteGoods();
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
				printf("ԭ���Ϊ%.2f\n�������޸ĺ�Ŀ��", pineapple.inventory);
				scanf_s("%f", &pineapple.inventory);
				printf("�޸ĳɹ����ٴ��޸�");
			}
			o = pineapple;
			reWriteGoods();
		}
		else if (number == 0) {
			log = 0;
			//�˳�����ϵͳ
			return;
		}
	}
}

//����Ա�鿴��Ϣ
void check() {
	printf("��Ӫҵ�%.2f\n", sum);
	printf("���У�ƻ��Ӫҵ��Ϊ%.2f���㽶��Ӫҵ��Ϊ%.2f�����ܵ�Ӫҵ��Ϊ%.2f��", apple.sum, banana.sum, pineapple.sum);
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

//����Աɾ���û�(�û������Ѹ���)
void usersDelete() {
	FILE* fp = fopen("users.txt", "r+");
	fread(&m, sizeof(Members), 1, fp);
	printf("������Ҫɾ���û����û������ֻ���");
	scanf_s("%s", &b.users, 21);
	while (1) {
		if (strcmp(m.mobileNumber, b.users) == 0 || strcmp(m.name, b.users) == 0) {
			printf("ɾ�����û�������Ϣ���㣬ȷ��������1");
			scanf_s("%d", &n);
			if (n == 1) {
				printf("ɾ����...");
				fseek(fp, -(int)sizeof(Members), SEEK_CUR);	//ָ�������޸�Ŀ��ǰ
				fwrite(&kongbai, sizeof(Members), 1, fp);		//д���µ�m����ԭm
				printf("ɾ���ɹ���\n");
				fclose(fp);
				return;
			}	
			else {
				printf("��Ҫ�����Ŷ����\n");
				break;
			}
		}
		else {
			if (!feof(fp)) {
				fread(&m, sizeof(Members), 1, fp);
			}
			else {
				printf("���޴��û�");
				fclose(fp);
				return;
			}
		}
	}
	fclose(fp);
}

//��½����
void login() {
	int n = 5;
	FILE* fp = fopen("users.txt", "a+");
	fread(&m, sizeof(struct users), 1, fp);
	printf("�����������û������ֻ�����\n");
	scanf_s("%s", &b.users, 21);
	while (1) {				//�����û������ֻ��� 
		if (strcmp(m.mobileNumber, b.users) == 0 || strcmp(m.name, b.users) == 0) {
			if (m.userState == 0) {
				fclose(fp);
				break;		//˵���˺�������������һ���������� 
			}
			else if(m.userState ==1){
				printf("�˺�������������ϵ����Ա����\n");
				fclose(fp);
				return;
			}
		}
		else {
			if (!feof(fp)) {
				fread(&m, sizeof(Members), 1, fp);
			}
			else {
				printf("���޴��û����������룡\n");
				fclose(fp);
				return;
			}
			
		}
	}
	while (1) {				//�������� 
		if (n == 0) {			//���ж��˺��Ƿ����� 
			printf("�˺�������������ϵ����Ա����\n");
			m.userState = 1;
			fseek(fp,-(long)sizeof (Members),1);
			fwrite(&m, sizeof(Members), 1, fp);
			return;
		}
		printf("����������\n");
		scanf_s("%s", b.password, 21);
		if (strcmp(m.password, b.password) == 0) {
			printf("��½�ɹ���\n");
			log = 1;
			break;
		}
		else {
			printf("�������������%d�λ�����������\n", --n);
		}
	}
}

//��ֵ����(�û������Ѹ���)
void recharge() {
	if (log == 0) {
		printf("�û�δ��¼��������ת����½ҳ��...\n");
		login();
	}
	float n;					//��ֵ���
	printf("***********************************************\n");
	printf("*��ֵ10000����������Ա\t��ֵ50000�����𿨻�Ա*\n");
	printf("*������Ա���������\t   �𿨻�Ա���������*\n");
	printf("***********************************************\n");
	while (1) {
		printf("�������Ϊ��%.2f���������ֵ���˳�������0\n", m.balance);
		scanf_s("%f", &n);
		if (n == 0) {
			return;
		}
		else if (n == 10000) {			//����
			m.balance += n;
			if (m.discount == 1) {
				m.memberType = 1;
				m.discount = (float)0.9;
				printf("��ϲ�����ѳ�Ϊ������Ա�����о����Żݣ�\n");
			}
		}
		else if (n == 50000) {			//��
			m.balance += n;
			if (m.memberType != 2) {
				m.discount = (float)0.8;
				m.memberType = 2;
				printf("��ϲ�����ѳ�Ϊ�𿨻�Ա�����а����Żݣ�\n");
			}
		}
		else {							//����
			m.balance += n;
		}
		reWriteUsers();
	}
	
}

//->ȷ��֧��->���ݼ�¼
//֧��
void pay() {
	while (1) {
		printf("\n\n���֧���밴1���ֻ�֧���밴2������֧���밴3\n");
		scanf_s("%d", &i);
		if (i == 1) {
			if (m.balance >= list1.listsum) {
				m.balance -= list1.listsum;
				//���
				reWriteUsers();
				//��Ʒ����
				sum += list1.listsum;
				apple.sum += list1.appleNumber * apple.price * m.discount;
				apple.inventory -= list1.appleNumber;
				if (list1.appleNumber != 0) apple.frequency++;
				o = apple;	reWriteGoods();
				banana.sum += list1.bananaNumber * banana.price * m.discount;
				banana.inventory -= list1.bananaNumber;
				if (list1.bananaNumber != 0) banana.frequency++;
				o = banana;	reWriteGoods();
				pineapple.sum += list1.pineappleNumber * pineapple.price * m.discount;
				pineapple.inventory -= list1.pineappleNumber;
				if (list1.pineappleNumber != 0) pineapple.frequency++;
				o = pineapple;	reWriteGoods();
				list1 = kongbaiList;
				printf("����ɹ�����Ʒ���������ʹ������ջ���ַ��\n");
				return;
			}
			else {
				printf("���㣡�Ƽ�ʹ���ֻ�֧��Ŷ�ף�\n");
				continue;
			}
		}
		else if (i == 2) {
			printf("����ʹ���ֻ�֧����֧�����������1\n");
			scanf_s("%d", &n);
			if (n == 1) {
				sum += list1.listsum;
				apple.sum += list1.appleNumber * apple.price * m.discount;
				apple.inventory -= list1.appleNumber;
				if (list1.appleNumber != 0) apple.frequency++;
				o = apple;	reWriteGoods();
				banana.sum += list1.appleNumber * banana.price * m.discount;
				banana.inventory -= list1.appleNumber;
				if (list1.bananaNumber != 0) banana.frequency++;
				o = banana;	reWriteGoods();
				pineapple.sum += list1.appleNumber * pineapple.price * m.discount;
				pineapple.inventory -= list1.appleNumber;
				if (list1.pineappleNumber != 0) pineapple.frequency++;
				o = pineapple;	reWriteGoods();
				list1 = kongbaiList;
				printf("����ɹ�����Ʒ���������ʹ������ջ���ַ��\n");
				return;
			}
		}
		else if (i == 3) {
			printf("ȷ�Ϸ���֧��������1\n");
			scanf_s("%d", &n);
			if (n == 1) {
				list1 = kongbaiList;
				printf("��ȡ������\n");
				return;
			}
		}
	}

}

//չʾ->���->����->�嵥
//���﹦��(�û������Ѹ��ǣ���Ʒ�����Ѹ���)
void shopping() {
	if (m.memberType == 0) {
		printf("����������ͨ��Ա��ף��������죡\n");
	}
	else if (m.memberType == 1) {
		printf("��������������Ա��������Żݣ�ף��������죡\n");
	}
	else if (m.memberType == 2) {
		printf("�������ǽ𿨻�Ա��������Żݣ�ף��������죡\n");
	}
	printf("��Ʒ    \t|ƻ��\t|�㽶\t|����\t|\n");
	printf("����/�� \t|%.2f\t|%.2f\t|%.2f\t|\n", apple.price, banana.price, pineapple.price);
	printf("���    \t|11111\t|22222\t|33333\t|\n");
	while (1) {
		printf("������Ҫ�������Ʒ��ţ�����9���ˣ�����0�˳��̵꣬");
		scanf_s("%d", &number);
		if (number == 0) {
			break;
		}
		//��ʾ�嵥
		else if (number == 9) {
			list1.listsum = m.discount * (list1.appleNumber * apple.price + list1.bananaNumber * banana.price + list1.pineappleNumber * pineapple.price);
			if (list1.listsum == 0) {
				printf("���ﳵ��û����Ʒ���ף�\n");
				continue;
			}
			printf("���Ĺ����嵥���£�\n");
			printf("      ��Ʒ\t   ����/��\t    ����\t      �ܼ�\n");
			if (list1.appleNumber != 0) {
				printf("%10s\t%8.2f\t%8.2f\t%10.2f\n", apple.name, apple.price, list1.appleNumber, (double)list1.appleNumber * apple.price);
			}
			if (list1.bananaNumber != 0) {
				printf("%10s\t%8.2f\t%8.2f\t%10.2f\n", banana.name, banana.price, list1.bananaNumber, (double)list1.bananaNumber * banana.price);
			}
			if (list1.pineappleNumber != 0) {
				printf("%10s\t%8.2f\t%8.2f\t%10.2f\n", pineapple.name, pineapple.price, list1.pineappleNumber, (double)list1.pineappleNumber * pineapple.price);
			}
			if (m.discount != 1) {
				printf("\n\n\n�ܼ�(��%d��)\t\t\t\t\t\t%.2fԪ\t", (int)(m.discount * 10), list1.listsum);
			}
			else {
				printf("\n\n\n�ܼ�\t\t\t\t\t\t%.2fԪ\t",  list1.listsum);
			}
			pay();
			return;
		}
		else if (number == apple.number) {
			o = apple;
			printf("ƻ������%.2f��������Ҫ������ٽ��أ�", apple.price);
			scanf_s("%f", &jin);
			if (apple.inventory <= jin) {
				printf("�ܱ�Ǹ����Ʒ��治�㣬��ȴ�����...\n");
			}
			else {
				list1.appleNumber += jin;
				printf("�Ѽ��빺�ﳵ��\n");
			}	
		}
		else if (number == banana.number) {
			o = banana;
			printf("�㽶����%.2f��������Ҫ������ٽ��أ�", banana.price);
			scanf_s("%f", &jin);
			if (banana.inventory <= jin) {
				printf("�ܱ�Ǹ����Ʒ��治�㣬��ȴ�����...\n");
			}
			else {
				list1.bananaNumber += jin;
				printf("�Ѽ��빺�ﳵ��\n");
			}
		}
		else if (number == pineapple.number) {
			o = pineapple;
			printf("���ܵ���%.2f��������Ҫ������ٽ��أ�", pineapple.price);
			scanf_s("%f", &jin);
			if (pineapple.inventory <= jin) {
				printf("�ܱ�Ǹ����Ʒ��治�㣬��ȴ�����...\n");
			}
			else {
				list1.pineappleNumber += jin;
				printf("�Ѽ��빺�ﳵ��\n");
			}
		}
	}
}

//�û����в鿴���޸��˺���Ϣ(�û������Ѹ��ǣ��޸������Ѳ���)
void checkAndModify() {
	state();
	printf("�޸��û���������1���޸��ֻ�����������2���޸�����������3��ע���˻�������4���˳��û�����ģ��������0\n");
	scanf_s("%d", &i);
	//�û���
	if (i == 1) {
		while (1) {
			t = 1;
			FILE* fp = fopen("users.txt", "r");
			printf("�������޸ĺ���û���\n");
			scanf_s("%s", &a.name, 50);
			fread(&d, sizeof(Members), 1, fp);
			while (1) {
				if (strcmp(d.name, a.name) == 0) {
					printf("�û����Ѵ��ڣ�������ѡ�����\n");
					fclose(fp);
					return;
				}
				else {
					if (!feof(fp)) {
						fread(&d, sizeof(Members), 1, fp);
					}
					else {
						//�û�����δ���ڣ��������һ��
						fclose(fp);
						break;
					}
				}
			}
			l = strlen(a.name);
			if (l > 20) {
				printf("�û������ó���20λ��");
				continue;
			}
			for (i = 0; i < l; i++) {
				temp = a.name[i];
				if (!(temp >= '0' && temp <= '9' || temp >= 'a' && temp <= 'z' || temp >= 'A' && temp <= 'Z')) {
					printf("�û������Ƿ��ַ���");
					t = 0;
					break;
				}
			}
			if (t == 0) {
				t = 1;
				continue;
			}
			strcpy(m.name,a.name);
			reWriteUsers();
			break;
		}
	}
	//�ֻ���
	else if (i == 2) {
		while (1) {
			printf("�����������ֻ�����\n");
			scanf_s("%s", &a.mobileNumber, 50);
			FILE* fp1 = fopen("users.txt", "r+");
			fread(&d, sizeof(Members), 1, fp1);
			while (1) {
				if (strcmp(d.mobileNumber, a.mobileNumber) == 0) {
					printf("�ֻ����Ѵ��ڣ�������ѡ�������\n");
					fclose(fp1);
					return;
				}
				else {
					if (!feof(fp1)) {
						fread(&d, sizeof(Members), 1, fp1);
					}
					else {
						//�ֻ�δ���ڣ���һ��
						fclose(fp1);
						break;
					}
				}
			}
			l = strlen(a.mobileNumber);
			for (i = 0; i < l; i++) {
				temp = a.mobileNumber[i];
				if (!(temp >= '0' && temp <= '9')) {
					printf("�ֻ����뺬�Ƿ��ַ���\n");
					t = 0;
					break;
				}
			}
			if (t == 0) {
				t = 1;
				continue;
			}
			if (l != 11) {
				printf("�ֻ����볤��ӦΪ11λ\n");
				continue;
			}
			strcpy(m.mobileNumber, a.mobileNumber);
			reWriteUsers();
			break;
		}
	}
	//����
	else if(i == 3){
		//ȷ��ԭ����
		while (1) {
			printf("������ԭ����:");
			scanf_s("%s", &a.password, 21);
			if (strcmp(a.password, m.password) == 0) {
				break;
			}
			else {
				printf("ԭ�������");
				return;
			}
		}
		//�޸�����
		while (1) {
			printf("���޸ĺ������:");
			scanf_s("%s", &a.password, 21);
			if (strlen(a.password) < 6 || strlen(a.password) > 20) {
				printf("���벻�Ϸ�������Ӧ����6λ���ϣ�\n");
				continue;				//�ٴ�ѭ��while
			}
			printf("���ٴ�ȷ����������\n");
			scanf_s("%s", &b.password, 21);
			if (strcmp(a.password, b.password) != 0) {
				printf("������������벻һ�£����������룡\n");
			}
			//�ɹ�
			else {
				strcpy(m.password, a.password);
				reWriteUsers();
				break;
			}
		}
	}
	//ע��
	else if (i == 4) {
		FILE* fp = fopen("users.txt", "r+");
		fread(&d, sizeof(Members), 1, fp);
		while (1) {
			if (strcmp(m.name,d.name) == 0) {
				printf("ɾ�����û�������Ϣ���㣬ȷ��������1");
				scanf_s("%d", &n);
				if (n == 1) {
					printf("ɾ����...");
					fseek(fp, -(int)sizeof(Members), SEEK_CUR);	//ָ�������޸�Ŀ��ǰ
					fwrite(&kongbai, sizeof(Members), 1, fp);	//�ÿհ׶���ȥ�滻ԭ����
					log = 0;
					printf("ɾ���ɹ���\n");
					fclose(fp);
					return;
				}
				else {
					printf("��Ҫ�����Ŷ����\n");
					break;
				}
			}
			else {
				if (!feof(fp)) {
					fread(&d, sizeof(Members), 1, fp);
					continue;
				}
				else {
					printf("ɾ��ʧ�ܡ�");
					fclose(fp);
					return;
				}
			}
		}
		fclose(fp);
	}
	//�˳��û�����ģ��
	else if (i == 0) {
		return;
	}
	printf("�����Ѹ��£�\n");
}

//������
int main() {
	FILE* f = fopen("goods.txt", "w");
	fwrite(&apple, sizeof(Goods), 1, f);
	fwrite(&banana, sizeof(Goods), 1, f);
	fwrite(&pineapple, sizeof(Goods), 1, f);
	fclose(f);
	while (1) {
		FILE* fp = fopen("goods.txt", "r+");
		fread(&apple, sizeof(Goods), 1, fp);
		fread(&banana, sizeof(Goods), 1, fp);
		fread(&pineapple, sizeof(Goods), 1, fp);
		fclose(fp);
		if (log == 0) {
			printf("��ӭ�������˳��й���ϵͳ��ע��������1����½������2������������9\n");
		}
		//����Աҳ��
		else if (log == 2) {
			while (1) {
				printf("�޸���Ʒ��Ϣ�밴1���鿴��̨�����밴2��ɾ���û��밴3���˳��밴0\n");
				scanf_s("%d", &n);
				if (n == 1) {
					modify();
					fclose(fp);
					continue;
				}
				else if (n == 2) {
					check();
					break;
				}
				else if (n == 3) {
					usersDelete();
					break;
				}
				else if (n == 0) {
					log = 0;
					break;
				}
			}
			continue;
		}
		//��ֵ�͹��﹦���ڵ�½��ſɿ���
		else if(log == 1){
			state();
			printf("��ֵ�밴3�������밴4���鿴���޸��˺���Ϣ�밴5���˳��˺��밴0\n");
		}
		scanf_s("%d", &n);
		if (n == 1) {
			registers();
			continue;
		}
		else if (n == 2) {
			login();
			continue;
		}
		else if (n == 3) {
			recharge();
			continue;
		}
		else if (n == 4) {
			shopping();
			continue;
		}
		else if (n == 5) {
			checkAndModify();
			continue;
		}
		else if (n == 9) {
			administrator_signin();
			continue;
		}
		else if (n == 0) {
			printf("��ӭ�´ι��٣�\n");
			log = 0;
			continue;
		}
	}
}