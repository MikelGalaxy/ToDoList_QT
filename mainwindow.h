#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QRadioButton>
#include <QCheckBox>
#include <QPushButton>
#include <QTableWidget>
#include <QLinkedList>
#include <QAbstractTableModel>
#include <QTreeWidget>
#include <QDate>
#include "task.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow();
    ~MainWindow();
    QTreeWidget *treeTable;
    void AddElement(Task task,QTreeWidget *treeTable);
    QLinkedList<Task>* GetTaskList();
private:
    void SetMainLayout(QVBoxLayout *layout);
    void SetFilters(QHBoxLayout *filterslayout);
    void CreateMenuBar();
    void SetTable(QTableWidget *table);
    void SetTreeTable(QTreeWidget *treeTable);
    void Exit();
    void PopulateTable(QTreeWidget *tree);
    void HideAllItems();

    Ui::MainWindow *ui;
    QMenu *fileMenu;
    QAction *loadFile;
    QAction *saveFile;
    QAction *saveToFile;
    QAction *exitProgram;

    QVBoxLayout *layout;
    QRadioButton *rbtnAll;
    QRadioButton *rbtnOverdue;
    QRadioButton *rbtnToday;
    QRadioButton *rbtnThisWeek;
    QCheckBox *cboxCompleted;
    QPushButton *btnAddTask;

    QTableWidget *table;
    QLinkedList<Task> *tasks;



private slots:
     void AddNewTask();
     void Filter();

};

#endif // MAINWINDOW_H
