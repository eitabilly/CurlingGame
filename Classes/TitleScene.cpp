//
//  TitleScene.cpp
//  CurlingGame
//
//  Created by 石田栄太 on 2016/06/27.
//
//

#include "TitleScene.hpp"
#include "GameScene.hpp"

USING_NS_CC;

Scene* TitleScene::createScene()
{
    //'scene' is an autorelease object
    Scene* scene
    {
        Scene::create()
    };
    
    //'Layer' is an autorelease object
    Layer* layer
    {
        TitleScene::create()
    };
    
    //Add layer as a child to scene
    scene->addChild(layer);
    
    //Return the scene
    return scene;
}

//On "init" you need to initialize your instance
bool TitleScene::init()
{
    /////////////////////////////////////////
    //1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    //画像サイズ
    Size visibleSize
    {
        Director::getInstance()->getVisibleSize()
    };
    
    //背景
    Sprite* bgSprite
    {
        Sprite::create("bg.png")
    };
    bgSprite->setPosition(visibleSize/2);
    this->addChild(bgSprite);
    
    //タイトルロゴ
    Sprite* logoSprite
    {
        Sprite::create("title.png")
    };
    logoSprite->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2 + 150));
    this->addChild(logoSprite);
    
    //スタートボタン
    ui::Button* startButton
    {
        ui::Button::create("singleplay.png")
    };
    startButton->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2 - 200));
    this->addChild(startButton);
    startButton->addTouchEventListener(CC_CALLBACK_2(TitleScene::touchEvent, this));
    
    return true;
}

//ボタンのタッチイベント
void TitleScene::touchEvent(Ref *pSender, ui::Widget::TouchEventType type)
{
    switch (type)
    {
        case ui::Widget::TouchEventType::BEGAN:
        {
            CCLOG("button pushed");
            // 何度も押せないように一度押したらアクションを無効化する
            this->getEventDispatcher()->removeAllEventListeners();
            // 0.5秒待ってからゲームを開始する
            auto delay = DelayTime::create(0.2);
            // ゲームを始めるアクション
            auto startGame = CallFunc::create([]{
                Scene* scene { GameScene::createScene()};
                auto transition = TransitionCrossFade::create(0.5, scene);
                Director::getInstance()->replaceScene(transition);
            });
            
            this->runAction(Sequence::create(delay,startGame,NULL));
            
            break;
        }
        default:
            break;
    }
}