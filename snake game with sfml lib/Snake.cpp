#include "Snake.h"

using namespace std;
using namespace sf;
Snake::Snake() : m_body(list<Sprite>(4))
{
	m_head = --m_body.end();
	m_tail = m_body.begin();
}

Snake::~Snake()
{
}

void Snake::init(const Texture& bodytexture, const Texture& headtexture)
{
	float x = 30.f;
	m_head->setTexture(headtexture);
	m_head->setPosition({ x, 30.f });
	for (auto& piece : m_body)
	{
		piece.setTexture(bodytexture);
		piece.setPosition({ x,30.f });
		x += 30.f;
	}
}

void Snake::Move(const Vector2f& direction)
{
	m_tail->setPosition(m_head->getPosition() + direction);
	m_head = m_tail;
	m_tail++;
	m_head->getTexture();
	if (m_tail == m_body.end())
	{
		m_tail = m_body.begin();
	}
}

bool Snake::IsOn(const Sprite& other) const
{
	return other.getGlobalBounds().intersects(m_head->getGlobalBounds());
}

bool Snake::IsOnitself() const
{
	bool flag = false;
	for (auto piece = m_body.begin(); piece != m_body.end(); piece++)
	{
		if (m_head != piece)
		{
			flag = IsOn(*piece);
			

			if (flag)
			{
				break;
			}
		}
	}
	return flag;
}

void Snake::Grow(const Vector2f& direction)
{
	Sprite newpiece;
	newpiece.setTexture(*(m_body.begin()->getTexture()));
	newpiece.setPosition(m_head->getPosition() + direction);
	m_head = m_body.insert(++m_head, newpiece);

}


void Snake::draw(RenderTarget& target, RenderStates states) const
{
	for (auto& piece : m_body)
	{
		target.draw(piece);
	} 
}
