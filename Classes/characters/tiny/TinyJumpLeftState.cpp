#include "TinyJumpLeftState.h"
#include "TinyIdleState.h"
#include "TinyMoveLeftState.h"
#include "TinyMoveRightState.h"
#include "TinyAnimations.hpp"

namespace Tiny
{
	TinyJumpLeftState::TinyJumpLeftState(Tiny* tiny)
		:State("Tiny Jump Left")
	{
		_tiny = tiny;
	}

	TinyJumpLeftState::~TinyJumpLeftState()
	{
	}

	void TinyJumpLeftState::didEnterWithPreviousState(State* previousState)
	{
		if(previousState->getStateName() == "Tiny Jump")
		{
			_tiny->getPhysicsBody()->setVelocity(cocos2d::Vec2(-150, _tiny->getPhysicsBody()->getVelocity().y));
		}
		else
		{
			_tiny->getPhysicsBody()->setVelocity(cocos2d::Vec2(-150, 350));
		}
		_tiny->stopActionByTag(0);
		_tiny->runAction(TexturePacker::TinyAnimations::createJUMPLEFT_JUMPLEFTAnimateAction(0.3, -1));
	}

	void TinyJumpLeftState::updateWithDeltaTime(const float delta)
	{
		if (_stateMachine->enterState<TinyMoveLeftState>())
		{
			return;
		}
		if (_stateMachine->enterState<TinyIdleState>())
		{
			return;
		}
	}

	void TinyJumpLeftState::willExitWithNextState(State* nextState)
	{
	}

	bool TinyJumpLeftState::isValidNextState(State* state)
	{
		auto name = state->getStateName();
		if (name == "Tiny Idle")
		{
			if (_tiny->isTouchingGround())
			{
				return true;
			}
		}
		if (name == "Tiny Move Left")
		{
			if (_tiny->isTouchingGround() && _tiny->isLeftPressed())
			{
				return true;
			}
		}

		return false;
	}
}
