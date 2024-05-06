#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//普通用户结构数组
typedef struct users{
	char users[21];			//通用名 
	char name[21];     		//用户名
	char mobileNumber[12];  //手机号码
	char password[21];		//密码
	float balance;			//余额
	int memberType;		 	//会员类型，0表示普通会员，1表示银卡会员，2表示金卡会员
	float discount;    		//普通会员没折扣，银卡会员9折，金卡会员8折
	int userState;			//账号状态，0表示正常，1表示锁定
}Members;

//管理员结构数组
typedef struct {
	char chg_name[21];
	char chg_password[21];
}administrator;
administrator c = { "admin", "admin" };

//商品结构数组
typedef struct {
	char name[21];		//名字
	int number;			//编号
	float price;		//单价
	float inventory;	//库存
	float sum;			//单个商品营业额
	int frequency;		//购买次数
}Goods;
//创建三个商品对象，o存放当前对象，k为空白对象
Goods  o, k;
Goods apple = { "apple",11111,0.75,1000,0,0 };
Goods banana = { "banana",22222,3.5,1000,0,0 };
Goods pineapple = { "pineapple",33333,4.2,1000,0,0};

//购物清单结构数组
typedef struct {
	float appleNumber;
	float bananaNumber;
	float pineappleNumber;
	float listsum;
}shoppingList;
//list1存放当前清单，kongbai用来清空清单
shoppingList list1 = { 0,0,0,0 };
shoppingList kongbaiList = { 0,0,0,0 };

//a用来暂存注册信息，b用来暂存登陆写入信息，m用来获取用户信息，d在覆盖的时候用，kongbai一直都是空白
Members a, b, d, m;
Members kongbai = { "","","","",0,3,0,3 };
int log = 0;		//用来记录登陆状态，0表示未登录，1表示已登录，2表示管理员状态

//为了避免重复声明，先声明为全局变量
int number;	//商品编号
float jin;	//斤
float sum = 0; //总营业额
int n;
int i;		//处理for累加
int l;		//判断用户名、密码长度
int t;		//进入充值系统仅显示一次会员广告
char temp;

//覆盖原用户数据
void reWriteUsers() {
	FILE* fp = fopen("users.txt", "r+");
	//d空白对象，m为用户数据对象，相同结构体
	while (fread(&d, sizeof(Members), 1, fp) == 1) {
		if (strcmp(d.name, m.name) == 0 || strcmp(d.mobileNumber,m.mobileNumber) == 0) {
			fseek(fp, -(int)sizeof(Members), SEEK_CUR);	//指针移至修改目标前
			fwrite(&m, sizeof(Members), 1, fp);		//写入新的m覆盖原m
			break;
		}
	}
	fclose(fp);
}

//覆盖原商品数据（单个商品）
void reWriteGoods() {
	//o为当前修改的商品
	FILE* fp = fopen("goods.txt", "r+");
	while (fread(&k, sizeof(Goods), 1, fp) == 1) {
		if (strcmp(k.name, o.name) == 0) {
			fseek(fp, -(int)sizeof(Goods), SEEK_CUR);	//指针移至修改目标前
			fwrite(&o, sizeof(Goods), 1, fp);
			break;
		}
	}
	fclose(fp);
}

//状态显示
void state() {
	printf("您的用户名是：%s，你的电话号码是：%s，余额：%.2f，", m.name, m.mobileNumber, m.balance);
	if (m.memberType == 0) {
		printf("普通会员，");
	}
	else if (m.memberType == 1) {
		printf("银卡会员，");
	}
	else if (m.memberType == 2) {
		printf("金卡会员，");
	}

	if (m.userState == 0) {
		printf("用户状态正常\n");
	}
	else {
		printf("用户已锁定\n");
	}
}

//注册用户名管理(用户名已查重)
void chargeName() {
	while (1) {
		FILE* fp = fopen("users.txt", "a+");
		printf("请输入用户名\n");
		scanf_s("%s", &a.name, 50);
		fread(&d, sizeof(Members), 1, fp);
		while (1) {
			if (strcmp(d.name, a.name) == 0) {
				printf("用户名已存在！请重新注册！\n");
				i = 0;
				fclose(fp);
				return;
			}
			else {
				if (!feof(fp)) {
					fread(&d, sizeof(Members), 1, fp);
				}
				else {
					//用户名还未存在，则进入下一步
					fclose(fp);
					i = 1;
					break;
				}
			}
		}
		l = strlen(a.name);
		if (l > 20) {
			printf("用户名不得超过20位！\n请重新输入用户名\n");
			continue;
		}
		for (i = 0; i < l; i++) {
			temp = a.name[i];
			if (!(temp >= '0' && temp <= '9' || temp >= 'a' && temp <= 'z' || temp >= 'A' && temp <= 'Z')) {
				printf("用户名含非法字符！\n请重新输入用户名\n");
				continue;
			}
		}
		//两个if都过了就break出来
		i = 1;
		break;
	}
	
}

//注册时手机号码管理(手机号已查重)
void phoneNumber() {
	while (1) {
		FILE* fp = fopen("users.txt", "r+");
		printf("请输入您的手机号码\n");
		scanf_s("%s", &a.mobileNumber, 50);
		fread(&d, sizeof(Members), 1, fp);
		while (1) {
			if (strcmp(d.mobileNumber, a.mobileNumber) == 0) {
				printf("手机号已存在！请重新注册！\n");
				i = 0;
				fclose(fp);
				return;
			}
			else {
				if (!feof(fp)) {
					fread(&d, sizeof(Members), 1, fp);
				}
				else {
					//手机号码还未存在，则进入下一步
					fclose(fp);
					i = 1;
					break;
				}
			}
		}
		l = strlen(a.mobileNumber);
		for (i = 0; i < l; i++) {
			temp = a.mobileNumber[i];
			if (!(temp >= '0' && temp <= '9')) {
				printf("手机号码含非法字符！");
				continue;
			}
		}
		if (l != 11) {
			printf("手机号码长度应为11位");
			continue;
		}
		//两个if都过就成功
		i = 1;
		break;
	}
}

//注册功能
void registers() {
	//用户名管理
	chargeName();
	//用户名重复则重新注册
	if (i == 0) return;
	//手机号码管理
	phoneNumber();
	//手机号重复则重新注册
	if (i == 0) return;
	//密码管理	
	while (1) {
		printf("请输入您的密码\n");
		scanf_s("%s", &a.password, 21);
		if (strlen(a.password) < 6 || strlen(a.password) > 20) {
			printf("密码不合法！长度应该在6位以上！");
			continue;				//再次循环while
		}
		printf("请再次确认您的密码\n");
		scanf_s("%s", &b.password, 21);
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
	FILE* fp = fopen("users.txt", "a+");
	fwrite( &a, sizeof(struct users), 1, fp);
	fclose(fp);
}

//管理员登陆系统
void administrator_signin() {
	int n = 5;
	printf("此为管理员系统，请输入管理员账号");
	while (1) {
		scanf_s("%s", &b.name, 21);
		if (strcmp(b.name, c.chg_name) != 0) {
			printf("查无此管理员！");
			continue;
		}
		else {
			break;
		}
	}
	while (1) {
		printf("请输入管理员密码");
		scanf_s("%s", &b.password, 21);
		if (strcmp(b.password, c.chg_password) != 0) {
			printf("密码错误！");
			continue;
		}
		else {
			log = 2;
			return;
		}
	}
}

//管理员修改信息(商品数据已覆盖)
void modify() {
	while (1) {
		printf("请输入商品编号，输入0返回");
		scanf_s("%d", &number);
		if (number == apple.number) {
			printf("输入1修改单价，输入2修改库存");
			scanf_s("%d", &n);
			//修改单价
			if (n == 1) {
				printf("原单价为%f\n请输入修改后的单价", apple.price);
				scanf_s("%f", &apple.price);
				printf("修改成功，再次修改");
			}
			//修改库存
			else if (n == 2) {
				printf("原库存为%.2f\n请输入修改后的库存", apple.inventory);
				scanf_s("%f", &apple.inventory);
				printf("修改成功，再次修改");
			}
			o = apple;
			reWriteGoods();
		}
		else if (banana.number == number) {
			printf("输入1修改单价，输入2修改库存");
			scanf_s("%d", &n);
			//修改单价
			if (n == 1) {
				printf("原单价为%f\n请输入修改后的单价", banana.price);
				scanf_s("%f", &banana.price);
				printf("修改成功，再次修改");
			}
			//修改库存
			else if (n == 2) {
				printf("原库存为%.2f\n请输入修改后的库存", banana.inventory);
				scanf_s("%f", &banana.inventory);
				printf("修改成功，再次修改");
			}
			o = banana;
			reWriteGoods();
		}
		else if (pineapple.number == number) {
			printf("输入1修改单价，输入2修改库存");
			scanf_s("%d", &n);
			//修改单价
			if (n == 1) {
				printf("原单价为%f\n请输入修改后的单价", pineapple.price);
				scanf_s("%f", &pineapple.price);
				printf("修改成功，再次修改");
			}
			//修改库存
			else if (n == 2) {
				printf("原库存为%.2f\n请输入修改后的库存", pineapple.inventory);
				scanf_s("%f", &pineapple.inventory);
				printf("修改成功，再次修改");
			}
			o = pineapple;
			reWriteGoods();
		}
		else if (number == 0) {
			log = 0;
			//退出管理系统
			return;
		}
	}
}

//管理员查看信息
void check() {
	printf("总营业额：%.2f\n", sum);
	printf("其中，苹果营业额为%.2f，香蕉的营业额为%.2f，菠萝的营业额为%.2f，", apple.sum, banana.sum, pineapple.sum);
	//比较营业额
	if (apple.sum > banana.sum && apple.sum > pineapple.sum) {
		printf("苹果营业额最高\n");
	}
	else if (banana.sum > pineapple.sum) {
		printf("香蕉的营业额最高\n");
	}
	else {
		printf("菠萝的营业额最高\n");
	}
	printf("总购买次数：%d\n", apple.frequency + banana.frequency + pineapple.frequency);
	printf("其中，苹果卖出次数%d，香蕉卖出次数%d，菠萝卖出次数%d，", apple.frequency, banana.frequency, pineapple.frequency);
	//比较购买次数
	if (apple.frequency > banana.frequency && apple.frequency > pineapple.frequency) {
		printf("苹果卖出次数中最多\n");
	}
	else if (banana.frequency > pineapple.frequency) {
		printf("香蕉卖出次数最多\n");
	}
	else {
		printf("菠萝卖出次数最多\n");
	}
}

//管理员删除用户(用户数据已覆盖)
void usersDelete() {
	FILE* fp = fopen("users.txt", "r+");
	fread(&m, sizeof(Members), 1, fp);
	printf("请输入要删除用户的用户名或手机号");
	scanf_s("%s", &b.users, 21);
	while (1) {
		if (strcmp(m.mobileNumber, b.users) == 0 || strcmp(m.name, b.users) == 0) {
			printf("删除后用户所有信息清零，确认请输入1");
			scanf_s("%d", &n);
			if (n == 1) {
				printf("删除中...");
				fseek(fp, -(int)sizeof(Members), SEEK_CUR);	//指针移至修改目标前
				fwrite(&kongbai, sizeof(Members), 1, fp);		//写入新的m覆盖原m
				printf("删除成功！\n");
				fclose(fp);
				return;
			}	
			else {
				printf("不要误操作哦！！\n");
				break;
			}
		}
		else {
			if (!feof(fp)) {
				fread(&m, sizeof(Members), 1, fp);
			}
			else {
				printf("查无此用户");
				fclose(fp);
				return;
			}
		}
	}
	fclose(fp);
}

//登陆功能
void login() {
	int n = 5;
	FILE* fp = fopen("users.txt", "a+");
	fread(&m, sizeof(struct users), 1, fp);
	printf("请输入您的用户名或手机号码\n");
	scanf_s("%s", &b.users, 21);
	while (1) {				//输入用户名或手机号 
		if (strcmp(m.mobileNumber, b.users) == 0 || strcmp(m.name, b.users) == 0) {
			if (m.userState == 0) {
				fclose(fp);
				break;		//说明账号正常，可在下一步输入密码 
			}
			else if(m.userState ==1){
				printf("账号已锁定，请联系管理员处理！\n");
				fclose(fp);
				return;
			}
		}
		else {
			if (!feof(fp)) {
				fread(&m, sizeof(Members), 1, fp);
			}
			else {
				printf("查无此用户，重新输入！\n");
				fclose(fp);
				return;
			}
			
		}
	}
	while (1) {				//输入密码 
		if (n == 0) {			//先判断账号是否锁定 
			printf("账号已锁定，请联系管理员处理！\n");
			m.userState = 1;
			fseek(fp,-(long)sizeof (Members),1);
			fwrite(&m, sizeof(Members), 1, fp);
			return;
		}
		printf("请输入密码\n");
		scanf_s("%s", b.password, 21);
		if (strcmp(m.password, b.password) == 0) {
			printf("登陆成功！\n");
			log = 1;
			break;
		}
		else {
			printf("密码错误！您还有%d次机会重新输入\n", --n);
		}
	}
}

//充值功能(用户数据已覆盖)
void recharge() {
	if (log == 0) {
		printf("用户未登录，即将跳转到登陆页面...\n");
		login();
	}
	float n;					//充值金额
	printf("***********************************************\n");
	printf("*充值10000秒升银卡会员\t充值50000秒升金卡会员*\n");
	printf("*银卡会员购物享九折\t   金卡会员购物享八折*\n");
	printf("***********************************************\n");
	while (1) {
		printf("您的余额为：%.2f，请输入充值金额，退出请输入0\n", m.balance);
		scanf_s("%f", &n);
		if (n == 0) {
			return;
		}
		else if (n == 10000) {			//银卡
			m.balance += n;
			if (m.discount == 1) {
				m.memberType = 1;
				m.discount = (float)0.9;
				printf("恭喜！您已成为银卡会员，享有九折优惠！\n");
			}
		}
		else if (n == 50000) {			//金卡
			m.balance += n;
			if (m.memberType != 2) {
				m.discount = (float)0.8;
				m.memberType = 2;
				printf("恭喜！您已成为金卡会员，享有八折优惠！\n");
			}
		}
		else {							//其他
			m.balance += n;
		}
		reWriteUsers();
	}
	
}

//->确认支付->数据记录
//支付
void pay() {
	while (1) {
		printf("\n\n余额支付请按1，手机支付请按2，放弃支付请按3\n");
		scanf_s("%d", &i);
		if (i == 1) {
			if (m.balance >= list1.listsum) {
				m.balance -= list1.listsum;
				//余额
				reWriteUsers();
				//商品数据
				sum += list1.listsum;
				apple.sum += list1.appleNumber * apple.price * m.discount;
				apple.inventory -= list1.appleNumber;
				if (list1.appleNumber != 0) apple.frequency++;
				o = apple;	reWriteGoods();
				banana.sum += list1.bananaNumber * banana.price * m.discount;
				banana.inventory -= list1.bananaNumber;
				if (list1.bananaNumber != 0) banana.frequency++;
				o = banana;	reWriteGoods();
				pineapple.sum += list1.pineappleNumber * pineapple.price * m.discount;
				pineapple.inventory -= list1.pineappleNumber;
				if (list1.pineappleNumber != 0) pineapple.frequency++;
				o = pineapple;	reWriteGoods();
				list1 = kongbaiList;
				printf("购买成功！物品将于明日送达您的收货地址！\n");
				return;
			}
			else {
				printf("余额不足！推荐使用手机支付哦亲！\n");
				continue;
			}
		}
		else if (i == 2) {
			printf("正在使用手机支付，支付完成请输入1\n");
			scanf_s("%d", &n);
			if (n == 1) {
				sum += list1.listsum;
				apple.sum += list1.appleNumber * apple.price * m.discount;
				apple.inventory -= list1.appleNumber;
				if (list1.appleNumber != 0) apple.frequency++;
				o = apple;	reWriteGoods();
				banana.sum += list1.appleNumber * banana.price * m.discount;
				banana.inventory -= list1.appleNumber;
				if (list1.bananaNumber != 0) banana.frequency++;
				o = banana;	reWriteGoods();
				pineapple.sum += list1.appleNumber * pineapple.price * m.discount;
				pineapple.inventory -= list1.appleNumber;
				if (list1.pineappleNumber != 0) pineapple.frequency++;
				o = pineapple;	reWriteGoods();
				list1 = kongbaiList;
				printf("购买成功！物品将于明日送达您的收货地址！\n");
				return;
			}
		}
		else if (i == 3) {
			printf("确认放弃支付请输入1\n");
			scanf_s("%d", &n);
			if (n == 1) {
				list1 = kongbaiList;
				printf("已取消订单\n");
				return;
			}
		}
	}

}

//展示->编号->数量->清单
//购物功能(用户数据已覆盖，商品数据已覆盖)
void shopping() {
	if (m.memberType == 0) {
		printf("您现在是普通会员，祝您购物愉快！\n");
	}
	else if (m.memberType == 1) {
		printf("您现在是银卡会员，享九折优惠，祝您购物愉快！\n");
	}
	else if (m.memberType == 2) {
		printf("您现在是金卡会员，享八折优惠，祝您购物愉快！\n");
	}
	printf("商品    \t|苹果\t|香蕉\t|菠萝\t|\n");
	printf("单价/斤 \t|%.2f\t|%.2f\t|%.2f\t|\n", apple.price, banana.price, pineapple.price);
	printf("编号    \t|11111\t|22222\t|33333\t|\n");
	while (1) {
		printf("请输入要购买的商品编号，输入9结账，输入0退出商店，");
		scanf_s("%d", &number);
		if (number == 0) {
			break;
		}
		//显示清单
		else if (number == 9) {
			list1.listsum = m.discount * (list1.appleNumber * apple.price + list1.bananaNumber * banana.price + list1.pineappleNumber * pineapple.price);
			if (list1.listsum == 0) {
				printf("购物车里没有商品呢亲！\n");
				continue;
			}
			printf("您的购物清单如下：\n");
			printf("      商品\t   单价/斤\t    数量\t      总价\n");
			if (list1.appleNumber != 0) {
				printf("%10s\t%8.2f\t%8.2f\t%10.2f\n", apple.name, apple.price, list1.appleNumber, (double)list1.appleNumber * apple.price);
			}
			if (list1.bananaNumber != 0) {
				printf("%10s\t%8.2f\t%8.2f\t%10.2f\n", banana.name, banana.price, list1.bananaNumber, (double)list1.bananaNumber * banana.price);
			}
			if (list1.pineappleNumber != 0) {
				printf("%10s\t%8.2f\t%8.2f\t%10.2f\n", pineapple.name, pineapple.price, list1.pineappleNumber, (double)list1.pineappleNumber * pineapple.price);
			}
			if (m.discount != 1) {
				printf("\n\n\n总价(打%d折)\t\t\t\t\t\t%.2f元\t", (int)(m.discount * 10), list1.listsum);
			}
			else {
				printf("\n\n\n总价\t\t\t\t\t\t%.2f元\t",  list1.listsum);
			}
			pay();
			return;
		}
		else if (number == apple.number) {
			o = apple;
			printf("苹果单价%.2f，请问您要购买多少斤呢？", apple.price);
			scanf_s("%f", &jin);
			if (apple.inventory <= jin) {
				printf("很抱歉！商品库存不足，请等待补货...\n");
			}
			else {
				list1.appleNumber += jin;
				printf("已加入购物车。\n");
			}	
		}
		else if (number == banana.number) {
			o = banana;
			printf("香蕉单价%.2f，请问您要购买多少斤呢？", banana.price);
			scanf_s("%f", &jin);
			if (banana.inventory <= jin) {
				printf("很抱歉！商品库存不足，请等待补货...\n");
			}
			else {
				list1.bananaNumber += jin;
				printf("已加入购物车。\n");
			}
		}
		else if (number == pineapple.number) {
			o = pineapple;
			printf("菠萝单价%.2f，请问您要购买多少斤呢？", pineapple.price);
			scanf_s("%f", &jin);
			if (pineapple.inventory <= jin) {
				printf("很抱歉！商品库存不足，请等待补货...\n");
			}
			else {
				list1.pineappleNumber += jin;
				printf("已加入购物车。\n");
			}
		}
	}
}

//用户自行查看及修改账号信息(用户数据已覆盖，修改数据已查重)
void checkAndModify() {
	state();
	printf("修改用户名请输入1，修改手机号码请输入2，修改密码请输入3，注销账户请输入4，退出用户管理模块请输入0\n");
	scanf_s("%d", &i);
	//用户名
	if (i == 1) {
		while (1) {
			t = 1;
			FILE* fp = fopen("users.txt", "r");
			printf("请输入修改后的用户名\n");
			scanf_s("%s", &a.name, 50);
			fread(&d, sizeof(Members), 1, fp);
			while (1) {
				if (strcmp(d.name, a.name) == 0) {
					printf("用户名已存在！请重新选择操作\n");
					fclose(fp);
					return;
				}
				else {
					if (!feof(fp)) {
						fread(&d, sizeof(Members), 1, fp);
					}
					else {
						//用户名还未存在，则进入下一步
						fclose(fp);
						break;
					}
				}
			}
			l = strlen(a.name);
			if (l > 20) {
				printf("用户名不得超过20位！");
				continue;
			}
			for (i = 0; i < l; i++) {
				temp = a.name[i];
				if (!(temp >= '0' && temp <= '9' || temp >= 'a' && temp <= 'z' || temp >= 'A' && temp <= 'Z')) {
					printf("用户名含非法字符！");
					t = 0;
					break;
				}
			}
			if (t == 0) {
				t = 1;
				continue;
			}
			strcpy(m.name,a.name);
			reWriteUsers();
			break;
		}
	}
	//手机号
	else if (i == 2) {
		while (1) {
			printf("请输入您的手机号码\n");
			scanf_s("%s", &a.mobileNumber, 50);
			FILE* fp1 = fopen("users.txt", "r+");
			fread(&d, sizeof(Members), 1, fp1);
			while (1) {
				if (strcmp(d.mobileNumber, a.mobileNumber) == 0) {
					printf("手机号已存在！请重新选择操作！\n");
					fclose(fp1);
					return;
				}
				else {
					if (!feof(fp1)) {
						fread(&d, sizeof(Members), 1, fp1);
					}
					else {
						//手机未存在，下一步
						fclose(fp1);
						break;
					}
				}
			}
			l = strlen(a.mobileNumber);
			for (i = 0; i < l; i++) {
				temp = a.mobileNumber[i];
				if (!(temp >= '0' && temp <= '9')) {
					printf("手机号码含非法字符！\n");
					t = 0;
					break;
				}
			}
			if (t == 0) {
				t = 1;
				continue;
			}
			if (l != 11) {
				printf("手机号码长度应为11位\n");
				continue;
			}
			strcpy(m.mobileNumber, a.mobileNumber);
			reWriteUsers();
			break;
		}
	}
	//密码
	else if(i == 3){
		//确认原密码
		while (1) {
			printf("请输入原密码:");
			scanf_s("%s", &a.password, 21);
			if (strcmp(a.password, m.password) == 0) {
				break;
			}
			else {
				printf("原密码错误！");
				return;
			}
		}
		//修改密码
		while (1) {
			printf("请修改后的密码:");
			scanf_s("%s", &a.password, 21);
			if (strlen(a.password) < 6 || strlen(a.password) > 20) {
				printf("密码不合法！长度应该在6位以上！\n");
				continue;				//再次循环while
			}
			printf("请再次确认您的密码\n");
			scanf_s("%s", &b.password, 21);
			if (strcmp(a.password, b.password) != 0) {
				printf("两次输入的密码不一致！请重新输入！\n");
			}
			//成功
			else {
				strcpy(m.password, a.password);
				reWriteUsers();
				break;
			}
		}
	}
	//注销
	else if (i == 4) {
		FILE* fp = fopen("users.txt", "r+");
		fread(&d, sizeof(Members), 1, fp);
		while (1) {
			if (strcmp(m.name,d.name) == 0) {
				printf("删除后用户所有信息清零，确认请输入1");
				scanf_s("%d", &n);
				if (n == 1) {
					printf("删除中...");
					fseek(fp, -(int)sizeof(Members), SEEK_CUR);	//指针移至修改目标前
					fwrite(&kongbai, sizeof(Members), 1, fp);	//用空白对象去替换原对象
					log = 0;
					printf("删除成功！\n");
					fclose(fp);
					return;
				}
				else {
					printf("不要误操作哦！！\n");
					break;
				}
			}
			else {
				if (!feof(fp)) {
					fread(&d, sizeof(Members), 1, fp);
					continue;
				}
				else {
					printf("删除失败。");
					fclose(fp);
					return;
				}
			}
		}
		fclose(fp);
	}
	//退出用户管理模块
	else if (i == 0) {
		return;
	}
	printf("数据已更新！\n");
}

//主函数
int main() {
	FILE* f = fopen("goods.txt", "w");
	fwrite(&apple, sizeof(Goods), 1, f);
	fwrite(&banana, sizeof(Goods), 1, f);
	fwrite(&pineapple, sizeof(Goods), 1, f);
	fclose(f);
	while (1) {
		FILE* fp = fopen("goods.txt", "r+");
		fread(&apple, sizeof(Goods), 1, fp);
		fread(&banana, sizeof(Goods), 1, fp);
		fread(&pineapple, sizeof(Goods), 1, fp);
		fclose(fp);
		if (log == 0) {
			printf("欢迎来到无人超市管理系统！注册请输入1，登陆请输入2，管理请输入9\n");
		}
		//管理员页面
		else if (log == 2) {
			while (1) {
				printf("修改商品信息请按1，查看后台数据请按2，删除用户请按3，退出请按0\n");
				scanf_s("%d", &n);
				if (n == 1) {
					modify();
					fclose(fp);
					continue;
				}
				else if (n == 2) {
					check();
					break;
				}
				else if (n == 3) {
					usersDelete();
					break;
				}
				else if (n == 0) {
					log = 0;
					break;
				}
			}
			continue;
		}
		//充值和购物功能在登陆后才可看到
		else if(log == 1){
			state();
			printf("充值请按3，购物请按4，查看及修改账号信息请按5，退出账号请按0\n");
		}
		scanf_s("%d", &n);
		if (n == 1) {
			registers();
			continue;
		}
		else if (n == 2) {
			login();
			continue;
		}
		else if (n == 3) {
			recharge();
			continue;
		}
		else if (n == 4) {
			shopping();
			continue;
		}
		else if (n == 5) {
			checkAndModify();
			continue;
		}
		else if (n == 9) {
			administrator_signin();
			continue;
		}
		else if (n == 0) {
			printf("欢迎下次光临！\n");
			log = 0;
			continue;
		}
	}
}