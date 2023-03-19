#include "land.h"


bool land::init()
{
    string back_path = "image/land.png";
    posLand.getPos(0, SCREEN_HEIGHT - LAND_HEIGHT);
    if (isNULL())
    {
        if (Load(back_path.c_str(), 1))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return false;
}

void land::Free()
{
    free();
}

void land::render()
{
    if (posLand.x > 0)
    {
        Render(posLand.x, posLand.y);
    }
    else if (posLand.x > -SCREEN_WIDTH && posLand.x <= 0)
    {
        Render(posLand.x, posLand.y);
        Render(posLand.x + SCREEN_WIDTH, posLand.y, 0, NULL);
    }
    else
    {
        posLand.getPos(0, SCREEN_HEIGHT - LAND_HEIGHT);
        Render(posLand.x, posLand.y);
    }
}

void land::update()
{
    posLand.x -= 3;
}
