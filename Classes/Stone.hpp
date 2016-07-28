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
#include "CurlingSprite.hpp"

class Stone : public cocos2d::Layer
{
protected:
    Stone();
    virtual ~Stone();
    bool init() override;
    
public:
    
    CREATE_FUNC(Stone);
    
    // 速度減衰処理（重力設定できないので独自実装）
    void registVelocity(float);
    
private:
    
    // Touchイベントの開始地点
    cocos2d::Point currentTouchPoint;
    
    void update(float dt) override;
};


#endif /* Stone_hpp */
