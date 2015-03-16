#ifndef MESSAGE_H
#define MESSAGE_H

#include <SFML/Graphics.hpp>

class Message
{
    public:
        int type;
};

class KeyboardMessage: public Message
{
    public:
        sf::Keyboard::Key key;
        bool status;

        KeyboardMessage( sf::Keyboard::Key k, bool s ) { type = 1; key = k; status = s; };
};

class CollisionMessage: public Message
{
    public:
        int recv;
        int coll;

        CollisionMessage( int i, int j ) { type = 2; recv = i; coll = j; };
};

#endif // MESSAGE_H
