#include<stdio.h>
int main() {
	float a = 1;					//��ʼ���仯��
	float sum = 0;					//��ʼ������
	int c = 1;						//��ʼ������	
	printf("�ҵļ���С����\n");
	while (a != 0) {				//ѭ�����
		printf("��ǰ���%.2f\n", sum);
		printf("��Ǯ������1��ȡǮ������2������������0\n");
		printf("������:");
		scanf_s("%f", &a);			//�������
		if (a == 1) {				//�ж��Ǵ�Ǯ����ȡǮ
			printf("�������Ǯ���");
			scanf_s("%f", &a);		//�����Ǯ���
			sum += a;
		}
		else if (a == 2) {
			printf("������ȡǮ���");
			scanf_s("%f", &a);		//����ȡǮ���
			sum -= a;
		}
		else if (a == 0) {
			continue;				//������0��ʱ�����ִ��
		}
		if (sum < 0) {				//��Ǯ�����С��0ʱ
			printf("Ǯ����û����ô��Ǯ�ˣ�\n");
			continue;
		}
	}
}