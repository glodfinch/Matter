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

#endif // MESSAGE_H
