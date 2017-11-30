#ifndef DOT_H
#define DOT_H


class Dot
{
public:
    Dot();
    Dot(int , int);
    int row;
    int col;
    bool operator==(const Dot)const;
    bool operator!=(const Dot)const;
    bool operator<(const Dot)const;

    bool leftAt(const Dot)const;
    bool rightAt(const Dot)const;
    bool upAt(const Dot)const;
    bool downAt(const Dot)const;
};

#endif // DOT_H
