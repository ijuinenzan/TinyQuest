#include "Coin.h"
#include <Define.h>

namespace Tiny
{
	Coin* Coin::create(const cocos2d::Vec2& position)
	{
		Coin *coin = new (std::nothrow) Coin();
		if (coin && coin->init(position))
		{
			coin->autorelease();
			return coin;
		}
		CC_SAFE_DELETE(coin);
		return nullptr;
	}

	Coin::Coin()
	{
	}

	Coin::~Coin()
	{
	}

	bool Coin::init(const cocos2d::Vec2& position)
	{
		if (!initWithFile("Coin.png"))
		{
			return false;
		}
		auto bodyCoin = cocos2d::PhysicsBody::createBox(cocos2d::Size(20, 20), cocos2d::PHYSICSBODY_MATERIAL_DEFAULT);

		bodyCoin->getShape(0)->setRestitution(0.f);
		bodyCoin->getShape(0)->setFriction(0.0f);
		bodyCoin->getShape(0)->setDensity(3.0f);
		bodyCoin->setRotationEnable(false);
		bodyCoin->setDynamic(true);
		bodyCoin->setGravityEnable(false);

		this->setTag(COIN_TAG);

		this->setPhysicsBody(bodyCoin);
		bodyCoin->setContactTestBitmask(0x000001);

		this->setPosition(position);

		this->scheduleUpdate();

		return true;
	}
}
