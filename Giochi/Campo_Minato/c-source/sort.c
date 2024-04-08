void merge(int arr[], int left, int mid, int right) {
	int i, j, k;
	int n1 = mid - left + 1;
	int n2 = right - mid;

	int L[n1], R[n2];		 // Creazione di array temporanei
	for (i = 0; i < n1; ++i) // Assegnazione dei valori da sinistra
		L[i] = arr[left + i];
	for (j = 0; j < n2; ++j) // Assegnazione dei valori dal centro a destra
		R[j] = arr[mid + 1 + j];

	i = 0;
	j = 0;
	k = left;
	while (i < n1 && j < n2)
	{ // inserisco tutti i
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	// Copia gli elementi rimanenti di L[], se ce ne sono
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	// Copia gli elementi rimanenti di R[], se ce ne sono
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[], int left, int right)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
}