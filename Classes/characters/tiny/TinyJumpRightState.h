#ifndef __TINY_JUMP_RIGHT_STATE_H__
#define __TINY_JUMP_RIGHT_STATE_H__
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

#endif //!__TINY_JUMP_RIGHT_STATE_H__
