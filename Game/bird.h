#pragma once

#include "lib.h"
#include "pipe.h"
#include "sound.h"


class bird :LTexture
{
public:
    bool init(bool isDark);

    void render(bool isDark);

    void Free();

    void resetTime()
    {
        time = 0;
    }

    void fall();

    void update( int pileWidth, int pileHeight);
private:
    string bird1_path = "image/bird1.png";
    string bird2_path = "image/bird2.png";
    string bird3_path = "image/bird3.png";
    int angle, time, x0;
    int ahead = 0;
    int animationTimer;
    SDL_Texture* tex1;
    SDL_Texture* tex2;
    string saved_path = "";
    sound getPoint;
    position posBird;
};