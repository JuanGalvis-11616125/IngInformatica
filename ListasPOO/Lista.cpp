#include "Lista.h"
#include <iostream>
using namespace std;

Lista::Lista()
{
	Punta = nullptr;
}

void ValidarLista()
{
	cout << "NO HAY LISTA EXISTENTE";
}

// INSERTAR AL INICIO
void Lista::InsertarInicio(int D)
{
	Nodo  *x = new Nodo();
	x->SetDato(D);
	x->SetLiga(nullptr);

	if(Punta == nullptr)
	{
		Punta = x;
	}else
		{
			x->SetLiga(Punta);
			Punta = x;
		}
}

// MOSTRAR
void Lista::MostrarLista()
{
	if (Punta == nullptr)
	{
		ValidarLista();
	}
	else
	{
		Nodo* p = Punta;

		while (p != nullptr)
		{
			cout << "\t |" << p->GetDato() << "|";
			cout << "\t =>";
			// AVANZAR, MOVIENDOSE POR LAS LIGAS
			p = p->GetLiga();
		}
	}
	cin.get();
}

// INSERTAR AL FINAL
void Lista::InsertarFinal(int D)
{
	if (Punta == nullptr)
	{
		InsertarInicio(D);
	}
	else
	{
		Nodo* f = Punta;
		Nodo* Final = nullptr;

		if (f == nullptr)
		{
			cout << "NO HAY LISTA EXISTENTE";

		}
		else
		{
			Nodo* x = new Nodo();

			while (Final != f) {
				if (f->GetLiga() == nullptr)
				{
					Final = f;

				}
				else
				{
					f = f->GetLiga();
				}

			}

			Final->SetLiga(x);
			x->SetLiga(nullptr);
			x->SetDato(D);
		}
	}

	cin.get();
}

// BUSCAR
void Lista::Buscar(int D)
{
	if (Punta == nullptr)
	{
		ValidarLista();
	}
	else
	{
		int C = 0;
		Nodo* n = Punta;
		while (n != nullptr)
		{
			if (n->GetDato() == D)
			{
				C++;
			}

			n = n->GetLiga();
		}

		if (C > 1)
		{
			cout << "Encontramos ese valor " << C << " veces";
		
		}
		else if (C == 1)
				{
					cout << "Encontramos ese valor " << C << " vez";
				}
	}

	cin.get();
}

// REEMPLAZAR
void Lista::Reemplazar(int D)
{
	if (Punta == nullptr)
	{
		ValidarLista();
	}
	
	Nodo* r = Punta;
	while (r != nullptr)
	{
		if (r->GetDato() == D)
		{
			int ND;
			cout << "NUEVO VALOR: "; cin >> ND;
			r->SetDato(ND);
		}

		r = r->GetLiga();
	}

	MostrarLista();

	cin.get();
}

// ELIMINAR
void Lista::Eliminar(int D)
{

	if (Punta == nullptr)
	{
		ValidarLista();
	}
	else
	{
		Nodo* p1 = Punta;
		Nodo* q = p1;
		p1 = p1->GetLiga();

		if (Punta->GetDato() == D)
		{
			Punta = Punta->GetLiga();
		}
		else
		{
			while (q->GetLiga() != nullptr)
			{
				if (p1->GetDato() == D)
				{
					q->SetLiga(p1->GetLiga());
					delete p1;
					p1 = q->GetLiga();
				}
				else
				{
					q = p1;
					p1 = p1->GetLiga();
				}
			}
		}

	}

	cin.get();
}

// ORDENAR
void Lista::Ordenar()
{
	if (Punta == nullptr)
	{
		ValidarLista();
	}
	else
	{
		Nodo* M = Punta;
		Nodo* Verf = Punta;

		Verf = Verf->GetLiga();

		int Aux;
		int opcO;

		cout << "1-ASCENDENTE O 2-DESCENDENTE: "; cin >> opcO;

		while (M != nullptr)
		{

			while (Verf != nullptr)
			{

				if (opcO == 1)
				{
					// ASCENDETE
					if (M->GetDato() < Verf->GetDato())
					{
						Aux = M->GetDato();
						M->SetDato(Verf->GetDato());
						Verf->SetDato(Aux);
					}

				}
				else if (opcO == 2)
				{
					// DESCENDIENTE
					if (M->GetDato() > Verf->GetDato())
					{
						Aux = M->GetDato();
						M->SetDato(Verf->GetDato());
						Verf->SetDato(Aux);
					}
				}

				Verf = Verf->GetLiga();
			}

			Verf = Punta;
			M = M->GetLiga();

		}

		MostrarLista();
	}
	cin.get();
}

void Lista::InsertarOrdenado(int D, int opcO)
{	
	if (Punta == nullptr)
	{
		InsertarInicio(D);
	}
	else
	{
		int Validac = 1;
		Nodo* x = Punta;
		Nodo* p = x;
		p = x->GetLiga();

		int Min = 0, May = 0;
		int Calculo = 0;
		
		// ASCENDENTE =========================================

		if (opcO == 1)
		{
			if (x->GetLiga() == nullptr)
			{
				if (x->GetDato() > D)
				{
					InsertarInicio(D);

				}
				else if (x->GetDato() < D)
				{
					InsertarFinal(D);
				}
			}
			else
			{
			x = Punta;
			p = x;
			p = x->GetLiga();
			
			while (p != nullptr && Validac == 1)
			{
				if (x->GetDato() > D)
				{
					May = x->GetDato();
					Validac = 0;

				}else if (x->GetDato() < D && p->GetDato() > D)
				{
					May = p->GetDato(); 
					Validac = 0;
				}

				x = p;
				p = x->GetLiga();

				if (x->GetDato() < D && p == nullptr)
				{
					InsertarFinal(D);
					Validac = 0;
				}
			}

			x = Punta;
			p = x;
			p = x->GetLiga();

			Validac = 1;

			while(p != nullptr && Validac == 1)
			{
				if (x->GetDato() == May)
				{
					InsertarInicio(D);
					Validac = 0;

				}else if (p->GetDato() == May)
				{
					Nodo* NOR = new Nodo();
					NOR->SetDato(D);
					NOR->SetLiga(x->GetLiga());

					x->SetLiga(NOR);
					Validac = 0;
				}
			
				x = p;
				p = x->GetLiga();
			}
			}
		}
		else if(opcO == 2)
		{
			// DESCENDENTE =========================================

			x = Punta;
			p = x;
			p = x->GetLiga();

			if (x->GetLiga() == nullptr)
			{
				if (x->GetDato() > D)
				{
					InsertarFinal(D);

				}
				else if (x->GetDato() < D)
				{
					InsertarInicio(D);
				}
			}
			else
			{ 

			while (p != nullptr && Validac == 1)
			{
				if (D < x->GetDato())
				{
					Min = x->GetDato();
					Calculo = x->GetDato() - D;
					Validac = 0;
				}

				x = p;
				p = p->GetLiga();

				if (D < x->GetDato() && p == nullptr && Validac == 1)
				{
					Min = x->GetDato();
					Calculo = x->GetDato() - D;
					Validac = 0;
				}
			}
		
			x = Punta;
			p = x;
			p = x->GetLiga();
			Validac = 1;

			int Compara = D - x->GetDato();

			if (Compara < 0)
			{
				Compara = 9999999999;
			}
			
			
				if (Compara < Calculo)
				{
					InsertarInicio(D);
				}
				else
				{
					while (p != nullptr && Validac == 1)
					{
						if (x->GetDato() == Min)
						{
							Nodo* NOR = new Nodo();
							NOR->SetDato(D);
							NOR->SetLiga(x->GetLiga());
							x->SetLiga(NOR);

							Validac = 0;

						}
						else if (p->GetDato() == Min)
						{
							Nodo* NOR = new Nodo();
							NOR->SetDato(D);
							NOR->SetLiga(p->GetLiga());
							p->SetLiga(NOR);

							Validac = 0;
						}

						x = p;
						p = p->GetLiga();
					}
				}
			}
	}
	}
}

// SUMAR LISTAS
void Lista::SumarListas(Lista* l1, Lista* l2)
{
	Nodo* x1 = l1->Punta;
	Nodo* x2 = l2->Punta;

	int InFin = 0;
	int Validacion = 1;
	int Dato1 = x1->GetDato();
	int Dato2 = x2->GetDato();

	while (Validacion != 0)
	{
		int Suma = 0;

		// VALIDAR NULL
		if (x1 == NULL && x2 == NULL)
		{
			Validacion = 0;
		
		}
		else if (x1 == NULL)
			{
				Dato1 = 0;
				Dato2 = x2->GetDato();
			
			}
			else if (x2 == NULL)
				{
					Dato2 = 0;
					Dato1 = x1->GetDato();
				}
					else
					{
						Dato1 = x1->GetDato();
						Dato2 = x2->GetDato();
					}

		if (Validacion == 1)
		{
			// SUMA

			Suma = Dato1 + Dato2;
			InsertarFinal(Suma);
	
			// MOVERSE VERIFICANDO
			if (x1 == nullptr && x2 == nullptr)
			{
				Validacion = 0;

			}
			else if (x1 == nullptr)
			{
				x2 = x2->GetLiga();

			}
			else if (x2 == nullptr)
			{
				x1 = x1->GetLiga();

			}
			else
			{
				x1 = x1->GetLiga();
				x2 = x2->GetLiga();
			}
		}
		else
		{
			Validacion = 0;
		}

		}
}

// UNIR LISTAS
void Lista::UnirListas(Lista* l1, Lista* l2)
{
	Nodo* x1 = l1->Punta;
	Nodo* x2 = l2->Punta;
	int opcO;

	cout << "1-ASCENDENTE O 2-DESCENDENTE: "; cin >> opcO;

	while (x1 != NULL)
	{
		InsertarOrdenado(x1->GetDato(), opcO);
		x1 = x1->GetLiga();
	}

	while (x2 != NULL)
	{
		InsertarOrdenado(x2->GetDato(), opcO);
		x2 = x2->GetLiga();
	}
}