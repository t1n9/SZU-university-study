#include<stdio.h>
int main() {
	int i,j,temp,k;
	
	int death[17] = { 571179,102655,37672,186920,127638,105718,118699,77591,386416,81326,70446,61176,64707,23870,68746,214095,4845 };
	for(i = 0; i < 16; i ++){
		k = i;
		for(j = i + 1; j < 17; j++){
			if(death[k] > death[j]){
				k = j;
			}
		}
		if(k!=i){
			temp = death[i];
			death[i] = death[k];
			death[k] = temp;
		}
	}
	for(i = 0; i < 17; i ++){
		printf("%d\n",death[i]);
	}
	
	
} 
