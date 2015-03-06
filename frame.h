#ifndef FRAME_H
#define FRAME_H

#include <SFML/Graphics.hpp>

class Frame
{
    public:
        sf::Texture texture;
        int delay;

        Frame( sf::Texture text, int del ) { texture = text; delay = del; };
};

#endif // FRAME_H
