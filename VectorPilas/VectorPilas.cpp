// VectorPilas.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.

#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "Pilas.h"
using namespace std;

int Dime = 0,opc,Dato;
void Menu();
bool Vac, LLen;


int main()
{
	cout << "DIMENSION DEL VECTOR: ";
	cin >> Dime;
	
	Pilas* Pila1 = new Pilas(Dime);

	do
	{

	Menu();
	cout << "\n OPCION: "; cin >> opc;

	switch (opc)
	{
	case 1:
	{
		Vac = Pila1->PilaVacia();
		if (Vac == true)
		{
			cout << "PILA VACIA";
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
			cout << "PILA LLENA";
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
		Pila1->MostrarV();
	}break;

	case 6:
	{}break;

	default:
		
		cout << "OPCION INVALIDA";
	break;
	}

	system("pause>null");
	system("cls");
	} while (opc != 6);
		
}

void Menu()
{

	cout << "1. VALIDAR VACIA \n";
	cout << "2. VALIDAR LLENA \n";

	cout << "3. APILAR \n";
	cout << "4. DESAPILAR \n";

	cout << "5. MOSTRAR \n";
	cout << "6. SALIR";
}