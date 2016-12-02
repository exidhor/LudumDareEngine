#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "TestHelper.hpp"
#include "Physic/Vec2.hpp"
#include "AI/AIComponent.hpp"
#include "AI/Kinematic/KinematicBehaviors.hpp"

#define MAX_SEEK_SPEED 100

enum EBehaviors
{
	NONE,
	SEEK,
	FLEE,
	ARRIVING,
	WANDER
};

int manageInput(sf::RenderWindow & window,
				std::vector<sf::RectangleShape> & rects,
				std::vector<AIComponent> & ias,
				int selectedShapeIndex,
				sf::Vector2f & offset)
{
	sf::Event event;

	EBehaviors currentBehavior(EBehaviors::NONE);
	// handle the behaviors selection
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && selectedShapeIndex != -1)
	{
		currentBehavior = EBehaviors::SEEK;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && selectedShapeIndex != -1)
	{
		currentBehavior = EBehaviors::FLEE;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) && selectedShapeIndex != -1)
	{
		currentBehavior = EBehaviors::ARRIVING;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R) && selectedShapeIndex != -1)
	{
		currentBehavior = EBehaviors::WANDER;
	}

	// handle the shape selection or the target
	Vec2 target;
	bool targetIsSet = false;

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		sf::Vector2f mousePosition(sf::Mouse::getPosition(window));

		bool touchShape = false;
		for (unsigned i = 0; i < rects.size(); i++)
		{
			if (rects[i].getGlobalBounds().contains(mousePosition))
			{
				selectedShapeIndex = i;
				offset = rects[selectedShapeIndex].getPosition() - mousePosition;
				touchShape = true;
				break;
			}

			if(!touchShape && currentBehavior != EBehaviors::NONE)
			{
				targetIsSet = true;
				target = mousePosition;
			}
		}
	}


	// handle exit status
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
	}

	return selectedShapeIndex;
}

void configureSteering(int selectedShapeIndex,
					   EBehaviors behavior,
					   bool targetIsSet, 
					   Vec2 const& target, 
					   std::vector<AIComponent> & ias)
{
	if(selectedShapeIndex == -1 || behavior == EBehaviors::NONE)
	{
		return;
	}

	switch(behavior)
	{
	case SEEK :
		if (!targetIsSet)
			return;

		ias[selectedShapeIndex].SetKinematicSteering(new KinematicSeek(ias[selectedShapeIndex].GetLocation(),
													                   MAX_SEEK_SPEED,
													                   ));

		std::cout << "SEEK selected (target : " << target.x << ", " << target.y  << ")" << std::endl;
		break;

	case FLEE :
		if (!targetIsSet)
			return;

		std::cout << "FLEE selected (target : " << target.x << ", " << target.y << ")" << std::endl;
		break;

	case ARRIVING :
		if (!targetIsSet)
			return;

		std::cout << "ARRIVING selected (target : " << target.x << ", " << target.y << ")" << std::endl;
		break;

	case WANDER :


		std::cout << "WANDER selected" << std::endl;
		break;
	}
}

void init(std::vector<sf::RectangleShape> & rects, sf::Vector2u const& windowSize)
{
	sf::Vector2u minSize(10, 10);
	sf::Vector2u maxSize(100, 100);

	for (unsigned i = 0; i < rects.size(); i++)
	{
		rects[i].setSize(getRandomSize(minSize, maxSize));
		rects[i].setFillColor(getRandomColor());
		rects[i].setPosition(getRandomPosition(windowSize));
	}
}

void testKinematicBehaviors()
{
	sf::RenderWindow window(sf::VideoMode(1000, 800), "Test Kinematic Behaviors");

	std::vector<sf::RectangleShape> rects(10, sf::RectangleShape());
	init(rects, window.getSize());
	
	std::vector<AIComponent> ais;
	for (int i = 0; i < rects.size(); i++)
	{
		ais.push_back(AIComponent(&rects[i]));
	}

	sf::Vector2f offset;
	int selectedShapeIndex = -1;

	sf::Clock c;

	while (window.isOpen())
	{
		float time = c.getElapsedTime().asSeconds();
		c.restart();

		selectedShapeIndex = manageInput(window, rects, ais, selectedShapeIndex, offset);

		// update IAs
		for(int i = 0; i < ais.size(); i++)
		{
			ais[i].Update(time);
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