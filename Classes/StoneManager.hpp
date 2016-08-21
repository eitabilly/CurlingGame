//
//  StoneManager.hpp
//  CurlingGame
//
//  Created by 石田栄太 on 2016/08/02.
//
//
/** 仕様書
 *  このクラスはStoneクラスの管理を行う
 *  このクラスを継承することによって、複数のストーンのスプライトを作成することができるようになる
 *  アクセルマクロの CUR_STONE_MNG はその名の通り、このクラスにアクセスするマクロである
 *  ストーンを複数個読み込み、IDもしくはインデックスを指定してそれぞれを管理する
 */

#ifndef StoneManager_hpp
#define StoneManager_hpp

#include <stdio.h>
#include "Stone.hpp"
#include <list>

//アクセスマクロ
#define CUR_STONE_MNG StoneManager::getInstance()

class StoneManager
{
protected:
    // インスタンス
    static StoneManager* mInstance;
    
    //コンストラクタデストラクタ
    StoneManager();
    virtual ~StoneManager();
    
public:
    /**インスタンス生成
     *
     */
    static void createInstance(void);
    
    /**インスタンス取得
     *
     */
    static StoneManager& getInstance(void);
    
    /**ストーン作成
     *  @param  id  
     *  @param  filename    ストーン画像の名前
     *  @return Stone
     */
    Stone* createUnit(int id, const std::string& filename);
    
    /**ストーン数取得
     *  @return int  ストーンの数
     */
    int getUnitNum(void);
    
    /**ストーン取得（インデックス指定）
     *  @param  idx インデックス
     *  @return その位置にあるStoneまたはnullptr
     */
    Stone* getUnitByIdx(int idx);
    
    /**ストーン取得（ID検索）
     *  @param  id  ID
     *  @return その位置にあるStoneまたはnullptr
     */
    Stone* getUnitById(int id);
    
protected:
    // 構造体によるストーン管理データ
    struct CurlingStoneBox {
        int nId;
        Stone* pStoneUnit;
        CurlingStoneBox() {
            nId = 0;
            pStoneUnit = NULL;
        }
    };
    
    // リスト
    std::list<CurlingStoneBox> lstStoneUnitBox;

};

#endif /* StoneManager_hpp */
