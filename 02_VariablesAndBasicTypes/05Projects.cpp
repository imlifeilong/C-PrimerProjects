#include <iostream>
#include <string>
#include <ctime>
using namespace std;


#define MAX_LENGTH  1000


// 联系人 结构体
struct Person
{
	string name;
	int age;
	int sex;
	string phone;
	string address;

};

// 通讯录 结构体
struct Contact
{
	int length=0;
	Person person[MAX_LENGTH];
};



Contact contact;



void AddPerson(Contact * contact)
{
	if (contact->length >= MAX_LENGTH)
	{
		cout << "联系人已满" << endl;
		return;
	}
	Person person;
	cout << "请输入姓名：";
	cin >> person.name;
	cout << "请输入年龄：";
	cin >> person.age;

	
	int sex;
	while (true)
	{
		cout << "请输入性别：\n0：女\n1：男\n";
		cin >> sex;
		if (sex == 0 || sex == 1)
		{
			person.sex = sex;
			break;
		}
		else 
		{
			cout << "输入错误，请重新输入！" << endl;
		}
	}

	cout << "请输入电话：";
	cin >> person.phone;

	cout << "请输入地址：";
	cin >> person.address;
	contact->person[contact->length] = person;
	
	// 更新通讯录人数
	contact->length++;
	cout << "添加成功" << endl;
	system("pause"); // 按任意键继续
	system("cls"); // 清屏操作
}

void ShowContact(Contact* contact)
{
	if (contact->length == 0)
	{
		cout << "通讯录为空" << endl;
	}
	else 
	{
		for (int i = 0; i < contact->length; i++)
		{
			cout << "联系人姓名：" << contact->person[i].name;
			cout << "\t年龄：" << contact->person[i].age;
			cout << "\t性别：" << (contact->person[i].sex == 0 ? "女" : "男");
			cout << "\t电话：" << contact->person[i].phone;
			cout << "\t地址：" << contact->person[i].address;
			cout << endl;
		}
	}
	
	system("pause"); // 按任意键继续
	system("cls"); // 清屏操作
}


// 返回通讯录中成员的索引，否则返回-1
int IndexOfContact(Contact* contact, string name)
{
	for (int i = 0; i < contact->length; i++)
	{
		if (name == contact->person[i].name)
		{
			return i;
		}
	}
	return -1;
}

void DeletePerson(Contact* contact, string name)
{
	int index = IndexOfContact(contact, name);
	if (-1 != index)
	{
		// 数组删除，只需要将该位置后的所有元素向前移动一位，覆盖掉当前位置即可
		for (int i = index; i < contact->length; i++)
		{
			contact->person[i] = contact->person[i + 1];
		}
		contact->length--; // 更新通讯录人数
		cout << "删除成功" << endl;
	}
	else
	{
		cout << "没有查找到联系人" << endl;
	}
	system("pause"); // 按任意键继续
	system("cls"); // 清屏操作
}


void FindPerson(Contact* contact)
{
	cout << "请输入姓名：" << endl;
	string name;
	cin >> name;
	int index = IndexOfContact(contact, name);
	if (-1 != index)
	{
		cout << "联系人姓名：" << contact->person[index].name;
		cout << "\t年龄：" << contact->person[index].age;
		cout << "\t性别：" << (contact->person[index].sex == 0 ? "女" : "男");
		cout << "\t电话：" << contact->person[index].phone;
		cout << "\t地址：" << contact->person[index].address;
		cout << endl;
	}
	else
	{
		cout << "没有查找到联系人" << endl;
	}
	system("pause"); // 按任意键继续
	system("cls"); // 清屏操作
}

void UpdatePerson(Contact* contact)
{
	cout << "请输入姓名：" << endl;
	string name;
	cin >> name;
	int index = IndexOfContact(contact, name);
	if (-1 != index)
	{
		cout << "请输入姓名：";
		cin >> contact->person[index].name;
		cout << "请输入年龄：";
		cin >> contact->person[index].age;

		int sex;
		while (true)
		{
			cout << "请输入性别：\n0：女\n1：男\n";
			cin >> sex;
			if (sex == 0 || sex == 1)
			{
				contact->person[index].sex = sex;
				break;
			}
			else
			{
				cout << "输入错误，请重新输入！" << endl;
			}
		}

		cout << "请输入电话：";
		cin >> contact->person[index].phone;

		cout << "请输入地址：";
		cin >> contact->person[index].address;
		cout << "修改成功" << endl;
	}
	else
	{
		cout << "没有查找到联系人" << endl;
	}
	system("pause"); // 按任意键继续
	system("cls"); // 清屏操作
}

void EmptyContact(Contact* contact)
{
	// 将通讯录的人数置为0，做逻辑删除
	contact->length = 0;
	cout << "通讯录已清空" << endl;
	system("pause"); // 按任意键继续
	system("cls"); // 清屏操作
}
void ShowMenu()
{
	cout << "*********************************" << endl;
	cout << "********* 1、增加联系人 *********" << endl;
	cout << "********* 2、显示联系人 *********" << endl;
	cout << "********* 3、删除联系人 *********" << endl;
	cout << "********* 4、查找联系人 *********" << endl;
	cout << "********* 5、修改联系人 *********" << endl;
	cout << "********* 6、清空联系人 *********" << endl;
	cout << "********* 7、退出通讯录 *********" << endl;
	cout << "*********************************" << endl;
}


void ContactBookMain()
{
	while (true)
	{
		ShowMenu();
		int op;
		cin >> op;
		switch (op)
		{
		
		case(1):
			AddPerson(&contact);
			break;
		case(2):
			ShowContact(&contact);
			break;
		case(3):
		{
			// 如果代码比较复杂，需要用{}包起来
			string name;
			cout << "请输入姓名：" << endl;
			cin >> name;
			DeletePerson(&contact, name);
			break;
		}
		case(4):
			FindPerson(&contact);
			break;
		case(5):
			UpdatePerson(&contact);
			break;
		case(6):
			EmptyContact(&contact);
			break;
		case(7):
			cout << "退出系统" << endl;
			return;
		}

	}
	
}


void ProjectMain()
{
	ContactBookMain();
}