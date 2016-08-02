//
//  Stage.hpp
//  CurlingGame
//
//  Created by 石田栄太 on 2016/07/07.
//
//

#ifndef Stage_hpp
#define Stage_hpp

#include "cocos2d.h"
#include "Stone.hpp"
#include "CurlingSprite.hpp"

class Stage : public cocos2d::Layer
{
protected:
    Stage();
    virtual ~Stage();
    bool init() override;
    
public:
    void update(float dt) override;

    CREATE_FUNC(Stage);
    
};

#endif /* Stage_hpp */
