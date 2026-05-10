#include "Student.h"

Student::Student()
  :m_Sign(0),next_Stu(nullptr){}

Student::Student(int sign, const std::string& name, const std::string& clas)
  : m_Sign(sign),
    m_Name(name),
    m_Class(clas),
    m_Math("0"),
    m_Chinese("0"),
    m_Eng("0"),
    m_Computer("0"), 
    next_Stu(nullptr)
{}

Student::~Student(){}

int Student::getsign() const {
  return m_Sign;
}
void Student::setsign(int num){
  m_Sign=num;
}

std::string Student::getname() const {
  return m_Name;

}
void Student::setname(const std::string name){
 m_Name=name;
} 

std::string Student::getclass() const {
  return m_Class;
}
void Student::setclass(const std::string name){
 m_Class=name;
}

std::string Student::getchinese() const {
  return m_Chinese;
}
void Student::setchinese(const std::string name){
 m_Chinese=name;
}

std::string Student::getmath() const {
  return m_Math;
}
void Student::setmath(const std::string name){
 m_Math=name;
}

std::string Student::geteng() const {
  return m_Eng;
}
void Student::seteng(const std::string name){
 m_Eng=name;
}

std::string Student::getcom() const {
  return m_Computer;
}
void Student::setcom(const std::string name){
 m_Computer=name;
}

Student* Student::getnext(){
  return next_Stu;
}
void Student::setnext(Student* next){
  next_Stu=next;
}

double Student::gettotal()const{
  return std::stod(m_Math) + std::stod(m_Chinese) + std::stod(m_Eng) + std::stod(m_Computer);
}