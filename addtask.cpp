#include "addtask.h"
#include "ui_addtask.h"
#include "task.h"

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
    this->setWindowTitle(tr("Add new task"));
}

void AddTask::on_cancelbtn_clicked()
{
    this->close();
}


void AddTask::on_completionSlider_valueChanged(int value)
{
     ui->lblCompletion->setText("Completion "+QString::number(value)+"%");
}

void AddTask::SetDataToUpdate(QString OldDueDate,QString OldTitle,int OldCompletion,QString OldDescription)
{
    this->isNew=false;
    ui->saveAddbtn->setText(tr("&Save"));
    this->setWindowTitle(tr("Update task"));
    QDate Olddate = QDate::fromString(OldDueDate,"yyyy/MM/dd");
    ui->dateEdit->setDate(Olddate);
    ui->titleEdit->setText(OldTitle);
    ui->completionSlider->setValue(OldCompletion);
    ui->plainTextEdit->setPlainText(OldDescription);
}



void AddTask::on_saveAddbtn_clicked()
{
    DueDate=ui->dateEdit->date().toString(ui->dateEdit->displayFormat());
    Title=ui->titleEdit->text();
    Completion=ui->completionSlider->value();
    Description=ui->plainTextEdit->toPlainText();

    Task *nTask=new Task(DueDate,Title,Completion,Description);
    this->origin->AddElement(*(nTask),(this->origin->treeTable));
    this->origin->GetTaskList()->append(*(nTask));
    this->close();
}
