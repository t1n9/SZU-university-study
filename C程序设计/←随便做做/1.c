#include<stdio.h>

typedef struct {
    char name[20]; //姓名
    float score[4];   //四门功课的成绩
    float average; //四门功课的平均成绩
}student;

student aa={"tt",100,100,100,100,100};

int main(){
	
	printf("姓名\t|语文\t|数学\t|英语\t|物理\n");
    printf("%s\t|%7.2f|%7.2f|%7.2f|%7.2f\n",aa.name,aa.score[0],aa.score[1],aa.score[2],aa.score[3]);
    return 0;
} 
