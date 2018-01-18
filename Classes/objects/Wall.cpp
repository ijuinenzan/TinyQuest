#include "Wall.h"
#include <Define.h>

namespace Tiny
{
	Wall* Wall::create(const cocos2d::Vec2& position, const cocos2d::Size& size)
	{
		Wall *wall = new (std::nothrow) Wall();
		if (wall && wall->init(position, size))
		{
			wall->autorelease();
			return wall;
		}
		CC_SAFE_DELETE(wall);
		return nullptr;
	}

	Wall::Wall()
	{
	}

	Wall::~Wall()
	{
	}

	bool Wall::init(const cocos2d::Vec2& position, const cocos2d::Size& size)
	{
		auto bodyWall = cocos2d::PhysicsBody::createBox(size, cocos2d::PHYSICSBODY_MATERIAL_DEFAULT);

		bodyWall->getShape(0)->setRestitution(0.f);
		bodyWall->getShape(0)->setFriction(0.0f);
		bodyWall->getShape(0)->setDensity(3.0f);
		bodyWall->setRotationEnable(false);
		bodyWall->setDynamic(false);

		this->setTag(WALL_TAG);

		this->setPhysicsBody(bodyWall);
		bodyWall->setContactTestBitmask(0x000001);

		this->setPosition(position);

		return true;
	}
}
