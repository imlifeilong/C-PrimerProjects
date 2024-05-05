#include <iostream>
#include <string> // 有 iostream 情况下不使用也可以
#include <ctime>
using namespace std;

/*
* 数据类型的意义：给变量分配合适的内存空间
01 整形
short	短整型		2字节	-2^15 ~ 2^15-1
int		整形			4字节	-2^31 ~ 2^31-1
long	长整形		Windows 4字节，Linux 32位系统 4字节 64位系统 8字节 -2^31 ~ 2^31-1
long long	长长整形 8字节	-2^63 ~ 2^63-1



02 浮点型
float	单精度 4字节	7位有效数字，比如：3.141592
double	双精度 8字节	15~16位有效数字
默认输出 6位有效数字

*/ 

void BasicNumberType()
{
	short n1 = 32768; // 越界了
	int n2 = 32768;
	long n3 = 10;
	long long n4 = 3000;

	cout << n1 << endl;
	cout << n2 << endl;
	cout << n3 << endl;
	cout << n4 << endl;

	// 编译器默认浮点数是双精度，需要多做一步转换
	// 加上f后可以直接表示单精度
	float f1 = 3.1415926f;
	cout << f1 << endl;
	double f2 = 3.141592657;
	cout << f2 << endl;

	// 科学计数
	float f3 = 4e3; // 4 * 10^3 = 4000
	cout << f3 << endl;
	float f4 = 4e-3; // 4 * 0.1^3 = 0.004
	cout << f4 << endl;
}

/*
03 字符型
char 1字节 存的是字符的ASCII码
*/

void BasicCharType()
{
	char ch1 = 'a'; // 只能使用单引号，并且单引号内只能放一个字符
	cout << ch1 << endl;
	cout << (int) ch1 << endl; // 将ch1强制转换成int型


}


void KeywordSizeOf()
{
	int n = 1000;
	// sizeof 返回一个对象或者类型所占的内存字节数。
	cout << "short 占用内存空间：" << sizeof(short) << endl;
	cout << "int 占用内存空间：" << sizeof(n) << endl;
	cout << "long 占用内存空间：" << sizeof(long) << endl;
	cout << "long long 占用内存空间：" << sizeof(long long) << endl;
	cout << "float 占用内存空间：" << sizeof(float) << endl;
	cout << "double 占用内存空间：" << sizeof(double) << endl;
	cout << "char 占用内存空间：" << sizeof(char) << endl;
	cout << "bool 占用内存空间：" << sizeof(bool) << endl;
}


void BasicStringType()
{
	// C风格的字符串, 要使用双引号
	char str1 [] = "abc";
	cout << str1 << endl;

	// C++风格字符串

	string str2 = "def";
	cout << str2 << endl;


}

/*
bool 类型 只有两个值 true false 占1个字节

*/
void BasicBoolType()
{
	bool isFile = true;
	cout << isFile << endl;  // 1 非0的值都是true

	bool isConnected = false;
	cout << isConnected << endl;	// 0


}

// 赋值运算
void AssigningOperator()
{
	int a = 10;
	a += 2;
	cout << a << endl;  // 12

	a = 10;
	a -= 2;
	cout << a << endl;  // 8

	a = 10;
	a *= 2;
	cout << a << endl;  // 20

	a = 10;
	a /= 2;
	cout << a << endl;  // 5

	a = 10;
	a %= 2;
	cout << a << endl;  // 0

	// % 取余运算必须是整数，并且被除数不能为0

	int a1 = 10;
	int b1 = ++a1 * 10;
	cout << a1 << b1 << endl; // a1=11; b1=110

	int a2 = 10;
	int b2 = a2++ * 10;
	cout << a2 << b2 << endl; // a1=11; b1=100


}

void TernaryOperation()
{
	int a = 10;
	int b = 30;
	int c = 0;
	c = a > b ? a : b;
	cout << "c = " << c << endl; // 30

	// C++中三目运算返回的变量，可以继续赋值
	a > b ? a : b = 100;
	cout << "a = " << a << endl;  // 10	
	cout << "b = " << b << endl;  // 100


}

void SwitchSentence()
{
	// switch 结构清晰效率高，但是 只能判断整形或字符型，不能是区间

	int score;
	cout << "输入分数：" << endl;
	cin >> score;
	switch (score)
	{
	case 100:
		cout << "满分" << endl;
		break;
	case 90:
		cout << "优秀" << endl;
		break;
	case 80:
		cout << "良好" << endl;
		break;
	case 70:
		cout << "还行" << endl;
		break;
	case 60:
		cout << "及格" << endl;
		break;
	default:
		cout << "不及格" << endl;
		break;
	}
}

void WhileLoopStructure() 
{
	// 添加随机种子 利用系统时间生成随机数，防止每次随机数都一样
	srand((unsigned int)time(NULL));
	int num = rand() % 100 + 1;
	int data;

	while (true)
	{
		cout << "请输入数字:" << endl;
		cin >> data;
		if (data > num)
		{
			cout << "太大了" << endl;
		}
		else if (data < num)
		{
			cout << "太小了" << endl;
		}
		else
		{
			cout << "猜对了" << endl;
			break;
		}

	}

}
void DoWhileLoopStructure()
{
	// 先执行一次循环，再进行判断
	int num = 0;
	do {
		cout << num << endl;
		num++;
	} 
	while (num < 10);


	int x = 100;
	do {
		int a = x % 10; // 个位
		int b = (x / 10) % 10; // 十位
		int c = (x / 100) % 10; // 百位
		int y = a * a * a + b * b * b + c * c * c;
		if (x ==y)
		{
			cout << x << "是水仙花数" << endl;
		}
		x++;
	} while (x < 1000);
}


void ForLoopStructure()
{
	for (int i = 1; i <= 100; i++)
	{
		// 7的倍数 个位7 十位7
		if (i % 7 == 0 || i % 10 == 7 || (i < 100 && i / 10 % 10 == 7))
		{
			cout << i << "可以敲桌子了" << endl;
		}
	}
}

void NestedLoop()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << "* ";
		}
		cout << endl;
	}
}

void MultiplicationTables()
{
	// 乘法口诀表
	for (int i = 1; i < 10; i++)
	{
		// 每一列小于等于行数
		for (int j = 1; j <= i; j++)
		{
			cout << j << "*" << i << "=" << i * j << "\t";
		}
		cout << endl;
	}
}


void GoToSentence()
{
	for (int i = 0; i < 10; i++)
	{
		if (i == 3)
		{
			// goto 后面的程序不会执行
			goto SMALL;
		}
		cout << i << endl;
	}
SMALL:
	cout << "选择3" << endl;

}

void BasicDataTypeMain()
{
	 BasicNumberType();
	 KeywordSizeOf();
	 BasicCharType();
	 BasicStringType();
	 BasicBoolType();
	 SwitchSentence();
	 WhileLoopStructure();
	 DoWhileLoopStructure();
	 ForLoopStructure();
	 NestedLoop();
	 MultiplicationTables();
	 GoToSentence();
}