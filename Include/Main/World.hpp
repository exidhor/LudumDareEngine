#pragma once
#include <vector>
#include "Component/GameObject.hpp"

class World
{
public :
	World(unsigned reserveSize = 0);

	void Register(GameObject * gameObject);
	bool Unregister(GameObject * gameObject);

	void GetDrawable(std::vector<GameObject*> & output) const;
	void GetSortedDrawable(std::vector<GameObject*> & output) const;
	void GetPhysics(std::vector<GameObject*> & output) const;
	void GetLayer(int layer, std::vector<GameObject*> & output) const;

private :
	void Sort(std::vector<GameObject*>& vector) const;

	std::vector<GameObject*> m_active;
};
