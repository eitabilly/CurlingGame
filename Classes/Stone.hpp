//
//  Stone.hpp
//  CurlingGame
//
//  Created by 石田栄太 on 2016/07/08.
//
//
/** 仕様書
 *  このクラスは、CurlingGameで使用するストーンを動かすクラスである
 *  ストーンの作成は全てStoneManagerを継承したクラスにて行う
 */

#ifndef Stone_hpp
#define Stone_hpp

#include "cocos2d.h"
#include "StoneSprite.hpp"

class Stone : public StoneSprite
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
    
    /** 引数の座標の位置が画像の中心から見て左右どちらにあるかに応じて左右に速度を加算する
     *@param cocos2d::Vec2  タッチの起点座標
     *@return void
     */
    virtual void setWidthVec(cocos2d::Vec2, int kai);
    
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
    
    
    /** 速度減衰処理
     *  調整として段階的に速度を減らしていく処理を実装している
     *  @param  float   
     */
    void registVelocity(float);
    
    bool boolStoneadd(void);
    
protected:
    // ドラッグ描画用
    cocos2d::DrawNode* pDrawNode;
    
    // タッチ座標
    cocos2d::Vec2 touchPoint;
    
    // ドラッグ座標
    cocos2d::Vec2 dragPoint;
    
    bool velocon;
    bool velocoff;
    
};


#endif /* Stone_hpp */
