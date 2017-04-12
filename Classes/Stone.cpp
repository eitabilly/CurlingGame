//
//  Stone.cpp
//  CurlingGame
//
//  Created by 石田栄太 on 2016/07/08.
//
//

#include "Stone.hpp"

USING_NS_CC;

#define CURLING_APPLY_VELOCITY_RATE 4.0f    //引っ張り係数
#define CURLING_REG_VELOCITY_RATE   0.01f	//通常速度減衰係数
#define CURLING_WIDTH_VELOCITY_ADD  3   //タップ時に曲げる係数

Stone::Stone(const std::string& filename)
:StoneSprite(filename)
,velocon(false)
,velocoff(false)
{
    pDrawNode = DrawNode::create();
    addChild(pDrawNode);
    setEnableTouchMove(false);
    
    // 物理エンジン作成
    PhysicsMaterial phyMat = PHYSICSBODY_MATERIAL_DEFAULT;
    phyMat.density		= 1.0f; // 密度
    phyMat.restitution	= 1.05f; // 反発係数
    phyMat.friction		= 1.0f; // 摩擦係数
    // ストーンの形状と同じ円で作成
    PhysicsBody* phyBody = cocos2d::PhysicsBody::createCircle( getContentSize().width/2, phyMat );
    phyBody->setMass(1.0f); // 質量
    phyBody->setCategoryBitmask( 1 ); // カテゴリー
    phyBody->setCollisionBitmask( 1 ); // 衝突判定するカテゴリー
    phyBody->setDynamic(true); // 重力の影響を有効化
    phyBody->setRotationEnable(true); // 剛体の回転を有効化
    setPhysicsBody( phyBody );
    
    // 速度減衰処理
    schedule(schedule_selector(Stone::registVelocity));
}

//タッチした場所を返す
void Stone::setTouchPoint(Vec2 point)
{
    // 投げ処理は自分のローカル座標で行うので基点は中心
    touchPoint.x = 0.0f;
    touchPoint.y = 0.0f;
    // スプライトの幅と高さ（アンカーではなく左下から中心までの距離のため必要）
    int w = this->getContentSize().width;
    int h = this->getContentSize().height;
    touchPoint.x += w/2.0f;
    touchPoint.y += h/2.0f;
    
    // 基底の処理
    StoneSprite::setTouchPoint(point);
}

//タッチ座標をそれぞれのローカル座標に変更する　現在はドラッグした距離に応じて三角形を表示する
void Stone::setPositionWithTouchPoint(Vec2 point)
{
    if(isTouched()) {
        // 自分のローカル座標へ変換
        dragPoint = convertToNodeSpace(point);
        // 三角形の底辺の左右の太さ
        Vec2 vSide(dragPoint.y - touchPoint.y, - (dragPoint.x - touchPoint.x));
        vSide.normalize();
        vSide.scale(50.0f);
        // 描画
        pDrawNode->clear();
        pDrawNode->drawTriangle(Vec2(dragPoint.x+vSide.x, dragPoint.y+vSide.y),
                                Vec2(touchPoint.x, touchPoint.y),
                                Vec2(dragPoint.x-vSide.x, dragPoint.y-vSide.y),
                                Color4F(1.0f,1.0f,1.0f,1.0f)
                                );
    }
    
    // 基底の処理
    StoneSprite::setPositionWithTouchPoint(point);
}

//タッチ座標が中央より右であった場合，右側へ速度を，左だった場合は左側へ速度を持たせる
//希望としてはタップ時間に応じて加速度的に曲げたい
void Stone::setWidthVec(Vec2 point, int kai)
{
    if (point.x < getPosition().x){
        if (getPhysicsBody()->getVelocity().y > (getPhysicsBody()->getVelocity().x - CURLING_WIDTH_VELOCITY_ADD) && getPhysicsBody()->getVelocity().y > 0-getPhysicsBody()->getVelocity().x){
            Vec2 velocity(getPhysicsBody()->getVelocity().x - CURLING_WIDTH_VELOCITY_ADD, getPhysicsBody()->getVelocity().y - CURLING_WIDTH_VELOCITY_ADD);
            getPhysicsBody()->setVelocity(velocity);
        }
        log("left");
    }
    else{
        if (getPhysicsBody()->getVelocity().y > (getPhysicsBody()->getVelocity().x + CURLING_WIDTH_VELOCITY_ADD) && getPhysicsBody()->getVelocity().y > 0-getPhysicsBody()->getVelocity().x){
            Vec2 velocity(getPhysicsBody()->getVelocity().x + CURLING_WIDTH_VELOCITY_ADD, getPhysicsBody()->getVelocity().y - CURLING_WIDTH_VELOCITY_ADD);
            getPhysicsBody()->setVelocity(velocity);
        }
        log("right");
    }
}


//タッチ座標を初期化　現在は投げ処理も含めている
void Stone::clearTouchPoint(void)
{
    // 投げ処理（簡易版）
    // は削除(速度追加する形式に変更するよ)
    /*
     if(isTouched()) {
     if (dragPoint.x == 0.0f && dragPoint.y == 0.0f){
     touchPoint.x = 0.0f;
     touchPoint.y = 0.0f;
     }
     Vec2 vDirc(dragPoint.x - touchPoint.x, dragPoint.y - touchPoint.y);
     setPosition(getPosition().x - vDirc.x, getPosition().y - vDirc.y);
     }
     */
    
    // 引っ張った距離に係数(CURLING_APPLY_VELOCITY_RATE)をかけて速度に設定
    if(isTouched())
    {
        if (dragPoint.x == 0.0f && dragPoint.y == 0.0f){
            touchPoint.x = 0.0f;
            touchPoint.y = 0.0f;
        }
        Vec2 velocity(touchPoint.x - dragPoint.x, touchPoint.y - dragPoint.y);
        velocity.scale(CURLING_APPLY_VELOCITY_RATE);
        getPhysicsBody()->setVelocity(velocity);
    }
    
    // 初期化
    touchPoint.set(0.0f, 0.0f);
    dragPoint.set(0.0f, 0.0f);
    pDrawNode->clear();
    
    // 基底の処理
    StoneSprite::clearTouchPoint();
}

void Stone::registVelocity(float)
{
    if(0 < getPhysicsBody()->getVelocity().length()) {
        // 減衰処理
        Vec2 tmp(getPhysicsBody()->getVelocity());
        if(tmp.length() < 1.1f) {
            getPhysicsBody()->setVelocity(Vec2(0.0f, 0.0f));
        }
        else {
            tmp.scale(CURLING_REG_VELOCITY_RATE);
            getPhysicsBody()->setVelocity(getPhysicsBody()->getVelocity()-tmp);
        }
    }
}

bool Stone::boolStoneadd(void)
{
    Vec2 tmp(getPhysicsBody()->getVelocity());
    if (tmp.length() == 0.0f){
        velocoff = true;
    }
    return velocoff;
}

