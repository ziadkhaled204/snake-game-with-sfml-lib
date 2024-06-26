#include "MainMenu.h"
#include<SFML/Window/Event.hpp>
#include<iostream>
#include"GamePlay.h"

using namespace sf;
MainMenu::MainMenu(shared_ptr<Coontext> &context):m_context(context),
playbuttonselected(true),playbuttonpressed(false),exitbuttonselected(false)
,exitbuttonpressed(false)
{
}

MainMenu::~MainMenu()
{

}

void MainMenu::init()
{
	m_context->m_assets->add_Fonts(MAIN_FONT, "Assets/Fonts/Honk-Regular.ttf");

	//title
	m_gameTitle.setFont(m_context->m_assets->GetFont(MAIN_FONT));
	m_gameTitle.setString("SNAKE GAME");
	m_gameTitle.setCharacterSize(100);
	m_gameTitle.setOrigin(m_gameTitle.getLocalBounds().width / 2,
						  m_gameTitle.getLocalBounds().height / 2);
	m_gameTitle.setPosition(m_context->m_window->getSize().x / 2,
							m_context->m_window->getSize().y / 2-150.f);
	
	//playbutton
	m_playbutton.setFont(m_context->m_assets->GetFont(MAIN_FONT));
	m_playbutton.setString("Play");
	m_playbutton.setCharacterSize(50);
	m_playbutton.setOrigin(m_playbutton.getLocalBounds().width / 2,
						  m_playbutton.getLocalBounds().height / 2);
	m_playbutton.setPosition(m_context->m_window->getSize().x / 2,
							m_context->m_window->getSize().y / 2-50.f);
	
	//exitbutton
	m_exitbutton.setFont(m_context->m_assets->GetFont(MAIN_FONT));
	m_exitbutton.setString("Exit");
	m_exitbutton.setCharacterSize(50);
	m_exitbutton.setOrigin(m_exitbutton.getLocalBounds().width / 2,
						  m_exitbutton.getLocalBounds().height / 2);
	m_exitbutton.setPosition(m_context->m_window->getSize().x / 2,
							m_context->m_window->getSize().y / 2+25.f);

}


void MainMenu::ProcessInput()
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
					if (!playbuttonselected)
					{
						playbuttonselected = true;
						exitbuttonselected = false;
					}
					break;
				}
			case Keyboard::Down:
				{
					if (!exitbuttonselected)
					{
						playbuttonselected = false;
						exitbuttonselected = true;
					}
					break;
				}
			case Keyboard::Return:
				{
					
					if (playbuttonselected)
					{
						playbuttonpressed = true;
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

void MainMenu::Update(const Time& deltatime)
{
	if (playbuttonselected)
	{
		m_playbutton.setCharacterSize(70);
		m_exitbutton.setCharacterSize(50);
	}
	else
	{
		m_exitbutton.setCharacterSize(70);
		m_playbutton.setCharacterSize(50);
	}
	if (playbuttonpressed)
	{
		m_context->m_states->Add(make_unique<GamePlay>(m_context), true);
	}
	else if(exitbuttonpressed)
	{
		m_context->m_window->close();
	}
}


void MainMenu::Draw()
{

	m_context->m_window->clear();
	m_context->m_window->draw(m_gameTitle);
	m_context->m_window->draw(m_playbutton);
	m_context->m_window->draw(m_exitbutton);
	m_context->m_window->display();
}

