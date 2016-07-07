//
//  Stage.cpp
//  CurlingGame
//
//  Created by 石田栄太 on 2016/07/07.
//
//

#include "Stage.hpp"

USING_NS_CC;

Stage::Stage()
:_tiledMap(nullptr)
{
    
}

Stage::~Stage()
{
    CC_SAFE_RELEASE_NULL(_tiledMap);
}

bool Stage::init()
{
    if(!Layer::init())
    {
        return false;
    }
    
    //マップファイルからノード作成
    auto map = TMXTiledMap::create("map/curling_coat_map.tmx");
    this->addChild(map);
    this->setTiledMap(map);
    
    this->scheduleUpdate();
    
    return true;
}

void Stage::update(float dt)
{
    
}