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
	std::vector<PhysicsComponent*> collisions = m_quadTree.Retrieve(GetGlobalRect(ray));

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
	// Check if the start of the ray is inside the rect
	bool isInside = rect.contains(ray.start);

	//				 top
	//			 -----------
	//    left  |			|  right
	//			|			|
	//			 ----------- 
	//               bot

	bool checkLeftEdge = false;
	bool checkTopEdge = false;
	bool checkRightEdge = false;
	bool checkBotEdge = false;

	if(isInside)
	{
		
	}
	else
	{
		
	}

	return CollisionToken(); // todo : return an object set
}

int PhysicEngine::GetClosestPoint(Ray const& ray, std::vector<CollisionToken> const& points) const
{
	float bestDistance = FLT_MAX;
	int bestIndex = -1;

	float currentDistance = 0;

	for(int i = 0; i < points.size(); i++)
	{
		currentDistance = ray.start.SquareDistance(points[i]);

		if(currentDistance < bestDistance)
		{
			bestDistance = currentDistance;
			bestIndex = i;
		}
	}

	return bestIndex;
}

sf::FloatRect PhysicEngine::GetGlobalRect(Ray const& ray) const
{
	sf::FloatRect researchZone;
	
	bool x_start_smaller = ray.start.x < ray.end.x;
	bool y_start_smaller = ray.start.y < ray.end.y;

	if(x_start_smaller)
	{
		researchZone.left = ray.start.x;
		researchZone.width = ray.end.x - ray.start.x;
	}
	else
	{
		researchZone.left = ray.end.x;
		researchZone.width = ray.start.x - ray.end.x;
	}

	if(y_start_smaller)
	{
		researchZone.top = ray.start.y;
		researchZone.height = ray.end.y - ray.start.y;
	}
	else
	{
		researchZone.top = ray.end.y;
		researchZone.height = ray.start.y - ray.end.y;
	}

	return researchZone;
}

HitPoint PhysicEngine::GetHitPoint(Ray const& one, Ray const& second) const
{
	float scalarProduct = (one.start.x - one.end.x) * (second.start.y - second.end.y)
		- (one.start.y - one.end.y) * (second.start.x - second.end.x);

	if (scalarProduct == 0) return HitPoint();

	float xi = ((second.start.x - second.end.x) * (one.start.x * one.end.y - one.start.y * one.end.x)
				- (one.start.x - one.end.x) * (second.start.x * second.end.y - second.start.y * second.end.x)) / scalarProduct;

	float yi = ((second.start.y - second.end.y) * (one.start.x * one.end.y - one.start.y * one.end.x)
				- (one.start.y - one.end.y) * (second.start.x * second.end.y - second.start.y * second.end.x)) / scalarProduct;

	if (second.start.x == second.end.x)
	{
		if (yi < std::min(one.start.y, one.end.y) || yi > std::max(one.start.y, one.end.y))
			return HitPoint();
	}

	Vec2 intersection(xi, yi);

	if (xi < std::min(one.start.x, one.end.x) || xi > std::max(one.start.x, one.end.x))
		return HitPoint();
	if (xi < std::min(second.start.x, second.end.x) || xi > std::max(second.start.x, second.end.x))
		return HitPoint();

	if (yi < std::min(one.start.y, one.end.y) || yi > std::max(one.start.y, one.end.y))
		return HitPoint();
	if (yi < std::min(second.start.y, second.end.y) || yi > std::max(second.start.y, second.end.y))
		return HitPoint();

	return intersection;
}