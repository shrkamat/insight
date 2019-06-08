#ifndef SERVICEMODEL_H
#define SERVICEMODEL_H

#include <QObject>
#include <QSqlTableModel>

class ServiceModel : public QSqlTableModel
{
    Q_OBJECT

public:
    explicit ServiceModel(QObject *parent=nullptr);
    static QString dbCreate();
    QSqlQueryModel *categoryQueryModel();
};

#endif // SERVICEMODEL_H
