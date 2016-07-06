//
//  GameScene.hpp
//  CurlingGame
//
//  Created by 石田栄太 on 2016/06/30.
//
//

#ifndef GameScene_hpp
#define GameScene_hpp

#include <cocos2d.h>

USING_NS_CC;

class GameScene : public cocos2d::Layer
{
    //クラスメソッド
public:
    static cocos2d::Scene* createScene();
    
    //インスタンスメソッド
private:
    static cocos2d::Sprite* addNewCircleAtPosition(Node *parent, Point p, bool dynamic, const char *fileName);
    
    static cocos2d::Sprite* addNewBoxAtPosition(Node *parent, Point p, bool dynamic, const char *fileName);
    
    virtual bool init(); //初期化
    
    void setupScrean(); //画面の設定
    
    CREATE_FUNC(GameScene);
};

#endif /* GameScene_hpp */
