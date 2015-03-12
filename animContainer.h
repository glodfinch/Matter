#ifndef ANIMCONTAINER_H
#define ANIMCONTAINER_H

#include "container.h"
#include "frame.h"
#include <vector>


class AnimContainer: public Container
{
	public:
		std::vector<Frame> textureBank;
		unsigned int currentFrame = 0;
		int currentDelay = 0;

		AnimContainer( std::vector<std::string>& files, std::vector<int>& del );
		void incFrame();
};

#endif // SPRITECONTAINER_H
