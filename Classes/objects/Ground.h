#ifndef __GROUND_H__
#define __GROUND_H__

#include <cocos2d.h>

namespace Tiny
{
	class Ground : public cocos2d::Node
	{
	public:
		static Ground* create(const cocos2d::Vec2& position, const cocos2d::Size& size);
	CC_CONSTRUCTOR_ACCESS:
		Ground();
		virtual ~Ground();

		bool init(const cocos2d::Vec2& position, const cocos2d::Size& size) ;
	private:
	};
}


#endif //!__GROUND_H__