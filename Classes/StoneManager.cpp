//
//  StoneManager.cpp
//  CurlingGame
//
//  Created by 石田栄太 on 2016/08/02.
//
//

#include "StoneManager.hpp"

USING_NS_CC;

// インスタンス
StoneManager* StoneManager::mInstance = NULL;

// インスタンス生成
void StoneManager::createInstance(void)
{
    mInstance = new StoneManager();
}

// インスタンス取得
StoneManager& StoneManager::getInstance(void)
{
    return *mInstance;
}

StoneManager::StoneManager()
{
    lstStoneUnitBox.clear();
}

StoneManager::~StoneManager()
{
    std::list<CurlingStoneBox>::iterator it = lstStoneUnitBox.begin();
    while(it != lstStoneUnitBox.end()) {
        delete((*it).pStoneUnit);
        it++;
    }
    lstStoneUnitBox.clear();
}

//ストーンの作成
Stone* StoneManager::createUnit(int id, const std::string& filename)
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    CurlingStoneBox unitBox;
    unitBox.nId = id;
    unitBox.pStoneUnit = new Stone(filename);
    unitBox.pStoneUnit->setPosition(Vec2(visibleSize.width/2 + origin.x,200.0f));
    lstStoneUnitBox.push_back(unitBox);
    
    return unitBox.pStoneUnit;
}

//ストーンの数
int StoneManager::getUnitNum(void)
{
    return lstStoneUnitBox.size();
}

//ストーン取得（インデックス指定）
Stone* StoneManager::getUnitByIdx(int idx)
{
    std::list<CurlingStoneBox>::iterator it = lstStoneUnitBox.begin();
    while(it != lstStoneUnitBox.end()) {
        if (idx==0){
            return ((*it).pStoneUnit);
        }
        idx--;
        it++;
    }
    return NULL;
}

//ストーン取得（ID検索）
Stone* StoneManager::getUnitById(int id)
{
    std::list<CurlingStoneBox>::iterator it = lstStoneUnitBox.begin();
    while(it != lstStoneUnitBox.end()) {
        if ((*it).nId==id){
            return ((*it).pStoneUnit);
        }
        it++;
    }
    return NULL;
}
