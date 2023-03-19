#include "game.h"


void game::takeInput()
{
	while (SDL_PollEvent(&event) != 0)
	{
		if (event.type == SDL_QUIT)
		{
			userInput.Type = input::QUIT;
			quit = true;
		}
		else if (event.type == SDL_MOUSEBUTTONDOWN || (event.type == SDL_KEYDOWN && (event.key.keysym.sym == SDLK_SPACE || event.key.keysym.sym == SDLK_UP) ) )
		{
			userInput.Type = input::PLAY;
		}
		else if ( ( event.type==SDL_MOUSEBUTTONUP && changePauseTab()==true ) || (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE && event.key.repeat == 0))
		{
			userInput.Type = input::PAUSE;
		}
	}
}

game::game()
{
	initGraphic();
	pipe.init();
	land.init();
	sound.init();
	//text.init();
}

game::~game()
{
	player.Free();
	pipe.Free();
	land.Free();
	sound.Free();
	//text.Free();
	free();
	releaseGraphic();
}

void game::releaseGraphic()
{
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	SDL_DestroyRenderer(gRenderer);
	gRenderer = NULL;
	IMG_Quit();
	TTF_Quit();
	SDL_Quit();
}

bool game::initGraphic()
{
	bool success = true;
	string text_path = "TTF/google3.ttf";
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}

		gWindow = SDL_CreateWindow("Flappy Bird", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (gRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}

				if (TTF_Init() == -1)
				{
					printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
					success = false;
				}
				font = TTF_OpenFont(text_path.c_str(), 28);

				if (font == NULL)
				{
					printf("SDL could not initialize! SDL Error: %s\n", TTF_GetError());
					success = false;
				}

			} 
		}
	}

	return success;
}

void game::display()
{
	SDL_RenderPresent(gRenderer);
	SDL_RenderClear(gRenderer);
}

void game::renderScore(bool state)
{
	stringstream scoreText;
	scoreText << score;
	textcolor = { 0xFF, 0xFF, 0xFF, 0xFF };
	SDL_Surface* textSurface = TTF_RenderText_Solid(font, scoreText.str().c_str(), textcolor);
	//scorePos.getPos(168, 25);
	Texture = SDL_CreateTextureFromSurface(gRenderer, textSurface);
	if (state == true)
	{
		SDL_Rect scorePos = { 245,262,15, 30 };
		if (score >= 10) scorePos.w = 25;
		SDL_RenderCopy(gRenderer, Texture, NULL, &scorePos);
	}
	else
	{
		SDL_Rect scorePos = { 156,25,40, 70 };
		if ( score >= 10) scorePos.w = 60;
		SDL_RenderCopy(gRenderer, Texture, NULL, &scorePos);
	}
}

void game::renderBestScore(bool state)
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

	stringstream scoreText;
	scoreText << bestScore;
	textcolor = { 0xFF, 0xFF, 0xFF, 0xFF };
	SDL_Surface* textSurface = TTF_RenderText_Solid(font, scoreText.str().c_str(), textcolor);
	Texture = SDL_CreateTextureFromSurface(gRenderer, textSurface);
	if (state == true)
	{
		SDL_Rect scorePos = { 245, 310, 25, 30 };
		if (bestScore >= 10) scorePos.w = 25;
		SDL_RenderCopy(gRenderer, Texture, NULL, &scorePos);
	}
}

void game::renderMessage()
{
	LTexture image;
	image.Load("image/message1.png", 1);
	image.Render(70, 90);
	image.free();
}

void game::renderBackground()
{
	LTexture image;
	image.Load("image/background.png", 1);
	image.Render(0, 0);
	image.free();
}

void game::renderBackgroundNight()
{
	LTexture image;
	image.Load("image/background-night.png", 1);
	image.Render(0, 0);
	image.free();
}

void game::renderLand()
{
	LTexture image;
	image.Load("image/land.png", 1);
	image.Render((SCREEN_WIDTH - image.getWidth()) / 2, SCREEN_HEIGHT - image.getHeight());
	image.free();
}

void game::resume()
{
	LTexture image;
	image.Load("image/resume.png", 1);
	image.Render(SCREEN_WIDTH - 50, 20);
	image.free();
}

void game::pause()
{
	LTexture image;
	image.Load("image/pause.png", 1);
	image.Render(SCREEN_WIDTH - 50, 20);
	image.free();
}

bool game::changePauseTab()
{
	int x, y;
	SDL_GetMouseState(&x, &y);
	if ((x > SCREEN_WIDTH - 50 && x < SCREEN_WIDTH - 50 + 28) && (y > 20 && y < 20 + 26))
	{
		return true;
	}
	return false;
}

void game::renderPauseTab()
{
	LTexture image;
	image.Load("image/pauseTab.png", 1);
	image.Render((SCREEN_WIDTH - image.getWidth()) / 2, 230);
	image.free();
}

void game::lightTheme()
{
	LTexture image;
	image.Load("image/bird1.png", 0.8);
	image.Render(105, 315);
	image.free();
}

void game::darkTheme()
{
	LTexture image;
	image.Load("image/shiba1.png", 0.8);
	image.Render(105, 315);
	image.free();
}

void game::nextButton()
{
	LTexture image;
	image.Load("image/nextRight.png", 1);
	image.Render(149, 322);
	image.Load("image/nextLeft.png", 1);
	image.Render(88, 322);
	image.free();
}

bool game::changeTheme()
{
	int x, y;
	SDL_GetMouseState(&x, &y);
	if (((x > 149 && x < 149 + 13) || (x > 88 && x < 88 + 13)) && (y > 322 && y < 322 + 16))
	{
		return true;
	}
	return false;
}

void game::renderGameOver()
{
	LTexture image;
	image.Load("image/gameOver.png", 1);
	image.Render((SCREEN_WIDTH - image.getWidth()) / 2, 150);
	image.free();
}

void game::renderMedal()
{
	LTexture image;

	if (score > 20 && score <= 50)
	{
		image.Load("medal/silver.png", scaleNumberS);
	}
	else if (score > 50)
	{
		image.Load("medal/gold.png", scaleNumberS);
	}
	else
	{
		image.Load("medal/honor.png", scaleNumberS);
	}
	image.Render(82, 275);

	image.free();
}

void game::replay()
{
	LTexture image;
	image.Load("image/replay.png", 1);
	image.Render((SCREEN_WIDTH - image.getWidth()) / 2, 380);
	image.free();
}

bool game::checkReplay()
{
	int x, y;
	SDL_GetMouseState(&x, &y);
	if (x > (SCREEN_WIDTH - 100) / 2 && x < (SCREEN_WIDTH + 100) / 2 && y > 380 && y < 380 + 60)
	{
		return true;
	}
	return false;
}

void game::Restart()
{
	die = false;
	score = 0;
	player.resetTime();
}