#include<stdio.h>
//法一
/*
void replace(int* j, int* k) {	//直接让j和k的指针指向传入的变量的地址
	int temp;
	temp = *j;					//j和k的值一变，原来的值也就变了
	*j = *k;
	*k = temp;
	return;
}
int main() {
	int a, b;
	printf("a的值为：");
	scanf_s("%d", &a);
	printf("b的值为：");
	scanf_s("%d", &b);
	replace(&a, &b);			//调用函数
	printf("交换两个变量的值后，a值为%d，b值为%d\n", a, b);
}

*/
//法二

#include<stdio.h>
int a, b, temp;
void replace() {	//用全局变量做
	temp = a;
	a = b;
	b = temp;
}
int main() {
	printf("请输入a：");
	scanf_s("%d", &a);
	printf("请输入b：");
	scanf_s("%d", &b);
	replace();			//调用函数
	printf("交换两个变量的值后，a值为%d，b值为%d\n", a, b);
}