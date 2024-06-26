#pragma once
#include <SFML/System/Time.hpp>
using namespace sf;
namespace Engine
{
	class State
	{
	public:
		State() {};
		virtual ~State() {};

		virtual void init() = 0;
		virtual void ProcessInput() = 0;
		virtual void Update(const Time& deltatime) = 0;
		virtual void Draw() = 0;

		virtual void Pause() {};
		virtual void start() {};

	};
}