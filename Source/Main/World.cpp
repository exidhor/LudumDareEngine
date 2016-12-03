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

std::vector<GameObject*> World::GetDrawable() const
{
	std::vector<GameObject*> drawable;

	for(unsigned i = 0; i < m_active.size(); i++)
	{
		if(m_active[i]->GetComponent<RenderComponent>() != nullptr)
		{
			drawable.push_back(m_active[i]);
		}
	}

	return drawable;
}

std::vector<GameObject*> World::GetPhysics() const
{
	
}

std::vector<GameObject*> World::GetLayer(int layer) const
{
	
}