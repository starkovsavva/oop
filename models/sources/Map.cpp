//
// Created by sdf on 03.10.2024.
//
#include <stdexcept>
#include "../headers/Map.h"



Map::Map(int len){
    for
}


const std::vector<std::vector<Cell>> &Map::getField() const {
    return field;
}

bool Map::hasShipAt(int x, int y) {
    if(x < 0 || y < 0 || x >= field.size() || y>=field[0].size()){
        throw std::out_of_range("координаты за пределами карты");
    }

    return this->field[x][y].hasShip();

};


