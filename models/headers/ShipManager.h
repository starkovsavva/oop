//
// Created by sdf on 03.10.2024.
//

#ifndef UNTITLED1_SHIPMANAGER_H
#define UNTITLED1_SHIPMANAGER_H


#include <vector>
#include "Ship.h"

class ShipManager {

public:

    ShipManager(std::vector<int> shipSizes);


    const bool createShip(int len);
    const void findByUniqueRef(int unique_ref);

private:
    std::vector<Ship> ships;


};


#endif //UNTITLED1_SHIPMANAGER_H
