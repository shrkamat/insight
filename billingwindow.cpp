#include "billingwindow.h"
#include "serviceview.h"
#include "ui_billingwindow.h"

#include <QDebug>

BillingWindow::BillingWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BillingWindow)
{
    ui->setupUi(this);
    ServiceView *service = new ServiceView(ui->frame);
    connect(service, SIGNAL(itemSelected(Service)), this, SLOT(onServiceSelected(Service)));
}

BillingWindow::~BillingWindow()
{
    delete ui;
}

void BillingWindow::onServiceSelected(Service service)
{
    qDebug() << service.toString();
}
