#pragma once

#include <memory>
#include <stack>

#include "State.hpp"

namespace Game{
	
	typedef std::unique_ptr<State> StateRef;
	
	class StateMachine{
		
	public:
		StateMachine ( ) { }
		~StateMachine ( ) { } 
		
		void AddState (StateRef newState, bool isReplacing = true);
		void RemoveState ( );
		
		void ProcessStateChanges( );
		
		StateRef &GetActivateState ( );
		
	private:
		
		std::stack<StateRef> _states;
		StateRef _newState;
		
		bool _isRemoving;
		bool _isAdding;
		bool _isReplacing;	
		
		
	};
}
