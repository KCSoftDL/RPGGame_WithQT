#include "area_prairie.h"
#include "ui_area_prairie.h"

area_prairie::area_prairie(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::area_prairie)
{
    ui->setupUi(this);
//    player =Player;
//    areanum =1;
    Boar.give(200, 250, 100, 100);
    Slime.give(100, 50, 50, 50);
    wolf.give(100, 300, 100, 150);
    BOSS_Tauren.give(3000, 400, 400, 1500);
    status =new PlayerStatus(this);
    connect(ui->pushButton,SIGNAL(clicked(bool)), this,SLOT(on_pushButton_clicked()));
    connect(this,SIGNAL(clicked(bool)),status,SLOT(setvalue(QVariant)));
}

area_prairie::~area_prairie()
{
    delete ui;
}

void area_prairie::on_pushButton_clicked()
{
    QVariant variance;
    variance.setValue(player);
    emit send_data(variance);//发出信号
    this->hide();
    status->show();
}

void area_prairie::on_buttonBox_accepted()
{
    switch (player.hatred)
    {
    case 1:
        Slime.battle(player);
        areanum +=1;
        break;
    case 2:
        Boar.battle(player);
        areanum ++;
        break;
    case 3:
        wolf.battle(player);
        areanum ++;
        break;
    default:
        BOSS_Tauren.BOSS_battle(player);
        areanum =1;
        break;
    }

}

void area_prairie::on_buttonBox_rejected()
{

}

void area_prairie::setvalue(QVariant data)
{
    person player ;
    player = data.value<person>();
}
