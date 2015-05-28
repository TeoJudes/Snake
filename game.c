#include "includes.h"
#include "fonctions.h"

SDL_Rect snakeT[50] = {0};

int game(SDL_Surface* Screen, int score)
    {
        int keep=1;
        int timebg=0, time=0;
        int sizesnake = 1;
        int direction = RIGHT;
        int i=0, j=0;
        SDL_Surface *Wall = NULL, *Snake = NULL, *Empty = NULL, *Mush;
        SDL_Rect position;
            position.x;
            position.y;
        int map[BLOCK_WIDTH][BLOCK_HEIGHT]= {{0}};
        SDL_Event event;

        Snake = SDL_LoadBMP("BodySnake.bmp");
        Wall = SDL_LoadBMP("Wall.bmp");
        Empty = SDL_LoadBMP("MorceauFond.bmp");
        Mush = SDL_LoadBMP("mush.bmp");

        buildmap(map);

       while (keep)
            {
                SDL_PollEvent(&event);
                switch(event.type)
                {
                    case SDL_QUIT:
                    keep = 0;
                    break;

                    case SDL_KEYDOWN:
                        switch (event.key.keysym.sym)
                        {
                            case SDLK_DOWN:
                                        direction = BOT;
                                    break;

                            case SDLK_UP:
                                        direction = TOP;
                                    break;

                            case SDLK_LEFT:
                                        direction = LEFT;
                                    break;

                            case SDLK_RIGHT:
                                        direction = RIGHT;
                                break;

                            case SDLK_ESCAPE:
                                    keep = 0;
                                    break;
                        default:
                            break;

                            }
                        break;

                }

            time = SDL_GetTicks();

            if ( (time - timebg) > 80 )

                {
                    keep = movement(map , direction, sizesnake);
                    timebg=time;
                }
                BlitAll(map, Screen, Wall ,Empty, Snake, Mush);
                SDL_Flip(Screen);
            }
            SDL_Quit();
            return EXIT_SUCCESS;
    }
