#include "TetrisScene.h"
#include "json/document.h"
#include <assert.h>

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
    auto name = it->name.GetString();

  }

}
