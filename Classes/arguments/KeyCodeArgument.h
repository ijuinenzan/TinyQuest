#ifndef __KEY_CODE_ARGUMENT_H__
#define __KEY_CODE_ARGUMENT_H__

#include "base/CCEventKeyboard.h"
#include "BaseArgument.h"

namespace Tiny
{
	class KeyCodeArgument: public BaseArgument
	{
	public:
		KeyCodeArgument(const cocos2d::EventKeyboard::KeyCode &keyCode);
		const cocos2d::EventKeyboard::KeyCode& getKeyCode() const;
	private:
		cocos2d::EventKeyboard::KeyCode _keyCode;
	};
}


#endif //!__KEY_CODE_ARGUMENT_H__