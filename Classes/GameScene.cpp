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
{
    
}

GameScene::~GameScene()
{

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
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    curlingStage = new CurlingSprite("curling_coat.png");
    curlingStage->setPosition(Vec2(visibleSize.width/2 + origin.x, 2048));
    this->addChild(curlingStage);
    
    curlingStone = new Stone("stone_red.png");
    curlingStone->setPosition(Vec2(visibleSize.width/2 + origin.x,200.0f));
    curlingStage->addChild(curlingStone);
    
    //タッチ関係
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = CC_CALLBACK_2(GameScene::onTouchBegan, this);
    listener->onTouchMoved = CC_CALLBACK_2(GameScene::onTouchMoved, this);
    listener->onTouchEnded = CC_CALLBACK_2(GameScene::onTouchEnded, this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
    
    this->scheduleUpdate();
    
    return true;
}

//タッチ処理を開始するためのもの
bool GameScene::onTouchBegan(Touch* pTouch, Event* pEvent)
{
    Vec2 pos = pTouch->getLocation();
    
    if(curlingStone->isTouchPoint(pos))
    {
        curlingStone->setTouchPoint(pos);
        log("Touched on Stone");
    }
    else if(curlingStage->isTouchPoint(pos))
    {
        curlingStage->setTouchPoint(pos);
        log("Touched on Stage");
    }
    
    return true;
}

//タッチを移動（ドラッグ）する時
void GameScene::onTouchMoved(Touch* pTouch, Event* pEvent)
{
    Vec2 pos = pTouch->getLocation();
    curlingStone->setPositionWithTouchPoint(pos);
    curlingStage->setPositionWithTouchPoint(pos);
}

//タッチの終了
void GameScene::onTouchEnded(Touch* pTouch, Event* pEvent)
{
    curlingStone->clearTouchPoint();
    curlingStage->clearTouchPoint();
}