#pragma once

// Forward declaration
#include "Component/GameObject.hpp"

#include <vector>

/**
 * \class World
 * \brief Gather all the GameObject of the Game into this class.
 *		  It provides an acces to the GameObject groups (RenderComponent, Physics, ...)
 */
class World
{
public :

	/**
	 * \brief	Initialize the GameObject array
	 * \param	reserveSize : the size which will be reserved
	 */
	World(unsigned reserveSize = 0);

	/**
	 * \brief   Add a GameObject to the Active GameObject.
	 *			Now it can is available for all the Engine
	 * \param	gameObject : the GameObject to register
	 */
	void Register(GameObject * gameObject);
	
	/**
	 * \brief	Remove a GameObject from the Active GameObject
	 * \param	gameObject : the GameObject to remove 
	 * \return	True if the GameObject was removed, False otherwise
	 */
	bool Unregister(GameObject * gameObject);

	/**
	 * \brief	Return all the GameObject which have a RenderComponent
	 *			from the Active GameObject
	 * \param	output : all the GameObject found are stored into this vector 
	 */
	void GetRenders(std::vector<GameObject*> & output) const;

	/**
	 * \brief	Return all the GameObject which have a RenderComponent
	 *			from the Active GameObject.
	 *			It stores them compared to their position.
	 * \param	output : all the GameObject found are stored into this vector
	 */
	void GetSortedRenders(std::vector<GameObject*> & output) const;

	/**
	 * \brief	Return all the GameObject which have a PhysicsComponent
	 *			from the Active GameObject.
	 * \param	output : all the GameObject found are stored into this vector
	 */
	void GetPhysics(std::vector<GameObject*> & output) const;

	/**
	 * \brief	Return all the GameObject which are in the same layer
	 *			from the Active GameObject.
	 * \param	layer : the layer we want
	 * \param	output : all the GameObject found are stored into this vector
	 */
	void GetLayer(int layer, std::vector<GameObject*> & output) const;

private :
	/**
	 * \brief	Sort the GameObject compared to their position.
	 *			The first element has the smallest y in his position.
	 * \param	vector : the vector to sort 
	 */
	void Sort(std::vector<GameObject*>& vector) const;

	std::vector<GameObject*> m_active;
};
