//
// Created by sdf on 03.10.2024.
//

#ifndef UNTITLED1_CELL_HPP
#define UNTITLED1_CELL_HPP

#include "Ship.hpp"
#include "Constants.hpp"
#include <memory>

enum class CellStatus { UNKNOWN, EMPTY, SHIP };

enum class CellValue : char {
    WaterHidden = ' ',
    WaterRevealed = '~',
    ShipPart = 'S',
    Hit = 'X',
    Destroyed = '0'
};


struct Coordinate {
    int x;
    int y;

    Coordinate() = default;

    Coordinate(int x_val = 0, int y_val = 0) : x(x_val), y(y_val) {}
    bool operator==(const Coordinate &other) const {
        return x == other.x && y == other.y;
    }

    bool operator<(const Coordinate& other) const {
        if (x < other.x) return true;
        if (x > other.x) return false;
        return y < other.y;
    }

};

class Cell{
private:
    CellValue value;
    Coordinate coords;
    CellStatus cellStatus;
    Segment* segmentReference;
public:
    Cell(Coordinate coords, CellStatus status,CellValue cellValue , Segment* segment = nullptr): coords(coords), cellStatus(status), value(cellValue), segmentReference(segment){};
    Segment* getSegmentReference() const {
        return segmentReference;

    }
    void setValue(CellValue value) {
        Cell::value = value;
    }

    CellStatus getCellStatus() const{
        return cellStatus;
    }
    void setSegment(Segment* newSegment) {
        segmentReference = newSegment;
    }
    Coordinate getCoords() const {
        return coords;
    }
    char display() const{
        return static_cast<char>(value);
    }

    void setCellStatus(CellStatus status){
        cellStatus = status;
    }
    const Cell *const getCell() const{
        return this;
    }



};
#endif //UNTITLED1_CELL_HPP
