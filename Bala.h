#pragma once

#include "Entidad.h"

class Bala : public Entidad
{
public:

	Bala(int x, int y, int dx, int dy)
	{
		this->x = x;
		this->y = y;

		this->dx = dx;
		this->dy = dy;

		ancho = alto = 7;
		if (dx != 0)
			ancho = 40;
		if (dy != 0)
			alto = 40;
	
	}

};

class Balas
{
	vector <Bala*> balas;

public:
	~Balas()
	{
		for (int i = 0; i < balas.size(); i++)  // -----> For Normal
		{
			delete balas.at(i);
		}

	}
	void Agregar_Balas(Bala* bala)
	{
		balas.push_back(bala);
	}
	void Eliminar(int pos)
	{
		balas.erase(balas.begin() + pos);
	}

	int Size()
	{
		return balas.size();
	}
	Bala* Get(int pos)
	{
		return balas[pos];
	}

	
	bool Colision(Rectangle obj)
	{
		for each (Bala * b in balas)
		{
			if (b->NextArea().IntersectsWith(obj))
				return true;
		}
		return false;
	}
	void Mover(Graphics^ g)
	{

		for each (Bala * b in balas)  // -----> For Normal del CLI
		{
			b->Mover(g);
		}

		Rectangle pantalla = Rectangle(0, 0, g->VisibleClipBounds.Width, g->VisibleClipBounds.Height);
		for (int i = 0; i < Size(); i++)
		{
			if (balas[i]->Area().IntersectsWith(pantalla) == false)
			{
				Eliminar(i--);
			}
		}


	}
	void Dibujar(Graphics^ g)
	{
		for each (Bala* b in balas)  // -----> For Standar de C++ v14
		{
			b->Dibujar(g, nullptr);
		}
	}


};