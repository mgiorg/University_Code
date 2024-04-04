#ifndef __CERCA_MATRICE__
#define __CERCA_MATRICE__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int R = 10;
const int C = 10;
double prob_terra = 0.5;

int terra(int **m, int r, int c);
void initPalude(int **m, double prob);
void stampaPalude(int **m);
int cercaMatrice(int **m, int r, int c, int camm[]);

#endif