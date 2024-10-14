//
// Created by sdf on 03.10.2024.
//

#include "../headers/ShipManager.hpp"

Ship& ShipManager::createShip(int len){
    Ship ship(len);
    ships.emplace_back(ship);
    return ship;
}

ShipManager::ShipManager(std::vector<int> shipSizes) {
    for (int i = 0; i < shipSizes.size(); ++i) {
        Ship ship(shipSizes.at(i));
        ships.emplace_back(ship);

    }

}
const std::vector<Ship>& ShipManager::getShips() const{
    return ships;

}
