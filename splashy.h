#ifndef SPLASHY_H
#define SPLASHY_H

#include <QVector>
#include "dot.h"

class Splashy
{
public:
    Splashy(bool *dotmap, class Dot startDot, class Dot endDot, int mapSize = 0);
    Splashy(class Splashy *father, class Dot nextDot);
    ~Splashy();

#define mapType(map) ((bool (*)[mapSize])(map))

    bool *dotMap = NULL;
    bool probe();
    void show();
    bool mapIsAllFalse();
    void setMap(class Dot aaa);
    void getValidDot();
    void getLineDot(class Dot a, class Dot b);

    int mapSize;
    class Dot preDot;
    class Dot curDot;
    class Dot startDot;
    class Dot endDot;
    QVector <class Dot> validDot;
    QVector <class Dot> walkWay;
};

#endif // SPLASHY_H
