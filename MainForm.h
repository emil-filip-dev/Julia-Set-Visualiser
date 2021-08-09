#pragma once

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

		Graphics^ graphics;

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
			this->canvas->Location = System::Drawing::Point(37, 41);
			this->canvas->Name = L"canvas";
			this->canvas->Size = System::Drawing::Size(659, 542);
			this->canvas->TabIndex = 0;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(725, 620);
			this->Controls->Add(this->canvas);
			this->Name = L"MainForm";
			this->Text = L"Julia Set Visualiser";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::canvas_Paint);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
		graphics = canvas->CreateGraphics();
	}

	private: System::Void canvas_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		Brush^ b = gcnew SolidBrush(Color::Red);
		graphics->FillRectangle(b, 0, 0, 100, 100);
	}

	};
}
