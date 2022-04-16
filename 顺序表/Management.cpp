#include<fstream>
#include<iostream>
#include<iomanip>
#include"Management.h"
using namespace std;

//格式化输出提示信息
void prompt() {
	printf("***********欢迎使用学生信息管理系统（当前共有%02d名学生）*********\n", displayFile());
	printf("*                1)添加学生信息                                  *\n");
	printf("*                2)查询学生信息                                  *\n");
	printf("*                3)删除学生信息                                  *\n");
	printf("*                4)修改学生信息                                  *\n");
	printf("*                5)显示所有学生信息以及统计信息                  *\n");
	printf("*                6)清空当前页面                                  *\n");
	printf("*                0)退出软件                                      *\n");
	printf("******************************************************************\n");
};
//格式化输出学生信息
void outputStu(const Student& stu) {
	cout << left << setw(20)<< stu.getName()
		<< setw(5) << stu.getAge()
		<< setw(15) << stu.getID() 
		<< setw(10) << stu.getGender() << endl;

}
//添加学生信息
void addStu(const Student& stu) {
	ofstream outputFile;
	outputFile.open("student.dat", ios::app | ios::binary);
	if (outputFile.is_open()) {
		outputFile.write(reinterpret_cast<const char*>(&stu), sizeof(Student));
		cout << "学生"<<stu.getName()
			<<"已添加完成......" << endl;
	}
	else
		cout << "添加失败......" << endl;
	outputFile.close();

}

//查询学生信息
void lookupStu(const Student& stu) {
	ifstream inputFile("student.dat", ios::in | ios::binary);
	if (!inputFile) {
		cout << "信息查询失败......" << endl;
	}
	cout << left << setw(20) << "Name" << setw(5) << "Age"
		<< setw(15) << "ID" << setw(10) << "Gender" << endl;
	Student temp;
	//inputFile.seekg(0);
	while (inputFile.peek() != EOF) {
		inputFile.read(reinterpret_cast<char*>(&temp), sizeof(Student));
		if (stu.getID() == temp.getID()) {
			outputStu(temp);
		}
	}
	inputFile.close();
}
void lookupStu(const Student& stu, int flag) {
	ifstream inputFile("student.dat", ios::in | ios::binary);
	if (!inputFile) {
		cout << "信息查询失败......" << endl;
	}
	cout << left << setw(20) << "Name" << setw(5) << "Age"
		<< setw(15) << "ID" << setw(10) << "Gender" << endl;
	Student temp;
	while (inputFile.peek() != EOF) {
		inputFile.read(reinterpret_cast<char*>(&temp), sizeof(Student));
		if (flag == 1 && stu.getName() == temp.getName())
			outputStu(temp);
		else if (flag == 2 && stu.getAge() == temp.getAge())
			outputStu(temp);
		else if(flag == 3 && stu.getGender() == temp.getGender())
			outputStu(temp);
	}
	inputFile.close();
}
//删除学生信息
void deleteStu(const Student& stu) {
	ofstream tempFile("temp.dat", ios::out | ios::binary);
	ifstream originalFile("student.dat", ios::in | ios::binary);
	if (!originalFile && !tempFile)
		cerr << "删除失败，文件未打开" << endl;
	Student temp;
	while (originalFile.peek() != EOF) {
		originalFile.read(reinterpret_cast<char*>(&temp), sizeof(Student));
		//将不需删除的信息复制到tempFile中
		if (stu.getID() != temp.getID()) {
			tempFile.write(reinterpret_cast<const char*>(&temp), sizeof(Student));
		}
		else {
			cout << "学生" << temp.getName() << "信息已删除" << endl;
		}
	}
	originalFile.close();
	tempFile.close();
	ofstream outputFile("student.dat", ios::out | ios::binary);
	ifstream temp1File("temp.dat", ios::in | ios::binary);
	//信息写回原文件
	while (temp1File.peek() != EOF) {
		temp1File.read(reinterpret_cast<char*>(&temp), sizeof(Student));
		outputFile.write(reinterpret_cast<const char*>(&temp), sizeof(Student));
	}
	//end
	outputFile.close();
	temp1File.close();
}
//修改学生信息
void changeStu(const Student& stu, const Student& newStu) {
	ofstream tempFile("temp.dat", ios::out | ios::binary);
	ifstream originalFile("student.dat", ios::in | ios::binary);
	if (!originalFile && !tempFile)
		cerr << "删除失败，文件未打开" << endl;
	Student temp;
	while (originalFile.peek() != EOF) {
		originalFile.read(reinterpret_cast<char*>(&temp), sizeof(Student));
		//将不需删除的信息复制到tempFile中
		if (stu.getID() != temp.getID()) {
			tempFile.write(reinterpret_cast<const char*>(&temp), sizeof(Student));
		}
		else {
			tempFile.write(reinterpret_cast<const char*>(&newStu), sizeof(Student));
		}
	}
	originalFile.close();
	tempFile.close();
	ofstream outputFile("student.dat", ios::out | ios::binary);
	ifstream temp1File("temp.dat", ios::in | ios::binary);
	//信息写回原文件
	while (temp1File.peek() != EOF) {
		temp1File.read(reinterpret_cast<char*>(&temp), sizeof(Student));
		outputFile.write(reinterpret_cast<const char*>(&temp), sizeof(Student));
	}
	//end
	outputFile.close();
	temp1File.close();
}
//输出文件中学生信息的数量
int displayFile() {
	int sum = 0;
	ifstream inputFile("student.dat", ios::in | ios::binary);
	if (!inputFile) {
		cout << "信息输出失败......" << endl;
	}
	Student temp;
	while (inputFile.peek() != EOF) {
		inputFile.read(reinterpret_cast<char*>(&temp), sizeof(Student));
		++sum;
	}
	return sum;
}
//输出文件中所有学生的详细信息
void displayStu() {
	ifstream inputFile("student.dat", ios::in | ios::binary);
	if (!inputFile) {
		cout << "信息输出失败......" << endl;
	}
	Student temp;
	printf("当前管理系统共有%02d名学生\n", displayFile());
	cout << left << setw(20) << "Name" << setw(5) << "Age"
		<< setw(15) << "ID" << setw(10) << "Gender" << endl;
	while (inputFile.peek()!=EOF) {
		inputFile.read(reinterpret_cast<char*>(&temp), sizeof(Student));
		outputStu(temp);
	}
}