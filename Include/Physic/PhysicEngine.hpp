#pragma once
#include <cfloat>
#include "Physic/QuadTree/QuadTree.hpp"
#include "Physic/Vec2.hpp"
#include "Physic/Ray.hpp"
#include "Main/World.hpp"
#include "Component/PhysicsComponent.hpp"

#define MAX_OBJECT_PER_LEVEL 10
#define MAX_LEVEL            5

class CollisionToken
{
public :
	CollisionToken()
		: collisionFound(false),
		collisionPoint(),
		physicsComponent(nullptr)
	{
		// nothing
	}

	CollisionToken(Vec2 const& collisionPoint,
				   PhysicsComponent* physicsComponent)
		: collisionFound(true),
		collisionPoint(collisionPoint),
		physicsComponent(physicsComponent)
	{
		// nothing
	}

	operator Vec2() const
	{
		return collisionPoint;
	}

	bool collisionFound;
	Vec2 collisionPoint;
	PhysicsComponent* physicsComponent;
};

class PhysicEngine
{
public :
	PhysicEngine(sf::IntRect const& bounds);

	void Prepare(World const& world);

private :

	CollisionToken ShootRaycast(Ray const& ray);

	std::vector<CollisionToken> GetCollision(Ray const& ray);

	std::vector<PhysicsComponent*> GetCollision(sf::FloatRect const& rect);

	std::vector<PhysicsComponent*> GetCollision(Vec2 const& point);

	CollisionToken Intersects(sf::FloatRect const& rect, Ray const& ray);

	int GetClosestPoint(Ray const& ray, std::vector<CollisionToken> const& points) const;


	QuadTree<PhysicsComponent*> m_quadTree;
};
