/*
ѧ������ϵͳ��
---����
	ѧ����
		���ݽṹ�����������䣬�Ա�ѧ��
		��������ȡ���޸����ݽṹ
	����ϵͳ��
		���ݽṹ��ѧ��
		��������ʼ��������ɾ���顢�ġ���ѯѧ����������ѯ����ѧ����ϸ��Ϣ
*/
#include<iostream>
#include<string>
#include"Student.h"
#include"Management.h"
using namespace std;
enum OP {
	__EXIT,        //0		�˳�ϵͳ
	__ADD,	       //1		���ѧ����Ϣ 
	__SEARCH,	   //2		��ѯѧ����Ϣ
	__DELETE,	   //3		ɾ��ѧ����Ϣ
	__CHANGE,	   //4		�޸�ѧ����Ϣ
	__DISPLAY,	   //5		��ʾ����ѧ����Ϣ�Լ�ͳ����Ϣ
	__CLEAR,       //6		��յ�ǰҳ��

};
int main() {
	prompt();
	int num;
	cin >> num;
	//��ѭ��
	while (num != __EXIT) {
		if (num < 0 || num>6) {
			cout << "Error: ���� " << num << " �Ƿ�������������\n\n";
			prompt();
			cin >> num;
		}
		else {
			string name;
			int age = 0;
			long long ID = 0;
			string gender;
			switch (num) {
			//���ѧ����Ϣ
			case __ADD:
			{
				cout << "������ѧ��������";
				cin >> name;
				cout << "������ѧ������: ";
				cin >> age;
				cout << "������ѧ��ѧ��: ";
				cin >> ID;
				cout << "������ѧ���Ա�: ";
				cin >> gender;
				Student stu(name, age, ID, gender);
				addStu(stu);
				break;
			}
			//��ѯѧ����Ϣ
			case __SEARCH:
			{
				cout << "***********************" << endl;
				cout << "1����ȷ����" << endl;
				cout << "0��ģ������" << endl;
				int flag;
				cin >> flag;
				if (flag == 0) {
					cout << "*1������������" << endl;
					cout << "*2�����������" << endl;
					cout << "*3�����Ա����" << endl;
					int instruct;
					cin >> instruct;
					switch (instruct) {
					case 1: {
						cout << "�����뽫Ҫ����ѧ��������" << endl;
						cin >> name;
						Student lookStu;
						lookStu.changeName(name);
						lookupStu(lookStu, instruct);
						break;
					}
					case 2: {
						cout << "�����뽫Ҫ����ѧ�����䣺" << endl;
						cin >> age;
						Student lookStu;
						lookStu.changeAge(age);
						lookupStu(lookStu, instruct);
						break;
					}
					case 3: {
						cout << "�����뽫Ҫ����ѧ���Ա�" << endl;
						cin >> gender;
						Student lookStu;
						lookStu.changeGender(gender);
						lookupStu(lookStu, instruct);
						break;
					}
					default: {
						cout << "�����Ƿ�.............." << endl;
						break;
					}
					}
				}
				else {
					cout << "�����뽫Ҫ����ѧ��ѧ�ţ�" << endl;
					cin >> ID;
					Student lookStu;
					lookStu.changeID(ID);
					lookupStu(lookStu);
				}
				break;
			}
			//ɾ��ѧ����Ϣ
			case __DELETE: {
				cout << "�����뽫Ҫɾ��ѧ��ѧ�ţ�" << endl;
				cin >> ID;
				Student deleStu;
				deleStu.changeID(ID);
				deleteStu(deleStu);
				break;
			}
			//�޸�ѧ����Ϣ
			case __CHANGE: {
				char newName[20];
				long long newAge;
				char newGender[10];
				cout << "�����뽫Ҫɾ��ѧ��ѧ�ţ�" << endl;
				cin >> ID;
				cout << "������ԭѧ����Ϣ" << endl;
				cout << "ѧ��������";
				cin >> name;
				cout << "ѧ�����䣺";
				cin >> age;
				cout << "ѧ���Ա�";
				cin >> gender;

				cout << "�������ѧ������Ϣ��" << endl;
				cout << "ѧ��������";
				cin >> newName;
				cout << "ѧ�����䣺";
				cin >> newAge;
				cout << "ѧ���Ա�";
				cin >> newGender;
				Student stu(name, age, ID, gender);
				Student newStu(newName, newAge, ID, newGender);
				changeStu(stu, newStu);
				break;
			}
			//����ļ�������ѧ����Ϣ
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