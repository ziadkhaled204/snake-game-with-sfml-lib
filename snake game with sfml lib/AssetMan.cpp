#include "AssetMan.h"

Engine::AssetMan::AssetMan()
{
}

Engine::AssetMan::~AssetMan()
{
}

void Engine::AssetMan::addTexture(int id, const string& filePath, bool wantRepeated)
{
	auto texture = make_unique<Texture>();


	if (texture->loadFromFile(filePath))
	{
		texture->setRepeated(wantRepeated);
		m_textures[id] = move(texture);
	}
}

void Engine::AssetMan::add_Fonts(int id, const string& filePath)
{
	auto font = make_unique<Font>();


	if (font->loadFromFile(filePath))
	{
		m_fonts[id] = move(font);
	}
}

const Texture& Engine::AssetMan::GetTexture(int id) const
{
	return *(m_textures.at(id).get());
}

const Font& Engine::AssetMan::GetFont(int id) const
{
	return *(m_fonts.at(id).get());
}
