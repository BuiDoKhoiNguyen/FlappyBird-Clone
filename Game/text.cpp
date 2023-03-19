/*#include "text.h"

/*
void text::Render(SDL_Renderer* ren)
{
	SDL_RenderCopy(ren, tex, NULL, &getDest());
}

void text::ScoreUpdate()
{
	setDest(168, 25, 20, 20);
}

bool text::init()
{      
    bool success = true;
    TTF_Init();
    string text_path = "TTF/google3.ttf";
    if (SDL_Init(SDL_INIT_AUDIO) < 0)
    {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        success = false;
    }
    else
    {
        font = TTF_OpenFont(text_path.c_str(), 28);
      
        if (font == NULL)
        {
            printf("SDL could not initialize! SDL Error: %s\n", TTF_GetError());
            success = false;
        }
        //scorePos.getPos(156, 25);
        //tex = TTF_RenderText_Solid(font, score_text.c_str(), texcolor );
    }
    return success;
}

void text::renderText()
{
    SDL_Rect scorePos = { 156,25,40, 70 };
    cout << "hello";
    SDL_RenderCopy(ren, tex, NULL, &scorePos );
}

void text::updateScore()
{
	stringstream scoreText;
	scoreText << score;
    textcolor = { 0xFF, 0xFF, 0xFF, 0xFF };
	SDL_Surface* textSurface = TTF_RenderText_Solid(font, scoreText.str().c_str(), textcolor);
    //scorePos.getPos(168, 25);
	tex = SDL_CreateTextureFromSurface(ren, textSurface);
}

void text::updateBestScore(TTF_Font* font)
{
    ifstream fileIn("bestScore.txt");
    if (fileIn.is_open())
    {
        fileIn >> bestScore;
    }

    ofstream fileOut("bestScore.txt");
    if (score > bestScore)
    {
        bestScore = score;
    }

    fileOut << bestScore;
    fileIn.close();
    fileOut.close();
}
/*
void text::createTextureText(TTF_Font* font, SDL_Color textcolor, SDL_Renderer* ren, string text)
{
	SDL_Surface* textMenu = TTF_RenderText_Solid(font, text.c_str(), textcolor);

	tex = SDL_CreateTextureFromSurface(ren, textMenu);
}

void text::Free()
{
    free();

    TTF_CloseFont(font);
    font = NULL;
   
    TTF_Quit();
}
*/