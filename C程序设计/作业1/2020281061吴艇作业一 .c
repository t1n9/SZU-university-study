#include<stdio.h>
int main(){
	//�ɽ� 
	float a;
	scanf_s("%f",&a);						//VS��ʾ����"_s"����ȫ������
	if(a>=0) {								//���������ɶ�����0.5���㣬�ʷֳ��������
		printf("%d\n",(int)(a+0.5));		//��(a+0.5)ת��Ϊ���Σ��ٴ�ӡ 
		return 0;
	}else{
		printf("%d\n",(int)(a-0.5));
		return 0;
	}
} 
int main2() {
	//ֱ���ж�С�����һλ�Ƿ�>=/<=��+/-��5
	float a;
	scanf("%f",&a);
	int b = a;
	//ͬ����������������Ҫ������������� 
	//��ֻҪ��Ҫ��λ�������ۼ��� 
	if((int)(a*10)%10 >= 5){
		printf("%d\n",b+1);				//��һλ
		return 0;
	} else if((int)(a*10)%10<= -5){
		printf("%d\n",b-1);				//��һλ
		return 0;
	} else{
		printf("%d\n",b);				//���ý�λ
		return 0;
	}

} 
