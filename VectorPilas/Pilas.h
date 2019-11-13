#pragma once
class Pilas
{
private:

	int Tope;
	int Limite;
	int V[];

public:

	Pilas(int Dimension);
	bool PilaVacia();
	bool PilaLLena();
	void Apilar(int D);
	int Desapilar();

	int GetTope();
	int GetLimite();
	
	void InsertarOrdenado();
	void Ordenar();

	void Buscar();
	void Reemplazar();
	void Eliminar();

	void MostrarV();
};

