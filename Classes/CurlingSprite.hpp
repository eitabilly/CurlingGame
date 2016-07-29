//
//  CurlingSprite.hpp
//  CurlingGame
//
//  Created by 石田栄太 on 2016/07/27.
//
//

#ifndef CurlingSprite_hpp
#define CurlingSprite_hpp

#include <stdio.h>
#include "cocos2d.h"

class CurlingSprite : public cocos2d::Sprite
{
public:
    
    /** 渡されたファイル名のスプライトを作成する
     *@param filename ファイル名
     */
    CurlingSprite(const std::string& filename);
    
    Stone(const std::string& filename);
    
    
    // タッチ判定関連
    
    /** タッチされたポイントがスプライトの範囲内かどうかを判定する
     *@param cocos2d::Vec2 座標
     *@return bool 成否
     */
    virtual bool isTouchPoint(cocos2d::Vec2) const;
    
    /** タッチされたかどうかの判定
     *@param void 引数無し
     *@retunr bool 成否
     */
    virtual bool isTouched(void) const;
    
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
    
    
    // タッチ移動有効フラグ設定
    
    /** 引数enable を受け取った時、フラグを書き換える。初期状態はtrue
     *@param bool true or false
     */
    void setEnableTouchMove(bool enable) {
        bEnableTouchMove = enable;
    };
    
    /** フラグを返す
     *@param void 
     *@return bool true or false
     */
    bool isEnableTouchMove(void) const {
        return bEnableTouchMove;
    };
    
    
protected:
    
    // スプライト範囲取得
    
    /** スプライトの範囲を呼び出し、戻り値として返します
     *@param void
     *@return cocos2d::Rect スプライトを取得したRect
     */
    cocos2d::Rect getRect(void) const;
    
protected:
    
    // タッチ判定関連
    
    bool bTouched;
    cocos2d::Vec2 ofstTouchPoint;
    
    
    // タッチ移動有効フラグ
    
    bool bEnableTouchMove;
};

#endif /* CurlingSprite_hpp */
