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
,_redstone(nullptr)
{
    
}

Stage::~Stage()
{
    CC_SAFE_RELEASE_NULL(_tiledMap);
    CC_SAFE_RELEASE_NULL(_redstone);
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
    
    //ハウスレイヤーを取得
    auto house1Layer = map->getLayer("house1");
    auto house2Layer = map->getLayer("house2");
    
    //マップのサイズ
    auto mapSize = map->getMapSize();
    for (int x = 0; x < mapSize.width; ++x) {
        for (int y = 0; y < mapSize.height; ++y) {
            auto coordinate = Vec2(x,y);
            
            this->addPhysicsBody(house1Layer, coordinate);
            this->addPhysicsBody(house2Layer, coordinate);
        }
    }
    
    //redstoneの生成
    auto redstone = Stone::create();
    redstone->setPosition(Vec2(200 , 100));
    this->addChild(redstone);
    this->setRedstone(redstone);
    
    this->scheduleUpdate();
    
    return true;
}

Sprite* Stage::addPhysicsBody(TMXLayer *layer, Vec2 &coordinate)
{
    //タイルのスプライトを取り出す
    auto sprite = layer->getTileAt(coordinate);
    if (sprite) {
        //剛体用のマテリアルを作成
        auto material = PhysicsMaterial();
        //ひっかからないように摩擦を0にする
        material.friction = 0;
        //剛体を設置する
        auto physicsBody = PhysicsBody::createBox(sprite->getContentSize(),material);
        //剛体を固定する
        physicsBody->setDynamic(false);
        //剛体をつけるSpriteのアンカーポイントを左下にする
        sprite->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
        //剛体をSpriteにつける
        sprite->setPhysicsBody(physicsBody);
        
        return sprite;
    }
    return nullptr;
}

void Stage::update(float dt)
{
    
}