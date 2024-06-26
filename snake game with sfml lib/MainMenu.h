#pragma once
#include<memory>

#include"State.h"
#include"Game.h"

#include<SFML/Graphics/Text.hpp>


using namespace std;
using namespace sf;


class MainMenu : public Engine::State
{
private:
	shared_ptr<Coontext> m_context;
	Text m_gameTitle;
	Text m_playbutton;
	Text m_exitbutton;

	//playbutton
	bool playbuttonselected;
	bool playbuttonpressed;

	//exitbutton
	bool exitbuttonselected;
	bool exitbuttonpressed;

public:
	MainMenu(shared_ptr<Coontext>& context);
	~MainMenu();

	void init() override;
	void ProcessInput() override;
	void Update(const Time& deltatime) override;
	void Draw() override;

};

