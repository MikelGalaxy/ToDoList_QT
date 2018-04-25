#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addtask.h"
#include "task.h"
#include <QDebug>

MainWindow::MainWindow()
{
    QWidget *hook = new QWidget();
    this->setCentralWidget(hook);

    QVBoxLayout *layout=new QVBoxLayout();
    this->SetMainLayout(layout);
    QHBoxLayout *filtersLayout = new QHBoxLayout;
    this->SetFilters(filtersLayout);
    layout->addLayout(filtersLayout);
    hook->setLayout(layout);

    btnAddTask = new QPushButton(tr("&Add Task"));
    connect(btnAddTask, SIGNAL (released()),this, SLOT (AddNewTask()));
    tasks = new QLinkedList<Task>();
//    QLinkedList<Task> *backUp;


    this->CreateMenuBar();
    treeTable = new QTreeWidget();
    this->SetTreeTable(treeTable);

    layout->addWidget(treeTable);
    layout->addWidget(btnAddTask);

    PopulateTable(treeTable);

    this->setWindowTitle("ToDo List QT");
    this->setMinimumSize(640, 480);
    this->resize(640, 480);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SetMainLayout(QVBoxLayout *layout)
{
    layout -> setContentsMargins(2,3,3,4);
//    layout -> setStretch(0, 0);
//    layout -> setStretch(1, 0);
//    layout -> setStretch(2, 1);


}

void MainWindow::SetFilters(QHBoxLayout *filtersLayout)
{
    rbtnAll = new QRadioButton;
    rbtnOverdue = new QRadioButton;
    rbtnToday = new QRadioButton;
    rbtnThisWeek = new QRadioButton;
    cboxCompleted = new QCheckBox;

    rbtnAll->setText(tr("&All"));
    rbtnAll->setChecked(true);
    rbtnOverdue->setText(tr("&Overdue"));
    rbtnToday->setText(tr("&Today"));
    rbtnThisWeek->setText(tr("&This Week"));
    cboxCompleted->setText(tr("&Not Completed"));

    connect(rbtnAll,SIGNAL(clicked()),this,SLOT(Filter()));
    connect(rbtnOverdue,SIGNAL(clicked()),this,SLOT(Filter()));
    connect(rbtnToday,SIGNAL(clicked()),this,SLOT(Filter()));
    connect(rbtnThisWeek,SIGNAL(clicked()),this,SLOT(Filter()));
    connect(cboxCompleted,SIGNAL(clicked()),this,SLOT(Filter()));

    filtersLayout->addWidget(rbtnAll);
    filtersLayout->addWidget(rbtnOverdue);
    filtersLayout->addWidget(rbtnToday);
    filtersLayout->addWidget(rbtnThisWeek);
    filtersLayout->addStretch(20);
    filtersLayout->addWidget(cboxCompleted);
}


void MainWindow::CreateMenuBar()
{

    loadFile = new QAction(tr("&Load from file"), this);
        connect(loadFile, &QAction::triggered, this, &MainWindow::LoadFromFile);

    saveFile = new QAction(tr("&Save"), this);
        connect(saveFile, &QAction::triggered, this, &MainWindow::Save);
    saveFile->setDisabled(true);
    saveToFile = new QAction(tr("&Save to file"), this);
        connect(saveToFile, &QAction::triggered, this, &MainWindow::SaveToFile);

    exitProgram = new QAction(tr("&Exit"), this);
    connect(exitProgram, &QAction::triggered, this, &MainWindow::Exit);


    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(loadFile);
    fileMenu->addAction(saveFile);
    fileMenu->addAction(saveToFile);
    fileMenu->addAction(exitProgram);
}

void MainWindow::AddNewTask()
{
    AddTask taskAdd;
    taskAdd.setModal(true);
   // taskAdd.setPath(path);
    taskAdd.setOrigin(this);
    taskAdd.exec();
}


QLinkedList<Task>* MainWindow::GetTaskList()
{
    return tasks;
}

void MainWindow::PopulateTable(QTreeWidget *treeTable)
{
    treeTable->clear();
    for(QLinkedList<Task>::iterator it=tasks->begin();it!=tasks->end();it++)
    {
        this->AddElement(it.i->t,treeTable);
    }
}


void MainWindow::SetTreeTable(QTreeWidget *treeTable)
{
    tasks->append(*(new Task("2018/03/21","What?!",0,"OKI DOKI")));
    tasks->append(*(new Task("2017/03/21","Ehh?!",0,"XXXX")));
    tasks->append(*(new Task("2017/03/21","EWWh?!",100,"XXXX")));
    tasks->append(*(new Task("2018/04/24","WEEE?!",25,"ZWASDSADS")));

    treeTable->setColumnCount(5);
    QStringList tableHeader;
    tableHeader << "Finished" << "DueDate" << "Title" << "% Complete" << "Description";
    treeTable->setHeaderLabels(tableHeader);
    treeTable->setColumnWidth(0,70);
    treeTable->setColumnWidth(2,140);

    connect(treeTable,SIGNAL(itemDoubleClicked(QTreeWidgetItem*,int)),
            this,SLOT(ItemSelected(QTreeWidgetItem*)));
}

void MainWindow::AddElement(Task task,QTreeWidget *treeTable)
{
    //maping and adding task
    QTreeWidgetItem *itm = new QTreeWidgetItem(treeTable);
    if(task.GetCompletion()!=100)
        itm->setText(0,"X");
    else
        itm->setText(0,"V");
    itm->setText(1,task.GetDueDate());
    itm->setText(2,task.GetTitle());
    itm->setText(3,QString::number(task.GetCompletion()));
    itm->setText(4,task.GetDescription());


}

void MainWindow::Filter()
{
    QTreeWidgetItemIterator it(treeTable);
    QString currdate = QDate::currentDate().toString("yyyy/MM/dd");
    QDate dateC=QDate::currentDate();
    if(cboxCompleted->isChecked())
    {
        if(rbtnAll->isChecked())
        {
            this->HideAllItems();
            while (*it) {
              if ((*it)->text(3)=="100")
               (*it)->setHidden(false);
              ++it;
            }
        }else if(rbtnOverdue->isChecked())
        {
            this->HideAllItems();
            while (*it) {
              QDate taskDate=QDate::fromString((*it)->text(1),"yyyy/MM/dd");
              if ((*it)->text(3)=="100" && taskDate<dateC)
               (*it)->setHidden(false);
              ++it;
            }

        }else if(rbtnToday->isChecked())
        {
            this->HideAllItems();
            while (*it) {
              if ((*it)->text(3)=="100" && (*it)->text(1)==currdate)
               (*it)->setHidden(false);
              ++it;
            }
        }else if(rbtnThisWeek->isChecked())
        {
            this->HideAllItems();
            while (*it) {
                QDate taskDate=QDate::fromString((*it)->text(1),"yyyy/MM/dd");
              if ((*it)->text(3)=="100" && taskDate.weekNumber()==dateC.weekNumber())
               (*it)->setHidden(false);
              ++it;
            }
        }
    }else{
        if(rbtnAll->isChecked())
        {
            while (*it) {
               (*it)->setHidden(false);
              ++it;
            }
        }else if(rbtnOverdue->isChecked())
        {
            this->HideAllItems();
            while (*it) {
              QDate taskDate=QDate::fromString((*it)->text(1),"yyyy/MM/dd");
              if (taskDate<dateC)
               (*it)->setHidden(false);
              ++it;
            }

        }else if(rbtnToday->isChecked())
        {
            this->HideAllItems();
            while (*it) {
              if ((*it)->text(1)==currdate)
               (*it)->setHidden(false);
              ++it;
            }
        }else if(rbtnThisWeek->isChecked())
        {
            this->HideAllItems();
            while (*it) {
                QDate taskDate=QDate::fromString((*it)->text(1),"yyyy/MM/dd");
              if (taskDate.weekNumber()==dateC.weekNumber())
               (*it)->setHidden(false);
              ++it;
            }
        }
    }
}
void MainWindow::HideAllItems()
{
    QTreeWidgetItemIterator it(treeTable);
    while (*it)
    {
        (*it)->setHidden(true);
         ++it;
    }
}


void MainWindow::Exit()
{
    exit(0);
}

void MainWindow::LoadFromFile()
{
    QFileDialog fileDailog(this);
    fileDailog.setFileMode(QFileDialog::ExistingFile);
    fileDailog.setNameFilter(tr("Text (*.txt)"));
    fileDailog.setViewMode(QFileDialog::List);


    QStringList fileNames;
    if (fileDailog.exec()){
        fileNames = fileDailog.selectedFiles();
        this->filePath = ((QString)fileNames.at(0)).toUtf8().constData();
        saveFile->setEnabled(true);
        ReadFromFile(filePath,tasks);
        PopulateTable(treeTable);
//        qInfo()<<filePath;
    }
}

void MainWindow::SaveToFile()
{
//    QFileDialog fileDailog(this);
//    fileDailog.setFileMode(QFileDialog::AnyFile);
//    fileDailog.setNameFilter(tr("Text (*.txt)"));
//    fileDailog.setViewMode(QFileDialog::List);
//    QStringList fileNames;
//    if (fileDailog.exec()){
//        fileNames = fileDailog.selectedFiles();
//        this->filePath = ((QString)fileNames.at(0)).toUtf8().constData();
//        saveFile->setEnabled(true);
//
//    }
    this->filePath = QFileDialog::getSaveFileName(this,
            tr("Save TaskList"), "",
            tr("TestFile (*.txt);"));
    WriteToFile(filePath,tasks);
    qInfo()<<filePath;
}

void MainWindow::Save()
{
    WriteToFile(filePath,tasks);
}



void MainWindow::ReadFromFile(QString path,QLinkedList<Task>* taskList)
{
    taskList->clear();
    QFile file(path);
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", file.errorString());
    }

    QTextStream in(&file);
    Task *t;
    while(!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(",");
        t=new Task(fields.at(0),fields.at(1),fields.at(2).toInt(),fields.at(3));
        taskList->append(*t);
    }
    file.close();
}

void MainWindow::WriteToFile(QString path,QLinkedList<Task>* taskList)
{
    QFile file(path);
    if(!file.open(QIODevice::ReadWrite)) {
        QMessageBox::information(0, "error", file.errorString());
    }

    QTextStream out(&file);
    QString task;
    for(QLinkedList<Task>::iterator it=taskList->begin();it!=taskList->end();it++)
    {
        task=it.i->t.StreamOut();
        out<<task<<endl;
    }
    file.close();
}

void MainWindow::ItemSelected(QTreeWidgetItem* item)
{

//    qInfo()<<item->text(1);
    AddTask taskEdit;
    taskEdit.setModal(true);
    taskEdit.SetDataToUpdate(item->text(1),item->text(2),(item->text(3)).toInt(),item->text(4));
    taskEdit.setOrigin(this);
    taskEdit.exec();
}
