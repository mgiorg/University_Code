TipoLista sommeDueADue_aux(TipoLista lista) {
  	if (lista == NULL) return listaVuota();
	else if (cdr(lista) == NULL) return lista;
  	else {
    	return cons(car(lista) + car(cdr(lista)), sommeDueADue_aux(cdr(cdr(lista))));
    }
}

TipoLista append (TipoLista l, T e) {
	if (l == NULL) return cons(e, l);
  	return cons(car(l), append(cdr(l) ,e)); 
}

TipoLista sommeDueADue(TipoLista l) {
	int len = length(l) / 2;
  	TipoLista nuova = (TipoLista) malloc ((length(l) + 1) * sizeof(int));
  	if (l == NULL) return listaVuota();
	nuova = append(l, car(l));
  	if (length(l) == 1) return cons(2 * car(l), nuova);
  	if (length(l) % 2  == 0) return sommeDueADue_aux(l);
  	else return sommeDueADue_aux(nuova);  	
}

double* mediaSommeDueADue(TipoLista* liste, int n) {
  	TipoLista* nuove = (TipoLista*) malloc (n * length(liste[0]) * sizeof(int));
  	double* ris = (double*) malloc (n * sizeof(double));
  	for (int i = 0; i < n; i++) {
    	nuove[i] = sommeDueADue(liste[i]);
    }
	for (int i = 0; i < n; i++) {
    	*(ris + i) = (double)sommaLista(nuove[i]) / (double)length(nuove[i]);
    }
	return ris;
}
