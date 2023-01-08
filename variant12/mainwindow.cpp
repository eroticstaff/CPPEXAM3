#include "mainwindow.h"

#include <QComboBox>
#include <QCheckBox>
#include <QLineEdit>
#include <QPushButton>
#include <QTableWidget>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent)
{
    QWidget *central = new QWidget(this);
    // Create the layout for the main window
    QVBoxLayout *layout = new QVBoxLayout(this);

    // Create the table
    QTableWidget *table = new QTableWidget(this);
    table->setColumnCount(4);
    table->setHorizontalHeaderLabels({"Staff", "Tasks", "Status", "Notes"});

    // Create the "Add row" button and connect its clicked signal to a slot
    QPushButton *addRowButton = new QPushButton("Add row");
    QObject::connect(addRowButton, &QPushButton::clicked, [this, table] {
        // Add a new row to the table
        int row = table->rowCount();
        table->insertRow(row);

        // Create a combo box for the staff column and populate it with the list of staff
        QComboBox *staffComboBox = new QComboBox();
        staffComboBox->addItems({"John", "Jane", "Mike", "Samantha"});

        // Create a combo box for the tasks column and populate it with the list of tasks
        QComboBox *tasksComboBox = new QComboBox();
        tasksComboBox->addItems({"Task 1", "Task 2", "Task 3", "Task 4"});

        // Create a check box for the status column
        QCheckBox *statusCheckBox = new QCheckBox();

        // Create a line edit for the notes column
        QLineEdit *notesLineEdit = new QLineEdit();

        // Add the widgets to the table
        table->setCellWidget(row, 0, staffComboBox);
        table->setCellWidget(row, 1, tasksComboBox);
        table->setCellWidget(row, 2, statusCheckBox);
        table->setCellWidget(row, 3, notesLineEdit);
    });

    // Create the "Show solved tasks" button and connect its clicked signal to a slot
    QPushButton *showSolvedTasksButton = new QPushButton("Show solved tasks");
    QObject::connect(showSolvedTasksButton, &QPushButton::clicked, [this, table] {
        // Create a new widget to hold the solved tasks table
        QWidget *solvedTasksWidget = new QWidget();

        // Create the solved tasks table
        QTableWidget *solvedTasksTable = new QTableWidget(solvedTasksWidget);
        solvedTasksTable->setColumnCount(3);
        solvedTasksTable->setHorizontalHeaderLabels({"Staff", "Tasks", "Notes"});

        // Iterate over the rows of the main table and add the solved tasks to the solved tasks table
        for (int row = 0; row < table->rowCount(); ++row) {
            QCheckBox *statusCheckBox = qobject_cast<QCheckBox*>(table->cellWidget(row, 2));
            if (statusCheckBox->isChecked()) {
                // Get the staff, tasks, and notes for the current row
                QComboBox *staffComboBox = qobject_cast<QComboBox*>(table->cellWidget(row, 0));
                QComboBox *tasksComboBox = qobject_cast<QComboBox*>(table->cellWidget(row, 1));
                QLineEdit *notesLineEdit = qobject_cast<QLineEdit*>(table->cellWidget(row, 3));
                QString staff = staffComboBox->currentText();
                QString tasks = tasksComboBox->currentText();
                QString notes = notesLineEdit->text();

                // Add a new row to the solved tasks table
                int solvedTasksRow = solvedTasksTable->rowCount();
                solvedTasksTable->insertRow(solvedTasksRow);

                // Add the staff, tasks, and notes to the solved tasks table
                solvedTasksTable->setItem(solvedTasksRow, 0, new QTableWidgetItem(staff));
                solvedTasksTable->setItem(solvedTasksRow, 1, new QTableWidgetItem(tasks));
                solvedTasksTable->setItem(solvedTasksRow, 2, new QTableWidgetItem(notes));
            }
        }

        // Show the solved tasks widget
        solvedTasksWidget->show();
    });

    // Add the buttons and the table to the layout
    layout->addWidget(addRowButton);
    layout->addWidget(showSolvedTasksButton);
    layout->addWidget(table);
    central->setLayout(layout);
    setCentralWidget(central);
}

MainWindow::~MainWindow()
{
}
