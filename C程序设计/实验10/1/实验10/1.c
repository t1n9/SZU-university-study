#include<stdio.h>
//��һ
/*
void replace(int* j, int* k) {	//ֱ����j��k��ָ��ָ����ı����ĵ�ַ
	int temp;
	temp = *j;					//j��k��ֵһ�䣬ԭ����ֵҲ�ͱ���
	*j = *k;
	*k = temp;
	return;
}
int main() {
	int a, b;
	printf("a��ֵΪ��");
	scanf_s("%d", &a);
	printf("b��ֵΪ��");
	scanf_s("%d", &b);
	replace(&a, &b);			//���ú���
	printf("��������������ֵ��aֵΪ%d��bֵΪ%d\n", a, b);
}

*/
//����

#include<stdio.h>
int a, b, temp;
void replace() {	//��ȫ�ֱ�����
	temp = a;
	a = b;
	b = temp;
}
int main() {
	printf("������a��");
	scanf_s("%d", &a);
	printf("������b��");
	scanf_s("%d", &b);
	replace();			//���ú���
	printf("��������������ֵ��aֵΪ%d��bֵΪ%d\n", a, b);
}