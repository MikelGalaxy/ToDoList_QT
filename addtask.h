#ifndef ADDTASK_H
#define ADDTASK_H

#include <QDialog>
#include <string>
#include "mainwindow.h"

namespace Ui {
class AddTask;
}

class AddTask : public QDialog
{
    Q_OBJECT

public:
    explicit AddTask(QWidget *parent = 0);
    inline void setOrigin(MainWindow *origin){ this->origin = origin; }
    void SetDataToUpdate(QString OldDueDate,QString OldTitle,int OldCompletion,QString OldDescription);

private:
    Ui::AddTask *ui;
    bool isNew;
    MainWindow *origin;
    QString DueDate;
    QString Title;
    int Completion;
    QString Description;

private slots:
    void on_cancelbtn_clicked();
    void on_completionSlider_valueChanged(int value);
    void on_saveAddbtn_clicked();


};

#endif // ADDTASK_H
