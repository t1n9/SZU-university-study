#include<stdio.h>

char nation[][17] = { "美国","法国","土耳其","印度","英国","俄罗斯","意大利","西班牙","巴西","德国","哥伦比亚","阿根廷","波兰","加拿大","伊朗","墨西哥","中国" };
int confirm[17] = { 31990519,5502014,4550820,16263695,4416588,4691290,3935703,3468617,14237078,3263415,2740544,2824652,2742122,1172697,2358809,2319519,102347 };
int death[17] = { 571179,102655,37672,186920,127638,105718,118699,77591,386416,81326,70446,61176,64707,23870,68746,214095,4845 };
float deathRate[17];			//死亡人数death/确诊人数confirm		
//由于不想破环原数组内元素与序号的关系，于是又创建了一个用来排序修改
int copy_confirm[17] = { 31990519,5502014,4550820,16263695,4416588,4691290,3935703,3468617,14237078,3263415,2740544,2824652,2742122,1172697,2358809,2319519,102347 };
int copy_death[17] = { 571179,102655,37672,186920,127638,105718,118699,77591,386416,81326,70446,61176,64707,23870,68746,214095,4845 };
float copy_deathRate[17];

int i;			//下标为i的值开始进行冒泡排序
int j;			//冒泡排序的次数
int k;			//选择排序最小值下标
int n;			//计算*个数
int temp;		//储存整型中间值
float ftemp;	//储存浮点型中间值
//不想破环原数组，故重新创建序号关系，用于排序
int temparr1[17] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };
int temparr2[17] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };
int temparr3[17] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };

//直方图绘制
//按确诊人数
void confirm_histogram(int p) {
	//默认直方图里依照最大值为100%，即最大值对应的国家"*"号占满
	n = (int)(2*(0.5+ (50 * confirm[p]) / 31990519));
	printf("%-10s", nation[p]);
	while(n--){
		printf("*");
	}
	printf("\n");
}
//按死亡率
void deathRate_histogram(int p) {
	//默认直方图里依照最大值为100%，即最大值对应的国家"*"号占满
	n = (int)(100 * (deathRate[p] / 9.230146));
	printf("%-10s", nation[p]);
	while (n--) {
		printf("*");
	}
	printf("\n");
}
//按死亡人数
void death_histogram(int p) {
	//默认直方图里依照最大值为100%，即最大值对应的国家"*"号占满
	n = (int)(2 * (0.5 + (50 * death[p]) / 571179));
	printf("%-10s", nation[p]);
	while (n--) {
		printf("*");
	}
	printf("\n");
}


//输出表格
//按确诊人数
void c_form(int p) {
	printf("%3d|%10d|%8s|%10d|%10f\n", i + 1, confirm[p], nation[p], death[p], deathRate[p]);
}
//按死亡率
void dr_form(int p) {
	printf("%3d|%10f|%10d|%8s|%10d\n", i + 1, deathRate[p], death[p], nation[p], confirm[p]);
}
//按死亡人数
void d_form(int p) {
	printf("%3d|%10d|%8s|%10d|%10f\n", i + 1, death[p], nation[p], confirm[p], deathRate[p]);
}

//按照确诊人数排序
void confirm_sort() {
	printf("确诊人数表格：\n");
	printf("序号   确诊人数     国家   死亡人数   死亡率%%\n");
	//开始冒泡排序
	for (i = 1; i < 17; i++) {
		for (j = 0; j < 17 - i; j++) {
			//这里不想破环原数组，故修改和判断的都是copy的数组
			if (copy_confirm[j] > copy_confirm[j + 1]) {
				//原来的三个数组中的对应关系不变，故只要知道改变后的位置即可
				temp = temparr1[j];
				temparr1[j] = temparr1[j + 1];
				temparr1[j + 1] = temp;
				temp = copy_confirm[j];
				copy_confirm[j] = copy_confirm[j + 1];
				copy_confirm[j + 1] = temp;
			}
		}
	}
	for (i = 0; i < 17; i++) {
		//将改变后的位置传入，以打印表格
		c_form(temparr1[16 - i]);
	}
	printf("确诊人数直方图：\n");
	for (i = 0; i < 17; i++) {
		//将改变后的位置传入，以打印直方图
		confirm_histogram(temparr1[16 - i]);
	}
}

//按照死亡率排序
void deathrate_sort() {
	printf("死亡率表格：\n");
	printf("序号   死亡率%%     死亡人数   国家   确诊人数\n");
	//开始冒泡排序
	for (i = 1; i < 17; i++) {
		for (j = 0; j < 17 - i; j++) {
			//修改和判断的都是copy的数组
			if (copy_deathRate[j] > copy_deathRate[j + 1]) {
				//原来的三个数组中的对应关系不变，故只要知道改变后的位置即可
				temp = temparr2[j];
				temparr2[j] = temparr2[j + 1];
				temparr2[j + 1] = temp;
				ftemp = copy_deathRate[j];
				copy_deathRate[j] = copy_deathRate[j + 1];
				copy_deathRate[j + 1] = ftemp;
			}
		}
	}
	for (i = 0; i < 17; i++) {
		//将改变后的位置传入，以打印表格
		dr_form(temparr2[16 - i]);
	}
	printf("死亡率直方图：\n");
	for (i = 0; i < 17; i++) {
		//将改变后的位置传入，以打印直方图
		deathRate_histogram(temparr2[16 - i]);
	}
}

//按照死亡人数排序
void death_sort() {
	printf("死亡人数表格：\n");
	printf("序号   死亡人数     国家   确诊人数   死亡率%%\n");
	//选择排序
	for (i = 0; i < 16; i++) {
		k = i;
		//修改和判断的都是copy的数组
		for (j = i + 1; j < 17; j++) {
			if (copy_death[k] > copy_death[j]) {
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
	for (i = 0; i < 17; i++) {
		//将改变后的位置传入，以打印表格
		d_form(temparr3[16 - i]);
	}
	printf("死亡人数直方图：\n");
	for (i = 0; i < 17; i++) {
		//将改变后的位置传入，以打印直方图
		death_histogram(temparr3[16 - i]);
	}
}

int main() {
	//先把各个国家的死亡率%计算出来，存在数组中
	for (i = 0; i < 17; i++) {
		deathRate[i] = 100*((float)death[i] / confirm[i]);
		copy_deathRate[i] = 100*((float)death[i] / confirm[i]);
	}
	int c;
	while (1) {
		printf("按确诊人数排列请按1，按死亡率排列请按2，按死亡人数排列请按3，输入0退出\n");
		scanf_s("%d",&c);
		if (c == 1) {
			confirm_sort();
		}
		else if (c == 2) {
			deathrate_sort();
		}
		else if (c == 3) {
			death_sort();
		}
		else if (c == 0) {
			return 0;
		}
	}
}

