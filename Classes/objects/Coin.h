#ifndef __COIN_H__
#define __COIN_H__

#include <cocos2d.h>

namespace Tiny
{
	class Coin : public cocos2d::Sprite
	{
	public:
		static Coin* create(const cocos2d::Vec2& position);
	CC_CONSTRUCTOR_ACCESS:
		Coin();
		virtual ~Coin();

		bool init(const cocos2d::Vec2& position);
	private:
	};
}


#endif //!__COIN_H__