#pragma once
#include <SFML/Graphics.hpp>
#include "Physic/QuadTree/QuadTreeContainer.hpp"

#define QUADTREE_ARRAY_SIZE 4 // because it's a "quad" tree 


template<class Object>
class QuadTreeNode
{
public:
	QuadTreeNode(int level,
			 sf::IntRect const& bounds,
			 unsigned maxObjectPerLevel,
			 unsigned maxLevel);

	/*!
	* \brief   clear the quadtree by recursively
	*          clearing all objects from all nodes.
	*/
	void Clear();


	/*!
	* \brief   Remove from the QuadTree an Object
	* \param   object : The object to remove
	* \return  true if the object was removed (and found !),
	*          false otherwise
	*/
	bool Remove(Object object);

	/*
	* \brief   Insert the object into the quadtree. If the node
	*          exceeds the capacity, it will split and add all
	*          objects to their corresponding nodes.
	* \param   a_Object The object to insert
	*/
	void Insert(QuadTreeContainer<Object> const& container);

	/*
	* \brief   Find all potential collisions for specific bounds
	* \param   returnObjects : the list of QTObject in collision
	*          with the specific bounds.
	* \param   researchZone : the specific bounds (i.e. the bounds of the
	*          object we want to test)
	* \return  the list of collided objects (use for recursive operation),
	*          which be the same as a_ReturnObjects at the end.
	*/
	std::vector<Object> Retrieve(std::vector<Object> & returnObjects,
								 sf::FloatRect const& researchZone);


private:
	/*!
	* \brief   splits the node into four subnodes by dividing
	*          the node into four equal parts and initializing
	*          the four subnodes with the new bounds.
	*/
	void Split();


	/*
	* \brief   Determine which node the object belongs to.
	* \param   rect : The hitbox of the object.
	* \return  The index of the QuadTree which the node belong to, or -1
	*          if there is no completely matching
	*/
	int GetIndex(sf::FloatRect const& rect);

	int FindIndex(Object object);

private:
	unsigned m_maxObjectPerLevel;
	unsigned m_maxLevel;

	int m_level;
	std::vector<QuadTreeContainer<Object>> m_containers;
	sf::IntRect m_bounds;
	std::vector<QuadTreeNode<Object>*> m_nodes;
};

#include "Physic/QuadTree/QuadTreeNode.inl"