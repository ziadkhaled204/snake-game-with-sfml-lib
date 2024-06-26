#pragma once
#include<memory>

#include"State.h"
#include"Game.h"

#include<SFML/Graphics/Text.hpp>


using namespace std;
using namespace sf;


class pauseGame : public Engine::State
{
private:
	shared_ptr<Coontext> m_context;
	Text pauseTitle;


public:
	pauseGame(shared_ptr<Coontext>& context);
	~pauseGame();

	void init() override;
	void ProcessInput() override;
	void Update(const Time& deltatime) override;
	void Draw() override;

};



