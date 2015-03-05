#ifndef FRAME_H
#define FRAME_H

class Frame
{
    public:
        sf::Texture texture;
        int delay;

        Frame( sf::Texture text, int del ) { texture = text; delay = del; };
};

#endif // FRAME_H
