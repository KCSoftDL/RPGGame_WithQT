#include "monster.h"


void monster::give(int h, int att, int de, int m)
{
    HP = h; ATK = att; DEF = de; money = m;
}

int monster::get_HP()
{
    return this->HP;
}

int monster::get_ATK()
{
    return this->ATK;
}

int monster::get_DEF()
{
    return this->get_DEF();
}

int monster::get_money()
{
    return this->get_money();
}

void monster::battle(person &you)
{
//    bool i;
    while (you.HP_now > 0 && HP >0)
    {
        if(you.DEF+you.have[2] < ATK)
            you.HP_now -= (ATK - you.DEF-you.have[2]);
        if(you.ATK +you.have[1] > DEF)
            HP -= (you.ATK +you.have[1]- DEF);
        else
        {
            QMessageBox box;
            box.setText("怪物防御力太高了，你打不动它，于是逃跑了！");
            box.exec();
            return ;
        }
        cout << "你的当前生命值为：" << you.HP_now << endl;
        cout << "怪物的当前生命值为：" << HP << endl;
//        cout << "是否继续？(输入1继续，输入0逃跑）" << endl;
//        cin >> i;
//        if (!i)
//            break;
    }
    if (you.HP_now <= 0)
    {
          you.gameover();
    }
    if (HP<=0)
    {
        cout << "恭喜你击败了怪物" << endl;
        cout << "你获得了金币，同时升级了" << endl;
        you.LVUP(1);
        you.show_stastus();
        you.getmoney(money);
    }
}

void monster::BOSS_battle(person& you)
{
//    bool i;
    int MAX=HP;
    while (you.HP_now != 0 && HP != 0)
    {
        you.HP_now -= (ATK - you.DEF - you.have[2]);
        HP -= (you.ATK + you.have[1] - DEF);
        if (HP * 2 <= MAX)
            ATK = ATK * 1.2;
        if (HP * 10 <= MAX)
            ATK = ATK * 1.25;
        cout << "你的当前生命值为：" << you.HP_now << endl;
        cout << "怪物的当前生命值为：" << HP << endl;
//        cout << "是否继续？(继续按1，逃跑按0）" << endl;
//        cin >> i;
//        if (!i)
//            break;
    }
    if (you.HP_now == 0)
    {
       you.gameover();
    }
    if (HP == 0)
    {
        you.LVUP(5);
        you.show_stastus();
        you.getmoney(money);
    }
}
