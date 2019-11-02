#include <iostream>
#include "Pilas.h"
using namespace std;

Pilas::Pilas(int Dimension)
{
	Tope = -1;
	Limite = Dimension;
	V[Limite] = 0;
}

int Pilas::GetTope()
{
	return Tope;
}

int Pilas::GetLimite()
{
	return Limite;
}

//LISTA VACIA
bool Pilas::PilaVacia()
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
bool Pilas::PilaLLena()
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

// APILAR
void Pilas::Apilar(int D)
{
	//VALIDAR SI ESTA LLENA
	if (!PilaLLena())
	{
		Tope++;
		V[Tope] = D;
	}
	else
	{
		cout << "PILA LLENA";
	}
}

//DESAPILAR	
int Pilas::Desapilar()
{

	//VALIDAR SI ESTA VACIA
	int Aux = 0;
	// VALIDAR SI LA LISTA ESTA LLENA
	bool Vacia = PilaVacia();
	if (Vacia == false)
	{
		Aux = V[Tope]; //APILAR EL NUEVO 
		Tope--; //AUMENTAR EL TOPE PARA INSERTAR
	}

	// RETONARNAR EL DATO DESAPILADO
	return Aux;
}

void Pilas::MostrarV()
{
	Pilas* Aux = new Pilas(Limite);

	if (Tope == -1)
	{
		cout << "NO HAY PILA EXISTENTE";
	}
	else
	{
		int a = Tope,x;

		//DESAPILO
		while (Tope != -1)
		{
			x = Desapilar();
			cout << x;
			cout << "\n";
			Aux->Apilar(x);
		}

		while (Tope != a)
		{
			x = Aux->Desapilar();
			Apilar(x);
		}
		
	}
	
}
