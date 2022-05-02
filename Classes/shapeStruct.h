#ifndef COCOS_TETRIS_SHAPESTRUCT_H
#define COCOS_TETRIS_SHAPESTRUCT_H

#include "cocos2d.h"
#include <vector>

struct shapeStruct {
  shapeStruct(int _x, int _y, cocos2d::Color3B) {}

  int x = 0;
  int y = 0;
  cocos2d::Node* node = nullptr;
};

static std::vector<shapeStruct> generateShape();

#endif // COCOS_TETRIS_SHAPESTRUCT_H
