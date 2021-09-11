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
	private: System::Windows::Forms::GroupBox^ grpViewport;
	private: System::Windows::Forms::GroupBox^ grpSet;

	private: System::Windows::Forms::GroupBox^ grpRender;
	private: System::Windows::Forms::Label^ lblPreset;
	private: System::Windows::Forms::ComboBox^ cbPresets;
	private: System::Windows::Forms::Label^ lblVar1;




	private: System::Windows::Forms::Button^ btRenderToViewport;
	private: System::Windows::Forms::Button^ btRenderToImage;


	private: System::Windows::Forms::TextBox^ tbVarInput1;



	private: System::Windows::Forms::Label^ lblVar2;
	private: System::Windows::Forms::TextBox^ tbVarInput2;
	private: System::Windows::Forms::CheckBox^ cbAutoUpdate;


	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ btHelp;
	private: System::Windows::Forms::NumericUpDown^ nIterations;








	private: System::Windows::Forms::Panel^ canvas;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->canvas = (gcnew System::Windows::Forms::Panel());
			this->grpViewport = (gcnew System::Windows::Forms::GroupBox());
			this->grpSet = (gcnew System::Windows::Forms::GroupBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->tbVarInput2 = (gcnew System::Windows::Forms::TextBox());
			this->lblVar2 = (gcnew System::Windows::Forms::Label());
			this->tbVarInput1 = (gcnew System::Windows::Forms::TextBox());
			this->lblVar1 = (gcnew System::Windows::Forms::Label());
			this->lblPreset = (gcnew System::Windows::Forms::Label());
			this->cbPresets = (gcnew System::Windows::Forms::ComboBox());
			this->grpRender = (gcnew System::Windows::Forms::GroupBox());
			this->nIterations = (gcnew System::Windows::Forms::NumericUpDown());
			this->btHelp = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->cbAutoUpdate = (gcnew System::Windows::Forms::CheckBox());
			this->btRenderToImage = (gcnew System::Windows::Forms::Button());
			this->btRenderToViewport = (gcnew System::Windows::Forms::Button());
			this->grpViewport->SuspendLayout();
			this->grpSet->SuspendLayout();
			this->grpRender->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nIterations))->BeginInit();
			this->SuspendLayout();
			// 
			// canvas
			// 
			this->canvas->Dock = System::Windows::Forms::DockStyle::Fill;
			this->canvas->Location = System::Drawing::Point(3, 16);
			this->canvas->Name = L"canvas";
			this->canvas->Size = System::Drawing::Size(937, 504);
			this->canvas->TabIndex = 0;
			this->canvas->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::canvas_Paint);
			// 
			// grpViewport
			// 
			this->grpViewport->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->grpViewport->Controls->Add(this->canvas);
			this->grpViewport->Location = System::Drawing::Point(12, 67);
			this->grpViewport->Name = L"grpViewport";
			this->grpViewport->Size = System::Drawing::Size(943, 523);
			this->grpViewport->TabIndex = 0;
			this->grpViewport->TabStop = false;
			this->grpViewport->Text = L"Viewport";
			// 
			// grpSet
			// 
			this->grpSet->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->grpSet->Controls->Add(this->label2);
			this->grpSet->Controls->Add(this->comboBox1);
			this->grpSet->Controls->Add(this->tbVarInput2);
			this->grpSet->Controls->Add(this->lblVar2);
			this->grpSet->Controls->Add(this->tbVarInput1);
			this->grpSet->Controls->Add(this->lblVar1);
			this->grpSet->Controls->Add(this->lblPreset);
			this->grpSet->Controls->Add(this->cbPresets);
			this->grpSet->Location = System::Drawing::Point(12, 13);
			this->grpSet->Name = L"grpSet";
			this->grpSet->Size = System::Drawing::Size(943, 48);
			this->grpSet->TabIndex = 1;
			this->grpSet->TabStop = false;
			this->grpSet->Text = L"Set";
			// 
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(717, 20);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(77, 13);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Colour scheme";
			this->label2->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// comboBox1
			// 
			this->comboBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(799, 17);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(138, 21);
			this->comboBox1->TabIndex = 6;
			// 
			// tbVarInput2
			// 
			this->tbVarInput2->Location = System::Drawing::Point(402, 17);
			this->tbVarInput2->Name = L"tbVarInput2";
			this->tbVarInput2->Size = System::Drawing::Size(100, 20);
			this->tbVarInput2->TabIndex = 5;
			// 
			// lblVar2
			// 
			this->lblVar2->AutoSize = true;
			this->lblVar2->Location = System::Drawing::Point(379, 20);
			this->lblVar2->Name = L"lblVar2";
			this->lblVar2->Size = System::Drawing::Size(22, 13);
			this->lblVar2->TabIndex = 4;
			this->lblVar2->Text = L"θ =";
			// 
			// tbVarInput1
			// 
			this->tbVarInput1->Location = System::Drawing::Point(264, 17);
			this->tbVarInput1->Name = L"tbVarInput1";
			this->tbVarInput1->Size = System::Drawing::Size(100, 20);
			this->tbVarInput1->TabIndex = 3;
			// 
			// lblVar1
			// 
			this->lblVar1->AutoSize = true;
			this->lblVar1->Location = System::Drawing::Point(241, 20);
			this->lblVar1->Name = L"lblVar1";
			this->lblVar1->Size = System::Drawing::Size(22, 13);
			this->lblVar1->TabIndex = 2;
			this->lblVar1->Text = L"k =";
			// 
			// lblPreset
			// 
			this->lblPreset->AutoSize = true;
			this->lblPreset->Location = System::Drawing::Point(7, 20);
			this->lblPreset->Name = L"lblPreset";
			this->lblPreset->Size = System::Drawing::Size(76, 13);
			this->lblPreset->TabIndex = 1;
			this->lblPreset->Text = L"Formula preset";
			// 
			// cbPresets
			// 
			this->cbPresets->FormattingEnabled = true;
			this->cbPresets->Location = System::Drawing::Point(89, 17);
			this->cbPresets->Name = L"cbPresets";
			this->cbPresets->Size = System::Drawing::Size(138, 21);
			this->cbPresets->TabIndex = 0;
			// 
			// grpRender
			// 
			this->grpRender->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->grpRender->Controls->Add(this->nIterations);
			this->grpRender->Controls->Add(this->btHelp);
			this->grpRender->Controls->Add(this->label1);
			this->grpRender->Controls->Add(this->cbAutoUpdate);
			this->grpRender->Controls->Add(this->btRenderToImage);
			this->grpRender->Controls->Add(this->btRenderToViewport);
			this->grpRender->Location = System::Drawing::Point(12, 596);
			this->grpRender->Name = L"grpRender";
			this->grpRender->Size = System::Drawing::Size(943, 53);
			this->grpRender->TabIndex = 3;
			this->grpRender->TabStop = false;
			this->grpRender->Text = L"Settings and Tools";
			// 
			// nIterations
			// 
			this->nIterations->Location = System::Drawing::Point(88, 21);
			this->nIterations->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100000000, 0, 0, 0 });
			this->nIterations->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->nIterations->Name = L"nIterations";
			this->nIterations->Size = System::Drawing::Size(120, 20);
			this->nIterations->TabIndex = 6;
			this->nIterations->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 75, 0, 0, 0 });
			this->nIterations->ValueChanged += gcnew System::EventHandler(this, &MainForm::nIterations_ValueChanged);
			// 
			// btHelp
			// 
			this->btHelp->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btHelp->Location = System::Drawing::Point(862, 18);
			this->btHelp->Name = L"btHelp";
			this->btHelp->Size = System::Drawing::Size(75, 23);
			this->btHelp->TabIndex = 5;
			this->btHelp->Text = L"Help";
			this->btHelp->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(7, 23);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(75, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Max iterations:";
			// 
			// cbAutoUpdate
			// 
			this->cbAutoUpdate->AutoSize = true;
			this->cbAutoUpdate->Checked = true;
			this->cbAutoUpdate->CheckState = System::Windows::Forms::CheckState::Checked;
			this->cbAutoUpdate->Location = System::Drawing::Point(355, 22);
			this->cbAutoUpdate->Name = L"cbAutoUpdate";
			this->cbAutoUpdate->Size = System::Drawing::Size(127, 17);
			this->cbAutoUpdate->TabIndex = 2;
			this->cbAutoUpdate->Text = L"Auto update viewport";
			this->cbAutoUpdate->UseVisualStyleBackColor = true;
			this->cbAutoUpdate->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cbAutoUpdate_CheckedChanged);
			// 
			// btRenderToImage
			// 
			this->btRenderToImage->Location = System::Drawing::Point(498, 18);
			this->btRenderToImage->Name = L"btRenderToImage";
			this->btRenderToImage->Size = System::Drawing::Size(105, 23);
			this->btRenderToImage->TabIndex = 1;
			this->btRenderToImage->Text = L"Render to image";
			this->btRenderToImage->UseVisualStyleBackColor = true;
			// 
			// btRenderToViewport
			// 
			this->btRenderToViewport->Enabled = false;
			this->btRenderToViewport->Location = System::Drawing::Point(234, 18);
			this->btRenderToViewport->Name = L"btRenderToViewport";
			this->btRenderToViewport->Size = System::Drawing::Size(115, 23);
			this->btRenderToViewport->TabIndex = 0;
			this->btRenderToViewport->Text = L"Render to viewport";
			this->btRenderToViewport->UseVisualStyleBackColor = true;
			this->btRenderToViewport->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::btRenderToViewport_MouseClick);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(967, 661);
			this->Controls->Add(this->grpRender);
			this->Controls->Add(this->grpSet);
			this->Controls->Add(this->grpViewport);
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Julia Set Visualiser";
			this->ResizeBegin += gcnew System::EventHandler(this, &MainForm::MainForm_ResizeBegin);
			this->ResizeEnd += gcnew System::EventHandler(this, &MainForm::MainForm_ResizeEnd);
			this->SizeChanged += gcnew System::EventHandler(this, &MainForm::MainForm_SizeChanged);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::MainForm_Paint);
			this->grpViewport->ResumeLayout(false);
			this->grpSet->ResumeLayout(false);
			this->grpSet->PerformLayout();
			this->grpRender->ResumeLayout(false);
			this->grpRender->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nIterations))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

		bool autoUpdate_ = true;
		bool finishedResizing_ = true;

		VisualiserController* controller_;

		Graphics^ juliaGraphics_;
		Bitmap^ juliaImage_;

		JuliaSet* juliaSet_;

		void updateJuliaImage()
		{
			juliaGraphics_ = canvas->CreateGraphics();
			juliaImage_ = gcnew Bitmap(juliaGraphics_->VisibleClipBounds.Width,
				juliaGraphics_->VisibleClipBounds.Height);
			controller_->render(juliaImage_, false);
		}

		void paintJuliaSet()
		{
			juliaGraphics_->DrawImageUnscaled(juliaImage_, 0, 0);
		}

		void updateViewport() {
			updateJuliaImage();
			paintJuliaSet();
		}

		void autoUpdateViewport() {
			if (autoUpdate_) {
				updateViewport();
			}
		}
		
		System::Void MainForm_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
			static bool firstPaint = true;
			if (firstPaint) {
				cbAutoUpdate_CheckedChanged(sender, e);
				nIterations_ValueChanged(sender, e);
				firstPaint = false;
			}
		}

		System::Void MainForm_ResizeBegin(System::Object^ sender, System::EventArgs^ e) 
		{
			finishedResizing_ = false;
		}

		System::Void MainForm_ResizeEnd(System::Object^ sender, System::EventArgs^ e) 
		{
			finishedResizing_ = true;
			// MainForm_SizeChanged doesn't get called after this, so must update the image here too.
			autoUpdateViewport();
		}

		System::Void canvas_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) 
		{
			autoUpdateViewport();
		}

		System::Void MainForm_SizeChanged(System::Object^ sender, System::EventArgs^ e) 
		{
			if (finishedResizing_) {
				autoUpdateViewport();
			}
		}

		System::Void cbAutoUpdate_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
			autoUpdate_ = this->cbAutoUpdate->Checked;
			this->btRenderToViewport->Enabled = !autoUpdate_;
			autoUpdateViewport();
		}

		System::Void nIterations_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
			controller_->renderIterations = (int) Decimal::ToSingle(this->nIterations->Value);
			autoUpdateViewport();
		}

		System::Void btRenderToViewport_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
			updateViewport();
		}
	};
}
