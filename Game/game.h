#pragma once

#include "bird.h"
#include "pipe.h"
#include "land.h"
#include "sound.h"
#include "lib.h"


using namespace std;

class game :LTexture
{
public:
    struct input
    {
        enum type { QUIT, PLAY, NONE, PAUSE };
        type Type;
    };
    input userInput;
    bird player;
    pipe pipe;
    sound sound;
    land land;
    TTF_Font* font;
    SDL_Color textcolor;
public:
    game();

    ~game();

    bool initGraphic();

    bool isQuit()
    {
        return quit;
    }

    bool isDie()
    {
        return die;
    }

    int getPipeWidth()
    {
        return pipe.width();
    }

    int getPipeHeight()
    {
        return pipe.height();
    }

    void takeInput();

    void display();

    void releaseGraphic();
    //
    void renderScore(bool state);

    void renderBestScore(bool state);
    /*
    void renderScoreSmall();

    void renderScoreLarge();

    void renderBestScore();
    */
    void renderMessage();

    void renderBackground();

    void renderBackgroundNight();

    void renderLand();

    void resume();

    void pause();

    bool changePauseTab();

    void renderPauseTab();

    void lightTheme();

    void darkTheme();

    void nextButton();

    bool changeTheme();

    void renderGameOver();

    void renderMedal();

    void replay();

    bool checkReplay();

    void Restart();

private:
    const double scaleNumberS = 0.75;
    int bestScore;
};