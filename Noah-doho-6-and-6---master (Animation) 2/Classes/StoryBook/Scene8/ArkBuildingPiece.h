//
//  ArkBuildingPiece.h
//  Noah360
//
//  Created by Neil D on 03/10/13.
//
//

#ifndef __Noah360__ArkBuildingPiece__
#define __Noah360__ArkBuildingPiece__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;
class ArkBuildingPiece: public cocos2d::CCNode,public CCTargetedTouchDelegate
{
    public:
        static ArkBuildingPiece* create(CCString *name,CCString *letter,CCPoint spos,CCPoint bcpos, CCPoint fcpos,CCObject *obj,SEL_CallFuncO selector);
        bool initArkBuildingPiece(CCString *name,CCString *letter,CCPoint spos,CCPoint bcpos, CCPoint fcpos,CCObject *obj,SEL_CallFuncO selector);
        ArkBuildingPiece();
        virtual ~ArkBuildingPiece();
        virtual void onEnter();
        virtual void onExit();
    float scalefactor;
        CCString* arkPieceName;
        CCString* arkPieceLetter;
        int arkPieceNumber;
        CCSprite* image;
        CCPoint startPosition;
        CCPoint finishedCorrectPosition;
        CCPoint blockCorrectPosition;
        CCSize size;
        bool isEnabled;
        bool isDrag;
        CCPoint whereTouch;
        CC_SYNTHESIZE(bool, isCorrect, isCorrect);
        CC_SYNTHESIZE_RETAIN(CCSprite*, wire, wire);

        unsigned int piece_to_place;
        SEL_CallFuncO   callback_selector;
        CCObject *parent;
        //CCPoint getPointRelativeToDesignWireframe(CCSize wireframeDimensions, RelativeToType relativeTo, CCPoint point);
        virtual bool ccTouchBegan(CCTouch* touch, CCEvent* event);
        virtual void ccTouchMoved(CCTouch* touch, CCEvent* event);
        virtual void ccTouchEnded(CCTouch* touch, CCEvent* event);
    
    public:
        void tick(float  dt);
        void EnablePiece();
        void ShowPainted();
        void stopSwallingTouchs();
        void SetWirePosition(CCPoint pos ,CCSize screenSize);
    private:
        cocos2d::extension::CCBAnimationManager *mAnimationManager;

};
#endif /* defined(__Noah360__ArkBuildingPiece__) */
