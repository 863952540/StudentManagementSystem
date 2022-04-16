#ifndef STUDENT_H
#define STUDENT_H

#include<string>
#include<algorithm>

class Student {
public:
	Student(const std::string& name = "", unsigned int age = 0, unsigned int ID = 0,
		std::string gender = "") {
		changeName(name);
		this->age = age;
		changeGender(gender);
		this->ID = ID;
	}
	~Student() {}

	//对学生的操作
	std::string getName() const;
	void changeName(const std::string& name);

	int getAge() const;
	void changeAge(int age);

	int getID() const;
	void changeID(int ID);

	std::string getGender() const;
	void changeGender(const std::string& gender);
private:
	char name[20];
	int age;
	long long ID;
	char gender[10];
};


#endif
