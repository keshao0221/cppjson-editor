#ifndef LIST_H
#define LIST_H

#include"Student.h"

class list {
  private:
    Student* phead;

  private:
    void clear();
    int getcount()const;
    Student* findid(int id)const;
    Student* findname(const std::string& name)const;

  public:
    list();
    ~list();

    void initlist(int num);
    void initsys();
    void savefile() const;
    bool reloadfile();
    void outfile()const;
    void display() const;
    void additem(Student* pre);
    void addstu(const std::string&name,const std::string& clas);
    void insertstu(int pos,const std::string& name,const std::string& clas,const std::string& chinese,const std::string& math,const std::string& eng,const std::string& com);
    void deletstu(int id);
    void deletstuclient(int id);
    void modifystu(int id);
    void searchid(int id)const;
    void searchname(const std::string& name)const;
    void inputscore(int sta,int end,const std::string& subject);
    void shownopass()const;
    int sort(int id,int sub)const;
    int classsort(int id,int sub)const;
};

#endif