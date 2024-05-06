#include<stdio.h>
int main() {
	float a = 1;					//初始化变化数
	float sum = 0;					//初始化总数
	int c = 1;						//初始化操作	
	printf("我的记账小程序\n");
	while (a != 0) {				//循环语句
		printf("当前余额%.2f\n", sum);
		printf("存钱请输入1，取钱请输入2，结束请输入0\n");
		printf("请输入:");
		scanf_s("%f", &a);			//输入操作
		if (a == 1) {				//判断是存钱还是取钱
			printf("请输入存钱金额");
			scanf_s("%f", &a);		//输入存钱金额
			sum += a;
		}
		else if (a == 2) {
			printf("请输入取钱金额");
			scanf_s("%f", &a);		//输入取钱金额
			sum -= a;
		}
		else if (a == 0) {
			continue;				//当输入0的时候继续执行
		}
		if (sum < 0) {				//当钱包金额小于0时
			printf("钱包里没有这么多钱了！\n");
			continue;
		}
	}
}