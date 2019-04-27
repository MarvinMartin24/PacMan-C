#include "obstacle.h"

//creation d'obstacle
obstacle_t obstacle_create(char obstacle_type, int x, int y)
{
    obstacle_t obstacle;
    obstacle.obstacle_type = obstacle_type;
    obstacle.pos = position_create(x, y);
    return obstacle;
}




