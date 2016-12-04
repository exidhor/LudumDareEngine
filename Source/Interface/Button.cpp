//
// Created by Kraghan on 04/12/2016.
//

#include "Interface/Button.hpp"

Button::Button()
: m_detectionBox()
, m_pnormalTexture(nullptr)
, m_phoverTexture(nullptr)
, m_ppressedTexture(nullptr)
, m_psprite(nullptr)
{
    // None
}

Button::Button(sf::FloatRect detectionBox, sf::Texture *normalStateTexture, sf::Texture *pressedStateTexture)
: m_detectionBox(detectionBox)
, m_pnormalTexture(normalStateTexture)
, m_phoverTexture(nullptr)
, m_ppressedTexture(pressedStateTexture)
{
    //m_psprite = GetComponent<RenderComponent>()->GetSprite();
    m_psprite->setTexture(*m_pnormalTexture);
}

Button::Button(sf::FloatRect detectionBox, sf::Texture *normalStateTexture, sf::Texture *hoverStateTexture,
               sf::Texture *pressedStateTexture)
: m_detectionBox(detectionBox)
, m_pnormalTexture(normalStateTexture)
, m_phoverTexture(hoverStateTexture)
, m_ppressedTexture(pressedStateTexture)
{
    //m_psprite = GetComponent<RenderComponent>()->GetSprite();
    m_psprite->setTexture(*m_pnormalTexture);
}

Button::~Button()
{
    // None
}

void Button::addListener(Listener *listener)
{
    m_alistener.push_back(listener);
}

void Button::execute(sf::Event event)
{
    if(m_psprite == nullptr)
        return;

    if(event.type == sf::Event::MouseButtonPressed)
    {
        if(m_detectionBox.contains(event.mouseButton.x,event.mouseButton.y))
        {
            m_psprite->setTexture(*m_ppressedTexture);
        }
        else
        {
            m_psprite->setTexture(*m_pnormalTexture);
        }
    }
    else if(m_phoverTexture != nullptr
       && event.type == sf::Event::MouseMoved)
    {
        if(m_detectionBox.contains(event.mouseMove.x,event.mouseMove.y))
        {
            m_psprite->setTexture(*m_phoverTexture);
        }
        else
        {
            m_psprite->setTexture(*m_pnormalTexture);
        }
    }
    else
        return;

    for(auto listener : m_alistener)
        listener->onClick(event);
}

