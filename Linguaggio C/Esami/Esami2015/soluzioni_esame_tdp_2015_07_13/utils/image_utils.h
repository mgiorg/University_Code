#ifndef _IMAGE_UTILS_H_
#define _IMAGE_UTILS_H_

#include "../esercizio1/esercizio1.h"

Image* Image_alloc(int rows, int cols);
void   Image_free(Image* image);

Image* Image_load(char* filename);
void   Image_write(Image* image, char* filename);

void   Image_print(Image* image);
int    Image_compare(Image* image_a, Image* image_b);

#endif



