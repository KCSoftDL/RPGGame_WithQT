#ifndef PERSON_H
#define PERSON_H

#include <QMessageBox>
#include<string>
#include<iostream>
using namespace std;

class person
{
public:
    person();
    void gameover();
    void LVUP(int up);
    void show_stastus();
    void getmoney(int number);

    int LV;
    int HP_Max;
    int HP_now;
    int ATK ;	//攻击力
    int DEF ;	//防御力
    int money ;
    int have[10];
    int course[3];
    int hatred;
    string weapon;
    string armors;
};

#endif // PERSON_H
