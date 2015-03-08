#ifndef CONTAINER_H
#define CONTAINER_H

#include "message.h"
#include <memory>

class Container
{
    public:
        int type;

        virtual ~Container() {};
        virtual void recvMessage( std::shared_ptr<Message>& msg ) {};
};

#endif // CONTAINER_H
