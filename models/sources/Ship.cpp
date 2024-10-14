//
// Created by sdf on 02.10.2024.
//

#include <stdexcept>
#include "../headers/Ship.hpp"

Ship::Ship(int length) {
    if(length< 1 || length > 4){
        throw std::invalid_argument("Invalid ship length");
    }
    for (int i = 0; i < length; ++i) {
        segments.emplace_back();

    }



}

int Ship::getLen(){
    return this->segments.size();
}
Segment& Ship::getSegment(int index) {
    if (index < 0 || index >= segments.size()) {
        throw std::out_of_range("Invalid segment index");
    }
    return segments[index];
}
bool Ship::isDestroyed() const {
    for (const auto& segment : segments) {
        if (segment.getState() != SegmentState::Destroyed) {
            return false;
        }
    }
    return true;
}
