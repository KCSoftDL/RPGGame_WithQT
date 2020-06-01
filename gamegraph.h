#ifndef GAMEGRAPH_H
#define GAMEGRAPH_H

#include <QWidget>
#include <QMessageBox>
#include "person.h"
#include "area_prairie.h"

namespace Ui {
class GameGraph;
}

class GameGraph : public QWidget
{
    Q_OBJECT

public:
    explicit GameGraph(QWidget *parent = 0);
    GameGraph(QWidget *parent,person Player);
    ~GameGraph();

private slots:
    void on_pushButton_6_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_clicked();

private:
    Ui::GameGraph *ui;
    person Player;
    area_prairie *area;

};

#endif // GAMEGRAPH_H
