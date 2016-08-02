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

class Stone : public CurlingSprite
{
public:
    //コンストラクタ
    Stone(const std::string& filename);
    
    // タッチ関連
    
    /** 引数の座標を起点として、タッチ状態にする
     *@param cocos2d::Vec2 タッチの基点座標
     *@return void
     */
    virtual void setTouchPoint(cocos2d::Vec2);
    
    /** setTouchPointでタッチ状態にしたものを初期化することで解除する
     *@param void
     *@return void
     */
    virtual void clearTouchPoint(void);
    
    /** setTouchPointでタッチ状態にした座標を、引数の座標に移動させる。スプライトのドラッグ処理などに使用
     *@param cocos2d::Vec2 移動後の座標
     *@return void
     */
    virtual void setPositionWithTouchPoint(cocos2d::Vec2);
    
protected:
    // ドラッグ描画用
    cocos2d::DrawNode* pDrawNode;
    
    // タッチ座標
    cocos2d::Vec2 touchPoint;
    
    // ドラッグ座標
    cocos2d::Vec2 dragPoint;
    
};


#endif /* Stone_hpp */
