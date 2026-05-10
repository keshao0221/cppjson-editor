#include "menu.h"
#include "list.h"
#include <iostream>

int main() {
    list studentList;

    if (studentList.reloadfile()) {
        std::cout << "数据加载成功！" << std::endl;
    } else {
        std::cout << "未找到数据文件，初始化新系统..." << std::endl;
        int num;
        std::cout << "请输入学生数量: ";
        std::cin >> num;
        studentList.initlist(num);
        studentList.initsys();
    }

    Menu menu(studentList);
    menu.mainMenu();

    studentList.savefile();
    return 0;
}