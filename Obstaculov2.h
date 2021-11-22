// CLASE HIJA //
#pragma once
#include "Entidad.h"



class Obstaculov2 :public Entidad
{

public:

	Obstaculov2(Bitmap^ img)
	{
		x = rand() % 250;
		y = rand() % 200;
		//ancho = alto = rand() % 25 + 25;
		dx = dy = 10;
		ancho = img->Width;
		alto = img->Height;

	}
	void Mover(Graphics^ g)
	{


		//if (x <= 0 || x + ancho >= g->VisibleClipBounds.Width) dx *= -1;
		if (y <= 0 || y + alto >= g->VisibleClipBounds.Height) dy *= -1;
		//x += dx;
		y += dy;



	}

	void Dibujar(Graphics^ g, Bitmap^ img)
	{
		Rectangle corte = Rectangle(IDx * ancho, alto, ancho, alto);
		g->DrawImage(img, NextArea());
		g->DrawRectangle(Pens::BlueViolet, NextArea()); /// ----> HITBOX

	}

};

class Obstaculosv2
{
private:

	vector<Obstaculov2*> obstaculosv2;
public:

	Obstaculosv2(int n, Rectangle obj, Bitmap^ img)
	{
		for (int i = 0; i < n; i++)
		{
			Obstaculov2* obs = new Obstaculov2(img);
			if (obs->Area().IntersectsWith(obj) == false && Colision(obs->Area()) == false)
				obstaculosv2.push_back(obs);
			else
			{
				delete obs;
				i--;
			}

		}
	}
	~Obstaculosv2()
	{
		for (int i = 0; i < obstaculosv2.size(); i++)  // -----> For Normal
		{
			delete obstaculosv2.at(i);
		}

	}

	int Eliminar(Rectangle rect)
	{
		int cant_eliminados = 0;
		for (int i = 0; i < obstaculosv2.size(); i++)
		{
			if (obstaculosv2[i]->Area().IntersectsWith(rect))
			{
				obstaculosv2.erase(obstaculosv2.begin() + i--);
				cant_eliminados++;

			}
		}
		return cant_eliminados;
	}
	bool Colision(Rectangle obj)
	{
		for each (Obstaculov2 * obs in obstaculosv2)
		{
			if (obs->NextArea().IntersectsWith(obj))
				return true;
		}
		return false;
	}
	void Mover(Graphics^ g)
	{


		for each (Obstaculov2 * obs in obstaculosv2)  // -----> For Normal del CLI
		{
			obs->Mover(g);
		}


	}
	void Dibujar(Graphics^ g, Bitmap^ img)
	{
		for (Obstaculov2* obs : obstaculosv2)  // -----> For Standar de C++ v14
		{
			obs->Dibujar(g, img);
		}
	}

};
