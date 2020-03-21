//
// Created by Cyrille Kone on 17/03/2020.
//


/* Template of the 7 wonders of the world of the 7 colors assigment. */
#define HEIGHT 480
#define WIDTH 640
#include <stdio.h>     /* printf */
#include "SDL.h"
#include "maths.h"
void pause();
void DrawRect(SDL_Renderer*, const SDL_Rect*, const SDL_Color*);
void FillBoard(SDL_Renderer*,const SDL_Color*);
void ClearScreen(SDL_Renderer* renderer);
/* We want a 30x30 board game by default */
#define BOARD_SIZE 30

/** Represent the actual current board game
 *
 * NOTE: global variables are usually discouraged (plus encapsulation in
 *     an appropriate data structure would also be preferred), but don't worry.
 *     For this first assignment, no dinosaure will get you if you do that.
 */
char board[BOARD_SIZE * BOARD_SIZE] = { 0 }; // Filled with zeros
int margin_left = 20;
int  margin_right = 20;
int margin_top = 20;
int margin_bottom = 20;

/** Retrieves the color of a given board cell */
char get_cell(int x, int y)
{
    return board[y * BOARD_SIZE + x];
}

/** Changes the color of a given board cell */
void set_cell(int x, int y, char color)
{
    board[y * BOARD_SIZE + x] = color;
}

/** Prints the current state of the board on screen
 *
 * Implementation note: It would be nicer to do this with ncurse or even
 * SDL/allegro, but this is not really the purpose of this assignment.
 */
void print_board(void)
{
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            printf("%c", get_cell(i, j));
        }
        printf("\n");
    }
}

/** Program entry point */
int main(void)
{
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Color color = {random_integer(0,255),random_integer(0,255),random_integer(0,255),random_integer(0,255)};
    printf("\n\nWelcome to the 7 wonders of the world of the 7 colors\n"
           "*****************************************************\n\n"
           "Current board state:\n");

    //print_board();
    SDL_Init(SDL_INIT_VIDEO|SDL_INIT_EVENTS); // Initialisation de la SDL
    window = SDL_CreateWindow("Philae", 0,0,WIDTH,HEIGHT,SDL_WINDOW_RESIZABLE);
    SDL_SetWindowPosition(window,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED);
    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
    //SDL_RenderClear(renderer);
    ClearScreen(renderer);
    FillBoard(renderer,&color);
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    SDL_RenderPresent(renderer);
    char p[5] = "Hello";
    for (int i=0;i<5;i++){
        shuffle(p,5);
        puts(p);
    }
    pause(); // Mise en pause du programme
    SDL_Quit(); // Arrêt de la SDL
    return 0; // Everything went well
}
void pause()
{
    int continuer = 1;
    SDL_Event event;

    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
        }
    }
}
void DrawRect(SDL_Renderer* renderer, const SDL_Rect* rect, const SDL_Color* color){
    SDL_SetRenderDrawColor(renderer,color->r,color->g,color->b,color->a);
    SDL_RenderFillRect(renderer, rect);
}
void FillBoard(SDL_Renderer* renderer,const SDL_Color* color){
    int case_size = 50; // case size in pixels
    int space_size = 10; // space between aligned cases in pixel
    SDL_Rect rect = {margin_top,margin_left,case_size,case_size};
    DrawRect(renderer,&rect,color);
    while (HEIGHT - margin_bottom > rect.y + space_size){
        rect.x += space_size + case_size;
        if (rect.x >= WIDTH - margin_right){
            rect.x = margin_left;
            rect.y += case_size+space_size;
        }

        DrawRect(renderer,&rect,color);
    }
}
void ClearScreen(SDL_Renderer* renderer){
    SDL_SetRenderDrawColor(renderer,255,255,255,25);
    SDL_RenderClear(renderer);
}