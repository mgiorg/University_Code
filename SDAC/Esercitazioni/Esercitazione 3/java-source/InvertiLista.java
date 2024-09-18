import java.util.*;
public class InvertiLista {
    private static void aux(LinkedList<Integer> l, int i, int n) {
		if(i == (int)n/2) return; // passo base
		int last = l.get(n-1-i); //salvo l'ultimo elemento
		l.set(n-1-i, l.get(i));
		l.set(i, last);
		aux(l, i+1, n);
    }

    public static void invertiLista(LinkedList<Integer> list) {
        aux(list, 0, list.size());
    }
}
