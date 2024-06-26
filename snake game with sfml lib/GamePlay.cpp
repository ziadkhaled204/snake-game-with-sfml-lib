#include<memory>
#include<SFML/Window/Event.hpp>
#include<string.h>

#include "GamePlay.h"
#include"gameOver.h"
#include"pauseGame.h"
#include"Snake.h"

#include<stdlib.h>
#include<time.h>
#include<algorithm>


using namespace std;
using namespace sf;

int GamePlay::m_score;
GamePlay::GamePlay()
{

}
GamePlay::GamePlay(shared_ptr<Coontext>& context) : m_context(context), snakedirection({ 30.f,0.f }),
m_elapsedtime(Time::Zero), m_paused(false)
{
	srand(time(nullptr));
}

GamePlay::~GamePlay()
{
}

void GamePlay::init()
{
	m_context->m_assets->addTexture(GRASS, "Assets/Textures/background.png",true);
	m_context->m_assets->addTexture(FOOD, "Assets/Textures/food.png");
	m_context->m_assets->addTexture(WALL, "Assets/Textures/wall.jpg",true);
	m_context->m_assets->addTexture(SNAKEHEAD, "Assets/Textures/snake face.jpg");
	m_context->m_assets->addTexture(SNAKE, "Assets/Textures/snake body.jpg");

	//grass
	m_grass.setTexture(m_context->m_assets->GetTexture(GRASS));
	m_grass.setTextureRect(m_context->m_window->getViewport(m_context->m_window->getDefaultView()));

	//wall
	for (auto& wall : m_walls)
	{
		wall.setTexture(m_context->m_assets->GetTexture(WALL));
	}
	m_walls[0].setTextureRect({ 0,0,1800,30 });
	m_walls[1].setTextureRect({ 0,0,1800,30 });
	m_walls[1].setPosition({ 0,960 - 30 });


	m_walls[2].setTextureRect({ 0,0,30,960 });
	m_walls[3].setTextureRect({ 0,0,30,960 });
	m_walls[3].setPosition({ 1800-30,0 });
	
	//food
	m_food.setTexture(m_context->m_assets->GetTexture(FOOD));
	m_food.setPosition(1800/2.f, 960/2.f);

	//snake
	m_snake.init(m_context->m_assets->GetTexture(SNAKE), m_context->m_assets->GetTexture(SNAKEHEAD));
	
	//score
	m_scoreText.setFont(m_context->m_assets->GetFont(MAIN_FONT));
	m_scoreText.setCharacterSize(30);
	m_scoreText.setString("SCORE : " + to_string(m_score));
}

void GamePlay::ProcessInput()
{
	Event event;
	while (m_context->m_window->pollEvent(event))
	{
		if (event.type == Event::Closed)
			m_context->m_window->close();
		else if (event.type == Event::KeyPressed)
		{
			Vector2f newdirection = snakedirection;
			switch (event.key.code)
			{
			case Keyboard::Up:
			{
				newdirection = { 0.f,-30.f };
				break;
			}
			case Keyboard::Down:
			{
				newdirection = { 0.f,30.f };
				break;
			}
			case Keyboard::Right:
			{
				newdirection = { 30.f,0.f };
				break;
			}
			case Keyboard::Left:
			{
				newdirection = { -30.f,0.f };
				break;
			}
			case Keyboard:: Escape:
			{
				m_context->m_states->Add(make_unique<pauseGame>(m_context));
				break;
			}
			default:
				break;
			}
			if (abs(snakedirection.x) != abs(newdirection.x) ||
				abs(snakedirection.y) != abs(newdirection.y))
			{
				snakedirection = newdirection;
			}
		}
	}
}

void GamePlay::Update(const Time& deltatime)
{
	if (!m_paused)
	{
		m_elapsedtime += deltatime;
		if (m_score % 5 == 0 && m_score > 0) 
		{
			m_movementInterval -= Time(seconds(0.000000005));
		}

		if (m_elapsedtime > m_movementInterval)
		{
			for (auto& wall : m_walls)
			{
				if (m_snake.IsOn(wall))
				{
					m_context->m_states->Add(make_unique<gameOver>(m_context), true);
					return;
				}
			}
			if (m_snake.IsOnitself())
			{
				m_context->m_states->Add(make_unique<gameOver>(m_context),true);
			}
			if (m_snake.IsOn(m_food))
			{
				m_snake.Grow(snakedirection);
				float x = 1800.f, y = 980.f;
				while (x > 1600 || y > 780)
				{
				x = rand() % m_context->m_window->getSize().x;
				y = rand() % m_context->m_window->getSize().y;
				}
					m_food.setPosition(x, y);
					m_score++;
					m_scoreText.setString("SCORE : " + to_string(m_score));
			}
			else
			{
				m_snake.Move(snakedirection);
			}

			m_elapsedtime = Time::Zero;
		}
	}
}

void GamePlay::Draw()
{
	m_context->m_window->clear();
	m_context->m_window->draw(m_grass);
	for (auto& wall : m_walls)
	{
		m_context->m_window->draw(wall);
	}
	m_context->m_window->draw(m_food);
	m_context->m_window->draw(m_snake);
	m_context->m_window->draw(m_scoreText);

	m_context->m_window->display();
}

void GamePlay::start()
{
	m_paused = false;
}

void GamePlay::Pause()
{
	m_paused = true;
}
