#include "facultymodel.h"

FacultyModel::FacultyModel(QObject *parent)
        : QStandardItemModel(parent)
{
    // Add the faculty items
    QStandardItem *faculty1 = new QStandardItem("Faculty 1");
    appendRow(faculty1);
    QStandardItem *faculty2 = new QStandardItem("Faculty 2");
    appendRow(faculty2);

    // Add the group items under each faculty
    QStandardItem *group1 = new QStandardItem("Group 1");
    faculty1->appendRow(group1);
    QStandardItem *group2 = new QStandardItem("Group 2");
    faculty1->appendRow(group2);
    QStandardItem *group3 = new QStandardItem("Group 3");
    faculty2->appendRow(group3);
    QStandardItem *group4 = new QStandardItem("Group 4");
    faculty2->appendRow(group4);

    // Add the student items under each group
    QList<QStandardItem *> students;
    students << new QStandardItem("John") << new QStandardItem("Doe");
    group1->appendRow(students);
    students.clear();
    students << new QStandardItem("Jane") << new QStandardItem("Doe");
    group1->appendRow(students);
    students.clear();
    students << new QStandardItem("Bob") << new QStandardItem("Smith");
    group2->appendRow(students);
    students.clear();
    students << new QStandardItem("Alice") << new QStandardItem("Smith");
    group3->appendRow(students);
    students.clear();
    students << new QStandardItem("Eve") << new QStandardItem("Jackson");
    group4->appendRow(students);
}
