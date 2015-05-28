#include "includes.h"


void pause()
{
    int continuer=1;
    SDL_Event event;

    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;

        }
    }
}

void Aff_Mush(int map[BLOCK_WIDTH][BLOCK_HEIGHT])
    {
        srand(time(NULL));
        int minx = 0;
        int maxx= BLOCK_WIDTH - 1;

        int miny = 0;
        int maxy = BLOCK_HEIGHT - 1;

        int randx = 0;
        int randy = 0;

        do
        {
         randx = (rand() % (maxx - minx + 1)) + minx;
         randy = (rand() % (maxy - miny + 1)) + miny;
        }
        while(map[randx][randy] != EMPTY );
        map[randx][randy] = MUSH;

    }

void Aff_Snake(int map[BLOCK_WIDTH][BLOCK_HEIGHT])
    {
        srand(time(NULL));
        int minx = 0;
        int maxx= BLOCK_WIDTH - 1;

        int miny = 0;
        int maxy = BLOCK_HEIGHT - 1;

        int randx = 0;
        int randy = 0;

        do
        {
         randx = (rand() % (maxx - minx + 1)) + minx;
         randy = (rand() % (maxy - miny + 1)) + miny;
        }
        while(map[randx][randy] != EMPTY);
        map[randx][randy] = SNAKE;
        snakeT[0].x = randx;
        snakeT[0].y = randy;


    }


void buildmap(int map[BLOCK_WIDTH][BLOCK_HEIGHT])
    {

        int i=0, j=0, k=0, l=0;


        while(j<BLOCK_HEIGHT) //mur du haut
            {
                map [0][j] = WALL; //wall
                j=j+1;
            }

        while(k<BLOCK_HEIGHT)//mur du bas
            {
                map [BLOCK_WIDTH-1][k]=WALL;
                k=k+1;
            }

        while(i<BLOCK_WIDTH) //mur de gauche
            {
                map [i][0] = WALL;
                i=i+1;
            }

        while(l<BLOCK_WIDTH)//mur de droite
            {
                map [l][BLOCK_HEIGHT-1]=WALL;
                l=l+1;
            }

            Aff_Mush(map);
            Aff_Snake(map);

    }

int broken (int map[BLOCK_WIDTH][BLOCK_HEIGHT], int sizesnake, int x, int y)
{
    int score;

    if (map[x][y] == WALL || map[x][y] == SNAKE)
    {
    sizesnake = 0 ;
    }
    else if (map[x][y] == MUSH)
    {
    sizesnake =score;
    Aff_Mush(map);
    }

    return sizesnake;
}


int movement(int map[BLOCK_WIDTH][BLOCK_HEIGHT], int direction, int sizesnake)
{

    setPos(map, sizesnake);

    switch (direction)
    {

    case LEFT: //gauche
        snakeT[0].x--;
        if (broken(map, sizesnake, snakeT[0].x, snakeT[0].y))
        {
        map[snakeT[0].x][snakeT[0].y] = SNAKE;
        }
        else
        {
        return 0;
        }

        break;

    case RIGHT: //droite
        snakeT[0].x++;
        if (broken(map, sizesnake, snakeT[0].x, snakeT[0].y))
        {
        map[snakeT[0].x][snakeT[0].y] = SNAKE;
        }
        else
        {
        return 0;
        }

        break;

    case TOP:// haut
        snakeT[0].y--;
        if (broken(map, sizesnake,snakeT[0].x, snakeT[0].y))
        {
        map[snakeT[0].x][snakeT[0].y] = SNAKE;
        }
        else
        {
        return 0;
        }

        break;

    case BOT: //bas
        snakeT[0].y++;
        if (broken(map, sizesnake,snakeT[0].x, snakeT[0].y))
        {
        map[snakeT[0].x][snakeT[0].y] = SNAKE;
        }
        else
        {
        return 0;
        }

        break;

    }

return 1;
}

void BlitAll (int map[BLOCK_WIDTH][BLOCK_HEIGHT], SDL_Surface *Screen, SDL_Surface *Wall, SDL_Surface *Empty, SDL_Surface *Snake, SDL_Surface *Mush)
{
    int i = 0;
    int j = 0;
    SDL_Rect position;
        position.x = 0;
        position.y = 0;

         for(i = 0 ; i < BLOCK_WIDTH ; i++)
                {
                for(j = 0 ; j < BLOCK_HEIGHT ; j++)
                    {
                        position.x = i * BLOCK;
                        position.y = j * BLOCK;
                        SDL_BlitSurface(Empty, NULL, Screen, &position);
                    }
                }

        for (i=0; i<BLOCK_WIDTH; i++)
            {
                for(j=0; j<BLOCK_HEIGHT; j++)
                    {
                    position.x = i * BLOCK;
                    position.y = j * BLOCK;

                    switch (map[i][j])
                        {
                          case WALL:
                            SDL_BlitSurface (Wall, NULL, Screen, &position);
                            break;

                        case MUSH:
                            SDL_BlitSurface (Mush, NULL, Screen, &position);
                            break;

                        case SNAKE:
                            SDL_BlitSurface (Snake, NULL, Screen, &position);
                            break;

                        }

                    }
            }
            SDL_Flip(Screen);
}

