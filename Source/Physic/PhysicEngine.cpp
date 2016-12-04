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
		HitPoint hitPoint = Intersects(collisions[i]->getCollider(), ray);
		
		if(hitPoint)
		{
			collisionTokens.push_back(CollisionToken(hitPoint, collisions[i]));
		}
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

HitPoint PhysicEngine::Intersects(sf::FloatRect const& rect, Ray const& ray)
{
	// Check if the start of the ray is inside the rect
	bool rayIsInside = rect.contains(ray.start);

	//		names for the edges
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

	bool startIsSmaller_x = ray.start.x < ray.end.x;
	bool startIsSmaller_y = ray.start.y < ray.end.y;
 
	if(rayIsInside)
	{
		startIsSmaller_x = !startIsSmaller_x;
		startIsSmaller_y = !startIsSmaller_y;
	}

	if (startIsSmaller_x)
		checkLeftEdge = true;
	else
		checkRightEdge = true;

	if (startIsSmaller_y)
		checkTopEdge = true;
	else
		checkBotEdge = true;

	HitPoint hitPoint_a;
	HitPoint hitPoint_b;

	if(checkLeftEdge)
	{
		hitPoint_a = GetHitPoint(ray, Ray(Vec2(rect.left, rect.top),
							              Vec2(rect.left, rect.top + rect.height)));
	}
	else //if(checkRightEdge)
	{
		hitPoint_a = GetHitPoint(ray, Ray(Vec2(rect.left + rect.width, rect.top),
								          Vec2(rect.left + rect.width, rect.top + rect.height)));
	}
	if (checkTopEdge)
	{
		hitPoint_b = GetHitPoint(ray, Ray(Vec2(rect.left, rect.top),
								          Vec2(rect.left + rect.width, rect.top)));
	}
	else //if(checkBotEdge)
	{
		hitPoint_b = GetHitPoint(ray, Ray(Vec2(rect.left, rect.top + rect.height),
							              Vec2(rect.left + rect.width, rect.top + rect.height)));
	}

	bool best_is_a;

	// find the best hitpoint
	if(hitPoint_a && !hitPoint_b)
	{
		return hitPoint_a;
	}
	else if(!hitPoint_a && hitPoint_b)
	{
		return hitPoint_b;
	}
	else
	{
		float distance_to_a = ComputeSquareLength(ray.start, hitPoint_a);
		float distance_to_b = ComputeSquareLength(ray.start, hitPoint_b);

		if (distance_to_a < distance_to_b)
			return hitPoint_a;
		else
			return hitPoint_b;
	}
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

float PhysicEngine::ComputeSquareLength(Vec2 const& point_a, Vec2 const& point_b)
{
	return (point_a.x - point_b.x) * (point_a.x - point_b.x)
		+ (point_a.y - point_b.y) * (point_a.y - point_b.y);
}