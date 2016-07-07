//
//  Stage.cpp
//  CurlingGame
//
//  Created by 石田栄太 on 2016/07/06.
//
//

#include "StageScene.hpp"

USING_NS_CC;

StageScene::StageScene()
:_tiledMap(nullptr)
{
    
}

StageScene::~StageScene()
{
    CC_SAFE_RELEASE_NULL(_tiledMap);
}

bool StageScene::init()
{
    if(!Layer::init())
    {
        return false;
    }
    
    //mapファイルからノードを作成
    auto map = TMXTiledMap::create("curling_coat_map.tmx");
    this->addChild(map);
    this->setTiledMap(map);
    
    //地形データを取得
    auto coatLayer = map->getLayer("curling_coat");
    //ハウス1
    auto house1Layer = map->getLayer("house1");
    //ハウス2
    auto house2Layer = map->getLayer("house2");
    
    //マップのサイズ
    auto mapSize = map->getMapSize();
    for (int x = 0; x < mapSize.width; ++x){
        for (int y = 0; y < mapSize.height; ++y){
            auto coordinate = Vec2(x,y);
            
            this->addPhysicsBody(coatLayer, coordinate);
            this->addPhysicsBody(house1Layer, coordinate);
            this->addPhysicsBody(house2Layer, coordinate);
        }
    }
    
    this->scheduleUpdate();
    
    return true;
}

Sprite* addPhysicsBody(cocos2d::TMXLayer *layer, cocos2d::Vec2& coordinate)
{
    //タイルのスプライトを取り出す
    auto sprite = layer->getTileAt(coordinate);
    if(sprite){
        //剛体用のマテリアルを作成
        auto material = PhysicsMaterial();
        //摩擦は0
        material.friction = 0;
        //剛体を設置
        auto physicsBody = PhysicsBody::createBox(sprite->getContentSize(),material);
        //剛体を固定
        physicsBody->setDynamic(false);
        //剛体をつけるSpriteのアンカーポイントを中心にする
        sprite->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
        //剛体をSpriteにつける
        sprite->setPhysicsBody(physicsBody);
        
        return sprite;
    }
    
    return nullptr;
}

void StageScene::update(float dt)
{
    
}