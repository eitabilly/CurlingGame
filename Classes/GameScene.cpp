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
        Scene::create()
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
    
    //画面表示の設定
    this->setupScrean();
    
    return true;
}

//画面の設定
void GameScene::setupScrean()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
}