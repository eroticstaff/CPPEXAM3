#include "mainwindow.h"
#include "facultymodel.h"

#include <QSplitter>
#include <QTreeView>
#include <QTableView>
#include <QItemSelectionModel>
#include <QHeaderView>

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent)
{
    // Create the data model
    model = new FacultyModel(this);

    // Create the tree view and table view
    treeView = new QTreeView(this);
    tableView = new QTableView(this);
    treeView->setModel(model);
    tableView->setModel(model);

    // Set the tree view to show only the top level items
    treeView->setRootIsDecorated(true);
    treeView->setItemsExpandable(true);

    // Set the table view to show only the students
    tableView->setRootIndex(QModelIndex());

    // Use a splitter to show the tree view and table view side by side
    splitter = new QSplitter(this);
    splitter->addWidget(treeView);
    splitter->addWidget(tableView);
    splitter->setSizes(QList<int>() << 200 << 400);

    setCentralWidget(splitter);

    // Connect the selection model of the tree view to the table view
    QItemSelectionModel *selectionModel = treeView->selectionModel();
    tableView->setSelectionModel(selectionModel);

    // Set the table view to show only the students under the selected group
    connect(selectionModel, &QItemSelectionModel::currentChanged, [this](const QModelIndex &current, const QModelIndex &previous) {
        Q_UNUSED(previous);
        if (current.parent().isValid()) {
            tableView->setRootIndex(current);
            tableView->setColumnHidden(1, false);
        } else {
            tableView->setRootIndex(QModelIndex());
            tableView->setColumnHidden(1, true);
        }
    });
}
