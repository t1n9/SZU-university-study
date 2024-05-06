#include<stdio.h>
int main(){
	int n = 0;
	scanf("%d",&n);
	int mix1 = 1;
	int mix2 = 0;
	int i,j;
	for(i = 1; i <= n; i++){
		mix1 = 1;
		for(j = 1;j <= i; j++){
			mix1 *= j;
		}
		mix2 += mix1;
	}
	printf("%d",mix2);
} 
