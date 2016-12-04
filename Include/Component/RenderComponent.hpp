#pragma once
#include <SFML/Graphics.hpp>

class RenderComponent : public sf::Drawable
{
public :
	RenderComponent();

	RenderComponent(sf::Texture const& texture);

	RenderComponent(const sf::Texture &texture, const sf::IntRect &rectangle);

	sf::Transformable * GetTranformable();

	const sf::Transformable * GetTranformable() const;

	void Enable();
	void Disable();

	bool IsAvailable() const;

	sf::Sprite * GetSprite();

	const sf::Sprite * GetSprite() const;

protected :
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

private :
	sf::Sprite m_sprite;
	bool m_available;
};
