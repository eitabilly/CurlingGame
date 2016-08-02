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
{
    
}

Stage::~Stage()
{

}

bool Stage::init()
{
    if(!Layer::init())
    {
        return false;
    }
    
    
    //画面の大きさを取り出す
    auto winSize = Director::getInstance()->getWinSize();
    
    // 背景
    Sprite* floor = Sprite::create("curling_coat.png");
    floor->setAnchorPoint(Vec2(0 , 0));
    floor->setPosition(Vec2(0 , 0));
    this->addChild(floor);
    
    
    this->scheduleUpdate();
    
    return true;
}


void Stage::update(float dt)
{
    
}