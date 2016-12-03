#pragma once
#include <vector>
#include "Component/GameObject.hpp"

class World
{
public :
	World(unsigned reserveSize = 0);

	void Register(GameObject * gameObject);
	bool Unregister(GameObject * gameObject);

	std::vector<GameObject*> GetDrawable() const;

	std::vector<GameObject*> GetPhysics() const;

	std::vector<GameObject*> GetLayer(int layer) const;

private :
	std::vector<GameObject*> m_active;
};
