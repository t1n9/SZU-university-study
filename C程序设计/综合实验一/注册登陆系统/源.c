#include<stdio.h>
#include<string.h>
typedef struct {
	char users[21];			//通用名 
	char name[21];     		//用户名
	char mobileNumber[12];  //手机号码
	char password[21];		//密码
	float balance;			//余额
	int memberType;		 	//会员类型，0表示普通会员，1表示银卡会员，2表示金卡会员
	float discount;    		//普通会员没折扣，银卡会员9折，金卡会员8折
	int userState;			//账号状态，0表示正常，1表示锁定
}Members;

Members a, b;
int log = 0;				//用来记录登陆状态，0表示未登录，1表示已登录

//为了避免重复声明，先声明为全局变量
int n;
int i;		//处理for累加
int l;		//判断用户名、密码长度
int t;		//进入充值系统仅显示一次会员广告
char temp;

void state() {		//状态显示
	printf("您的用户名是：%s，你的电话号码是：%s，余额：%.2f，", a.name, a.mobileNumber, a.balance);
	if (a.memberType == 0) {
		printf("普通会员，");
	}
	else if (a.memberType == 1) {
		printf("银卡会员，");
	}
	else if (a.memberType == 2) {
		printf("金卡会员，");
	}

	if (a.userState == 0) {
		printf("用户状态正常\n");
	}
	else {
		printf("用户已锁定\n");
	}
}

//注册用户名管理
char chargeName() {
	printf("请输入用户名\n");
	scanf_s("%s", &a.name, 50);
	l = strlen(a.name);
	if (l > 20) {
		printf("用户名不得超过20位！");
		chargeName();
	}
	for (i = 0; i < l; i++) {
		temp = a.name[i];
		if (!(temp >= '0' && temp <= '9' || temp >= 'a' && temp <= 'z' || temp >= 'A' && temp <= 'Z')) {
			printf("用户名含非法字符！");
			chargeName();
		}
	}
}

//注册时手机号码管理
int phoneNumber() {
	printf("请输入您的手机号码\n");
	scanf_s("%s", &a.mobileNumber, 50);
	l= strlen(a.mobileNumber);

	for (i = 0; i < l; i++) {
		temp = a.mobileNumber[i];
		if (!(temp >= '0' && temp <= '9')) {
			printf("手机号码含非法字符！");
			phoneNumber();
		}
	}
	if (l != 11) {
		printf("请输入11位手机号码！");
		phoneNumber();
	}
}

void registers() {			//注册功能
	//用户名管理
	chargeName();
	//手机号码管理
	phoneNumber();
	//密码管理	
	while (1) {
		printf("请输入您的密码\n");
		scanf_s("%s", &a.password , 21);
		if (strlen(a.password) < 6 || strlen(a.password) > 20) {
			printf("密码不合法！");
			continue;				//再次循环while
		}
		printf("请再次确认您的密码\n");
		scanf_s("%s", &b.password , 21);
		if (strcmp(a.password, b.password) != 0) {
			printf("两次输入的密码不一致！请重新输入！\n");
		}
		else {
			printf("注册成功，请登陆！\n");
			break;
		}
	}
	//初始化用户信息
	a.userState = 0;
	a.discount = 1;
	a.balance = 100;
	a.memberType = 0;
}

void login() {				//登陆功能
	int n = 5;
	while (1) {				//输入用户名或手机号 
		printf("请输入您的用户名或手机号码\n");
		scanf_s("%s", &b.users , 21);
		if (strcmp(a.mobileNumber,b.users) == 0 || strcmp(a.name,b.users) == 0) {
			if (a.userState == 0) {
				break;		//说明账号正常，可在下一步输入密码 
			}
			else {
				printf("账号已锁定，请联系管理员处理！\n");
			}
		}
		else {
			printf("查无此账号信息！请重新输入！\n");
		}
	}
	while (1) {				//输入密码 
		if (n == 0) {			//先判断账号是否锁定 
			printf("账号已锁定，请联系管理员处理！\n");
			a.userState = 1;
			login();
		}
		printf("请输入密码\n");
		scanf_s("%s", b.password , 21);
		if (strcmp(a.password, b.password) == 0) {
			printf("登陆成功！\n");
			log = 1;
			state();
			break;
		}
		else {
			printf("密码错误！您还有%d次机会重新输入\n", --n);
		}
	}
}

void recharge() {				//充值功能
	if (log == 0) {
		printf("用户未登录，即将跳转到登陆页面...\n");
		login();
	}
	float n;					//充值金额
	t = 0;
	while (1) {
		if (t == 0) {
			printf("***********************************************\n");
			printf("*充值10000秒升银卡会员\t充值50000秒升金卡会员*\n");
			printf("*银卡会员购物享九折\t   金卡会员购物享八折*\n");
			printf("***********************************************\n");
		}
		t = 1;
		printf("您的余额为：%.2f，请输入充值金额，退出请输入0\n", a.balance);
		scanf_s("%f", &n);
		if (n == 0) {
			state();
			return;
		}
		else if (n == 10000) {			//银卡
			a.balance += n;
			if (a.discount == 1) {
				a.memberType = 1;
				a.discount = 0.9;
				printf("恭喜！您已成为银卡会员，享有九折优惠！\n");
			}
		}
		else if (n == 50000) {			//金卡
			a.balance += n;
			if(a.memberType != 2){
				a.discount = 0.8;
				a.memberType = 2;
				printf("恭喜！您已成为金卡会员，享有八折优惠！\n");
			}
		}
		else {							//其他
			a.balance += n;
			printf("充值成功！\n");
		}
	}
}

void shopping() {				//购物功能，还未开发
	if (a.memberType == 0) {
		printf("您现在是普通会员，祝您购物愉快！\n");
	}
	else if (a.memberType == 1) {
		printf("您现在是银卡会员，享九折优惠，祝您购物愉快！\n");
	}
	else if (a.memberType == 2) {
		printf("您现在是金卡会员，享八折优惠，祝您购物愉快！\n");
	}

	printf("店铺还在装修中...敬请期待哦!\n");
}

int main() {
	while (1) {
		if (log == 0) {
			printf("欢迎来到××管理平台！注册请输入1，登陆请输入2，退出请按0\n");
		}
		else {				//充值和购物功能在登陆后才可看到
			printf("充值请按3，购物请按4，退出请按0\n");
		}
		scanf_s("%d", &n);
		if (n == 1) {
			registers();
		}
		else if (n == 2) {
			login();
		}
		else if (n == 3) {
			recharge();
		}
		else if (n == 4) {
			shopping();
		}
		else if (n == 0) {
			printf("欢迎下次光临！\n");
			return 0;
		}
	}
}