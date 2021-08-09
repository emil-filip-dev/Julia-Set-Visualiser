#include "MainForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace JuliaSetVisualiser;

[STAThread]
void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(true);
	MainForm form;
	Application::Run(%form);
}