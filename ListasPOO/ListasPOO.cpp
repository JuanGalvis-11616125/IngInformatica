#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include "Lista.h"
using namespace std;

void Menu();

int D;
int opc = 0;
int OL = 0;
int opcO = 0;
Lista* lista1 = new Lista();
Lista* lista2 = new Lista();
Lista* lista3 = new Lista();
Lista* lista4 = new Lista();

int main()
{
	do
	{
		Menu();
		cin >> opc;
		
		if (opc != 11)
		{
			cout << "LISTA 1 - 2: ";
			cin >> OL;
		}

		switch (opc)
		{
		case 1:
			cout << "\nINGRESE UN NUMERO: "; cin >> D;
			if (OL == 1)
			{
				lista1->InsertarInicio(D);
			}
			else if (OL == 2)
					{
						lista2->InsertarInicio(D);
					}
			break;

		case 2:
			cout << "\nINGRESE UN NUMERO: "; cin >> D;
			if (OL == 1)
			{
				lista1->InsertarFinal(D);
			}
			else if (OL == 2)
			{
				lista2->InsertarFinal(D);
			}
			break;

		case 3:
			if (OL == 1)
			{
				lista1->Ordenar();
			}
			else if (OL == 2)
			{
				lista2->Ordenar();
			}
		
			break;

		case 4:
			cout << "\nINGRESE EL NUMERO: "; cin >> D;
			if (OL == 1)
			{
				lista1->Buscar(D);
			}
			else if (OL == 2)
			{
				lista2->Buscar(D);
			}
			
			break;

		case 5:
			cout << "\nINGRESE EL NUMERO: "; cin >> D;
			if (OL == 1)
			{
				lista1->Reemplazar(D);
			}
			else if (OL == 2)
			{
				lista2->Reemplazar(D);
			}
			
			break;

		case 6:
			cout << "\nINGRESE EL NUMERO: "; cin >> D;
			if (OL == 1)
			{
				lista1->Eliminar(D);
			}
			else if (OL == 2)
			{
				lista2->Eliminar(D);
			}
		
			break;

		case 7:
			if (OL == 1)
			{
				lista1->MostrarLista();
			}
			else if (OL == 2)
			{
				lista2->MostrarLista();
			}
			else if (OL == 3)
			{
				lista3->MostrarLista();
			}
			else if (OL == 4)
			{
				lista4->MostrarLista();
			}
			
			break;

		case 8:
			cout << "\nINGRESE EL NUMERO: "; cin >> D;
			if (OL == 1)
			{
				cout << "1-ASCENDENTE O 2-DESCENDENTE: "; cin >> opcO;
				lista1->InsertarOrdenado(D, opcO);
			}
			else if (OL == 2)
			{
				cout << "1-ASCENDENTE O 2-DESCENDENTE: "; cin >> opcO;
				lista2->InsertarOrdenado(D, opcO);
			}
			break;

		case 9:

			lista3->SumarListas(lista1,lista2);
			
			lista1->MostrarLista();
			lista2->MostrarLista();
			cout << "RESULTADO: \n";
			lista3->MostrarLista();

			break;

		case 10:

			lista4->UnirListas(lista1, lista2);
			break;

		}
		
		cin.get();
		// LIMPIAR PANTALLA cls->CLEAR
		system("cls");

	} while (opc != 11);
}

void Menu()
{
	// OPCIONES
	cout << "\n \t LISTA ENLAZADA\n\n";
	cout << "\n1. INSERTAR AL INICIO";
	cout << "\n2. INSERTAR AL FINAL";
	cout << "\n3. ORDENAR LISTA";
	cout << "\n4. BUSCAR UN VALOR";
	cout << "\n5. REEMPLAZAR UN VALOR";
	cout << "\n6. ELIMINAR UN VALOR";
	cout << "\n7. MOSTRAR LA LISTA";
	cout << "\n8. INSERTAR ORDENADO";
	cout << "\n9. SUMAR LISTAS";
	cout << "\n10. UNIR LISTAS";
	cout << "\n11. SALIR";

	cout << "\n INSERTAR OPCION: ";
}