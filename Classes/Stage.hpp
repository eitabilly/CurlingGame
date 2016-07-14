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

class Stage : public cocos2d::Layer
{
protected:
    Stage();
    virtual ~Stage();
    bool init() override;
    
public:
    void update(float dt) override;
    
    //タイルマップ
    CC_SYNTHESIZE_RETAIN(cocos2d::TMXTiledMap*, _tiledMap, TiledMap);
    //ストーン
    CC_SYNTHESIZE_RETAIN(Stone *, _redstone, Redstone);
    CREATE_FUNC(Stage);
    
private:
    /** 指定のレイヤーの得定位置のタイルに剛体を設置する
     *指定座標にタイルがなかった場合はnullptrを返す
     *@param layer 対象のレイヤー
     *@param coordinate 対象タイルのあるマップ上の座標
     *@return タイルのスプライト　またはnullptr
     */
    cocos2d::Sprite* addPhysicsBody(cocos2d::TMXLayer *layer, cocos2d::Vec2& coordinate);
};

#endif /* Stage_hpp */
