#ifndef MENU_H
#define MENU_H

#include "list.h"

class Menu {
private:
    list& studentList;
    int currentRole;

public:
    Menu(list& list);
    void mainMenu();
    void studentMenu();
    void adminMenu();
    bool checkAdminPassword();

private:
    void displayMainMenu();
    void displayStudentMenu();
    void displayAdminMenu();
};

#endif