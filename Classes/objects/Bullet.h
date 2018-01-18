#ifndef __BULLET_H__
#define __BULLET_H__

#include <cocos2d.h>

namespace Tiny
{
	class Bullet : public cocos2d::Sprite
	{
	public:
		static Bullet* create(const cocos2d::Vec2& position);
	CC_CONSTRUCTOR_ACCESS:
		Bullet();
		virtual ~Bullet();

		bool init(const cocos2d::Vec2& position);

		void update(float dt) override;
	private:
	};
}


#endif //!__GROUND_H__