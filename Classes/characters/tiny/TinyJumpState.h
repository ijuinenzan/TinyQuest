#ifndef __TINY_JUMP_STATE_H__
#define __TINY_JUMP_STATE_H__
#include "Tiny.h"

namespace Tiny
{
	class TinyJumpState : public State
	{
	private:
		Tiny*_tiny;
	public:
		TinyJumpState(Tiny* tiny);
		virtual ~TinyJumpState();

		void didEnterWithPreviousState(State* previousState) override;
		void updateWithDeltaTime(const float delta) override;
		void willExitWithNextState(State* nextState) override;

		bool isValidNextState(State* state) override;
	};
}

#endif //!__TINY_JUMP_STATE_H__
