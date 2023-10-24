/**
 * Punto appartiene alla circonferenza
 */

/**
 * raggio = numero
 * punto(x, y, z)
 *
 * pitagora: sqrt( (x^2 + y^2) ^2 +  z^2)
 */
#include <iostream>
#include <cmath>

int main()
{
	int p[3], raggio;

	std::cout << "Inserire valore del raggio della sfera" << std::endl;
	std::cin >> raggio;

	for(int i = 0; i <3; ++i)
	{
		std::cout << "Inserire coordinata" << i+1<< std::endl;
		std::cin >> p[i];
	}

	int raggio_calcolato = sqrt( pow(p[0], 2) + pow(p[1], 2) + pow(p[2], 2) );

	if(raggio_calcolato == raggio)
	{
		std::cout << "Il punto appartiene alla circonferenza" << std::endl;
	}
	else
	{
		std::cout << "Il punto non appartiene alla circonferenza" << std::endl;
	}
}