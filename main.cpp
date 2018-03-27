//
//  main.cpp
//  Project
//
//  Created by 叶胥达 on 2018/3/26.
//  Copyright © 2018年 叶胥达. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include "Point.h"

using namespace std;

int main(){
    int n;
    cout << "输入点的数目：";
    cin >> n;
    Point Vertex[n];
    cout << "输入" << n << "个点的坐标：\n";
    for(int i=0;i<n;i++){
        cout << i+1 << ". ";
        cin >> Vertex[i].x >> Vertex[i].y;
    }
    
    ///1. Find point with min x-coordinate
    for(int i=n-1;i!=-1;i--){
        if(compare_x(Vertex[i+1],Vertex[i]))
            swap(Vertex[i+1],Vertex[i]);
    }
    
    ///2. Move point to (0,0)
    for(int i=1;i<n;i++)Vertex[i]=Vertex[i]-Vertex[0];
    Vertex[0]=Point(0,0);
    
    ///3. Sort last n-1 Points by its arg
    sort(Vertex+1,Vertex+n,compare_arg);
    
    ///4. Build a stack to scan the edges
    Point VertexStack[n];int t=-1;//top
    for(int i=0;i<n;i++){
        while(t>0&&triangle(VertexStack[t-1],VertexStack[t],Vertex[i])<=0)t--;//pop
        VertexStack[++t]=Vertex[i];
    }
    //Points in VertexStack constitute vertexes of the convex hull.
    //Notice that Vertex[0] and Vertex[n-1] MUST be in the vertexes.
    
    ///5. Calculate the area
    cout << "凸包的面积为：" << polygon(VertexStack,t+1) << endl;
}
