#include "PingSpammer.h"

using namespace System;

using namespace System::Windows::Forms;

[STAThread]
int main() {

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	pingSpammer::PingSpammer form;
	Application::Run(%form);

	

	return 0;
}