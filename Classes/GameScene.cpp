//
//  GameScene.cpp
//  CurlingGame
//
//  Created by 石田栄太 on 2016/06/30.
//
//

#include "GameScene.hpp"
#include "TitleScene.hpp"

USING_NS_CC;

///重力を表すベクトル
const Vec2 ZERO_GRAVITY = Vec2(0,0);

GameScene::GameScene()
:_stage(nullptr)
{
    
}

GameScene::~GameScene()
{
    CC_SAFE_RELEASE_NULL(_stage);
}

Scene* GameScene::createScene()
{
    //シーンの作成
    Scene* scene
    {
        Scene::createWithPhysics()
    };
    
    //物理空間を取り出す
    auto world = scene->getPhysicsWorld();
    
    //重力を設定する(ゼログラビティ)
    world->setGravity(ZERO_GRAVITY);
    
    
    //レイヤーの作成
    Layer* layer
    {
        GameScene::create()
    };
    scene->addChild(layer);
    
    return scene;
}

//初期化
bool GameScene::init()
{
    //レイヤーの作成
    if(!Layer::init())
    {
        return false;
    }
    
    //Stage.cppを呼び出しステージを作成する
    auto stage = Stage::create();
    this->addChild(stage);
    this->setStage(stage);
    
    this->scheduleUpdate();
    
    return true;
}

