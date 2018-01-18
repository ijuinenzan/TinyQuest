#ifndef __ENEMY_H__
#define __ENEMY_H__

#include <cocos2d.h>

namespace Tiny
{
	class Enemy : public cocos2d::Node
	{
	public:
		static Enemy* create(const cocos2d::Vec2& position);
	CC_CONSTRUCTOR_ACCESS:
		Enemy();
		virtual ~Enemy();

		bool init(const cocos2d::Vec2& position);

		void update(float dt) override;
	private:
		float _timeFromLastShoot;
	};
}


#endif //!__GROUND_H__