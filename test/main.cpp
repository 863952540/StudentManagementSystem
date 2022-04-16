#include<fstream>
#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

typedef struct Student {
	string name;
	int age;
}stu;

int main() {
	ofstream outputFile("print.txt", ios::out || ios::binary);
	if (!outputFile) {
		cerr << "ERROE...." << endl;
	}
	stu a;
	a.name = "ÃÏÒåº½";
	a.age = 12;
	outputFile.write(reinterpret_cast<char*>(&a), sizeof(stu));
	outputFile.close();
	stu b;
	ifstream inputFile("print.txt", ios::in || ios::binary);
	if (!inputFile) {
		cerr << "ERROE...." << endl;
	}
	inputFile.read(reinterpret_cast<char*>(&b), sizeof(stu));
	cout << "Name is: " << b.name << setw(5)
		<< "Age is: " << b.age << endl;
	inputFile.close();
}