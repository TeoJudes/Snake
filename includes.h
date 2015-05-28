#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SDL/SDL.h>
#include <time.h>
#include <SDL/SDL_ttf.h>

#ifndef CONSTANT
#define CONSTANT

#define WIDTH BLOCK * BLOCK_WIDTH
#define HEIGHT BLOCK * BLOCK_HEIGHT
#define BLOCK 20
#define BLOCK_WIDTH 70      //nombres de blocks en vertical du quadrillage
#define BLOCK_HEIGHT 45    //idem en horizontal

//suivent les emplacement des bouttons du menu
#define PlayLx 314
#define PlayRx 517
#define PlayTy 17
#define PlayBy 76

#define InstruLx 250
#define InstruRx 590
#define InstruTy 77
#define InstruBy 141

#define ScoreLx 314
#define ScoreRx 517
#define ScoreTy 142
#define ScoreBy 209

#define ExitLx 314
#define ExitRx 517
#define ExitTy 210
#define ExitBy 282

#define ScoreReturnMenuLx 245
#define ScoreReturnMenuRx 577
#define ScoreReturnMenuTy 5
#define ScoreReturnMenuBy 66

#define InstruExitLx 312
#define InstruExitRx 580
#define InstruExitTy 535
#define InstruExitBy 580

#define InstruReturnMenuLx 20
#define InstruReturnMenuRx 290
#define InstruReturnMenuTy 535
#define InstruReturnMenuBy 580


#define EMPTY 0 //enumeration des objets du jeu
#define WALL 1
#define SNAKE 2
#define MUSH 3
#define HEADSNAKE 4

#define BOT 3
#define TOP 2
#define RIGHT 1
#define LEFT 0


//struct snake
typedef struct snake snake;
struct snake
    {
        int sizesnake;
        SDL_Rect position;
    };

extern SDL_Rect snakeT[];

#endif // CONSTANT
