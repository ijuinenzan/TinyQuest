#include "Bullet.h"
#include <Define.h>

namespace Tiny
{
	Bullet* Bullet::create(const cocos2d::Vec2& position)
	{
		Bullet *bullet = new (std::nothrow) Bullet();
		if (bullet && bullet->init(position))
		{
			bullet->autorelease();
			return bullet;
		}
		CC_SAFE_DELETE(bullet);
		return nullptr;
	}

	Bullet::Bullet()
	{
	}

	Bullet::~Bullet()
	{
	}

	bool Bullet::init(const cocos2d::Vec2& position)
	{
		if (!initWithFile("Bullet.png"))
		{
			return false;
		}
		auto bodyBullet = cocos2d::PhysicsBody::createBox(cocos2d::Size(20,20), cocos2d::PHYSICSBODY_MATERIAL_DEFAULT);

		bodyBullet->getShape(0)->setRestitution(0.f);
		bodyBullet->getShape(0)->setFriction(0.0f);
		bodyBullet->getShape(0)->setDensity(3.0f);
		bodyBullet->setRotationEnable(false);
		bodyBullet->setDynamic(true);
		bodyBullet->setGravityEnable(false);
		bodyBullet->setVelocity(cocos2d::Vec2(-100, 0));

		this->setTag(BULLET_TAG);

		this->setPhysicsBody(bodyBullet);
		bodyBullet->setContactTestBitmask(0x000001);

		this->setPosition(position);

		this->scheduleUpdate();

		return true;
	}

	void Bullet::update(float dt)
	{
		_physicsBody->setVelocity(cocos2d::Vec2(_physicsBody->getVelocity().x, 0));
		if (_position.x < - cocos2d::Director::getInstance()->getVisibleSize().width)
		{
			this->removeFromParentAndCleanup(true);
		}
	}
}
