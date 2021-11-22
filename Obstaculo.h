// CLASE HIJA //
#pragma once
#include "Entidad.h"



class Obstaculo :public Entidad
{
	
public:

	Obstaculo(Bitmap^ img)
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


		if (x <= 0 || x + ancho >= g->VisibleClipBounds.Width) dx *= -1;
		if (y <= 0 || y + alto >= g->VisibleClipBounds.Height) dy *= -1;
		x += dx;
		y += dy;
	
	
	
	}

	void Dibujar(Graphics^ g, Bitmap^ img)
	{
		Rectangle corte = Rectangle(IDx * ancho, alto, ancho, alto);
		g->DrawImage(img, NextArea());
		g->DrawRectangle(Pens::YellowGreen, NextArea()); /// ----> HITBOX
		
	}

};

class Obstaculos
{
private:

	vector<Obstaculo*> obstaculos;
public:

	Obstaculos(int n,Rectangle obj, Bitmap^ img)
	{
		for (int i = 0; i < n; i++)
		{
			Obstaculo* obs = new Obstaculo(img);
			if (obs->Area().IntersectsWith(obj) == false && Colision(obs->Area()) == false)
				obstaculos.push_back(obs);
			else
			{
				delete obs;
				i--;
			}
			
		}
	}
	~Obstaculos() 
	{
		for (int i = 0; i < obstaculos.size(); i++)  // -----> For Normal
		{  
			delete obstaculos.at(i);
		}

	}

	int Eliminar(Rectangle rect)
	{
		int cant_eliminados = 0;
		for (int i = 0; i < obstaculos.size(); i++)
		{
			if (obstaculos[i]->Area().IntersectsWith(rect))
			{
				obstaculos.erase(obstaculos.begin() + i--);
				cant_eliminados++;

			}
		}
		return cant_eliminados;
	}
	bool Colision(Rectangle obj)
	{
		for each (Obstaculo * obs in obstaculos)
		{
			if (obs->NextArea().IntersectsWith(obj))
				return true;
		}
		return false;
	}
	void Mover(Graphics^ g)
	{

		
		for each (Obstaculo * obs in obstaculos)  // -----> For Normal del CLI
		{
			obs->Mover(g);
		}


	}
	void Dibujar(Graphics^ g, Bitmap^ img)
	{
		for (Obstaculo* obs : obstaculos)  // -----> For Standar de C++ v14
		{
			obs->Dibujar(g, img);
		}
	}

};