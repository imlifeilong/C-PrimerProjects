#include <iostream>
#include <string>
#include <ctime>
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

void PointAndArray() 
{
	int array[] = { 1,2,3,4,5 };
	int* p = array; // p指向array的首地址，即指向第一个元素


	cout << "通过索引访问第一个元素："<< array[0] << endl;
	cout << "通过指针访问第一个元素："<< * p << endl;
	p++;
	cout << "通过指针访问第二个元素：" << *p << endl;

	int* p2 = array;
	int length = sizeof(array) / sizeof(array[0]);
	for (int i = 0; i < length; i++)
	{
		cout << *p2 << endl;
		p2++;
	}

}

// 地址传递 接收两个变量的地址， 可以改变实参的值
void AddressPropagationSwap(int *a, int *b)
{
	int tmp = *a; // tmp 存a指向内存地址的值
	*a = *b;	  // a 所指内存的地址 指向 b 指向的内存地址的值	
	*b = tmp;	  // b指向内存的地址的值赋值为tmp
}




void BubbleSortWithPoint(int* array, int length)
{
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				int tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
			}
		}
	}
}

void PrintResult(int* array, int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << array[i] << " ";
	}
}


// 结构体 一些类型的集合，来组成一个自定义的类型
struct Student
{
	string name;
	int age;
	float score;
} student;


void StructData()
{
	// 结构体赋值的三种方式
	// 1 创建的时候 struct 关键字可以省略
	struct stu0;

	struct Student stu1;
	stu1.name = "李四";
	stu1.age = 20;
	stu1.score = 88.6;

	cout << "姓名：" << stu1.name << " 年龄：" << stu1.age << " 分数：" << stu1.score << endl;
	// 2
	struct Student stu2 = { "张三", 18, 98.5 };
	cout << "姓名：" << stu2.name << " 年龄：" << stu2.age << " 分数：" << stu2.score << endl;

	// 3 初始化的时候就定义 student
	student.name = "王五";
	student.age = 25;
	student.score = 86;
	cout << "姓名：" << student.name << " 年龄：" << student.age << " 分数：" << student.score << endl;
}


void StructArrayData()
{
	// 结构体数组
	Student StudentArray[3] = {
		{ "李四", 20, 88.6 },
		{ "张三", 18, 98.5 },
		{ "王五", 25, 86 },
	};

	for (int i = 0; i < 3;i++)
	{
		cout << "姓名：" << StudentArray[i].name << " 年龄：" << StudentArray[i].age << " 分数：" << StudentArray[i].score << endl;
	}
}

void StructPointData()
{
	// 结构体指针
	struct Student stu = { "张三", 18, 98.5 };
	// s指针指向 stu的地址
	struct Student* s = &stu;
	cout << "姓名：" << s->name << " 年龄：" << s->age << " 分数：" << s->score << endl;
}

struct Teacher 
{
	int id;
	string name;
	int age;
	Student student; // 老师所带的学生的结构体
};


struct Teachers
{
	string name;
	Student student[5];
};



void allocateMemory(Teachers tchs [], int length)
{
	string names = "ABCDE";
	for (int i = 0; i < length; i++)
	{
		tchs[i].name = "teacher_";
		tchs[i].name += names[i];
		
		for (int j = 0; j < 5; j++)
		{
			tchs[i].student[j].name = "student_";
			tchs[i].student[j].name +=names[j];
			tchs[i].student[j].score =  rand() % 61 + 40; // 随机生成分数
		}
	}

}

void printTeachers(Teachers tchs[], int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << "老师姓名：" << tchs[i].name << endl;

		for (int j = 0; j < 5; j++)
		{
			cout << "学生姓名：" << tchs[i].student[j].name << " 学分：" << tchs[i].student[j].score << endl;
		}
	}
}
void teachersMain()
{
	srand((unsigned int)time(NULL)); // 添加随机种子
	Teachers tchs[3];
	int length = sizeof(tchs) / sizeof(tchs[0]);
	allocateMemory(tchs, length);
	printTeachers(tchs, length);
}






void NestedStructData()
{
	// 嵌套结构体
	
	Teacher teacher;
	teacher.id = 1000001;
	teacher.name = "王老师";
	teacher.age = 33;
	struct Student stu = { "张三", 18, 98.5 };
	teacher.student = stu;

	cout << "老师编号：" << teacher.id << " 姓名：" << teacher.name << " 年龄：" << teacher.age << 
	" 学生的姓名：" << teacher.student.name << " 年龄：" << teacher.student.age << " 分数：" << teacher.student.score << endl;

}

void StructParameterFunction(Student *student)
{
	student->age = 50;
	// 结构体作为函数参数
	cout << "结构体传参-姓名：" << student->name << " 年龄：" << student->age << " 分数：" << student->score << endl;


}

void StructWithConst(const Student *student)
{
	// const 防止修改
	//student->age = 100; // 报错
	cout << " 学生的姓名：" << student->name << " 年龄：" << student->age << " 分数：" << student->score << endl;
}


struct StructHero
{
	string name;
	int age;
	string sex;
};


void HeroBubbleSort(struct StructHero hero[], int length)
{
	// 数组传参是地址传递，类似python中的列表
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length - i - 1; j++)
		{
			if (hero[j].age > hero[j + 1].age)
			{
				StructHero tmp = hero[j];
				hero[j] = hero[j + 1];
				hero[j + 1] = tmp;
			}
		}
	}
}

void PrintHero(struct StructHero hero[], int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << "英雄名：" << hero[i].name << " 年龄：" <<  hero[i].age << " 性别："<< hero[i].sex << endl;
	}
}


void HeroMain()
{
	StructHero hero[] = {
		{"张三", 14, "男"},
		{"刘四", 33, "男"},
		{"关五", 24, "女"},
		{"赵六", 14, "男"},
		{"吕无", 16, "男"},
	};

	int length = sizeof(hero) / sizeof(hero[0]);
	PrintHero(hero, length);
	HeroBubbleSort(hero, length);

	cout << "排序后：" << endl;
	PrintHero(hero, length);

}

void ContainerDataTypeMain()
{
	//ArrayData();
	//FindMaxValue();
	//ReverseArray();
	//BubbleSort();
	//TwoDimensionalArray();
	//PointData();
	//PointAndArray();

	//int a = 10;
	//int b = 20;

	//cout << "交换前：" << "a=" << a << " b=" << b << endl;
	//AddressPropagationSwap(&a, &b);
	//cout << "交换后：" << "a=" << a << " b=" << b << endl;

	//int array[] = { 12,1,13,4,2,6,8,3 };
	//int length = sizeof(array) / sizeof(array[0]);
	//BubbleSortWithPoint(array, length);
	//PrintResult(array, length);

	//StructData();
	//StructArrayData();
	//StructPointData();
	//NestedStructData();

	struct Student stu = { "张三", 18, 98.5 };
	//StructParameterFunction(&stu);
	//cout << "结构体传参-姓名：" << stu.name << " 年龄：" << stu.age << " 分数：" << stu.score << endl;
	//StructWithConst(&stu);
	//teachersMain();
	HeroMain();

}





