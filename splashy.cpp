#include <QDebug>
#include "splashy.h"

Splashy::Splashy(bool *dotmap, class Dot startDot, class Dot endDot, int mapSize)
    :mapSize(mapSize),startDot(startDot),endDot(endDot)
{
    this->dotMap = (bool *)malloc(mapSize*mapSize*sizeof(bool));
    memcpy(this->dotMap, dotmap, mapSize*mapSize*sizeof(bool));
    preDot = startDot;
    setMap(startDot);
    walkWay.append(startDot);
}

Splashy::Splashy(Splashy *father, class Dot nexDot)
{
    preDot      = father->curDot;
    startDot    = father->startDot;
    endDot      = father->endDot;
    mapSize     = father->mapSize;
    walkWay     = father->walkWay;    

    this->dotMap = (bool *)malloc(mapSize*mapSize*sizeof(bool));
    memcpy(dotMap, father->dotMap, mapSize*mapSize*sizeof(bool));
    setMap(nexDot);
    walkWay.append(curDot);
}
/*
 *  .   .   .   .
 *  .   .   .   .
 *  .   *   .   .
 *  .   *   .   .
 *  .   .   .   .
 *
 */
//遍历方向 ←↑→↓
void Splashy::getValidDot()
{
    validDot.clear();
    if(curDot == endDot)    return;

    if(!curDot.rightAt(preDot)){//get left
        getLineDot(endDot.leftAt(curDot)?   endDot:Dot(curDot.row, 0),   curDot);
    }
    if(!curDot.downAt(preDot)){//get up
        getLineDot(endDot.upAt(curDot)?     endDot:Dot(0, curDot.col),   curDot);
    }
    if(!curDot.leftAt(preDot)){//get right
        getLineDot(endDot.rightAt(curDot)?  endDot:Dot(curDot.row, mapSize-1),   curDot);
    }
    if(!curDot.upAt(preDot)){//get down
        getLineDot(endDot.downAt(curDot)?   endDot:Dot(mapSize-1, curDot.col),  curDot);
    }
}

void Splashy::getLineDot(class Dot a, class Dot b)
{
    if(a == b)  return;

    if(a.row == b.row && a.col < b.col){//同行 向左遍历
        for(int col = b.col - 1; col >= a.col; col--){
            if(mapType(dotMap)[a.row][col]){
                validDot.append(Dot(a.row, col));
                return;
            }
        }
    }
    if(a.row == b.row && a.col > b.col){//同行 向右遍历
        for(int col = b.col + 1; col <= a.col; col++){
            if(mapType(dotMap)[a.row][col]){
                validDot.append(Dot(a.row, col));
                return;
            }
        }
    }
    if(a.col == b.col && a.row < b.row){//同列 向上遍历
        for(int row = b.row - 1; row >= a.col; row--){
            if(mapType(dotMap)[row][a.col]){
                validDot.append(Dot(row, a.col));
                return;
            }
        }
    }
    if(a.col == b.col && a.row > b.row){//同列 向下遍历
        for(int row = b.row + 1; row <= a.row; row++){
            if(mapType(dotMap)[row][a.col]){
                validDot.append(Dot(row, a.col));
                return;
            }
        }
    }
}

bool Splashy::probe()
{
    getValidDot();
    //1.是否可继续
    //2.是否成功
    if(validDot.isEmpty()){
        qDebug() << "get Empty";
        this->show();
        if(curDot == endDot && mapIsAllFalse()){
            qDebug()<<"====================================";
            return true;
        }else
        {
            qDebug()<<"-----------------------------------";
            return false;
        }
    }

    foreach (class Dot oneDot, validDot) {
        Splashy son(this, oneDot);
        if(son.probe()){
            son.show();
            return true;
        }
    }
    return false;
}

void Splashy::show()
{
    foreach (Dot oneDot, walkWay) {
        qDebug() << QString("(%1,%2)").arg(oneDot.row).arg(oneDot.col);
    }
}

bool Splashy::mapIsAllFalse()
{
    for(int row = 0; row < mapSize; row++){
        for(int col = 0; col < mapSize; col++){
            if(mapType(dotMap)[row][col])
                return false;
        }
    }
    return true;
}
void Splashy::setMap(class Dot dot)
{
    //qDebug() << QString("(%1,%2)").arg(dot.row).arg(dot.col);
    mapType(dotMap)[dot.row][dot.col] = false;
    curDot = dot;
}

Splashy::~Splashy()
{
    free(dotMap);
    dotMap = NULL;
}
