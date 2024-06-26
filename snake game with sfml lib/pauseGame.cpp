#include "gameOver.h"
#include<SFML/Window/Event.hpp>
#include<iostream>
#include"GamePlay.h"
#include"pauseGame.h"

using namespace sf;
pauseGame::pauseGame(shared_ptr<Coontext>& context) :m_context(context)
{
}

pauseGame::~pauseGame()
{
}

void pauseGame::init()
{
	//pausetitle
	pauseTitle.setFont(m_context->m_assets->GetFont(MAIN_FONT));
	pauseTitle.setString("PAUSED :)");
	pauseTitle.setCharacterSize(100);
	pauseTitle.setOrigin(pauseTitle.getLocalBounds().width / 2,
		pauseTitle.getLocalBounds().height / 2);
	pauseTitle.setPosition(m_context->m_window->getSize().x / 2,
		m_context->m_window->getSize().y / 2.f);

	
}


void pauseGame::ProcessInput()
{
	Event event;
	while (m_context->m_window->pollEvent(event))
	{
		if (event.type == Event::Closed)
			m_context->m_window->close();
		else if (event.type == Event::KeyPressed)
		{
			switch (event.key.code)
			{
				case Keyboard::Escape:
				{
					m_context->m_states->PopCurrent();
				}
			}
		}
	}
}

void pauseGame::Update(const Time& deltatime)
{
	
}


void pauseGame::Draw()
{

	m_context->m_window->draw(pauseTitle);
	m_context->m_window->display();
}

