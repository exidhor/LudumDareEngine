//
// Created by Kraghan on 04/12/2016.
//

#ifndef LUDUMDAREENGINE_BUTTON_HPP
#define LUDUMDAREENGINE_BUTTON_HPP

#pragma once
#include <SFML/Graphics.hpp>
#include "Listener.hpp"
#include <Component/GameObject.hpp>

class Button : public GameObject
{
    //------------------------------------------------------------------------------------------------------------------
    /// Public members
    //------------------------------------------------------------------------------------------------------------------
public:
    /*!
     * \Brief   Default constructor
     */
    explicit            Button              ();

    /*!
     * \Brief   Button with a sprite for normal state and a sprite for pressed state
     * \Param   detectionBox : Click detection area
     * \Param   normalStateTexture : A pointer on a Texture of the normal state of the button
     * \Param   pressedStateTexture : A pointer on a Texture of the pressed state of the button
     */
    explicit            Button              (sf::FloatRect detectionBox,
                                             sf::Texture* normalStateTexture,
                                             sf::Texture* pressedStateTexture);

    /*!
     * \Brief   Button with a sprite for normal, hover and pressed state
     * \Param   detectionBox : Click detection area
     * \Param   normalStateTexture : A pointer on a Texture of the normal state of the button
     * \Param   hoverStateTexture : A pointer on a Texture of the hover state of the button
     * \Param   pressedStateTexture : A pointer on a Texture of the pressed state of the button
     */
    explicit            Button              (sf::FloatRect detectionBox,
                                             sf::Texture* normalStateTexture,
                                             sf::Texture* hoverStateTexture,
                                             sf::Texture* pressedStateTexture);

    /// Default destructor
    virtual             ~Button             ();

    /// \Brief Add listener to the button
    /// \Param listener listener to add to the button
    void                addListener         (Listener* listener);

    /// \Brief Execute all the listeners if the event is correct
    /// \Param event sf::Event who trigger the button
    void                execute             (sf::Event event);

    //------------------------------------------------------------------------------------------------------------------
    /// Protected members
    //------------------------------------------------------------------------------------------------------------------
protected:

    //------------------------------------------------------------------------------------------------------------------
    /// Private members
    //------------------------------------------------------------------------------------------------------------------
private:
    /// The click/hover detection rect
    sf::FloatRect       m_detectionBox;

    /// The normal state sprite of the button
    sf::Texture*        m_pnormalTexture;

    /// The hover state sprite of the button
    sf::Texture*        m_phoverTexture;

    /// The pressed state sprite of the button
    sf::Texture*        m_ppressedTexture;

    /// The sprite of the button
    sf::Sprite*         m_psprite;

    /// Array of listener
    std::vector<Listener*> m_alistener;
};


#endif //LUDUMDAREENGINE_BUTTON_HPP
