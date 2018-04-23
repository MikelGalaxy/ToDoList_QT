#include "task.h"

Task::Task()
{
    this->DueDate="";
    this->Title="";
    this->Completion=0;
    this->Description="";
}

Task::Task(QString DueDate,QString Title,int Completion,QString Description)
{
    this->DueDate=DueDate;
    this->Title=Title;
    this->Completion=Completion;
    this->Description=Description;
}

