#ifndef AREA_PRAIRIE_H
#define AREA_PRAIRIE_H

#include <QDialog>
#include "monster.h"
#include "playerstatus.h"

namespace Ui {
class area_prairie;
}

class area_prairie : public QDialog
{
    Q_OBJECT

public:
    explicit area_prairie(QWidget *parent = 0,person Player);
    ~area_prairie();

private slots:
    void on_pushButton_clicked();

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::area_prairie *ui;
    monster Boar;
    monster Slime;
    monster wolf;
    monster BOSS_Tauren;
    person player;
    PlayerStatus *status;
    int areanum;
};

#endif // AREA_PRAIRIE_H
