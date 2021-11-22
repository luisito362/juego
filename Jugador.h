// CLASE HIJA //
#pragma once
#include "Entidad.h"

enum SpriteJugador
{
	DispararArrriba,
	DispararIzquierda,
	DispararAbajo,
	DispararDerecha,
	
	AtacarArrriba,
	AtacarIzquierda,
	AtacarAbajo,
	AtacarDerecha,

	CaminarArriba,
	CaminarIzquierda,
	CaminarAbajo,
	CaminarDerecha,

	Morir

};

class Jugador : public Entidad
{

private:
	int vidas;
	int puntos;
	SpriteJugador accion;


public:

	Jugador(Bitmap ^img,int v)

	{
		x = 300;
		y = 345;
		dx = dy = 0;
		ancho = img->Width / 13;
		alto = img->Height / 13;

		accion = CaminarDerecha;

		//int n = (int)accion; // int n = int 2

		vidas = v;
		puntos = 0;

	}

	void SetVidas(int value)
	{
		vidas += value;
	}
	int GetVidas()
	{
		return vidas;
	}

	void SetAccion(SpriteJugador value)
	{
		if (accion != value)
			IDx = 0;
		accion = value;
	}
	SpriteJugador GetAccion() {
		return accion;
	}
	int GetPuntos()
	{
		return puntos;
	}
	void SetPuntos(int value)
	{
		puntos += value;
	}

	void Mover(Graphics^ g)
	{
		if (x + dx >= 0 && x + ancho + dx < g->VisibleClipBounds.Width) // &&
			x += dx; 

	 if(y + dy >= 0 && y + alto + dy < g->VisibleClipBounds.Height)  // &&
		y += dy;

	}

	void Dibujar(Graphics^ g, Bitmap^ img)
	{
		g->DrawString("VIDAS : " + vidas, gcnew Font("Arial", 12), Brushes::Black, 540, 20);
		g->DrawString("PUNTOS : " + puntos, gcnew Font("Arial", 12), Brushes::Black, 540, 50 );


		Rectangle corte = Rectangle(IDx * ancho, accion * alto, ancho, alto);
		g->DrawImage(img, Area(), corte, GraphicsUnit::Pixel);
		g->DrawRectangle(Pens::Blue,Area()); /// ----> HITBOX // CAJA AZUL
		g->DrawRectangle(Pens::Red, HitBox()); /// ----> HITBOX // CAJA ROJA


	
		if (accion >= DispararArrriba && accion <= DispararDerecha)
		{

			IDx = (IDx + 1) % 13;

			if (IDx == 0)
			{
				accion = (SpriteJugador)(accion + 8);
			}
		}
		else if (accion >= AtacarArrriba && accion <= AtacarDerecha)
		{
			IDx = (IDx + 1) % 8;

			if (IDx == 0)
				accion = (SpriteJugador)(accion + 4);
			
		}
		
		else if (accion >= CaminarArriba && accion <= CaminarDerecha && (dx != 0 || dy != 0))
			IDx = (IDx + 1) % 9;
		else if (accion == Morir)
			IDx = (IDx + 1) % 6;


	}

};
