#include<stdio.h>
#include<stdlib.h>
int i,j,temp;
//������ֵ����ð������
void mySelectSort(int* arrp, int num) {
	//ð������
	for (i = 1; i < num; i++) {
		for (j = 0; j < 7 -i; j++) {
			if (arrp[j] > arrp[j + 1]) {
				temp = arrp[j];
				arrp[j] = arrp[j + 1];
				arrp[j + 1] = temp;
			}
		}
	}
	//�������������
	printf("ð�����������Ϊ��\n");
	for (i = 0; i < num; i++) {
		printf("%d\n", arrp[i]);
	}
}
int main() {
	int arr[7];			//��������
	printf("��ֱ�����7��������");
	for (i = 0; i < 7; i++) {
		scanf_s("%d", &arr[i]);		//ѭ����������
	}
	mySelectSort(arr, 7);			//���ú������������λ������
}