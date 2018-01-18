#include "TinyIdleState.h"
#include "TinyMoveRightState.h"
#include "TinyMoveLeftState.h"
#include "TinyAnimations.hpp"
#include "TinyJumpState.h"

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
		_tiny->stopActionByTag(0);
	}

	void TinyIdleState::updateWithDeltaTime(const float delta)
	{
		if(_stateMachine->enterState<TinyMoveRightState>())
		{
			return;
		}
		if (_stateMachine->enterState<TinyMoveLeftState>())
		{
			return;
		}
		if (_stateMachine->enterState<TinyJumpState>())
		{
			return;
		}
	}

	void TinyIdleState::willExitWithNextState(State* nextState)
	{
	}

	bool TinyIdleState::isValidNextState(State* state)
	{
		const auto name = state->getStateName();
		if(name == "Tiny Move Right")
		{
			if (_tiny->isRightPressed())
			{
				return true;
			}
		}
		if(name == "Tiny Move Left")
		{
			if(_tiny->isLeftPressed())
			{
				return true;
			}
		}
		if (name == "Tiny Jump") 
		{
			if (_tiny->isSpacePressed()) 
			{
				return true;
			}
		}
		return false;
	}
}
