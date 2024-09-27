import java.util.*;

public class Sort {

    /* Disponibile in libreria java */
    public void quickSortDefault(int[] array) {
        Arrays.sort(array);
    }
    public void swap(int[] array, int first, int last) {
        int temp = array[first];
        array[first] = array[last];
        array[last] = temp;
    }
    public void printArray(int[] array, int n) {
        if(n <= 0) {
            System.out.println("");
            return;
        }
        System.out.print(array[n-1] + " ");
        printArray(array, n-1);
    }

    public void mergeSort(int[] array) {
        //implementazione solo del metodo ricorsivo
		mergeSortAux(array, 0, array.length -1);
        return;
    }
	public void mergeSortAux(int[] array, int left, int right) {
		if(left < right) {
			int mid = (left+right) / 2;
			mergeSortAux(array, left, mid);
			mergeSortAux(array, mid+1, right);
			merge(array, left, mid, right);
		}
	}
	public void merge(int[] array, int left, int mid, int right) {
		int i, j, k;
		int n1 = mid-left+1, n2 = right-mid;
		int L[] = new int[n1];	int R[] = new int[n2]; //creazione di array temporanei

		for(i = 0; i < n1; ++i) {
			L[i] = array[left+i];	//copia dei primi n1 elementi nell'array di sinistra
		}
		for(j = 0; j < n2; ++j) {
			R[j] = array[mid+j+1];	//copia dei primi n2 elementi nell'array di destra
		}

		i = 0;	j = 0;	k = left;

		while(i < n1 && j < n2) {
			if(L[i] < R[j]) {
				array[k] = L[i];
				i++;
			} else {
				array[k] = R[j];
				j++;
			}
			k++;
		}

		while(i < n1) {
			array[k] = L[i];
			i++;
			k++;
		}
		while(j < n2) {
			array[k] = R[j];
			j++;
			k++;
		}
	}

    public void heapSort(int[] array) {
        int n = array.length;
        //Fase 1: Organizzare l'array in un heap
        for(int i = n/2 -1; i >= 0; --i) {
            heapify(array, n, i);
        }

        //Fase 2: Estrarre uno ad uno gli elementi dall'heap
        for(int i = n-1; i > 0; --i) {
            swap(array, 0, i);
            heapify(array, i, 0);
        }
        return;
    }
    public void heapify(int[] array, int n, int i) {
        int largest = i;
        int left = i*2 +1;  //Figlio sinistro
        int right = i*2 + 2;//Figlio destro

        if(left<n && array[left] > array[largest])
            largest = left;
        if(right<n && array[right] > array[largest])
            largest = right;
        
        if(largest != i) {
            swap(array, i, largest);

            heapify(array, n, largest);
        }
    }

    public void insertionSort(int[] array) {
        for(int i = 1; i < array.length; ++i) {
            int key = array[i];
            int j = i-1;

            while(j >= 0 && array[j] > key) {
                array[j+1] = array[j];
                j--;
            }
            array[j+1] = key;
        }
        return;
    }
    public void insertionSortAux(int[] array, int n) {
        //caso base se ha un solo elemento (è già ordinato)
        if(n <= 1) return;

        //ordina i primi n-1 elementi
        insertionSortAux(array, n-1);

        int key = array[n-1];
        insertRicorsivo(array, n-2, key);
    }
    public void insertRicorsivo(int[] array, int j, int key) {
        if(j < 0 || array[j] <= key) { //trovata la posizione corretta o siamo arrivati all'inizio
            array[j+1] = key;
            return;
        }

        //sposto l'elemento a destra e continuo la ricerca
        array[j+1] = array[j];

        //insert ricorsivo chiamato al passo precedente
        insertRicorsivo(array, j-1, key);
    }
    public void insertionSortRicorsivo(int[] array) {
        insertionSortAux(array, array.length);
        return;
    }

    public void selectionSort(int[] array) {
        System.out.println("selectionSort non è ancora implementato");
        return;
    }

    public void quickSort(int[] array) {
        int clone[] = array.clone();
        int r = array.length - 1;
        quickAux(array, 0, r);
        return;
    }
    public void quickAux(int[] array, int p, int r) {
        if(p < r) {
            int q = quickPartition(array, p, r);
            quickAux(array, p, q-1);
            quickAux(array, q+1, r);
        }
    }
    public int quickPartition(int[] array, int p, int r) {
        int x = array[r];
        int i = p-1;
        for(int j = p; j < r; ++j) {
            if(array[j] <= x) {
                i++;
                swap(array, i, j);
            }
        }
        swap(array, i+1, r);
        System.out.print("Array partizionato: ");
        printArray(array, array.length);
        return i+1;
    }

    public void radixSort(int[] array) {
        System.out.println("radixSort non è ancora implementato");
        return;
    }

    public void bucketSort(int[] array) {
        System.out.println("bucketSort non è ancora implementato");
        return;
    }
}
