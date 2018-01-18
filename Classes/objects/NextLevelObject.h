#ifndef __NEXT_LEVEL_OBJECT_H__
#define __NEXT_LEVEL_OBJECT_H__

#include <cocos2d.h>

namespace Tiny
{
	class NextLevelObject : public cocos2d::Node
	{
	public:
		static NextLevelObject* create(const cocos2d::Vec2& position, const cocos2d::Size& size, const std::string &nextMapName);
	CC_CONSTRUCTOR_ACCESS:
		NextLevelObject();
		virtual ~NextLevelObject();

		bool init(const cocos2d::Vec2& position, const cocos2d::Size& size, const std::string &nextMapName);
	private:
		std::string _nextMapName;
	};
}


#endif //!__NEXT_LEVEL_OBJECT_H__