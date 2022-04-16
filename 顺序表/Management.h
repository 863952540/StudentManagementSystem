#ifndef MANAGEMENT_H
#define MANAGEMENT_H

#include"Student.h"
//格式化输出学生信息
void outputStu(const Student& stu);
//格式化输出提示信息
void prompt();
//添加学生信息
void addStu(const Student& stu);
//查询学生信息
void lookupStu(const Student& stu);//精确查找
void lookupStu(const Student& stu, int flag);//模糊查找
//删除学生信息
void deleteStu(const Student& stu);
//修改学生信息
void changeStu(const Student& stu, const Student& newStu);
//输出文件中学生信息的数量
int displayFile();
//输出文件中所有学生的详细信息
void displayStu();
#endif
