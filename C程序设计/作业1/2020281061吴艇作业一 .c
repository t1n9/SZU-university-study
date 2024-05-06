#include<stdio.h>
int main(){
	//巧解 
	float a;
	scanf_s("%f",&a);						//VS提示不加"_s"不安全。。。
	if(a>=0) {								//正负数不可都加上0.5来算，故分成两种情况
		printf("%d\n",(int)(a+0.5));		//把(a+0.5)转化为整形，再打印 
		return 0;
	}else{
		printf("%d\n",(int)(a-0.5));
		return 0;
	}
} 
int main2() {
	//直接判断小数点后一位是否>=/<=（+/-）5
	float a;
	scanf("%f",&a);
	int b = a;
	//同样，这里正负还是要分两种情况讨论 
	//但只要对要进位的数讨论即可 
	if((int)(a*10)%10 >= 5){
		printf("%d\n",b+1);				//进一位
		return 0;
	} else if((int)(a*10)%10<= -5){
		printf("%d\n",b-1);				//进一位
		return 0;
	} else{
		printf("%d\n",b);				//不用进位
		return 0;
	}

} 
