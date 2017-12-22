#include "TinyMoveLeftState.h"
#include "TinyIdleState.h"
#include "TinyAnimations.hpp"

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
		//_tiny->runAction(TexturePacker::TinyAnimations::createMOVELEFT_MOVELEFTAnimateAction(0.7,5));
		_tiny->setScaleX(-1);
	}

	void TinyMoveLeftState::updateWithDeltaTime(const float delta)
	{
		_stateMachine->enterState<TinyIdleState>();

	}

	void TinyMoveLeftState::willExitWithNextState(State* nextState)
	{
	}

	bool TinyMoveLeftState::isValidNextState(State* state)
	{
		auto name = state->getStateName();
		if (name == "Tiny Idle") {
			if (!_tiny->isLeftPressed())
			{
				return true;
			}
		}
		return false;
	}
}
