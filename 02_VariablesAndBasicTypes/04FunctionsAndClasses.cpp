#include <iostream>
#include <string> // �� iostream ����²�ʹ��Ҳ����
#include <ctime>
using namespace std;

// ��������ʱ a��b���β�
int add(int a, int b)
{
	int c = a + b;
	return c;
}

// ֵ����, ����������
// ֵ���ݣ��βα仯ʱ����Ӱ��ʵ��
void ValuePropagationSwap(int a, int b)
{
	cout << "����ǰ��" << "a=" << a << " b=" << b << endl;
	int tmp = a;
	a = b;
	b = tmp;
	cout << "������" << "a=" << a << " b=" << b << endl;
}


// ������������ǰ���߱�����
int sub(int a, int b);

void FunctionsAndClassesMain()
{
	// �������õ�ʱ�� 1��2��ʵ��
	int res = add(1, 2);
	cout << res << endl;
	int a = 1;
	int b = 2;
	ValuePropagationSwap(a, b);

	cout << "���Ľ����" << "a=" << a << " b=" << b << endl;

	res = sub(a, b);
	cout << res << endl;
}

int sub(int a, int b)
{
	return a - b;
}