#include <iostream>

int main() 
{
	int codigo[4], supuestoCodigo[4], numeroCoincidencias;
	char pistas[4];

	std::cout << "MASTERMIND\n";
	std::cout << "Intente adivinar el codigo:";

	// TODO: Remover y reemplezar por el generador de codigo aleatorio
	for (int i = 0; i < 4; i++)
	{
		std::cout << "\nIntroduzca el valor " << i + 1 << ":";
		std::cin >> codigo[i];
	}

	for (int i = 0; i < 10; i++) 
	{
		std::cout << "Intento Nro. " << i + 1 << "\n";
		numeroCoincidencias = 0;

		for (int j = 0; j < 4; j++) 
		{
			std::cout << "Introduzca el valor para la columna " << j + 1 << ":";
			std::cin >> supuestoCodigo[j];
		}

		for (int vc = 0; vc < 4; vc++)
		{
			for (int vj = 0;vj < 4; vj++) 
			{
				if ((supuestoCodigo[vj] == codigo[vc]) && (vc == vj)) 
					pistas[vc] = 'C';
				else if ((supuestoCodigo[vj] == codigo[vc]) && (vc != vj)) 
					pistas[vc] = 'F';
				else
					pistas[vc] = 'X';
			}
		}

		for (int vi = 0; vi < 4;vi++)
		{
			if (pistas[vi] == 'C')
				numeroCoincidencias++;
		}

		if (numeroCoincidencias == 4) 
		{
			std::cout << "Ganaste en" << i << "intentos";
			break;
		}
		
		for (int i = 0; i < 4; i++) 
			std::cout << pistas[i] << " ";

		std::cout << "Las coincidencias fueron: " << numeroCoincidencias;

	}

	return 0;
}