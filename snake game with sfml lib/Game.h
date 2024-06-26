#pragma once
#include<memory>

#include "AssetMan.h"
#include "StateMan.h"

#include<SFML/Graphics/RenderWindow.hpp>

using namespace std;
using namespace sf;

enum AssetsID
{
	MAIN_FONT = 0,
	WALL,
	FOOD,
	GRASS,
	SNAKE,
	SNAKEHEAD
};
struct Coontext
{
	unique_ptr<Engine::AssetMan> m_assets;
	unique_ptr<Engine::StateMan> m_states;
	unique_ptr<RenderWindow> m_window;


	Coontext()
	{
		m_assets = make_unique<Engine::AssetMan>();
		m_states = make_unique<Engine::StateMan>();
		m_window = make_unique<RenderWindow>();
	}
};
class Game
{
	shared_ptr<Coontext> m_context;
	const Time FPS = seconds(1.f / 60.f);
public:
	Game();
	~Game();
	void Run();
};

