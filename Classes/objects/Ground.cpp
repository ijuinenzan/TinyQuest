#include "Ground.h"
#include <Define.h>

namespace Tiny
{
	Ground* Ground::create(const cocos2d::Vec2& position, const cocos2d::Size& size)
	{
		Ground *ground = new (std::nothrow) Ground();
		if (ground && ground->init(position, size))
		{
			ground->autorelease();
			return ground;
		}
		CC_SAFE_DELETE(ground);
		return nullptr;
	}

	Ground::Ground()
	{
	}

	Ground::~Ground()
	{
	}

	bool Ground::init(const cocos2d::Vec2& position, const cocos2d::Size& size)
	{
		auto bodyGround = cocos2d::PhysicsBody::createBox(size, cocos2d::PHYSICSBODY_MATERIAL_DEFAULT);

		bodyGround->getShape(0)->setRestitution(0.f);
		bodyGround->getShape(0)->setFriction(0.0f);
		bodyGround->getShape(0)->setDensity(3.0f);
		bodyGround->setRotationEnable(false);
		bodyGround->setDynamic(false);

		this->setTag(GROUND_TAG);

		this->setPhysicsBody(bodyGround);
		bodyGround->setContactTestBitmask(0x000001);

		this->setPosition(position);

		return true;
	}
}
