#include "Component/RenderComponent.hpp"

RenderComponent::RenderComponent()
	: m_sprite(),
	m_available(true)
{
	// nothing
}

RenderComponent::RenderComponent(sf::Texture const& texture)
	: m_sprite(texture),
	m_available(true)
{
	// nothing
}

RenderComponent::RenderComponent(const sf::Texture &texture, const sf::IntRect &rectangle)
	: m_sprite(texture, rectangle),
	m_available(true)
{
	// nothing
}

sf::Transformable * RenderComponent::GetTranformable() {
	return &m_sprite;
}

void RenderComponent::Enable()
{
	m_available = true;
}

void RenderComponent::Disable()
{
	m_available = false;
}

bool RenderComponent::IsAvailable() const
{
	return m_available;
}

void RenderComponent::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	if(m_available)
	{
		target.draw(m_sprite, states);
	}
}

sf::Sprite *RenderComponent::GetSprite()
{
    return &m_sprite;
}
