//
// Created by Cyrille Kone on 21/03/2020.
//

#include "maths.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdio.h>
int find(const int* tab, const int length, const int val){
    for (int i=0;i<length;i++){
        if (tab[i]== val){
            return 0;
        }
    }
    return -1;
}
void copy(const int* source, int* dest, int size_t){
    for (int i=0;i<size_t / sizeof(int);i++){
        dest[i] = source[i];
        printf("index is %d",i);
    }
}

void shuffle(char* tab, const int length){
    int* sigma = permutation(length);
    char* c_tab = malloc(sizeof(char) * length);
    memcpy(c_tab,tab, sizeof(char)*length);
    for (int i=0;i<length;i++){
        tab[i]=c_tab[sigma[i] - 1];
    }
    free(c_tab);
}
int random_integer(const int low, const int high){
     unsigned int seed = time(NULL);
     rand_r(&seed);
     return rand() %(high - low +1) + low;
}
int* permutation(const int n){
     int* tab = malloc(sizeof(int) * n);
     tab[0] = random_integer(1,n);
     int length = 1;
     while (length < n){
         int val = random_integer(1,n);
         if(find(tab,length, val) == -1){
             tab[length]=val;
             ++length;
         }

     }
     return tab;
}
