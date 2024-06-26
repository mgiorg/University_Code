typedef struct {
  int rows;
  int cols;
  double **mat;
} Mat;

typedef int T;
struct NodoSCL
{
    T info;
    struct NodoSCL *next;
};
typedef struct NodoSCL TipoNodo;
typedef TipoNodo *TipoLista;

#define ERRORE_InfoAlbBin -99999
typedef int TipoInfoAlbero;

typedef struct StructAlbero {
  TipoInfoAlbero info;
  struct StructAlbero* destro;
  struct StructAlbero* sinistro;
} TipoNodoAlbero;

typedef TipoNodoAlbero* TipoAlbero;

int sommaElementi(Mat* m, int a, int b, int c, int d) {
  	int somma = 0;
	
  	printf("a: %d, b: %d, c: %d, d: %d\n", a, b, c, d);
  	for(int i = a; i <= c; ++i) {
    	for(int j = b; j <= d; ++j) { 
          	/*if(a<0 || b<0 || a >= m-> rows || b>= m-> cols || c>= m->rows || d>= m->cols) {
                somma+= 0;
            }*/
          	if(i < 0 || i >= m-> rows || j < 0 || j >= m-> cols) somma+= 0;
          	else if(m-> mat[i][j]%2 == 0) {
              printf("Sommo l'elemento %d in posizione %d, %d\n", m-> mat[i][j], i, j);
           	  somma+= m-> mat[i][j];
            }	
        }
    }
  	return somma;
}

Mat* somme_angoli(Mat* m, int i, int j) {

  Mat* r = mat_alloc(2, 2);
  int COLS = m-> cols;
  int ROWS = m-> rows;
  r-> mat[0][0] = sommaElementi(m, 0, 0, i-1, j-1);
  r-> mat[0][1] = sommaElementi(m, 0, j, i-1, COLS-1);
  r-> mat[1][0] = sommaElementi(m, i, 0, ROWS-1, j-1);
  r-> mat[1][1] = sommaElementi(m, i, j, ROWS-1, COLS-1);

  return r;
}

TipoLista aux(TipoLista l, int x) {
	if(estVuota(l)) return listaVuota();
  	TipoLista output = aux(cdr(l), x);
  	if(car(l) >= x) {
    	if(!estVuota(cdr(l))) {
        	output = cons(car(l) * car(cdr(l)), output);
        } else output = cons(0, output);
    }
  	return output;
}

TipoLista prodSuccessivoPrecedente(TipoLista l,int x) {
  
  return aux(l, x);
}


int maxSommaProdSuccessivoPrecedente(TipoLista* liste,int x, int n){
  	int max = 0;
	for(int i = 0; i < n; ++i) {
    	int somma = sommaLista(prodSuccessivoPrecedente(liste[i], x));
      	if(somma > max) max = somma;
    }
  return max;
}

int contaPariSX(TipoAlbero a) {
    if (estVuoto(a)) {
        return 0;
    }
    int count = (radice(a) % 2 == 0) ? 1 : 0;
    return count + contaPariSX(sinistro(a)) + contaPariSX(destro(a));
}

int contaDispariDX(TipoAlbero a) {
    if (estVuoto(a)) {
        return 0;
    }
    int count = (radice(a) % 2 != 0) ? 1 : 0;
    return count + contaDispariDX(sinistro(a)) + contaDispariDX(destro(a));
}

void confronta_parita(TipoAlbero* a) {
	if(estVuoto(*a)) return;
  	
  	int pariSinistro = contaPariSX(sinistro(*a));
    int dispariDestro = contaDispariDX(destro(*a));
  
  	if(pariSinistro > dispariDestro) (*a)-> info = 1;
  	else if(pariSinistro < dispariDestro) (*a)-> info = -1;
  	else (*a)-> info = 0;
  
  	confronta_parita(&(*a)-> sinistro);
 	confronta_parita(&(*a)-> destro); 

  return;
}