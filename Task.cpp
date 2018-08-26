#include<iostream>
using namespace std;

class Task{
protected:
    char name[100];
    int hours;
public:
    Task();
    Task(char, int);
    Task(const Task&);
    Task& operator=(const Task&);
    void setName(char)const;
    void setHours(int)const;
    const char* getName();
    int getHours();
    virtual int getTotalTime()const;
    virtual void print()const;

};

void Task::print()const{
cout<<hours<<" "<<getTotalTime<<endl;}
class ReccuringTask: Task{
private:
        int repeat;
public:
        ReccurintTask(const char*, int, int);
        virtual int getTotalTime()const;

};

int ReccuringTask::getTotalTime()const
{
return repeat*hours;
}
Reccuring Task::Reccurint Task(const char*n,int h, int r): Task(n,h){
repeat=r;
}


Task::Task(const Employee&t)
{setName(t.name);
setHours(t.hours);
}

Task &Task::operator=(const Task &t)
{ if(this==&t)return *this;
setName(t.name);
setHours(t.hours);
return *this;
}

int Task:: getTotalTime()const{
return hours;}
void Task::setName(const char* n)
{
name=n;
}

const char* Task::getName()const
{
return name;
}

void Task::setHours(int hours)
{
hours=h;
}

int Task::getHours()const
{
return name;
}

Task::Task(const char* n, int h){
    setName(n);
    setHours(h);
}
Task::Task(){
    name="";
    hours=0;
}

