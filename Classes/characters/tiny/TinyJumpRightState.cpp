#include "TinyJumpRightState.h"
#include "TinyIdleState.h"
#include "TinyMoveLeftState.h"
#include "TinyMoveRightState.h"

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
		_tiny->getPhysicsBody()->setVelocity(cocos2d::Vec2(100, 200));
	}

	void TinyJumpRightState::updateWithDeltaTime(const float delta)
	{
		if (_stateMachine->enterState<TinyIdleState>()) {
			return;
		}
		if (_stateMachine->enterState<TinyMoveRightState>()) {
			return;
		}
	}

	void TinyJumpRightState::willExitWithNextState(State* nextState)
	{
	}

	bool TinyJumpRightState::isValidNextState(State* state)
	{
		auto name = state->getStateName();
		if (name == "Tiny Idle") {
			if (_tiny->isTouchingGround())
			{
				return true;
			}


		}
		if (name == "Tiny Move Right") {
			if (_tiny->isTouchingGround()) {
				return true;
			}
		}

		return false;
	}
}
