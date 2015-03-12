#ifndef CONTAINER_H
#define CONTAINER_H

#include "message.h"
#include <SFML/Graphics.hpp>
#include <memory>

class Container
{
    public:
        int type;
        sf::Sprite sprite;

        virtual ~Container() {};
        virtual void recvMessage( std::shared_ptr<Message>& msg ) {};
};

#endif // CONTAINER_H
