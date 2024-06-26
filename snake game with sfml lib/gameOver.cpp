#include<memory>
#include<string.h>

#include "gameOver.h"
#include<SFML/Window/Event.hpp>
#include<iostream>
#include"GamePlay.h"


using namespace sf;
gameOver::gameOver(shared_ptr<Coontext>& context) :m_context(context),
retrybuttonselected(true), retrybuttonpressed(false), exitbuttonselected(false)
, exitbuttonpressed(false)
{
}

gameOver::~gameOver()
{

}

void gameOver::init()
{
	m_context->m_assets->add_Fonts(MAIN_FONT, "Assets/Fonts/Honk-Regular.ttf");

	//title
	m_gameOvertitle.setFont(m_context->m_assets->GetFont(MAIN_FONT));
	m_gameOvertitle.setString("Game Over :///");
	m_gameOvertitle.setCharacterSize(100);
	m_gameOvertitle.setOrigin(m_gameOvertitle.getLocalBounds().width / 2,
		m_gameOvertitle.getLocalBounds().height / 2);
	m_gameOvertitle.setPosition(m_context->m_window->getSize().x / 2,
		m_context->m_window->getSize().y / 2 - 150.f);

	//m_retrybutton
	m_retrybutton.setFont(m_context->m_assets->GetFont(MAIN_FONT));
	m_retrybutton.setString("Play");
	m_retrybutton.setCharacterSize(50);
	m_retrybutton.setOrigin(m_retrybutton.getLocalBounds().width / 2,
		m_retrybutton.getLocalBounds().height / 2);
	m_retrybutton.setPosition(m_context->m_window->getSize().x / 2,
		m_context->m_window->getSize().y / 2 + 25.f);

	//exitbutton
	m_exitbutton.setFont(m_context->m_assets->GetFont(MAIN_FONT));
	m_exitbutton.setString("Exit");
	m_exitbutton.setCharacterSize(50);
	m_exitbutton.setOrigin(m_exitbutton.getLocalBounds().width / 2,
		m_exitbutton.getLocalBounds().height / 2);
	m_exitbutton.setPosition(m_context->m_window->getSize().x / 2,
		m_context->m_window->getSize().y / 2 + 100.f);

	//scoreboard
	m_scoreText.setFont(m_context->m_assets->GetFont(MAIN_FONT));
	m_scoreText.setString("SCORE : " + to_string(m_score));
	m_scoreText.setCharacterSize(70);
	m_scoreText.setOrigin(m_scoreText.getLocalBounds().width / 2,
		m_scoreText.getLocalBounds().height / 2);
	m_scoreText.setPosition(m_context->m_window->getSize().x / 2,
		m_context->m_window->getSize().y / 2 - 50.f);
}


void gameOver::ProcessInput()
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
			case Keyboard::Up:
			{
				if (!retrybuttonselected)
				{
					retrybuttonselected = true;
					exitbuttonselected = false;
				}
				break;
			}
			case Keyboard::Down:
			{
				if (!exitbuttonselected)
				{
					retrybuttonselected = false;
					exitbuttonselected = true;
				}
				break;
			}
			case Keyboard::Return:
			{
				if (retrybuttonselected)
				{
					retrybuttonpressed = true;
				}
				else
				{
					exitbuttonpressed = true;
				}
				break;
			}
			default:
				break;
			}
		}
	}
}

void gameOver::Update(const Time& deltatime)
{
	if (retrybuttonselected)
	{
		m_retrybutton.setCharacterSize(70);
		m_exitbutton.setCharacterSize(50);
	}
	else
	{
		m_exitbutton.setCharacterSize(70);
		m_retrybutton.setCharacterSize(50);
	}
	if (retrybuttonpressed)
	{
		m_context->m_states->Add(make_unique<GamePlay>(m_context), true);
		m_score = 0;
	}
	else if (exitbuttonpressed)
	{
		m_context->m_window->close();
	}
}


void gameOver::Draw()
{

	m_context->m_window->clear();
	m_context->m_window->draw(m_gameOvertitle);
	m_context->m_window->draw(m_scoreText);
	m_context->m_window->draw(m_retrybutton);
	m_context->m_window->draw(m_exitbutton);
	m_context->m_window->display();
}

