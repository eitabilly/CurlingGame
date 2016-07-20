//
//  Stone.cpp
//  CurlingGame
//
//  Created by 石田栄太 on 2016/07/08.
//
//

#include "Stone.hpp"
#include "Stage.hpp"

USING_NS_CC;

Stone::Stone()
{
    
}

Stone::~Stone()
{
}

bool Stone::init()
{
    if(!Layer::init())
    {
        return false;
    }
    
    //画面の大きさを取り出す
    auto winSize = Director::getInstance()->getWinSize();
    
    //テスト
    auto sprite = Sprite::create("stone_red.png");
    //スプライトと同じ大きさの剛体を作成する
    auto pyhsicsBody = PhysicsBody::createCircle(40);
    //剛体をSpriteに付ける
    sprite->setPhysicsBody(pyhsicsBody);
    sprite->setPosition(Vec2(winSize.width / 2.0, 200));
    
    this->addChild(sprite);
    
    
    return true;
}
