#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Physic/QuadTree/QuadTree.hpp"
#include "TestHelper.hpp"


sf::RectangleShape* manageInput(sf::RenderWindow & window,
								std::vector<sf::RectangleShape> & rects,
								sf::RectangleShape* shapeSelected,
								sf::Vector2f & offset)
{
	sf::Event event;

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		sf::Vector2f mousePosition(sf::Mouse::getPosition(window));

		if (shapeSelected == nullptr)
		{
			for (unsigned i = 0; i < rects.size(); i++)
			{
				if (rects[i].getGlobalBounds().contains(mousePosition))
				{
					shapeSelected = &rects[i];
					offset = shapeSelected->getPosition() - mousePosition;
					break;
				}
			}
		}
		else
		{
			shapeSelected->setPosition(mousePosition + offset);
		}
	}
	else
	{
		shapeSelected = nullptr;
	}

	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
	}

	return shapeSelected;
}

void testCollision()
{
	sf::RenderWindow window(sf::VideoMode(1000, 800), "Physic Engine Test");

	QuadTree<sf::RectangleShape*> quadTree(window.getViewport(window.getView()),
										   3,
										   10);

	std::vector<sf::RectangleShape> rects(10, sf::RectangleShape());
	sf::Vector2u minSize(10, 10);
	sf::Vector2u maxSize(100, 100);

	for (unsigned i = 0; i < rects.size(); i++)
	{
		rects[i].setSize(getRandomSize(minSize, maxSize));
		rects[i].setFillColor(getRandomColor());
		rects[i].setPosition(getRandomPosition(window.getSize()));
	}

	sf::Vector2f offset;
	sf::RectangleShape* shapeSelected = nullptr;

	while (window.isOpen())
	{
		shapeSelected = manageInput(window, rects, shapeSelected, offset);

		// quad tree preparation

		quadTree.Clear();

		for (unsigned i = 0; i <rects.size(); i++)
		{
			quadTree.Insert(&rects[i], rects[i].getGlobalBounds());
		}

		// collision detection
		if (shapeSelected != nullptr)
		{
			std::vector<sf::RectangleShape*> founds = quadTree.Retrieve(shapeSelected->getGlobalBounds());

			unsigned numberCollision = 0;

			for (unsigned i = 0; i < founds.size(); i++)
			{
				if (founds[i]->getGlobalBounds().intersects(shapeSelected->getGlobalBounds()))
				{
					founds[i]->setFillColor(getRandomColor());

					numberCollision++;
				}
			}

			std::cout << "Collision with " << numberCollision << std::endl;
		}

		// display cycle

		window.clear();

		for (unsigned i = 0; i < rects.size(); i++)
		{
			window.draw(rects[i]);
		}

		window.display();
	}
}
