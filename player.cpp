#include "player.h"

#include <iostream>

Player::Player( std::vector<std::string>& files, std::vector<int>& del )
{
    type = 3;

    for( unsigned int i = 0; i < files.size(); i++ )
    {
        sf::Texture tempText;

        if( !tempText.loadFromFile( files[ i ] ) )
        {
            std::cerr << "Error loading file " << files[ i ] << std::endl;
            break;
        }

        Frame tempFrame( tempText, del[ i ] );
        textureBank.push_back( tempFrame );
    }

    sprite.setTexture( textureBank[ 0 ].texture, true );
}

void Player::update()
{
    if( currentDelay == textureBank[ currentFrame ].delay )
    {
        currentDelay = 0;

        if( currentFrame == textureBank.size() - 1 )
        {
            currentFrame = 0;
        }
        else
        {
            currentFrame++;
        }
    }
    else
    {
        currentDelay++;
    }

    sprite.setTexture( textureBank[ currentFrame ].texture, true );
    sprite.move( xVel, yVel );
}

void Player::recvMessage( int msg )
{
    switch( msg )
    {
        case 1: //Press right
            xVel = 1;
            break;

        case 2: //Press left
            xVel = -1;
            break;

        case 3: //Release right
        case 4: //Release left
            xVel = 0;
            break;

        default:
            break;
    }
}
