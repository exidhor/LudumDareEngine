/// \file    GameObject.hpp
/// \date    03/12/2016
/// \brief   Contains the header of the class GameObject
/// \author  Aredhele
/// \version 0.1.0

#pragma once
#include <iostream>
#include "Component/AIComponent.hpp"
#include "Component/SoundComponent.hpp"
#include "Component/RenderComponent.hpp"
#include "Component/PhysicsComponent.hpp"

#ifndef __GAME_OBJECT_HPP
#define __GAME_OBJECT_HPP

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

    template <typename T>
    void RemoveComponent();

    void SetLayer(int layer);

    int GetLayer() const;

    sf::Transformable* GetTransformable();

    Vec2 GetCenteredPosition() const;

private:

    int m_layer;

    AIComponent* m_ai;
    SoundComponent * m_sound;
    PhysicsComponent* m_physics;
    RenderComponent m_render;
};

#include "Component/GameObject.inl"

#endif // __GAME_OBJECT_HPP

