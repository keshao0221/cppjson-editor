#include"list.h"
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>

list::list() : phead(nullptr){}

list::~list(){
  clear();
}

void list::clear(){
  while(phead){
    Student* next=phead->getnext();
    delete phead;
    phead=next;
  }
  phead=nullptr;
}

int list::getcount()const{
  int cnt=0;
  Student* tmp=phead->getnext();
  while(tmp){
    cnt++;
    tmp=tmp->getnext();
  }
  return cnt;
}

void list::initlist(int num){
  clear();
  phead=new Student();
  phead->setsign(0);
  phead->setnext(nullptr);

  Student* tmp=phead;
  for(int i=1;i<=num;i++){
    Student* newstu=new Student(i,"","");
    tmp->setnext(newstu);
    tmp=newstu;
  }
}

void list::initsys(){
  Student* tmp=phead->getnext();
  while(tmp){
    std::cout<<"请输入"<<tmp->getsign()<<"的信息:\n";
    std::cout<<"姓名：";
    std::string name,clas;
    std::cin>>name;
    std::cout<<"班级：";
    std::cin>>clas;
    tmp->setname(name);
    tmp->setclass(clas);
    tmp=tmp->getnext();
  }
}

void list::savefile() const{
  std::ofstream file("data.nd",std::ios::binary);
  if(!file){
    std::cerr<<"文件保存失败\n";
    return;
  }

  Student* tmp=phead;
  while(tmp){
    file.write(reinterpret_cast<const char*>(tmp),sizeof(Student));
    tmp=tmp->getnext();
  }
  file.close();
}

bool list::reloadfile(){
  std::ifstream file("data.nd",std::ios::binary);
  if(!file)return false;

  clear();
  phead=new Student;

  Student* tmp=phead;
  Student buffer;
  while(file.read(reinterpret_cast<char*>(&buffer),sizeof(Student))){
    Student* newstu=new Student();
    *newstu=buffer;
    newstu->setnext(nullptr);
    tmp->setnext(newstu);
    tmp=newstu;
  }

  file.close();
  return true;
}

void list::outfile()const{
  std::ofstream file("StudentInformation.txt");
  if(!file){
    std::cerr<<"文件导出失败\n";
    return;
  }

  Student* tmp=phead->getnext();
  while(tmp){
    file << "编号:" << tmp->getsign() 
         << " 姓名:" << tmp->getname() 
         << " 班级:" << tmp->getclass()
         << " 数学:" << tmp->getmath()
         << " 语文:" << tmp->getchinese()
         << " 英语:" << tmp->geteng()
         << " 专业:" << tmp->getcom() << "\n";
    tmp=tmp->getnext();
  }
  file.close();
  std::cout<<"数据已导出到 StudentInformation.txt\n";
}

Student* list::findid(int id)const{
  Student* tmp=phead->getnext();
  while(tmp){
    if(tmp->getsign()==id){
      return tmp;
    }
    tmp=tmp->getnext();
  }
  return nullptr;
}

Student* list::findname(const std::string& name)const{
  Student* tmp=phead->getnext();
  while(tmp){
    if(tmp->getname()==name){
      return tmp;
    }
    tmp=tmp->getnext();
  }
  return nullptr;
}

void list::searchid(int id)const{
  Student* result=findid(id);
  if(result){
    std::cout << "|编号:" << result->getsign() 
              << " |姓名:" << result->getname() 
              << " |班级:" << result->getclass() << "\n";
    std::cout << "|数学成绩:" << result->getmath() << "\n";
    std::cout << "|语文成绩:" << result->getchinese() << "\n";
    std::cout << "|英语成绩:" << result->geteng() << "\n";
    std::cout << "|专业成绩:" << result->getcom() << "\n";
    std::cout << "|总成绩:" << result->gettotal() << "\n";
  }else{
    std::cout<<"未找到编号为"<<id<<"的学生\n";
  }
}

void list::searchname(const std::string& name)const{
  Student* tmp=phead->getnext();
  bool found=false;
  while(tmp){
    if(tmp->getname()==name){
      std::cout << "|编号:" << tmp->getsign() 
                << " |姓名:" << tmp->getname() 
                << " |班级:" << tmp->getclass() << "\n";
      std::cout << "|数学成绩:" << tmp->getmath() << "\n";
      std::cout << "|语文成绩:" << tmp->getchinese() << "\n";
      std::cout << "|英语成绩:" << tmp->geteng() << "\n";
      std::cout << "|专业成绩:" << tmp->getcom() << "\n";
      std::cout << "|总成绩:" << tmp->gettotal() << "\n\n";
      found=true;
    }
    tmp=tmp->getnext();
  }
  if(!found){
    std::cout<<"未找到姓名为"<<name<<"的学生\n";
  }
}

int list::sort(int id,int sub)const{
  Student* target=findid(id);
  if(!target)return 0;

  double targetScore;
  switch(sub){
    case 1: targetScore=std::stod(target->getmath()); break;
    case 2: targetScore=std::stod(target->getchinese()); break;
    case 3: targetScore=std::stod(target->geteng()); break;
    case 4: targetScore=std::stod(target->getcom()); break;
    case 5: targetScore=target->gettotal(); break;
    default: return 0;
  }

  int rank=1;
  Student* tmp=phead->getnext();
  while(tmp){
    double score;
    switch(sub){
      case 1: score=std::stod(tmp->getmath()); break;
      case 2: score=std::stod(tmp->getchinese()); break;
      case 3: score=std::stod(tmp->geteng()); break;
      case 4: score=std::stod(tmp->getcom()); break;
      case 5: score=tmp->gettotal(); break;
      default: score=0;
    }
    if(score>targetScore)rank++;
    tmp=tmp->getnext();
  }
  return rank;
}

int list::classsort(int id,int sub)const{
  Student* target=findid(id);
  if(!target)return 0;

  std::string clas=target->getclass();
  double targetScore;
  switch(sub){
    case 1: targetScore=std::stod(target->getmath()); break;
    case 2: targetScore=std::stod(target->getchinese()); break;
    case 3: targetScore=std::stod(target->geteng()); break;
    case 4: targetScore=std::stod(target->getcom()); break;
    case 5: targetScore=target->gettotal(); break;
    default: return 0;
  }

  int rank=1;
  Student* tmp=phead->getnext();
  while(tmp){
    if(tmp->getclass()==clas){
      double score;
      switch(sub){
        case 1: score=std::stod(tmp->getmath()); break;
        case 2: score=std::stod(tmp->getchinese()); break;
        case 3: score=std::stod(tmp->geteng()); break;
        case 4: score=std::stod(tmp->getcom()); break;
        case 5: score=tmp->gettotal(); break;
        default: score=0;
      }
      if(score>targetScore)rank++;
    }
    tmp=tmp->getnext();
  }
  return rank;
}

void list::display() const{
  Student* temp=phead->getnext();
  while(temp){
    std::cout << "|编号:" << temp->getsign() 
              << " |姓名:" << temp->getname() 
              << " |班级:" << temp->getclass() << "\n";
    std::cout << "|数学成绩:" << temp->getmath() 
              << " 院系名次:" << sort(temp->getsign(), 1) 
              << " 班级名次:" << classsort(temp->getsign(), 1) << "\n";
    std::cout << "|语文成绩:" << temp->getchinese() 
              << " 院系名次:" << sort(temp->getsign(), 2) 
              << " 班级名次:" << classsort(temp->getsign(), 2) << "\n";
    std::cout << "|英语成绩:" << temp->geteng() 
              << " 院系名次:" << sort(temp->getsign(), 3) 
              << " 班级名次:" << classsort(temp->getsign(), 3) << "\n";
    std::cout << "|专业成绩:" << temp->getcom() 
              << " 院系名次:" << sort(temp->getsign(), 4) 
              << " 班级名次:" << classsort(temp->getsign(), 4) << "\n";
    std::cout << "|总成绩:" << temp->gettotal() 
              << " 院系名次:" << sort(temp->getsign(), 5) 
              << " 班级名次:" << classsort(temp->getsign(), 5) << "\n\n";
    temp=temp->getnext();
  }
}

void list::addstu(const std::string& name,const std::string& clas){
  Student* tmp=phead;
  while(tmp->getnext()){
    tmp=tmp->getnext();
  }
  int newId=tmp->getsign()+1;
  Student* newstu=new Student(newId,name,clas);
  tmp->setnext(newstu);
}

void list::insertstu(int pos,const std::string& name,const std::string& clas,const std::string& chinese,const std::string& math,const std::string& eng,const std::string& com){
  Student* tmp=phead;
  for(int i=1;i<pos && tmp;i++){
    tmp=tmp->getnext();
  }
  if(!tmp){
    std::cout<<"插入位置无效\n";
    return;
  }
  Student* newstu=new Student();
  newstu->setsign(pos);
  newstu->setname(name);
  newstu->setclass(clas);
  newstu->setchinese(chinese);
  newstu->setmath(math);
  newstu->seteng(eng);
  newstu->setcom(com);
  newstu->setnext(tmp->getnext());
  tmp->setnext(newstu);

  Student* update=tmp->getnext()->getnext();
  while(update){
    update->setsign(update->getsign()+1);
    update=update->getnext();
  }
}

void list::deletstu(int id){
  Student* tmp=phead;
  while(tmp->getnext()){
    if(tmp->getnext()->getsign()==id){
      Student* del=tmp->getnext();
      tmp->setnext(del->getnext());
      delete del;

      Student* update=tmp->getnext();
      while(update){
        update->setsign(update->getsign()-1);
        update=update->getnext();
      }
      return;
    }
    tmp=tmp->getnext();
  }
  std::cout<<"未找到编号为"<<id<<"的学生\n";
}

void list::deletstuclient(int id){
  deletstu(id);
}

void list::modifystu(int id){
  Student* stu=findid(id);
  if(!stu){
    std::cout<<"未找到编号为"<<id<<"的学生\n";
    return;
  }
  std::cout<<"请输入新的学生信息:\n";
  std::cout<<"姓名：";
  std::string name;
  std::cin>>name;
  stu->setname(name);
  std::cout<<"班级：";
  std::string clas;
  std::cin>>clas;
  stu->setclass(clas);
}

void list::inputscore(int sta,int end,const std::string& subject){
  for(int i=sta;i<=end;i++){
    Student* stu=findid(i);
    if(!stu)continue;
    std::cout<<"请输入学号"<<i<<"的"<<subject<<"成绩：";
    std::string score;
    std::cin>>score;
    if(subject=="数学")stu->setmath(score);
    else if(subject=="语文")stu->setchinese(score);
    else if(subject=="英语")stu->seteng(score);
    else if(subject=="专业")stu->setcom(score);
  }
}

void list::shownopass()const{
  Student* tmp=phead->getnext();
  while(tmp){
    int failCount=0;
    if(std::stod(tmp->getmath())<60)failCount++;
    if(std::stod(tmp->getchinese())<60)failCount++;
    if(std::stod(tmp->geteng())<60)failCount++;
    if(std::stod(tmp->getcom())<60)failCount++;
    if(failCount>=2){
      std::cout << "|编号:" << tmp->getsign() 
                << " |姓名:" << tmp->getname() 
                << " |班级:" << tmp->getclass() << "\n";
      std::cout << "|数学:" << tmp->getmath() 
                << " |语文:" << tmp->getchinese() 
                << " |英语:" << tmp->geteng() 
                << " |专业:" << tmp->getcom() << "\n\n";
    }
    tmp=tmp->getnext();
  }
}