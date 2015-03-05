#include "game.h"

int main()
{
    Game matter( 640, 360, "Matter", "0.5.2" );
    return !matter.start();
}
