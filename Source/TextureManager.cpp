#include "TextureManager.hpp"
#include <cassert>


TextureManager::TextureManager()
{
	// nothing
}

bool TextureManager::add(std::string const& path, std::string const& key)
{
	// load the texture and store it in the map
	auto ret = m_textureMap.emplace(key, sf::Texture());

	std::string const realPath = getCompletePath(path);

	if(ret.second == false) // it means that the key already exists
	{
		std::cerr << "Error during the creation of the texture : \"" << realPath << "\"" << std::endl;
		std::cerr << "the key \"" << key << "\" already exists" << std::endl;
		std::cerr << std::endl;

		return false;
	}

	if(ret.first->second.loadFromFile(realPath))
	{
		std::cout << "Texture loaded succefully " << std::endl;
		std::cout << "Path : \"" << realPath << "\"" << std::endl;
		std::cout << "Key  : \"" << key << "\"" << std::endl;
		std::cout << std::endl;
	}
	else
	{
		std::cerr << "Error during the creation of the texture : \"" << realPath << "\" ";
		std::cerr << "with the key \"" << key << "\"" << std::endl;
		std::cerr << "impossible to find the Texture" << std::endl;
		std::cerr << std::endl;

		m_textureMap.erase(key); // the texture doesn't have to be stored, this key has to be free

		return false;
	}

	return true;
}

sf::Texture const& TextureManager::get(std::string const& key)
{
	return m_textureMap.at(key);
}

std::string const TextureManager::getCompletePath(std::string const& path) const
{
	return DEFAULT_TEXTURE_PATH + path;
}