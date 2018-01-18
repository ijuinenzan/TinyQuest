#include "TinyJumpRightState.h"
#include "TinyIdleState.h"
#include "TinyMoveLeftState.h"
#include "TinyMoveRightState.h"
#include "TinyAnimations.hpp"

namespace Tiny
{
	TinyJumpRightState::TinyJumpRightState(Tiny* tiny)
		:State("Tiny Jump Right")
	{
		_tiny = tiny;
	}

	TinyJumpRightState::~TinyJumpRightState()
	{
	}

	void TinyJumpRightState::didEnterWithPreviousState(State* previousState)
	{
		if (previousState->getStateName() == "Tiny Jump")
		{
			_tiny->getPhysicsBody()->setVelocity(cocos2d::Vec2(150, _tiny->getPhysicsBody()->getVelocity().y));
		}
		else
		{
			_tiny->getPhysicsBody()->setVelocity(cocos2d::Vec2(150, 350));
		}
		_tiny->stopActionByTag(0);
		_tiny->runAction(TexturePacker::TinyAnimations::createJUMPRIGHT_JUMPRIGHTAnimateAction(0.3, -1));
	}

	void TinyJumpRightState::updateWithDeltaTime(const float delta)
	{
		if (_stateMachine->enterState<TinyMoveRightState>()) 
		{
			return;
		}
		if (_stateMachine->enterState<TinyIdleState>()) 
		{
			return;
		}
	}

	void TinyJumpRightState::willExitWithNextState(State* nextState)
	{
	}

	bool TinyJumpRightState::isValidNextState(State* state)
	{
		auto name = state->getStateName();
		if (name == "Tiny Idle") 
		{
			if (_tiny->isTouchingGround())
			{
				return true;
			}
		}
		if (name == "Tiny Move Right") 
		{
			if (_tiny->isTouchingGround() && _tiny->isRightPressed()) 
			{
				return true;
			}
		}

		return false;
	}
}
