/// \file    GameObject.hpp
/// \date    03/12/2016
/// \brief   Contains the header of the class GameObject
/// \author  Aredhele
/// \version 0.1.0

#ifndef __GAME_OBJECT_HPP
#define __GAME_OBJECT_HPP

#include <vector>
#include <iostream>
#include "Physic/PhysicsComponent.hpp"

/// \class  GameObject
/// \brief  Base class for all objects manipulated by the engine
class GameObject
{
public :

    GameObject();

private:

    PhysicsComponent * m_physicComponent; ///< The physic component
};

#include "Component/GameObject.inl"

#endif // __GAME_OBJECT_HPP

