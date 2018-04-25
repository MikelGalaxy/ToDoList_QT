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
#include <QFileDialog>
#include <QMessageBox>
#include <fstream>
#include <iostream>
#include <sstream>
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
    void PopulateTable(QTreeWidget *tree);

private:
    void SetMainLayout(QVBoxLayout *layout);
    void SetFilters(QHBoxLayout *filterslayout);
    void CreateMenuBar();
    void SetTable(QTableWidget *table);
    void SetTreeTable(QTreeWidget *treeTable);
    void ReadFromFile(QString path,QLinkedList<Task>* taskList);
    void WriteToFile(QString path,QLinkedList<Task>* taskList);

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

    QLinkedList<Task> *tasks;

    QString filePath;

private slots:
     void AddNewTask();
     void Filter();
     void ItemSelected(QTreeWidgetItem*);
     void Exit();
     void LoadFromFile();
     void SaveToFile();
     void Save();

};

#endif // MAINWINDOW_H
