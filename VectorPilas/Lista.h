#pragma once
class Nodo
{
private:
	int dato;
	Nodo* Liga;

public:
	Nodo();
	Nodo(int D, Nodo* NLiga);
	int GetDato();
	void SetDato(int D);

	Nodo* GetLiga();
	void SetLiga(Nodo* L);

};

class Lista
{
private:
	int Limite;
	int Tope;
	
	Nodo* Punta;


public:
	Lista(int Dimension);
	bool PilaVacia();
	bool PilaLLena();
	int Desapilar();
	void ApilarLista(int D);
	void MostrarL();

};

