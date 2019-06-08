#include "db.h"
#include "employeesview.h"
#include "serviceview.h"
#include "billingwindow.h"
#include <QApplication>
#include <QDebug>

int main (int argc, char *argv[])
{
    qDebug() << "Hello, World";

    QApplication a(argc, argv);

    DB *db = new DB("test");

//    ServiceView e;
//    e.show();

    BillingWindow w;
    w.show();

    return a.exec();
}
