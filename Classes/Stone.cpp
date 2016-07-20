//
//  Stone.cpp
//  CurlingGame
//
//  Created by 石田栄太 on 2016/07/08.
//
//

#include "Stone.hpp"
#include "Stage.hpp"

USING_NS_CC;

// tag list
#define CHAR_OBJTAG 100

Stone::Stone()
{
    
}

Stone::~Stone()
{
    
}

bool Stone::init()
{
    if(!Layer::init())
    {
        return false;
    }
    
    //画面の大きさを取り出す
    auto winSize = Director::getInstance()->getWinSize();
    
    //ストーン(赤)
    auto sprite = Sprite::create("stone_red.png");
    //スプライトと同じ大きさの剛体を作成する
    auto pyhsicsBody = PhysicsBody::createCircle(40);
    //剛体をSpriteに付ける
    sprite->setPhysicsBody(pyhsicsBody);
    sprite->setTag(CHAR_OBJTAG);
    sprite->setPosition(Vec2(winSize.width / 2.0, 200));
    
    this->addChild(sprite);
    
    
    // Touchイベントを管理しているEventDispatcherインスタンスを取得
    auto eventDispatcher = Director::getInstance()->getEventDispatcher();
    // 登録するリスナー情報を生成
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = CC_CALLBACK_2(Stone::onTouchBegan, this);
    listener->onTouchMoved = CC_CALLBACK_2(Stone::onTouchMoved, this);
    listener->onTouchEnded = CC_CALLBACK_2(Stone::onTouchEnded, this);
    listener->onTouchCancelled = CC_CALLBACK_2(Stone::onTouchCancelled, this);
    // リスナー情報を登録
    eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    
    
    return true;
}

//タッチ開始 最初に１度だけ呼ばれる
bool Stone::onTouchBegan(Touch* touch, Event* event)
{
    // チキンの矩形情報を求める
    auto* charSprite = (Sprite*)this->getChildByTag(CHAR_OBJTAG);
    Point point = charSprite->getPosition();
    int width = charSprite->getContentSize().width;
    int height = charSprite->getContentSize().height;
    Rect charSpriteRect = Rect(point.x - (width / 2), point.y - (height / 2), width,height);
    //タッチの位置を取得
    auto tPos = touch->getLocation();
    // タッチ位置がチキン矩形内か判定
    if ( charSpriteRect.containsPoint(tPos) == true )
    {// チキンがタッチされた！
        CCLOG("stone pushed");
        // ここに処理をいろいろと書くのだよ。
        return true;
    }
    // ここまで処理が来たということはチキンがタッチされなかったということ。
    // falseを返すと以降のタッチイベントは呼ばれない
    return true;
}
// ドラッグする最中ずっと呼ばれる
void Stone::onTouchMoved(Touch* touch, Event* event)
{
}
// タッチを離すと呼ばれる
void Stone::onTouchEnded(Touch* touch, Event* event)
{
}
// タッチがキャンセルされると呼ばれる
void Stone::onTouchCancelled(Touch* touch, Event* event)
{
    // キャンセル時も一応線を削除
}