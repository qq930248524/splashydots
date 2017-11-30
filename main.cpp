#include <QCoreApplication>
#include <QDebug>

#include "splashy.h"
#include "dot.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    const int mapSize = 4;
    bool dotmap[mapSize][mapSize] = {
        true,  true,  true,  true,
        true,  false,  false,  false,
        true,  false,  false,  true,
        true,  true,  true,  true
    };
//    const int mapSize = 3;
//    bool dotmap[mapSize][mapSize] = {
//        true,  true,  true,
//        true,  false,  true,
//        true,  true,  true
//    };

    Dot startDot = {0,3};
    Dot endDot = {2,3};

    for(int i = 0; i < mapSize; i++){
        qDebug() << QString(" %1 %2 %3 %4")
                .arg(dotmap[i][0])
                .arg(dotmap[i][1])
                .arg(dotmap[i][2])
                .arg(dotmap[i][3]);
    }

    Splashy mainSplashy(&dotmap[0][0], startDot, endDot, mapSize);
    mainSplashy.probe();

    return a.exec();
}
