#pragma once
#include <SFML/Graphics.hpp>

class RenderComponent : public sf::Drawable
{
public :
	RenderComponent();

	RenderComponent(sf::Texture const& texture);

	RenderComponent(const sf::Texture &texture, const sf::IntRect &rectangle);

	sf::Transformable* GetTranformable();

	void Enable();
	void Disable();

	bool IsAvailable() const;

protected :
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

private :
	sf::Sprite m_sprite;
	bool m_available;
};
