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
};


#endif /* Stone_hpp */
