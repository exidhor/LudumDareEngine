/// \file    GameObject.hpp
/// \date    03/12/2016
/// \brief   Contains the header of the class GameObject
/// \author  Aredhele
/// \version 0.1.0

#ifndef __GAME_OBJECT_HPP
#define __GAME_OBJECT_HPP

#include <iostream>
#include "AI/AIComponent.hpp"
#include "Physic/PhysicsComponent.hpp"

/// \class  GameObject
/// \brief  Base class for all objects manipulated by the engine
class GameObject
{
public:

    /// \brief  Default constructor
    explicit GameObject(void);

    /// \brief  Default destructor
    virtual ~GameObject(void);

    /// \brief  Return the first component of type T
    /// \return The first component of type T, else nullptr
    template <typename T>
    T * GetComponent(void);

    /// \brief  Add a component to the game object
    ///         If the component exists, remove the old one
    ///         and create a new component of type T
    template <typename T>
    void AddComponent(void);

private:

    /// \brief  Return nullptr because there's no component of type T
    /// \return nullptr
    template <typename T>
    T * __GetComponent(void);

    /// \brief  Do nothing because the component doesn't exist
    template <typename T>
    void __AddComponent(void);
};

#include "Component/GameObject.inl"

#endif // __GAME_OBJECT_HPP

