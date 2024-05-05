#include <iostream>
#include <string> // �� iostream ����²�ʹ��Ҳ����
#include <ctime>
using namespace std;

/*
* �������͵����壺������������ʵ��ڴ�ռ�
01 ����
short	������		2�ֽ�	-2^15 ~ 2^15-1
int		����			4�ֽ�	-2^31 ~ 2^31-1
long	������		Windows 4�ֽڣ�Linux 32λϵͳ 4�ֽ� 64λϵͳ 8�ֽ� -2^31 ~ 2^31-1
long long	�������� 8�ֽ�	-2^63 ~ 2^63-1



02 ������
float	������ 4�ֽ�	7λ��Ч���֣����磺3.141592
double	˫���� 8�ֽ�	15~16λ��Ч����
Ĭ����� 6λ��Ч����

*/ 

void BasicNumberType()
{
	short n1 = 32768; // Խ����
	int n2 = 32768;
	long n3 = 10;
	long long n4 = 3000;

	cout << n1 << endl;
	cout << n2 << endl;
	cout << n3 << endl;
	cout << n4 << endl;

	// ������Ĭ�ϸ�������˫���ȣ���Ҫ����һ��ת��
	// ����f�����ֱ�ӱ�ʾ������
	float f1 = 3.1415926f;
	cout << f1 << endl;
	double f2 = 3.141592657;
	cout << f2 << endl;

	// ��ѧ����
	float f3 = 4e3; // 4 * 10^3 = 4000
	cout << f3 << endl;
	float f4 = 4e-3; // 4 * 0.1^3 = 0.004
	cout << f4 << endl;
}

/*
03 �ַ���
char 1�ֽ� ������ַ���ASCII��
*/

void BasicCharType()
{
	char ch1 = 'a'; // ֻ��ʹ�õ����ţ����ҵ�������ֻ�ܷ�һ���ַ�
	cout << ch1 << endl;
	cout << (int) ch1 << endl; // ��ch1ǿ��ת����int��


}


void KeywordSizeOf()
{
	int n = 1000;
	// sizeof ����һ���������������ռ���ڴ��ֽ�����
	cout << "short ռ���ڴ�ռ䣺" << sizeof(short) << endl;
	cout << "int ռ���ڴ�ռ䣺" << sizeof(n) << endl;
	cout << "long ռ���ڴ�ռ䣺" << sizeof(long) << endl;
	cout << "long long ռ���ڴ�ռ䣺" << sizeof(long long) << endl;
	cout << "float ռ���ڴ�ռ䣺" << sizeof(float) << endl;
	cout << "double ռ���ڴ�ռ䣺" << sizeof(double) << endl;
	cout << "char ռ���ڴ�ռ䣺" << sizeof(char) << endl;
	cout << "bool ռ���ڴ�ռ䣺" << sizeof(bool) << endl;
}


void BasicStringType()
{
	// C�����ַ���, Ҫʹ��˫����
	char str1 [] = "abc";
	cout << str1 << endl;

	// C++����ַ���

	string str2 = "def";
	cout << str2 << endl;


}

/*
bool ���� ֻ������ֵ true false ռ1���ֽ�

*/
void BasicBoolType()
{
	bool isFile = true;
	cout << isFile << endl;  // 1 ��0��ֵ����true

	bool isConnected = false;
	cout << isConnected << endl;	// 0


}

// ��ֵ����
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

	// % ȡ��������������������ұ���������Ϊ0

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

	// C++����Ŀ���㷵�صı��������Լ�����ֵ
	a > b ? a : b = 100;
	cout << "a = " << a << endl;  // 10	
	cout << "b = " << b << endl;  // 100


}

void SwitchSentence()
{
	// switch �ṹ����Ч�ʸߣ����� ֻ���ж����λ��ַ��ͣ�����������

	int score;
	cout << "���������" << endl;
	cin >> score;
	switch (score)
	{
	case 100:
		cout << "����" << endl;
		break;
	case 90:
		cout << "����" << endl;
		break;
	case 80:
		cout << "����" << endl;
		break;
	case 70:
		cout << "����" << endl;
		break;
	case 60:
		cout << "����" << endl;
		break;
	default:
		cout << "������" << endl;
		break;
	}
}

void WhileLoopStructure() 
{
	// ���������� ����ϵͳʱ���������������ֹÿ���������һ��
	srand((unsigned int)time(NULL));
	int num = rand() % 100 + 1;
	int data;

	while (true)
	{
		cout << "����������:" << endl;
		cin >> data;
		if (data > num)
		{
			cout << "̫����" << endl;
		}
		else if (data < num)
		{
			cout << "̫С��" << endl;
		}
		else
		{
			cout << "�¶���" << endl;
			break;
		}

	}

}
void DoWhileLoopStructure()
{
	// ��ִ��һ��ѭ�����ٽ����ж�
	int num = 0;
	do {
		cout << num << endl;
		num++;
	} 
	while (num < 10);


	int x = 100;
	do {
		int a = x % 10; // ��λ
		int b = (x / 10) % 10; // ʮλ
		int c = (x / 100) % 10; // ��λ
		int y = a * a * a + b * b * b + c * c * c;
		if (x ==y)
		{
			cout << x << "��ˮ�ɻ���" << endl;
		}
		x++;
	} while (x < 1000);
}


void ForLoopStructure()
{
	for (int i = 1; i <= 100; i++)
	{
		// 7�ı��� ��λ7 ʮλ7
		if (i % 7 == 0 || i % 10 == 7 || (i < 100 && i / 10 % 10 == 7))
		{
			cout << i << "������������" << endl;
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
	// �˷��ھ���
	for (int i = 1; i < 10; i++)
	{
		// ÿһ��С�ڵ�������
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
			// goto ����ĳ��򲻻�ִ��
			goto SMALL;
		}
		cout << i << endl;
	}
SMALL:
	cout << "ѡ��3" << endl;

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