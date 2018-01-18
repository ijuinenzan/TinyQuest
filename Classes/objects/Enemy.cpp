#include "Enemy.h"
#include <Define.h>
#include "Bullet.h"

namespace Tiny
{
	Enemy* Enemy::create(const cocos2d::Vec2& position)
	{
		Enemy *enemy = new (std::nothrow) Enemy();
		if (enemy && enemy->init(position))
		{
			enemy->autorelease();
			return enemy;
		}
		CC_SAFE_DELETE(enemy);
		return nullptr;
	}

	Enemy::Enemy()
	{
	}

	Enemy::~Enemy()
	{
	}

	bool Enemy::init(const cocos2d::Vec2& position)
	{
		this->setTag(ENEMY_TAG);

		this->setPosition(position);

		_timeFromLastShoot = 0.f;

		this->scheduleUpdate();

		return true;
	}

	void Enemy::update(float dt)
	{
		_timeFromLastShoot += dt;

		if(_timeFromLastShoot >3)
		{
			this->getParent()->addChild(Bullet::create(getPosition()));
			_timeFromLastShoot = 0;
		}
	}
}
