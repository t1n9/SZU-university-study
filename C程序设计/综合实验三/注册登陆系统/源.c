#include<stdio.h>
#include<string.h>

//普通用户结构数组
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
	int inventory;		//库存
	float sum;			//单个商品营业额
	int frequency;		//购买次数
}Goods;

//创建三个商品对象
Goods apple = { "apple",11111, 0.7, 1000, 0, 0 };
Goods banana = { "banana", 22222,3.5, 1000, 0, 0 };
Goods pineapple = { "pineapple",33333, 4.2, 1000, 0, 0 };

Members a, b;		//创建两个对象，一个用来记录用户信息，一个用来登陆的时候对比
int log = 0;		//用来记录登陆状态，0表示未登录，1表示已登录，2表示管理员状态

//为了避免重复声明，先声明为全局变量
int number;	//商品编号
int jin;	//斤
float sum = 0; //总营业额
int n;
int i;		//处理for累加
int l;		//判断用户名、密码长度
int t;		//进入充值系统仅显示一次会员广告
char temp;
char temparr[] = "\0";

//状态显示
void state() {
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
void chargeName() {
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
void phoneNumber() {
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

//注册功能
void registers() {
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

//管理员登陆系统
void administrator_signin() {
	int n = 5;
	printf("此为管理员系统，请输入管理员账号");
	while (1) {
		scanf_s("%s", &b.name,21);
		if (strcmp(b.name,c.chg_name)!=0) {
			printf("查无此管理员！");
			continue;
		}
		else {
			break;
		}
	}
	while (1) {
		printf("请输入管理员密码");
		scanf_s("%s", &b.password,21);
		if (strcmp(b.password,c.chg_password)!=0) {
			printf("密码错误！");
			continue;
		}
		else {
			log = 2;
			return;
		}
	}
}

//管理员修改信息
void modify() {
	while (1) {
		printf("请输入商品编号，输入0退出管理系统");
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
				printf("原库存为%d\n请输入修改后的库存", apple.inventory);
				scanf_s("%d", &apple.inventory);
				printf("修改成功，再次修改");
			}
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
				printf("原库存为%d\n请输入修改后的库存", banana.inventory);
				scanf_s("%d", &banana.inventory);
				printf("修改成功，再次修改");
			}
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
				printf("原库存为%d\n请输入修改后的库存", pineapple.inventory);
				scanf_s("%d", &pineapple.inventory);
				printf("修改成功，再次修改");
			}
		}
		else if (number == 0) {
			log = 0;
			//退出管理系统
			printf("欢迎来到××管理平台！注册请输入1，登陆请输入2，管理请输入9，退出请按0\n");
			return;
		}
	}	
}

//管理员查看信息
void check() {
	printf("总营业额：%f\n", sum);
	printf("其中，苹果营业额为%f，香蕉的营业额为%f，菠萝的营业额为%f，",apple.sum,banana.sum,pineapple.sum);
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

//管理员删除用户
void usersDelete() {
	printf("请输入要删除用户的用户名或手机号");
	scanf_s("%s", &b.users, 21);
	if (strcmp(a.mobileNumber, b.users) == 0 || strcmp(a.name, b.users) == 0) {
		printf("删除后用户所有信息清零，确认请输入1");
		scanf_s("%d", &n);
		if (n == 1) {
			printf("删除中...\n删除成功！");
			a.balance = 0;
			a.discount = 1;
			a.memberType = 0;
			a.userState = 0;
			for (i = 0; a.name[i] != 0; i++) {
				a.name[i] = 0;
			}
			for (i = 0; a.users[i] != 0; i++) {
				a.users[i] = 0;
			}
			for (i = 0; a.mobileNumber[i] != 0; i++) {
				a.mobileNumber[i] = 0;
			}
			for (i = 0; a.password[i] != 0; i++) {
				a.password[i] = 0;
			}
			return;
		}
	}
}

//登陆功能
void login() {
	int n = 5;
	while (1) {				//输入用户名或手机号 
		printf("请输入您的用户名或手机号码，注册请输入0\n");
		scanf_s("%s", &b.users , 21);
		if (strcmp(a.mobileNumber,b.users) == 0 || strcmp(a.name,b.users) == 0) {
			if (a.userState == 0) {
				break;		//说明账号正常，可在下一步输入密码 
			}
			else {
				printf("账号已锁定，请联系管理员处理！\n");
			}
		}
		else if (strcmp("0", b.users) == 0) {
			printf("即将跳转到注册系统...\n");
			registers();
		}
		else{
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

//充值功能
void recharge() {
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

//购物功能
void shopping() {
	if (a.memberType == 0) {
		printf("您现在是普通会员，祝您购物愉快！\n");
	}
	else if (a.memberType == 1) {
		printf("您现在是银卡会员，享九折优惠，祝您购物愉快！\n");
	}
	else if (a.memberType == 2) {
		printf("您现在是金卡会员，享八折优惠，祝您购物愉快！\n");
	}
	while (1) {
		printf("请输入要购买的商品编号，输入0退出购物界面");
		scanf_s("%d", &number);
		if (number == 0) {
			break;
		}
		else if (number == apple.number) {
			printf("苹果单价%f，请问您要购买多少斤呢？", apple.price);
			scanf_s("%d", &jin);
			if ((a.balance - apple.price * jin * a.discount) > 0 && apple.inventory > 0) {
				a.balance -= apple.price * jin * a.discount;
				printf("购买成功！物品将于明日送达您的收货地址！\n");
				sum += apple.price * jin * a.discount;
				apple.sum += apple.price * jin * a.discount;
				apple.frequency += 1;
				apple.inventory -= jin;
			}
			else if (apple.inventory <= 0) {
				printf("很抱歉！商品库存不足，请等待补货...");
			}
			else {
				printf("余额不足！即将跳转到充值页面...\n");
				recharge();
			}
		}
		else if (number == banana.number) {
			printf("香蕉单价%f，请问您要购买多少斤呢？", banana.price);
			scanf_s("%d", &jin);
			if ((a.balance - banana.price * jin * a.discount) > 0 && banana.inventory > 0) {
				a.balance -= banana.price * jin * a.discount;
				printf("购买成功！物品将于明日送达您的收货地址！\n");
				sum += banana.price * jin * a.discount;
				banana.sum += banana.price * jin * a.discount;
				banana.frequency += 1;
				banana.inventory -= jin;
			}
			else if (banana.inventory <= 0) {
				printf("很抱歉！商品库存不足，请等待补货...");
			}
			else {
				printf("余额不足！即将跳转到充值页面...\n");
				recharge();
			}
		}
		else if (number == pineapple.number) {
			printf("菠萝单价%f，请问您要购买多少斤呢？", pineapple.price);
			scanf_s("%d", &jin);
			if ((a.balance - pineapple.price * jin * a.discount) > 0 && pineapple.inventory > 0) {
				a.balance -= pineapple.price * jin * a.discount;
				printf("购买成功！物品将于明日送达您的收货地址！\n");
				sum += pineapple.price * jin * a.discount;
				pineapple.sum += pineapple.price * jin * a.discount;
				pineapple.frequency += 1;
				pineapple.inventory -= jin;
			}
			else if (pineapple.inventory <= 0) {
				printf("很抱歉！商品库存不足，请等待补货...");
			}
			else {
				printf("余额不足！即将跳转到充值页面...\n");
				recharge();
			}
		}
	}
	
}

//主函数
int main() {
	while (1) {
		if (log == 0) {
			printf("欢迎来到××管理平台！注册请输入1，登陆请输入2，管理请输入9，退出请按0\n");
		}
		else if (log == 2) {
			printf("修改商品信息请按1，查看后台数据请按2，删除用户请按3，退出请按0\n");
			scanf_s("%d", &n);
			if (n == 1) {
				modify();
			}
			else if (n == 2) {
				check();
				continue;
			}
			else if (n == 3) {
				usersDelete();
			}
			else if (n == 0) {
				log = 0;
				continue;
			}
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
		else if (n == 9) {
			administrator_signin();
		}
		else if (n == 0) {
			printf("欢迎下次光临！\n");
			return 0;
		}
	}
}