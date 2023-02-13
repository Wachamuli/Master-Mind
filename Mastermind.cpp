// William Payan - ID: 1103012


#include <iostream>
#include <string> // Nos pormite usar la funcion getline

int main()
{
	int codigo[4], supuestoCodigo[4], numeroCoincidencias;
	char pistas[4];
	std::string w; //Esta variable lee un string en caso de que el usuario lo introduzca por error
	std::cin.exceptions(std::istream::failbit); // Este componente es usado en el catch para evitar un error en el programa en caso de que se introduzca un string
		
	std::cout << "MASTERMIND\n";
	std::cout << "Intente adivinar el codigo:";

	// TODO: Remover y reemplezar por el generador de codigo aleatorio
	for (int i = 0; i < 4; i++)
	{
		std::cout << "\nIntroduzca el valor " << i + 1 << ":";
		std::cin >> codigo[i];
	}

	for (int i = 0; i < 10; i++) // Bucle de intentos
	{

		std::cout << "Intento Nro. " << i + 1 << "\n";
		numeroCoincidencias = 0;

		for (int j = 0; j < 4; j++) // Bucle para que el usuario adivine el codigo
		{
			
			try
			{
				std::cout << "Introduzca el valor para la columna " << j + 1 << ":";
				std::cin >> supuestoCodigo[j];
				if (supuestoCodigo[j] < 1 || supuestoCodigo[j] > 6) // Comprobamos que los valores esten dentro del rango especificado por las reglas del juego
				{
					std::cout << "Este valor no esta en el rango" << std::endl; // Indicamos el error
					std::cout << "Por favor introduzca un valor entre 1 y 6" << std::endl; // Solicitamos la rectificacion del usuario
					j--; // Evitamos que se agregue un valor a una nueva columna sin rectificar el error
				}
				
			}
			catch (std::ios_base::failure) // Excepciones en caso de error
			{
				std::cout << "Este valor no es del tipo adecuado" << std::endl; // Indicamos el error
				std::cout << "Por favor introduzca un valor entre 1 y 6" << std::endl; // Solicitamos la rectificacion del usuario
				std::cin.clear(); //Eliminamos el string puesto por el usuario
				getline(std::cin, w); //Con esta funcion leemos el string
				j--; // Evitamos que se agregue un valor a una nueva columna sin rectificar el error
			}
			
		}

		for (int vc = 0; vc < 4; vc++)
		{
			for (int vj = 0; vj < 4; vj++)
			{
				if ((supuestoCodigo[vj] == codigo[vc]) && (vc == vj))
					pistas[vc] = 'C';
				else if ((supuestoCodigo[vj] == codigo[vc]) && (vc != vj))
					pistas[vc] = 'F';
				else
					pistas[vc] = 'X';
			}
		}

		for (int vi = 0; vi < 4; vi++)
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