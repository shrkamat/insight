#ifndef SERVICEVIEW_H
#define SERVICEVIEW_H

#include "service.h"
#include <QWidget>

namespace Ui {
class ServiceView;
}

class ServiceView : public QWidget
{
    Q_OBJECT

public:
    explicit ServiceView(QWidget *parent = nullptr);
    ~ServiceView();

Q_SIGNALS:
    void itemSelected(Service service);

private slots:
    void on_cbo_currentIndexChanged(const QString &arg1);
    void on_tableView_doubleClicked(const QModelIndex &index);

private:
    Ui::ServiceView *ui;
};

#endif // SERVICEVIEW_H
