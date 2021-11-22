#pragma once
#include "Jugador.h"
#include "Obstaculo.h"
#include "Enemigo.h"
#include "bala.h"


ref class Controladora
{
private:

	Jugador* jugador;
	Obstaculos* obstaculos;
	Enemigos* enemigos;
	Balas* balas;
	
	Bitmap^ imgTroll;
	Bitmap^ imgJugador;
	Bitmap^ imgEnemigo;
	

	int cd_ataque_enemigo;
	int cd_ataque_obstaculo;
	int tiempo;

	bool resultado;
	int objetivo;

public:
	Controladora(int ene,int v,int t) {

		imgTroll = gcnew Bitmap("imgs/piza.png");
		imgJugador = gcnew Bitmap("img/jugador_v2.png");
		imgEnemigo = gcnew Bitmap("imgs/hamburguesas.png");
		
 
		jugador = new Jugador(imgJugador,v);
		obstaculos = new Obstaculos(5, jugador->Area(), imgTroll);
		enemigos = new Enemigos(imgEnemigo, ene);
		balas = new Balas();
		
		cd_ataque_obstaculo = 0;
		cd_ataque_enemigo = 0;
		objetivo = 5 + ene;
		tiempo = t * 1000 + clock();


	}
	~Controladora() {

		delete jugador;
		delete obstaculos;
		delete imgTroll;
		delete enemigos;
		delete balas;
	}

	bool GetResultado()
	{
		return resultado;

	}

	void Movimiento_Jugador(bool accion, Keys tecla)
	{
		int v = 3;

		if (accion == true)
		{
			if (tecla == Keys::Up)
			{
				jugador->SetDY(-v);
				jugador->SetAccion(CaminarArriba);
			}
				
			else if (tecla == Keys::Down)
			{
				jugador->SetDY(v);
				jugador->SetAccion(CaminarAbajo);
			}
				
			else if (tecla == Keys::Left)
			{
				jugador->SetDX(-v);
				jugador->SetAccion(CaminarIzquierda);
			}
				
			else if (tecla == Keys::Right)
			{
				jugador->SetDX(v);
				jugador->SetAccion(CaminarDerecha);
			}
				
			else if (tecla == Keys::Space)
			{
				if (jugador->GetAccion() == CaminarArriba)
					jugador->SetAccion(AtacarArrriba);
				else if (jugador->GetAccion() == CaminarAbajo)
					jugador->SetAccion(AtacarAbajo);
				else if (jugador->GetAccion() == CaminarDerecha)
					jugador->SetAccion(AtacarDerecha);
				else if (jugador->GetAccion() == CaminarIzquierda)
					jugador->SetAccion(AtacarIzquierda);
			}


		}
		else
		{

			if (tecla == Keys::Up)
				jugador->SetDY(0);
			else if (tecla == Keys::Down)
				jugador->SetDY(0);
			else if (tecla == Keys::Left)
				jugador->SetDX(0);
			else if (tecla == Keys::Right)
				jugador->SetDX(0);




		}

	}
	void Disparar_Jugador(MouseButtons boton)
	{
		if (boton == MouseButtons::Left)
		{
			if (jugador->GetAccion() == CaminarArriba)
				jugador->SetAccion(DispararArrriba);
			else if (jugador->GetAccion() == CaminarAbajo)
				jugador->SetAccion(DispararAbajo);
			else if (jugador->GetAccion() == CaminarDerecha)
				jugador->SetAccion(DispararDerecha);
			else if (jugador->GetAccion() == CaminarIzquierda)
				jugador->SetAccion(DispararIzquierda);

		}
	}

	bool Mover(Graphics^ g)
	{
		if (jugador->GetAccion() >= AtacarArrriba && jugador->GetAccion() <= AtacarDerecha && jugador->GetIDx() == 7)
		{
			jugador->SetPuntos(obstaculos->Eliminar(jugador->Area()));
		}
		if (jugador->GetAccion() >= DispararArrriba && jugador->GetAccion() <= DispararDerecha && jugador->GetIDx() == 12)
		{
			int v = 10;
			if (jugador->GetAccion() == DispararArrriba)
				balas->Agregar_Balas(new Bala(jugador->GetX() + jugador->GetAncho() / 2, jugador->GetY() + jugador->GetAlto() / 2, 0, -v));
			if (jugador->GetAccion() == DispararAbajo)
				balas->Agregar_Balas(new Bala(jugador->GetX() + jugador->GetAncho() / 2, jugador->GetY() + jugador->GetAlto() / 2, 0, v));
			if (jugador->GetAccion() == DispararDerecha)
				balas->Agregar_Balas(new Bala(jugador->GetX() + jugador->GetAncho() / 2, jugador->GetY() + jugador->GetAlto() / 2, v, 0));
			if (jugador->GetAccion() == DispararIzquierda)
				balas->Agregar_Balas(new Bala(jugador->GetX() + jugador->GetAncho() / 2, jugador->GetY() + jugador->GetAlto() / 2, -v, 0));
		}

		for (int i = 0; i < balas->Size(); i++)
		{
			Bala* B = balas->Get(i);
			// jugador->SetPuntos(enemigos->Eliminar(B->Area()));
			enemigos->Matar(B->Area());
		}
		for (int i = 0; i < enemigos->Size(); i++)
		{
			Enemigo* E = enemigos->Get(i);
			if (E->GetAcccion() == enemigoMorir && E->GetIDx() == 5)
			{
				enemigos->Eliminar(i);
				jugador->SetPuntos(1);
			}
		}



		if (enemigos->Colision(jugador->NextHitBox()) && clock() - cd_ataque_enemigo >= 2000)
		{
			jugador->SetVidas(-1);
			cd_ataque_enemigo = clock();

			if (jugador->GetVidas() == 0)
			{
				jugador->SetAccion(Morir);
			}

		}
		if (obstaculos->Colision(jugador->NextHitBox()) && clock() - cd_ataque_obstaculo >= 2000)
		{
			jugador->SetVidas(-1);
			cd_ataque_obstaculo = clock();

			if (jugador->GetVidas() == 0)
			{
				jugador->SetAccion(Morir);
			}
		}

		/*
		if (obstaculos->Colision(jugador->NextHitBox()) == false && jugador->GetAccion() != Morir)
			jugador->Mover(g);
		*/




		if (jugador->GetAccion() == Morir && jugador->GetIDx() == 5)
		{
			resultado = false;
			return false;
		}

		if (clock() >= tiempo)
		{
			jugador->SetAccion(Morir);
		}

		if (objetivo == jugador->GetPuntos())
		{
			resultado = true;
			return false;


		}
	
	
		
		jugador->Mover(g);
		obstaculos->Mover(g);
		enemigos->Mover(g);
		balas->Mover(g);

		return true;
	}
	void Dibujar(Graphics^ g)
	{
		
		g->DrawString("TIEMPÓ : " + ((tiempo - clock()) / 1000), gcnew Font("Arial", 12), Brushes::Black, 540, 35);

		
		obstaculos->Dibujar(g, imgTroll);
		enemigos->Dibujar(g, imgEnemigo);
		balas->Dibujar(g);
		jugador->Dibujar(g, imgJugador);
	
	
		
		

	}

};
