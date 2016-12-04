#pragma once
#include "Physic/QuadTree/QuadTreeNode.hpp"

/**
 * \class QuadTree
 * \brief A quadtree is a tree data structure in which each internal
 *		  node has exactly four children.
 *		  So it works with recursion.
 *		  This structure is uses to optimize collision detections.
 */
template <class Object>
class QuadTree
{
public :
	/**
	 * \brief	Construct the QuadTree by constructing the root
	 * \param	bounds : the bounds for the collision (usually the window area)
	 * \param	maxObjectPerLevel : the maximum numbre of objects per level 
	 * \param	maxLevel : The maximum number of level
	 */
	QuadTree(sf::IntRect const& bounds,
			 unsigned maxObjectPerLevel,
			 unsigned maxLevel);

	/*!
	* \brief   clear the quadtree by recursively
	*          removing all objects from all nodes.
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
	void Insert(Object object, sf::FloatRect const& rect);

	/*
	* \brief   Find all potential collisions for specific bounds
	* \param   researchZone : the specific bounds (i.e. the bounds of the
	*          object we want to test)
	* \return  the list of collided objects
	*/
	std::vector<Object> Retrieve(sf::FloatRect const& researchZone);

private :
	QuadTreeNode<Object> m_root;
};

#include "Physic/QuadTree/QuadTree.inl"