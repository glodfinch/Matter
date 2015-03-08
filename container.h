#ifndef CONTAINER_H
#define CONTAINER_H

class Container
{
    public:
        int type;

        virtual ~Container() {};
        virtual void recvMessage( int msg ) {};
};

#endif // CONTAINER_H
