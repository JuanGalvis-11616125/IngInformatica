// VectorPilas.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.

#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "Pilas.h"
#include "Lista.h"
using namespace std;

int Dime = 0,opc,Dato,VL;
void MenuV();
void MenuL();
bool Vac, LLen;


int main()
{
	cout << "[1]VECTOR  [2]LISTA: ";
	cin >> VL;

	if (VL == 1)
	{

		cout << "DIMENSION DEL VECTOR: ";
		cin >> Dime;

		Pilas* Pila1 = new Pilas(Dime);

		do
		{

			MenuV();
			cout << "\n OPCION: "; cin >> opc;

			switch (opc)
			{
			case 1:
			{
				Vac = Pila1->PilaVacia();
				if (Vac == true)
				{
					cout << "LA PILA ESTA VACIA";
				}
				else
				{
					cout << "NO ESTA VACIA";
				}

			}break;

			case 2:
			{
				LLen = Pila1->PilaLLena();
				if (LLen == true)
				{
					cout << "LA PILA ESTA LLENA";
				}
				else
				{
					cout << "NO ESTA LLENA";
				}

			}break;

			case 3:
			{
				cout << "INGRESE EL DATO PARA APILAR: ";
				cin >> Dato;
				Pila1->Apilar(Dato);
			}break;

			case 4:
			{
				if (Pila1->PilaVacia() == false)
				{
					cout << Pila1->Desapilar();
				}
				else
				{
					cout << "PILA VACIA";
				}

			}break;

			case 5:
			{
				Pila1->Buscar();

			}break;

			case 6:
			{
				Pila1->Reemplazar();
			}break;

			case 7:
			{
				Pila1->Eliminar();
			}break;

			case 8:
			{
				Pila1->MostrarV();
			}break;
			case 9:
			{
				Pila1->InsertarOrdenado();
			}
			break;

			case 10:
				Pila1->Ordenar();
				break;

			}

			system("pause>null");
			system("cls");
		} while (opc != 11);

	}
	else if (VL == 2)
	{

	cout << "DIMESION DE LA LISTA: "; cin >> Dime;
	Lista* Lista1 = new Lista(Dime);

	do
	{
		MenuL();
		cout << "\n OPCION: "; cin >> opc;

		switch (opc)
		{

		case 1:

			Vac = Lista1->PilaVacia();
			if (Vac == true)
			{
				cout << "LA PILA ESTA VACIA";
			}
			else
			{
				cout << "NO ESTA VACIA";
			}

			break;

		case 2:

			LLen = Lista1->PilaLLena();
			if (LLen == true)
			{
				cout << "LA PILA ESTA LLENA";
			}
			else
			{
				cout << "NO ESTA LLENA";
			}

			break;

		case 3:

			cout << "DATO: "; cin >> Dato;
			Lista1->ApilarLista(Dato);

			break;

		case 4:

			cout << Lista1->Desapilar();

			break;

			case 5:
				
				Lista1->MostrarL();

				break;
		}

		system("pause>null");
		system("cls");
	} while (opc != 6);


	}
}

void MenuV()
{

	cout << "1. VALIDAR VACIA \n";
	cout << "2. VALIDAR LLENA \n";

	cout << "3. APILAR \n";
	cout << "4. DESAPILAR \n";

	cout << "5. BUSCAR \n";
	cout << "6. REEMPLAZAR \n";
	cout << "7. ELIMINAR \n";

	cout << "8. MOSTRAR \n";
	cout << "9. INSERTAR ORDENADO \n";
	cout << "10. ORDENAR \n";
	cout << "11. SALIR";
}

void MenuL()
{

	cout << "1. VALIDAR VACIA \n";
	cout << "2. VALIDAR LLENA \n";

	cout << "3. APILAR \n";
	cout << "4. DESAPILAR \n";

	cout << "5. MOSTRAR \n";
	cout << "6. SALIR";
}