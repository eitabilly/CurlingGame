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
    
    auto stage = Stage::create();
    this->addChild(stage);
    this->setStage(stage);
    
    this->scheduleUpdate();
    
    return true;
}