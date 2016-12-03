#include "Physic/PhysicEngine.hpp"

PhysicEngine::PhysicEngine(sf::IntRect const& bounds)
	: m_quadTree(bounds, MAX_OBJECT_PER_LEVEL, MAX_LEVEL)
{
	// nothing
}

void PhysicEngine::Prepare(World const& world)
{
	m_quadTree.Clear();

	// TODO : add all the go of the world into the QuadTree
	//m_quadTree.Insert(...);
}

CollisionToken PhysicEngine::ShootRaycast(Ray const& ray)
{
	std::vector<CollisionToken> collisions = GetCollision(ray);

	int bestIndex = GetClosestPoint(ray, collisions);

	if(bestIndex == -1)
	{
		return CollisionToken();
	}

	return collisions[bestIndex];
}

std::vector<CollisionToken> PhysicEngine::GetCollision(Ray const& ray)
{
	sf::FloatRect researchZone(ray.start, ray.end);

	std::vector<PhysicsComponent*> collisions = m_quadTree.Retrieve(researchZone);

	std::vector<CollisionToken> collisionTokens;
	collisionTokens.reserve(collisions.size());

	for (int i = collisions.size() - 1; i >= 0; i--)
	{
		// todo : find how to compute the collision detection between a segment and a AABB
		// and store the collisionPoint into the CollisionToken
		//if (collisions[i]->getCollider().intersects(rect))
		//{
		//		collisionTokens.push_back(
		//}
	}

	return collisionTokens;
}

std::vector<PhysicsComponent*> PhysicEngine::GetCollision(sf::FloatRect const& rect)
{
	std::vector<PhysicsComponent*> collisions = m_quadTree.Retrieve(rect);

	for(int i = collisions.size() - 1; i >= 0; i--)
	{
		if(!collisions[i]->getCollider().intersects(rect))
		{
			collisions.pop_back();
		}
	}

	return collisions;
}

std::vector<PhysicsComponent*> PhysicEngine::GetCollision(Vec2 const& point)
{
	sf::FloatRect researchZone(point, Vec2(1, 1));

	std::vector<PhysicsComponent*> collisions = m_quadTree.Retrieve(researchZone);

	for (int i = collisions.size() - 1; i >= 0; i--)
	{
		if (!collisions[i]->getCollider().contains(point))
		{
			collisions.pop_back();
		}
	}

	return collisions;
}

CollisionToken PhysicEngine::Intersects(sf::FloatRect const& rect, Ray const& ray)
{
	// collision between the left segment

	// collision between the top segment

	// collision between the left segment

	// collision between the bot segment


	return CollisionToken(); // todo : return an object set
}

int PhysicEngine::GetClosestPoint(Ray const& ray, std::vector<CollisionToken> const& points) const
{
	float bestDistance = FLT_MAX;
	int bestIndex = -1;

	float currentDistance = 0;

	for(int i = 0; i < points.size(); i++)
	{
		currentDistance = ray.start.SquareDistance(points[i].collisionPoint);

		if(currentDistance < bestDistance)
		{
			bestDistance = currentDistance;
			bestIndex = i;
		}
	}

	return bestIndex;
}