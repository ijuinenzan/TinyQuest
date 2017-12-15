﻿//
//  state_machine.h
//

#ifndef state_machine_h
#define state_machine_h

#include <unordered_map>
#include "state.h"

class StateMachine
{
public:
	/**
	*  Create state machine
	*
	*  @return new state machine
	*/
	static StateMachine* create()
	{
		auto ref = new (std::nothrow) StateMachine();
		return ref;
	}

	/**
	*  Find state by id and return casted state
	*
	*  @return casted state
	*/
	template<class T>
	T* findState()
	{
		const std::string name = typeid(T).name();
		if (_states.count(name) != 0)
		{
			return static_cast<T*>(_states[name]);
		}
		return nullptr;
	}

	/**
	*  Add new state to state machine
	*
	*  @param args arguments to pass to constructor of state
	*/
	template<typename T, class... Args>
	void addState(Args&&... args)
	{
		auto typeId = typeid(T).name();

		auto state = new T(std::forward<Args>(args)...);
		state->setStateMachine(this);
		_states.insert({ typeId, state });
	}

	/**
	*  Check if we can enter state
	*
	*  @return true if this state is valid, false otherwise
	*/
	template<typename T>
	bool canEnterState()
	{
		if (_state == nullptr)
		{
			return true;
		}
		else
		{
			auto state = findState<T>();
			if (state)
			{
				return _state->isValidNextState(state);
			}
		}
		return false;
	}

	/**
	*  Enters new state
	*
	*  Before entering new state old state will check if it is a valid state to execute
	*  transaction
	*
	*  Order of execution:
	*
	*  willExitWithNextState will be called on current state
	*  didEnterWithPreviousState will be called on new state
	*
	*  @return true if entered, false otherwise
	*/
	template<typename T>
	bool enterState()
	{
		auto state = findState<T>();
		if (state)
		{
			if (_state == nullptr)
			{
				_state = state;
				_state->didEnterWithPreviousState(nullptr);
				return true;
			}
			else
			{
				if (_state->isValidNextState(state))
				{
					_state->willExitWithNextState(state);
					state->didEnterWithPreviousState(_state);
					_state = state;
					return true;
				}
			}
		}
		return false;
	}

	/**
	*  Enters new state without any check if next state is valid
	*
	*
	*  Order of execution:
	*
	*  willExitWithNextState will be called on current state
	*  didEnterWithPreviousState will be called on new state
	*
	*  @return true if entered, false otherwise
	*/
	template<typename T>
	bool setState()
	{
		auto state = findState<T>();
		if (state)
		{
			if (_state == nullptr)
			{
				_state = state;
				_state->didEnterWithPreviousState(nullptr);
				return true;
			}
			else
			{
				_state->willExitWithNextState(state);
				state->didEnterWithPreviousState(_state);
				_state = state;
				return true;
			}
		}
		return false;
	}

	/**
	*  Update state machine delta time, this will call updateWithDeltaTime on current state
	*
	*  @param delta delta time
	*/
	void updateWithDeltaTime(float delta)
	{
		if (_state != nullptr)
		{
			_state->updateWithDeltaTime(delta);
		}
	}

	/**
	*  Get current state
	*
	*  @return current state
	*/
	State* getState()
	{
		return _state;
	}

	~StateMachine()
	{
		_state = nullptr;
	}

private:
	std::unordered_map<std::string, State*> _states;
	State* _state;

	StateMachine() :
		_state(nullptr)
	{

	}
};

#endif /* state_machine_h */