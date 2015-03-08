#include "game.h"
#include "spriteContainer.h"
#include "animContainer.h"
#include "player.h"
#include <memory>
#include <iostream>

Game::Game( int w, int h, std::string name, std::string ver )
:  window( sf::VideoMode( w, h ), name + " " + ver, sf::Style::Titlebar | sf::Style::Close )
{
    sf::View view( sf::FloatRect( 0, 0, 160, 90 ) );
    window.setView( view );
    std::shared_ptr<SpriteContainer> testSprite( new SpriteContainer( "./img/archenoid.stand0.png" ) );
    gameObjects.push_back( testSprite );

    std::vector<std::string> tempFiles{ "./img/arch.jog00.png", "./img/arch.jog01.png",
                                        "./img/arch.jog02.png", "./img/arch.jog03.png",
                                        "./img/arch.jog04.png", "./img/arch.jog05.png",
                                        "./img/arch.jog06.png", "./img/arch.jog07.png",
                                        "./img/arch.jog08.png", "./img/arch.jog09.png",
                                        "./img/arch.jog10.png", "./img/arch.jog11.png" };
    std::vector<int> tempDel{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
    std::shared_ptr<AnimContainer> testAnim( new AnimContainer( tempFiles, tempDel ) );
    testAnim->sprite.setPosition( 30, 0 );
    gameObjects.push_back( testAnim );
    std::shared_ptr<Player> testPlayer( new Player( tempFiles, tempDel ) );
    testPlayer->sprite.setPosition( 0, 50 );
    gameObjects.push_back( testPlayer );
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
    }

    return ret;
}

bool Game::update()
{
    bool ret = true;

    for( unsigned int i = 0; i < gameObjects.size(); i++ )
    {
        switch( gameObjects[ i ]->type )
        {
        case 2:
            std::dynamic_pointer_cast<AnimContainer>( gameObjects[ i ] )->incFrame();
            break;

        case 3:
            std::dynamic_pointer_cast<Player>( gameObjects[ i ] )->update();
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

    for( unsigned int i = 0; i < gameObjects.size(); i++ )
    {
        switch( gameObjects[ i ]->type )
        {
        case 1: //Sprite
            window.draw( std::dynamic_pointer_cast<SpriteContainer>( gameObjects[ i ] )->sprite );
            break;

        case 2: //Animation
            window.draw( std::dynamic_pointer_cast<AnimContainer>( gameObjects[ i ] )->sprite );
            break;

        case 3: //Player
            window.draw( std::dynamic_pointer_cast<Player>( gameObjects[ i ] )->sprite );
            break;

        default:
            break;
        }
    }

    window.display();
    return ret;
}
