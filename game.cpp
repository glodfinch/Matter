#include "game.h"
#include "spriteContainer.h"
#include <memory>

Game::Game( int w, int h, std::string name, std::string ver )
:  window( sf::VideoMode( w, h ), name + " " + ver, sf::Style::Titlebar | sf::Style::Close )
{
    std::shared_ptr<SpriteContainer> test( new SpriteContainer( "./img/archenoid.stand0.png" ) );
    gameObjects.push_back( test );
}

bool Game::start()
{
    bool ret = true;

    while( window.isOpen() )
    {
        ret &= events();
        ret &= update();
        ret &= render();

        if( !ret )
        {
            break;
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
    return ret;
}

bool Game::render()
{
    bool ret = true;
    window.clear();

    for( unsigned int i = 0; i < gameObjects.size(); i++ )
    {
        window.draw( std::dynamic_pointer_cast<SpriteContainer>( gameObjects[ i ] )->sprite );
    }

    window.display();
    return ret;
}
