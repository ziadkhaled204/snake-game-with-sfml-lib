#pragma once
#include<map>
#include<memory>
#include<SFML/Graphics/Font.hpp>
#include<SFML/Graphics/Texture.hpp>
#include<string>
using namespace std;
using namespace sf;
namespace Engine
{
	class AssetMan
	{
	private:
		map <int,unique_ptr<Texture>> m_textures;
		map<int, unique_ptr<Font>> m_fonts;
	public:
		AssetMan();
		~AssetMan();
		
		void addTexture(int id, const string& filePath, bool wantRepeated = false);
		void add_Fonts(int id,const string &filePath);

			
		const Texture& GetTexture(int id)const;
		const Font& GetFont(int id)const;
	};
}

