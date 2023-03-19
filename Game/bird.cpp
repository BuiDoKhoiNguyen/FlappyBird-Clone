#include "bird.h"

bool bird::init(bool isDark)
{
    getPoint.init();
    string bird1_path = "image/bird1.png";
    if (isDark) bird1_path = "image/shiba1.png";
    if (saved_path == bird1_path)
    {
        posBird.getPos(75, SCREEN_HEIGHT / 2 - 10);
        ahead = 0;
        angle = 0;
    }
    if (isNULL() || saved_path != bird1_path)
    {
        saved_path = bird1_path;
        if (Load(bird1_path.c_str(), 1))
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

void bird::Free()
{
    free();
}

void bird::render(bool isDark)
{
    animationTimer++;
    if (isDark)
    {
        bird1_path = "image/shiba1.png";
        bird2_path = "image/shiba2.png";
        bird3_path = "image/shiba3.png";
    }
    else
    {
        bird1_path = "image/bird1.png";
        bird2_path = "image/bird2.png";
        bird3_path = "image/bird3.png";
    }
    if (animationTimer < 10)
    {
        if ( Load(bird1_path.c_str(), 1));
        Render(posBird.x, posBird.y, angle);
    }
    else if (animationTimer >= 10 && animationTimer <= 20)
    {
        if (Load(bird2_path.c_str(), 1));
        Render(posBird.x, posBird.y, angle);
    }
    else if (animationTimer > 20)
    {
        if (Load(bird3_path.c_str(), 1));
        Render(posBird.x, posBird.y, angle);
    }
    if (animationTimer > 30)
    {
        animationTimer = 0;
    }   
}

void bird::fall()
{
    if (die && posBird.y < SCREEN_HEIGHT - LAND_HEIGHT - SHIBA_HEIGHT - 5)
    {
        if (time == 0)
        {
            x0 = posBird.y;
            angle = -25;
        }
        else if (angle < 70 && time > 30)
        {
            angle += 3;
        }

        if (time >= 0)
        {
            posBird.y = x0 + time * time * 0.18 - 7.3 * time;
            time++;
        }
    }
    else return;
}

void bird::update(int pipeWidth, int pipeHeight)
{
    if (!die)
    {
        if (time == 0)
        {
            x0 = posBird.y;
            angle = -25;
        }
        else if (angle < 70 && time > 30)
        {
            angle += 3;
        }

        if (time >= 0)
        {
            posBird.y = x0 + time * time * 0.18 - 7.3 * time;
            time++;
        }

        if ((posBird.x + getWidth() > posPipe[ahead].x + 5) && (posBird.x + 5 < posPipe[ahead].x + pipeWidth) &&
            (posBird.y + 5 < posPipe[ahead].y + pipeHeight || posBird.y + getHeight() > posPipe[ahead].y + pipeHeight + PIPE_SPACE + 5 ))
        {
            die = true;
        }
        else if (posBird.x > posPipe[ahead].x + pipeWidth)
        {
            ahead = (ahead + 1) % TOTAL_PIPE;
            score++;
            getPoint.playTing();
        }

        if (posBird.y > SCREEN_HEIGHT - LAND_HEIGHT - SHIBA_HEIGHT - 5 || posBird.y < -10)
        {
            die = true;
        }
    }
}