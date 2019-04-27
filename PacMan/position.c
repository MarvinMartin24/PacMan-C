#include "position.h"
#include "game.h"

position_t position_create(int x, int y){
    position_t pos;
    pos.x = x;
    pos.y = y;
    return pos;
}

