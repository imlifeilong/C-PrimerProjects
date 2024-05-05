#include <iostream>
#include <string>
using namespace std;

void ArrayData()
{
	// ������ʱ���������ܸ�ֵ����

	int array1[10];
	int array2[10] = { 0,1,2,3,4 }; // ���Ȳ���ʱ����0�
	int array3[] = { 0,1,2,3,4 ,5};
	
	cout << "array1��������ռ���ڴ棺" << sizeof(array1) << endl; // 40 ���� 4�ֽ�*10
	cout << "array1ÿ��Ԫ��ռ���ڴ棺" << sizeof(array1[0]) << endl; // 4
	cout << "array1�����Ԫ�ظ�����" << sizeof(array1)/sizeof(array1[0]) << endl; // 10
	cout << "array1���� 16�����׵�ַ��" << array1 << endl; 
	cout << "array1���� 10�����׵�ַ��" << (long long)array1 << endl;

	cout << "array1��һ��Ԫ�� 16�����׵�ַ��" << &array1[0] << endl;
	cout << "array1��һ��Ԫ�� 10�����׵�ַ��" << (long long)&array1[0] << endl;


	cout << "array2ռ���ڴ棺" << sizeof(array2) << endl; 
	cout << "array3ռ���ڴ棺" << sizeof(array3) << endl;

}

void FindMaxValue()
{
	int array[] = { 728,223, 254, 444, 333,554,123,666 };
	int max = 0;
	int length = sizeof(array) / sizeof(array[0]);
	for (int i = 0; i < length; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
	}
	cout << "���ֵ�ǣ�" << max << endl;
}

void ReverseArray()
{
	// ��ת����
	int array[] = { 728,223, 254, 444, 333,554,123,666,1 };
	int length = sizeof(array) / sizeof(array[0]);
	for (int i = 0; i < length / 2; i++)
	{
		int left = i;
		int right = length - 1-i;
		int tmp = array[left];
		array[left] = array[right];
		array[right] = tmp;
	}
	
	for (int i = 0; i < length; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
		
}


void BubbleSort()
{
	// ð������
	int array1 []= { 4,2,8,0,5,7,1,3,9 };
	int array[] = { 12,1,13,4,2,6,8,3 };
	int length = sizeof(array) / sizeof(array[0]);

	//for (int i = 0; i < length; i++)
	//{
	//	// һ������length��ɨ��
	//	// ÿ��ʹ�õ�i�����������������бȽϣ��ҳ���С��ֵ�����ڵ�iλ
	//	for (int j = i+1; j < length; j++)
	//	{
	//		if (array[i] > array[j])
	//		{
	//			int tmp = array[i];
	//			array[i] = array[j];
	//			array[j] = tmp;
	//		}
	//	}
	//}
	for (int i = 0; i < length; i++)
	{
		// һ������length��ɨ��
		// ÿ�˴ӵ�һ��λ�ÿ�ʼɨ�裬�����ǰλ�ñ���һλ�󣬾ͽ���ǰ����������һλ
		// length-i-1 ÿ�˱Ƚϴ���
		for (int j = 0; j < length-i-1; j++)
		{
			if (array[j] > array[j + 1])
			{
				int tmp = array[j];
				array[j] = array[j+1];
				array[j+1] = tmp;
			}
		}
	}

	for (int i = 0; i < length; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;

}

void TwoDimensionalArray()
{
	int array1[2][3];
	int array2[2][3] = { {1,2,3}, {4,5,6} };
	int array3[2][3] = { 1,2,3,4,5,6 };
	int array4[][3] = { 1,2,3,4,5,6 };

	int array[2][3] = {
		{1,2,3},
		{4,5,6}
	};

	cout << "��ά������������ռ���ڴ棺" << sizeof(array) << endl; // 24 ���� 4�ֽ�*6
	cout << "��ά�����һ��ռ���ڴ棺" << sizeof(array[0]) << endl; // 12 
	cout << "��ά�����һ��Ԫ��ռ���ڴ棺" << sizeof(array[0][0]) << endl; // 4
	cout << "��ά�����������" << sizeof(array) / sizeof(array[0]) << endl; // 2
	cout << "��ά�����������" << sizeof(array[0]) / sizeof(array[0][0]) << endl; // 3
	cout << "��ά���� 16�����׵�ַ��" << array << endl;
	cout << "��ά���� 10�����׵�ַ��" << (long long)array << endl;

	cout << "��ά�����һ�� 16�����׵�ַ��" << &array[0] << endl;
	cout << "��ά�����һ�� 10�����׵�ַ��" << (long long)&array[0] << endl;

	int score[3][3] = {
		{100,100,100},
		{80,60,90},
		{90,88,98},
	};
	string names[] = { "alex", "Thom", "Mask" };

	int row_length = sizeof(score) / sizeof(score[0]);
	int column_length = sizeof(score[0]) / sizeof(score[0][0]);
	for (int i = 0; i < row_length; i++)
	{
		int sum_score = 0;
		for (int j = 0; j < column_length; j++)
		{
			
			sum_score += score[i][j];
		}
		
		cout << "ͬѧ"+names[i] +"�÷֣�" << sum_score << endl;
	}

}


/*
ָ�� �����ڴ��ַ
32 λ����ϵͳռ�� 4�ֽ�
64 λ����ϵͳռ�� 8�ֽ�

*/

void PointData()
{
	int a = 10;
	int* p;

	cout << "ָ��ռ�õ��ڴ�ռ䣺" << sizeof(p) << endl;

	p = &a; // pָ��ָ��a�ĵ�ַ &a ȡa�ĵ�ַ
	cout << &a << endl; // a���ڴ��ַ
	cout << p << endl;	// pָ����ڴ�ĵ�ַ

	a = 100;
	cout << *p << endl; // �鿴ָ��ָ����ڴ��е�����
	*p = 900; // �޸�p ָ����ڴ�ĵ�ַ��ֵ ��a������ֵ
	cout << a << endl;


	// ��ָ�� ָ���ڴ���Ϊ0�Ŀռ�
	int* p0 = NULL;
	// 0-255�ڴ治ûȨ�޷���
	// cout << *p0 << endl;  // ����

	// Ұָ�� ָ��Ƿ����ڴ�ռ� ���� ����
	int* p1 = (int*)0x1234;
	//cout << *p1 << endl;


	// ����ָ�� const ����ָ�� ָ����ָ�ĵ�ַ���Ըģ�ָ����ָ�ĵ�ַ�е�ֵ���ܸ�
	int c = 10;
	int d = 20;
	const int * p2 = &c;

	cout << p2 << "->" << *p2 << endl;
	// *p2 = d; // ����
	p2 = &d;

	cout << p2 << "->" << *p2 << endl;
	// ָ�볣�� const ���γ��� ָ����ָ�ĵ�ַ���ܸģ� ָ����ָ�ĵ�ַ�е�ֵ���Ը�

	
	int* const p3 = &c;
	cout << p3 << "->" << *p3 << endl;
	*p3 = d;
	// p3 = &d; // ����
	cout << p3 << "->" << *p3 << endl;

	// const ���� ָ��ͳ��� ָ����ָ��ַ����ָ��ַ�е�ֵ�����ܸ�

	const int* const p4 = &c;
	// *p4 = d; // ����
	// p4 = &d; // ���� 




}


void ContainerDataTypeMain()
{
	//ArrayData();
	//FindMaxValue();
	//ReverseArray();
	//BubbleSort();
	//TwoDimensionalArray();
	PointData();
}