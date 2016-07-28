//
//  GameScene.hpp
//  CurlingGame
//
//  Created by 石田栄太 on 2016/06/30.
//
//

#ifndef GameScene_hpp
#define GameScene_hpp

#include "cocos2d.h"
#include "Stage.hpp"
#include "Stone.hpp"
#include "CurlingSprite.hpp"
#include "ui/cocosGUI.h"

class GameScene:public cocos2d::Layer
{
public:
    //There's no 'id' in cpp. so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    //Here's a difference. Method 'init' in cocos2d-x returns bool. instead of returning 'id' in cocos2d-iphone
    virtual bool init() override;
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    //Implement the "static create()" method manually
    CREATE_FUNC(GameScene);
    
    // タッチ関係のイベント
    
    /** タッチされた座標を読み取り、範囲内をタッチしていた場合trueを返す
     *@param Touch*pTouch タッチされた座標
     *@param Event*pEvent イベント
     *@return bool true or false
     */
    bool onTouchBegan(cocos2d::Touch* pTouch, cocos2d::Event* pEvent) override;
    
    /** タッチされた座標がドラックされた時のドラッグ先の座標を渡す
     *@param Touch*pTouch タッチされた座標
     *@param Event*pEvent イベント
     */
    void onTouchMoved(cocos2d::Touch* pTouch, cocos2d::Event* pEvent) override;
    
    /** タッチ関連情報を初期化することでタッチ関連を終了する
     *@param Touch*pTouch タッチされた座標
     *@param Event*pEvent イベント
     */
    void onTouchEnded(cocos2d::Touch* pTouch, cocos2d::Event* pEvent) override;
    
       
protected:
    GameScene();
    virtual ~GameScene();
    
    CurlingSprite*  curlingStage;
    CurlingSprite*  curlingStone;
    
    
};


#endif /* GameScene_hpp */
