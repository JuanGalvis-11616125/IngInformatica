#pragma once
class Nodo
{
private: 
	int dato;
	Nodo* Liga;

public:
	Nodo();
	Nodo(int D, Nodo* L);
	int GetDato();
	void SetDato(int D);

	Nodo* GetLiga();
	void SetLiga(Nodo * L);

};

