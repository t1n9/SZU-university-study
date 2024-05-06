#include<stdio.h>
int g, i , max, str[20];
float a, b;
char sym;
//计算器功能
float calculate() {
	float result = 0;
	scanf_s("%f", &a);
	scanf_s(" %c", &sym,1);
	scanf_s("%f", &b);				//输入算式
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
	return result;					//把结果返回
}
//倒置数组，返回最大值
int invert() {
	int max = 0;
	while (i < 7) {
		scanf_s("%d", &str[i]);
		i++;
	}
	i = 6;
	do{				//循环
		if (str[i] > max) max = str[i];		//每次循环记录较大值，循环到最后即为最大值
		if (i == 6) {		//最后一个元素
			printf("倒置后数组为：%d，", str[i]);
			continue;
		}
		if (i == 0) {		//第一个元素
			printf("%d\n", str[i]);
			break;
		}
		printf("%d，",str[i]);	//中间的元素
	} while (i--);
	return max;				//把最大值返回
}
int main() {
	while (1) {
		printf("计算器请按1，倒置数组请按2，输入0退出\n");
		scanf_s("%d", &g);
		if (g == 1) {
			printf("请输入：");
			printf("函数执行结果为%.2f\n", calculate());
		}
		else if (g == 2) {
			printf("请分别输入7个数：");
			printf("数组中最大数为%d\n", invert());
		}
		else if (g == 0) {
			return 0;
		}
	}
}