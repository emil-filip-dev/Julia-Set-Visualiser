#pragma once

#include "VisualiserController.h"

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
		MainForm(VisualiserController* controller) {
			InitializeComponent();
			
			controller_ = controller;
		}

		MainForm(void) {
			InitializeComponent();
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
			this->canvas->Dock = System::Windows::Forms::DockStyle::Fill;
			this->canvas->Location = System::Drawing::Point(0, 0);
			this->canvas->Name = L"canvas";
			this->canvas->Size = System::Drawing::Size(684, 661);
			this->canvas->TabIndex = 0;
			this->canvas->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::canvas_Paint);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(684, 661);
			this->Controls->Add(this->canvas);
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Julia Set Visualiser";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->ResizeEnd += gcnew System::EventHandler(this, &MainForm::MainForm_ResizeEnd);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::canvas_Paint);
			this->ResumeLayout(false);

		}
#pragma endregion

		VisualiserController* controller_;

		Graphics^ juliaGraphics_;
		Bitmap^ juliaImage_;

		JuliaSet* juliaSet_;

		void updateJuliaImage() {
			if (!juliaGraphics_) {
				juliaGraphics_ = canvas->CreateGraphics();
			}
			juliaImage_ = gcnew Bitmap(juliaGraphics_->VisibleClipBounds.Width,
				                       juliaGraphics_->VisibleClipBounds.Height);
			controller_->render(juliaImage_, true);
		}

		void paintJuliaSet() {
			juliaGraphics_->DrawImageUnscaled(juliaImage_, 0, 0);
		}

		System::Void canvas_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
			if (!juliaImage_) {
				updateJuliaImage();
			}
			paintJuliaSet();
		}

		System::Void MainForm_ResizeEnd(System::Object^ sender, System::EventArgs^ e) {
			updateJuliaImage();
			paintJuliaSet();
		}
	};
}
