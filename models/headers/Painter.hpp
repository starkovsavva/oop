//
// Created by sdf on 04.10.2024.
//

#ifndef UNTITLED1_PAINTER_H
#define UNTITLED1_PAINTER_H


class Painter {
public:
    Painter(const std::vector<std::vector<Cell>>& field);
    void draw() const;
private:
    int rows_, cols_;
    const std::vector<std::vector<Cell>>& myField_;
    const std::vector<std::vector<Cell>>>& enemyField_;
};


#endif //UNTITLED1_PAINTER_H
