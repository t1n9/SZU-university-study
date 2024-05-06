#include<stdio.h>
#include<stdlib.h>

typedef struct theUsers{
	char name[21];     		//用户名
	char mobileNumber[12];  //手机号码
	char password[21];		//密码
}users;

void createFile() {
	FILE *fp;
	if((fp = fopen("users.txt","rb")) == NULL){
		if((fp = fopen("users.txt","wb+")) == NULL){
			printf("无法创建文件！");
			exit(0);
		}
	}
}

void registers(){
	users a,b;
	FILE *fp;
	char temp[20];
	fp = fopen("users.txt","r");
	//从文件中读取一个结构体字符块，存到b 
	fread(&b,sizeof(struct theUsers),1,fp);
	
	//确认用户名未注册 
	printf("请输入账号\n");
	scanf("%s",&a.name);
	while(1){
		//比较b结构体里的name是否相等 
		if(strcmp(a.name,b.name)){	//不相等 
			if(!feof(fp)){			//未到末尾则继续 
				//继续读取下一个存到b 
				fread(&b,sizeof(struct theUsers),1,fp);
			}else{
				break;
			}
		}else{
			printf("用户名已存在，请重新注册\n");
			fclose(fp); 
			return;
		}
	}
	//确认手机号未注册
/*	printf("请输入手机号\n");
	scanf("%s",&a.mobileNumber);
	while(1){
		if(strcmp(a.mobileNumber,b.mobileNumber)){
			if(!feof(fp)){
				fread(&b,sizeof(struct theUsers),1,fp);
			}else{
				break;
			}
		}else{
			printf("手机号已存在，请重新注册\n");
			fclose(fp);
			return;
		}
	}
*/	
	printf("请输入手机号");
	scanf("%s",&a.mobileNumber);
	printf("请输入密码");
	scanf("%s",a.password);
	fwrite(&a,sizeof(struct theUsers),1,fp);
	
}


int main() {
	int c;
	while(1){
		printf("欢迎，注册请按1");
		scanf("%d",&c);
		if(c == 1){
			createFile();
			registers();
		}
	}
} 
