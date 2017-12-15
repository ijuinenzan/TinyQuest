#pragma once
#include "Tiny.h"

namespace Tiny
{
	class TinyMoveRightState : public State
	{
	private:
		Tiny*_tiny;
	public:
		TinyMoveRightState(Tiny* tiny);
		virtual ~TinyMoveRightState();

		void didEnterWithPreviousState(State* previousState) override;
		void updateWithDeltaTime(const float delta) override;
		void willExitWithNextState(State* nextState) override;

		bool isValidNextState(State* state) override;
	};
}

