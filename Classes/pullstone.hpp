//
//  pullstone.hpp
//  CurlingGame
//
//  Created by 石田栄太 on 2016/07/20.
//
//

#ifndef pullstone_hpp
#define pullstone_hpp

#include "cocos2d.h"
#include "Stone.hpp"
#include "Stage.hpp"

class PullStone : public cocos2d::Layer
{
protected:
    PullStone();
    virtual ~PullStone();
    bool init() override;
    
public:
    void update(float dt) override;
    
    static cocos2d::Scene* createScene();
    
    //ステージ
    CC_SYNTHESIZE_RETAIN(Stage*, _stage, Stage);
    //ストーン
    CC_SYNTHESIZE_RETAIN(Stone *, _redstone, Redstone);
    
    CREATE_FUNC(PullStone);
    
};

#endif /* pullstone_hpp */
