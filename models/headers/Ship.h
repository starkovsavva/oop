//
// Created by sdf on 02.10.2024.
//

#ifndef UNTITLED1_SHIP_H
#define UNTITLED1_SHIP_H


#include <vector>
#include "Segment.h"
#include <memory>

class Ship {
public:
    Ship(int length);
    bool isHorizontal1() const;
    int getLen() const;
    void setIsHorizontal(bool isHorizontal);
private:
    std::vector<std::unique_ptr<Segment>> segments;
    bool isHorizontal;
    int len;
};


#endif //UNTITLED1_SHIP_H
