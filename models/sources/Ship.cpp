//
// Created by sdf on 02.10.2024.
//

#include "../headers/Ship.h"

Ship::Ship(int length) {

    for (int i = 0; i < length; ++i) {
        segments.push_back(std::make_unique<Segment>(*this));
    }

}

int Ship::getLen() const {
    return this->len;
}

bool Ship::isHorizontal1() const {
    return isHorizontal;
}

void Ship::setIsHorizontal(bool isHorizontal) {
    Ship::isHorizontal = isHorizontal;
}
