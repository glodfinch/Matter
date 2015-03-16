#ifndef SPRITECONTAINER_H
#define SPRITECONTAINER_H

#include <SFML/Graphics.hpp>
#include "container.h"
#include "collisionBox.h"

class SpriteContainer: public Container
{
	public:
		sf::Texture texture;

		SpriteContainer( std::string file );
		void update() {};
};

#endif // SPRITECONTAINER_H
