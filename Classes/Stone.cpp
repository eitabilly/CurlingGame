//
//  Stone.cpp
//  CurlingGame
//
//  Created by 石田栄太 on 2016/07/08.
//
//

#include "Stone.hpp"

USING_NS_CC;

Stone::Stone(const std::string& filename)
:CurlingSprite(filename)
{
    pDrawNode = DrawNode::create();
    addChild(pDrawNode);
    setEnableTouchMove(false);
}

//タッチした場所を返す
void Stone::setTouchPoint(Vec2 point)
{
    // 弾き処理は自分のローカル座標で行うので基点は中心
    touchPoint.x = 0.0f;
    touchPoint.y = 0.0f;
    // スプライトの幅と高さ（アンカーではなく左下から中心までの距離のため必要）
    int w = this->getContentSize().width;
    int h = this->getContentSize().height;
    touchPoint.x += w/2.0f;
    touchPoint.y += h/2.0f;
    
    // 基底の処理
    CurlingSprite::setTouchPoint(point);
}

//タッチ座標を初期化　現在は弾き処理も含めている
void Stone::clearTouchPoint(void)
{
    // 弾き処理（簡易版）
    if(isTouched()) {
        if (dragPoint.x == 0.0f && dragPoint.y == 0.0f){
            touchPoint.x = 0.0f;
            touchPoint.y = 0.0f;
        }
        Vec2 vDirc(dragPoint.x - touchPoint.x, dragPoint.y - touchPoint.y);
        setPosition(getPosition().x - vDirc.x, getPosition().y - vDirc.y);
    }
    // 初期化
    touchPoint.set(0.0f, 0.0f);
    dragPoint.set(0.0f, 0.0f);
    pDrawNode->clear();
    
    // 基底の処理
    CurlingSprite::clearTouchPoint();
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
    CurlingSprite::setPositionWithTouchPoint(point);
}