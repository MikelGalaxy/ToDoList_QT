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
    //connect(addTaskAct, &QAction::triggered, this, &MainWindow::addTask);



    this->CreateMenuBar();

    table = new QTableWidget(this);
    this->SetTable(table);

    layout->addWidget(table);
    layout->addWidget(btnAddTask);

    PopulateTable(table);

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

    saveFile = new QAction(tr("&Save"), this);
    saveFile->setDisabled(true);
    saveToFile = new QAction(tr("&Save to file"), this);



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
    //taskAdd.setOrigin(this);
    taskAdd.exec();
}

void MainWindow::SetTable(QTableWidget *table)
{
    table -> setColumnCount(5);
    QStringList tableHeader;
    tableHeader << "Finished" << "DueDate" << "Title" << "% Complete" << "Description";
    table -> setHorizontalHeaderLabels(tableHeader);
    table -> horizontalHeader()->setStretchLastSection(true);
    table->setColumnWidth(0,70);
    table->setColumnWidth(2,140);
    //table->setModel(Task);
//    table -> verticalHeader() -> setVisible(false);
//    table -> setEditTriggers(QAbstractItemView::NoEditTriggers);
//    table -> setSelectionBehavior(QAbstractItemView::SelectRows);
//    table -> setSelectionMode(QAbstractItemView::SingleSelection);
//    table -> setStyleSheet("QTableView {selection-background-color: #E0F7FA; selection-color: #000000;}");

    //inserting data
   // updateTable(IOManager::readFile(path));

//    connect( table, SIGNAL( cellDoubleClicked (int, int) ),
//     this, SLOT( cellSelected( int, int ) ) );
}

void MainWindow::PopulateTable(QTableWidget *table)
{
    tasks = new QLinkedList<Task>();
    tasks->append(*(new Task("2018/03/21","What?!",0,"OKI DOKI")));
    tasks->append(*(new Task("2017/03/21","Ehh?!",0,"XXXX")));

    for(int i=0;i<tasks->size();i++)
    {

        qInfo() << "C++ Style Info Message";
    }

}


void MainWindow::Exit()
{
    exit(0);
}
