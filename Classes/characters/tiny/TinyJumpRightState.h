#pragma once
#include "Tiny.h"

namespace Tiny
{
	class TinyJumpRightState : public State
	{
	private:
		Tiny*_tiny;
	public:
		TinyJumpRightState(Tiny* tiny);
		virtual ~TinyJumpRightState();

		void didEnterWithPreviousState(State* previousState) override;
		void updateWithDeltaTime(const float delta) override;
		void willExitWithNextState(State* nextState) override;

		bool isValidNextState(State* state) override;
	};
}

