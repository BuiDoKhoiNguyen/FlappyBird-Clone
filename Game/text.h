/*
#pragma once
#include"lib.h"
#include<sstream>
#include<fstream>

class text : public LTexture
{
private:
	SDL_Texture* tex;
	SDL_Renderer* ren;
	TTF_Font* font = NULL;
	SDL_Color textcolor;
	position scorePos;
	short int bestScore;
	
public:

	bool init();
	void renderText();
	void updateScore();
	void updateBestScore( TTF_Font* font);
	//void createTextureText(TTF_Font* font, SDL_Color textcolor, SDL_Renderer* ren, string text);
	void Free();
};
*/
