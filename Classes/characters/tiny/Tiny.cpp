#include "Tiny.h"
#include "TinyAnimations.hpp"
#include "TinyIdleState.h"
#include "TinyMoveRightState.h"
#include "TinyMoveLeftState.h"
#include "TinyJumpRightState.h"

#include "Define.h"
#include "TinyJumpLeftState.h"
#include "TinyJumpState.h"


namespace Tiny
{
	Tiny* Tiny::create(const cocos2d::Vec2& initialPosition)
	{
		Tiny *tiny = new (std::nothrow) Tiny();
		if (tiny && tiny->init(initialPosition))
		{
			tiny->autorelease();
			return tiny;
		}
		CC_SAFE_DELETE(tiny);
		return nullptr;
	}

	Tiny::Tiny()
		:_isLeftPressed(false), _isRightPressed(false), _isSpacePressed(false), _isTouchingGround(false), _isRespawning(false)
	{
	}

	Tiny::~Tiny()
	{
	}

	bool Tiny::init(const cocos2d::Vec2& initialPosition)
	{
		_initialPosition = initialPosition;
		TexturePacker::TinyAnimations::addSpriteFramesToCache();
		if(!initWithSpriteFrameName(TexturePacker::TinyAnimations::idleRightMoveRight0))
		{
			return false;
		}
		this->setTag(TINY_TAG);
		_body = cocos2d::PhysicsBody::createBox(cocos2d::Size(24, 28), cocos2d::PHYSICSBODY_MATERIAL_DEFAULT);

		_body->getShape(0)->setRestitution(1.0f);
		_body->getShape(0)->setFriction(0.0f);
		_body->getShape(0)->setDensity(1.0f);
		_body->setRotationEnable(false);
		_body->setDynamic(true);

		auto contactListener = cocos2d::EventListenerPhysicsContact::create();
		contactListener->onContactBegin = [=](cocos2d::PhysicsContact& contact) {
			auto a = contact.getShapeA()->getBody()->getNode();
			auto b = contact.getShapeB()->getBody()->getNode();

			if (a == nullptr || b == nullptr)
			{
				return false;
			}

			if (a->getTag() == TINY_TAG && b->getTag() == ENEMY_TAG
				|| b->getTag() == TINY_TAG && a->getTag() == ENEMY_TAG)
			{
				return false;
			}

			if (a->getTag() == TINY_TAG && b->getTag() == COIN_TAG
				|| b->getTag() == TINY_TAG && a->getTag() == COIN_TAG)
			{
				return false;
			}

			if(a->getTag() == BULLET_TAG || b->getTag() == BULLET_TAG)
			{
				if(a->getTag() == GROUND_TAG || b->getTag() == GROUND_TAG || a->getTag() == TINY_TAG || b->getTag() == TINY_TAG)
				{
					if(a->getTag() == BULLET_TAG)
					{
						if (!static_cast<Sprite*>(b)->isVisible())
						{
							return false;
						}
						a->removeFromParent();
						if(b->getTag() == TINY_TAG)
						{

							const auto particle = cocos2d::ParticleExplosion::create();
							particle->setTotalParticles(1000);
							particle->setPosition(this->getPosition());
							this->getScene()->addChild(particle);

							auto action = cocos2d::Sequence::create(cocos2d::DelayTime::create(1.f), cocos2d::CallFunc::create([=]
							{
								this->setVisible(true);
								//this->setPhysicsBody(_body);
								this->setPosition(_initialPosition);
								this->getPhysicsBody()->setVelocity(cocos2d::Vec2(0, 0));
								_isTouchingGround = true;
								_isRespawning = false;

							}), nullptr);
							action->setTag(1);
							this->runAction(action);
							this->setVisible(false);
							_isLeftPressed = false;
							_isRightPressed = false;
							_stateMachine->setState<TinyIdleState>();
							_isRespawning = true;
							this->setPosition(_initialPosition);
							this->getPhysicsBody()->setVelocity(cocos2d::Vec2(0, 0));
						}
					}
					else if(b->getTag() == BULLET_TAG)
					{
						if (!static_cast<Sprite*>(a)->isVisible())
						{
							return false;
						}
						b->removeFromParent();
						if (a->getTag() == TINY_TAG)
						{

							const auto particle = cocos2d::ParticleExplosion::create();
							particle->setTotalParticles(1000);
							particle->setPosition(this->getPosition());
							this->getScene()->addChild(particle);

							auto action = cocos2d::Sequence::create(cocos2d::DelayTime::create(1.f), cocos2d::CallFunc::create([=]
							{
								this->setVisible(true);
								//this->setPhysicsBody(_body);
								this->setPosition(_initialPosition);
								this->getPhysicsBody()->setVelocity(cocos2d::Vec2(0, 0));
								_isTouchingGround = true;
								_isRespawning = false;

							}), nullptr);
							action->setTag(1);
							this->runAction(action);
							this->setVisible(false);
							_isLeftPressed = false;
							_isRightPressed = false;
							_stateMachine->setState<TinyIdleState>();
							_isRespawning = true;
							//this->setPhysicsBody(NULL);
							this->setPosition(_initialPosition);
							this->getPhysicsBody()->setVelocity(cocos2d::Vec2(0, 0));
						}
					}

					return true;
				}
			}

			if (a->getTag() == TINY_TAG && b->getTag() == TRAP_TAG
				|| b->getTag() == TINY_TAG && a->getTag() == TRAP_TAG)
			{
				if(a->getTag() == TINY_TAG && !static_cast<Sprite*>(a)->isVisible())
				{
					return false;
				}
				if (b->getTag() == TINY_TAG && !static_cast<Sprite*>(b)->isVisible())
				{
					return false;
				}
				const auto particle = cocos2d::ParticleExplosion::create();
				particle->setTotalParticles(1000);
				particle->setPosition(this->getPosition());
				this->getScene()->addChild(particle);

				auto action = cocos2d::Sequence::create(cocos2d::DelayTime::create(1.f), cocos2d::CallFunc::create([=]
				{
					this->setVisible(true);
					//this->setPhysicsBody(_body);
					this->setPosition(_initialPosition);
					this->getPhysicsBody()->setVelocity(cocos2d::Vec2(0, 0));
					_isTouchingGround = true;
					_isRespawning = false;

				}), nullptr);
				action->setTag(1);
				this->runAction(action);
				this->setVisible(false);
				_isLeftPressed = false;
				_isRightPressed = false;
				_stateMachine->setState<TinyIdleState>();
				_isRespawning = true;
				//this->setPhysicsBody(NULL);
				this->setPosition(_initialPosition);
				this->getPhysicsBody()->setVelocity(cocos2d::Vec2(0, 0));



				return true;
			}

			if(contact.getContactData()->normal.x == -1 || contact.getContactData()->normal.x == 1)
			{
				return true;
			}



			if (a->getTag() == TINY_TAG && (b->getTag() == GROUND_TAG || b->getTag() == PLATFORM_TAG)
				|| b->getTag() == TINY_TAG && (a->getTag() == GROUND_TAG || a->getTag() == PLATFORM_TAG))
			{
				_isTouchingGround = true;

				if(b->getTag() == PLATFORM_TAG || a->getTag() == PLATFORM_TAG)
				{
					_physicsBody->setGravityEnable(false);
				}
			}



			return true;
		};

		contactListener->onContactSeparate = [=](cocos2d::PhysicsContact& contact) {
			auto a = contact.getShapeA()->getBody()->getNode();
			auto b = contact.getShapeB()->getBody()->getNode();

			if (a == nullptr || b == nullptr)
			{
				return;
			}

			if (a->getTag() == TINY_TAG && (b->getTag() == GROUND_TAG || b->getTag() == PLATFORM_TAG)
				|| b->getTag() == TINY_TAG && (a->getTag() == GROUND_TAG || a->getTag() == PLATFORM_TAG))
			{
				_isTouchingGround = false;

				if (contact.getContactData()->normal.x == -1 || contact.getContactData()->normal.x == 1)
				{
					return;
				}

				if (b->getTag() == PLATFORM_TAG || a->getTag() == PLATFORM_TAG)
				{
					_physicsBody->setGravityEnable(true);
				}
			}
		};


		this->setPhysicsBody(_body);
		_body->setContactTestBitmask(0x000001);

		auto keyboardListener = cocos2d::EventListenerKeyboard::create();
		keyboardListener->onKeyPressed = CC_CALLBACK_2(Tiny::onKeyPressed, this);
		keyboardListener->onKeyReleased = CC_CALLBACK_2(Tiny::onKeyReleased, this);
		_eventDispatcher->addEventListenerWithSceneGraphPriority(keyboardListener, this);

		_stateMachine->addState<TinyIdleState>(this);
		_stateMachine->addState<TinyMoveRightState>(this);
		_stateMachine->addState<TinyMoveLeftState>(this);
		_stateMachine->addState<TinyJumpRightState>(this);
		_stateMachine->addState<TinyJumpLeftState>(this);
		_stateMachine->addState<TinyJumpState>(this);
		_stateMachine->enterState<TinyIdleState>();

		_eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);

		setPosition(_initialPosition);

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
		if (_isRespawning)
		{
			return;
		}
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
		if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_SPACE) 
		{
			_isSpacePressed = false;
		}
	}
}
