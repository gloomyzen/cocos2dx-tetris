#include "TetrisScene.h"
#include "json/document.h"
#include <assert.h>

const float widthSize = 10.f;
const float heightSize = 20.f;
const float tileSize = 10.f; //width and height of tile
const float tileScale = 4.f;
const float tickTime = 1.5f;

void TetrisScene::initScene() {
    rapidjson::Document document;
    auto jsonStr = cocos2d::FileUtils::getInstance()->getStringFromFile("shapes.json");
    assert(!jsonStr.empty() && "shapes.json is empty.");
    if (jsonStr.empty()) {
        return;
    }
    document.Parse<0>(jsonStr.c_str());
    assert(!document.HasParseError() && "json has errors.");
    if (document.HasParseError()) {
        return;
    }

    for (auto it = document.MemberBegin(); it != document.MemberEnd(); ++it) {
        assert(it->value.IsArray() && "shape must be array!");
        std::vector<shapeStruct> shape;
        auto array = it->value.GetArray();
        for (auto ar = array.Begin(); ar != array.End(); ++ar) {
            assert(ar->IsArray() && "shape must be array!");
            auto piece = ar->GetArray();
            if (piece[0u].IsNumber() && piece[1u].IsNumber()) {
                shape.emplace_back(piece[0u].GetInt(), piece[1u].GetInt());
            }
        }
        shapes.push_back(shape);
    }
    playGame();
}

void TetrisScene::playGame() {
    auto delay = cocos2d::DelayTime::create(tickTime);
    auto clb = cocos2d::CallFunc::create([this](){
        spawn();
        //todo add move
        //todo add check
    });
    auto seq = cocos2d::Sequence::create(delay, clb, nullptr);
    auto repeat = cocos2d::RepeatForever::create(seq);
    this->runAction(repeat);
}

void TetrisScene::spawn() {
    auto director = cocos2d::Director::getInstance();
    auto sceneSize = director->getVisibleSize();
    auto shape = shapes.front(); //todo add random shape
    for (const auto& item : shape) {
        auto sprite = new cocos2d::Sprite();
        sprite->initWithFile("tile.png");
        addChild(sprite);
        sprite->setContentSize({tileSize, tileSize});
        sprite->setScale(tileScale);
        sprite->setAnchorPoint(cocos2d::Vec2::ZERO);
        auto origSize = tileSize * tileScale;
        sprite->setPositionY(sceneSize.height - origSize);
        sprite->setPositionX(sceneSize.width / origSize / 2 * origSize);
    }

}
