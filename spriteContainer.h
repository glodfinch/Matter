#ifndef SPRITECONTAINER_H
#define SPRITECONTAINER_H

#include <SFML/Graphics.hpp>
#include "container.h"

class SpriteContainer: public Container
{
	public:
		sf::Texture texture;

		SpriteContainer( std::string file );
};

#endif // SPRITECONTAINER_H
