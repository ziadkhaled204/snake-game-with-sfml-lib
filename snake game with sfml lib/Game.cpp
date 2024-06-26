#include <SFML/Graphics/CircleShape.hpp>


#include "Game.h"
#include"MainMenu.h"

using namespace std;
using namespace sf;

Game::Game():m_context(make_shared<Coontext>())
{
	m_context->m_window->create(VideoMode(1800,960),"SNAKE GAME",Style::Close);
    m_context->m_states->Add(make_unique<MainMenu>(m_context));
}

Game::~Game()
{
}

void Game::Run()
{
    CircleShape shape(100.f);
    shape.setFillColor(Color::Green);

    Clock clock;
    Time sincelastframe = Time::Zero;
    while (m_context->m_window->isOpen())
    {
        sincelastframe += clock.restart();

        while (sincelastframe > FPS)
        {
            sincelastframe -= FPS;

            m_context->m_states->ProcessStateChange();
            m_context->m_states->GetCurrent()->ProcessInput();
            m_context->m_states->GetCurrent()->Update(FPS);
            m_context->m_states->GetCurrent()->Draw();
            
        }
    }
}
    