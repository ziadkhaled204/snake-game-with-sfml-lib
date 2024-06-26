#pragma once
#include<list>


#include<SFML/Graphics/Sprite.hpp>
#include<SFML/Graphics/RenderTexture.hpp>
#include<SFML/Graphics/RenderTarget.hpp>
#include<SFML/Graphics/RenderTexture.hpp>
#include<SFML/Graphics/Drawable.hpp>

using namespace std;
using namespace sf;
class Snake : public Drawable
{
	list<Sprite> m_body;
	list<Sprite>::iterator m_head;
	list<Sprite>::iterator m_tail;
public:
	Snake();
	~Snake();
	void init(const Texture& bodytexture, const Texture& headtexture);
	void Move(const Vector2f& vector);
	bool IsOn(const Sprite& other) const;
	bool IsOnitself() const;
	void Grow(const Vector2f& direction);

	void draw(RenderTarget& target, RenderStates states) const override;
};

