#include "servicemodel.h"

ServiceModel::ServiceModel(QObject *parent)
//    QSqlTableModel (parent)
{
    this->setTable("service");

    this->setHeaderData(1, Qt::Horizontal, "Category");
    this->setHeaderData(2, Qt::Horizontal, "Service");
    this->setHeaderData(3, Qt::Horizontal, "Cost");
}

QString ServiceModel::dbCreate()
{
    const QString str = "CREATE TABLE IF NOT EXISTS service(id INTEGER PRIMARY KEY AUTOINCREMENT, category STRING, name STRING, cost DOUBLE);";
    return str;
}

QSqlQueryModel * ServiceModel::categoryQueryModel()
{
    QSqlQueryModel *model = new QSqlQueryModel(this);
    model->setQuery("SELECT DISTINCT category FROM service ORDER BY category;");
    return model;
}
