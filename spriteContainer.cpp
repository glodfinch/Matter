#include "spriteContainer.h"
#include <iostream>

SpriteContainer::SpriteContainer( std::string file )
{
    type = 1;

	if ( !texture.loadFromFile( file ) )
	{
		std::cerr << "Error loading file " << file << std::endl;
	}

	sprite.setTexture( texture );
}
