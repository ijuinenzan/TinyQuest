// ---------------------------------------
// Sprite definitions for TinyAnimations
// Generated with TexturePacker 4.5.0
//
// https://www.codeandweb.com/texturepacker
// ---------------------------------------

#include "TinyAnimations.hpp"

USING_NS_CC;

namespace TexturePacker
{

void TinyAnimations::addSpriteFramesToCache()
{
    SpriteFrameCache *cache = SpriteFrameCache::getInstance();
    cache->addSpriteFramesWithFile("Tiny.plist");
};

void TinyAnimations::removeSpriteFramesFromCache()
{
    SpriteFrameCache *cache = SpriteFrameCache::getInstance();
    cache->removeSpriteFramesFromFile("Tiny.plist");
};


// ---------------------
// sprite name constants
// ---------------------
const std::string TinyAnimations::idleLeftMoveLeft0   = "IdleLeft/MoveLeft0.png";
const std::string TinyAnimations::idleRightMoveRight0 = "IdleRight/MoveRight0.png";
const std::string TinyAnimations::jumpLeftJumpLeft0   = "JumpLeft/JumpLeft0.png";
const std::string TinyAnimations::jumpLeftJumpLeft1   = "JumpLeft/JumpLeft1.png";
const std::string TinyAnimations::jumpRightJumpRight0 = "JumpRight/JumpRight0.png";
const std::string TinyAnimations::jumpRightJumpRight1 = "JumpRight/JumpRight1.png";
const std::string TinyAnimations::moveAheadMoveAhead0 = "MoveAhead/MoveAhead0.png";
const std::string TinyAnimations::moveAheadMoveAhead1 = "MoveAhead/MoveAhead1.png";
const std::string TinyAnimations::moveAheadMoveAhead2 = "MoveAhead/MoveAhead2.png";
const std::string TinyAnimations::moveLeftMoveLeft0   = "MoveLeft/MoveLeft0.png";
const std::string TinyAnimations::moveLeftMoveLeft1   = "MoveLeft/MoveLeft1.png";
const std::string TinyAnimations::moveLeftMoveLeft2   = "MoveLeft/MoveLeft2.png";
const std::string TinyAnimations::moveRightMoveRight0 = "MoveRight/MoveRight0.png";
const std::string TinyAnimations::moveRightMoveRight1 = "MoveRight/MoveRight1.png";
const std::string TinyAnimations::moveRightMoveRight2 = "MoveRight/MoveRight2.png";

// ---------------------------------------------------------
// convenience functions returing pointers to Sprite objects
// ---------------------------------------------------------
Sprite* TinyAnimations::createIdleLeftMoveLeft0Sprite()
{
    return Sprite::createWithSpriteFrameName(idleLeftMoveLeft0);
}

Sprite* TinyAnimations::createIdleRightMoveRight0Sprite()
{
    return Sprite::createWithSpriteFrameName(idleRightMoveRight0);
}

Sprite* TinyAnimations::createJumpLeftJumpLeft0Sprite()
{
    return Sprite::createWithSpriteFrameName(jumpLeftJumpLeft0);
}

Sprite* TinyAnimations::createJumpLeftJumpLeft1Sprite()
{
    return Sprite::createWithSpriteFrameName(jumpLeftJumpLeft1);
}

Sprite* TinyAnimations::createJumpRightJumpRight0Sprite()
{
    return Sprite::createWithSpriteFrameName(jumpRightJumpRight0);
}

Sprite* TinyAnimations::createJumpRightJumpRight1Sprite()
{
    return Sprite::createWithSpriteFrameName(jumpRightJumpRight1);
}

Sprite* TinyAnimations::createMoveAheadMoveAhead0Sprite()
{
    return Sprite::createWithSpriteFrameName(moveAheadMoveAhead0);
}

Sprite* TinyAnimations::createMoveAheadMoveAhead1Sprite()
{
    return Sprite::createWithSpriteFrameName(moveAheadMoveAhead1);
}

Sprite* TinyAnimations::createMoveAheadMoveAhead2Sprite()
{
    return Sprite::createWithSpriteFrameName(moveAheadMoveAhead2);
}

Sprite* TinyAnimations::createMoveLeftMoveLeft0Sprite()
{
    return Sprite::createWithSpriteFrameName(moveLeftMoveLeft0);
}

Sprite* TinyAnimations::createMoveLeftMoveLeft1Sprite()
{
    return Sprite::createWithSpriteFrameName(moveLeftMoveLeft1);
}

Sprite* TinyAnimations::createMoveLeftMoveLeft2Sprite()
{
    return Sprite::createWithSpriteFrameName(moveLeftMoveLeft2);
}

Sprite* TinyAnimations::createMoveRightMoveRight0Sprite()
{
    return Sprite::createWithSpriteFrameName(moveRightMoveRight0);
}

Sprite* TinyAnimations::createMoveRightMoveRight1Sprite()
{
    return Sprite::createWithSpriteFrameName(moveRightMoveRight1);
}

Sprite* TinyAnimations::createMoveRightMoveRight2Sprite()
{
    return Sprite::createWithSpriteFrameName(moveRightMoveRight2);
}


// ------------------------------------------------
// convenience functions returning animation frames
// ------------------------------------------------

Vector<SpriteFrame*> TinyAnimations::getJUMPLEFT_JUMPLEFTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(2);
    frames.pushBack(frameCache->getSpriteFrameByName(jumpLeftJumpLeft0));
    frames.pushBack(frameCache->getSpriteFrameByName(jumpLeftJumpLeft1));
    return frames;
}

Vector<SpriteFrame*> TinyAnimations::getJUMPRIGHT_JUMPRIGHTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(2);
    frames.pushBack(frameCache->getSpriteFrameByName(jumpRightJumpRight0));
    frames.pushBack(frameCache->getSpriteFrameByName(jumpRightJumpRight1));
    return frames;
}

Vector<SpriteFrame*> TinyAnimations::getMOVEAHEAD_MOVEAHEADAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(3);
    frames.pushBack(frameCache->getSpriteFrameByName(moveAheadMoveAhead0));
    frames.pushBack(frameCache->getSpriteFrameByName(moveAheadMoveAhead1));
    frames.pushBack(frameCache->getSpriteFrameByName(moveAheadMoveAhead2));
    return frames;
}

Vector<SpriteFrame*> TinyAnimations::getMOVELEFT_MOVELEFTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(3);
    frames.pushBack(frameCache->getSpriteFrameByName(moveLeftMoveLeft0));
    frames.pushBack(frameCache->getSpriteFrameByName(moveLeftMoveLeft1));
    frames.pushBack(frameCache->getSpriteFrameByName(moveLeftMoveLeft2));
    return frames;
}

Vector<SpriteFrame*> TinyAnimations::getMOVERIGHT_MOVERIGHTAnimationFrames()
{
    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> frames;
    frames.reserve(3);
    frames.pushBack(frameCache->getSpriteFrameByName(moveRightMoveRight0));
    frames.pushBack(frameCache->getSpriteFrameByName(moveRightMoveRight1));
    frames.pushBack(frameCache->getSpriteFrameByName(moveRightMoveRight2));
    return frames;
}


// ----------
// animations
// ----------

Animate *TinyAnimations::createJUMPLEFT_JUMPLEFTAnimateAction(float delay, unsigned int loops)
{
	const auto animation = Animate::create(Animation::createWithSpriteFrames(getJUMPLEFT_JUMPLEFTAnimationFrames(), delay, loops));
	animation->setTag(0);
	return animation;
}
Animate *TinyAnimations::createJUMPRIGHT_JUMPRIGHTAnimateAction(float delay, unsigned int loops)
{
	const auto animation = Animate::create(Animation::createWithSpriteFrames(getJUMPRIGHT_JUMPRIGHTAnimationFrames(), delay, loops));
	animation->setTag(0);
	return animation;
}
Animate *TinyAnimations::createMOVEAHEAD_MOVEAHEADAnimateAction(float delay, unsigned int loops)
{
	const auto animation = Animate::create(Animation::createWithSpriteFrames(getMOVEAHEAD_MOVEAHEADAnimationFrames(), delay, loops));
	animation->setTag(0);
	return animation;
}
Animate *TinyAnimations::createMOVELEFT_MOVELEFTAnimateAction(float delay, unsigned int loops)
{
	const auto animation = Animate::create(Animation::createWithSpriteFrames(getMOVELEFT_MOVELEFTAnimationFrames(), delay, loops));
	animation->setTag(0);
	return animation;
}
Animate *TinyAnimations::createMOVERIGHT_MOVERIGHTAnimateAction(float delay, unsigned int loops)
{
	const auto animation = Animate::create(Animation::createWithSpriteFrames(getMOVERIGHT_MOVERIGHTAnimationFrames(), delay, loops));
	animation->setTag(0);
	return animation;
}

}; // namespace

