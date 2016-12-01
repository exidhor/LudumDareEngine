#pragma once
#include "Physic/QuadTree/QuadTreeNode.hpp"

template <class Object>
class QuadTree
{
public :
	QuadTree(sf::IntRect const& bounds,
			 unsigned maxObjectPerLevel,
			 unsigned maxLevel);

	void Clear();

	bool Remove(Object object);

	void Insert(Object object, sf::FloatRect const& rect);

	std::vector<Object> Retrieve(sf::FloatRect const& researchZone);

private :
	QuadTreeNode<Object> m_root;
};

#include "Physic/QuadTree/QuadTree.inl"