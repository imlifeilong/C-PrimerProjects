#include <iostream>
#include <string> // 有 iostream 情况下不使用也可以
#include <ctime>
using namespace std;

// 函数定义时 a和b是形参
int add(int a, int b)
{
	int c = a + b;
	return c;
}

// 值传递, 交换两个数
// 值传递，形参变化时不会影响实参
void ValuePropagationSwap(int a, int b)
{
	cout << "交换前：" << "a=" << a << " b=" << b << endl;
	int tmp = a;
	a = b;
	b = tmp;
	cout << "交换后：" << "a=" << a << " b=" << b << endl;
}


// 函数声明，提前告诉编译器
int sub(int a, int b);

void FunctionsAndClassesMain()
{
	// 函数调用的时候 1和2是实参
	int res = add(1, 2);
	cout << res << endl;
	int a = 1;
	int b = 2;
	ValuePropagationSwap(a, b);

	cout << "最后的结果：" << "a=" << a << " b=" << b << endl;

	res = sub(a, b);
	cout << res << endl;
}

int sub(int a, int b)
{
	return a - b;
}