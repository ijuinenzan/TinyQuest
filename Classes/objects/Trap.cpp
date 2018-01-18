#include "Trap.h"
#include <Define.h>

namespace Tiny
{
	Trap* Trap::create(const cocos2d::Vec2& position, const cocos2d::Size& size)
	{
		Trap *trap = new (std::nothrow) Trap();
		if (trap && trap->init(position, size))
		{
			trap->autorelease();
			return trap;
		}
		CC_SAFE_DELETE(trap);
		return nullptr;
	}

	Trap::Trap()
	{
	}

	Trap::~Trap()
	{
	}

	bool Trap::init(const cocos2d::Vec2& position, const cocos2d::Size& size)
	{
		auto bodyTrap = cocos2d::PhysicsBody::createBox(size, cocos2d::PHYSICSBODY_MATERIAL_DEFAULT);

		bodyTrap->getShape(0)->setRestitution(0.f);
		bodyTrap->getShape(0)->setFriction(0.0f);
		bodyTrap->getShape(0)->setDensity(3.0f);
		bodyTrap->setRotationEnable(false);
		bodyTrap->setDynamic(false);

		this->setTag(TRAP_TAG);

		this->setPhysicsBody(bodyTrap);
		bodyTrap->setContactTestBitmask(0x000001);

		this->setPosition(position);

		return true;
	}
}
