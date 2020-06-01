#include "gamegraph.h"
#include "ui_gamegraph.h"
#include "area_prairie.h"

GameGraph::GameGraph(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameGraph)
{
    ui->setupUi(this);
    person Player=person();
//    connect(ui->pushButton,SIGNAL(clicked(bool)), this,SLOT(on_pushButton_4_clicked()));
    area =new area_prairie(this,Player);
}

GameGraph::GameGraph(QWidget *parent,person player) :
    QWidget(parent),
    ui(new Ui::GameGraph)
{
    ui->setupUi(this);
    person Player=player;
//    connect(ui->pushButton,SIGNAL(clicked(bool)), this,SLOT(on_pushButton_4_clicked()));
    area =new area_prairie(this,Player);
}

GameGraph::~GameGraph()
{
    delete ui;
}

void GameGraph::on_pushButton_6_clicked()
{
    QMessageBox box;
    box.setText("本功能暂未开放，敬请期待！");
    box.exec();
}

void GameGraph::on_pushButton_2_clicked()
{
    QMessageBox box;
    box.setText("本功能暂未开放，敬请期待！");
    box.exec();
}

void GameGraph::on_pushButton_3_clicked()
{
    QMessageBox box;
    box.setText("本功能暂未开放，敬请期待！");
    box.exec();
}

void GameGraph::on_pushButton_4_clicked()
{
    QMessageBox box;
    box.setText("现版本城外区域仅开放草原区域，请见谅，祝您游戏愉快！");
    box.exec();
    area->show();
    this->hide();
}

void GameGraph::on_pushButton_5_clicked()
{
    QMessageBox box;
    box.setText("谢谢你玩我的游戏，再见！");
    box.exec();
    exit(-1);
}

void GameGraph::on_pushButton_clicked()
{
    Player.HP_now =Player.HP_Max;
    Player.money -= 100;
}
