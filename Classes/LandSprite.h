//
//  LandSprite.h
//  Richer
//
//  Created by Macbook Air on 9/1/15.
//
//

#ifndef __Richer__LandSprite__
#define __Richer__LandSprite__

#include "Richer.h"

class LandSprite : public cocos2d::Sprite{
public:
    Position p;                     // 地图系统坐标
    int type;                       // 土地类型
    int streetVal;                  // 街道价值
    int data;                       // 土地数据
    int owner;                      // 土地所有者
    std::vector<Sprite *> objs;     // 土地上的物品, 比如: 炸弹...
    
    static LandSprite *create(int type);
    LandSprite();
    std::string int2Img(int i);             // 地图类型转资源string的帮助方法
    void setUp(int streetVal, Position p);  // 初始化
    
    void levelUp(int who);                  // 升级函数
    void putObj(int what);                  // 放置物品
};

#endif /* defined(__Richer__LandSprite__) */
