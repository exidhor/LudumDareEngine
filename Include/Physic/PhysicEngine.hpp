#pragma once
#include <cfloat>
#include "Physic/QuadTree/QuadTree.hpp"
#include "Physic/Vec2.hpp"
#include "Physic/Ray.hpp"
#include "Main/World.hpp"
#include "Component/PhysicsComponent.hpp"

#define MAX_OBJECT_PER_LEVEL 10
#define MAX_LEVEL            5

class HitPoint
{
public:
	HitPoint()
		: hit(false)
	{}

	HitPoint(Vec2 const& point)
		: point(point),
		hit(true)
	{}

	operator Vec2() const
	{
		return point;
	}

	operator bool() const
	{
		return hit;
	}

	Vec2 point;
	bool hit;
};

class CollisionToken
{
public :
	CollisionToken()
		: physicsComponent(nullptr)
	{
		// nothing
	}

	CollisionToken(Vec2 const& collisionPoint,
				   PhysicsComponent* physicsComponent)
		: hitPoint(collisionPoint),
		physicsComponent(physicsComponent)
	{
		// nothing
	}

	operator Vec2() const
	{
		return hitPoint;
	}

	operator bool() const
	{
		return hitPoint;
	}

	operator PhysicsComponent*() const
	{
		return physicsComponent;
	}

	HitPoint hitPoint;
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

	sf::FloatRect GetGlobalRect(Ray const& ray) const;

	/*!
	* \brief   Find the intersection (Collision point) between two lines
	*          Source : http://www.ahristov.com/tutorial/geometry-games/intersection-segments.html
	* \param   one : first ray
	* \param   second : second ray
	* \return  A HitPoint which store the Position of the intersection if there is one
	*/
	HitPoint GetHitPoint(Ray const& one, Ray const& second) const;
	

	QuadTree<PhysicsComponent*> m_quadTree;
};
