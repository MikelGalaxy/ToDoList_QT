#include "task.h"
#include <QString>

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

QString Task::GetDueDate()
{
    return DueDate;
}
QString Task::GetTitle()
{
    return Title;
}
int Task::GetCompletion()
{
    return Completion;
}
QString Task::GetDescription()
{
    return Description;
}

