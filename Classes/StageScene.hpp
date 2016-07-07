//
//  Stage.hpp
//  CurlingGame
//
//  Created by 石田栄太 on 2016/07/06.
//
//

#ifndef Stage_hpp
#define Stage_hpp

#include "cocos2d.h"

class StageScene:public cocos2d::Layer
{
public:
    void update(float dt) override;
    
    //タイルマップ
    CC_SYNTHESIZE_RETAIN(cocos2d::TMXTiledMap*, _tiledMap, TiledMap);
    
    /** ステージを生成します
     *  @return ステージ
     */
    static cocos2d::Scene* createScene();
    
protected:
    virtual bool init() override;
    StageScene();
    virtual ~StageScene();
    
private:
    /** 指定のレイヤーの特定位置のタイルに剛体を設置します
     *  指定座標にタイルがなかった場合はnullptrを返します
     *  @param layer 対象のレイヤー
     *  @param coordinate 対象タイルのあるマップ上の座標
     *  @return タイルのスプライト、またはnullptr
     */
    cocos2d::Sprite* addPhysicsBody(cocos2d::TMXLayer *layer, cocos2d::Vec2& coordinate);
    
};

#endif /* Stage_hpp */
