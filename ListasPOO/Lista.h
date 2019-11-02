#pragma once
#include "Nodo.h" 
using namespace std;
class Lista
{
private:
	Nodo* Punta;

public:
	Lista();
	void InsertarInicio(int D);
	void MostrarLista();
	void InsertarFinal(int D);
	void Buscar(int D);
	void Reemplazar(int D);
	void Eliminar(int D);
	void Ordenar();
	void InsertarOrdenado(int D, int ORD);
	void SumarListas(Lista* l1, Lista* l2);
	void UnirListas(Lista* l1, Lista* l2);
};

