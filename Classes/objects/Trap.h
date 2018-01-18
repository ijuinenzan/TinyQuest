#ifndef __TRAP_H__
#define __TRAP_H__

#include <cocos2d.h>

namespace Tiny
{
	class Trap : public cocos2d::Node
	{
	public:
		static Trap* create(const cocos2d::Vec2& position, const cocos2d::Size& size);
	CC_CONSTRUCTOR_ACCESS:
		Trap();
		virtual ~Trap();

		bool init(const cocos2d::Vec2& position, const cocos2d::Size& size);
	private:
	};
}


#endif //!__TRAP_H__