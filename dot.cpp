#include "dot.h"

Dot::Dot()
{

}

Dot::Dot(int a, int b)
    :row(a),col(b)
{

}

bool Dot::operator==(const Dot a)const
{
    return ((this->row == a.row) && (this->col == a.col));
}

bool Dot::operator!=(const Dot a)const
{
    return ((this->row != a.row) || (this->col != a.col));
}

//↖为大
bool Dot::operator<(const Dot a)const
{
    if(a.upAt(*this)){
        return true;
    }
    if(a.row == row && a.col < col){
        return true;
    }
    return false;
}


bool Dot::leftAt(const Dot dot)const
{

    if(dot.row != this->row || dot.col <= this->col){
        return false;
    }
    return true;
}
bool Dot::rightAt(const Dot dot)const
{
    if(dot.row != this->row || dot.col >= this->col){
        return false;
    }
    return true;
}
bool Dot::upAt(const Dot dot)const
{
    if(dot.col != this->col || dot.row <= this->row){
        return false;
    }
    return true;
}
bool Dot::downAt(const Dot dot)const
{
    if(dot.col != this->col || dot.row >= this->row){
        return false;
    }
    return true;
}



