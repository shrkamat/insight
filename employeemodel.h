#ifndef EMPLOYEEMODEL_H
#define EMPLOYEEMODEL_H

#include <QObject>
#include <QSqlTableModel>

class EmployeeModel : public QSqlTableModel
{
    Q_OBJECT

public:
    explicit EmployeeModel(QObject *parent=nullptr);
};

#endif // EMPLOYEEMODEL_H
