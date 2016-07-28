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

// tag list
#define CHAR_OBJTAG 100
#define PULL_LINE_OBJTAG 200

#define CROKUNIT_REG_VELOCITY_RATE		0.04f	// 速度減衰係数

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
    
    //画面の大きさを取り出す
    auto winSize = Director::getInstance()->getWinSize();
    
    //ストーン(赤)
    auto sprite = Sprite::create("stone_red.png");
    
    auto material = PHYSICSBODY_MATERIAL_DEFAULT;
    material.density   = 1.0f; // 密度
    material.restitution = 0.8f; // 反発係数
    material.friction    = 1.0f; // 摩擦係数
    
    //スプライトと同じ大きさの剛体を作成する
    PhysicsBody* physicsBody = PhysicsBody::createCircle(getContentSize().width / 2, material);
    
    physicsBody->setMass(1.0f); // 質量
    physicsBody->setCategoryBitmask( 1 ); // カテゴリー
    physicsBody->setCollisionBitmask( 1 ); // 衝突判定するカテゴリー
    physicsBody->setDynamic(true); // 重力の影響を有効化
    
    //剛体をSpriteに付ける
    sprite->setPhysicsBody(physicsBody);
    sprite->setTag(CHAR_OBJTAG);
    sprite->setPosition(Vec2(winSize.width / 2.0, 200));
    
    // 速度減衰処理を独自実装
    schedule(schedule_selector(Stone::registVelocity));
    
    this->addChild(sprite);
    
    
    // Touchイベントを管理しているEventDispatcherインスタンスを取得
    auto eventDispatcher = Director::getInstance()->getEventDispatcher();
    // 登録するリスナー情報を生成
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = CC_CALLBACK_2(Stone::onTouchBegan, this);
    listener->onTouchMoved = CC_CALLBACK_2(Stone::onTouchMoved, this);
    listener->onTouchEnded = CC_CALLBACK_2(Stone::onTouchEnded, this);
    listener->onTouchCancelled = CC_CALLBACK_2(Stone::onTouchCancelled, this);
    // リスナー情報を登録
    eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    
    
    return true;
}

void Stone::registVelocity(float)
{
    if(0 < getPhysicsBody()->getVelocity().length()) {
        // 減衰処理
        Vec2 tmp(getPhysicsBody()->getVelocity());
        if(tmp.length() < 1.0f) {
            getPhysicsBody()->setVelocity(Vec2(0.0f, 0.0f));
        }
        else {
            tmp.scale(CROKUNIT_REG_VELOCITY_RATE);
            getPhysicsBody()->setVelocity(getPhysicsBody()->getVelocity()-tmp);
        }
    }
}

void Stone::update(float dt)
{
    auto* draw = dynamic_cast<DrawNode*>(this->getChildByTag(PULL_LINE_OBJTAG));
    if ( draw != nullptr )
    {//存在した場合＝ひっぱり中なのでひっぱりラインを更新
        draw->clear();
        auto* charSprite = (Sprite*)this->getChildByTag(CHAR_OBJTAG);
        auto charSpritePos = charSprite->getPosition();
        draw->drawSegment(Vec2(charSpritePos.x, charSpritePos.y), Vec2(currentTouchPoint.x, currentTouchPoint.y), 2.0f, Color4F(.5f, 1.0f, .7f, 1.0f));
    }
}