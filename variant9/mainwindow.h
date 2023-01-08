#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QSplitter;
class QTreeView;
class QTableView;
class FacultyModel;

class MainWindow : public QMainWindow
{
Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private:
    FacultyModel *model;
    QSplitter *splitter;
    QTreeView *treeView;
    QTableView *tableView;
};

#endif // MAINWINDOW_H
