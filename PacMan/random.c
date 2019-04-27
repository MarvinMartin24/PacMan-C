
#include "random.h"
#include "game.h"
#include "position.h"



int randomX(int width)
 {
	int r;

	r = rand() % (width-1)+1;
	return r;
}

int randomY(int height)
 {
	int r;

	r = rand() % (height-1)+1;
	return r;
}



int random()
{
    int r;
    r = rand() % (1- (-1)+1)+(-1);
    return r;
}


int x,y;
position_t randomdirection()
{
    x=random();
    switch (x)
    {
        case -1 :
            y=0;
            break;


        case 0 :
                do{
                y=random();
                }while (y==0);
                break;


        case 1 :
             y=0;
             break;

    }


    return position_create(x,y);
}
