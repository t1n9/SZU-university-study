#include<stdio.h>

typedef struct {
    char name[20]; //����
    float score[4];   //���Ź��εĳɼ�
    float average; //���Ź��ε�ƽ���ɼ�
}student;

student aa={"tt",100,100,100,100,100};

int main(){
	
	printf("����\t|����\t|��ѧ\t|Ӣ��\t|����\n");
    printf("%s\t|%7.2f|%7.2f|%7.2f|%7.2f\n",aa.name,aa.score[0],aa.score[1],aa.score[2],aa.score[3]);
    return 0;
} 
