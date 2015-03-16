#ifndef GAME_H
#define GAME_H

#include <vector>
#include <memory>
#include <string>
#include "container.h"
#include "message.h"
#include "objectManager.h"

class Game
{
    public:
        Game( int w, int h, std::string name, std::string ver );
        bool start();
        bool events();
        bool update();
        bool render();
        void sendMessage( std::shared_ptr<Message> msg );
        bool checkCollision( int i, int j );

        sf::RenderWindow window;
        ObjectManager gameObjects;
        //std::vector<
};

#endif // GAME_H
