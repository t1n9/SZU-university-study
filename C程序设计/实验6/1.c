#include<stdio.h>
int main() {
	int i;
	char arr1[5];
	char arr2[5];
	printf("�������һ��С��5λ������");
	scanf_s("%s", &arr1, 5);
	printf("\n������ڶ���С��5λ������");
	scanf_s("%s", &arr2, 5);
	for (i = 0; i < 5; i++) {		//ѭ���ж�������ÿһλ�Ƿ���ͬ
		if (arr1[i] == arr2[i]) {
			continue;				//��ͬ�����ѭ����һλ
		}
		else {
			printf("�������鲻һ��");	//��һλ��һ�����������
			return 0;
		}
	}
	printf("��������һ��");			//ȫ������ͬ���˳�ѭ����˵����ȫһ��
}
