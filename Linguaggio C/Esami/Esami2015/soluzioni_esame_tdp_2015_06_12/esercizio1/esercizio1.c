#include <stdlib.h>
#include <string.h>

#include "esercizio1.h"

int insert_word(char* word, char** m, int m_rows, int m_cols, 
		int row, int col, int direction) {
  // Dimension check
  int length = strlen(word);  
  if(row < 0 || col < 0 || row > m_rows || col > m_cols) { return 0; }
  if(direction == 0 && col + length > m_cols) { return 0; }
  if(direction == 1 && row + length > m_rows) { return 0; }

  // Check if the spot is suitable
  int i, r = row, c = col;
  for(i = 0; i < length; ++i) {
    if(m[r][c] == '#') { return 0; }
    if(m[r][c] != '_' && m[r][c] != word[i]) { return 0; }
    if(direction == 0) { c++; }
    else { r++; }
  }
  
  // Check if the word is too small
  if(r < m_rows && c < m_cols && m[r][c] == '_') { return 0; }
  
  // Copy the word in the matrix
  r = row;
  c = col;
  for(i = 0; i < length; ++i) {
    m[r][c] = word[i];
    if(direction == 0) { c++; }
    else { r++; }
  }

  return 1;
}
