#include "Tiny.h"
#include "TinyAnimations.hpp"
#include "TinyIdleState.h"
#include "TinyMoveRightState.h"
#include "TinyMoveLeftState.h"
#include "TinyJumpRightState.h"

#include "Define.h"


namespace Tiny
{
	Tiny* Tiny::create()
	{
		Tiny *tiny = new (std::nothrow) Tiny();
		if (tiny && tiny->init())
		{
			tiny->autorelease();
			return tiny;
		}
		CC_SAFE_DELETE(tiny);
		return nullptr;
	}

	Tiny::Tiny()
		:_isLeftPressed(false), _isRightPressed(false), _isSpacePressed(false)
	{
	}

	Tiny::~Tiny()
	{
	}

	bool Tiny::init()
	{
		TexturePacker::TinyAnimations::addSpriteFramesToCache();
		if(!initWithSpriteFrameName(TexturePacker::TinyAnimations::idleRightMoveRight0))
		{
			return false;
		}
		this->setTag(TINY_TAG);
		auto bodyTiny = cocos2d::PhysicsBody::createBox(cocos2d::Size(24, 28), cocos2d::PHYSICSBODY_MATERIAL_DEFAULT);

		bodyTiny->getShape(0)->setRestitution(1.0f);
		bodyTiny->getShape(0)->setFriction(0.0f);
		bodyTiny->getShape(0)->setDensity(1.0f);
		bodyTiny->setRotationEnable(false);
		bodyTiny->setDynamic(true);

		auto contactListener = cocos2d::EventListenerPhysicsContact::create();
		contactListener->onContactBegin = [=](cocos2d::PhysicsContact& contact) {
			auto a = contact.getShapeA()->getBody()->getNode();
			auto b = contact.getShapeB()->getBody()->getNode();

			if (a->getTag() == TINY_TAG && b->getTag() == GROUND_TAG
				|| b->getTag() == TINY_TAG && a->getTag() == GROUND_TAG)
			{
				_isTouchingGround = true;
			}

			return true;
		};

		contactListener->onContactSeparate = [=](cocos2d::PhysicsContact& contact) {
			auto a = contact.getShapeA()->getBody()->getNode();
			auto b = contact.getShapeB()->getBody()->getNode();

			if (a->getTag() == TINY_TAG && b->getTag() == GROUND_TAG
				|| b->getTag() == TINY_TAG && a->getTag() == GROUND_TAG)
			{
				_isTouchingGround = false;
			}
		};


		this->setPhysicsBody(bodyTiny);
		bodyTiny->setContactTestBitmask(0x000001);

		auto keyboardListener = cocos2d::EventListenerKeyboard::create();
		keyboardListener->onKeyPressed = CC_CALLBACK_2(Tiny::onKeyPressed, this);
		keyboardListener->onKeyReleased = CC_CALLBACK_2(Tiny::onKeyReleased, this);
		_eventDispatcher->addEventListenerWithSceneGraphPriority(keyboardListener, this);

		_stateMachine->addState<TinyIdleState>(this);
		_stateMachine->addState<TinyMoveRightState>(this);
		_stateMachine->addState<TinyMoveLeftState>(this);
		_stateMachine->addState<TinyJumpRightState>(this);
		_stateMachine->enterState<TinyIdleState>();

		_eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);

		return true;
	}

	bool Tiny::isLeftPressed() const
	{
		return _isLeftPressed;
	}

	bool Tiny::isRightPressed() const
	{
		return _isRightPressed;
	}

	bool Tiny::isSpacePressed() const
	{
		return _isSpacePressed;
	}

	bool Tiny::isTouchingGround() const
	{
		
		return _isTouchingGround;
	}

	void Tiny::onKeyPressed(const cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event)
	{
		if(keyCode == cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW)
		{
			_isLeftPressed = true;
		}

		if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW)
		{
			_isRightPressed = true;
		}
		if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_SPACE) {
			_isSpacePressed = true;
		}
	}

	void Tiny::onKeyReleased(const cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event)
	{
		if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW)
		{
			_isLeftPressed = false;
		}

		if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW)
		{
			_isRightPressed = false;
		}
		if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_SPACE) {
			_isSpacePressed = false;
		}
	}
}
