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
    
    // 重力を無効化
    PhysicsWorld* phyWorld = scene->getPhysicsWorld();
    Vect gravity;
    gravity.setPoint(0, 0);
    phyWorld->setGravity(gravity);
    
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

    curlingStage = new StoneSprite("curling_coat1136.png");
    curlingStage->setPosition(Vec2(visibleSize.width/2 + origin.x, 563));
    this->addChild(curlingStage);
    
    //Stone.hppを消したため削除
    /*
    curlingStone = new Stone("stone_red.png");
    curlingStone->setPosition(Vec2(visibleSize.width/2 + origin.x,200.0f));
    curlingStage->addChild(curlingStone);
    */
    
    // インスタンス生成
    StoneManager::createInstance();
    // ストーンの登録（仮にIDを1でひとつ登録）
    Stone* unit = CUR_STONE_MNG.createUnit(1, "stone_red.png");
    curlingStage->addChild(unit);
     
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
    
    //処理の変更のため削除
    /*
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
    */
    
    bool isTouch = false;
    //ストーン管理クラスに登録されている、一番新しいストーンで判定
    int idx = CUR_STONE_MNG.getUnitNum() - 1;
        Stone* unit = CUR_STONE_MNG.getUnitByIdx(idx);
        if (unit){
            if (unit->isTouchPoint(pos))
            {
                unit->setTouchPoint(pos);
                isTouch = true;
                log("Touched on Stone");
            }
        }
    //ストーンをタッチしていなかった場合はステージの処理を行う
    if (isTouch == false){
        if (curlingStage->isTouchPoint(pos))
        {
            //curlingStage->setTouchPoint(pos);
            isTouch = true;
            log("Touched on Stage");
        }
    }
    
    //仮実装
    //ストーンもステージもタッチしていなかった場合はストーンを追加する
    if(isTouch == false) {
        // ストーンの登録（仮にIDを1でひとつ登録）
        Stone* unit = CUR_STONE_MNG.createUnit(1, "stone_red.png");
        curlingStage->addChild(unit);
    }
    
    return true;
}

//タッチを移動（ドラッグ）する時
void GameScene::onTouchMoved(Touch* pTouch, Event* pEvent)
{
    Vec2 pos = pTouch->getLocation();
    //Stone.hppを消したため削除
    //curlingStone->setPositionWithTouchPoint(pos);
    
    //仮実装
    //ストーン管理クラスに登録されている、すべてのストーンで判定
    for(int idx=0; idx<CUR_STONE_MNG.getUnitNum(); ++idx) {
        if (idx == CUR_STONE_MNG.getUnitNum()-1){
            Stone* unit = CUR_STONE_MNG.getUnitByIdx(idx);
            if(unit) {
                unit->setPositionWithTouchPoint(pos);
            }
        }
    }
    
    curlingStage->setPositionWithTouchPoint(pos);
}

//タッチの終了
void GameScene::onTouchEnded(Touch* pTouch, Event* pEvent)
{
    //Stone.hppを消したため削除
    //curlingStone->clearTouchPoint();
    
    //仮実装
    //ストーン管理クラスに登録されている、すべてのストーンで判定
    for(int idx=0; idx<CUR_STONE_MNG.getUnitNum(); ++idx) {
        Stone* unit = CUR_STONE_MNG.getUnitByIdx(idx);
        if(unit) {
            unit->clearTouchPoint();
        }
    }
    
    curlingStage->clearTouchPoint();
}
