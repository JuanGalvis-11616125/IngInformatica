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
	int Aux = 0;
	bool Vacia = PilaVacia();
	if (Vacia == false)
	{
		Aux = V[Tope]; 
		Tope--;
	}

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
			cout << "|" << x << "|";
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

void Pilas::Buscar()
{
	if (!PilaVacia())
	{
		int Dato;
		cout << "DATO A BUSCAR: "; cin >> Dato;
		int C = 0;
		Pilas* Aux = new Pilas(Limite);

		while (Tope != -1)
		{
			int DatoD = Desapilar();
			if (DatoD == Dato)
			{
				C++;
			}

			Aux->Apilar(DatoD);
		}

		while (Aux->GetTope() != -1)
		{
			Apilar(Aux->Desapilar());
		}

		if (C == 0)
		{
			cout << "DATO NO ENCONTRADO";

		}
		else if (C == 1)
		{
			cout << "DATO ENCONTADO UNA VEZ";
		}
		else if (C > 1)
		{
			cout << "DATO ENCONTADO " << C << " VECES";
		}
	}
	else
	{
		cout << "PILA VACIA";
	}
	
}

void Pilas::Reemplazar()
{
	if (!PilaVacia())
	{
		int Dato,NDato;
		cout << "DATO A REEMPLAZAR: "; cin >> Dato;
		Pilas* Aux = new Pilas(Limite);

		while (Tope != -1)
		{
			int DatoD = Desapilar();
			if (DatoD == Dato)
			{
				cout << "NUEVO DATO: "; cin >> NDato;
				Aux->Apilar(NDato);
			}
			else
			{
				Aux->Apilar(DatoD);
			}

		}

		while (Aux->GetTope() != -1)
		{
			Apilar(Aux->Desapilar());
		}

		MostrarV();
	}
	else
	{
		cout << "PILA VACIA";
	}
}

void Pilas::Eliminar()
{
	if (!PilaVacia())
	{
		int Dato;
		cout << "DATO A ELIMINAR: "; cin >> Dato;
		Pilas* Aux = new Pilas(Limite);

		while (Tope != -1)
		{
			int DatoD = Desapilar();
			if (DatoD != Dato)
			{
				Aux->Apilar(DatoD);
			}
		}

		while (Aux->GetTope() != -1)
		{
			Apilar(Aux->Desapilar());
		}

		MostrarV();
	}
	else
	{
		cout << "PILA VACIA";
	}
}

void Pilas::InsertarOrdenado()
{
	int Dato;
	int DatoP1;
	int Validar = 1;
	cout << "DATO A INSERTAR: "; cin >> Dato;

	if (Tope == -1)
	{
		Apilar(Dato);
	}
	else
	{
		Pilas* Aux = new Pilas(Limite);

		do
		{
			DatoP1 = Desapilar();
			
			if (Dato < DatoP1)
			{
				Aux->Apilar(DatoP1);
				Apilar(Dato);
				Validar = 0;
			}
			else
			{
				Apilar(DatoP1);
				Apilar(Dato);
				Validar = 0;
			}
		} while (Validar == 1);
	
		while (Aux->GetTope() != -1)
		{
			Apilar(Aux->Desapilar());
		}

	}
}

void Pilas::Ordenar()
{
	if (PilaVacia())
	{
		cout << "LA PILA ESTA VACIA";
	}
	else {

		Pilas* Aux1 = new Pilas(Limite);
		Pilas* Aux2 = new Pilas(Limite);

		int DatoV, Menor;

		while (Tope != -1) //VACIAR PILA PRINCIPAL
		{
			Aux1->Apilar(Desapilar());
		}

		do {

		Menor = Aux1->Desapilar();

		while (Aux1->GetTope() != -1)
		{
			DatoV = Aux1->Desapilar();

			if (Menor > DatoV)
			{
				Aux2->Apilar(Menor);
				Menor = DatoV;
			}
			else
			{
				Aux2->Apilar(DatoV);
			}

		}

		Apilar(Menor);

		while (Aux2->GetTope() != -1)
		{
			Aux1->Apilar(Aux2->Desapilar());
		}

		} while (Aux1->GetTope() != -1);

		MostrarV();
	}
	
	

}