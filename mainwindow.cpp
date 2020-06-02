#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gamegraph.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    connect(ui->pushButton,SIGNAL(clicked(bool)), this,SLOT(on_pushButton_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
//    game =new GameGraph(this) ;
    this->hide();
    game->show();

}

void MainWindow::on_pushButton_3_clicked()
{
    QMessageBox box;
    box.setText("本功能暂未开放，敬请期待！");
    box.exec();
}

void MainWindow::on_pushButton_2_clicked()
{
    QMessageBox box;
    box.setText("谢谢你玩我的游戏，再见！");
    box.exec();
    exit(-1);
}
