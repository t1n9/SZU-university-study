#include<stdio.h>
struct student {
    char name[20]; //����
    float score[4];   //���Ź��εĳɼ�
    float average; //���Ź��ε�ƽ���ɼ�
};
int i, ii, num;
struct student temp;
struct student stu[50];
//4����ѧ����ƽ���ɼ���ѧ����Ϣ��������ĺ����� stu Ϊ�ṹ�����飬 num Ϊ������Ԫ�صĸ����� 
void sortByAverageScore(struct student stu[], int num) {
    printf("����Ϊƽ��������\n");
    //��ð������
    for (i = 0; i < num; i++) {
        for (ii = i; ii < num - i; ii++) {
            if (stu[ii].average < stu[ii + 1].average) {
                temp = stu[ii];
                stu[ii] = stu[ii+1];
                stu[ii + 1] = temp;
            }
        }
    }
    printf("����\t|����\t|��ѧ\t|Ӣ��\t|����\t|ƽ����\n");
    for (i = 0; i < num; i++) {
        printf("%s\t|%7.1f|%7.1f|%7.1f|%7.1f|%7.2f\n", stu[i].name, stu[i].score[0], stu[i].score[1], stu[i].score[2], stu[i].score[3], stu[i].average);
    }
}
//3����ѧ��ƽ���ɼ��ĺ����� stu Ϊ�ṹ�����飬 num Ϊ������Ԫ�صĸ�����
void averageScore(struct student stu[], int num) {
    for (i = 0; i < num; i++) {
        stu[i].average = (stu[i].score[0] + stu[i].score[1] + stu[i].score[2] + stu[i].score[3]) / 4;
    }
}
//2ѧ����Ϣ�������Ļ�ĺ����� stu Ϊ�ṹ�����飬 num Ϊ������Ԫ�صĸ�����
void outputToScreen(struct student stu[], int num) {
    printf("�����ѧ����Ϣ��\n");
    printf("����\t|����\t|��ѧ\t|Ӣ��\t|����\n");
    for (i = 0; i < num; i++) {
        printf("%s\t|%7.1f|%7.1f|%7.1f|%7.1f\n", stu[i].name, stu[i].score[0], stu[i].score[1], stu[i].score[2], stu[i].score[3]);
    }
}
//1�Ӽ�������ѧ����Ϣ�ĺ����� stu Ϊ�ṹ�����飬 num Ϊ������Ԫ�صĸ�����
void inputFromKeyboard(struct student stu[], int num) {
    for (i = 0; i < num; i++) {
        printf("������������");
        scanf_s("%s", &stu[i].name,20);
        printf("��ֱ��������ġ���ѧ��Ӣ������ĿƳɼ���");
        for (ii = 0; ii < 4; ii++) {
            scanf_s("%f", &stu[i].score[ii]);
        }
    }
}
int main() {
    printf("�����뼴�������ѧ��������");
    scanf_s("%d", &num);
    inputFromKeyboard(stu,num);
    outputToScreen(stu, num);
    averageScore(stu, num);
    sortByAverageScore(stu, num);
    return 0;
}