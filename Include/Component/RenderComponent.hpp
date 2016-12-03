#pragma once
#include <SFML/Graphics.hpp>

class RenderComponent : public sf::Sprite
{
public :
	RenderComponent();

	RenderComponent(sf::Texture const& texture);

	RenderComponent(const sf::Texture &texture, const sf::IntRect &rectangle);

	void Enable();
	void Disable();

	bool IsAvailable() const;

protected :
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

private :
	bool m_available;
};
