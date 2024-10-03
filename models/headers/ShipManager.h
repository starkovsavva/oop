//
// Created by sdf on 03.10.2024.
//

#ifndef UNTITLED1_SHIPMANAGER_H
#define UNTITLED1_SHIPMANAGER_H


#include <vector>
#include "Ship.h"

class ShipManager {

public:

    ShipManager();


    const bool createShip(int len);
    const void findByUniqueRef();

private:
    std::vector<Ship> ships;


};


#endif //UNTITLED1_SHIPMANAGER_H
