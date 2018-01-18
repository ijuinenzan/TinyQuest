#ifndef __PLATFORM_H__
#define __PLATFORM_H__

#include <cocos2d.h>

namespace Tiny
{
	class Platform : public cocos2d::Sprite
	{
	public:
		static Platform* create(const cocos2d::Vec2& position, const cocos2d::Size& size, const float minX, const float maxX);
	CC_CONSTRUCTOR_ACCESS:
		Platform();
		virtual ~Platform();

		bool init(const cocos2d::Vec2& position, const cocos2d::Size& size, const float minX, const float maxX);

		void update(float dt) override;
	private:
		float _minX;
		float _maxX;
	};
}


#endif //!__GROUND_H__