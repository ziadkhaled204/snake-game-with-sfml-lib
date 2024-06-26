#pragma once
#include<memory>
#include<array>
#include<SFML/Graphics/Sprite.hpp>
#include<SFML/Graphics/Text.hpp>

#include"Game.h"
#include"State.h"
#include"Snake.h"

using namespace std;
using namespace sf;

class GamePlay: public Engine::State
{
	shared_ptr<Coontext>m_context;
	Sprite m_grass;
	Sprite m_food;
	array<Sprite, 4> m_walls;
	Snake m_snake;

	Vector2f snakedirection;
	Time m_elapsedtime;
	Time m_movementInterval = Time(seconds(0.04));

	bool m_paused;

public:
	GamePlay();
	GamePlay(shared_ptr<Coontext> &context);
	~GamePlay();
	 void init() override;
	 void ProcessInput() override;
	 void Update(const Time& deltatime) override;
	 void Draw() override;
	 void start() override;
	 void Pause() override;


	Text m_scoreText;
	static int m_score;
};
