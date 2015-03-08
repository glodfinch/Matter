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
    KEYBOARD_W = false;
    KEYBOARD_A = false;
    KEYBOARD_S = false;
    KEYBOARD_D = false;
    KEYBOARD_WS = false;
    KEYBOARD_AD = false;
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

    if( KEYBOARD_A || KEYBOARD_D )
    {
        if( KEYBOARD_AD )
        {
            xVel = 1;
        }
        else
        {
            xVel = -1;
        }
    }
    else
    {
        xVel = 0;
    }

    sprite.setTexture( textureBank[ currentFrame ].texture, true );
    sprite.move( xVel, yVel );
}

void Player::recvMessage( std::shared_ptr<Message>& msg )
{
    switch( msg->type )
    {
        case 1: //Keyboard
        {
            std::shared_ptr<KeyboardMessage> tempMsg( std::static_pointer_cast<KeyboardMessage>( msg ) );
            if( tempMsg->status )
            {
                if( tempMsg->key == sf::Keyboard::A )
                {
                    KEYBOARD_A = true;
                    KEYBOARD_AD = false;
                }
                else if( tempMsg->key == sf::Keyboard::D )
                {
                    KEYBOARD_D = true;
                    KEYBOARD_AD = true;
                }
            }
            else
            {
                if( tempMsg->key == sf::Keyboard::A )
                {
                    KEYBOARD_A = false;
                }
                else if( tempMsg->key == sf::Keyboard::D )
                {
                    KEYBOARD_D = false;
                }
            }
            break;
        }

        default:
            break;
    }
}
