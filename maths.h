//
// Created by Cyrille Kone on 21/03/2020.
//

#ifndef PHILAE_MATHS_H
#define PHILAE_MATHS_H

#endif //PHILAE_MATHS_H
#include "SDL.h"
int random_integer(int low, int high );
int* permutation(int n);
void shuffle(char* tab, int length);
int randint(int n);
int choice(const int* tab, int length);
SDL_Color random_choice(const SDL_Color* colors, int length);