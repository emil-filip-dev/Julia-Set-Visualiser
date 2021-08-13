#pragma once

#include "JuliaSetRenderer.h"

namespace JuliaSetVisualiser {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
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
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
	private: System::Windows::Forms::Panel^ canvas;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->canvas = (gcnew System::Windows::Forms::Panel());
			this->SuspendLayout();
			// 
			// canvas
			// 
			this->canvas->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->canvas->Location = System::Drawing::Point(12, 12);
			this->canvas->Name = L"canvas";
			this->canvas->Size = System::Drawing::Size(960, 937);
			this->canvas->TabIndex = 0;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(984, 961);
			this->Controls->Add(this->canvas);
			this->Name = L"MainForm";
			this->Text = L"Julia Set Visualiser";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::canvas_Paint);
			this->ResumeLayout(false);

		}
#pragma endregion

		JuliaSet* juliaSet_;
		JuliaSetRenderer^ renderer_;

		System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
			juliaSet_ = new JuliaSet(complex<double>(0.7885, 0) * exp(complex<double>(0, M_PI * 2.0 * 171.0 / 360.0)), 2.0);
			renderer_ = gcnew JuliaSetRenderer(canvas->CreateGraphics());
		}

		System::Void canvas_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
			renderer_->render(juliaSet_);
		}

	};
}
