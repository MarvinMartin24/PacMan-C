#ifndef OBSTACLE_H
#define OBSTACLE_H
#include "position.h"

typedef struct obstacle_t{
    char obstacle_type;
    position_t pos;
} obstacle_t;

obstacle_t obstacle_create(char obstacle_type, int x, int y);

#endif /* end of include guard: OBSTACLE_H */
