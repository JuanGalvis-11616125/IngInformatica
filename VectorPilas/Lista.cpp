#include <iostream>
#include <conio.h>
using namespace std;
#include "Lista.h"

// NODOS

Nodo::Nodo()
{
	dato = 0;
	Liga = nullptr;
}

int Nodo::GetDato()
{
	return dato;
}

void Nodo::SetDato(int D)
{
	dato = D;
}

Nodo* Nodo::GetLiga()
{
	return Liga;
}

void Nodo::SetLiga(Nodo* L)
{
	Liga = L;
}

// LISTA

Lista::Lista(int Dimension)
{
	Punta = nullptr;
	Tope = -1;
	Limite = Dimension;
}

bool Lista::PilaVacia()
{
	if (Tope == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//LISTA LLENA
bool Lista::PilaLLena()
{
	if (Tope == Limite)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Lista::Desapilar()
{

	if (PilaVacia())
	{
		cout << "LA LISTA ESTA VACIA";
	}
	else
	{
		Nodo* p1 = Punta;
		int Aux = 0,Cant = 0;

		while (p1 != nullptr)
		{
			if (Cant == Tope)
			{
				Aux = p1->GetDato();
				Tope--;
			}
			else
			{
				p1 = p1->GetLiga();
			}

			Cant++;

		}

		return Aux;
	}

	cin.get();
}

void Lista::ApilarLista(int D)
{

	if (!PilaLLena()) 
	{

		Nodo* x = new Nodo();
		Nodo* P = Punta;
		x->SetDato(D);
		x->SetLiga(nullptr);
		Tope++;

		if (Punta == NULL) {

			Punta = x;

		}
		else {

			while (P->GetLiga() != NULL) {

				P = P->GetLiga();

			}

			P->SetLiga(x);

		}

	}
	else
	{

		cout << "PILA LLENA.";

	}
}

void Lista::MostrarL()
{

	Lista* Aux = new Lista(Limite);

	if (Tope == -1)
	{
		cout << "NO HAY PILA EXISTENTE";
	}
	else
	{
		int a = Tope,b=0;

		//DESAPILO
		while (Tope != -1)
		{
			b = Desapilar();
			cout << "|" << b << "|";
			cout << "\n";
			Aux->ApilarLista(b);
		}

		while (Tope != a)
		{
			b = Aux->Desapilar();
			ApilarLista(b);

		}

	}
}


