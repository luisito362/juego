#pragma once
#include "FrmMain.h"
#include "FrmInstrucciones.h"
#include "FrmCreditos.h"


namespace Caballero {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	
	public ref class FrmMenu : public System::Windows::Forms::Form
	{
	public:
		FrmMenu(void)
		{
			InitializeComponent();
			
		}

	protected:

		~FrmMenu()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnIniciar;
	protected:

	protected:

	private: System::Windows::Forms::NumericUpDown^ nudv;



	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::NumericUpDown^ nudene;


	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::NumericUpDown^ nudt;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;



	private:
	
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
	
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FrmMenu::typeid));
			this->btnIniciar = (gcnew System::Windows::Forms::Button());
			this->nudv = (gcnew System::Windows::Forms::NumericUpDown());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->nudene = (gcnew System::Windows::Forms::NumericUpDown());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->nudt = (gcnew System::Windows::Forms::NumericUpDown());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudv))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudene))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudt))->BeginInit();
			this->SuspendLayout();
			// 
			// btnIniciar
			// 
			this->btnIniciar->Location = System::Drawing::Point(36, 100);
			this->btnIniciar->Name = L"btnIniciar";
			this->btnIniciar->Size = System::Drawing::Size(88, 37);
			this->btnIniciar->TabIndex = 0;
			this->btnIniciar->Text = L"Iniciar";
			this->btnIniciar->UseVisualStyleBackColor = true;
			this->btnIniciar->Click += gcnew System::EventHandler(this, &FrmMenu::btnIniciar_Click);
			// 
			// nudv
			// 
			this->nudv->Location = System::Drawing::Point(310, 220);
			this->nudv->Name = L"nudv";
			this->nudv->Size = System::Drawing::Size(58, 20);
			this->nudv->TabIndex = 2;
			this->nudv->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(319, 204);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(33, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Vidas";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(302, 98);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(78, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Hamburguesas";
			// 
			// nudene
			// 
			this->nudene->Location = System::Drawing::Point(309, 114);
			this->nudene->Name = L"nudene";
			this->nudene->Size = System::Drawing::Size(58, 20);
			this->nudene->TabIndex = 4;
			this->nudene->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->nudene->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(319, 144);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(42, 13);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Tiempo";
			// 
			// nudt
			// 
			this->nudt->Location = System::Drawing::Point(311, 160);
			this->nudt->Name = L"nudt";
			this->nudt->Size = System::Drawing::Size(58, 20);
			this->nudt->TabIndex = 6;
			this->nudt->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(36, 160);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(88, 37);
			this->button1->TabIndex = 8;
			this->button1->Text = L"Instrucciones";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &FrmMenu::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(36, 223);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(88, 37);
			this->button2->TabIndex = 9;
			this->button2->Text = L"Creditos";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &FrmMenu::button2_Click);
			// 
			// FrmMenu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(415, 317);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->nudt);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->nudene);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->nudv);
			this->Controls->Add(this->btnIniciar);
			this->ForeColor = System::Drawing::SystemColors::WindowText;
			this->Name = L"FrmMenu";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"FrmMenu";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudv))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudene))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudt))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnIniciar_Click(System::Object^ sender, System::EventArgs^ e)
	{

		FrmMain^ frm = gcnew FrmMain((int)nudene->Value, (int) nudv->Value, (int) nudt->Value);
	


		this->Visible = false;
		frm->ShowDialog();
		this->Visible = true;
	}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e){
	FrmInstrucciones^ frm = gcnew FrmInstrucciones();



	this->Visible = false;
	frm->ShowDialog();
	this->Visible = true;
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	FrmCreditos^ frm = gcnew FrmCreditos();

	this->Visible = false;
	frm->ShowDialog();
	this->Visible = true;
	
}
};
}
