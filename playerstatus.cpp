#include "playerstatus.h"
#include "ui_playerstatus.h"

Q_DECLARE_METATYPE(person)

PlayerStatus::PlayerStatus(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PlayerStatus)
{
    ui->setupUi(this);
}

PlayerStatus::~PlayerStatus()
{
    delete ui;
}

void PlayerStatus::setvalue(QVariant data)
{
    person player ;
    player = data.value<person>();
    ui->label_5->setNum(player.LV);
    ui->lineEdit_2->setText((QString)(player.HP_now));
//    ui->lineEdit->setText(player.LV);
//    ui->lineEdit_2->setText(player.HP_now);
    ui->lineEdit_3->setText((QString)(player.ATK+player.have[1]));
    ui->lineEdit_4->setText((QString)(player.DEF+player.have[2]));
}

