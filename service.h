#ifndef SERVICE_H
#define SERVICE_H

#include <QString>

class Service
{
public:
    Service(int id, const QString& category, const QString& name, double cost);
    QString toString() const;

private:
    // CREATE TABLE IF NOT EXISTS service(id INTEGER PRIMARY KEY AUTOINCREMENT, category STRING, name STRING, cost DOUBLE);
    int m_id;
    QString m_category;
    QString m_name;
    double m_cost;
};

#endif // SERVICE_H
