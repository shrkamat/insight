#include "service.h"

Service::Service(int id, const QString &category, const QString &name, double cost)
    :m_id(id), m_category(category), m_name(name), m_cost(cost)
{
}

QString Service::toString() const
{
    return QString("id:%1 %2 %3").arg(QString::number(m_id), m_name, QString::number(m_cost));
}
