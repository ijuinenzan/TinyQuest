#include "TinyMoveLeftState.h"
#include "TinyIdleState.h"
#include "TinyAnimations.hpp"
#include "TinyMoveRightState.h"
#include "TinyJumpLeftState.h"

namespace Tiny
{
	TinyMoveLeftState::TinyMoveLeftState(Tiny* tiny)
		:State("Tiny Move Left")
	{
		_tiny = tiny;
	}

	TinyMoveLeftState::~TinyMoveLeftState()
	{
	}

	void TinyMoveLeftState::didEnterWithPreviousState(State* previousState)
	{
		_tiny->getPhysicsBody()->setVelocity(cocos2d::Vec2(-100, 0));
		_tiny->stopActionByTag(0);
		_tiny->runAction(TexturePacker::TinyAnimations::createMOVELEFT_MOVELEFTAnimateAction(0.3, -1));
	}

	void TinyMoveLeftState::updateWithDeltaTime(const float delta)
	{
		if(_stateMachine->enterState<TinyIdleState>())
		{
			return;
		}
		if(_stateMachine->enterState<TinyMoveRightState>())
		{
			return;
		}
		if (_stateMachine->enterState<TinyJumpLeftState>())
		{
			return;
		}
	}

	void TinyMoveLeftState::willExitWithNextState(State* nextState)
	{
	}

	bool TinyMoveLeftState::isValidNextState(State* state)
	{
		const auto name = state->getStateName();
		if (name == "Tiny Idle") 
		{
			if (!_tiny->isLeftPressed())
			{
				return true;
			}
		}
		if(name == "Tiny Move Right")
		{
			if(_tiny->isRightPressed())
			{
				return true;
			}
		}
		if (name == "Tiny Jump Left")
		{
			if (_tiny->isSpacePressed())
			{
				return true;
			}
		}
		return false;
	}
}
