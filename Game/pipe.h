#pragma once

#include "lib.h"

extern vector<position> posPipe;

class pipe :LTexture
{
private:
    const int randMin = -373 + 30;
    const int randMax = SCREEN_HEIGHT - LAND_HEIGHT - 373 - PIPE_DISTANCE - 30;
public:
    bool init();

    void Free();

    void render();

    void update();

    int width() { return getWidth(); }

    int height() { return getHeight(); }
};