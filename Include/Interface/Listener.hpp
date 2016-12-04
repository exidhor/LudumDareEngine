//
// Created by Kraghan on 04/12/2016.
//

#ifndef LUDUMDAREENGINE_LISTENER_HPP
#define LUDUMDAREENGINE_LISTENER_HPP


#include <SFML/Window/Event.hpp>

class Listener {
    //------------------------------------------------------------------------------------------------------------------
    /// Public members
    //------------------------------------------------------------------------------------------------------------------
public:
    /*!
     * \Brief Default constructor
     */
    explicit            Listener                ();

    /*!
     * \Brief Default destructor
     */
    virtual             ~Listener               ();

    /*!
     * \Brief Function called when an event is triggered
     * \Param event sf::Event event triggered
     */
    virtual void        onClick                 (sf::Event event) = 0;

    //------------------------------------------------------------------------------------------------------------------
    /// Protected members
    //------------------------------------------------------------------------------------------------------------------
protected:

    //------------------------------------------------------------------------------------------------------------------
    /// Private members
    //------------------------------------------------------------------------------------------------------------------
private:
};


#endif //LUDUMDAREENGINE_LISTENER_HPP
