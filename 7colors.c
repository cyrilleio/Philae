//
// Created by Cyrille Kone on 17/03/2020.
//


/* Template of the 7 wonders of the world of the 7 colors assigment. */
#define HEIGHT 480
#define WIDTH 480
#define NUM_COLORS 3
#include <stdio.h>     /* printf */
#include "SDL.h"
#include "maths.h"
#include "io.h"
typedef struct Rect Rect;
typedef struct Board Board;
void pause();
void DrawRect(SDL_Renderer*, const SDL_Rect*, SDL_Color);
void FillBoard(SDL_Renderer*,const SDL_Color*, Board*);
void ClearScreen(SDL_Renderer* renderer);
void PrintRect(Rect rect);
SDL_Color MakeColor(int r,int g, int b, int a);
void PrintColor(SDL_Color color);
void DrawBoard(SDL_Renderer* renderer,Board* board1);
struct Board{
    int size;
    Rect* rects;
};
struct Rect {
    SDL_Color color;
    SDL_Rect rect;
};

/* We want a 30x30 board game by default */
#define BOARD_SIZE 20

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
SDL_Color blue = {0,51,102,255} ;
SDL_Color red = {255,0,0,255};
SDL_Color green = {0,100,0,255};
SDL_Color gray = {112,128,144,255 };
SDL_Color coral = {240,128,128,255};
SDL_Color tomato = {255,99,71,255};
SDL_Color teal = {0,128,128,255};
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
    Board* board1 = malloc(sizeof(Board));
    SDL_Color colors[7] = {blue,red,green,teal,gray,coral,tomato};
    printf("\n\nWelcome to the 7 wonders of the world of the 7 colors\n"
           "*****************************************************\n\n"
           "Current board state:\n");

    //print_board();
    SDL_Init(SDL_INIT_VIDEO|SDL_INIT_EVENTS); // Initialisation de la SDL
    window = SDL_CreateWindow("Philae", 0,0,WIDTH,HEIGHT,NULL);
    SDL_SetWindowPosition(window,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED);
    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
    //SDL_RenderClear(renderer);
    ClearScreen(renderer);
    FillBoard(renderer,colors,board1);
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    SDL_Color white = {255,255,255,255};
    board1->rects[380].color = white;
    board1->rects[19].color = white;
    DrawBoard(renderer,board1);
    SDL_RenderPresent(renderer);
    int tab[5] = {3,4,6,7,8};
    PrintRect(board1->rects[380]);
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
void DrawRect(SDL_Renderer* renderer, const SDL_Rect* rect, const SDL_Color color){
    SDL_SetRenderDrawColor(renderer,color.r,color.g,color.b,color.a);
    SDL_RenderFillRect(renderer, rect);
}
void FillBoard(SDL_Renderer* renderer,const SDL_Color* colors, Board* board1){
    int case_size = HEIGHT/BOARD_SIZE; // case size in pixels
    int space_size = 0; // space between aligned cases in pixel
    Rect* rects = malloc(sizeof(Rect)*BOARD_SIZE*BOARD_SIZE);
    board1->rects = rects;
    board1->size = BOARD_SIZE;
    SDL_Rect rect = {0,0,case_size,case_size};
    //DrawRect(renderer,&rect,random_choice(colors,6));
    for (int i = 0; i <BOARD_SIZE ; ++i) {
        for (int j = 0; j < BOARD_SIZE ; ++j) {
            Rect* rect1 = malloc(sizeof(Rect));
            SDL_Color* color = malloc(sizeof(SDL_Color));
            *color = random_choice(colors,6);
            rect.x = j*case_size;
            rect.y = i*case_size;
            rect1->rect = rect;
            rect1->color = *color;
            board1->rects[i*BOARD_SIZE + j] = *rect1;
        }
    }
    while (HEIGHT - margin_bottom > rect.y + space_size){
        rect.x += space_size + case_size;
        if (rect.x >= WIDTH - margin_right){
            rect.x = margin_left;
            rect.y += case_size+space_size;
        }

        DrawRect(renderer,&rect,random_choice(colors,6));
    }
}
void ClearScreen(SDL_Renderer* renderer){
    SDL_SetRenderDrawColor(renderer,255,255,255,25);
    SDL_RenderClear(renderer);
}
SDL_Color MakeColor(int r,int g, int b, int a){
    SDL_Color color = {r, g, b, a};
    return color;
}
void FillColors(SDL_Color* color, int length){

    for (int i = 0; i <length ; ++i) {

    }
}
Board CreateBoard(){
    Board* board = malloc(sizeof(Board));

}
void DrawBoard(SDL_Renderer* renderer,Board* board1){
    for (int i = 0; i < board1->size ; ++i) {
        for (int j = 0; j < board1->size; ++j) {
            Rect rect = board1->rects[i*board1->size + j];
            DrawRect(renderer,&rect.rect,rect.color);
        }

    }
}
void PrintColor(SDL_Color color){
    printf("red: %d green:%d blue:%d alpha:%d",color.r,color.g,color.b,color.a);
};
void PrintRect(Rect rect){
    PrintColor(rect.color);
    printf("x:%d y:%d",rect.rect.x,rect.rect.y);
}
