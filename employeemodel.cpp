#include "employeemodel.h"

EmployeeModel::EmployeeModel(QObject *parent)
{
    this->setTable("employees");

    this->setHeaderData(1, Qt::Horizontal, "First Name");
    this->setHeaderData(2, Qt::Horizontal, "Last Name");
    this->setHeaderData(3, Qt::Horizontal, "Contact - Mob");
    this->setHeaderData(4, Qt::Horizontal, "Contact - Alt");
    this->setHeaderData(5, Qt::Horizontal, "Address");

    this->select();
}
