//
//  GameScene.cpp
//  CurlingGame
//
//  Created by 石田栄太 on 2016/06/30.
//
//

#include "GameScene.hpp"

Scene* GameScene::createScene()
{
    //シーンの作成
    Scene* scene
    {
        Scene::createWithPhysics()
    };
    
    //レイヤーの作成
    Layer* layer
    {
        GameScene::create()
    };
    scene->addChild(layer);
    
    return scene;
}

// 丸(物理エンジン)を作成
Sprite* GameScene::addNewCircleAtPosition(Node *parent, Point p, bool dynamic, const char *fileName)
{
    Sprite* sprite = Sprite::create(fileName);
    auto material = PHYSICSBODY_MATERIAL_DEFAULT;
    material.density     = 1.0f; // 密度
    material.restitution = 0.7f; // 反発係数
    material.friction    = 0.1f; // 摩擦係数
    sprite->setPhysicsBody(PhysicsBody::createCircle((sprite->getContentSize().width/2 - 1), material));
    sprite->getPhysicsBody()->setDynamic(dynamic);
    sprite->setPosition(p);
    parent->addChild(sprite, 10);
    return sprite;
}

// 四角(物理エンジン)を作成
Sprite* GameScene::addNewBoxAtPosition(Node *parent, Point p, bool dynamic, const char *fileName) {
    Sprite* sprite = Sprite::create(fileName);
    auto material = PHYSICSBODY_MATERIAL_DEFAULT;
    material.density     = 1.0f; // 密度
    material.restitution = 0.7f; // 反発係数
    material.friction    = 0.0f; // 摩擦係数
    sprite->setPhysicsBody(PhysicsBody::createBox(sprite->getContentSize(), material));
    sprite->getPhysicsBody()->setDynamic(dynamic);
    sprite->setPosition(p);
    parent->addChild(sprite, 10);
    return sprite;
}

//初期化
bool GameScene::init()
{
    //レイヤーの作成
    if(!Layer::init())
    {
        return false;
    }
    
    //画面表示の設定
    this->setupScrean();
    
    return true;
}

//画面の設定
void GameScene::setupScrean()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
}