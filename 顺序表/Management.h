#ifndef MANAGEMENT_H
#define MANAGEMENT_H

#include"Student.h"
//��ʽ�����ѧ����Ϣ
void outputStu(const Student& stu);
//��ʽ�������ʾ��Ϣ
void prompt();
//���ѧ����Ϣ
void addStu(const Student& stu);
//��ѯѧ����Ϣ
void lookupStu(const Student& stu);//��ȷ����
void lookupStu(const Student& stu, int flag);//ģ������
//ɾ��ѧ����Ϣ
void deleteStu(const Student& stu);
//�޸�ѧ����Ϣ
void changeStu(const Student& stu, const Student& newStu);
//����ļ���ѧ����Ϣ������
int displayFile();
//����ļ�������ѧ������ϸ��Ϣ
void displayStu();
#endif
