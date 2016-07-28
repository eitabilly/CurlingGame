//
//  CurlingSprite.cpp
//  CurlingGame
//
//  Created by 石田栄太 on 2016/07/27.
//
//

#include "CurlingSprite.hpp"

USING_NS_CC;

CurlingSprite::CurlingSprite(const std::string& filename)
:bTouched(false)
,ofstTouchPoint(0.0f,0.0f)
,bEnableTouchMove(true)
{
    initWithFile(filename);
}


Rect CurlingSprite::getRect(void) const
{
    // スプライトの座標（画像の中心座標）
    Vec2 point = this->getPosition();
    
    // スプライトの幅と高さ
    int w = this->getContentSize().width;
    int h = this->getContentSize().height;
    
    // スプライトの範囲を返す
    return Rect(point.x-(w/2), point.y-(h/2), w, h);
}

bool CurlingSprite::isTouchPoint(Vec2 point) const
{
    Vec2 pointLocal = getParent()->convertToNodeSpace(point);
    //containPoint(point) pointがRectの領域内に触れた時trueを返す
    return this->getRect().containsPoint(pointLocal);
}

bool CurlingSprite::isTouched(void) const
{
    return bTouched;
}

void CurlingSprite::setTouchPoint(Vec2 point)
{
    Vec2 pointLocal = getParent()->convertToNodeSpace(point);
    ofstTouchPoint = this->getPosition() - pointLocal;
    bTouched = true;
}

void CurlingSprite::clearTouchPoint(void)
{
    ofstTouchPoint.set(0.0f,0.0f);
    bTouched = false;
}

void CurlingSprite::setPositionWithTouchPoint(Vec2 point)
{
    if(isEnableTouchMove()){
        if(bTouched) {
            Vec2 pointLocal = getParent()->convertToNodeSpace(point);
            this->setPosition(pointLocal + ofstTouchPoint);
    
        }
    }
}
