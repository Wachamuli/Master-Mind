// Mastedmind Optimizado
//Falta solo generar random los 4 numeros

#include <iostream>
#include <cctype>

using namespace std;

int main()
{
	int clave[4], nCoincidencias = 0, intentos=0;
	int Jugadas[10][4];
	char Pistas[10][4];
	
	
	//--------------------Explicando juego a usuario y dando bienvenida------------------------

	cout << "Bienvenido a MASTERMIND" << endl;
	cout << "Tienes 10 intentos para adivinar la clave oculta de" << endl;
	cout << " 4 numeros (entre el 1-6) en el orden correcto."<<endl;

	//---------------Generar 4 numeros random para la clave 4 digitos entre 1 y 6--------------
	
	int arreglo[10];
		int aux = 0;

		srand(time(0));

		for (int i = 0; i < 4; i++) {
			aux = (1 + rand() % 6);

			int aux2 = 0;

			while (aux2 < i) {

				if (aux != arreglo[aux2])
					aux2++;

				else {
					aux = (1 + rand() % 6);
					aux2 = 0;

				}
			}

			clave[i] = aux;//guardamos la clave generada con esta funcion
			//cout << clave[i] << "\n";
		}
	
	//clave[0] = 5; clave[1] = 3; clave[2] = 6; clave[3] = 1;

	//-------------------------------------------Comenzar juego-----------------------------
	

	while(nCoincidencias!=4 && intentos<10)//mientras no se completen las 4 C en pista y los intentos sean menores a 10
	{
		int  jugada[4];
		nCoincidencias = 0;
		
		
		for (int j = 0; j < 4; j++) // Bucle para que el usuario introduzca el intento
		{
			int buffer = 0;
			char Ibuffer[10];
			cout << "Introduzca el valor para la columna " << j + 1 << ":";
			cin >> Ibuffer; //guardamos el valor del buffer en la variable tipo CHAR
			buffer = atoi(Ibuffer);//convertimos caracter en entero
			//en caso de no ser un numero el buffer entonces sera igual a 0.
			
			bool repetido = false; //declaro una variable tipo bool para validar si el
			//digito introducido esta repetido o no en la jugada actual
			for(int i=0; i<4; i++)
			{
				if (buffer == Jugadas[intentos][i]) { repetido = true; } //si esta repetido
				//entonces es verdadero
			}

			//validamos aca el rango y si esta repetido no nos dejara guardar tampoco
			if (buffer < 1 || buffer > 6 || repetido)
			{
				cout << "Este valor no esta en el rango, no es valido o es repetido" << std::endl; // Indicamos el error
				j--;
				
			}
			else
			{
			
				jugada[j] = buffer;//en caso contrario guardamos correctamente el valor
				Jugadas[intentos][j] = buffer;//aprovechamos y guardamos tambien en el arreglo resumen

			}
			
		}

		char pista[4]; //declaramos arreglo para las pistas de forma local
		
		for (int j = 0; j < 4; j++) // Bucle para que el usuario adivine el codigo
		{
			for (int c = 0; c < 4; c++)
			{
				if (jugada[j] == clave[c]) //si el valor de la jugada coincide con alguna de la clave
				{
					if (j == c) //ademas si este que coincide pertenece al mismo indice o lugar
					{
						pista[j] = 'C'; //acierta y esta caliente
					}
					else //si solo coincide en algun lugar que no es el mismo esta frio
					{
						pista[j] = 'F'; 
					}
				}
				else if ((pista[j] != 'F') && pista[j] != 'C') //ahora si en ningun momento esta no coincidencia
					//no fue ni F ni C y no esta entonces sera X.
				{
					pista[j] = 'X';
				}
			}
		}

		for (int j = 0; j < 4; j++) // Bucle para guardar las pistas en el arreglo resumen de Pistas
		{
			Pistas[intentos][j] = pista[j];
		}


		//------------------Se imprime el resultado por fila--------------------------
		for (int c = 0; c < 4; c++) // Bucle para imprimir la pista
		{
			cout << "[" << pista[c] << "]";
		}
		cout << endl;
		for (int c = 0; c < 4; c++) // Bucle para imprimir los digitos jugados
		{
			cout << "[" << jugada[c] << "]";
		}
		cout <<endl<< "calificacion actual: " << 10 - intentos <<endl;

		for (int c = 0; c < 4; c++) // Bucle para contar el numero de C (acertados o calientes)
		{
			if (pista[c] == 'C') { nCoincidencias++;}
		}

		//al final limpiamos
		memset(pista, 0, 4);//se limpia el arreglo pista
		memset(jugada, 0, 4);//se limpia el arreglo jugada
		intentos++;//agrego un intento completado
	}

	//Luego de salir del bucle, sea porque se acabaron los intentos o porque adivino los 4 digitos
	//Continuamos ahora a determinar la salida:

	if (nCoincidencias == 4)//si las coincidencias son 4 (hay 4 C en la pista)
	{
		cout << "Felicitaciones, ha adivinado los siguientes 4 digitos: " << endl;
		
	}else //en caso de que no
	{
		cout << "Lastima, no ha adivinado los siguientes 4 digitos: " << endl;
	}

	for (int c = 0; c < 4; c++) // Imprimimos la clave de 4 digitos
	{
		cout << "[" << clave[c] << "]";
	}
	cout << endl;
	
	cout << endl << "Resumen del Juego: " << endl; //imprimimos las tabla resumen del juego

	for (int i = 0; i < intentos; i++) // Bucle para imprimir todas las pistas y jugadas
	{
		for (int j= 0; j < 4; j++) // Bucle para imprimir jugadas
		{
			cout << "[" << Jugadas[i][j] << "]";
		}
		cout << "               ";
		for (int j = 0; j < 4; j++) // Bucle para imprimir pistas
		{
			cout << "[" << Pistas[i][j] << "]";
		}
		cout << endl;
	}cout << endl;



	getchar();

	return 0;
}
