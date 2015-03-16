#include "player.h"

#include <iostream>

Player::Player( std::vector<std::string>& files, std::vector<int>& del )
{
    type = 3;
    textureBanks.resize( 2 );
    std::vector<std::string> tempStandFiles{ "./img/arch.jog00.png" };
    std::vector<int> tempStandDel{ 1 };
    std::vector<std::string> tempRunFiles{ "./img/arch.jog00.png", "./img/arch.jog01.png",
                                        "./img/arch.jog02.png", "./img/arch.jog03.png",
                                        "./img/arch.jog04.png", "./img/arch.jog05.png",
                                        "./img/arch.jog06.png", "./img/arch.jog07.png",
                                        "./img/arch.jog08.png", "./img/arch.jog09.png",
                                        "./img/arch.jog10.png", "./img/arch.jog11.png" };
    std::vector<int> tempRunDel{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

    for( unsigned int i = 0; i < tempStandFiles.size(); i++ )
    {
        sf::Texture tempText;

        if( !tempText.loadFromFile( tempStandFiles[ i ] ) )
        {
            std::cerr << "Error loading file " << tempStandFiles[ i ] << std::endl;
            break;
        }

        Frame tempFrame( tempText, tempStandDel[ i ] );
        textureBanks[ 0 ].push_back( tempFrame );
    }

    for( unsigned int i = 0; i < tempRunFiles.size(); i++ )
    {
        sf::Texture tempText;

        if( !tempText.loadFromFile( tempRunFiles[ i ] ) )
        {
            std::cerr << "Error loading file " << tempRunFiles[ i ] << std::endl;
            break;
        }

        Frame tempFrame( tempText, tempRunDel[ i ] );
        textureBanks[ 1 ].push_back( tempFrame );
    }

    sprite.setTexture( textureBanks[ state ][ 0 ].texture, true );
    collBox.x = 0;
    collBox.y = 0;
    collBox.w = 9;
    collBox.h = 13;
}

void Player::update()
{
    if( currentDelay == textureBanks[ state ][ currentFrame ].delay )
    {
        currentDelay = 0;

        if( currentFrame == textureBanks[ state ].size() - 1 )
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
        changeState( 1 );

        if( KEYBOARD_AD )
        {
            xVel = 1;
            flip = false;
        }
        else
        {
            xVel = -1;
            flip = true;
        }
    }
    else
    {
        changeState( 0 );
        xVel = 0;
    }

    sprite.setTexture( textureBanks[ state ][ currentFrame ].texture, true );
    sprite.move( xVel, yVel );
    int width = textureBanks[ state ][ currentFrame ].texture.getSize().x;
    int height = textureBanks[ state ][ currentFrame ].texture.getSize().y;

    if( flip )
    {
        sprite.setTextureRect( sf::IntRect( width, 0, -width, height ) );
    }
    else
    {
        sprite.setTextureRect( sf::IntRect( 0, 0, width, height ) );
    }
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

        case 2: //Collision
        {
            sprite.move( -xVel, -yVel );
        }

        default:
            break;
    }
}

void Player::changeState( int s )
{
    if( state != s )
    {
        state = s;
        currentFrame = 0;
        currentDelay = 0;
    }
}
