#ifndef EMPLOYEESVIEW_H
#define EMPLOYEESVIEW_H

#include <QWidget>

namespace Ui {
class EmployeesView;
}

class EmployeesView : public QWidget
{
    Q_OBJECT

public:
    explicit EmployeesView(QWidget *parent = nullptr);
    ~EmployeesView();

private:
    Ui::EmployeesView *ui;
};

#endif // EMPLOYEESVIEW_H
