#ifndef OBJECT_H
#define OBJECT_H

#include <vector>
#include <memory>
#include "container.h"
#include <SFML/Graphics.hpp>

class ObjectManager
{
    public:
        std::vector<std::shared_ptr<Container> > objects;

        bool addObject( int type, std::string file, int x = 0, int y = 0 );
        bool addObject( int type, std::vector<std::string> files = std::vector<std::string>(), std::vector<int> dels = std::vector<int>(), int x = 0, int y = 0 );
        bool removeObject( int id );
        void sortX();
};

#endif // OBJECT_H
