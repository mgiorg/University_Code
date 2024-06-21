#include <stdlib.h>
#include <stdio.h>

#include "image_utils.h"

Image* Image_alloc(int rows, int cols) {
  Image* image = (Image*) malloc(sizeof(Image));
  char* pixels = (char*) malloc(rows * cols * sizeof(char));
  char** row_ptrs = (char**) malloc(rows * sizeof(char*));
  image->rows = rows;
  image->cols = cols;
  image->pixels = pixels;
  image->row_ptrs = row_ptrs;  
  int i;  
  for(i = 0; i < rows; ++i) { 
    row_ptrs[i] = pixels + (i * cols); 
  }
  return image;
}

void Image_free(Image* image) {
  char* pixels = image->pixels;
  char** row_ptrs = image->row_ptrs;
  free(image);
  free(pixels);
  free(row_ptrs);
}

Image* Image_load(char* filename) {
  int rows = 0;
  int cols = 0;
  FILE* f = fopen(filename, "r");
  if(f == NULL) {
    printf("Error while opening file %s... aborting!\n", filename);
    exit(-1);
  }

  char buffer[1024];
  if(fscanf(f, "%s", buffer) == 1) { rows = atoi(buffer); }
  else {
    printf("Error while reading file %s, cannot read number of rows of the image... aborting!\n", filename);
    exit(-1);
  }
  if(fscanf(f, "%s", buffer) == 1) { cols = atoi(buffer); }
  else {
    printf("Error while reading file %s, cannot read number of cols of the image... aborting!\n", filename);
    exit(-1);
  }
  if(rows == 0 || cols == 0) { 
    printf("Error while reading file %s, either rows or columns number of the image are zero... aborting!\n", filename);
    exit(-1);
  }
  int i = 0;  
  Image* image = Image_alloc(rows, cols);
  while(i < rows * cols && fscanf(f, "%s", buffer) == 1) {
    image->pixels[i] = atoi(buffer);
    i++;
  }
  if(i != rows * cols) {
    printf("Error while reading file %s, cannot read all image pixels... aborting!\n", filename);
    Image_free(image);
    exit(-1);
  }

  return image;
}

void Image_write(Image* image, char* filename) {
  FILE* f = fopen(filename, "w");
  if(f == NULL) {
    printf("Error while opening file %s... aborting!\n", filename);
    exit(-1);
  }

  fprintf(f, "%d %d\n", image->rows, image->cols);
  int r, c;  
  for(r = 0; r < image->rows; ++r) {
    for(c = 0; c < image->cols; ++c) {
      fprintf(f, "%d ", image->row_ptrs[r][c]);
    }
    fprintf(f, "\n");
  }
}

void Image_print(Image* image) {
  printf("Image %dx%d:\n", image->rows, image->cols);
  int r, c;
  for(r = 0; r < image->rows; ++r) {
    for(c = 0; c < image->cols; ++c) {
      printf("%d  ", (int)image->row_ptrs[r][c]);
    }
    printf("\n");
  }
}

int Image_compare(Image* image_a, Image* image_b) {
  int r, c;  
  if(image_a->rows != image_b->rows) { return 0; }
  if(image_a->cols != image_b->cols) { return 0; }
  for(r = 0; r < image_a->rows; ++r) {
    for(c = 0; c < image_a->cols; ++c) {
      if(image_a->row_ptrs[r][c] != image_b->row_ptrs[r][c]) { return 0; }
    }
  }
  return 1;
}
