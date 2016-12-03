#include "Component/RenderComponent.hpp"

RenderComponent::RenderComponent()
	: sf::Sprite(),
	m_available(true)
{
	// nothing
}

RenderComponent::RenderComponent(sf::Texture const& texture)
	: sf::Sprite(texture),
	m_available(true)
{
	// nothing
}

RenderComponent::RenderComponent(const sf::Texture &texture, const sf::IntRect &rectangle)
	: sf::Sprite(texture, rectangle),
	m_available(true)
{
	// nothing
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
		sf::Drawable::draw(target, states);
	}
}