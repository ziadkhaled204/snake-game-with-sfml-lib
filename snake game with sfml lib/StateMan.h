#pragma once
#include<stack>
#include<memory>
#include "State.h"
using namespace std;
using namespace sf;
namespace Engine
{
	class StateMan
	{
	private:
		stack<unique_ptr<State>> m_stateStack;
		unique_ptr < State > m_newState;

		bool m_add;
		bool m_remove;
		bool m_replace;
	public:
		StateMan();
		~StateMan();
		void Add(unique_ptr<State> toAdd, bool replace = false);
		void PopCurrent();
		void ProcessStateChange();
		unique_ptr<State> &GetCurrent();
	};
}
