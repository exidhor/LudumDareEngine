#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "TestHelper.hpp"
#include "Physic/Vec2.hpp"
#include "AI/AIComponent.hpp"
#include "AI/Kinematic/KinematicBehaviors.hpp"
#include "Physic/Location/StationaryLocation.hpp"

#define MAX_SEEK_SPEED 100

#define MAX_FLEE_SPEED 100

#define MAX_ARRIVE_SPEED 100
#define ARRIVE_RADIUS 5.0f
#define TIME_TO_TARGET 5.0f

#define MAX_WANDER_SPEED 100
#define MAX_WANDER_ROTATION 50

#define NUMBER_RECTS 10


enum EBehaviors
{
	NONE,
	SEEK,
	FLEE,
	ARRIVING,
	WANDER,
	STOP
};

int manageInput(sf::RenderWindow & window,
				std::vector<sf::RectangleShape> & rects,
				std::vector<AIComponent> & ias,
				int selectedShapeIndex,
				sf::Vector2f & offset,
				std::vector<KinematicSeek> & seeks,
				std::vector<KinematicFlee> & flees,
				std::vector<KinematicArrive> & arrives,
				std::vector<KinematicWander> & wanders)
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
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::T) && selectedShapeIndex != -1)
	{
		currentBehavior = EBehaviors::STOP;
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
					   std::vector<AIComponent> & ias,
					   std::vector<KinematicSeek> & seeks,
					   std::vector<KinematicFlee> & flees,
					   std::vector<KinematicArrive> & arrives,
					   std::vector<KinematicWander> & wanders)
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

		ias[selectedShapeIndex].SetKinematicSteering(&seeks[selectedShapeIndex]);
		seeks[selectedShapeIndex].setTargetPosition(new StationaryLocation(target));

		std::cout << "SEEK selected (target : " << target.x << ", " << target.y  << ")" << std::endl;
		break;

	case FLEE :
		if (!targetIsSet)
			return;

		ias[selectedShapeIndex].SetKinematicSteering(&flees[selectedShapeIndex]);
		flees[selectedShapeIndex].setTargetPosition(new StationaryLocation(target));

		std::cout << "FLEE selected (target : " << target.x << ", " << target.y << ")" << std::endl;
		break;

	case ARRIVING :
		if (!targetIsSet)
			return;

		ias[selectedShapeIndex].SetKinematicSteering(&arrives[selectedShapeIndex]);
		arrives[selectedShapeIndex].setTargetPosition(new StationaryLocation(target));

		std::cout << "ARRIVING selected (target : " << target.x << ", " << target.y << ")" << std::endl;
		break;

	case WANDER :

		ias[selectedShapeIndex].SetKinematicSteering(&wanders[selectedShapeIndex]);

		std::cout << "WANDER selected" << std::endl;
		break;

	case STOP :

		ias[selectedShapeIndex].SetKinematicSteering(nullptr);

		std::cout << "STOP selected" << std::endl;
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

	std::vector<sf::RectangleShape> rects(NUMBER_RECTS, sf::RectangleShape());
	
	init(rects, window.getSize());

	std::vector<KinematicSeek> seeks;
	std::vector<KinematicFlee> flees;
	std::vector<KinematicArrive> arrives;
	std::vector<KinematicWander> wanders;

	for(int i = 0; i < NUMBER_RECTS; i++)
	{
		seeks.push_back(KinematicSeek(MAX_SEEK_SPEED, nullptr));
		flees.push_back(KinematicFlee(MAX_FLEE_SPEED, nullptr));
		arrives.push_back(KinematicArrive(MAX_ARRIVE_SPEED, nullptr, TIME_TO_TARGET, ARRIVE_RADIUS));
		wanders.push_back(KinematicWander(MAX_WANDER_SPEED, MAX_WANDER_ROTATION));
	}
	
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

		selectedShapeIndex = manageInput(window, 
										 rects, 
										 ais, 
										 selectedShapeIndex, 
										 offset,
										 seeks,
										 flees,
										 arrives,
										 wanders);

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