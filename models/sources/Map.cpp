//
// Created by sdf on 03.10.2024.
//
#include <stdexcept>
#include "../headers/Map.hpp"
#include <iostream>
#include <iomanip>


Map::Map(int width, int height): width(width), height(height){
    if (width <= 0 || height <= 0) {
        throw std::invalid_argument("Invalid field dimensions");
    }

    for(int y = 0; y < height; ++y){
        field.emplace_back();
        for (int x = 0; x < width; ++x) {
            field[y].emplace_back(Coordinate(x, y),CellStatus::UNKNOWN,CellValue::WaterRevealed);

        }
    }

}
bool Map::isOutOfBounds(const Coordinate& coord) const {
    bool res = coord.x < 0 || coord.x >= width || coord.y < 0 || coord.y >= height;
//    std::cout<< res<<std::endl;
    return res;
}

bool Map::isCellOccupied(const Coordinate& coord) const {
    bool res = !isOutOfBounds(coord) && !(field.at(coord.y).at(coord.x).getCell()->getSegmentReference() == nullptr);
//    std::cout<< res<<std::endl;
    return res;
}


void Map::placeShip(Ship& ship, Coordinate startPos, Orientation orientation) {
//Проверка
    Coordinate segmentCoords = Coordinate(startPos.x,startPos.y);
    int length = ship.getLen();
    for (int i = 0; i < length; ++i) {
        if (Orientation::HORIZONTAL == orientation){
            segmentCoords = Coordinate(startPos.x+i,startPos.y);
        }
        else{
            segmentCoords = Coordinate(startPos.x,startPos.y + i);
        }

        if(segmentCoords.x < 0|| segmentCoords.x >= width || segmentCoords.y < 0 || segmentCoords.y >= height){
            throw std::invalid_argument("Ship out of bounds!");
        }
    }

    for (int i = 0; i < length; ++i) {
        Coordinate segmentCoord1 = Coordinate(startPos.x+i,startPos.y);
        if (orientation == Orientation::HORIZONTAL) {
            segmentCoord1 = Coordinate(startPos.x + i, startPos.y);
        } else {
            segmentCoord1 = Coordinate(startPos.x, startPos.y + i);
        }
        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                Coordinate checkCoord = Coordinate(segmentCoord1.x + dx, segmentCoord1.y + dy);
                if (isCellOccupied(checkCoord)) {
                    throw std::invalid_argument("Ship placement too close to another ship");
                }
            }
        }
    }
//Ставим корабль

        for (int i = 0; i < length; ++i) {
            Coordinate segmentCoord = Coordinate(startPos.x+i,startPos.y);
            if (orientation == Orientation::HORIZONTAL) {
                segmentCoord = Coordinate(startPos.x + i, startPos.y);
            } else {
                segmentCoord = Coordinate(startPos.x, startPos.y + i);
            }

            field.at(segmentCoord.y).at(segmentCoord.x).setCellStatus(CellStatus::SHIP);
            field.at(segmentCoord.y).at(segmentCoord.x).setSegment(&ship.getSegment(i));
            field.at(segmentCoord.y).at(segmentCoord.x).setValue(CellValue::ShipPart);
        }

}

void Map::printCell(Coordinate coords) const {
    std::cout<< field.at(coords.y).at(coords.x).display(); std::cout<< std::endl;

}

//void Map::updateCells() const{
//    for (int i = 0; i < height; ++i) {
//        for (int j = 0; j < width; ++j) {
//            Cell& cell = field.at(i).at(j);
//            if(cell.getCellStatus() == CellStatus::SHIP){
//
//                Segment* segment = cell.getSegmentReference();
//                cell.setValue(CellValue::ShipPart);
//                if(segment->getState() == SegmentState::Intact){
//                    segment->setState(SegmentState::Damaged);
//                    cell.setValue(CellValue::Destroyed);
//                } else if(segment->getState() == SegmentState::Damaged){
//                    segment->setState(SegmentState::Destroyed);
//                    cell.setValue(CellValue::Destroyed);
//                }
//
//                return CellStatus::SHIP;
//
//            }else if(cell.getCellStatus() == CellStatus::UNKNOWN){
//                cell.setCellStatus(CellStatus::EMPTY);
//                cell.setValue(CellValue::WaterRevealed);
//                return cell.getCellStatus();
//            }
//        }
//    }
//}
CellStatus Map::attackCell(const Coordinate &coord) {
    if (coord.x < 0 || coord.x >= width || coord.y < 0 || coord.y >= height) {
        throw std::invalid_argument("Attack out of bounds");
    }
    Cell& cell = field.at(coord.y).at(coord.x);
    if(cell.getCellStatus() == CellStatus::SHIP){

        Segment* segment = cell.getSegmentReference();
        cell.setValue(CellValue::ShipPart);
        if(segment->getState() == SegmentState::Intact){
            segment->setState(SegmentState::Damaged);
            cell.setValue(CellValue::Destroyed);
        } else if(segment->getState() == SegmentState::Damaged){
            segment->setState(SegmentState::Destroyed);
            cell.setValue(CellValue::Destroyed);
        }

        return CellStatus::SHIP;

    }else if(cell.getCellStatus() == CellStatus::UNKNOWN){
        cell.setCellStatus(CellStatus::EMPTY);
        cell.setValue(CellValue::WaterRevealed);
        return cell.getCellStatus();
    }





}
void Map::display() const {
    int size = field.size();
    char letters[] {'1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B',
                    'C','D', 'E', 'F', 'G', 'H', 'K', 'S', 'T', 'U',
                    'V', 'W', 'X','Y', 'Z'};

    std::cout << "    ";
    for (int j = 0; j < size; ++j) {
        std::cout << "+ — ";
    }
    std::cout << "+\n";

    for (int i = 0; i < size; ++i) {
        std::cout << std::setw(2) << i + 1 << ". ";

        for (int j = 0; j < size; ++j) {
            std::cout << "| ";
            switch (field[i][j].display()) {
                case 'S':
                    std::cout << "\033[1;32m";
                    break;
                case '!':
                    std::cout << "\033[1;33m";
                    break;
                case '0':
                    std::cout << "\033[1;31m";
                    break;
                case '~':
                    std::cout << "\033[1;34m";
                    break;
            }
            std::cout << field[i][j].display() << "\033[0m ";
        }
        std::cout << "|\n";

        std::cout << "    ";
        for (int j = 0; j < size; ++j) {
            std::cout << "+ — ";
        }
        std::cout << "+\n";
    }

    std::cout << "    ";
    for (int j = 0; j < size; ++j) {
        std::cout << "  " << letters[j] << " ";
    }
    std::cout << '\n';
}


Map::Map(const Map& other): width(other.width), height(other.height) {
    field = other.field;
}

Map::Map(Map&& other) noexcept : width(other.width), height(other.height), field(std::move(other.field)) {
    other.width = 0;
    other.height = 0;
}

Map& Map::operator=(const Map& other) {
    if (this == &other) return *this;
    width = other.width;
    height = other.height;
    field = other.field;
    return *this;
}

Map& Map::operator=(Map&& other) noexcept {
    if (this == &other) return *this;
    width = other.width;
    height = other.height;
    field = std::move(other.field);
    other.width = 0;
    other.height = 0;
    return *this;
}






