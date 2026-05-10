#include "menu.h"
#include <iostream>
#include <string>

Menu::Menu(list& list) : studentList(list), currentRole(0) {}

void Menu::displayMainMenu() {
    std::cout << "\n===== 学生管理系统 =====" << std::endl;
    std::cout << "A: 学生登录" << std::endl;
    std::cout << "B: 管理员登录" << std::endl;
    std::cout << "C: 退出系统" << std::endl;
    std::cout << "请选择: ";
}

void Menu::displayStudentMenu() {
    std::cout << "\n===== 学生菜单 =====" << std::endl;
    std::cout << "A: 输出所有学生信息" << std::endl;
    std::cout << "B: 查找学生" << std::endl;
    std::cout << "C: 输出不及格学生" << std::endl;
    std::cout << "D: 导出文件" << std::endl;
    std::cout << "E: 切换身份" << std::endl;
    std::cout << "请选择: ";
}

void Menu::displayAdminMenu() {
    std::cout << "\n===== 管理员菜单 =====" << std::endl;
    std::cout << "A: 输出所有学生信息" << std::endl;
    std::cout << "B: 查找学生" << std::endl;
    std::cout << "C: 删除学生" << std::endl;
    std::cout << "D: 添加学生" << std::endl;
    std::cout << "E: 修改学生信息" << std::endl;
    std::cout << "F: 输出不及格学生" << std::endl;
    std::cout << "G: 批量录入成绩" << std::endl;
    std::cout << "H: 导出文件" << std::endl;
    std::cout << "I: 插入学生" << std::endl;
    std::cout << "J: 保存数据" << std::endl;
    std::cout << "K: 切换身份" << std::endl;
    std::cout << "请选择: ";
}

bool Menu::checkAdminPassword() {
    std::string password;
    std::cout << "请输入管理员密码: ";
    std::cin >> password;
    return password == "admin";
}

void Menu::mainMenu() {
    char choice;
    while (true) {
        displayMainMenu();
        std::cin >> choice;
        choice = toupper(choice);
        
        switch (choice) {
            case 'A':
                currentRole = 1;
                studentMenu();
                break;
            case 'B':
                if (checkAdminPassword()) {
                    currentRole = 2;
                    adminMenu();
                } else {
                    std::cout << "密码错误！" << std::endl;
                }
                break;
            case 'C':
                std::cout << "感谢使用学生管理系统！" << std::endl;
                return;
            default:
                std::cout << "无效选择，请重新输入！" << std::endl;
        }
    }
}

void Menu::studentMenu() {
    char choice;
    while (true) {
        displayStudentMenu();
        std::cin >> choice;
        choice = toupper(choice);
        
        switch (choice) {
            case 'A':
                studentList.display();
                break;
            case 'B': {
                std::cout << "请选择查找方式:\n1. 按编号查找\n2. 按姓名查找\n";
                int searchChoice;
                std::cin >> searchChoice;
                if (searchChoice == 1) {
                    int id;
                    std::cout << "请输入学生编号: ";
                    std::cin >> id;
                    studentList.searchid(id);
                } else if (searchChoice == 2) {
                    std::string name;
                    std::cout << "请输入学生姓名: ";
                    std::cin >> name;
                    studentList.searchname(name);
                } else {
                    std::cout << "无效选择！" << std::endl;
                }
                break;
            }
            case 'C':
                studentList.shownopass();
                break;
            case 'D':
                studentList.outfile();
                break;
            case 'E':
                currentRole = 0;
                return;
            default:
                std::cout << "无效选择，请重新输入！" << std::endl;
        }
    }
}

void Menu::adminMenu() {
    char choice;
    while (true) {
        displayAdminMenu();
        std::cin >> choice;
        choice = toupper(choice);
        
        switch (choice) {
            case 'A':
                studentList.display();
                break;
            case 'B': {
                std::cout << "请选择查找方式:\n1. 按编号查找\n2. 按姓名查找\n";
                int searchChoice;
                std::cin >> searchChoice;
                if (searchChoice == 1) {
                    int id;
                    std::cout << "请输入学生编号: ";
                    std::cin >> id;
                    studentList.searchid(id);
                } else if (searchChoice == 2) {
                    std::string name;
                    std::cout << "请输入学生姓名: ";
                    std::cin >> name;
                    studentList.searchname(name);
                } else {
                    std::cout << "无效选择！" << std::endl;
                }
                break;
            }
            case 'C': {
                int id;
                std::cout << "请输入要删除的学生编号: ";
                std::cin >> id;
                studentList.deletstu(id);
                break;
            }
            case 'D': {
                std::string name, clas;
                std::cout << "请输入新学生姓名: ";
                std::cin >> name;
                std::cout << "请输入新学生班级: ";
                std::cin >> clas;
                studentList.addstu(name, clas);
                std::cout << "学生添加成功！" << std::endl;
                break;
            }
            case 'E': {
                int id;
                std::cout << "请输入要修改的学生编号: ";
                std::cin >> id;
                studentList.modifystu(id);
                break;
            }
            case 'F':
                studentList.shownopass();
                break;
            case 'G': {
                int start, end;
                std::string subject;
                std::cout << "请输入学号范围（开始 结束）: ";
                std::cin >> start >> end;
                std::cout << "请输入科目（数学/语文/英语/专业）: ";
                std::cin >> subject;
                studentList.inputscore(start, end, subject);
                break;
            }
            case 'H':
                studentList.outfile();
                break;
            case 'I': {
                int pos;
                std::string name, clas, chinese, math, eng, com;
                std::cout << "请输入插入位置: ";
                std::cin >> pos;
                std::cout << "请输入学生姓名: ";
                std::cin >> name;
                std::cout << "请输入班级: ";
                std::cin >> clas;
                std::cout << "请输入语文成绩: ";
                std::cin >> chinese;
                std::cout << "请输入数学成绩: ";
                std::cin >> math;
                std::cout << "请输入英语成绩: ";
                std::cin >> eng;
                std::cout << "请输入专业成绩: ";
                std::cin >> com;
                studentList.insertstu(pos, name, clas, chinese, math, eng, com);
                break;
            }
            case 'J':
                studentList.savefile();
                std::cout << "数据保存成功！" << std::endl;
                break;
            case 'K':
                currentRole = 0;
                return;
            default:
                std::cout << "无效选择，请重新输入！" << std::endl;
        }
    }
}