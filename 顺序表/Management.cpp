#include<fstream>
#include<iostream>
#include<iomanip>
#include"Management.h"
using namespace std;

//��ʽ�������ʾ��Ϣ
void prompt() {
	printf("***********��ӭʹ��ѧ����Ϣ����ϵͳ����ǰ����%02d��ѧ����*********\n", displayFile());
	printf("*                1)���ѧ����Ϣ                                  *\n");
	printf("*                2)��ѯѧ����Ϣ                                  *\n");
	printf("*                3)ɾ��ѧ����Ϣ                                  *\n");
	printf("*                4)�޸�ѧ����Ϣ                                  *\n");
	printf("*                5)��ʾ����ѧ����Ϣ�Լ�ͳ����Ϣ                  *\n");
	printf("*                6)��յ�ǰҳ��                                  *\n");
	printf("*                0)�˳����                                      *\n");
	printf("******************************************************************\n");
};
//��ʽ�����ѧ����Ϣ
void outputStu(const Student& stu) {
	cout << left << setw(20)<< stu.getName()
		<< setw(5) << stu.getAge()
		<< setw(15) << stu.getID() 
		<< setw(10) << stu.getGender() << endl;

}
//���ѧ����Ϣ
void addStu(const Student& stu) {
	ofstream outputFile;
	outputFile.open("student.dat", ios::app | ios::binary);
	if (outputFile.is_open()) {
		outputFile.write(reinterpret_cast<const char*>(&stu), sizeof(Student));
		cout << "ѧ��"<<stu.getName()
			<<"��������......" << endl;
	}
	else
		cout << "���ʧ��......" << endl;
	outputFile.close();

}

//��ѯѧ����Ϣ
void lookupStu(const Student& stu) {
	ifstream inputFile("student.dat", ios::in | ios::binary);
	if (!inputFile) {
		cout << "��Ϣ��ѯʧ��......" << endl;
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
		cout << "��Ϣ��ѯʧ��......" << endl;
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
//ɾ��ѧ����Ϣ
void deleteStu(const Student& stu) {
	ofstream tempFile("temp.dat", ios::out | ios::binary);
	ifstream originalFile("student.dat", ios::in | ios::binary);
	if (!originalFile && !tempFile)
		cerr << "ɾ��ʧ�ܣ��ļ�δ��" << endl;
	Student temp;
	while (originalFile.peek() != EOF) {
		originalFile.read(reinterpret_cast<char*>(&temp), sizeof(Student));
		//������ɾ������Ϣ���Ƶ�tempFile��
		if (stu.getID() != temp.getID()) {
			tempFile.write(reinterpret_cast<const char*>(&temp), sizeof(Student));
		}
		else {
			cout << "ѧ��" << temp.getName() << "��Ϣ��ɾ��" << endl;
		}
	}
	originalFile.close();
	tempFile.close();
	ofstream outputFile("student.dat", ios::out | ios::binary);
	ifstream temp1File("temp.dat", ios::in | ios::binary);
	//��Ϣд��ԭ�ļ�
	while (temp1File.peek() != EOF) {
		temp1File.read(reinterpret_cast<char*>(&temp), sizeof(Student));
		outputFile.write(reinterpret_cast<const char*>(&temp), sizeof(Student));
	}
	//end
	outputFile.close();
	temp1File.close();
}
//�޸�ѧ����Ϣ
void changeStu(const Student& stu, const Student& newStu) {
	ofstream tempFile("temp.dat", ios::out | ios::binary);
	ifstream originalFile("student.dat", ios::in | ios::binary);
	if (!originalFile && !tempFile)
		cerr << "ɾ��ʧ�ܣ��ļ�δ��" << endl;
	Student temp;
	while (originalFile.peek() != EOF) {
		originalFile.read(reinterpret_cast<char*>(&temp), sizeof(Student));
		//������ɾ������Ϣ���Ƶ�tempFile��
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
	//��Ϣд��ԭ�ļ�
	while (temp1File.peek() != EOF) {
		temp1File.read(reinterpret_cast<char*>(&temp), sizeof(Student));
		outputFile.write(reinterpret_cast<const char*>(&temp), sizeof(Student));
	}
	//end
	outputFile.close();
	temp1File.close();
}
//����ļ���ѧ����Ϣ������
int displayFile() {
	int sum = 0;
	ifstream inputFile("student.dat", ios::in | ios::binary);
	if (!inputFile) {
		cout << "��Ϣ���ʧ��......" << endl;
	}
	Student temp;
	while (inputFile.peek() != EOF) {
		inputFile.read(reinterpret_cast<char*>(&temp), sizeof(Student));
		++sum;
	}
	return sum;
}
//����ļ�������ѧ������ϸ��Ϣ
void displayStu() {
	ifstream inputFile("student.dat", ios::in | ios::binary);
	if (!inputFile) {
		cout << "��Ϣ���ʧ��......" << endl;
	}
	Student temp;
	printf("��ǰ����ϵͳ����%02d��ѧ��\n", displayFile());
	cout << left << setw(20) << "Name" << setw(5) << "Age"
		<< setw(15) << "ID" << setw(10) << "Gender" << endl;
	while (inputFile.peek()!=EOF) {
		inputFile.read(reinterpret_cast<char*>(&temp), sizeof(Student));
		outputStu(temp);
	}
}