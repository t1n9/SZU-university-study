#include<stdio.h>

char nation[][17] = { "����","����","������","ӡ��","Ӣ��","����˹","�����","������","����","�¹�","���ױ���","����͢","����","���ô�","����","ī����","�й�" };
int confirm[17] = { 31990519,5502014,4550820,16263695,4416588,4691290,3935703,3468617,14237078,3263415,2740544,2824652,2742122,1172697,2358809,2319519,102347 };
int death[17] = { 571179,102655,37672,186920,127638,105718,118699,77591,386416,81326,70446,61176,64707,23870,68746,214095,4845 };
float deathRate[17];			//��������death/ȷ������confirm		
//���ڲ����ƻ�ԭ������Ԫ������ŵĹ�ϵ�������ִ�����һ�����������޸�
int copy_confirm[17] = { 31990519,5502014,4550820,16263695,4416588,4691290,3935703,3468617,14237078,3263415,2740544,2824652,2742122,1172697,2358809,2319519,102347 };
int copy_death[17] = { 571179,102655,37672,186920,127638,105718,118699,77591,386416,81326,70446,61176,64707,23870,68746,214095,4845 };
float copy_deathRate[17];

int i;			//�±�Ϊi��ֵ��ʼ����ð������
int j;			//ð������Ĵ���
int k;			//ѡ��������Сֵ�±�
int n;			//����*����
int temp;		//���������м�ֵ
float ftemp;	//���渡�����м�ֵ
//�����ƻ�ԭ���飬�����´�����Ź�ϵ����������
int temparr1[17] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };
int temparr2[17] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };
int temparr3[17] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };

//ֱ��ͼ����
//��ȷ������
void confirm_histogram(int p) {
	//Ĭ��ֱ��ͼ���������ֵΪ100%�������ֵ��Ӧ�Ĺ���"*"��ռ��
	n = (int)(2*(0.5+ (50 * confirm[p]) / 31990519));
	printf("%-10s", nation[p]);
	while(n--){
		printf("*");
	}
	printf("\n");
}
//��������
void deathRate_histogram(int p) {
	//Ĭ��ֱ��ͼ���������ֵΪ100%�������ֵ��Ӧ�Ĺ���"*"��ռ��
	n = (int)(100 * (deathRate[p] / 9.230146));
	printf("%-10s", nation[p]);
	while (n--) {
		printf("*");
	}
	printf("\n");
}
//����������
void death_histogram(int p) {
	//Ĭ��ֱ��ͼ���������ֵΪ100%�������ֵ��Ӧ�Ĺ���"*"��ռ��
	n = (int)(2 * (0.5 + (50 * death[p]) / 571179));
	printf("%-10s", nation[p]);
	while (n--) {
		printf("*");
	}
	printf("\n");
}


//������
//��ȷ������
void c_form(int p) {
	printf("%3d|%10d|%8s|%10d|%10f\n", i + 1, confirm[p], nation[p], death[p], deathRate[p]);
}
//��������
void dr_form(int p) {
	printf("%3d|%10f|%10d|%8s|%10d\n", i + 1, deathRate[p], death[p], nation[p], confirm[p]);
}
//����������
void d_form(int p) {
	printf("%3d|%10d|%8s|%10d|%10f\n", i + 1, death[p], nation[p], confirm[p], deathRate[p]);
}

//����ȷ����������
void confirm_sort() {
	printf("ȷ���������\n");
	printf("���   ȷ������     ����   ��������   ������%%\n");
	//��ʼð������
	for (i = 1; i < 17; i++) {
		for (j = 0; j < 17 - i; j++) {
			//���ﲻ���ƻ�ԭ���飬���޸ĺ��жϵĶ���copy������
			if (copy_confirm[j] > copy_confirm[j + 1]) {
				//ԭ�������������еĶ�Ӧ��ϵ���䣬��ֻҪ֪���ı���λ�ü���
				temp = temparr1[j];
				temparr1[j] = temparr1[j + 1];
				temparr1[j + 1] = temp;
				temp = copy_confirm[j];
				copy_confirm[j] = copy_confirm[j + 1];
				copy_confirm[j + 1] = temp;
			}
		}
	}
	for (i = 0; i < 17; i++) {
		//���ı���λ�ô��룬�Դ�ӡ���
		c_form(temparr1[16 - i]);
	}
	printf("ȷ������ֱ��ͼ��\n");
	for (i = 0; i < 17; i++) {
		//���ı���λ�ô��룬�Դ�ӡֱ��ͼ
		confirm_histogram(temparr1[16 - i]);
	}
}

//��������������
void deathrate_sort() {
	printf("�����ʱ��\n");
	printf("���   ������%%     ��������   ����   ȷ������\n");
	//��ʼð������
	for (i = 1; i < 17; i++) {
		for (j = 0; j < 17 - i; j++) {
			//�޸ĺ��жϵĶ���copy������
			if (copy_deathRate[j] > copy_deathRate[j + 1]) {
				//ԭ�������������еĶ�Ӧ��ϵ���䣬��ֻҪ֪���ı���λ�ü���
				temp = temparr2[j];
				temparr2[j] = temparr2[j + 1];
				temparr2[j + 1] = temp;
				ftemp = copy_deathRate[j];
				copy_deathRate[j] = copy_deathRate[j + 1];
				copy_deathRate[j + 1] = ftemp;
			}
		}
	}
	for (i = 0; i < 17; i++) {
		//���ı���λ�ô��룬�Դ�ӡ���
		dr_form(temparr2[16 - i]);
	}
	printf("������ֱ��ͼ��\n");
	for (i = 0; i < 17; i++) {
		//���ı���λ�ô��룬�Դ�ӡֱ��ͼ
		deathRate_histogram(temparr2[16 - i]);
	}
}

//����������������
void death_sort() {
	printf("�����������\n");
	printf("���   ��������     ����   ȷ������   ������%%\n");
	//ѡ������
	for (i = 0; i < 16; i++) {
		k = i;
		//�޸ĺ��жϵĶ���copy������
		for (j = i + 1; j < 17; j++) {
			if (copy_death[k] > copy_death[j]) {
				k = j;
			}
		}
		if (k != i) {
			temp = temparr3[i];
			temparr3[i] = temparr3[k];
			temparr3[k] = temp;
			temp = copy_death[i];
			copy_death[i] = copy_death[k];
			copy_death[k] = temp;
		}
	}
	for (i = 0; i < 17; i++) {
		//���ı���λ�ô��룬�Դ�ӡ���
		d_form(temparr3[16 - i]);
	}
	printf("��������ֱ��ͼ��\n");
	for (i = 0; i < 17; i++) {
		//���ı���λ�ô��룬�Դ�ӡֱ��ͼ
		death_histogram(temparr3[16 - i]);
	}
}

int main() {
	//�ȰѸ������ҵ�������%�������������������
	for (i = 0; i < 17; i++) {
		deathRate[i] = 100*((float)death[i] / confirm[i]);
		copy_deathRate[i] = 100*((float)death[i] / confirm[i]);
	}
	int c;
	while (1) {
		printf("��ȷ�����������밴1���������������밴2�����������������밴3������0�˳�\n");
		scanf_s("%d",&c);
		if (c == 1) {
			confirm_sort();
		}
		else if (c == 2) {
			deathrate_sort();
		}
		else if (c == 3) {
			death_sort();
		}
		else if (c == 0) {
			return 0;
		}
	}
}

