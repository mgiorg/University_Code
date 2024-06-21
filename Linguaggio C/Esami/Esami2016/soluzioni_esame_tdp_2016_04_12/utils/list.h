#ifndef _LIST_H_
#define _LIST_H_

#ifdef ESERCIZIO_1
#include "../esercizio1/esercizio1.h"
#endif

#ifdef ESERCIZIO_2
#include "../esercizio2/esercizio2.h"
#endif

#ifdef ESERCIZIO_3
#include "../esercizio3/esercizio3.h"
#endif

void    TipoSCL_print(TipoSCL l);
TipoSCL TipoSCL_load(char* filename);
TipoSCL TipoSCL_alloc();
void    TipoSCL_free(TipoSCL l);
int     TipoSCL_compare(TipoSCL src1, TipoSCL src2);

#endif



