#pragma once
#include "Tiny.h"

namespace Tiny
{
	class TinyMoveLeftState : public State
	{
	private:
		Tiny*_tiny;
	public:
		TinyMoveLeftState(Tiny* tiny);
		virtual ~TinyMoveLeftState();

		void didEnterWithPreviousState(State* previousState) override;
		void updateWithDeltaTime(const float delta) override;
		void willExitWithNextState(State* nextState) override;

		bool isValidNextState(State* state) override;
	};
}

