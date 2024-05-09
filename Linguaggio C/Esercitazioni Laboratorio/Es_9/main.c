#include "lista/lista.c"

TipoLista init(T* vec, int len);
TipoLista doubledCopy(TipoLista list);
TipoLista multipleSublist(TipoLista list, unsigned int m);
TipoLista subList(TipoLista list, int start, int end);
TipoLista interleave(TipoLista l1, TipoLista l2);

int main() {
    T vec[] = {0, 1, 2, 3, 4};
    int n = 5;
    TipoLista lista = init(vec, n);
    printlist(lista);

    return 0;
}

TipoLista init(T* vec, int len) {
    if(vec == NULL || (vec+1) == NULL) return;
    else {
        TipoLista lista = cons(*vec, init(vec+1, len));
        return lista;
    }
}