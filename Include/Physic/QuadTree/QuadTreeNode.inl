
template<class Object>
QuadTreeNode<Object>::QuadTreeNode(int level, 
						   sf::IntRect const& bounds,
						   unsigned maxObjectPerLevel,
						   unsigned maxLevel)
	: m_maxObjectPerLevel(maxObjectPerLevel),
	m_maxLevel(maxLevel),
	m_level(level),
	m_bounds(bounds),
	m_nodes(QUADTREE_ARRAY_SIZE)
{
	// nothing
}


template<class Object>
void QuadTreeNode<Object>::Clear()
{
	m_containers.clear();

	for (unsigned i = 0; i < m_nodes.size(); i++)
	{
		if (m_nodes[i] != nullptr)
		{
			m_nodes[i]->Clear();
			m_nodes[i] = nullptr;
		}
	}
}

template<class Object>
bool QuadTreeNode<Object>::Remove(Object object)
{
	int containerIndex = find(object);
	
	if (containerIndex != -1)
	{
		m_containers.erase(m_containers.begin() + containerIndex);
	}
	else if (m_nodes[0] != nullptr) // means that the current QuadTreeNode was splitted
	{
		for (unsigned i = 0; i < m_nodes.size(); i++)
		{
			if (m_nodes[i].Remove(object))
				return true;
		}
	}

	return false;
}

template<class Object>
void QuadTreeNode<Object>::Split()
{
	int subWidth = (int)(m_bounds.width / 2);
	int subHeight = (int)(m_bounds.height / 2);
	int x = (int)m_bounds.left;
	int y = (int)m_bounds.top;

	unsigned newLevel = m_level + 1;

	m_nodes[0] = new QuadTreeNode(newLevel,
								  sf::IntRect(x + subWidth, y, subWidth, subHeight),
								  m_maxObjectPerLevel,
								  m_maxLevel);

	m_nodes[1] = new QuadTreeNode(newLevel,
								  sf::IntRect(x, y, subWidth, subHeight),
								  m_maxObjectPerLevel,
								  m_maxLevel);

	m_nodes[2] = new QuadTreeNode(newLevel,
								  sf::IntRect(x, y + subHeight, subWidth, subHeight),
								  m_maxObjectPerLevel,
								  m_maxLevel);

	m_nodes[3] = new QuadTreeNode(newLevel,
								  sf::IntRect(x + subWidth, y + subHeight, subWidth, subHeight),
								  m_maxObjectPerLevel,
								  m_maxLevel);
}

template<class Object>
int QuadTreeNode<Object>::GetIndex(sf::FloatRect const& rect)
{
	int index = -1;
	double verticalMidPoint = m_bounds.left + (m_bounds.width / 2);
	double horizontalMidPoint = m_bounds.top + (m_bounds.height / 2);

	// Object can completely fit within the top quadrants
	bool topQuadrant = (rect.top < horizontalMidPoint
							&& rect.top + rect.height < horizontalMidPoint);

	// Object can completely fit within the bottom quadrants
	bool botQuadrant = (rect.top > horizontalMidPoint);

	if (rect.left < verticalMidPoint && rect.left + rect.width < verticalMidPoint)
	{
		if (topQuadrant)
			index = 1;

		else if (botQuadrant)
			index = 2;
	}

	// Object can completely fit within the right quadrants
	else if (rect.left > verticalMidPoint)
	{
		if (topQuadrant)
			index = 0;

		else if (botQuadrant)
			index = 3;
	}

	return index;
}

template<class Object>
void QuadTreeNode<Object>::Insert(QuadTreeContainer<Object> const& container)
{
	if (m_nodes[0] != nullptr)
	{
		int index = GetIndex(container.GetRect());

		if (index != -1)
		{
			m_nodes[index]->Insert(container);
			return;
		}
	}

	m_containers.push_back(container);

	if (m_containers.size() > m_maxObjectPerLevel 
		&& m_level < m_maxLevel)
	{
		if (m_nodes[0] == nullptr)
			Split();

		int containerIndex = 0;

		while (containerIndex < m_containers.size())
		{
			int quadTreeIndex = GetIndex(m_containers[containerIndex].GetRect());
			if (quadTreeIndex != -1)
			{
				// move the container from the parent QuadTreeNode to the child
				m_nodes[quadTreeIndex]->Insert(m_containers[containerIndex]);
				m_containers.erase(m_containers.begin() + containerIndex);
			}
			else
			{
				containerIndex++;
			}

		}
	}
}

template<class Object>
std::vector<Object> QuadTreeNode<Object>::Retrieve(std::vector<Object> & returnObjects,
												   sf::FloatRect const& researchZone)
{
	if (m_nodes[0] != nullptr)
	{
		int quadTreeIndex = GetIndex(researchZone);

		if (quadTreeIndex != -1)
		{
			m_nodes[quadTreeIndex]->Retrieve(returnObjects, researchZone);
		}
		else
		{
			for (unsigned i = 0; i < m_nodes.size(); i++)
			{
				m_nodes[i]->Retrieve(returnObjects, researchZone);
			}
		}
	}

	// add the m_container into the returnObjects vector
	for(unsigned i = 0; i < m_containers.size(); i++)
	{
		returnObjects.push_back(m_containers[i].GetObject());
	}

	return returnObjects;
}

template<class Object>
int QuadTreeNode<Object>::FindIndex(Object object)
{
	for(unsigned i = 0; i < m_containers.size(); i++)
	{
		if (m_containers[i].GetObject() == object)
			return i;
	}

	return -1;
}