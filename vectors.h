#ifndef VECTORS_H
#define VECTORS_H

#endif // VECTORS_H

#include "mainwindow.h"


class vecrtor3d
{
public :
    double x;
    double y;
    double z;

    vecrtor3d(void)
    {
        x=0;
        y=0;
        z=0;
    }
    vecrtor3d(double x,double y,double z):x(x),y(y),z(z){}

    friend vecrtor3d operator+(vecrtor3d v1,vecrtor3d v2);
    friend vecrtor3d operator+(vecrtor3d v1,double v2);
    friend vecrtor3d operator-(vecrtor3d v1,vecrtor3d v2);
    vecrtor3d operator-(double v1);
    vecrtor3d operator*(vecrtor3d v1);
    vecrtor3d operator*(double v1);

    vecrtor3d scalar(vecrtor3d v1);


};
