// ---------------------------------------
// Sprite definitions for TinyAnimations
// Generated with TexturePacker 4.5.0
//
// https://www.codeandweb.com/texturepacker
// 
// $TexturePacker:SmartUpdate:7e3da7627535dd94abd2f182845df3b9:cb1cbf700c83e309abf23fa34c0815b1:b86c838739b06696d7f5de3fa3f25258$
// ---------------------------------------

#ifndef __TINYANIMATIONS_H__
#define __TINYANIMATIONS_H__

#include "cocos2d.h"

namespace TexturePacker
{

class TinyAnimations
{
public:
    /**
     * Add sprite frames contained in theTinyAnimations sheet to
     * the SpriteFrameCache.
     */
    static void addSpriteFramesToCache();

    /**
     * Remove sprite frames contained in theTinyAnimations sheet from
     * the SpriteFrameCache.
     */
    static void removeSpriteFramesFromCache();

    // ---------------------
    // sprite name constants
    // ---------------------
    static const std::string idleLeftMoveLeft0;
    static const std::string idleRightMoveRight0;
    static const std::string jumpLeftJumpLeft0;
    static const std::string jumpLeftJumpLeft1;
    static const std::string jumpRightJumpRight0;
    static const std::string jumpRightJumpRight1;
    static const std::string moveAheadMoveAhead0;
    static const std::string moveAheadMoveAhead1;
    static const std::string moveAheadMoveAhead2;
    static const std::string moveLeftMoveLeft0;
    static const std::string moveLeftMoveLeft1;
    static const std::string moveLeftMoveLeft2;
    static const std::string moveRightMoveRight0;
    static const std::string moveRightMoveRight1;
    static const std::string moveRightMoveRight2;

    // --------------
    // Sprite objects
    // --------------
    static cocos2d::Sprite *createIdleLeftMoveLeft0Sprite();
    static cocos2d::Sprite *createIdleRightMoveRight0Sprite();
    static cocos2d::Sprite *createJumpLeftJumpLeft0Sprite();
    static cocos2d::Sprite *createJumpLeftJumpLeft1Sprite();
    static cocos2d::Sprite *createJumpRightJumpRight0Sprite();
    static cocos2d::Sprite *createJumpRightJumpRight1Sprite();
    static cocos2d::Sprite *createMoveAheadMoveAhead0Sprite();
    static cocos2d::Sprite *createMoveAheadMoveAhead1Sprite();
    static cocos2d::Sprite *createMoveAheadMoveAhead2Sprite();
    static cocos2d::Sprite *createMoveLeftMoveLeft0Sprite();
    static cocos2d::Sprite *createMoveLeftMoveLeft1Sprite();
    static cocos2d::Sprite *createMoveLeftMoveLeft2Sprite();
    static cocos2d::Sprite *createMoveRightMoveRight0Sprite();
    static cocos2d::Sprite *createMoveRightMoveRight1Sprite();
    static cocos2d::Sprite *createMoveRightMoveRight2Sprite();

    // ----------------
    // animation frames
    // ----------------
    static cocos2d::Vector<cocos2d::SpriteFrame*> getJUMPLEFT_JUMPLEFTAnimationFrames();
    static cocos2d::Vector<cocos2d::SpriteFrame*> getJUMPRIGHT_JUMPRIGHTAnimationFrames();
    static cocos2d::Vector<cocos2d::SpriteFrame*> getMOVEAHEAD_MOVEAHEADAnimationFrames();
    static cocos2d::Vector<cocos2d::SpriteFrame*> getMOVELEFT_MOVELEFTAnimationFrames();
    static cocos2d::Vector<cocos2d::SpriteFrame*> getMOVERIGHT_MOVERIGHTAnimationFrames();

    // ---------------
    // animate actions
    // ---------------
    static cocos2d::Animate *createJUMPLEFT_JUMPLEFTAnimateAction(float delay, unsigned int loops = 1);
    static cocos2d::Animate *createJUMPRIGHT_JUMPRIGHTAnimateAction(float delay, unsigned int loops = 1);
    static cocos2d::Animate *createMOVEAHEAD_MOVEAHEADAnimateAction(float delay, unsigned int loops = 1);
    static cocos2d::Animate *createMOVELEFT_MOVELEFTAnimateAction(float delay, unsigned int loops = 1);
    static cocos2d::Animate *createMOVERIGHT_MOVERIGHTAnimateAction(float delay, unsigned int loops = 1);

}; // class

}; // namespace

#endif // __TINYANIMATIONS_H__
