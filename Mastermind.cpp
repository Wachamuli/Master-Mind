#include <iostream>

int main() 
{
	int codigo[4], jugadas[4], i, j, vi, vj, adivina;
	char pista[4];
	std::cout << "Este programa intenta imitar el juego MasterMind \n";
	std::cout << "Introduzca su combinacion a adivinar";

	for (i = 0; i < 4; i++)
	{
		std::cout << "\n Introduzca el valor " << i + 1 << ":";
		std::cin >> codigo[i];
	}

	std::cout << "\n Introduzca sus Jugadas para adivinar la clave";

	for (i = 0; i < 10; i++) {
		std::cout << "Intento " << i + 1 << "\n";
		for (j = 0; j < 4; j++) {
			std::cout << "Introduzca el valor para la columna " << j + 1 << ":";
			std::cin >> jugadas[j];
		}
		// Verificacion de jugadas
		adivina = 0;

		for (vi = 0; vi < 4; vi++) 
		{
			pista[vi] = 'X';

			for (vj = 0;vj < 4; vj++) 
			{
				// Verificacion de jugada frente a frente
				if ((jugadas[vj] == codigo[vi]) && (vi == vj)) 
					pista[vi] = 'C';
				// verificacion de combinacion esta pero no frente a frente
				else if ((jugadas[vj] == codigo[vi]) && (vi != vj)) 
					pista[vi] = 'F';
			}
		}
		for (vi = 0; vi < 4;vi++) if (pista[vi] == 'C') adivina++;

		if (adivina == 4) 
		{
			std::cout << "ganaste en" << i << "intentos";
			i = 10;
		}
		else 
		{
			for (vi = 0; vi < 4; vi++) 
				std::cout << pista[vi] << " ";
		}

		std::cout << "Las coincidencia fueron: " << adivina;

	}
	return 0;
}