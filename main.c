#include "includes.h"
#include "fonctions.h"

int main ( int argc, char** argv )
        {
            SDL_Init( SDL_INIT_VIDEO);
            SDL_Surface *Screen = NULL;


            if (SDL_Init( SDL_INIT_VIDEO) == -1 )
                {
                    printf("Impossible de lancer la video");
                }
            Screen = SDL_SetVideoMode(WIDTH, HEIGHT, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);
            SDL_WM_SetCaption("Snake", NULL);
            int score = 0;


        int pursuit = 1;


        SDL_Event event;
        SDL_Surface *Menu = NULL;
        SDL_Rect posMenu;
        posMenu.x = 0;
        posMenu.y = 0;
        Menu = SDL_LoadBMP("Menu.bmp");


        SDL_FillRect(Screen, NULL, SDL_MapRGB(Screen->format, 0, 0, 0));
        SDL_BlitSurface(Menu, NULL, Screen, &posMenu);
        SDL_Flip(Screen);


        while (pursuit)
            {

                SDL_WaitEvent(&event);
                switch(event.type)
                {
                    case SDL_QUIT:
                    pursuit = 0;
                    break;
                    case SDL_KEYDOWN:
                        switch (event.key.keysym.sym)
                            {
                            case SDLK_ESCAPE:
                                pursuit = 0;
                                break;
                            default:
                                break;
                            }
                    break;
                    case SDL_MOUSEBUTTONUP:
                        {
                        if (event.button.x<PlayRx && event.button.x>PlayLx && event.button.y<PlayBy && event.button.y>PlayTy)
                            { game(Screen, score);}

                        else if (event.button.x<InstruRx && event.button.x>InstruLx && event.button.y<InstruBy && event.button.y>InstruTy)
                        {
                            int pursuitinstruction = 1;
                            SDL_Surface *Instruction = NULL;
                            SDL_Rect posInstruction;
                            posInstruction.x = 0;
                            posInstruction.y = 0;
                            Instruction = SDL_LoadBMP("Instructions.bmp");
                            SDL_BlitSurface(Instruction, NULL, Screen, &posInstruction);
                            SDL_Flip(Screen);

                                while (pursuitinstruction)
                                {
                                    SDL_WaitEvent(&event);
                                    switch(event.type)
                                        {
                                        case SDL_QUIT:
                                            pursuit =0;
                                            pursuitinstruction=0;
                                        break;

                                        case SDL_MOUSEBUTTONUP:
                                            if (event.button.x<InstruReturnMenuRx && event.button.x>InstruReturnMenuLx && event.button.y<InstruReturnMenuBy && event.button.y>InstruReturnMenuTy)
                                                {
                                                    SDL_BlitSurface(Menu, NULL, Screen, &posMenu);
                                                    SDL_Flip(Screen);
                                                    pursuitinstruction=0;
                                                    }
                                            if (event.button.x<InstruExitRx && event.button.x>InstruExitLx && event.button.y<InstruExitBy && event.button.y>InstruExitTy)
                                                {
                                                    pursuitinstruction=0;
                                                    pursuit = 0;
                                                    }
                                        break;
                                        }
                                }
                            SDL_FreeSurface(Instruction);

                        }

                        else if (event.button.x<ScoreRx && event.button.x>ScoreLx && event.button.y<ScoreBy && event.button.y>ScoreTy)
                        {

                            char contenu[30] = "";
                            char best[10] = "";
                            FILE* BestScore = NULL;
                            BestScore = fopen("BestScore.txt", "r");
                            fgets(best, 10, BestScore);
                            fclose(BestScore);

                            TTF_Init();
                            SDL_Color Black = {0, 0, 0};
                            TTF_Font *style = NULL;
                            SDL_Surface *texte = NULL;
                            SDL_Rect postexte;
                                postexte.x = 180 ;
                                postexte.y = 130 ;
                            style = TTF_OpenFont("alger.ttf", 28);
                            sprintf(contenu, " Le meilleur score est : %s", best);

                            texte = TTF_RenderText_Blended(style,contenu, Black);

                            int pursuitScore = 1;
                            SDL_Surface *MenuScore = NULL;
                            SDL_Rect posMenuScore;
                            posMenuScore.x = 0;
                            posMenuScore.y = 0;
                            MenuScore = SDL_LoadBMP("MenuScore.bmp");
                            SDL_BlitSurface(MenuScore, NULL, Screen, &posMenuScore);
                            SDL_BlitSurface(texte, NULL, Screen, &postexte);
                            SDL_Flip(Screen);

                                while (pursuitScore)
                                {
                                    SDL_WaitEvent(&event);
                                    switch(event.type)
                                        {
                                        case SDL_QUIT:
                                            pursuit =0;
                                                game(Screen, score);
                                                 pursuitScore=0;
                                        break;

                                        case SDL_MOUSEBUTTONUP:
                                            if (event.button.x<ScoreReturnMenuRx && event.button.x>ScoreReturnMenuLx && event.button.y<ScoreReturnMenuBy && event.button.y>ScoreReturnMenuTy)
                                                {
                                                    SDL_BlitSurface(Menu, NULL, Screen, &posMenu);
                                                    SDL_Flip(Screen);
                                                    pursuitScore=0;
                                                    }
                                            if (event.button.x<ExitRx && event.button.x>ExitLx && event.button.y<ExitBy && event.button.y>ExitTy)
                                                {
                                                    pursuitScore=0;
                                                    pursuit = 0;
                                                    }
                                        break;
                                        }
                                }
                            SDL_FreeSurface(MenuScore);
                            TTF_CloseFont(style);
                            TTF_Quit();

                        }

                        else if (event.button.x<ExitRx && event.button.x>ExitLx && event.button.y<ExitBy && event.button.y>ExitTy)
                        {pursuit = 0;}
                        }
                    break;

                }

        }

        SDL_FreeSurface(Menu);
        SDL_Quit();

        return EXIT_SUCCESS;
        }
