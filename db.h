#ifndef DB_H
#define DB_H

#include <QString>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDir>
#include <QDebug>

class DB
{
public:
    DB(const QString& name);
    bool exec(QString query);

private:
    QString m_name;
    QSqlDatabase *db;

    void init();
};

#endif // DB_H
