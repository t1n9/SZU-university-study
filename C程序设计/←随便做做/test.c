#include<stdio.h>
typedef struct {
	char name[21];		//名字
	int number;			//编号
	float price;		//单价
	float inventory;	//库存
	float sum;			//单个商品营业额
	int frequency;		//购买次数
}Goods;

Goods apple = {"apple",11111,0.75,1000,0,0};
Goods banana = {"banana",22222,3.5,1000,0,0};
Goods pineapple = {"pineapple",33333,4.2,1000,0,0};

int main(){
	FILE *fp = fopen("111.txt","w");
	fwrite(&apple,sizeof(Goods),1,fp);
	fwrite(&banana,sizeof(Goods),1,fp);
	fwrite(&pineapple,sizeof(Goods),1,fp);
	fclose(fp);
	printf("成功！");
} 
