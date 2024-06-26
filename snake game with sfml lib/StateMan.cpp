#include "StateMan.h"
using namespace std;
using namespace Engine;
StateMan::StateMan() : m_add(false), m_replace(false), m_remove(false) {}
StateMan::~StateMan() {}
void StateMan::Add(unique_ptr<State> toAdd, bool replace)
{
	m_add = true;
	m_newState = move(toAdd);
	m_replace = replace;
}
void StateMan::PopCurrent()
{
	m_remove = true;
}
void StateMan::ProcessStateChange()
{
	if (m_remove && !m_stateStack.empty())
	{
		m_stateStack.pop();

		if (!m_stateStack.empty())
		{
			m_stateStack.top()->start();
		}
		m_remove = false;
	}
	if (m_add)
	{
		if (m_replace && !m_stateStack.empty())
		{
			m_stateStack.pop();
			m_replace = false;
		}

		if (!m_stateStack.empty())
		{
			m_stateStack.top()->Pause();
		}
		m_stateStack.push(move(m_newState));
		m_stateStack.top()->init();
		m_stateStack.top()->start();
		m_add = false;
	}
}
unique_ptr<Engine::State> &Engine::StateMan::GetCurrent()
{
	return m_stateStack.top();
}
;