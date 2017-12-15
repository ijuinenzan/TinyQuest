#include "TinyMoveRightState.h"

namespace Tiny
{
	TinyMoveRightState::TinyMoveRightState(Tiny* tiny)
	{
		_tiny = tiny;
	}

	TinyMoveRightState::~TinyMoveRightState()
	{
	}

	void TinyMoveRightState::didEnterWithPreviousState(State* previousState)
	{
		_tiny->getPhysicsBody()->setVelocity(cocos2d::Vec2(0, 0));
	}

	void TinyMoveRightState::updateWithDeltaTime(const float delta)
	{
	}

	void TinyMoveRightState::willExitWithNextState(State* nextState)
	{
	}

	bool TinyMoveRightState::isValidNextState(State* state)
	{
		return false;
	}
}
