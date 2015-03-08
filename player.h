#ifndef PLAYER_H
#define PLAYER_H

#include "container.h"
#include "frame.h"
#include "message.h"
#include <vector>
#include <SFML/Graphics.hpp>
#include <string>

class Player: public Container
{
    public:
        std::vector<Frame> textureBank;
		sf::Sprite sprite;
		int currentFrame = 0;
		int currentDelay = 0;
        float xVel = 0;
        float yVel = 0;
        bool KEYBOARD_W, KEYBOARD_A, KEYBOARD_S, KEYBOARD_D, KEYBOARD_WS, KEYBOARD_AD;

        Player( std::vector<std::string>& files, std::vector<int>& del );
        void update();
        void recvMessage( std::shared_ptr<Message>& msg );
};

#endif // PLAYER_H
