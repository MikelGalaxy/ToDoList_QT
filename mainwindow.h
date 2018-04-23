#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QRadioButton>
#include <QCheckBox>
#include <QPushButton>
#include <QTableWidget>
#include <QLinkedList>
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


private:
    void SetMainLayout(QVBoxLayout *layout);
    void SetFilters(QHBoxLayout *filterslayout);
    void CreateMenuBar();
    void SetTable(QTableWidget *table);
    void Exit();
    void PopulateTable(QTableWidget *table);

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

};

#endif // MAINWINDOW_H
