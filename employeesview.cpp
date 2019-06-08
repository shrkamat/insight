#include "employeemodel.h"
#include "employeesview.h"
#include "ui_employeesview.h"

#include <QSqlQuery>

EmployeesView::EmployeesView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EmployeesView)
{
    ui->setupUi(this);
    ui->tableView->setModel(new EmployeeModel(this));
    ui->tableView->setAlternatingRowColors(true);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->setSortingEnabled(true);
    ui->tableView->setColumnHidden(0, true);
}

EmployeesView::~EmployeesView()
{
    delete ui;
}
