//
// Created by sdf on 04.10.2024.
//

#include "../headers/Game.hpp"
#include "../headers/Map.hpp"
#include "Constants.hpp"
#include "ShipManager.hpp"
#include <iostream>

void Game::gameInit(){
    std::cout << "Game initialized!" << std::endl;
    Map map(Constants::BOARD_SIZE,Constants::BOARD_SIZE);
    std::vector<int> sizes = {3,2,1};
    ShipManager shipManager(sizes);

    Ship ship(3);
    map.placeShip(ship,Coordinate(5 ,3),Orientation::HORIZONTAL);
    map.display();
//    map.printCell(Coordinate(5 ,3));
    map.attackCell(Coordinate(5,3));
    map.display();
//    map.printCell(Coordinate(5 ,3));
    map.attackCell(Coordinate(9,9));

    Ship ship1(3);
    map.placeShip(ship1,Coordinate(0,0),Orientation::VERTICAL);
    map.display();
//    map.placeShip(Co)

};