//
// Created by sdf on 03.10.2024.
//

#ifndef UNTITLED1_SEGMENT_HPP
#define UNTITLED1_SEGMENT_HPP

#include <functional>
#include "Ship.hpp"
#include <memory>
enum class SegmentState{
    Intact,
    Damaged,
    Destroyed
};

class Segment {
public:
    Segment() : state(SegmentState::Intact){}
    const void setState(SegmentState newState){
        this->state = newState;
    };
    SegmentState getState() const{
        return state;
    }
private:

    SegmentState state;
};


#endif //UNTITLED1_SEGMENT_HPP
