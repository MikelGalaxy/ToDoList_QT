#ifndef TASK_H
#define TASK_H
#include <QString>

class Task :public QTableModel
{
public:
    Task();
    Task(QString DueDate,QString Title,int Completion,QString Description);
private:
    QString DueDate;
    QString Title;
    int Completion;
    QString Description;
};

#endif // TASK_H
