#include<string>
#include"Student.h"
using namespace std;

//对学生的操作
string Student::getName() const {
	return name;
}
void Student::changeName(const std::string& name) {
	int length = name.size();
	length = (length < 20 ? length : 19);
	name.copy(this->name, length);
	this->name[length] = '\0';
}

int Student::getAge() const {
	return age;
}
void Student::changeAge(int age) {
	this->age = age;
}

int Student::getID() const {
	return ID;
}
void Student::changeID(int ID) {
	this->ID = ID;
}

string Student::getGender() const {
	return gender;
}
void Student::changeGender(const std::string& gender) {
	int length = gender.size();
	length = (length < 10 ? length : 9);
	gender.copy(this->gender, length);
	this->gender[length] = '\0';
}