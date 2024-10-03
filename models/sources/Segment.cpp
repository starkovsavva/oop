//
// Created by sdf on 03.10.2024.
//

#include "../headers/Segment.h"

const void Segment::changeState() {
    this->current = DESTROYED;
}

Segment::Segment(Ship& ship) : parentShip(ship) {
    // Инициализируем ссылку на родительский корабль
}

const Ship& Segment::getShip() const {
    return this->parentShip;
}
