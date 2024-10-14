//
// Created by sdf on 03.10.2024.
//

#ifndef UNTITLED1_MAP_HPP
#define UNTITLED1_MAP_HPP

#include "Cell.hpp"



class Map{
public:
    Map(int width,int height);
    void placeShip(Ship& ship, Coordinate startPos, Orientation orientation);
    void display() const;
    void updateCells() const;
    void printCell(Coordinate coords) const;
    Map(const Map& other);
    Map(Map&& other) noexcept;
    bool isOutOfBounds(const Coordinate& coord) const;
    bool isCellOccupied(const Coordinate& coord) const;
    Map& operator=(const Map& other);
    Map& operator=(Map&& other) noexcept;
    CellStatus attackCell(const Coordinate& coord);
private:
    int width;
    int height;
    std::vector<std::vector<Cell>> field;

};

#endif //UNTITLED1_MAP_HPP
