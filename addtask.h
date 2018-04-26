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
    void FindAndUpdateItem(Task t);
    void CanSave();

private:
    Ui::AddTask *ui;
    bool isNew;
    MainWindow *origin;
    QString DueDate;
    QString Title;
    int Completion;
    QString Description;
    Task *mTask;

private slots:
    void on_cancelbtn_clicked();
    void on_completionSlider_valueChanged(int value);
    void on_saveAddbtn_clicked();
    void on_plainTextEdit_textChanged();
    void on_titleEdit_textChanged(const QString &arg1);
    void on_dateEdit_userDateChanged(const QDate &date);
};

#endif // ADDTASK_H
