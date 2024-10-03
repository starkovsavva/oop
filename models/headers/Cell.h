//
// Created by sdf on 03.10.2024.
//

#ifndef UNTITLED1_CELL_H
#define UNTITLED1_CELL_H

#include "Ship.h"
#include <memory>

class Cell{
public:
    Cell();
    bool hasShip() const;
    void nextState() const;
private:
    std::unique_ptr<Segment> segmentReference;
public:
    const std::unique_ptr<Segment> &getShipReference() const;
};
#endif //UNTITLED1_CELL_H
