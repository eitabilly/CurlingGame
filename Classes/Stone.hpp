//
//  Stone.hpp
//  CurlingGame
//
//  Created by 石田栄太 on 2016/07/08.
//
//

#ifndef Stone_hpp
#define Stone_hpp

#include "cocos2d.h"

class Stone : public cocos2d::Layer
{
protected:
    Stone();
    virtual ~Stone();
    bool init() override;
    
public:
    
    CREATE_FUNC(Stone);
    
private:
    
    // Touchイベントの開始地点
    cocos2d::Point currentTouchPoint;
    
    // Touchイベント用
    bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event) override;
    void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event) override;
    void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event) override;
    void onTouchCancelled(cocos2d::Touch* touch, cocos2d::Event* event) override;
};


#endif /* Stone_hpp */
