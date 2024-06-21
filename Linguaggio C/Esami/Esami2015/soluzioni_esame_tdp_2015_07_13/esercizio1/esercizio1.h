#ifndef _ESERCIZIO1_H_
#define _ESERCIZIO1_H_

// image struct
typedef struct Image {
  int    rows;     // rows of the image
  int    cols;     // columns of the image
  char*  pixels;   // linear array of pixels
  char** row_ptrs; // array of row pointers
} Image;

// extracts the edges in an image. A pixel is an edge if the absolute value of the
// difference between the pixel and one of the neighbors is above a certain threshold
void Image_extractEdges(Image* dest, Image* src, char threshold);

// Check if a pixel is an edge
void Image_extractEdges(Image* dest, Image* src, char threshold)

#endif
