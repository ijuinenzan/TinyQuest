#ifndef __WALL_H__
#define __WALL_H__

#include <cocos2d.h>

namespace Tiny
{
	class Wall : public cocos2d::Node
	{
	public:
		static Wall* create(const cocos2d::Vec2& position, const cocos2d::Size& size);
	CC_CONSTRUCTOR_ACCESS:
		Wall();
		virtual ~Wall();

		bool init(const cocos2d::Vec2& position, const cocos2d::Size& size);
	private:
	};
}


#endif //!__WALL_H__