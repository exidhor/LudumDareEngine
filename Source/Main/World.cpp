#include "Main/World.hpp"

World::World(unsigned reserveSize)
{
	m_active.reserve(reserveSize);
}

void World::Register(GameObject * gameObject)
{
	m_active.push_back(gameObject);
}

bool World::Unregister(GameObject * gameObject)
{
	for(unsigned i = 0; i < m_active.size(); i++)
	{
		if(m_active[i] == gameObject)
		{
			m_active.erase(m_active.begin() + i);
			return true;
		}
	}

	return false;
}

void World::GetRenders(std::vector<GameObject*> & output) const
{
	for(unsigned i = 0; i < m_active.size(); i++)
	{
		if(m_active[i]->GetComponent<RenderComponent>() != nullptr)
		{
			output.push_back(m_active[i]);
		}
	}
}

void World::GetSortedRenders(std::vector<GameObject*> & output) const
{
	GetRenders(output);

	Sort(output);
}

void World::GetPhysics(std::vector<GameObject*> & output) const
{
	for(unsigned i = 0; i < m_active.size(); i++)
	{
		if(m_active[i]->GetComponent<PhysicsComponent>() != nullptr)
		{
			output.push_back(m_active[i]);
		}
	}
}

void World::GetLayer(int layer, std::vector<GameObject*> & output) const
{
	for(unsigned i = 0; i < m_active.size(); i++)
	{
		if(m_active[i]->GetLayer() == layer)
		{
			output.push_back(m_active[i]);
		}
	}
}

void World::Sort(std::vector<GameObject*>& vector) const
{
	struct
	{
		bool operator()(GameObject* a, GameObject* b)
		{
			sf::Vector2f const& a_position = a->GetTransformable()->getPosition();
			sf::Vector2f const& b_position = b->GetTransformable()->getPosition();

			if(a_position.y < b_position.y)
			{
				return true;
			}
			
			if(a_position.y == b_position.y)
			{
				return a_position.x < b_position.x;
			}

			return false;
		}

	} compare;


	std::sort(vector.begin(), vector.end(), compare);
}