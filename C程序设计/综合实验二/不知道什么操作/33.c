#include<stdio.h>
int main() {
	int i,j,temp,k;
	int temparr3[17] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };
	int copy_death[17] = { 571179,102655,37672,186920,127638,105718,118699,77591,386416,81326,70446,61176,64707,23870,68746,214095,4845 };
	int death[17] = { 571179,102655,37672,186920,127638,105718,118699,77591,386416,81326,70446,61176,64707,23870,68746,214095,4845 };
	printf("序号   死亡人数     国家   确诊人数   死亡率%%\n");
	//选择排序
	for (i = 0; i < 16; i++) {
		k = i;
		for (j = i + 1; j < 17; j++) {
			if (death[k] > death[j]) {
				k = j;
			}
		}
		if (k != i) {
			temp = temparr3[i];
			temparr3[i] = temparr3[k];
			temparr3[k] = temp;
			temp = copy_death[i];
			copy_death[i] = copy_death[k];
			copy_death[k] = temp;
			
		}
	}

//	for (i = 0; i < 17; i++) {
//		d_form(temparr3[16 - i]);
//	}
	for (i = 0; i < 17; i++) {
		printf("%d\n", copy_death[i]);
	}
	
} 
