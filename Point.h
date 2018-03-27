//
//  Point.h
//  Project
//
//  Created by 叶胥达 on 2018/3/26.
//  Copyright © 2018年 叶胥达. All rights reserved.
//

#ifndef Point_h
#define Point_h

#include <cmath>

//struct Point
struct Point{
    double x,y;
    Point(double _x=0,double _y=0){
        x=_x;
        y=_y;
    }
};

Point operator+(const Point &P1,const Point &P2){
    return Point(P1.x+P2.x,P1.y+P2.y);
}

Point operator-(const Point &P1,const Point &P2){
    return Point(P1.x-P2.x,P1.y-P2.y);
}

std::ostream & operator<<(std::ostream &os,const Point &P){
    os << "(" << P.x << "," << P.y << ")";return os;
}

double operator^(const Point &P1,const Point &P2){
    return P1.x*P2.y-P2.x*P1.y;
}

double triangle(const Point &P1,const Point &P2,const Point &P3){
    return ((P2-P1)^(P3-P1))/2;
}

double polygon(const Point *P,int n){
    double S=0;
    for(int i=1;i<n-1;i++){
        S+=triangle(P[0],P[i],P[i+1]);
    }
    return S;
}

bool compare_x(const Point &P1,const Point &P2){
    if(P1.x==P2.x)return P1.y<P2.y;
    else return P1.x<P2.x;
};

bool compare_arg(const Point &P1,const Point &P2){
    return atan2(P1.y,P1.x)<atan2(P2.y,P2.x);
}

#endif /* Point_h */
