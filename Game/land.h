#pragma once

#include "lib.h"


class land : LTexture
{
public:
    bool init();

    void Free();

    void render();

    void update();

private:
    position posLand;
};