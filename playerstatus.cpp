#include "playerstatus.h"
#include "ui_playerstatus.h"

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


