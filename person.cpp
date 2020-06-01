#include "person.h"

person::person()
{
    this->LV =1;
    this->HP_Max = 2000;
    this->HP_now = 2000;
    this->ATK = 200;	//攻击力
    this->DEF = 200;	//防御力
    this->money = 1000;
    for(int i=0;i<10;i++)
        this->have[i]=0;
}

void person::LVUP(int up)
{
    this->LV += up; this->ATK += 10*up; this->DEF += 10*up; this->HP_Max += 100*up; this->HP_now += 100*up;
}

void person::show_stastus()
{
    cout << "你当前等级为"<<this->LV << endl;
    cout << "你当前攻击力为" << this->ATK+this->have[1] << endl;
    cout << "你当前防御力为" << this->DEF+this->have[2] << endl;
    cout << "你的当前生命值为：" << this->HP_now << endl;
    cout << "你当前生命上限为" << this->HP_Max << endl;
    cout << "你当前金币为" << this->money << endl;
}

void person::getmoney(int number)
{
    this->money +=number;
}

void person::gameover()
{
//     QMessageBox::information(this,"failed","胜败乃兵家常事，大侠请重新来过");
    QMessageBox box;
    box.setText("胜败乃兵家常事，大侠请重新来过");
    box.exec();
}
