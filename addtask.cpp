#include "addtask.h"
#include "ui_addtask.h"


AddTask::AddTask(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddTask)
{
    ui->setupUi(this);
    ui->completionSlider->setRange(0,100);
    ui->dateEdit->setDisplayFormat("yyyy/MM/dd");
    QDate currdate = QDate::currentDate();
    ui->dateEdit->setDate(currdate);
    this->isNew=true;
    ui->saveAddbtn->setText(tr("&Add"));
    ui->saveAddbtn->setEnabled(false);
    this->setWindowTitle(tr("Add new task"));
//    ui->datepicker->setDisplayFormat("yyyy/MM/dd");

//    QDate date = QDate::currentDate();
//    ui->datepicker->setDate(date);


//    ui->savebtn->setEnabled(false);

    //this->newTask = true;
}

void AddTask::on_cancelbtn_clicked()
{
    this->close();
}


void AddTask::on_completionSlider_valueChanged(int value)
{
     ui->lblCompletion->setText("Completion "+QString::number(value)+"%");
}

