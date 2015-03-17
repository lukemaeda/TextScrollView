//
//  TextScrollScene.h
//  TextScrollView
//
//  Created by MAEDAHAJIME on 2015/03/17.
//
//

#ifndef __TextScrollView__TextScrollScene__
#define __TextScrollView__TextScrollScene__

#include "cocos2d.h"
#include "extensions/cocos-ext.h"
USING_NS_CC_EXT;

// 名前空間 #define USING_NS_CC using namespace cocos2d
USING_NS_CC;

class TextScrollScene : public cocos2d::Layer
{
public:
    
    // コンストラクタ
    TextScrollScene();
    // デストラクタ
    virtual ~TextScrollScene();
    
    // 初期化のメソッド
    virtual bool init();
    
    static cocos2d::Scene* createScene();
    
    // create()を使えるようにしている。
    CREATE_FUNC(TextScrollScene);
};

#endif /* defined(__TextScrollView__TextScrollScene__) */
