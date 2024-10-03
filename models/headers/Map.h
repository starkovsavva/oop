//
// Created by sdf on 03.10.2024.
//

#ifndef UNTITLED1_MAP_H
#define UNTITLED1_MAP_H

#include "Cell.h"

class Map{
public:
    Map(int len);
    bool hasShipAt(int,int);
    const std::vector<std::vector<Cell>>& getField() const;
private:
    const std::vector<std::vector<Cell>> field;

};

#endif //UNTITLED1_MAP_H
