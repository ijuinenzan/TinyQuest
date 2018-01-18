#include "TinyJumpState.h"
#include "TinyIdleState.h"
#include "TinyAnimations.hpp"
#include "TinyJumpRightState.h"
#include "TinyJumpLeftState.h"

namespace Tiny
{
	TinyJumpState::TinyJumpState(Tiny* tiny)
		:State("Tiny Jump")
	{
		_tiny = tiny;
	}

	TinyJumpState::~TinyJumpState()
	{
	}

	void TinyJumpState::didEnterWithPreviousState(State* previousState)
	{
		_tiny->getPhysicsBody()->setVelocity(cocos2d::Vec2(0, 350));
		_tiny->stopActionByTag(0);
	}

	void TinyJumpState::updateWithDeltaTime(const float delta)
	{
		if (_stateMachine->enterState<TinyJumpRightState>())
		{
			return;
		}
		if (_stateMachine->enterState<TinyJumpLeftState>())
		{
			return;
		}
		if (_stateMachine->enterState<TinyIdleState>())
		{
			return;
		}
	}

	void TinyJumpState::willExitWithNextState(State* nextState)
	{
	}

	bool TinyJumpState::isValidNextState(State* state)
	{
		auto name = state->getStateName();
		if (name == "Tiny Idle")
		{
			if (_tiny->isTouchingGround())
			{
				return true;
			}
		}
		if (name == "Tiny Jump Right")
		{
			if (!_tiny->isTouchingGround() && _tiny->isRightPressed())
			{
				return true;
			}
		}

		if (name == "Tiny Jump Left")
		{
			if (!_tiny->isTouchingGround() && _tiny->isLeftPressed())
			{
				return true;
			}
		}

		return false;
	}
}
