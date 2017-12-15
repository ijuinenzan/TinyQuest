#include "KeyCodeArgument.h"

namespace Tiny
{
	KeyCodeArgument::KeyCodeArgument(const cocos2d::EventKeyboard::KeyCode& keyCode)
	{
		_keyCode = keyCode;
	}

	const cocos2d::EventKeyboard::KeyCode& KeyCodeArgument::getKeyCode() const
	{
		return _keyCode;
	}
}
