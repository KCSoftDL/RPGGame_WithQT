#ifndef MONSTER_H
#define MONSTER_H

#include"person.h"
#include <QMessageBox>

class monster
{
public:
    void give(int h, int att, int de, int m);
    void battle(person &you);
    void BOSS_battle(person& you);

    int get_HP();
    int get_ATK();
    int get_DEF();
    int get_money();

private:
    int HP;
    int ATK;
    int DEF;
    int money;
};

#endif // MONSTER_H
