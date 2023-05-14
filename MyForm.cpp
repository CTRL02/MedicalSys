#include "MyForm.h"
#include<iostream>
#include<fstream>
#include<string>
using std::cout;
using std::cin;
using std::endl;
using std::ofstream;
using std::string;
using std::ifstream;

using namespace Project4;

using namespace System;

using namespace System::Windows::Forms;
[STAThread]

void main(array<String^>^ args)
{


    fillcustomer();
    fillsupplier();
    fillmedical();
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);    
    Project4::MyForm form; //cppsp project's name
    Application::Run(% form);
    addtofile();


}