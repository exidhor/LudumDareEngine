#pragma once
#include <SFML/Graphics.hpp>


sf::Color getRandomColor()
{
	int r = rand() % 255;
	int g = rand() % 255;
	int b = rand() % 255;

	return sf::Color(r, g, b);
}

sf::Vector2f getRandomPosition(sf::Vector2u const& bounds)
{
	int x = rand() % (int)bounds.x;
	int y = rand() % (int)bounds.y;

	return sf::Vector2f(x, y);
}

sf::Vector2f getRandomSize(sf::Vector2u const&  min,
						   sf::Vector2u const&  max)
{
	int width = rand() % (max.x - min.x) + min.x;
	int height = rand() % (max.y - min.y) + min.y;

	return sf::Vector2f(width, height);
}

