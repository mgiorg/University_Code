int fattoriale(int n)
{
	if (n == 0)
		return 1;
	else
		return n * fattoriale(n - 1);
}

int somma(int x, int y)
{
	if (y == 0)
		return x;
	else
		return 1 + somma(x, y - 1);
}

int prodotto(int x, int y)
{
	if (y == 0)
		return 0;
	else
		return somma(x, prodotto(x, y - 1));
}

int potenza(int b, int e)
{
	if (e == 0)
		return 1;
	else
		return prodotto(b, potenza(b, e - 1));
}

int fibonacci(int n)
{
	if (n == 1 || n == 0)
	{
		return n;
	}
	return (fibonacci(n - 1) + fibonacci(n - 2));
}

void stampa_stringa(char *s)
{
	if (*s == '\0')
		printf("\n");

	else
	{
		printf("%c", *s);
		stampa_stringa(s + 1);
	}
}

void stampa_array(int v[], int n)
{
	if (n == 0)
		printf("\n");

	else
	{
		printf("%d", v[0]);
		stampa_array(v + 1, n - 1);
	}
}

/*TORRI DI HANOI*/
void muoviUnDisco(int sorg, int dest, int *c)
{
	printf("Muovi un disco dalla %d a %d\n", sorg, dest);
	*c = *c + 1;
}

void muovi(int n, int sorg, int dest, int aux, int *c)
{
	if (n == 1)
		muoviUnDisco(sorg, dest, c);
	else
	{
		muovi(n - 1, sorg, aux, dest, c);
		muoviUnDisco(sorg, aux, c);
		muovi(n - 1, aux, dest, sorg, c);
	}
}