#pragma once
#include<memory>

#include"State.h"
#include"Game.h"
#include"GamePlay.h"

#include<SFML/Graphics/Text.hpp>


using namespace std;
using namespace sf;


class gameOver : public Engine::State,public GamePlay
{
private:
	shared_ptr<Coontext> m_context;
	Text m_gameOvertitle;
	Text m_retrybutton;
	Text m_exitbutton;

	//retrybutton
	bool retrybuttonselected;
	bool retrybuttonpressed;

	//exitbutton
	bool exitbuttonselected;
	bool exitbuttonpressed;

public:
	gameOver(shared_ptr<Coontext>& context);
	~gameOver();

	void init() override;
	void ProcessInput() override;
	void Update(const Time& deltatime) override;
	void Draw() override;

};



