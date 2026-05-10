#ifndef STUDENT_H
#define STUDENT_H

#include<string>
class Student{
  private:
    int m_Sign;
    std::string m_Name;
    std::string m_Class;
    std::string m_Math;
    std::string m_Chinese;
    std::string m_Eng;
    std::string m_Computer;
    Student* next_Stu;

  public:
    Student();
    Student(int id,const std::string& name,const std::string& clas);
    ~Student();  

    int getsign()const;
    void setsign(int sign);
    std::string getname()const;
    void setname(const std::string name);
    std::string getclass()const;
    void setclass(const std::string name);
    std::string getmath()const;
    void setmath(const std::string name);
    std::string getchinese()const;
    void setchinese(const std::string name);
    std::string geteng()const;
    void seteng(const std::string name);
    std::string getcom()const;
    void setcom(const std::string name);
    Student* getnext();
    void setnext(Student* next);
    double gettotal()const;


};

#endif 