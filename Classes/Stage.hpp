//
//  Stage.hpp
//  CurlingGame
//
//  Created by 石田栄太 on 2016/07/06.
//
//

#ifndef Stage_hpp
#define Stage_hpp

#include <cocos2d.h>
#include "ui/cocosGUI.h"

class StageScene:public cocos2d::Layer
{
public:
    //There's no 'id' in cpp. so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    //Here's a difference. Method 'init' in cocos2d-x returns bool. instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    //Implement the "static create()" method manually
    CREATE_FUNC(StageScene);
    
    //ボタンのタッチイベント
    void touchEvent(Ref *pSender, cocos2d::ui::Widget::TouchEventType type);
};


#endif /* Stage_hpp */
