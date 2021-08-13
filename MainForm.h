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
			this->Text = L"Julia Set Visualiser";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &MainForm::MainForm_FormClosed);
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->ResizeEnd += gcnew System::EventHandler(this, &MainForm::MainForm_ResizeEnd);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::canvas_Paint);
			this->ResumeLayout(false);

		}
#pragma endregion

		Graphics^ juliaGraphics_;
		Bitmap^ juliaImage_;

		JuliaSet* juliaSet_;
		JuliaSetRenderer* renderer_;

		void updateJuliaImage() {
			juliaGraphics_ = canvas->CreateGraphics();
			juliaImage_ = gcnew Bitmap(juliaGraphics_->VisibleClipBounds.Width,
				juliaGraphics_->VisibleClipBounds.Height);
			renderer_->render(juliaImage_);
		}

		void paintJuliaSet() {
			juliaGraphics_->DrawImageUnscaled(juliaImage_, 0, 0);
		}

		System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
			juliaSet_ = new JuliaSet(complex<double>(0.7885, 0) * exp(complex<double>(0, M_PI * 2.0 * 171.0 / 360.0)), 2.0);
			renderer_ = new JuliaSetRenderer(juliaSet_);
		}

		System::Void canvas_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
			if (!juliaImage_) {
				updateJuliaImage();
			}
			paintJuliaSet();
		}

		System::Void MainForm_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
			delete renderer_;
			delete juliaSet_;
		}

		System::Void MainForm_ResizeEnd(System::Object^ sender, System::EventArgs^ e) {
			updateJuliaImage();
			paintJuliaSet();
		}
};
}
