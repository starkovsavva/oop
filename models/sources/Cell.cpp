//
// Created by sdf on 03.10.2024.
//
#include "../headers/Cell.h"

bool Cell::hasShip() const {
    return this->ShipReference.get() != nullptr;

}

const std::unique_ptr<Segment> &Cell::getShipReference() const {
    return ShipReference;
}
