#include<stdio.h>
int g, i , max, str[20];
float a, b;
char sym;
//����������
float calculate() {
	float result = 0;
	scanf_s("%f", &a);
	scanf_s(" %c", &sym,1);
	scanf_s("%f", &b);				//������ʽ
	if (sym == '+') {
		result = a + b;
	}
	else if (sym == '-') {
		result = a - b;
	}
	else if (sym == '*') {
		result = a * b;
	}
	else if (sym == '/') {
		result = a / b;
	}
	return result;					//�ѽ������
}
//�������飬�������ֵ
int invert() {
	int max = 0;
	while (i < 7) {
		scanf_s("%d", &str[i]);
		i++;
	}
	i = 6;
	do{				//ѭ��
		if (str[i] > max) max = str[i];		//ÿ��ѭ����¼�ϴ�ֵ��ѭ�������Ϊ���ֵ
		if (i == 6) {		//���һ��Ԫ��
			printf("���ú�����Ϊ��%d��", str[i]);
			continue;
		}
		if (i == 0) {		//��һ��Ԫ��
			printf("%d\n", str[i]);
			break;
		}
		printf("%d��",str[i]);	//�м��Ԫ��
	} while (i--);
	return max;				//�����ֵ����
}
int main() {
	while (1) {
		printf("�������밴1�����������밴2������0�˳�\n");
		scanf_s("%d", &g);
		if (g == 1) {
			printf("�����룺");
			printf("����ִ�н��Ϊ%.2f\n", calculate());
		}
		else if (g == 2) {
			printf("��ֱ�����7������");
			printf("�����������Ϊ%d\n", invert());
		}
		else if (g == 0) {
			return 0;
		}
	}
}