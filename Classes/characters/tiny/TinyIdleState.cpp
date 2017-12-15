#include "TinyIdleState.h"
#include "TinyMoveRightState.h"

namespace Tiny
{
	TinyIdleState::TinyIdleState(Tiny* tiny)
		:State("Tiny Idle")
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
		_stateMachine->enterState<TinyMoveRightState>();
	}

	void TinyIdleState::willExitWithNextState(State* nextState)
	{
	}

	bool TinyIdleState::isValidNextState(State* state)
	{
		auto name = state->getStateName();
		if(_tiny->isRightPressed())
		{
			return true;
		}
		return false;
	}
}
