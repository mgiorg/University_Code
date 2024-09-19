/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
import java.util.*;
/**
 *
 * @author silvia
 */
public class Algoritmi {
    
    public static void permuta_negativi_positivi(float [] a){
        int j = 0;
        for(int i = 0; i < a.length; ++i) {
            if(a[i] < 0) {
                float temp = a[j];
                a[j] = a[i];
                a[i] = temp;
                j++;
            }
        }
        return;
}
    
    public static void bandiera(char[] a){
        int s = 0, d = a.length -1;
        while(a[s] == 'v') s++;
        while(a[d] == 'r') d--;

        while(d-s > 0) {
            if(a[s] != 'v') {
                if(a[d] != 'r') {
                    char temp = a[d];
                    a[d] = a[s];
                    a[s] = temp;
                    if(a[s] == 'v') s++;
                    if(a[d] == 'r') d--;
                } else d--;
            } else s++;
        }
        return;
    }
    
       
    public static boolean isQuadratoLatino(int[][] m){
        int dim = m.length;

        for(int i = 0; i < dim; i++) {

            HashSet<Integer> row = new HashSet<Integer>();
            HashSet<Integer> col = new HashSet<Integer>();
            for(int j = 0; j < dim; j++) {
                row.add(m[i][j]);
                col.add(m[j][i]);
            }

            if(row.size() != dim || col.size() != dim) return false;
        }
        return true;
    }
    public static void mergeSort(float[] a, int l, int r) {
        if(l<r) {
            int m = (l+r)/2;
            mergeSort(a, l, m);
            mergeSort(a, m+1, r);
            merge(a, l, m, r);
        }
    }
    public static void merge(float[] a, int l, int m, int r) {
        int n1 = m - l + 1;
        int n2 = r - m;

        // Crea sottoarray temporanei
        float[] L = new float[n1];
        float[] R = new float[n2];

        // Copia i dati negli array temporanei
        for (int i = 0; i < n1; ++i) {
            L[i] = a[l + i];
        }
        for (int j = 0; j < n2; ++j) {
            R[j] = a[m + 1 + j];
        }
        int i = 0, j = 0;
        int k = l;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                a[k] = L[i];
                i++;
            } else {
                a[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            a[k] = L[i];
            i++;
            k++;
        }

        // Copia gli elementi rimanenti di R[] se ce ne sono
        while (j < n2) {
            a[k] = R[j];
            j++;
            k++;
        }
    }
    public static float[] primiKMin(float[] a, int k){
        mergeSort(a, 0, a.length -1);
        //Arrays.sort(a);
        float[] arr = Arrays.copyOfRange(a, 0, k+1);
        return arr;
    }
    
}
