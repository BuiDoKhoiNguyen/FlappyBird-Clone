#include "game.h"
#include "lib.h"
#include "text.h"
#include <time.h>
#include <stdlib.h>


const int FPS = 60;
const int frameDelay = 1000 / FPS;

using namespace std;

int main(int argc, char** argv)
{
    Uint32 frameStart;
    int frameTime;
    game g;
    bool isMenu = 0;
    bool isPause = 0;
    bool isSound = 1;
    bool isDark = 0;

    while (!g.isQuit())
    {
        frameStart = SDL_GetTicks();

        if (g.isDie())
        {
            if (isMenu) {
                g.sound.playHit();
                g.player.render(isDark);
            }
            g.userInput.Type = game::input::NONE;
            while (g.isDie() && !g.isQuit())
            {
                g.takeInput();
                if (isMenu == 1 && g.userInput.Type == game::input::PLAY)
                {
                    if (g.checkReplay())
                    {
                        isMenu = 0;
                    }
                    g.userInput.Type = game::input::NONE;
                }
                if (!isDark) g.renderBackground();
                else g.renderBackgroundNight();
                g.pipe.render();
                g.land.render();
                if (isMenu)
                {
                    g.player.render(isDark);
                    g.player.fall();
                    g.renderGameOver();
                    g.renderMedal();

                    
                    g.renderScore(isMenu);
                    g.renderBestScore(isMenu);
                    //g.renderScoreSmall();
                    //g.renderBestScore();
                    g.replay();
                }
                else
                {
                    g.pipe.init();
                    g.player.init(isDark);
                    g.player.render(isDark);
                    g.renderMessage();
                    if (g.userInput.Type == game::input::PLAY)
                    {
                        g.Restart();
                        isMenu = 1;
                        g.userInput.Type = game::input::NONE;
                    }
                    g.land.update();
                }
                g.display();
            }
            g.pipe.init();
        }
        else
        {
            g.takeInput();

            if (g.userInput.Type == game::input::PAUSE )
            {
                isPause = abs(1 - isPause);
                g.userInput.Type = game::input::NONE;
            }
            
            if (isPause == 0 && g.userInput.Type == game::input::PLAY)
            {
                if (isSound) g.sound.playBreath();
                g.player.resetTime();
                g.userInput.Type = game::input::NONE;
            }

            if (!isDark) g.renderBackground();
            else g.renderBackgroundNight();
            g.pipe.render();
            g.land.render();
            g.player.render(isDark);

            g.renderScore(isPause);
            //g.renderScoreLarge();

            if (!isPause)
            {
                g.player.update(g.getPipeWidth(), g.getPipeHeight());
                g.pipe.update();
                g.land.update();
                g.pause();
            }
            else
            {
                g.resume();
                g.renderPauseTab();

                //g.renderScoreSmall();
                //g.renderBestScore();
                g.renderScore(isPause);
                g.renderBestScore(isPause);

                g.replay();
                g.sound.renderSound();
                if (!isDark) g.lightTheme(); else g.darkTheme();
                g.nextButton();
                if (g.userInput.Type == game::input::PLAY)
                {
                    if (g.checkReplay())
                    {
                        isPause = 0;
                    }
                    else if (g.sound.checkSound())
                    {
                        isSound = abs(1 - isSound);
                    }
                    else if (g.changeTheme())
                    {
                        isDark = abs(1 - isDark);
                        g.player.init(isDark);
                    }
                    g.userInput.Type = game::input::NONE;
                }
            }
            g.display();
        }

        //Limit FPS
        frameTime = SDL_GetTicks() - frameStart;
        if (frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }
    }
    return 0;
}
