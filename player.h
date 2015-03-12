#ifndef PLAYER_H
#define PLAYER_H

#include "container.h"
#include "frame.h"
#include "message.h"
#include <vector>
#include <string>

class Player: public Container
{
    public:
        std::vector<std::vector<Frame> > textureBanks;
		int currentFrame = 0;
		int currentDelay = 0;
        float xVel = 0;
        float yVel = 0;
        bool KEYBOARD_W = false;
        bool KEYBOARD_A = false;
        bool KEYBOARD_S = false;
        bool KEYBOARD_D = false;
        bool KEYBOARD_WS = false;
        bool KEYBOARD_AD = false;
        bool flip = false;
        int state = 1;

        Player( std::vector<std::string>& files, std::vector<int>& del );
        void update();
        void recvMessage( std::shared_ptr<Message>& msg );
        void changeState( int s );
};

#endif // PLAYER_H
