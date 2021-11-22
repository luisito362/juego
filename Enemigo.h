#pragma once
#include "Entidad.h"

enum SpriteEnemigo
{
	enemigoCaminarArriba,
	enemigoCaminarIzquierda,
	enemigoCaminarAbajo,
	enemigoCaminarDerecha,

	enemigoMorir

};

class Enemigo : public Entidad
{

	SpriteEnemigo accion;
	
public:
	Enemigo(Bitmap^ img)
	{
		x = rand() % 200;
		y = rand() % 200;

		if (rand() % 2 == 0)
		{
			//DX
			dx = rand() % 10 - 5;  /// -5 hasta 4 , si es 0 se cambia a 5 
			if (dx == 0)
			{
				dx = 5;
			}
		}
		else
		{
			//DY
			dy = rand() % 11 - 5;
			if (dy == 0)
			{
				dy = 5;
			}
		}
		
		ancho = img->Width / 9;
		alto = img->Height / 5; 


		accion = enemigoCaminarAbajo;
	
	
	}
	SpriteEnemigo GetAcccion()
	{
		return accion;
	}
	void SetAccion(SpriteEnemigo value)
	{
		accion = value;
	}
	void Mover(Graphics^ g)

	{

	
		//EBOTAR HORIZONTAL
		if (!(x + dx >= 0 && x + ancho + dx < g->VisibleClipBounds.Width))
		{
			dx *= -1;
		}

		// REBOTE VERTICAL
		if (!(y + dy >= 0 && y + alto + dy < g->VisibleClipBounds.Height))
		{
			dy *= -1;
		}
		
	

	

	

		

		
		if (dx < 0)
			accion = enemigoCaminarIzquierda;
		else if (dx > 0)
			accion = enemigoCaminarDerecha;
		else if (dy < 0)
			accion = enemigoCaminarArriba;
		else if (dy > 0)
			accion = enemigoCaminarAbajo;
		
		x += dx;
		y += dy;

	}
	void Dibujar(Graphics^ g, Bitmap^ img)
	{
		Rectangle corte = Rectangle(IDx * ancho, accion * alto, ancho, alto);
		g->DrawImage(img, Area(), corte, GraphicsUnit::Pixel);
		g->DrawRectangle(Pens::Blue, Area()); /// ----> HITBOX AZUL
		g->DrawRectangle(Pens::Red, HitBox()); /// ----> HITBOX ROJA

	
		

		if (accion >= enemigoCaminarArriba && accion <= enemigoCaminarDerecha)
		{
			IDx = (IDx + 1) % 9;

		}
		else if (accion == enemigoMorir)
		{
			IDx = (IDx + 1) % 7;
		}


	}

};

class Enemigos
{
	vector<Enemigo*> enemigos;

public:

	bool Colision(Rectangle obj)
	{
		for each (Enemigo * E in enemigos)
		{
			if (E->NextHitBox().IntersectsWith(obj))
				return true;
		}
		return false;
	}
	Enemigos(Bitmap^ img, int cant)
	{
		for (int i = 0; i < cant; i++)
		{
			enemigos.push_back(new Enemigo(img));
		}
	}
	~Enemigos()
	{
		for each (Enemigo * E in enemigos)
		{
			delete E;
		}
	}
	void Eliminar(int pos)
	{
		enemigos.erase(enemigos.begin() + pos);
	}

	int Size()
	{
		return enemigos.size();
	}
	Enemigo* Get(int pos)
	{
		return enemigos[pos];
	}


	void  /*Eliminar*/Matar(Rectangle rect)
	{
		// int cant_eliminados = 0;

		for (int i = 0; i < enemigos.size(); i++)
		{
			Enemigo* E = enemigos[i];
			if (/*enemigos*/E->HitBox().IntersectsWith(rect))
			{
				//enemigos.erase(enemigos.begin() + i--);
				//cant_eliminados++;
				E->SetDX(0);
				E->SetDY(0);
				E->SetAccion(enemigoMorir);

				
			}
		}
		
	}

	void Mover(Graphics^ g)
	{
		for each (Enemigo * E in enemigos)
		{
			E->Mover(g);
		}
	}
	void Dibujar(Graphics^ g,Bitmap^ img)
	{
		for each (Enemigo * E in enemigos)
		{
			E->Dibujar(g, img);
		}

	}


};


