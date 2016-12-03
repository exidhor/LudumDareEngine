#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "TestHelper.hpp"
#include "Physic/Vec2.hpp"
#include "Component/AIComponent.hpp"
#include "AI/Kinematic/KinematicBehaviors.hpp"
#include "Physic/Location/StationaryLocation.hpp"
#include "AI/Kinematic/KinematicPursue.hpp"

#define MAX_SEEK_SPEED 300

#define MAX_FLEE_SPEED 5

#define MAX_ARRIVE_SPEED 100
#define ARRIVE_TARGET_RADIUS 5.0f
#define ARRIVE_SLOW_RADIUS 50
#define TIME_TO_TARGET 0.1f

#define MAX_WANDER_SPEED 10
#define MAX_WANDER_ROTATION 50

#define PURSUE_MAX_SPEED 50
#define MAX_PREDICTION_TIME 2.0f

#define NUMBER_RECTS 10


enum EBehaviors
{
	NONE,
	SEEK,
	FLEE,
	ARRIVING,
	WANDER,
	PURSUE,
	STOP
};

void configureSteering(int selectedShapeIndex,
					   EBehaviors behavior,
					   bool targetIsSet,
					   bool targetIsPoint,
					   Vec2 const& target,
					   int targetIndex,
					   std::vector<AIComponent> & ias,
					   std::vector<KinematicSeek> & seeks,
					   std::vector<KinematicFlee> & flees,
					   std::vector<KinematicArrive> & arrives,
					   std::vector<KinematicWander> & wanders,
					   std::vector<KinematicPursue> & pursues)
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

		if(targetIsPoint)
		{
			seeks[selectedShapeIndex].SetTargetLocation(new StationaryLocation(target));
			std::cout << "SEEK selected (target : " << target.x << ", " << target.y << ")" << std::endl;
		}
		else
		{
			seeks[selectedShapeIndex].SetTargetLocation(ias[targetIndex].GetKinematic());
		}

		
		break;

	case FLEE :
		if (!targetIsSet)
			return;

		ias[selectedShapeIndex].SetKinematicSteering(&flees[selectedShapeIndex]);

		if (targetIsPoint)
		{
			flees[selectedShapeIndex].SetTargetLocation(new StationaryLocation(target));
			std::cout << "FLEE selected (target : " << target.x << ", " << target.y << ")" << std::endl;
		}
		else
		{
			flees[selectedShapeIndex].SetTargetLocation(ias[targetIndex].GetKinematic());
		}	
		break;

	case ARRIVING :
		if (!targetIsSet)
			return;

		ias[selectedShapeIndex].SetKinematicSteering(&arrives[selectedShapeIndex]);
		
		if (targetIsPoint)
		{
			arrives[selectedShapeIndex].SetTargetLocation(new StationaryLocation(target));
			std::cout << "ARRIVING selected (target : " << target.x << ", " << target.y << ")" << std::endl;
		}
		else
		{
			arrives[selectedShapeIndex].SetTargetLocation(ias[targetIndex].GetKinematic());
		}	
		break;

	case WANDER :

		ias[selectedShapeIndex].SetKinematicSteering(&wanders[selectedShapeIndex]);

		std::cout << "WANDER selected" << std::endl;
		break;

	case PURSUE :
		if (!targetIsSet || targetIsPoint)
			return;

		ias[selectedShapeIndex].SetKinematicSteering(&pursues[selectedShapeIndex]);
		pursues[selectedShapeIndex].SetPursueTarget(ias[targetIndex].GetKinematic());

		std::cout << "PURSUE selected" << std::endl;
		break;

	case STOP :

		ias[selectedShapeIndex].SetKinematicSteering(nullptr);

		std::cout << "STOP selected" << std::endl;
		break;
	}
}

void manageInput(sf::RenderWindow & window,
				std::vector<sf::RectangleShape> & rects,
				std::vector<AIComponent> & ias,
				int & selectedShapeIndex,
				std::vector<KinematicSeek> & seeks,
				std::vector<KinematicFlee> & flees,
				std::vector<KinematicArrive> & arrives,
				std::vector<KinematicWander> & wanders,
				std::vector<KinematicPursue> & pursues)
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
		currentBehavior = EBehaviors::PURSUE;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && selectedShapeIndex != -1)
	{
		currentBehavior = EBehaviors::STOP;
	}

	// handle the selection of the box
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		sf::Vector2f mousePosition(sf::Mouse::getPosition(window));

		for (unsigned i = 0; i < rects.size(); i++)
		{
			if (rects[i].getGlobalBounds().contains(mousePosition))
			{
				selectedShapeIndex = i;
				std::cout << "BOX SELECTED" << std::endl;
				break;
			}
		}
	}

	// handle the shape selection or the target
	bool targetIsSet = false;
	bool targetIsPoint = true;
	Vec2 target;
	int indexToTarget = -1;

	/*if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
	{   
		targetIsSet = true;

		target.x = sf::Mouse::getPosition(window).x;
		target.y = sf::Mouse::getPosition(window).y;

		for (unsigned i = 0; i < rects.size(); i++)
		{
			if (rects[i].getGlobalBounds().contains(target))
			{
				indexToTarget = i;
				targetIsPoint = false;
				std::cout << "BOX TARGETED" << std::endl;
				break;
			}
		}
	}*/

	if(currentBehavior != NONE)
	{
		targetIsSet = true;

		target.x = sf::Mouse::getPosition(window).x;
		target.y = sf::Mouse::getPosition(window).y;
		
		for (unsigned i = 0; i < rects.size(); i++)
		{
			if (rects[i].getGlobalBounds().contains(target))
			{
				indexToTarget = i;
				targetIsPoint = false;
				std::cout << "BOX TARGETED" << std::endl;
				break;
			}
		}
	}

	configureSteering(selectedShapeIndex, 
					  currentBehavior, 
					  targetIsSet,
					  targetIsPoint,
					  target,
					  indexToTarget,
					  ias, 
					  seeks,
					  flees, 
					  arrives, 
					  wanders,
					  pursues);

		// handle exit status
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
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
		rects[i].setOrigin(rects[i].getSize().x / 2, rects[i].getSize().y / 2);
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
	std::vector<KinematicPursue> pursues;

	for(int i = 0; i < NUMBER_RECTS; i++)
	{
		seeks.push_back(KinematicSeek(MAX_SEEK_SPEED, nullptr));
		flees.push_back(KinematicFlee(MAX_FLEE_SPEED, nullptr));
		arrives.push_back(KinematicArrive(MAX_ARRIVE_SPEED, nullptr, TIME_TO_TARGET, ARRIVE_TARGET_RADIUS, ARRIVE_SLOW_RADIUS));
		wanders.push_back(KinematicWander(MAX_WANDER_SPEED, MAX_WANDER_ROTATION));
		pursues.push_back(KinematicPursue(PURSUE_MAX_SPEED, nullptr, MAX_PREDICTION_TIME));
	}
	
	std::vector<AIComponent> ais;
	for (int i = 0; i < rects.size(); i++)
	{
		ais.push_back(AIComponent(&rects[i]));
	}

	sf::Vector2f offset;
	int selectedShapeIndex = -1;

	sf::Clock c;

	char a;

	while (window.isOpen())
	{
		float time = c.getElapsedTime().asSeconds();
		c.restart();

		manageInput(window,
					rects, 
					ais, 
					selectedShapeIndex, 
					seeks,
					flees,
					arrives,
					wanders,
					pursues);

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