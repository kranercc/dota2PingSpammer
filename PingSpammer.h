#pragma once
#include <iostream>
#include <msclr/marshal.h>
#include <fstream>

namespace pingSpammer {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for PingSpammer
	/// </summary>
	public ref class PingSpammer : public System::Windows::Forms::Form
	{
	public:
		PingSpammer(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~PingSpammer()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  activateButton;
	private: System::Windows::Forms::TextBox^  bindButton;
	private: System::Windows::Forms::TextBox^  pingsPerSecound;
	private: System::Windows::Forms::TextBox^  typeOfPing;

	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(PingSpammer::typeid));
			this->activateButton = (gcnew System::Windows::Forms::Button());
			this->bindButton = (gcnew System::Windows::Forms::TextBox());
			this->pingsPerSecound = (gcnew System::Windows::Forms::TextBox());
			this->typeOfPing = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// activateButton
			// 
			this->activateButton->Location = System::Drawing::Point(74, 168);
			this->activateButton->Name = L"activateButton";
			this->activateButton->Size = System::Drawing::Size(144, 23);
			this->activateButton->TabIndex = 0;
			this->activateButton->Text = L"Create Config";
			this->activateButton->UseVisualStyleBackColor = true;
			this->activateButton->Click += gcnew System::EventHandler(this, &PingSpammer::activateButton_Click);
			// 
			// bindButton
			// 
			this->bindButton->Location = System::Drawing::Point(24, 28);
			this->bindButton->Name = L"bindButton";
			this->bindButton->Size = System::Drawing::Size(100, 20);
			this->bindButton->TabIndex = 1;
			this->bindButton->Text = L"Bind button";
			this->bindButton->TextChanged += gcnew System::EventHandler(this, &PingSpammer::bindButton_TextChanged);
			// 
			// pingsPerSecound
			// 
			this->pingsPerSecound->Location = System::Drawing::Point(161, 28);
			this->pingsPerSecound->Name = L"pingsPerSecound";
			this->pingsPerSecound->Size = System::Drawing::Size(100, 20);
			this->pingsPerSecound->TabIndex = 2;
			this->pingsPerSecound->Text = L"pings per secound";
			this->pingsPerSecound->TextChanged += gcnew System::EventHandler(this, &PingSpammer::textBox2_TextChanged);
			// 
			// typeOfPing
			// 
			this->typeOfPing->Location = System::Drawing::Point(88, 75);
			this->typeOfPing->Name = L"typeOfPing";
			this->typeOfPing->Size = System::Drawing::Size(100, 20);
			this->typeOfPing->TabIndex = 3;
			this->typeOfPing->Text = L"x or !";
			this->typeOfPing->TextChanged += gcnew System::EventHandler(this, &PingSpammer::typeOfPing_TextChanged);
			// 
			// PingSpammer
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->typeOfPing);
			this->Controls->Add(this->pingsPerSecound);
			this->Controls->Add(this->bindButton);
			this->Controls->Add(this->activateButton);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"PingSpammer";
			this->Text = L"PingSpammer @krane";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void activateButton_Click(System::Object^  sender, System::EventArgs^  e) {
		String ^ buttonBinded = bindButton ->Text;
		String ^ pingtime = pingsPerSecound ->Text;
		String ^ typeofP = typeOfPing->Text;

		//change it to char
		msclr::interop::marshal_context ctx;
		const char* convertedButton = ctx.marshal_as<const char*>(buttonBinded);
		const char* convertedPingtime = ctx.marshal_as<const char*>(pingtime);
		const char* convertedTypeOfP = ctx.marshal_as<const char*>(typeofP);

		
		MessageBox::Show("Created: Button = " + buttonBinded + "\t" + "Pings Per Secound = " + pingtime + "\tType = " + typeofP, "Status");

		using namespace std;

		ofstream logs;
		logs.open("config.txt");

		logs << convertedButton;
		logs << "\t" << convertedPingtime;
		logs << "\t" << convertedTypeOfP;
		logs.close();


	}
	private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void bindButton_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void typeOfPing_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
};
}
