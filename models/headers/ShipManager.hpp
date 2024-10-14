//
// Created by sdf on 03.10.2024.
//

#ifndef UNTITLED1_SHIPMANAGER_HPP
#define UNTITLED1_SHIPMANAGER_HPP


#include <vector>
#include "Ship.hpp"

class ShipManager {

public:

    ShipManager(std::vector<int> shipSizes);

    const std::vector<Ship>& getShips() const;

    Ship& createShip(int len);

private:
    std::vector<Ship> ships;


};


#endif //UNTITLED1_SHIPMANAGER_HPP
