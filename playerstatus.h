#ifndef PLAYERSTATUS_H
#define PLAYERSTATUS_H

#include <QDialog>
#include"person.h"

namespace Ui {
class PlayerStatus;
}

class PlayerStatus : public QDialog
{
    Q_OBJECT

public:
    explicit PlayerStatus(QWidget *parent = 0);
    ~PlayerStatus();

public slots:
    void setvalue(QVariant data);

private slots:
    void on_pushButton_clicked();

private:
    Ui::PlayerStatus *ui;
};

#endif // PLAYERSTATUS_H
