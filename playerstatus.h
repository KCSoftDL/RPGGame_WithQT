#ifndef PLAYERSTATUS_H
#define PLAYERSTATUS_H

#include <QDialog>

namespace Ui {
class PlayerStatus;
}

class PlayerStatus : public QDialog
{
    Q_OBJECT

public:
    explicit PlayerStatus(QWidget *parent = 0);
    ~PlayerStatus();

private:
    Ui::PlayerStatus *ui;
};

#endif // PLAYERSTATUS_H
