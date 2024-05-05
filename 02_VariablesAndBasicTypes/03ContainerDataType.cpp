#include <iostream>
#include <string>
using namespace std;

void ArrayData()
{
	// 数组名时常量，不能赋值操作

	int array1[10];
	int array2[10] = { 0,1,2,3,4 }; // 长度不够时，用0填补
	int array3[] = { 0,1,2,3,4 ,5};
	
	cout << "array1整个数组占用内存：" << sizeof(array1) << endl; // 40 整形 4字节*10
	cout << "array1每个元素占用内存：" << sizeof(array1[0]) << endl; // 4
	cout << "array1数组的元素个数：" << sizeof(array1)/sizeof(array1[0]) << endl; // 10
	cout << "array1数组 16进制首地址：" << array1 << endl; 
	cout << "array1数组 10进制首地址：" << (long long)array1 << endl;

	cout << "array1第一个元素 16进制首地址：" << &array1[0] << endl;
	cout << "array1第一个元素 10进制首地址：" << (long long)&array1[0] << endl;


	cout << "array2占用内存：" << sizeof(array2) << endl; 
	cout << "array3占用内存：" << sizeof(array3) << endl;

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
	cout << "最大值是：" << max << endl;
}

void ReverseArray()
{
	// 反转数组
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
	// 冒泡排序
	int array1 []= { 4,2,8,0,5,7,1,3,9 };
	int array[] = { 12,1,13,4,2,6,8,3 };
	int length = sizeof(array) / sizeof(array[0]);

	//for (int i = 0; i < length; i++)
	//{
	//	// 一共进行length趟扫描
	//	// 每次使用第i个数，与后面的数进行比较，找出最小的值，放在第i位
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
		// 一共进行length趟扫描
		// 每趟从第一个位置开始扫描，如果当前位置比下一位大，就将当前的数换到下一位
		// length-i-1 每趟比较次数
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

	cout << "二维数组整个数组占用内存：" << sizeof(array) << endl; // 24 整形 4字节*6
	cout << "二维数组第一行占用内存：" << sizeof(array[0]) << endl; // 12 
	cout << "二维数组第一个元素占用内存：" << sizeof(array[0][0]) << endl; // 4
	cout << "二维数组的行数：" << sizeof(array) / sizeof(array[0]) << endl; // 2
	cout << "二维数组的列数：" << sizeof(array[0]) / sizeof(array[0][0]) << endl; // 3
	cout << "二维数组 16进制首地址：" << array << endl;
	cout << "二维数组 10进制首地址：" << (long long)array << endl;

	cout << "二维数组第一行 16进制首地址：" << &array[0] << endl;
	cout << "二维数组第一行 10进制首地址：" << (long long)&array[0] << endl;

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
		
		cout << "同学"+names[i] +"得分：" << sum_score << endl;
	}

}


/*
指针 访问内存地址
32 位操作系统占用 4字节
64 位操作系统占用 8字节

*/

void PointData()
{
	int a = 10;
	int* p;

	cout << "指针占用的内存空间：" << sizeof(p) << endl;

	p = &a; // p指针指向a的地址 &a 取a的地址
	cout << &a << endl; // a的内存地址
	cout << p << endl;	// p指向的内存的地址

	a = 100;
	cout << *p << endl; // 查看指针指向的内存中的数据
	*p = 900; // 修改p 指向的内存的地址的值 即a变量的值
	cout << a << endl;


	// 空指针 指向内存编号为0的空间
	int* p0 = NULL;
	// 0-255内存不没权限访问
	// cout << *p0 << endl;  // 报错

	// 野指针 指向非法的内存空间 访问 报错
	int* p1 = (int*)0x1234;
	//cout << *p1 << endl;


	// 常量指针 const 修饰指针 指针所指的地址可以改，指针所指的地址中的值不能改
	int c = 10;
	int d = 20;
	const int * p2 = &c;

	cout << p2 << "->" << *p2 << endl;
	// *p2 = d; // 报错
	p2 = &d;

	cout << p2 << "->" << *p2 << endl;
	// 指针常量 const 修饰常量 指针所指的地址不能改， 指针所指的地址中的值可以改

	
	int* const p3 = &c;
	cout << p3 << "->" << *p3 << endl;
	*p3 = d;
	// p3 = &d; // 报错
	cout << p3 << "->" << *p3 << endl;

	// const 修饰 指针和常量 指针所指地址和所指地址中的值都不能改

	const int* const p4 = &c;
	// *p4 = d; // 报错
	// p4 = &d; // 报错 




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