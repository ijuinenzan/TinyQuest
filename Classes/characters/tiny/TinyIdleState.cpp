#include "TinyIdleState.h"

namespace Tiny
{
	TinyIdleState::TinyIdleState(Tiny* tiny)
	{
		_tiny = tiny;
	}

	TinyIdleState::~TinyIdleState()
	{
	}

	void TinyIdleState::didEnterWithPreviousState(State* previousState)
	{
		_tiny->getPhysicsBody()->setVelocity(cocos2d::Vec2(0, 0));
	}

	void TinyIdleState::updateWithDeltaTime(const float delta)
	{
	}

	void TinyIdleState::willExitWithNextState(State* nextState)
	{
	}

	bool TinyIdleState::isValidNextState(State* state)
	{
		if(_tiny->isRightPressed())
		{
			return true;
		}
		return false;
	}
}
