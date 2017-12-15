#pragma once
#include "Tiny.h"

namespace Tiny
{
	class TinyIdleState: public State
	{
	private:
		Tiny*_tiny;
	public:
		TinyIdleState(Tiny* tiny);
		virtual ~TinyIdleState();
		void didEnterWithPreviousState(State* previousState) override;
		void updateWithDeltaTime(float delta) override;
		void willExitWithNextState(State* nextState) override;

		bool isValidNextState(State* state) override;
	};
}

