#include "TinyMoveRightState.h"
#include "TinyIdleState.h"
#include "TinyMoveLeftState.h"
#include "TinyJumpRightState.h"
#include "TinyAnimations.hpp"

namespace Tiny
{
	TinyMoveRightState::TinyMoveRightState(Tiny* tiny)
		:State("Tiny Move Right")
	{
		_tiny = tiny;
	}

	TinyMoveRightState::~TinyMoveRightState()
	{
	}

	void TinyMoveRightState::didEnterWithPreviousState(State* previousState)
	{
		_tiny->getPhysicsBody()->setVelocity(cocos2d::Vec2(100, 0));
		//_tiny->runAction(TexturePacker::TinyAnimations::createMOVERIGHT_MOVERIGHTAnimateAction(0.7, -1));
		_tiny->setScaleX(1);
	}

	void TinyMoveRightState::updateWithDeltaTime(const float delta)
	{
		if (_stateMachine->enterState<TinyIdleState>())
		{
			return;
		}
		if (_stateMachine->enterState<TinyJumpRightState>())
		{
			return;
		}
		
	}

	void TinyMoveRightState::willExitWithNextState(State* nextState)
	{
	}

	bool TinyMoveRightState::isValidNextState(State* state)
	{
		auto name = state->getStateName();
		if (name == "Tiny Idle") {
			if (!_tiny->isRightPressed())
			{
				return true;
			}
		}
		if (name == "Tiny Jump Right") {
			if (_tiny->isSpacePressed()) {
				return true;
			}
		}
		return false;
	}
}
