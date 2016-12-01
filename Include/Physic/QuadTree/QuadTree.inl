
template <class Object>
QuadTree<Object>::QuadTree(sf::IntRect const& bounds,
						   unsigned maxObjectPerLevel,
						   unsigned maxLevel)
	:m_root(0,// the level of the root is obviously the first (0)
			bounds,
			maxObjectPerLevel,
			maxLevel)
{
	// nothing
}

template <class Object>
void QuadTree<Object>::Clear()
{
	m_root.Clear();
}

template <class Object>
bool QuadTree<Object>::Remove(Object object)
{
	return m_root.Remove(object);
}

template <class Object>
void QuadTree<Object>::Insert(Object object, sf::FloatRect const& rect)
{
	m_root.Insert(QuadTreeContainer<Object>(object, rect));
}

template <class Object>
std::vector<Object> QuadTree<Object>::Retrieve(sf::FloatRect const& researchZone)
{
	std::vector <Object> objects;

	return m_root.Retrieve(objects, researchZone);

	return objects;
}