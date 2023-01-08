#ifndef FACULTYMODEL_H
#define FACULTYMODEL_H

#include <QStandardItemModel>

class FacultyModel : public QStandardItemModel
{
public:
    FacultyModel(QObject *parent = nullptr);
};

#endif // FACULTYMODEL_H
