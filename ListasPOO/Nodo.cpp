#include "Nodo.h"

Nodo::Nodo()
{
	dato = 0;
	Liga = nullptr;
}

Nodo::Nodo(int Dato, Nodo* Siguiente) {//VIENE DEL PRINCIPAL

	this->dato= Dato;//ESTE DATO ES EL DE LA CLASE, Y SE COMO SE LLAMA IGUAL AL QUE VIENE DEL PRINCIPAL SE LE PONE this->
	Liga = Siguiente;//este no se llama igual al del principal entonces solo se iguala

}

/* ======================= */

int Nodo::GetDato()
{
	return dato;
}

void Nodo::SetDato(int D)
{
	dato = D;
}

/* ================ */

Nodo* Nodo::GetLiga()
{
	return Liga;
}

void Nodo::SetLiga(Nodo * L)
{
	this->Liga = L;
}