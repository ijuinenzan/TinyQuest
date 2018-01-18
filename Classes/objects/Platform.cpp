#include "Platform.h"
#include <Define.h>

namespace Tiny
{
	Platform* Platform::create(const cocos2d::Vec2& position, const cocos2d::Size& size, const float minX, const float maxX)
	{
		Platform *platform = new (std::nothrow) Platform();
		if (platform && platform->init(position, size, minX, maxX))
		{
			platform->autorelease();
			return platform;
		}
		CC_SAFE_DELETE(platform);
		return nullptr;
	}

	Platform::Platform()
		:_minX(0), _maxX(0)
	{
	}

	Platform::~Platform()
	{
	}

	bool Platform::init(const cocos2d::Vec2& position, const cocos2d::Size& size, const float minX, const float maxX)
	{
		if(!initWithFile("Platform.png"))
		{
			return false;
		}
		_minX = minX;
		_maxX = maxX;
		auto bodyPlatform = cocos2d::PhysicsBody::createBox(size, cocos2d::PHYSICSBODY_MATERIAL_DEFAULT);

		bodyPlatform->getShape(0)->setRestitution(0.f);
		bodyPlatform->getShape(0)->setFriction(0.0f);
		bodyPlatform->getShape(0)->setDensity(3.0f);
		bodyPlatform->setRotationEnable(false);
		bodyPlatform->setDynamic(true);
		bodyPlatform->setGravityEnable(false);
		bodyPlatform->setVelocity(cocos2d::Vec2(100, 0));

		this->setTag(PLATFORM_TAG);

		this->setPhysicsBody(bodyPlatform);
		bodyPlatform->setContactTestBitmask(0x000001);

		this->setPosition(position);

		this->scheduleUpdate();

		return true;
	}

	void Platform::update(float dt)
	{
		_physicsBody->setVelocity(cocos2d::Vec2(_physicsBody->getVelocity().x, 0));
		if(_position.x < _minX)
		{
			this->_physicsBody->setVelocity(cocos2d::Vec2(100, 0));
		}
		if(_position.x > _maxX)
		{
			this->_physicsBody->setVelocity(cocos2d::Vec2(-100, 0));
		}
	}
}
