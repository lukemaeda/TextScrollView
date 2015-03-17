//
//  TextScrollScene.cpp
//  TextScrollView
//
//  Created by MAEDAHAJIME on 2015/03/17.
//
//

#include "TextScrollScene.h"

// 名前空間 #define USING_NS_CC using namespace cocos2d
USING_NS_CC;

// _/_/_/ コンストラクタ プロパティー _/_/_/
TextScrollScene::TextScrollScene()
{
    
}

#pragma mark - デストラクタで解放 メモリーリークを防ぐ

// SecondScene デストラクタで解放 メモリーリークを防ぐ
TextScrollScene::~TextScrollScene()
{
    
}

Scene* TextScrollScene::createScene()
{
    // 「シーン」は自動解放オブジェクトです
    auto scene = Scene::create();
    
    // 「レイアウト」は自動解放オブジェクトです
    auto layer = TextScrollScene::create();
    
    // シーンに子としてレイヤーを追加
    scene->addChild(layer);
    
    // シーンを返す
    return scene;
}

#pragma mark - 「INIT」初期化

// 「INIT」初期化
bool TextScrollScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    // 画面の座標関係の詳しい説明はここ http://www.cocos2d-x.org/wiki/Coordinate_System
    // 画面サイズを取得
    Size winSize = Director::getInstance()->getVisibleSize();
    //マルチレゾリューション対応がどうとか
    Point origin = Director::getInstance()->getVisibleOrigin();
    
    // バックグランドカラー
    auto background = LayerColor::create(Color4B::WHITE,
                                         winSize.width,
                                         winSize.height);
    // バックグランドカラー 第2引数は表示順
    this->addChild(background, 0);
    
    
    auto string_txt = "□三脚とレリーズ必須のバルブ撮影です。手持ちでは大変難しいです。\n\n□ピントは花火を打ち上げる場所に合わすようにすれば良いです。または、撮影距離は無限遠（∞マーク）（微妙なピントはファインダーで要確認）。\n\n□ISO100で絞りはF13でWB（ホワイトバランス）は電球モード（青みが増す）を基本に撮りました。\n\n□花火のタイミングはわずかな2秒程度の間隔です。\n\n□構図は、観客を入れて雰囲気を出し花火も全体に収めるように考慮した作品ですが偶然に撮れたもんです。狙って撮影するのも醍醐味があります。\n\n□液晶モニターと花火を見ながらバルブ撮影のレリーズボタンを離すことの繰り返しです。\n\n□カメラ[長秒ノイズ除去]をOFFでRAWでの保存、連続撮影が可能。\n\n□フリーアングル液晶モニターは凄く便利。\n\n□ノイズ等が発生した場合「各メーカーのRAW現像ソフト」で処理。\n\n□RAW＋JPG撮影をしています。RAWだと失敗写真でも何とかなる可能性があります（構図や背景は無理です）\n";
    
    //Scrollview
    auto *scroll = ScrollView::create(winSize);
    // 縦方向だけにスクロール
    scroll->setDirection(ScrollView::Direction::VERTICAL);
    addChild(scroll);
    
    auto label = LabelTTF::create(string_txt, "Arial Rounded MT Bold", 38);
    label->setColor(Color3B::BLACK);
    
    // 文字の開始位置を画面の上に合わせる
    // 文字データは、一番左上から表示させたいので、widthは0
    // heightはコンテンツサイズから画面縦を引いた負数にする
    label->setDimensions(Size(winSize.width,0));
    label->setDimensions(Size(label->getContentSize().width, label->getContentSize().height));
    // 左寄せにする
    label->setHorizontalAlignment(TextHAlignment::LEFT);
    
    // スクロールされるラベルの調整
    scroll->setContainer(label);
    scroll->setContentOffset(Point(0, 0 - (label->getContentSize().height - winSize.height)));

    return true;
}