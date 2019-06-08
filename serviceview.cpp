#include "service.h"
#include "serviceview.h"
#include "servicemodel.h"
#include "ui_serviceview.h"

#include <QSqlTableModel>
#include <QSqlError>
#include <QtDebug>

ServiceView::ServiceView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ServiceView)
{
    ui->setupUi(this);
    ServiceModel *model = new ServiceModel(this);
    ui->tableView->setModel(model);
    ui->tableView->setAlternatingRowColors(true);
    ui->tableView->horizontalHeader()->setStretchLastSection(false);
    ui->tableView->setSortingEnabled(true);
    ui->tableView->setColumnHidden(0, true);
    ui->tableView->setColumnHidden(1, true);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->cbo->setModel(model->categoryQueryModel());
}

ServiceView::~ServiceView()
{
    delete ui;
}

void ServiceView::on_cbo_currentIndexChanged(const QString &category)
{
    QSqlTableModel *model = qobject_cast<QSqlTableModel *>(ui->tableView->model());

    if (model != nullptr) {
        model->setFilter("category='" + category + "'");
    }
}

void ServiceView::on_tableView_doubleClicked(const QModelIndex &index)
{
    if (index.isValid()) {
        int id = ui->tableView->model()->data(index.siblingAtColumn(0)).toInt();
        QString category = ui->tableView->model()->data(index.siblingAtColumn(1)).toString();
        QString name = ui->tableView->model()->data(index.siblingAtColumn(2)).toString();
        double cost = ui->tableView->model()->data(index.siblingAtColumn(3)).toDouble();
        Service service = Service(id, category, name, cost);
        emit itemSelected(service);
    }
}
