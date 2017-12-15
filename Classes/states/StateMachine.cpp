//#include "StateMachine.h"
//
//namespace Tiny
//{
//	StateMachine* StateMachine::create()
//	{
//		const auto ref = new (std::nothrow) StateMachine();
//		return ref;
//	}
//
//	T* StateMachine::findState()
//	{
//		const std::string name = typeid(T).name();
//		if (_states.count(name) != 0)
//		{
//			return static_cast<T*>(_states[name]);
//		}
//		return nullptr;
//
//	}
//
//	void StateMachine::addState(Args&&... args)
//	{
//		auto typeId = typeid(T).name();
//
//		auto state = new T(std::forward<Args>(args)...);
//		state->setStateMachine(this);
//		_states.insert({ typeId, state });
//	}
//
//	bool StateMachine::canEnterState()
//	{
//		if (_state == nullptr)
//		{
//			return true;
//		}
//		else
//		{
//			auto state = findState<T>();
//			if (state)
//			{
//				return _state->isValidNextState(state);
//			}
//		}
//		return false;
//	}
//
//	bool StateMachine::enterState()
//	{
//		auto state = findState<T>();
//		if (state)
//		{
//			if (_state == nullptr)
//			{
//				_state = state;
//				_state->didEnter(nullptr);
//				return true;
//			}
//			else
//			{
//				if (_state->isValidNextState(state))
//				{
//					_state->willExit(state);
//					state->didEnterWithPreviousState(_state);
//					_state = state;
//					return true;
//				}
//			}
//		}
//		return false;
//	}
//
//	bool StateMachine::setState()
//	{
//		auto state = findState<T>();
//		if (state)
//		{
//			if (_state == nullptr)
//			{
//				_state = state;
//				_state->didEnter(nullptr);
//				return true;
//			}
//			else
//			{
//				_state->willExit(state);
//				state->didEnterWithPreviousState(_state);
//				_state = state;
//				return true;
//			}
//		}
//		return false;
//
//	}
//
//	void StateMachine::update(float delta) 
//	{
//		if (_state != nullptr)
//		{
//			_state->update(delta);
//		}
//	}
//
//	State* StateMachine::getState() 
//	{
//		return _state;
//	}
//
//	StateMachine::~StateMachine()
//	{
//		for(auto state: _states)
//		{
//			delete(state.second);
//		}
//		_state = nullptr;
//	}
//
//	StateMachine::StateMachine()
//		:_state(nullptr)
//	{
//	}
//}
