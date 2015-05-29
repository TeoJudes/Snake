#include "includes.h"
#include "fonctions.h"

int main ( int argc, char** argv )
        {

            SDL_Init( SDL_INIT_VIDEO);//on demarre la video
            SDL_Surface *Screen = NULL;//on crée la surface de l'ecran


            if (SDL_Init( SDL_INIT_VIDEO) == -1 )//si lancement impossible SDL_init renvoie -1
                {
                    printf("Impossible de lancer la video");//message d'erreur
                }
            Screen = SDL_SetVideoMode(WIDTH, HEIGHT, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);//32 bits/pixel, donnée chargées dans memoire video pas systeme+ deplacement fluides
            SDL_WM_SetCaption("Snake", NULL);//titre de la fenetre+ titre de l'icone



        int pursuit = 1;//boleen


        SDL_Event event;
        SDL_Surface *Menu = NULL;
        SDL_Rect posMenu;
        posMenu.x = 0;
        posMenu.y = 0;
        Menu = SDL_LoadBMP("Menu.bmp");


        SDL_FillRect(Screen, NULL, SDL_MapRGB(Screen->format, 0, 0, 0));//remplir la surface d'une couleur unie
        SDL_BlitSurface(Menu, NULL, Screen, &posMenu);//prepare l'image menu
        SDL_Flip(Screen);//actualise


        while (pursuit)
            {

                SDL_WaitEvent(&event);
                switch(event.type)
                {
                    case SDL_QUIT:
                    pursuit = 0;
                    break;
                    case SDL_KEYDOWN:// appuye sur une touche
                        switch (event.key.keysym.sym)//touche du cavier
                            {
                            case SDLK_ESCAPE://echap
                                pursuit = 0;
                                break;
                            case SDLK_RETURN://entrée
                                SDL_BlitSurface(Menu, NULL, Screen, &posMenu);
                                SDL_Flip(Screen);
                                break;
                            default:
                                break;
                            }
                    break;
                    case SDL_MOUSEBUTTONUP: //click de souris
                        {
                        if (event.button.x<PlayRx && event.button.x>PlayLx && event.button.y<PlayBy && event.button.y>PlayTy)//limites de Jouer
                            { game(Screen);}

                        else if (event.button.x<InstruRx && event.button.x>InstruLx && event.button.y<InstruBy && event.button.y>InstruTy)
                        {
                            int pursuitinstruction = 1;//boleen
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
                            SDL_FreeSurface(Instruction);//on libere la surface ce qui libere la mememoire utilisée

                        }

                        else if (event.button.x<ScoreRx && event.button.x>ScoreLx && event.button.y<ScoreBy && event.button.y>ScoreTy)
                        {

                            char contenu[30] = "";
                            char best[10] = "";
                            FILE* BestScore = NULL;
                            BestScore = fopen("BestScore.txt", "r");//lecture seule
                            fgets(best, 10, BestScore);//on lis une chaine de caractere
                            fclose(BestScore);

                            TTF_Init();//ecrire texte sur ecran
                            SDL_Color Black = {0, 0, 0};
                            TTF_Font *style = NULL;
                            SDL_Surface *texte = NULL;
                            SDL_Rect postexte;
                                postexte.x = 340 ;
                                postexte.y = 80 ;
                            style = TTF_OpenFont("alger.ttf", 28);//police+ taille
                            sprintf(contenu, " Le meilleur score est : %s", best);

                            texte = TTF_RenderText_Blended(style,contenu, Black);//affiche

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
        SDL_Quit();//fin du programme

        return EXIT_SUCCESS;
        }
