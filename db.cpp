#include "db.h"
#include "servicemodel.h"

DB::DB(const QString &name):
    m_name(name)
{
    this->init();
}

bool DB::exec(QString query)
{
    QSqlQuery sqlite(*db);
    bool ok = sqlite.exec(query);

    if (!ok) {
        qDebug() << "Failed " << db->lastError().text() << ": " << query;
    }
    return ok;
}

void DB::init()
{
    QDir dbPath;
    QString name = dbPath.currentPath() + "/" + m_name + ".db";

    db = new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE"));
    db->setDatabaseName(name);

    bool ok = db->open();
    if (!ok) {
        qDebug() << "Failed to open DB @ " << name;
    }

    this->exec("CREATE TABLE IF NOT EXISTS employees(id INTEGER PRIMARY KEY AUTOINCREMENT, fName STRING, lName STRING, mob STRING, alt STRING, addr STRING);");

    this->exec(ServiceModel::dbCreate());
    // this->exec("INSERT INTO employees(fName, lName, mob, alt, addr) VALUES('Sandhya', 'Kamath', '9620154702', '08251-230380', 'Bangalore 560076');");
    // this->exec("INSERT INTO service(category, name, cost) VALUES('Facial', 'Gold', 90);");
    // this->exec("INSERT INTO service(category, name, cost) VALUES('Waxing', 'Bikini', 400);");
}
