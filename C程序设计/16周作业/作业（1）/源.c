#include<stdio.h>
struct student {
    char name[20]; //姓名
    float score[4];   //四门功课的成绩
    float average; //四门功课的平均成绩
};
int i, ii, num;
struct student temp;
struct student stu[50];
//4根据学生的平均成绩对学生信息整体排序的函数。 stu 为结构体数组， num 为数组中元素的个数。 
void sortByAverageScore(struct student stu[], int num) {
    printf("下面为平均分排序：\n");
    //用冒泡排序
    for (i = 0; i < num; i++) {
        for (ii = i; ii < num - i; ii++) {
            if (stu[ii].average < stu[ii + 1].average) {
                temp = stu[ii];
                stu[ii] = stu[ii+1];
                stu[ii + 1] = temp;
            }
        }
    }
    printf("姓名\t|语文\t|数学\t|英语\t|物理\t|平均分\n");
    for (i = 0; i < num; i++) {
        printf("%s\t|%7.1f|%7.1f|%7.1f|%7.1f|%7.2f\n", stu[i].name, stu[i].score[0], stu[i].score[1], stu[i].score[2], stu[i].score[3], stu[i].average);
    }
}
//3计算学生平均成绩的函数。 stu 为结构体数组， num 为数组中元素的个数。
void averageScore(struct student stu[], int num) {
    for (i = 0; i < num; i++) {
        stu[i].average = (stu[i].score[0] + stu[i].score[1] + stu[i].score[2] + stu[i].score[3]) / 4;
    }
}
//2学生信息输出到屏幕的函数。 stu 为结构体数组， num 为数组中元素的个数。
void outputToScreen(struct student stu[], int num) {
    printf("输入的学生信息：\n");
    printf("姓名\t|语文\t|数学\t|英语\t|物理\n");
    for (i = 0; i < num; i++) {
        printf("%s\t|%7.1f|%7.1f|%7.1f|%7.1f\n", stu[i].name, stu[i].score[0], stu[i].score[1], stu[i].score[2], stu[i].score[3]);
    }
}
//1从键盘输入学生信息的函数。 stu 为结构体数组， num 为数组中元素的个数。
void inputFromKeyboard(struct student stu[], int num) {
    for (i = 0; i < num; i++) {
        printf("请输入姓名：");
        scanf_s("%s", &stu[i].name,20);
        printf("请分别输入语文、数学、英语、物理四科成绩：");
        for (ii = 0; ii < 4; ii++) {
            scanf_s("%f", &stu[i].score[ii]);
        }
    }
}
int main() {
    printf("请输入即将输入的学生数量：");
    scanf_s("%d", &num);
    inputFromKeyboard(stu,num);
    outputToScreen(stu, num);
    averageScore(stu, num);
    sortByAverageScore(stu, num);
    return 0;
}