#ifndef __TINY_H__
#define __TINY_H__

#include "../Actor.h"

namespace Tiny
{
	class Tiny : public Actor
	{
	public:
		static Tiny* create(const cocos2d::Vec2& initialPosition);
	CC_CONSTRUCTOR_ACCESS:
		Tiny();
		virtual ~Tiny();

		bool init(const cocos2d::Vec2& initialPosition);

		bool isLeftPressed() const;
		bool isRightPressed() const;
		bool isSpacePressed() const;
		bool isTouchingGround() const;
	private:
		bool _isLeftPressed;
		bool _isRightPressed;
		bool _isSpacePressed;

		bool _isTouchingGround;

		cocos2d::Vec2 _initialPosition;

		cocos2d::PhysicsBody* _body;

		bool _isRespawning;

		void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
		void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
	};
}


#endif //!__TINY_H__