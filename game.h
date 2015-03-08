#ifndef GAME_H
#define GAME_H

#include <vector>
#include <memory>
#include <string>
#include "container.h"
#include "message.h"

class Game
{
    public:
        Game( int w, int h, std::string name, std::string ver );
        bool start();
        bool events();
        bool update();
        bool render();
        void sendMessage( std::shared_ptr<Message> msg );

        sf::RenderWindow window;
        std::vector<std::shared_ptr<Container>> gameObjects;
};

#endif // GAME_H
