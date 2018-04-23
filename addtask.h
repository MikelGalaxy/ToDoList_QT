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

private:
    Ui::AddTask *ui;
    bool isNew;
   // MainWindow *origin;

private slots:
    void on_cancelbtn_clicked();
    void on_completionSlider_valueChanged(int value);


public:
     //inline void setOrigin(MainWindow *origin){ this->origin = origin; }

//public:
//    explicit NewTaskDialog(QWidget *parent = 0);
//    void setData(string duedate, string title, string percent, string description);
//    void setPath(string path);
//    inline void setOrigin(MainWindow *origin){ this->origin = origin; }
//    string oldDuedate;
//    string oldTitle;
//    string oldPercent;
//    string oldDescription;
//    ~NewTaskDialog();

//private slots:
//    void on_slider_valueChanged(int value);
//    void on_description_ed_textChanged();
//    void on_title_et_textChanged(const QString &arg1);
//    void on_datepicker_userDateChanged(const QDate &date);
//    void on_savebtn_clicked();
//    void on_cancelbtn_clicked();

//    void on_deletebtn_clicked();

//private:
//    void checkFields();
//    Ui::NewTaskDialog *ui;
//    bool newTask;
//    string path;
//    MainWindow *origin;
};

#endif // ADDTASK_H
