#include "TextureManager.hpp"



void main()
{
	// ----------------- Test TextureManager -------------------------- 
	TextureManager textureManager;

	std::string brigandPath = "brigand_V2_little.png";
	std::string paysanPath = "paysanNu.png";

	textureManager.add("brigand_V2_little.png", "brigand");
	textureManager.add("paysanNu.png", "brigand");

	textureManager.add("Unknown_path", "paysan");
	textureManager.add("paysanNu.png", "paysan");

	// ----------------- Init Graphic Stuffs --------------------------

	sf::RenderWindow window(sf::VideoMode(1000, 800), "SFML works!");
	sf::Sprite spriteBrigand;
	sf::Sprite spritePaysan;

	// ---------------- Link Sprite with Texture ---------------------
	spriteBrigand.setTexture(textureManager.get("brigand"));
	//textureManager.get("unknown_key"); IMPOSSIBLE -> ABORT CALL
	spritePaysan.setTexture(textureManager.get("paysan"));

	// --------------- Positionning the Sprite ----------------------
	spriteBrigand.setPosition(500, 10);
	spritePaysan.setPosition(100, 500);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(spriteBrigand);
		window.draw(spritePaysan);
		window.display();
	}
}