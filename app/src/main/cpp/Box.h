//
// Created by Administrator on 2019/7/4.
//

#ifndef MYAPPLICATION27_BOX_H
#define MYAPPLICATION27_BOX_H


class Box {
public:
    double length;   // 盒子的长度
    double breadth;  // 盒子的宽度
    double height;   // 盒子的高度

public:
    double getHeight(){
        return height+0.1;
    }
};



#endif //MYAPPLICATION27_BOX_H
