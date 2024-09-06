import java.util.*;
public class MatriceSparsa {

    private class Elem{
        int i;
        int j;
        int x;
        Elem next;
    }
    private int m;
    private int n;
    Elem head;

    public MatriceSparsa(int m, int n) {
        super();
        this.m = m; //indico quante righe e colonne deve avere
        this.n = n;
    }

    public int getNumRow() {
        return this.m;
    }

    public int getNumCol() {
        return this.n;
    }
    
    public void matRemove(int i, int j) {
        Elem it = this.head;
        Elem temp = it;

        while(it != null) {
            
        }
    }

    public void set(int i, int j, int x) {
        Elem elem = this.head;
        while(elem.i != i && elem.j != j) {
            elem = elem.next;
        }

        elem.x = x;
    }

    public int get(int i, int j) {
        // TODO: Implement here
        return 0;
    }

    public String toString() {
        // TODO: Implement here
        return null;
    }

    public MatriceSparsa add(MatriceSparsa mat1, MatriceSparsa mat2) {
        // TODO: Implement here
        return null;
    }

    public MatriceSparsa tra(MatriceSparsa mat) {
        // TODO: Implement here
        return null;
    }

    public MatriceSparsa mul(MatriceSparsa mat1, MatriceSparsa mat2) {
        // TODO: Implement here
        return null;
    }
}
