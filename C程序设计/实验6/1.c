#include<stdio.h>
int main() {
	int i;
	char arr1[5];
	char arr2[5];
	printf("请输入第一个小于5位的数组");
	scanf_s("%s", &arr1, 5);
	printf("\n请输入第二个小于5位的数组");
	scanf_s("%s", &arr2, 5);
	for (i = 0; i < 5; i++) {		//循环判断数组内每一位是否相同
		if (arr1[i] == arr2[i]) {
			continue;				//相同则继续循环下一位
		}
		else {
			printf("两个数组不一致");	//有一位不一致则结束程序
			return 0;
		}
	}
	printf("两个数组一致");			//全部都相同并退出循环则说明完全一致
}
