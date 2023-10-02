/**
 * Anni.c
 */
#include <stdio.h>

int day(int giorno, int mese, int anno);

/**
 * Anno bisestile:
 * 	-> Anni non secolari divisibili per 4
		Anni secolari divisibili per 400
		Gli anni secolari sono quelli divisibili per 100
 */

int main()
{
	int giorno, mese, anno;

	printf("Inserire una data nel formato gg/mm/aaaa: ");
	scanf("%d/%d/%d", &giorno, &mese, &anno);

	int g_totali = day(giorno, mese, anno);
	printf("\nLa data fornita indica il giorno numero %d dell'anno!!!\a\a\a", g_totali);

	return 0;
}

int day(int giorno, int mese, int anno)
{
	int x = 0;
	int giorni = 0;

	if(anno%100 == 0 && anno%400 == 0)
	{
		x = 1;
	}
	else if(anno%4 == 0)
	{
		x = 1;
	}
	else
	{
		x = 0;
	}

	if(x == 1)
	{
		for(int i = 1; i<mese; ++i)
		{
			if(i==1 || i==3 || i==5 || i==7 || i==8 || i==10 || i==12)
			{
				giorni = giorni + 31;
			}
			else if(i == 2)
			{
				giorni = giorni + 29;
			}
			else
			{
				giorni = giorni + 30;
			}
		}
		giorni = giorni + giorno;
	}
	else
	{
		for(int i = 1; i<mese; ++i)
		{
			if(i==1 || i==3 || i==5 || i==7 || i==8 || i==10 || i==12)
			{
				giorni = giorni + 31;
			}
			else if(i == 2)
			{
				giorni = giorni + 28;
			}
			else
			{
				giorni = giorni + 30;
			}
		}
		giorni = giorni + giorno;
	}
	return giorni;
}