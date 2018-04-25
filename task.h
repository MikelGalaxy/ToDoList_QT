#ifndef TASK_H
#define TASK_H
#include <QString>

class Task
{
public:
    Task();
    Task(QString DueDate,QString Title,int Completion,QString Description);
    QString GetDueDate();
    QString GetTitle();
    int GetCompletion();
    QString GetDescription();
    QString StreamOut();
private:
    QString DueDate;
    QString Title;
    int Completion;
    QString Description;
};

#endif // TASK_H
