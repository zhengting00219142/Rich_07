//
//  PlayerSprite.h
//  Richer
//
//  Created by Macbook Air on 9/1/15.
//
//

#ifndef __Richer__PlayerSprite__
#define __Richer__PlayerSprite__

#include "Richer.h"
#include "LandSprite.h"

class PlayerSprite : public cocos2d::Sprite{
public:
    // 4 selectable avatar: 0, 1, 2, 3
    Position p;                             // 地图系统坐标
    int facing;                             // 朝向: 顺时间/逆时针
    int cash;                               // 现金
    int ticket;                             // 点数
    int status;                             // 状态: 财神附身, 住院...
    int items[ITEM_KINDS];                  // 道具
    std::vector<LandSprite *> properties;   // 资产
    
    static PlayerSprite *create(int who, int fund);
    PlayerSprite();
    
    void move2Spot(Position dst);           // 移动到
    void purchaseLand(LandSprite *land);    // 购置资产
    void levelupLand(LandSprite *land);     // 升级资产
    
    int getNetWorth();                      // 获得身价
};

#endif /* defined(__Richer__PlayerSprite__) */
