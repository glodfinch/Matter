#include "game.h"
#include "spriteContainer.h"
#include "animContainer.h"
#include "player.h"
//#include "message.h"
#include <memory>
#include <iostream>

Game::Game( int w, int h, std::string name, std::string ver )
:  window( sf::VideoMode( w, h ), name + " " + ver, sf::Style::Titlebar | sf::Style::Close )
{
    sf::View view( sf::FloatRect( 0, 0, 160, 90 ) );
    window.setView( view );

    std::vector<std::string> tempFiles{ "./img/arch.jog00.png", "./img/arch.jog01.png",
                                        "./img/arch.jog02.png", "./img/arch.jog03.png",
                                        "./img/arch.jog04.png", "./img/arch.jog05.png",
                                        "./img/arch.jog06.png", "./img/arch.jog07.png",
                                        "./img/arch.jog08.png", "./img/arch.jog09.png",
                                        "./img/arch.jog10.png", "./img/arch.jog11.png" };
    std::vector<int> tempDel{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

    gameObjects.addObject( 1, "./img/archenoid.stand0.png" );
    gameObjects.addObject( 2, tempFiles, tempDel, 30 );
    gameObjects.addObject( 3, tempFiles, tempDel, 0, 50 );
}

bool Game::start()
{
    bool ret = true;
    sf::Clock timer;
    const sf::Int64 frameLimit = 1000000 / 60;

    while( window.isOpen() )
    {
        sf::Int64 time = timer.getElapsedTime().asMicroseconds();
        events();
        update();
        render();

        if( !ret )
        {
            break;
        }

        if( timer.getElapsedTime().asMicroseconds() - time < frameLimit )
        {
            sf::sleep( sf::microseconds( frameLimit - timer.getElapsedTime().asMicroseconds() ) );
            timer.restart();
        }
    }

    return ret;
}

bool Game::events()
{
    bool ret = true;
    sf::Event event;

    while( window.pollEvent( event ) )
    {
        if( event.type == sf::Event::Closed )
        {
            window.close();
        }

        if( event.type == sf::Event::KeyPressed )
        {
            if( event.key.code == sf::Keyboard::D )
            {
                sendMessage( std::shared_ptr<KeyboardMessage>( new KeyboardMessage( sf::Keyboard::D, 1 ) ) );
            }
            else if( event.key.code == sf::Keyboard::A )
            {
                sendMessage( std::shared_ptr<KeyboardMessage>( new KeyboardMessage( sf::Keyboard::A, 1 ) ) );
            }
        }

        if( event.type == sf::Event::KeyReleased )
        {
            if( event.key.code == sf::Keyboard::D )
            {
                sendMessage( std::shared_ptr<KeyboardMessage>( new KeyboardMessage( sf::Keyboard::D, 0 ) ) );
            }
            else if( event.key.code == sf::Keyboard::A )
            {
                sendMessage( std::shared_ptr<KeyboardMessage>( new KeyboardMessage( sf::Keyboard::A, 0 ) ) );
            }
        }
    }

    return ret;
}

bool Game::update()
{
    bool ret = true;

    for( unsigned int i = 0; i < gameObjects.objects.size(); i++ )
    {
        switch( gameObjects.objects[ i ]->type )
        {
        case 2:
            std::dynamic_pointer_cast<AnimContainer>( gameObjects.objects[ i ] )->incFrame();
            break;

        case 3:
            std::dynamic_pointer_cast<Player>( gameObjects.objects[ i ] )->update();
            break;

        default:
            break;
        }
    }

    return ret;
}

bool Game::render()
{
    bool ret = true;

    window.clear();

    for( unsigned int i = 0; i < gameObjects.objects.size(); i++ )
    {
        window.draw( gameObjects.objects[ i ]->sprite );
    }

    window.display();
    return ret;
}

void Game::sendMessage( std::shared_ptr<Message> msg )
{
    for( unsigned int i = 0; i < gameObjects.objects.size(); i ++ )
    {
        gameObjects.objects[ i ]->recvMessage( msg );
    }
}
