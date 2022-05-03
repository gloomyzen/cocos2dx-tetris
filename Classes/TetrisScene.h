#ifndef COCOS_TETRIS_TETRISSCENE_H
#define COCOS_TETRIS_TETRISSCENE_H

#include "cocos2d.h"
#include <vector>

struct shapeStruct {
    shapeStruct(int _x, int _y, cocos2d::Color3B _color = cocos2d::Color3B::BLUE) : x(_x), y(_y), color(_color) {}

    int x = 0;
    int y = 0;
    cocos2d::Color3B color = cocos2d::Color3B::BLUE;
};

class TetrisScene : public cocos2d::Scene {
public:
    void initScene();

private:
    void playGame();
    void spawn();

    std::vector<std::vector<shapeStruct>> shapes;
};

#endif// COCOS_TETRIS_TETRISSCENE_H
