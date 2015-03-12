#include "objectManager.h"
#include <string>
#include "spriteContainer.h"
#include "animContainer.h"
#include "player.h"

bool ObjectManager::addObject( int type, std::string file, int x, int y )
{
    if( type == 1 )
    {
        std::shared_ptr<SpriteContainer> tempSprite( new SpriteContainer( file ) );
        tempSprite->sprite.setPosition( x, y );
        objects.push_back( tempSprite );
    }

    return true;
}

bool ObjectManager::addObject( int type, std::vector<std::string> files, std::vector<int> dels, int x, int y )
{
    switch( type )
    {
        case 2:
        {
            std::shared_ptr<AnimContainer> tempAnim( new AnimContainer( files, dels ) );
            tempAnim->sprite.setPosition( x, y );
            objects.push_back( tempAnim );
            break;
        }

        case 3:
        {
            std::shared_ptr<Player> tempPlayer( new Player( files, dels ) );
            tempPlayer->sprite.setPosition( x, y );
            objects.push_back( tempPlayer );
            break;
        }

        default:
            break;
    }

    return true;
}

bool ObjectManager::removeObject( int id )
{
    return true;
}

void ObjectManager::sortX()
{
    for( unsigned int i = 0; i < objects.size() - 1; i ++ )
    {
        if( objects[ i ]->sprite.getPosition().x > objects[ i + 1 ]->sprite.getPosition().x )
        {
            std::swap( objects[ i ], objects[ i + 1 ] );

            for( int j = i; j > 0; j -- )
            {
                if( objects[ j ]->sprite.getPosition().x < objects[ j - 1 ]->sprite.getPosition().x )
                {
                    std::swap( objects[ j ], objects[ j - 1 ] );
                }
            }
        }
    }
}
