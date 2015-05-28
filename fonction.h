#include "includes.h"
//prototypes de fonction

int game(SDL_Surface* Screen, int score);

void pause();

void High_Score(int score);

void Aff_Fenetre (SDL_Surface*Screen);

void Aff_Mush(int map[][BLOCK_HEIGHT]);

void buildmap(int map[][BLOCK_HEIGHT]);

int broken (int map[][BLOCK_HEIGHT], int sizesnake, int x, int y);

int movement(int map[][BLOCK_HEIGHT], int direction, int sizesnake);




