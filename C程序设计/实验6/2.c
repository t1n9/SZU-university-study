#include<stdio.h>
int main() {
	char A[] = "ShenZhen";		//定义第一个数组
	char B[] = " China";		//定义第二个数组
	char* p1 = A;				//把p1指针指向A字符串的地址
	char* p2 = B;				//把p2指针指向B字符串的地址
	while (*p1++);
	p1--;						//这两步把指针指向最后一位'n'
	while (*p2) *p1++ = *p2++;	//在*p1的最后一位往后加上*p2(从首位开始到末尾）
	*p1 = '\0';					//在末尾加上\0封底
	printf("%s", A);
}
