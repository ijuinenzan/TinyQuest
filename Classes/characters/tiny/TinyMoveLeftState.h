#ifndef __TINY_MOVE_LEFT_STATE_H__
#define __TINY_MOVE_LEFT_STATE_H__
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

#endif //!__TINY_MOVE_LEFT_STATE_H__

