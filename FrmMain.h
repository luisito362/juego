#pragma once
#include "Controladora.h"

namespace Caballero {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de FrmMain
	/// </summary>
	public ref class FrmMain : public System::Windows::Forms::Form
	{
	private:

		Bitmap^ imgEscenario_1 = gcnew Bitmap("img/escenario_1.jpg");

		Controladora^ controladora;

	public:
		FrmMain(int ene, int v, int t)
		{
			InitializeComponent();
			controladora = gcnew Controladora(ene, v, t);// (Enemigos, vidas, tiempo)
			
			
		}

	protected:
	
		~FrmMain()
		{
			if (components)
			{
				delete components;
				delete controladora;
				delete imgEscenario_1;
			}
		}
	private: System::Windows::Forms::Timer^ clock;
	protected:

	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->clock = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// clock
			// 
			this->clock->Enabled = true;
			this->clock->Interval = 30;
			this->clock->Tick += gcnew System::EventHandler(this, &FrmMain::clock_Tick);
			// 
			// FrmMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(659, 423);
			this->Name = L"FrmMain";
			this->Text = L"FrmMain";
			this->Load += gcnew System::EventHandler(this, &FrmMain::FrmMain_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmMain::FrmMain_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmMain::FrmMain_KeyUp);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &FrmMain::FrmMain_MouseDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void clock_Tick(System::Object^ sender, System::EventArgs^ e) {

		Graphics^ g = this->CreateGraphics();
		BufferedGraphicsContext^ bfc = BufferedGraphicsManager::Current;
		BufferedGraphics^ bf = bfc->Allocate(g, this->ClientRectangle);


		bf->Graphics->Clear(Color::White);

		bf->Graphics->DrawImage(imgEscenario_1, 0.0, 0.0, g->VisibleClipBounds.Width, g->VisibleClipBounds.Height);

		controladora->Dibujar(bf->Graphics);

		bf->Render(g);

		delete bf;
		delete bfc;




		if (controladora->Mover(g) == false)
		{

			this->clock->Enabled = false;

			if(controladora->GetResultado() == true)
				MessageBox::Show("GANASTES");
			else
				MessageBox::Show("PERDISTES");
			
			this->Close();
		}


	}
	private: System::Void FrmMain_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {

		controladora->Movimiento_Jugador(true, e->KeyCode);

	}
	private: System::Void FrmMain_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {

		controladora->Movimiento_Jugador(false, e->KeyCode);
	}
	private: System::Void FrmMain_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {

		controladora->Disparar_Jugador(e->Button);
	}
	private: System::Void FrmMain_Load(System::Object^ sender, System::EventArgs^ e) {
	
	}
private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {


	
}
};
}
