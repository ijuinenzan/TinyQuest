#include "Actor.h"
#include "cocos/cocos2d.h"

namespace Tiny
{
	Actor* Actor::create()
	{
		Actor *actor = new (std::nothrow) Actor();
		if (actor && actor->init())
		{
			actor->autorelease();
			return actor;
		}
		CC_SAFE_DELETE(actor);
		return nullptr;
	}

	Actor* Actor::create(const std::string& filename)
	{
		Actor *actor = new (std::nothrow) Actor();
		if (actor && actor->initWithFile(filename))
		{
			actor->autorelease();
			return actor;
		}
		CC_SAFE_DELETE(actor);
		return nullptr;
	}

	Actor* Actor::createWithSpriteFrame(cocos2d::SpriteFrame* spriteFrame)
	{
		Actor *actor = new (std::nothrow) Actor();
		if (actor && spriteFrame && actor->initWithSpriteFrame(spriteFrame))
		{
			actor->autorelease();
			return actor;
		}
		CC_SAFE_DELETE(actor);
		return nullptr;
	}

	Actor* Actor::createWithSpriteFrameName(const std::string& spriteFrameName)
	{
		cocos2d::SpriteFrame *frame = cocos2d::SpriteFrameCache::getInstance()->getSpriteFrameByName(spriteFrameName);

#if COCOS2D_DEBUG > 0
		char msg[256] = { 0 };
		sprintf(msg, "Invalid spriteFrameName: %s", spriteFrameName.c_str());
		CCASSERT(frame != nullptr, msg);
#endif

		return createWithSpriteFrame(frame);
	}

	void Actor::update(float delta)
	{
		_stateMachine->updateWithDeltaTime(delta);
	}

	bool Actor::init()
	{
		_stateMachine = StateMachine::create();
		this->scheduleUpdate();
		initWithTexture(nullptr, cocos2d::Rect::ZERO);

		return true;
	}

	bool Actor::initWithFile(const std::string& filename)
	{
		_stateMachine = StateMachine::create();
		this->scheduleUpdate();
		if (filename.empty())
		{
			CCLOG("Call Sprite::initWithFile with blank resource filename.");
			return false;
		}

		_fileName = filename;
		_fileType = 0;

		cocos2d::Texture2D *texture = _director->getTextureCache()->addImage(filename);
		if (texture)
		{
			cocos2d::Rect rect = cocos2d::Rect::ZERO;
			rect.size = texture->getContentSize();
			return initWithTexture(texture, rect);
		}

		// don't release here.
		// when load texture failed, it's better to get a "transparent" sprite then a crashed program
		// this->release();
		return false;
	}

	

	bool Actor::initWithSpriteFrame(cocos2d::SpriteFrame* spriteFrame)
	{
		_stateMachine = StateMachine::create();
		this->scheduleUpdate();
		CCASSERT(spriteFrame != nullptr, "spriteFrame can't be nullptr!");
		if (spriteFrame == nullptr)
		{
			return false;
		}

		this->scheduleUpdate();

		bool ret = initWithTexture(spriteFrame->getTexture(), spriteFrame->getRect(), spriteFrame->isRotated());
		setSpriteFrame(spriteFrame);

		return ret;
	}

	

	bool Actor::initWithSpriteFrameName(const std::string& spriteFrameName)
	{
		_stateMachine = StateMachine::create();
		this->scheduleUpdate();
		CCASSERT(!spriteFrameName.empty(), "Invalid spriteFrameName");
		if (spriteFrameName.empty())
		{
			return false;
		}

		_fileName = spriteFrameName;
		_fileType = 1;

		cocos2d::SpriteFrame *frame = cocos2d::SpriteFrameCache::getInstance()->getSpriteFrameByName(spriteFrameName);
		return initWithSpriteFrame(frame);
	}



	Actor::Actor()
		:_stateMachine(nullptr)
	{
	}

	Actor::~Actor()
	{
		delete(_stateMachine);
	}
}
