#ifndef __TINY_JUMP_LEFT_STATE_H__
#define __TINY_JUMP_LEFT_STATE_H__

#include "Tiny.h"

namespace Tiny
{
	class TinyJumpLeftState : public State
	{
	private:
		Tiny*_tiny;
	public:
		TinyJumpLeftState(Tiny* tiny);
		virtual ~TinyJumpLeftState();

		void didEnterWithPreviousState(State* previousState) override;
		void updateWithDeltaTime(const float delta) override;
		void willExitWithNextState(State* nextState) override;

		bool isValidNextState(State* state) override;
	};
}

#endif //!__TINY_JUMP_LEFT_STATE_H__
