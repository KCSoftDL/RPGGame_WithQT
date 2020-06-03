#include "gamegraph.h"
#include "ui_gamegraph.h"
#include "area_prairie.h"

Q_DECLARE_METATYPE(person)

GameGraph::GameGraph(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameGraph)
{
    ui->setupUi(this);
    person Player=person();
//    connect(ui->pushButton,SIGNAL(clicked(bool)), this,SLOT(on_pushButton_4_clicked()));
    area =new area_prairie(this);
    connect(this, SIGNAL(send_data(QVariant)), area, SLOT(setvalue(QVariant))); // send the message of player to area_prairie
    connect(area, SIGNAL(send_data(QVariant)),this,SLOT(setvalue(QVariant)) );  //receive the message of player from area_prairie
}

/*
GameGraph::GameGraph(QWidget *parent,person player) :
    QWidget(parent),
    ui(new Ui::GameGraph)
{
    ui->setupUi(this);
    person Player=player;
//    connect(ui->pushButton,SIGNAL(clicked(bool)), this,SLOT(on_pushButton_4_clicked()));
    area =new area_prairie(this,Player);
}
*/

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
//    QMessageBox box;
//    box.setText("该功能暂未实现可视化，请在控制台交互，谢谢");
//    box.exec();
//    weapon_shop(Player);
    QMessageBox box;
    box.setText("目前武器店暂无新武器，但可花费金币强化武器，每次花费200，攻击力增加100");
    box.exec();
    if(Player.money >=200)
    {
        Player.money -= 200;
        Player.have[1] += 100;
    }
}

void GameGraph::on_pushButton_3_clicked()
{
//    QMessageBox box;
//    box.setText("该功能暂未实现可视化，请在控制台交互，谢谢");
//    box.exec();
//    armors_shop(Player);
    QMessageBox box;
    box.setText("目前防具店暂无新武器，但可花费金币强化防具，每次花费100，防御力增加50");
    box.exec();
    if(Player.money >=100)
    {
        Player.money -= 200;
        Player.have[2] += 50;
    }
}

void GameGraph::on_pushButton_4_clicked()
{

    QVariant variance;
//    Player.ATK =(ui->lineEdit_2->text()).toInt();
//    Player.HP_Max =(ui->lineEdit_2->text()).toInt();
//    Player.HP_now =(ui->lineEdit_2->text()).toInt();
//    Player.DEF =(ui->lineEdit_2->text()).toInt();
//    Player.LV =(ui->lineEdit_2->text()).toInt();
//    Player.hatred =(ui->lineEdit_2->text()).toInt();
    variance.setValue(Player);
    emit send_data(variance);//发出信号

    QMessageBox box;
    box.setText("现版本城外区域仅开放草原区域，请见谅，祝您游戏愉快！");
    box.exec();
    area->show();
//    this->hide();
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
    if(Player.money >= 100 | Player.have[0] == 1)
        Player.HP_now =Player.HP_Max;
    if( Player.have[0] == 0)
    {
        Player.money -= 100;
    }
}

void GameGraph::setvalue(QVariant data)
{
    Player = data.value<person>();
}

void GameGraph::weapon_shop(person you)
{
    int a;
        cout << "NPC:有什么需要的吗？" << endl;
        cout << "1.购买武器" << endl;
        cout << "2.修理武器" << endl;
        cout << "3.返回小镇" << endl;
        cin >> a;
        switch(a)
        {
            case 1:buy_weapon(you); break;
            case 2:	cout<<"本功能暂未开放，敬请期待！"<<endl; break;
            case 3:break;
            default:cout << "请正确选择" << endl; break;
        }
}

void GameGraph::armors_shop(person you)
{
    int a;
    cout << "NPC:有什么需要的吗？" << endl;
    cout << "1.购买防具套装" << endl;
    //cout << "2.修理护甲" << endl;
    cout << "3.返回小镇" << endl;
    cin >> a;
    switch (a)
    {
    case 1:buy_armors(you); break;
    case 2:	cout<<"本功能暂未开放，敬请期待！"<<endl; break;
    case 3:break;
    default:cout << "请正确选择" << endl; break;
    }
}

void GameGraph::buy_weapon(person you)
{
    int choose;
    cout << "1.桃木剑------------200金币" << endl;
    cout << "2.铁制长剑---------1000金币" << endl;
    cout <<"3.青釭剑------------3000金币"<< endl;
    cout <<"4.龙泉剑------------5000金币" << endl;
    cout <<"请选择你要购买的武器"<< endl;
    cin >> choose;
    switch (choose)
    {
    case 1:if (you.money >= 200)
    {
        cout << "你的装备替换成了桃木剑，破烂的原装备被店长收去，同时给了你50的金币作为收购费";
        you.money -= 150;
        you.have[1] = 100;
    }
           else
           {
               cout << "你的金币不够，请重新选择" << endl;
               buy_armors(you);
           }
           break;
    case 2:if (you.money >= 1000)
    {
        cout << "你的装备替换成了铁制长剑，破烂的原装备被店长收去，同时给了你100的金币作为收购费";
            you.money -= 900;
        you.have[1] = 300;
    }
           else
           {
               cout << "你的金币不够，请重新选择" << endl;
               buy_armors(you);
           }
           break;
    case 3:if (you.money >= 3000)
    {
        cout << "你的装备替换成了青釭剑，破烂的原装备被店长收去，同时给了你500的金币作为收购费";
        you.money -= 2500;
        you.have[1] = 1000;
    }
           else
           {
               cout << "你的金币不够，请重新选择" << endl;
               buy_armors(you);
           }
           break;
    case 4:if (you.money >= 5000)
    {
        cout << "你的装备替换成了龙泉剑，破烂的原装备被店长收去，同时给了你2000的金币作为收购费";
        you.money -= 3000;
        you.have[1] = 1500;
    }
           else
           {
               cout << "你的金币不够，请重新选择" << endl;
               buy_armors(you);
           }
           break;
    default:
        break;
    }

}

void GameGraph::buy_armors(person you)
{
    int choose;
    cout << "1.布衣------------100金币" << endl;
    cout << "2.精致皮衣---------1500金币" << endl;
    cout << "3.锁子甲------------40000金币" << endl;
    cout << "4.合金铠------------7500金币" << endl;
    cout << "请选择你要购买的武器" << endl;
    cin >> choose;
    switch (choose)
    {
    case 1:if (you.money >= 100)
    {
        cout << "你的防具替换成了布衣，破烂的原防具被店长收去" << endl;
        you.money -= 100;
        you.have[1] = 50;
    }
           else
           {
               cout << "你的金币不够，请重新选择" << endl;
               buy_armors(you);
           }
           break;
    case 2:if (you.money >= 1500)
    {
        cout << "你的防具替换成了精致皮衣，破烂的原防具被店长收去，同时给了你50的金币作为收购费" << endl;
        you.money -= 1450;
        you.have[1] = 300;
    }
           else
           {
               cout << "你的金币不够，请重新选择" << endl;
               buy_armors(you);
           }
           break;
    case 3:if (you.money >= 4000)
    {
        cout << "你的防具替换成了锁子甲，破烂的原防具被店长收去，同时给了你700的金币作为收购费" << endl;
        you.money -= 3700;
        you.have[1] = 1000;
    }
           else
           {
               cout << "你的金币不够，请重新选择" << endl;
               buy_armors(you);
           }
           break;
    case 4:if (you.money >= 7500)
    {
        cout << "你的防具替换成了合金铠，破烂的原防具被店长收去，同时给了你1500的金币作为收购费" << endl;
        you.money -= 6000;
        you.have[1] = 1500;
    }
           else
           {
               cout << "你的金币不够，请重新选择" << endl;
               buy_armors(you);
           }
           break;
    default:
        break;
    }
}
