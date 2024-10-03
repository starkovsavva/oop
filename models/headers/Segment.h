//
// Created by sdf on 03.10.2024.
//

#ifndef UNTITLED1_SEGMENT_H
#define UNTITLED1_SEGMENT_H

#include <functional>
#include "Ship.h"
#include <memory>

class Segment {
public:
    Segment(Ship& parentShip);
    const void changeState();
private:
    enum state {FULL , DESTROYED};
    state current;

    const Ship& getShip() const;
    const Ship& parentShip;
};


#endif //UNTITLED1_SEGMENT_H
