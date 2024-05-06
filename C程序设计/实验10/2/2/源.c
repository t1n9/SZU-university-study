#include<stdio.h>
#include<stdlib.h>
int i,j,temp;
//对无序值进行冒泡排序
void mySelectSort(int* arrp, int num) {
	//冒泡排序
	for (i = 1; i < num; i++) {
		for (j = 0; j < 7 -i; j++) {
			if (arrp[j] > arrp[j + 1]) {
				temp = arrp[j];
				arrp[j] = arrp[j + 1];
				arrp[j + 1] = temp;
			}
		}
	}
	//输出排序后的数组
	printf("冒泡排序后数组为：\n");
	for (i = 0; i < num; i++) {
		printf("%d\n", arrp[i]);
	}
}
int main() {
	int arr[7];			//定义数组
	printf("请分别输入7个无序数");
	for (i = 0; i < 7; i++) {
		scanf_s("%d", &arr[i]);		//循环输入数组
	}
	mySelectSort(arr, 7);			//调用函数，将数组和位数传入
}