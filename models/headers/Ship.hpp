//
// Created by sdf on 02.10.2024.
//

#ifndef UNTITLED1_SHIP_HPP
#define UNTITLED1_SHIP_HPP


#include <vector>
#include "Segment.hpp"
#include <memory>

enum class Orientation {
    HORIZONTAL,
    VERTICAL
};

class Ship {
public:
    Ship(int length);
    Orientation orientation;
    Segment& getSegment(int index);
    int getLen();
    void setOrientation(Orientation orientation1) {
        this->orientation = orientation1;
    }
    bool isDestroyed() const;
private:
    std::vector<Segment> segments;
};


#endif //UNTITLED1_SHIP_HPP
