#pragma once

#include "lib.h"


class sound :LTexture
{
public:
    bool init();

    void Free();

    void playBreath();

    void playHit();

    void playTing();

    void renderSound();

    bool checkSound();

private:
    const int POS_X = 107;
    const int POS_Y = 267;
    bool isPlay = 0;
    Mix_Chunk* breath = NULL;
    Mix_Chunk* hit = NULL;
    Mix_Chunk* drop = NULL;
    Mix_Chunk* ting = NULL;
    SDL_Rect Mute;
    SDL_Rect Active;
};