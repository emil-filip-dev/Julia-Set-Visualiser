#include "MainForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace JuliaSetVisualiser;

[STAThread]
void main(cli::array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(true);

	VisualiserController* controller = new VisualiserController();
	MainForm^ form = gcnew MainForm(controller);

	Application::Run(form);

	delete controller;
}