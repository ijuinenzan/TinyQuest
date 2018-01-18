#ifndef __GAME_COMPLETE_OBJECT_H__
#define __GAME_COMPLETE_OBJECT_H__

#include <cocos2d.h>

namespace Tiny
{
	class GameCompleteObject : public cocos2d::Node
	{
	public:
		static GameCompleteObject* create(const cocos2d::Vec2& position, const cocos2d::Size& size);
	CC_CONSTRUCTOR_ACCESS:
		GameCompleteObject();
		virtual ~GameCompleteObject();

		bool init(const cocos2d::Vec2& position, const cocos2d::Size& size);
	};
}


#endif //!__GAME_COMPLETE_OBJECT_H__