#include<stdio.h>
#include<stdlib.h>

typedef struct theUsers{
	char name[21];     		//�û���
	char mobileNumber[12];  //�ֻ�����
	char password[21];		//����
}users;

void createFile() {
	FILE *fp;
	if((fp = fopen("users.txt","rb")) == NULL){
		if((fp = fopen("users.txt","wb+")) == NULL){
			printf("�޷������ļ���");
			exit(0);
		}
	}
}

void registers(){
	users a,b;
	FILE *fp;
	char temp[20];
	fp = fopen("users.txt","r");
	//���ļ��ж�ȡһ���ṹ���ַ��飬�浽b 
	fread(&b,sizeof(struct theUsers),1,fp);
	
	//ȷ���û���δע�� 
	printf("�������˺�\n");
	scanf("%s",&a.name);
	while(1){
		//�Ƚ�b�ṹ�����name�Ƿ���� 
		if(strcmp(a.name,b.name)){	//����� 
			if(!feof(fp)){			//δ��ĩβ����� 
				//������ȡ��һ���浽b 
				fread(&b,sizeof(struct theUsers),1,fp);
			}else{
				break;
			}
		}else{
			printf("�û����Ѵ��ڣ�������ע��\n");
			fclose(fp); 
			return;
		}
	}
	//ȷ���ֻ���δע��
/*	printf("�������ֻ���\n");
	scanf("%s",&a.mobileNumber);
	while(1){
		if(strcmp(a.mobileNumber,b.mobileNumber)){
			if(!feof(fp)){
				fread(&b,sizeof(struct theUsers),1,fp);
			}else{
				break;
			}
		}else{
			printf("�ֻ����Ѵ��ڣ�������ע��\n");
			fclose(fp);
			return;
		}
	}
*/	
	printf("�������ֻ���");
	scanf("%s",&a.mobileNumber);
	printf("����������");
	scanf("%s",a.password);
	fwrite(&a,sizeof(struct theUsers),1,fp);
	
}


int main() {
	int c;
	while(1){
		printf("��ӭ��ע���밴1");
		scanf("%d",&c);
		if(c == 1){
			createFile();
			registers();
		}
	}
} 
