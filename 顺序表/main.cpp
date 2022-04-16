/*
学生管理系统：
---对象：
	学生：
		数据结构：姓名，年龄，性别，学号
		方法：获取、修改数据结构
	管理系统：
		数据结构：学生
		方法：初始化，增、删、查、改、查询学生数量、查询所有学生详细信息
*/
#include<iostream>
#include<string>
#include"Student.h"
#include"Management.h"
using namespace std;
enum OP {
	__EXIT,        //0		退出系统
	__ADD,	       //1		添加学生信息 
	__SEARCH,	   //2		查询学生信息
	__DELETE,	   //3		删除学生信息
	__CHANGE,	   //4		修改学生信息
	__DISPLAY,	   //5		显示所有学生信息以及统计信息
	__CLEAR,       //6		清空当前页面

};
int main() {
	prompt();
	int num;
	cin >> num;
	//主循环
	while (num != __EXIT) {
		if (num < 0 || num>6) {
			cout << "Error: 操作 " << num << " 非法，请重新输入\n\n";
			prompt();
			cin >> num;
		}
		else {
			string name;
			int age = 0;
			long long ID = 0;
			string gender;
			switch (num) {
			//添加学生信息
			case __ADD:
			{
				cout << "请输入学生姓名：";
				cin >> name;
				cout << "请输入学生年龄: ";
				cin >> age;
				cout << "请输入学生学号: ";
				cin >> ID;
				cout << "请输入学生性别: ";
				cin >> gender;
				Student stu(name, age, ID, gender);
				addStu(stu);
				break;
			}
			//查询学生信息
			case __SEARCH:
			{
				cout << "***********************" << endl;
				cout << "1、精确查找" << endl;
				cout << "0、模糊查找" << endl;
				int flag;
				cin >> flag;
				if (flag == 0) {
					cout << "*1、按姓名查找" << endl;
					cout << "*2、按年龄查找" << endl;
					cout << "*3、按性别查找" << endl;
					int instruct;
					cin >> instruct;
					switch (instruct) {
					case 1: {
						cout << "请输入将要查找学生姓名：" << endl;
						cin >> name;
						Student lookStu;
						lookStu.changeName(name);
						lookupStu(lookStu, instruct);
						break;
					}
					case 2: {
						cout << "请输入将要查找学生年龄：" << endl;
						cin >> age;
						Student lookStu;
						lookStu.changeAge(age);
						lookupStu(lookStu, instruct);
						break;
					}
					case 3: {
						cout << "请输入将要查找学生性别：" << endl;
						cin >> gender;
						Student lookStu;
						lookStu.changeGender(gender);
						lookupStu(lookStu, instruct);
						break;
					}
					default: {
						cout << "操作非法.............." << endl;
						break;
					}
					}
				}
				else {
					cout << "请输入将要查找学生学号：" << endl;
					cin >> ID;
					Student lookStu;
					lookStu.changeID(ID);
					lookupStu(lookStu);
				}
				break;
			}
			//删除学生信息
			case __DELETE: {
				cout << "请输入将要删除学生学号：" << endl;
				cin >> ID;
				Student deleStu;
				deleStu.changeID(ID);
				deleteStu(deleStu);
				break;
			}
			//修改学生信息
			case __CHANGE: {
				char newName[20];
				long long newAge;
				char newGender[10];
				cout << "请输入将要删除学生学号：" << endl;
				cin >> ID;
				cout << "请输入原学生信息" << endl;
				cout << "学生姓名：";
				cin >> name;
				cout << "学生年龄：";
				cin >> age;
				cout << "学生性别：";
				cin >> gender;

				cout << "请输入该学生新信息：" << endl;
				cout << "学生姓名：";
				cin >> newName;
				cout << "学生年龄：";
				cin >> newAge;
				cout << "学生性别：";
				cin >> newGender;
				Student stu(name, age, ID, gender);
				Student newStu(newName, newAge, ID, newGender);
				changeStu(stu, newStu);
				break;
			}
			//输出文件中所有学生信息
			case __DISPLAY: {
				displayStu();
				break;
			}
			case __CLEAR: {
				system("cls");
				break;
			}
			default:
				break;
			}
			cout << endl;
			prompt();
			cin >> num;
		}
	}
}