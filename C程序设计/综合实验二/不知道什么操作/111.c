#include<stdio.h>
int confirm[17] = { 31990519,5502014,4550820,16263695,4416588,4691290,3935703,3468617,14237078,3263415,2740544,2824652,2742122,1172697,2358809,2319519,102347 };
int main(){
	int i,j;
	int temp;
	
	for (j = 0; j < 17 - i; j++) {
			if (copy_confirm[j] > copy_confirm[j + 1]) {
				temp = temparr[j];
				temparr[j] = temparr[j + 1];
				temparr[j + 1] = temp;
				temp = copy_confirm[j];
				copy_confirm[j] = copy_confirm[j + 1];
				copy_confirm[j + 1] = temp;
			}
		}
	for(i = 0; i <17 ;i ++){
		printf("%d\n",confirm[i]);
	}
} 
