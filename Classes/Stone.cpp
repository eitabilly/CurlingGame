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
    
    Sprite* stone = Sprite::create("redstone.png");
    auto body = PhysicsBody::createCircle(this->getContentSize().width / 2.0);
    body->setRotationEnable(true);
    body->setMass(1.0f); // 重さを指定（ここが無いと後で飛ばせなくなる）
    stone->setPhysicsBody(body);
    
    return true;
}
