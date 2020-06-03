#include "area_prairie.h"
#include "ui_area_prairie.h"

Q_DECLARE_METATYPE(person)

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
    player.show_stastus();
    cout<<"hatred:"<<player.hatred<<endl;
    emit send_data(variance);//发出信号
//    player =variance.value<person>;
//    player.show_stastus();
//    this->hide();
    status->show();
}

void area_prairie::on_buttonBox_accepted()
{
    switch (player.hatred)
    {
    case 0:
        cout<<"you meet a Slime!"<<endl;
        Slime.battle(player);
        player.hatred +=1;
        break;
    case 1:
        cout<<"you meet a Slime!"<<endl;
        Slime.battle(player);
        player.hatred +=1;
        break;
    case 2:
        cout<<"you meet a Boar!"<<endl;
        Boar.battle(player);
        player.hatred ++;
        break;
    case 3:
        cout<<"you meet a wolf!"<<endl;
        wolf.battle(player);
        player.hatred ++;
        break;
    default:
        cout<<"you meet the BOSS_Tauren!"<<endl;
        BOSS_Tauren.BOSS_battle(player);
        player.hatred =1;
        break;
    }
    this->show();
}

void area_prairie::on_buttonBox_rejected()
{

    QVariant variance;
    variance.setValue(player);
    emit send_data(variance);//发出信号
}

void area_prairie::setvalue(QVariant data)
{
    person player ;
    player = data.value<person>();
}

void area_prairie::on_pushButton_2_clicked()
{
    switch (player.hatred)
    {
    case 0:
        Slime.give(100, 50, 50, 50);
        cout<<"you meet a Slime!"<<endl;
        Slime.battle(player);
        break;
    case 1:
        Slime.give(100, 50, 50, 50);
        cout<<"you meet a Slime!"<<endl;
        Slime.battle(player);
        player.hatred +=1;
        break;
    case 2:
        wolf.give(100, 300, 100, 150);
        cout<<"you meet a Boar!"<<endl;
        Boar.battle(player);
        break;
    case 3:
        cout<<"you meet a wolf!"<<endl;
        wolf.battle(player);
        break;
    default:
        BOSS_Tauren.give(3000, 400, 400, 1500);
        cout<<"you meet the BOSS_Tauren!"<<endl;
        BOSS_Tauren.BOSS_battle(player);
        break;
    }

}
