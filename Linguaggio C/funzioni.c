#include <stdlib.h>
#include <stdbool.h>

typedef int T;
typedef int TArray;
struct NodoSCL
{
    T info;
    struct NodoSCL *next;
};
typedef struct NodoSCL TipoNodo;
typedef TipoNodo *TipoLista;

TipoLista listaVuota() { return NULL; }

bool estVuota(TipoLista l) { return (l == NULL); }

TipoLista cons(T e, TipoLista l)
{
  TipoLista nuovo = (TipoLista)malloc(sizeof(TipoNodo));
  nuovo->info = e;
  nuovo->next = l;
  return nuovo;
}

T car(TipoLista l)
{
  if (l == NULL)
  {
    printf(" ERRORE : lista vuota \n ");
    exit(1);
  }
  return l->info;
}

TipoLista cdr(TipoLista l)
{
  if (l == NULL)
  {
    printf(" ERRORE : lista vuota \n ");
    exit(1);
  }
  return l->next;
}

void printlist_aux(TipoLista l)
{
	if (estVuota(l)) return;
	printf("%d, ", car(l));
	printlist_aux(cdr(l));
}



void printlist(TipoLista l)
{
	if (estVuota(l))
		printf("()");
	else
		printlist_aux(l);
	printf("\n");
}

void printlistcar_aux(TipoLista l)
{
	if (estVuota(l)) return;
	printf("%c, ", (char)car(l));
	printlistcar_aux(cdr(l));
}



void printlistcar(TipoLista l)
{
	if (estVuota(l))
		printf("()");
	else
		printlistcar_aux(l);
	printf("\n");
}




void freelist(TipoLista l)
{
	if (l == NULL)
		return;
	freelist(l->next);
	free(l);
}


int length(TipoLista l) {
	if (estVuota(l)) 
		return 0;
	return 1 + length(cdr(l));
}

int sommaLista_aux(int somma, TipoLista l) {
	if (estVuota(l))
		return somma;
	else
		return somma + sommaLista_aux(car(l), cdr(l));
}

int sommaLista(TipoLista l) {
	if (estVuota(l))
		return 0;
	else	
		return sommaLista_aux(car(l), cdr(l));
}

typedef struct {
  int rows;
  int cols;
  int **mat;
} Mat;

void mat_free(Mat *m)
{
	free(*m->mat);
	free(m->mat);
	free(m);
}

void mat_print(const Mat *m)
{

	if (m == NULL)
	{
		printf("NULL\n");
		return;
	}

	for (int r = 0; r < m->rows; ++r)
	{
		for (int c = 0; c < m->cols; ++c)
		{
			printf("%d, ", m->mat[r][c]);
		}
		printf("\n");
	}
}

void vec_print(float *vec, int size)
{

	if (vec==NULL){
		printf("NULL\n");
		return;
	}

	for (int r = 0; r < size; ++r)
	{
		
		printf("%f, ", vec[r]);
		
	}
	printf("\n");
}

Mat *mat_alloc(int rows, int cols)
{

	Mat *m = (Mat *)malloc(sizeof(Mat));

	m->cols = cols;
	m->rows = rows;
	m->mat = (int **)malloc(sizeof(int *) * rows);

	int *row_p = (int *)malloc(sizeof(int) * rows * cols);
	for (int i = 0; i < rows; ++i)
	{
		m->mat[i] = row_p;
		row_p += cols;
	}

	return m;
}