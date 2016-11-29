#pragma once
#include <unordered_map>
#include <iostream>
#include <SFML/Graphics.hpp>

#ifdef MVS // Microsoft Visual Studio

#define DEFAULT_TEXTURE_PATH "../LudumDare_Asset/Res/"

#else  // Default

#define DEFAULT_TEXTURE_PATH ""

#endif

class TextureManager
{
public :
	TextureManager();

	bool add(std::string const& path, std::string const& key);

	sf::Texture const& get(std::string const& key);

private :
	std::string const getCompletePath(std::string const& path) const;

	std::unordered_map <std::string, sf::Texture> m_textureMap;
};