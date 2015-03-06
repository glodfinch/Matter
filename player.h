#ifndef PLAYER_H
#define PLAYER_H

#include "container.h"
#include "frame.h"
#include <vector>
#include <SFML/Graphics.hpp>

class Player: public Container
{
    public:
		std::vector<Frame> textureBank;
		sf::Sprite sprite;
		int currentFrame = 0;
		int currentDelay = 0;
        float xVel = 1;
        float yVel = 0;

        Player( std::vector<std::string>& files, std::vector<int>& del );
        void update();
};

#endif // PLAYER_H
