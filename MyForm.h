#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include  <string.h>
#include<ctime>
#include <msclr\marshal_cppstd.h>
using std::cout;
using std::cin;
using std::endl;
using std::ofstream;
using std::string;
using std::ifstream;
using std::fstream;


using namespace System;
#define MAX 26 //max number of records
int x = 0; //for maximize button 
int custnum = 0;
int suppnum = 0;
int mednum = 0;
int suppidx = 0; //idx of supplier to be updated in update supplier name panel
int suppidxid = 0; //idx of supplier to be updated in update supplier id panel
int custidxid = 0; //idx of customer to be updated in customer update id panel
int custidxphone = 0; //idx of customer to be updated in customer update phone panel
int pause = 0; // pause background song

struct customer // customer detils
{
	string name;
	int id;
	string phone;
	int num;
	string custproducts[MAX]; // array of struct has the purchased products per user
	string TotalPriceofweek, Billvalue;
	string date; //date of last bill

}; customer cust[MAX];
struct supplier //supplier details
{
	int num; // number of supplied products
	int id;
	string phone;
	string name;
	string suppproducts[MAX];
};
supplier supp[MAX];



struct MedicalProducts //medical product details
{
	int id;
	int stock;
	string name;
	string SupplierName;
	string price;
	string date; //expiry date

}; MedicalProducts med[MAX];


void fillcustomer()
{
	ifstream k("customer.txt");
	string name;
	int i = 0;
	while (k >> name)
	{


		cust[i].id = stoi(name.substr(1));

		getline(k, cust[i].name);
		getline(k, cust[i].name);


		k >> name;
		cust[i].phone = name;


		k >> name;
		cust[i].num = stoi(name);
		for (int j = 0; j < cust[i].num; j++)
		{
			k >> name;
			cust[i].custproducts[j] = name;


		}


		getline(k, cust[i].date);
		getline(k, cust[i].date);


		k >> name;
		cust[i].Billvalue = name;


		k >> name;
		cust[i].TotalPriceofweek = name;

		i++;
	}
	custnum = i;
}
void fillsupplier()
{

	int i = 0;
	ifstream k("supplier.txt");
	string name;
	while (k >> name)
	{

		supp[i].id = stoi(name.substr(1));

		getline(k, supp[i].name);

		getline(k, supp[i].name);


		k >> name;
		supp[i].phone = name;


		k >> name;
		supp[i].num = stoi(name);
		for (int j = 0; j < supp[i].num; j++)
		{
			k >> name;
			supp[i].suppproducts[j] = name;


		}
		i++;
	}
	suppnum = i;
}
void fillmedical()
{

	ifstream k("medical.txt");
	string name;
	int i = 0;
	while (k >> name)
	{

		med[i].id = stoi(name.substr(1));
		getline(k, name);
		getline(k, name);

		med[i].name = name;
		getline(k, name);
		med[i].stock = stoi(name);
		getline(k, name);
		med[i].date = name;

		getline(k, name);
		med[i].SupplierName = name;
		getline(k, name);

		med[i].price = name;





		i++;
	}
	mednum = i;
}


void addtofile()
{

	ofstream m("medical.txt");
	ofstream k("customer.txt");
	ofstream s("supplier.txt");
	for (int i = 0; i < custnum; i++)
	{
		k << "U" << cust[i].id << endl << cust[i].name
			<< endl << cust[i].phone << endl << cust[i].num << endl;
		for (int j = 0; j < cust[i].num; j++)
		{
			k << cust[i].custproducts[j];
			k << endl;
		}
		k << cust[i].date << endl << cust[i].Billvalue << endl << cust[i].TotalPriceofweek << endl;

	}

	for (int i = 0; i < mednum; i++)
	{
		m << "M" << med[i].id << endl << med[i].name << endl << med[i].stock << endl
			<< med[i].date << endl;
		m << med[i].SupplierName << endl << med[i].price << endl;
	}

	for (int i = 0; i < suppnum; i++)
	{
		s << "S" << supp[i].id << endl << supp[i].name << endl << supp[i].phone << endl << supp[i].num << endl;
		for (int j = 0; j < supp[i].num; j++)
		{
			s << supp[i].suppproducts[j] << endl;
		}

	}



}






namespace Project4 {


	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		System::Media::SoundPlayer^ player = gcnew System::Media::SoundPlayer();
	public:

		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			player->SoundLocation = "Mozart - Lacrimosa.wav";
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ welcome1;


	private: System::Windows::Forms::Label^ header_welocme;
	protected:

	protected:


	private: System::Windows::Forms::Panel^ options;
	private: System::Windows::Forms::Button^ add;







	private: System::Windows::Forms::Button^ update;
	private: System::Windows::Forms::Button^ search;
	private: System::Windows::Forms::Button^ delete1;



	private: System::Windows::Forms::Button^ report;












	private:

	private:

	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::PictureBox^ pictureBox3;

	public: System::Windows::Forms::Panel^ newadd;
	private: System::Windows::Forms::Button^ medadd;
	private: System::Windows::Forms::Button^ suppadd;
	private: System::Windows::Forms::Button^ custadd;
	public:
	private:

	public:


	private: System::Windows::Forms::Panel^ addmed;





	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Panel^ home;

	private: System::Windows::Forms::TextBox^ suppliernamemed;

	private: System::Windows::Forms::TextBox^ namemed;
	private: System::Windows::Forms::TextBox^ stockmed;
	private: System::Windows::Forms::TextBox^ pricemed;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::MaskedTextBox^ datemed;

	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::PictureBox^ pictureBox4;
	private: System::Windows::Forms::Panel^ newcust;
	private: System::Windows::Forms::RichTextBox^ purchasedproducts;

	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Button^ button1cust;

	private: System::Windows::Forms::MaskedTextBox^ billdate;

	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::TextBox^ billvalue;


	private: System::Windows::Forms::TextBox^ custname;
	private: System::Windows::Forms::TextBox^ custphone;


	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Panel^ searchp;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Panel^ searchproduct;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Panel^ productsearchid;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::TextBox^ barsearch;

	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Panel^ showproduct;
	private: System::Windows::Forms::Label^ meddate;
	private: System::Windows::Forms::Label^ medsuppliername;


	private: System::Windows::Forms::Label^ medprice;

	private: System::Windows::Forms::Label^ medstock;

	private: System::Windows::Forms::Label^ medname;

	private: System::Windows::Forms::Label^ medid;

	private: System::Windows::Forms::Label^ label23;
	private: System::Windows::Forms::Label^ label22;
	private: System::Windows::Forms::Label^ label20;
	private: System::Windows::Forms::Label^ label19;
	private: System::Windows::Forms::Label^ label18;
	private: System::Windows::Forms::Label^ label17;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::Panel^ searchname;
	private: System::Windows::Forms::Button^ back;
	private: System::Windows::Forms::TextBox^ namemedtxt;


	private: System::Windows::Forms::Label^ label21;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label24;
	private: System::Windows::Forms::Label^ label25;
	private: System::Windows::Forms::Label^ label26;
	private: System::Windows::Forms::Label^ label27;
	private: System::Windows::Forms::Label^ label28;
	private: System::Windows::Forms::Label^ label29;
	private: System::Windows::Forms::Label^ label30;
	private: System::Windows::Forms::Label^ label31;
	private: System::Windows::Forms::Label^ label32;
	private: System::Windows::Forms::Label^ label33;
	private: System::Windows::Forms::Label^ label34;
	private: System::Windows::Forms::Label^ label35;
	private: System::Windows::Forms::Label^ label36;
	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::Panel^ deletepro;
	private: System::Windows::Forms::Button^ button10;
	private: System::Windows::Forms::Button^ button11;
	private: System::Windows::Forms::Button^ button12;
	private: System::Windows::Forms::Panel^ deleteproduct;

	private: System::Windows::Forms::Button^ button14;
	private: System::Windows::Forms::Button^ button13;
	private: System::Windows::Forms::Panel^ searchcustp;
	private: System::Windows::Forms::Button^ button15;
	private: System::Windows::Forms::Button^ button16;
	private: System::Windows::Forms::Panel^ searchcustidp;
	private: System::Windows::Forms::Button^ button17;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Label^ label37;
	private: System::Windows::Forms::Label^ label38;
	private: System::Windows::Forms::Label^ label39;
	private: System::Windows::Forms::Label^ label40;
	private: System::Windows::Forms::Label^ label41;
	private: System::Windows::Forms::Label^ label42;
	private: System::Windows::Forms::Label^ label43;
	private: System::Windows::Forms::Label^ label44;
	private: System::Windows::Forms::Label^ label45;
	private: System::Windows::Forms::Label^ label46;
	private: System::Windows::Forms::Label^ label47;
	private: System::Windows::Forms::Label^ label48;
	private: System::Windows::Forms::Label^ label49;
	private: System::Windows::Forms::Button^ button18;
	private: System::Windows::Forms::Label^ label50;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label52;
	private: System::Windows::Forms::Label^ label51;
	private: System::Windows::Forms::Panel^ updatepanel;


	private: System::Windows::Forms::Button^ button20;
	private: System::Windows::Forms::Button^ button19;



	private: System::Windows::Forms::Panel^ updatecust;






private: System::Windows::Forms::Panel^ updatesuppid;
private: System::Windows::Forms::Panel^ searchcustphone;











	private: System::Windows::Forms::Button^ button25;
	private: System::Windows::Forms::Panel^ panel12;
	private: System::Windows::Forms::Label^ label53;
	private: System::Windows::Forms::Label^ label54;
	private: System::Windows::Forms::Label^ label55;
	private: System::Windows::Forms::Label^ label56;
	private: System::Windows::Forms::Label^ label57;
	private: System::Windows::Forms::Label^ label58;
	private: System::Windows::Forms::Label^ label59;
	private: System::Windows::Forms::Label^ label60;
	private: System::Windows::Forms::Label^ label61;
	private: System::Windows::Forms::Label^ label62;
	private: System::Windows::Forms::Label^ label63;
	private: System::Windows::Forms::Label^ label64;
	private: System::Windows::Forms::Label^ label65;
	private: System::Windows::Forms::Label^ label66;
	private: System::Windows::Forms::Label^ label67;
	private: System::Windows::Forms::Button^ button26;
	private: System::Windows::Forms::Label^ label68;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::Panel^ searchsupp;
	private: System::Windows::Forms::Button^ button27;
	private: System::Windows::Forms::Button^ button28;
	private: System::Windows::Forms::Panel^ searchsupplierid;


	private: System::Windows::Forms::Panel^ panel14;
	private: System::Windows::Forms::Label^ label73;
	private: System::Windows::Forms::Label^ label74;
	private: System::Windows::Forms::Label^ label75;
	private: System::Windows::Forms::Label^ label76;
	private: System::Windows::Forms::Label^ label79;
	private: System::Windows::Forms::Label^ label81;
	private: System::Windows::Forms::Label^ label82;
	private: System::Windows::Forms::Label^ label83;
	private: System::Windows::Forms::Button^ button30;
	private: System::Windows::Forms::Label^ label84;
	private: System::Windows::Forms::TextBox^ textBox7;
	private: System::Windows::Forms::Panel^ searchsuppliername;


	private: System::Windows::Forms::Button^ button31;
	private: System::Windows::Forms::Panel^ panel16;
	private: System::Windows::Forms::Label^ label69;
	private: System::Windows::Forms::Label^ label70;
	private: System::Windows::Forms::Label^ label71;
	private: System::Windows::Forms::Label^ label72;
	private: System::Windows::Forms::Label^ label77;
	private: System::Windows::Forms::Label^ label78;
	private: System::Windows::Forms::Label^ label80;
	private: System::Windows::Forms::Label^ label85;
	private: System::Windows::Forms::Button^ button32;
	private: System::Windows::Forms::Label^ label86;
	private: System::Windows::Forms::TextBox^ textBox8;
	private: System::Windows::Forms::Panel^ addsupplier;
	private: System::Windows::Forms::Panel^ fullreport;
	private: System::Windows::Forms::Panel^ deletecust;
	private: System::Windows::Forms::Panel^ deletesup;
	private: System::Windows::Forms::Panel^ deletecustid;
	private: System::Windows::Forms::Panel^ deletecustphone;
	private: System::Windows::Forms::Panel^ deletesupplierid;
	private: System::Windows::Forms::Panel^ deletesuppliername;
	private: System::Windows::Forms::Panel^ deleteproductname;
	private: System::Windows::Forms::Panel^ deleteproductid;
	private: System::Windows::Forms::Button^ button34;
	private: System::Windows::Forms::Button^ button33;





















	private: System::Windows::Forms::Label^ label87;
	private: System::Windows::Forms::TextBox^ textBox9;
	private: System::Windows::Forms::Button^ button38;
	private: System::Windows::Forms::Label^ label88;
	private: System::Windows::Forms::TextBox^ textBox10;

	private: System::Windows::Forms::Label^ label89;
	private: System::Windows::Forms::TextBox^ textBox11;

	private: System::Windows::Forms::Label^ label90;
	private: System::Windows::Forms::TextBox^ textBox12;

	private: System::Windows::Forms::Label^ label92;
	private: System::Windows::Forms::TextBox^ textBox14;

	private: System::Windows::Forms::Label^ label91;
	private: System::Windows::Forms::TextBox^ textBox13;
	private: System::Windows::Forms::Button^ button35;
	private: System::Windows::Forms::Button^ button36;
private: System::Windows::Forms::Label^ label93;
private: System::Windows::Forms::TextBox^ textBox15;


private: System::Windows::Forms::Panel^ updatesupp;
private: System::Windows::Forms::Button^ button43;
private: System::Windows::Forms::Button^ button44;
private: System::Windows::Forms::Panel^ updatesuppname;

private: System::Windows::Forms::TextBox^ textBox16;
private: System::Windows::Forms::Label^ label94;
private: System::Windows::Forms::Button^ button45;
private: System::Windows::Forms::Button^ button21;
private: System::Windows::Forms::TextBox^ textBox5;
private: System::Windows::Forms::Label^ label95;
private: System::Windows::Forms::Label^ label96;
private: System::Windows::Forms::Label^ label99;
private: System::Windows::Forms::Label^ label97;

private: System::Windows::Forms::Button^ button46;
private: System::Windows::Forms::TextBox^ textBox17;
private: System::Windows::Forms::Button^ button47;
private: System::Windows::Forms::Button^ button22;
private: System::Windows::Forms::Button^ button23;
private: System::Windows::Forms::Panel^ updatecustomerphone;
private: System::Windows::Forms::Panel^ updatecustomerid;
private: System::Windows::Forms::TextBox^ textBox18;
private: System::Windows::Forms::Label^ label102;
private: System::Windows::Forms::TextBox^ textBox4;
private: System::Windows::Forms::Label^ label101;

private: System::Windows::Forms::Label^ label100;
private: System::Windows::Forms::Button^ button24;
private: System::Windows::Forms::TextBox^ textBox2;
private: System::Windows::Forms::Label^ label98;
private: System::Windows::Forms::Button^ button50;
private: System::Windows::Forms::Button^ button49;
private: System::Windows::Forms::Button^ button48;
private: System::Windows::Forms::MaskedTextBox^ maskedTextBox1;
private: System::Windows::Forms::Label^ label103;
private: System::Windows::Forms::Label^ label104;
private: System::Windows::Forms::Label^ label107;
private: System::Windows::Forms::Label^ label106;
private: System::Windows::Forms::Label^ label105;
private: System::Windows::Forms::Label^ label108;
private: System::Windows::Forms::Label^ label109;
private: System::Windows::Forms::Label^ label110;
private: System::Windows::Forms::Label^ label111;
private: System::Windows::Forms::Label^ label112;
private: System::Windows::Forms::Button^ button51;
private: System::Windows::Forms::Button^ button52;
private: System::Windows::Forms::Button^ button53;
private: System::Windows::Forms::MaskedTextBox^ maskedTextBox2;
private: System::Windows::Forms::TextBox^ textBox3;
private: System::Windows::Forms::Label^ label113;
private: System::Windows::Forms::TextBox^ textBox19;
private: System::Windows::Forms::Label^ label114;
private: System::Windows::Forms::Label^ label115;
private: System::Windows::Forms::Button^ button54;
private: System::Windows::Forms::TextBox^ textBox20;
private: System::Windows::Forms::Label^ label116;
private: System::Windows::Forms::Label^ label117;
private: System::Windows::Forms::Button^ button55;
private: System::Windows::Forms::ListView^ listView1;
private: System::Windows::Forms::ColumnHeader^ columnHeader1;
private: System::Windows::Forms::ColumnHeader^ columnHeader2;
private: System::Windows::Forms::ColumnHeader^ columnHeader3;
private: System::Windows::Forms::Button^ button56;
private: System::Windows::Forms::Label^ label118;
private: System::Windows::Forms::Button^ button39;


private: System::Windows::Forms::Label^ label121;
private: System::Windows::Forms::Label^ label120;
private: System::Windows::Forms::Label^ label119;
private: System::Windows::Forms::TextBox^ textBox23;

private: System::Windows::Forms::TextBox^ textBox21;
private: System::Windows::Forms::RichTextBox^ supplierproducts;
private: System::Windows::Forms::Button^ button57;
private: System::Windows::Forms::Label^ label122;
private: System::Windows::Forms::Button^ button40;
private: System::Windows::Forms::Button^ button58;
private: System::Windows::Forms::Button^ button59;
private: System::Windows::Forms::Button^ button60;
private: System::Windows::Forms::Button^ button61;
private: System::Windows::Forms::Label^ label123;
private: System::Windows::Forms::Button^ button41;
private: System::Windows::Forms::Label^ label124;
private: System::Windows::Forms::Button^ button42;
private: System::Windows::Forms::Label^ label125;
private: System::Windows::Forms::Label^ label126;
private: System::Windows::Forms::Button^ button37;
private: System::Windows::Forms::Label^ label127;
private: System::Windows::Forms::Button^ button29;
private: System::Windows::Forms::Button^ button62;
private: System::Windows::Forms::Button^ button63;
private: System::Windows::Forms::Button^ button64;
private: System::Windows::Forms::Button^ button65;
private: System::Windows::Forms::Button^ button67;
private: System::Windows::Forms::Button^ button66;






















































	private:

	public:





	private:
	public:
	private:

	private:

	public:

	public:
	private:






	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->welcome1 = (gcnew System::Windows::Forms::Panel());
			this->button55 = (gcnew System::Windows::Forms::Button());
			this->header_welocme = (gcnew System::Windows::Forms::Label());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->options = (gcnew System::Windows::Forms::Panel());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->report = (gcnew System::Windows::Forms::Button());
			this->update = (gcnew System::Windows::Forms::Button());
			this->add = (gcnew System::Windows::Forms::Button());
			this->search = (gcnew System::Windows::Forms::Button());
			this->delete1 = (gcnew System::Windows::Forms::Button());
			this->newadd = (gcnew System::Windows::Forms::Panel());
			this->medadd = (gcnew System::Windows::Forms::Button());
			this->suppadd = (gcnew System::Windows::Forms::Button());
			this->custadd = (gcnew System::Windows::Forms::Button());
			this->addmed = (gcnew System::Windows::Forms::Panel());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->datemed = (gcnew System::Windows::Forms::MaskedTextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->suppliernamemed = (gcnew System::Windows::Forms::TextBox());
			this->namemed = (gcnew System::Windows::Forms::TextBox());
			this->stockmed = (gcnew System::Windows::Forms::TextBox());
			this->pricemed = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->home = (gcnew System::Windows::Forms::Panel());
			this->newcust = (gcnew System::Windows::Forms::Panel());
			this->purchasedproducts = (gcnew System::Windows::Forms::RichTextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->button1cust = (gcnew System::Windows::Forms::Button());
			this->billdate = (gcnew System::Windows::Forms::MaskedTextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->billvalue = (gcnew System::Windows::Forms::TextBox());
			this->custname = (gcnew System::Windows::Forms::TextBox());
			this->custphone = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->searchp = (gcnew System::Windows::Forms::Panel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->searchproduct = (gcnew System::Windows::Forms::Panel());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->searchname = (gcnew System::Windows::Forms::Panel());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->label30 = (gcnew System::Windows::Forms::Label());
			this->label31 = (gcnew System::Windows::Forms::Label());
			this->label32 = (gcnew System::Windows::Forms::Label());
			this->label33 = (gcnew System::Windows::Forms::Label());
			this->label34 = (gcnew System::Windows::Forms::Label());
			this->label35 = (gcnew System::Windows::Forms::Label());
			this->label36 = (gcnew System::Windows::Forms::Label());
			this->back = (gcnew System::Windows::Forms::Button());
			this->namemedtxt = (gcnew System::Windows::Forms::TextBox());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->productsearchid = (gcnew System::Windows::Forms::Panel());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->showproduct = (gcnew System::Windows::Forms::Panel());
			this->meddate = (gcnew System::Windows::Forms::Label());
			this->medsuppliername = (gcnew System::Windows::Forms::Label());
			this->medprice = (gcnew System::Windows::Forms::Label());
			this->medstock = (gcnew System::Windows::Forms::Label());
			this->medname = (gcnew System::Windows::Forms::Label());
			this->medid = (gcnew System::Windows::Forms::Label());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->barsearch = (gcnew System::Windows::Forms::TextBox());
			this->deletepro = (gcnew System::Windows::Forms::Panel());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->deleteproduct = (gcnew System::Windows::Forms::Panel());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->button14 = (gcnew System::Windows::Forms::Button());
			this->searchcustp = (gcnew System::Windows::Forms::Panel());
			this->button15 = (gcnew System::Windows::Forms::Button());
			this->button16 = (gcnew System::Windows::Forms::Button());
			this->searchcustidp = (gcnew System::Windows::Forms::Panel());
			this->button17 = (gcnew System::Windows::Forms::Button());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->label52 = (gcnew System::Windows::Forms::Label());
			this->label51 = (gcnew System::Windows::Forms::Label());
			this->label37 = (gcnew System::Windows::Forms::Label());
			this->label38 = (gcnew System::Windows::Forms::Label());
			this->label39 = (gcnew System::Windows::Forms::Label());
			this->label40 = (gcnew System::Windows::Forms::Label());
			this->label41 = (gcnew System::Windows::Forms::Label());
			this->label42 = (gcnew System::Windows::Forms::Label());
			this->label43 = (gcnew System::Windows::Forms::Label());
			this->label44 = (gcnew System::Windows::Forms::Label());
			this->label45 = (gcnew System::Windows::Forms::Label());
			this->label46 = (gcnew System::Windows::Forms::Label());
			this->label47 = (gcnew System::Windows::Forms::Label());
			this->label48 = (gcnew System::Windows::Forms::Label());
			this->label49 = (gcnew System::Windows::Forms::Label());
			this->button18 = (gcnew System::Windows::Forms::Button());
			this->label50 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->updatepanel = (gcnew System::Windows::Forms::Panel());
			this->button20 = (gcnew System::Windows::Forms::Button());
			this->button19 = (gcnew System::Windows::Forms::Button());
			this->updatecust = (gcnew System::Windows::Forms::Panel());
			this->button22 = (gcnew System::Windows::Forms::Button());
			this->button23 = (gcnew System::Windows::Forms::Button());
			this->updatesuppid = (gcnew System::Windows::Forms::Panel());
			this->button60 = (gcnew System::Windows::Forms::Button());
			this->label99 = (gcnew System::Windows::Forms::Label());
			this->label97 = (gcnew System::Windows::Forms::Label());
			this->button46 = (gcnew System::Windows::Forms::Button());
			this->textBox17 = (gcnew System::Windows::Forms::TextBox());
			this->button47 = (gcnew System::Windows::Forms::Button());
			this->label93 = (gcnew System::Windows::Forms::Label());
			this->textBox15 = (gcnew System::Windows::Forms::TextBox());
			this->searchcustphone = (gcnew System::Windows::Forms::Panel());
			this->button25 = (gcnew System::Windows::Forms::Button());
			this->panel12 = (gcnew System::Windows::Forms::Panel());
			this->label53 = (gcnew System::Windows::Forms::Label());
			this->label54 = (gcnew System::Windows::Forms::Label());
			this->label55 = (gcnew System::Windows::Forms::Label());
			this->label56 = (gcnew System::Windows::Forms::Label());
			this->label57 = (gcnew System::Windows::Forms::Label());
			this->label58 = (gcnew System::Windows::Forms::Label());
			this->label59 = (gcnew System::Windows::Forms::Label());
			this->label60 = (gcnew System::Windows::Forms::Label());
			this->label61 = (gcnew System::Windows::Forms::Label());
			this->label62 = (gcnew System::Windows::Forms::Label());
			this->label63 = (gcnew System::Windows::Forms::Label());
			this->label64 = (gcnew System::Windows::Forms::Label());
			this->label65 = (gcnew System::Windows::Forms::Label());
			this->label66 = (gcnew System::Windows::Forms::Label());
			this->label67 = (gcnew System::Windows::Forms::Label());
			this->button26 = (gcnew System::Windows::Forms::Button());
			this->label68 = (gcnew System::Windows::Forms::Label());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->searchsupp = (gcnew System::Windows::Forms::Panel());
			this->button27 = (gcnew System::Windows::Forms::Button());
			this->button28 = (gcnew System::Windows::Forms::Button());
			this->searchsupplierid = (gcnew System::Windows::Forms::Panel());
			this->button29 = (gcnew System::Windows::Forms::Button());
			this->panel14 = (gcnew System::Windows::Forms::Panel());
			this->label73 = (gcnew System::Windows::Forms::Label());
			this->label74 = (gcnew System::Windows::Forms::Label());
			this->label75 = (gcnew System::Windows::Forms::Label());
			this->label76 = (gcnew System::Windows::Forms::Label());
			this->label79 = (gcnew System::Windows::Forms::Label());
			this->label81 = (gcnew System::Windows::Forms::Label());
			this->label82 = (gcnew System::Windows::Forms::Label());
			this->label83 = (gcnew System::Windows::Forms::Label());
			this->button30 = (gcnew System::Windows::Forms::Button());
			this->label84 = (gcnew System::Windows::Forms::Label());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->searchsuppliername = (gcnew System::Windows::Forms::Panel());
			this->button31 = (gcnew System::Windows::Forms::Button());
			this->panel16 = (gcnew System::Windows::Forms::Panel());
			this->label69 = (gcnew System::Windows::Forms::Label());
			this->label70 = (gcnew System::Windows::Forms::Label());
			this->label71 = (gcnew System::Windows::Forms::Label());
			this->label72 = (gcnew System::Windows::Forms::Label());
			this->label77 = (gcnew System::Windows::Forms::Label());
			this->label78 = (gcnew System::Windows::Forms::Label());
			this->label80 = (gcnew System::Windows::Forms::Label());
			this->label85 = (gcnew System::Windows::Forms::Label());
			this->button32 = (gcnew System::Windows::Forms::Button());
			this->label86 = (gcnew System::Windows::Forms::Label());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->addsupplier = (gcnew System::Windows::Forms::Panel());
			this->supplierproducts = (gcnew System::Windows::Forms::RichTextBox());
			this->button57 = (gcnew System::Windows::Forms::Button());
			this->label122 = (gcnew System::Windows::Forms::Label());
			this->textBox23 = (gcnew System::Windows::Forms::TextBox());
			this->textBox21 = (gcnew System::Windows::Forms::TextBox());
			this->label121 = (gcnew System::Windows::Forms::Label());
			this->label120 = (gcnew System::Windows::Forms::Label());
			this->label119 = (gcnew System::Windows::Forms::Label());
			this->fullreport = (gcnew System::Windows::Forms::Panel());
			this->button56 = (gcnew System::Windows::Forms::Button());
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->columnHeader1 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader2 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader3 = (gcnew System::Windows::Forms::ColumnHeader());
			this->deletecust = (gcnew System::Windows::Forms::Panel());
			this->button34 = (gcnew System::Windows::Forms::Button());
			this->button33 = (gcnew System::Windows::Forms::Button());
			this->deletesup = (gcnew System::Windows::Forms::Panel());
			this->button35 = (gcnew System::Windows::Forms::Button());
			this->button36 = (gcnew System::Windows::Forms::Button());
			this->deletecustid = (gcnew System::Windows::Forms::Panel());
			this->button67 = (gcnew System::Windows::Forms::Button());
			this->label126 = (gcnew System::Windows::Forms::Label());
			this->button37 = (gcnew System::Windows::Forms::Button());
			this->label87 = (gcnew System::Windows::Forms::Label());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->deletecustphone = (gcnew System::Windows::Forms::Panel());
			this->button66 = (gcnew System::Windows::Forms::Button());
			this->label127 = (gcnew System::Windows::Forms::Label());
			this->button38 = (gcnew System::Windows::Forms::Button());
			this->label88 = (gcnew System::Windows::Forms::Label());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->deletesupplierid = (gcnew System::Windows::Forms::Panel());
			this->button62 = (gcnew System::Windows::Forms::Button());
			this->label118 = (gcnew System::Windows::Forms::Label());
			this->button39 = (gcnew System::Windows::Forms::Button());
			this->label89 = (gcnew System::Windows::Forms::Label());
			this->textBox11 = (gcnew System::Windows::Forms::TextBox());
			this->deletesuppliername = (gcnew System::Windows::Forms::Panel());
			this->button63 = (gcnew System::Windows::Forms::Button());
			this->label123 = (gcnew System::Windows::Forms::Label());
			this->button40 = (gcnew System::Windows::Forms::Button());
			this->label90 = (gcnew System::Windows::Forms::Label());
			this->textBox12 = (gcnew System::Windows::Forms::TextBox());
			this->deleteproductname = (gcnew System::Windows::Forms::Panel());
			this->button64 = (gcnew System::Windows::Forms::Button());
			this->label125 = (gcnew System::Windows::Forms::Label());
			this->button42 = (gcnew System::Windows::Forms::Button());
			this->label92 = (gcnew System::Windows::Forms::Label());
			this->textBox14 = (gcnew System::Windows::Forms::TextBox());
			this->deleteproductid = (gcnew System::Windows::Forms::Panel());
			this->button65 = (gcnew System::Windows::Forms::Button());
			this->label124 = (gcnew System::Windows::Forms::Label());
			this->button41 = (gcnew System::Windows::Forms::Button());
			this->label91 = (gcnew System::Windows::Forms::Label());
			this->textBox13 = (gcnew System::Windows::Forms::TextBox());
			this->updatesupp = (gcnew System::Windows::Forms::Panel());
			this->button43 = (gcnew System::Windows::Forms::Button());
			this->button44 = (gcnew System::Windows::Forms::Button());
			this->updatesuppname = (gcnew System::Windows::Forms::Panel());
			this->button61 = (gcnew System::Windows::Forms::Button());
			this->label96 = (gcnew System::Windows::Forms::Label());
			this->label95 = (gcnew System::Windows::Forms::Label());
			this->button21 = (gcnew System::Windows::Forms::Button());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->button45 = (gcnew System::Windows::Forms::Button());
			this->textBox16 = (gcnew System::Windows::Forms::TextBox());
			this->label94 = (gcnew System::Windows::Forms::Label());
			this->updatecustomerphone = (gcnew System::Windows::Forms::Panel());
			this->button58 = (gcnew System::Windows::Forms::Button());
			this->label117 = (gcnew System::Windows::Forms::Label());
			this->label108 = (gcnew System::Windows::Forms::Label());
			this->label109 = (gcnew System::Windows::Forms::Label());
			this->label110 = (gcnew System::Windows::Forms::Label());
			this->label111 = (gcnew System::Windows::Forms::Label());
			this->label112 = (gcnew System::Windows::Forms::Label());
			this->button51 = (gcnew System::Windows::Forms::Button());
			this->button52 = (gcnew System::Windows::Forms::Button());
			this->button53 = (gcnew System::Windows::Forms::Button());
			this->maskedTextBox2 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label113 = (gcnew System::Windows::Forms::Label());
			this->textBox19 = (gcnew System::Windows::Forms::TextBox());
			this->label114 = (gcnew System::Windows::Forms::Label());
			this->label115 = (gcnew System::Windows::Forms::Label());
			this->button54 = (gcnew System::Windows::Forms::Button());
			this->textBox20 = (gcnew System::Windows::Forms::TextBox());
			this->label116 = (gcnew System::Windows::Forms::Label());
			this->updatecustomerid = (gcnew System::Windows::Forms::Panel());
			this->button59 = (gcnew System::Windows::Forms::Button());
			this->label107 = (gcnew System::Windows::Forms::Label());
			this->label106 = (gcnew System::Windows::Forms::Label());
			this->label105 = (gcnew System::Windows::Forms::Label());
			this->label104 = (gcnew System::Windows::Forms::Label());
			this->label103 = (gcnew System::Windows::Forms::Label());
			this->button50 = (gcnew System::Windows::Forms::Button());
			this->button49 = (gcnew System::Windows::Forms::Button());
			this->button48 = (gcnew System::Windows::Forms::Button());
			this->maskedTextBox1 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->textBox18 = (gcnew System::Windows::Forms::TextBox());
			this->label102 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label101 = (gcnew System::Windows::Forms::Label());
			this->label100 = (gcnew System::Windows::Forms::Label());
			this->button24 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label98 = (gcnew System::Windows::Forms::Label());
			this->welcome1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			this->options->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			this->newadd->SuspendLayout();
			this->addmed->SuspendLayout();
			this->newcust->SuspendLayout();
			this->searchp->SuspendLayout();
			this->searchproduct->SuspendLayout();
			this->searchname->SuspendLayout();
			this->panel1->SuspendLayout();
			this->productsearchid->SuspendLayout();
			this->showproduct->SuspendLayout();
			this->deletepro->SuspendLayout();
			this->deleteproduct->SuspendLayout();
			this->searchcustp->SuspendLayout();
			this->searchcustidp->SuspendLayout();
			this->panel3->SuspendLayout();
			this->updatepanel->SuspendLayout();
			this->updatecust->SuspendLayout();
			this->updatesuppid->SuspendLayout();
			this->searchcustphone->SuspendLayout();
			this->panel12->SuspendLayout();
			this->searchsupp->SuspendLayout();
			this->searchsupplierid->SuspendLayout();
			this->panel14->SuspendLayout();
			this->searchsuppliername->SuspendLayout();
			this->panel16->SuspendLayout();
			this->addsupplier->SuspendLayout();
			this->fullreport->SuspendLayout();
			this->deletecust->SuspendLayout();
			this->deletesup->SuspendLayout();
			this->deletecustid->SuspendLayout();
			this->deletecustphone->SuspendLayout();
			this->deletesupplierid->SuspendLayout();
			this->deletesuppliername->SuspendLayout();
			this->deleteproductname->SuspendLayout();
			this->deleteproductid->SuspendLayout();
			this->updatesupp->SuspendLayout();
			this->updatesuppname->SuspendLayout();
			this->updatecustomerphone->SuspendLayout();
			this->updatecustomerid->SuspendLayout();
			this->SuspendLayout();
			// 
			// welcome1
			// 
			this->welcome1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->welcome1->BackColor = System::Drawing::Color::Gray;
			this->welcome1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->welcome1->Controls->Add(this->button55);
			this->welcome1->Controls->Add(this->header_welocme);
			this->welcome1->Controls->Add(this->pictureBox2);
			this->welcome1->Controls->Add(this->pictureBox1);
			this->welcome1->Controls->Add(this->pictureBox3);
			this->welcome1->Location = System::Drawing::Point(0, 0);
			this->welcome1->Margin = System::Windows::Forms::Padding(4);
			this->welcome1->Name = L"welcome1";
			this->welcome1->Size = System::Drawing::Size(1543, 51);
			this->welcome1->TabIndex = 0;
			this->welcome1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel1_Paint);
			this->welcome1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::welcome1_MouseDown);
			this->welcome1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::welcome1_MouseMove);
			this->welcome1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::welcome1_MouseUp);
			// 
			// button55
			// 
			this->button55->BackColor = System::Drawing::Color::Transparent;
			this->button55->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button55.BackgroundImage")));
			this->button55->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button55->FlatAppearance->BorderSize = 0;
			this->button55->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button55->ForeColor = System::Drawing::Color::Transparent;
			this->button55->Location = System::Drawing::Point(278, 13);
			this->button55->Name = L"button55";
			this->button55->Size = System::Drawing::Size(36, 30);
			this->button55->TabIndex = 7;
			this->button55->UseVisualStyleBackColor = false;
			this->button55->Click += gcnew System::EventHandler(this, &MyForm::button55_Click);
			// 
			// header_welocme
			// 
			this->header_welocme->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->header_welocme->AutoSize = true;
			this->header_welocme->BackColor = System::Drawing::Color::Transparent;
			this->header_welocme->Font = (gcnew System::Drawing::Font(L"Century", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->header_welocme->ForeColor = System::Drawing::Color::White;
			this->header_welocme->Location = System::Drawing::Point(559, 15);
			this->header_welocme->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->header_welocme->Name = L"header_welocme";
			this->header_welocme->Size = System::Drawing::Size(675, 33);
			this->header_welocme->TabIndex = 1;
			this->header_welocme->Text = L"Welcome to Medical Store Management System";
			this->header_welocme->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->pictureBox2->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.BackgroundImage")));
			this->pictureBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->pictureBox2->Location = System::Drawing::Point(1496, 11);
			this->pictureBox2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(35, 30);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox2->TabIndex = 5;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Click += gcnew System::EventHandler(this, &MyForm::pictureBox2_Click_2);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->pictureBox1->Location = System::Drawing::Point(1457, 11);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(33, 30);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 4;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &MyForm::pictureBox1_Click_1);
			// 
			// pictureBox3
			// 
			this->pictureBox3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->pictureBox3->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.BackgroundImage")));
			this->pictureBox3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->pictureBox3->Location = System::Drawing::Point(1416, 11);
			this->pictureBox3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(35, 30);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox3->TabIndex = 6;
			this->pictureBox3->TabStop = false;
			this->pictureBox3->Click += gcnew System::EventHandler(this, &MyForm::pictureBox3_Click_1);
			// 
			// options
			// 
			this->options->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->options->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->options->Controls->Add(this->pictureBox4);
			this->options->Controls->Add(this->report);
			this->options->Controls->Add(this->update);
			this->options->Controls->Add(this->add);
			this->options->Controls->Add(this->search);
			this->options->Controls->Add(this->delete1);
			this->options->Location = System::Drawing::Point(0, 0);
			this->options->Margin = System::Windows::Forms::Padding(4);
			this->options->Name = L"options";
			this->options->Size = System::Drawing::Size(253, 716);
			this->options->TabIndex = 2;
			this->options->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel2_Paint);
			// 
			// pictureBox4
			// 
			this->pictureBox4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.BackgroundImage")));
			this->pictureBox4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->pictureBox4->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox4->Location = System::Drawing::Point(23, 21);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(205, 151);
			this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox4->TabIndex = 8;
			this->pictureBox4->TabStop = false;
			this->pictureBox4->Click += gcnew System::EventHandler(this, &MyForm::pictureBox4_Click);
			// 
			// report
			// 
			this->report->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->report->BackColor = System::Drawing::Color::White;
			this->report->Cursor = System::Windows::Forms::Cursors::Hand;
			this->report->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->report->Font = (gcnew System::Drawing::Font(L"Cooper Black", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->report->ForeColor = System::Drawing::SystemColors::Desktop;
			this->report->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->report->Location = System::Drawing::Point(0, 192);
			this->report->Margin = System::Windows::Forms::Padding(4);
			this->report->Name = L"report";
			this->report->Size = System::Drawing::Size(253, 76);
			this->report->TabIndex = 7;
			this->report->Text = L"FULL REPORT";
			this->report->UseVisualStyleBackColor = false;
			this->report->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// update
			// 
			this->update->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->update->BackColor = System::Drawing::Color::White;
			this->update->Cursor = System::Windows::Forms::Cursors::Hand;
			this->update->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->update->Font = (gcnew System::Drawing::Font(L"Cooper Black", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->update->ForeColor = System::Drawing::SystemColors::Desktop;
			this->update->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->update->Location = System::Drawing::Point(0, 284);
			this->update->Margin = System::Windows::Forms::Padding(4);
			this->update->Name = L"update";
			this->update->Size = System::Drawing::Size(253, 85);
			this->update->TabIndex = 4;
			this->update->Text = L"    UPDATE RECORDS    ";
			this->update->UseVisualStyleBackColor = false;
			this->update->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// add
			// 
			this->add->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->add->BackColor = System::Drawing::Color::White;
			this->add->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->add->Cursor = System::Windows::Forms::Cursors::Hand;
			this->add->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->add->Font = (gcnew System::Drawing::Font(L"Cooper Black", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->add->ForeColor = System::Drawing::SystemColors::Desktop;
			this->add->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->add->Location = System::Drawing::Point(0, 387);
			this->add->Margin = System::Windows::Forms::Padding(4);
			this->add->Name = L"add";
			this->add->Size = System::Drawing::Size(253, 90);
			this->add->TabIndex = 3;
			this->add->Text = L"ADD RECORDS";
			this->add->UseVisualStyleBackColor = false;
			this->add->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// search
			// 
			this->search->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->search->BackColor = System::Drawing::Color::White;
			this->search->Cursor = System::Windows::Forms::Cursors::Hand;
			this->search->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->search->Font = (gcnew System::Drawing::Font(L"Cooper Black", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->search->ForeColor = System::Drawing::SystemColors::Desktop;
			this->search->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->search->Location = System::Drawing::Point(0, 499);
			this->search->Margin = System::Windows::Forms::Padding(4);
			this->search->Name = L"search";
			this->search->Size = System::Drawing::Size(253, 93);
			this->search->TabIndex = 5;
			this->search->Text = L"  SEARCH FOR  RECORDS";
			this->search->UseVisualStyleBackColor = false;
			this->search->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// delete1
			// 
			this->delete1->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->delete1->BackColor = System::Drawing::Color::White;
			this->delete1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->delete1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->delete1->Font = (gcnew System::Drawing::Font(L"Cooper Black", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->delete1->ForeColor = System::Drawing::SystemColors::Desktop;
			this->delete1->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->delete1->Location = System::Drawing::Point(0, 622);
			this->delete1->Margin = System::Windows::Forms::Padding(4);
			this->delete1->Name = L"delete1";
			this->delete1->Size = System::Drawing::Size(253, 94);
			this->delete1->TabIndex = 6;
			this->delete1->Text = L"   DELETE RECORDS";
			this->delete1->UseVisualStyleBackColor = false;
			this->delete1->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// newadd
			// 
			this->newadd->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->newadd->BackColor = System::Drawing::SystemColors::Control;
			this->newadd->Controls->Add(this->medadd);
			this->newadd->Controls->Add(this->suppadd);
			this->newadd->Controls->Add(this->custadd);
			this->newadd->Location = System::Drawing::Point(322, 69);
			this->newadd->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->newadd->Name = L"newadd";
			this->newadd->Size = System::Drawing::Size(1147, 623);
			this->newadd->TabIndex = 17;
			this->newadd->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::newadd_Paint);
			// 
			// medadd
			// 
			this->medadd->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->medadd->BackColor = System::Drawing::Color::White;
			this->medadd->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->medadd->FlatAppearance->BorderSize = 0;
			this->medadd->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->medadd->Font = (gcnew System::Drawing::Font(L"Cooper Black", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->medadd->ForeColor = System::Drawing::SystemColors::Desktop;
			this->medadd->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->medadd->Location = System::Drawing::Point(330, 346);
			this->medadd->Margin = System::Windows::Forms::Padding(4);
			this->medadd->Name = L"medadd";
			this->medadd->Size = System::Drawing::Size(488, 78);
			this->medadd->TabIndex = 8;
			this->medadd->Text = L"ADD MEDICAL";
			this->medadd->UseVisualStyleBackColor = false;
			this->medadd->Click += gcnew System::EventHandler(this, &MyForm::medadd_Click);
			// 
			// suppadd
			// 
			this->suppadd->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->suppadd->BackColor = System::Drawing::Color::White;
			this->suppadd->FlatAppearance->BorderSize = 0;
			this->suppadd->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->suppadd->Font = (gcnew System::Drawing::Font(L"Cooper Black", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->suppadd->ForeColor = System::Drawing::SystemColors::Desktop;
			this->suppadd->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->suppadd->Location = System::Drawing::Point(330, 257);
			this->suppadd->Margin = System::Windows::Forms::Padding(4);
			this->suppadd->Name = L"suppadd";
			this->suppadd->Size = System::Drawing::Size(488, 72);
			this->suppadd->TabIndex = 9;
			this->suppadd->Text = L"ADD SUPPLIER";
			this->suppadd->UseVisualStyleBackColor = false;
			this->suppadd->Click += gcnew System::EventHandler(this, &MyForm::suppadd_Click);
			// 
			// custadd
			// 
			this->custadd->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->custadd->BackColor = System::Drawing::Color::White;
			this->custadd->FlatAppearance->BorderSize = 0;
			this->custadd->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->custadd->Font = (gcnew System::Drawing::Font(L"Cooper Black", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->custadd->ForeColor = System::Drawing::SystemColors::Desktop;
			this->custadd->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->custadd->Location = System::Drawing::Point(330, 173);
			this->custadd->Margin = System::Windows::Forms::Padding(4);
			this->custadd->Name = L"custadd";
			this->custadd->Size = System::Drawing::Size(488, 68);
			this->custadd->TabIndex = 10;
			this->custadd->Text = L"ADD CUSTOMER";
			this->custadd->UseVisualStyleBackColor = false;
			this->custadd->Click += gcnew System::EventHandler(this, &MyForm::custadd_Click);
			// 
			// addmed
			// 
			this->addmed->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->addmed->BackColor = System::Drawing::SystemColors::Control;
			this->addmed->Controls->Add(this->label7);
			this->addmed->Controls->Add(this->button2);
			this->addmed->Controls->Add(this->datemed);
			this->addmed->Controls->Add(this->label6);
			this->addmed->Controls->Add(this->suppliernamemed);
			this->addmed->Controls->Add(this->namemed);
			this->addmed->Controls->Add(this->stockmed);
			this->addmed->Controls->Add(this->pricemed);
			this->addmed->Controls->Add(this->label5);
			this->addmed->Controls->Add(this->label4);
			this->addmed->Controls->Add(this->label3);
			this->addmed->Controls->Add(this->label2);
			this->addmed->Controls->Add(this->label1);
			this->addmed->Location = System::Drawing::Point(322, 69);
			this->addmed->Name = L"addmed";
			this->addmed->Size = System::Drawing::Size(1147, 623);
			this->addmed->TabIndex = 15;
			this->addmed->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::addmed_Paint);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::Color::Transparent;
			this->label7->ForeColor = System::Drawing::Color::Red;
			this->label7->Location = System::Drawing::Point(211, 190);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(0, 16);
			this->label7->TabIndex = 24;
			// 
			// button2
			// 
			this->button2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button2->BackColor = System::Drawing::Color::White;
			this->button2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button2->FlatAppearance->BorderSize = 0;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Cooper Black", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::SystemColors::Desktop;
			this->button2->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button2->Location = System::Drawing::Point(494, 535);
			this->button2->Margin = System::Windows::Forms::Padding(4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(159, 51);
			this->button2->TabIndex = 23;
			this->button2->Text = L"ADD ";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click_2);
			// 
			// datemed
			// 
			this->datemed->Location = System::Drawing::Point(439, 365);
			this->datemed->Mask = L"00/00/0000";
			this->datemed->Name = L"datemed";
			this->datemed->Size = System::Drawing::Size(198, 22);
			this->datemed->TabIndex = 21;
			this->datemed->ValidatingType = System::DateTime::typeid;
			this->datemed->MaskInputRejected += gcnew System::Windows::Forms::MaskInputRejectedEventHandler(this, &MyForm::maskedTextBox1_MaskInputRejected_1);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Century", 6, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::Red;
			this->label6->Location = System::Drawing::Point(215, 387);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(0, 15);
			this->label6->TabIndex = 20;
			// 
			// suppliernamemed
			// 
			this->suppliernamemed->Location = System::Drawing::Point(439, 454);
			this->suppliernamemed->Name = L"suppliernamemed";
			this->suppliernamemed->Size = System::Drawing::Size(198, 22);
			this->suppliernamemed->TabIndex = 19;
			// 
			// namemed
			// 
			this->namemed->Location = System::Drawing::Point(439, 161);
			this->namemed->Name = L"namemed";
			this->namemed->Size = System::Drawing::Size(198, 22);
			this->namemed->TabIndex = 18;
			this->namemed->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox3_TextChanged);
			// 
			// stockmed
			// 
			this->stockmed->Location = System::Drawing::Point(439, 230);
			this->stockmed->Name = L"stockmed";
			this->stockmed->Size = System::Drawing::Size(198, 22);
			this->stockmed->TabIndex = 17;
			// 
			// pricemed
			// 
			this->pricemed->Location = System::Drawing::Point(439, 294);
			this->pricemed->Name = L"pricemed";
			this->pricemed->Size = System::Drawing::Size(198, 22);
			this->pricemed->TabIndex = 16;
			this->pricemed->TextChanged += gcnew System::EventHandler(this, &MyForm::pricemed_TextChanged);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->Font = (gcnew System::Drawing::Font(L"Cooper Black", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label5->Location = System::Drawing::Point(213, 449);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(201, 26);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Supplier\'s Name";
			this->label5->Click += gcnew System::EventHandler(this, &MyForm::label5_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Cooper Black", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label4->Location = System::Drawing::Point(213, 361);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(145, 26);
			this->label4->TabIndex = 3;
			this->label4->Text = L"ExpiryDate";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Cooper Black", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label3->Location = System::Drawing::Point(213, 294);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(72, 26);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Price";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Cooper Black", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label2->Location = System::Drawing::Point(213, 230);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(81, 26);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Stock";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Cooper Black", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label1->Location = System::Drawing::Point(213, 161);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(78, 26);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Name";
			// 
			// home
			// 
			this->home->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->home->BackColor = System::Drawing::Color::Transparent;
			this->home->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"home.BackgroundImage")));
			this->home->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->home->ForeColor = System::Drawing::Color::Transparent;
			this->home->Location = System::Drawing::Point(322, 69);
			this->home->Name = L"home";
			this->home->Size = System::Drawing::Size(1147, 623);
			this->home->TabIndex = 18;
			// 
			// newcust
			// 
			this->newcust->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->newcust->BackColor = System::Drawing::SystemColors::Control;
			this->newcust->Controls->Add(this->purchasedproducts);
			this->newcust->Controls->Add(this->label8);
			this->newcust->Controls->Add(this->button1cust);
			this->newcust->Controls->Add(this->billdate);
			this->newcust->Controls->Add(this->label9);
			this->newcust->Controls->Add(this->billvalue);
			this->newcust->Controls->Add(this->custname);
			this->newcust->Controls->Add(this->custphone);
			this->newcust->Controls->Add(this->label10);
			this->newcust->Controls->Add(this->label11);
			this->newcust->Controls->Add(this->label12);
			this->newcust->Controls->Add(this->label13);
			this->newcust->Controls->Add(this->label14);
			this->newcust->Location = System::Drawing::Point(322, 69);
			this->newcust->Name = L"newcust";
			this->newcust->Size = System::Drawing::Size(1147, 623);
			this->newcust->TabIndex = 25;
			this->newcust->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::newcust_Paint);
			// 
			// purchasedproducts
			// 
			this->purchasedproducts->Location = System::Drawing::Point(439, 294);
			this->purchasedproducts->Name = L"purchasedproducts";
			this->purchasedproducts->Size = System::Drawing::Size(198, 52);
			this->purchasedproducts->TabIndex = 25;
			this->purchasedproducts->Text = L"";
			this->purchasedproducts->TextChanged += gcnew System::EventHandler(this, &MyForm::purchasedproducts_TextChanged);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::Color::Transparent;
			this->label8->ForeColor = System::Drawing::Color::Red;
			this->label8->Location = System::Drawing::Point(223, 187);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(0, 16);
			this->label8->TabIndex = 24;
			// 
			// button1cust
			// 
			this->button1cust->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button1cust->BackColor = System::Drawing::Color::White;
			this->button1cust->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button1cust->FlatAppearance->BorderSize = 0;
			this->button1cust->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1cust->Font = (gcnew System::Drawing::Font(L"Cooper Black", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1cust->ForeColor = System::Drawing::SystemColors::Desktop;
			this->button1cust->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button1cust->Location = System::Drawing::Point(494, 535);
			this->button1cust->Margin = System::Windows::Forms::Padding(4);
			this->button1cust->Name = L"button1cust";
			this->button1cust->Size = System::Drawing::Size(159, 51);
			this->button1cust->TabIndex = 23;
			this->button1cust->Text = L"ADD ";
			this->button1cust->UseVisualStyleBackColor = false;
			this->button1cust->Click += gcnew System::EventHandler(this, &MyForm::button1cust_Click);
			// 
			// billdate
			// 
			this->billdate->Location = System::Drawing::Point(439, 373);
			this->billdate->Mask = L"aaa aaa 00 00:00:00 0000";
			this->billdate->Name = L"billdate";
			this->billdate->Size = System::Drawing::Size(198, 22);
			this->billdate->TabIndex = 21;
			this->billdate->ValidatingType = System::DateTime::typeid;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Century", 6, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->ForeColor = System::Drawing::Color::Red;
			this->label9->Location = System::Drawing::Point(215, 395);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(190, 30);
			this->label9->TabIndex = 20;
			this->label9->Text = L"Format: Day Mon Date hh:mm:ss Year\r\nex: Sat Feb 22 12:34:11 2019";
			// 
			// billvalue
			// 
			this->billvalue->Location = System::Drawing::Point(439, 454);
			this->billvalue->Name = L"billvalue";
			this->billvalue->Size = System::Drawing::Size(198, 22);
			this->billvalue->TabIndex = 19;
			// 
			// custname
			// 
			this->custname->Location = System::Drawing::Point(439, 161);
			this->custname->Name = L"custname";
			this->custname->Size = System::Drawing::Size(198, 22);
			this->custname->TabIndex = 18;
			// 
			// custphone
			// 
			this->custphone->Location = System::Drawing::Point(439, 230);
			this->custphone->Name = L"custphone";
			this->custphone->Size = System::Drawing::Size(198, 22);
			this->custphone->TabIndex = 17;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->BackColor = System::Drawing::Color::Transparent;
			this->label10->Font = (gcnew System::Drawing::Font(L"Cooper Black", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label10->Location = System::Drawing::Point(213, 449);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(125, 26);
			this->label10->TabIndex = 4;
			this->label10->Text = L"Bill Value";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->BackColor = System::Drawing::Color::Transparent;
			this->label11->Font = (gcnew System::Drawing::Font(L"Cooper Black", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label11->Location = System::Drawing::Point(213, 369);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(112, 26);
			this->label11->TabIndex = 3;
			this->label11->Text = L"Bill Date";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->BackColor = System::Drawing::Color::Transparent;
			this->label12->Font = (gcnew System::Drawing::Font(L"Cooper Black", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label12->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label12->Location = System::Drawing::Point(213, 294);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(141, 52);
			this->label12->TabIndex = 2;
			this->label12->Text = L"Purchased \r\nProduct";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->BackColor = System::Drawing::Color::Transparent;
			this->label13->Font = (gcnew System::Drawing::Font(L"Cooper Black", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label13->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label13->Location = System::Drawing::Point(213, 230);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(85, 26);
			this->label13->TabIndex = 1;
			this->label13->Text = L"Phone";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->BackColor = System::Drawing::Color::Transparent;
			this->label14->Font = (gcnew System::Drawing::Font(L"Cooper Black", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label14->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label14->Location = System::Drawing::Point(213, 161);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(78, 26);
			this->label14->TabIndex = 0;
			this->label14->Text = L"Name";
			// 
			// searchp
			// 
			this->searchp->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->searchp->BackColor = System::Drawing::SystemColors::Control;
			this->searchp->Controls->Add(this->button1);
			this->searchp->Controls->Add(this->button3);
			this->searchp->Controls->Add(this->button4);
			this->searchp->Location = System::Drawing::Point(322, 69);
			this->searchp->Name = L"searchp";
			this->searchp->Size = System::Drawing::Size(1147, 623);
			this->searchp->TabIndex = 7;
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->button1->BackColor = System::Drawing::Color::White;
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Cooper Black", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::SystemColors::Desktop;
			this->button1->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button1->Location = System::Drawing::Point(329, 359);
			this->button1->Margin = System::Windows::Forms::Padding(4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(488, 78);
			this->button1->TabIndex = 11;
			this->button1->Text = L"SEARCH FOR PRODUCT";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click_6);
			// 
			// button3
			// 
			this->button3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->button3->BackColor = System::Drawing::Color::White;
			this->button3->FlatAppearance->BorderSize = 0;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Font = (gcnew System::Drawing::Font(L"Cooper Black", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->ForeColor = System::Drawing::SystemColors::Desktop;
			this->button3->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button3->Location = System::Drawing::Point(329, 270);
			this->button3->Margin = System::Windows::Forms::Padding(4);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(488, 72);
			this->button3->TabIndex = 12;
			this->button3->Text = L"SEARCH FOR SUPPLIER";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click_2);
			// 
			// button4
			// 
			this->button4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->button4->BackColor = System::Drawing::Color::White;
			this->button4->FlatAppearance->BorderSize = 0;
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button4->Font = (gcnew System::Drawing::Font(L"Cooper Black", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->ForeColor = System::Drawing::SystemColors::Desktop;
			this->button4->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button4->Location = System::Drawing::Point(329, 186);
			this->button4->Margin = System::Windows::Forms::Padding(4);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(488, 68);
			this->button4->TabIndex = 13;
			this->button4->Text = L"SEARCH FOR CUSTOMER";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click_1);
			// 
			// searchproduct
			// 
			this->searchproduct->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->searchproduct->BackColor = System::Drawing::SystemColors::Control;
			this->searchproduct->Controls->Add(this->button5);
			this->searchproduct->Controls->Add(this->button6);
			this->searchproduct->ForeColor = System::Drawing::Color::Transparent;
			this->searchproduct->Location = System::Drawing::Point(322, 69);
			this->searchproduct->Name = L"searchproduct";
			this->searchproduct->Size = System::Drawing::Size(1147, 623);
			this->searchproduct->TabIndex = 7;
			// 
			// button5
			// 
			this->button5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->button5->BackColor = System::Drawing::Color::White;
			this->button5->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button5->FlatAppearance->BorderSize = 0;
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button5->Font = (gcnew System::Drawing::Font(L"Cooper Black", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button5->ForeColor = System::Drawing::SystemColors::Desktop;
			this->button5->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button5->Location = System::Drawing::Point(329, 317);
			this->button5->Margin = System::Windows::Forms::Padding(4);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(488, 78);
			this->button5->TabIndex = 13;
			this->button5->Text = L"SEARCH FOR PRODUCT BY ID";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click_1);
			// 
			// button6
			// 
			this->button6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->button6->BackColor = System::Drawing::Color::White;
			this->button6->FlatAppearance->BorderSize = 0;
			this->button6->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button6->Font = (gcnew System::Drawing::Font(L"Cooper Black", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button6->ForeColor = System::Drawing::SystemColors::Desktop;
			this->button6->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button6->Location = System::Drawing::Point(329, 228);
			this->button6->Margin = System::Windows::Forms::Padding(4);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(488, 72);
			this->button6->TabIndex = 14;
			this->button6->Text = L"SEARCH FOR PRODUCT BY NAME";
			this->button6->UseVisualStyleBackColor = false;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// searchname
			// 
			this->searchname->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->searchname->BackColor = System::Drawing::SystemColors::Control;
			this->searchname->Controls->Add(this->button9);
			this->searchname->Controls->Add(this->panel1);
			this->searchname->Controls->Add(this->back);
			this->searchname->Controls->Add(this->namemedtxt);
			this->searchname->Controls->Add(this->label21);
			this->searchname->ForeColor = System::Drawing::Color::Transparent;
			this->searchname->Location = System::Drawing::Point(322, 69);
			this->searchname->Name = L"searchname";
			this->searchname->Size = System::Drawing::Size(1147, 623);
			this->searchname->TabIndex = 15;
			this->searchname->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::searchname_Paint);
			// 
			// button9
			// 
			this->button9->BackColor = System::Drawing::Color::Transparent;
			this->button9->FlatAppearance->BorderColor = System::Drawing::SystemColors::Control;
			this->button9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button9->ForeColor = System::Drawing::Color::Black;
			this->button9->Location = System::Drawing::Point(127, 129);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(102, 29);
			this->button9->TabIndex = 5;
			this->button9->Text = L"SEARCH";
			this->button9->UseVisualStyleBackColor = false;
			this->button9->Click += gcnew System::EventHandler(this, &MyForm::button9_Click);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->label24);
			this->panel1->Controls->Add(this->label25);
			this->panel1->Controls->Add(this->label26);
			this->panel1->Controls->Add(this->label27);
			this->panel1->Controls->Add(this->label28);
			this->panel1->Controls->Add(this->label29);
			this->panel1->Controls->Add(this->label30);
			this->panel1->Controls->Add(this->label31);
			this->panel1->Controls->Add(this->label32);
			this->panel1->Controls->Add(this->label33);
			this->panel1->Controls->Add(this->label34);
			this->panel1->Controls->Add(this->label35);
			this->panel1->Controls->Add(this->label36);
			this->panel1->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->panel1->Location = System::Drawing::Point(267, 123);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(626, 400);
			this->panel1->TabIndex = 4;
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->label24->Font = (gcnew System::Drawing::Font(L"Century", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label24->ForeColor = System::Drawing::Color::Black;
			this->label24->Location = System::Drawing::Point(255, 282);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(13, 18);
			this->label24->TabIndex = 13;
			this->label24->Text = L" ";
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->label25->Font = (gcnew System::Drawing::Font(L"Century", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label25->ForeColor = System::Drawing::Color::Black;
			this->label25->Location = System::Drawing::Point(255, 328);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(13, 18);
			this->label25->TabIndex = 12;
			this->label25->Text = L" ";
			// 
			// label26
			// 
			this->label26->AutoSize = true;
			this->label26->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->label26->Font = (gcnew System::Drawing::Font(L"Century", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label26->ForeColor = System::Drawing::Color::Black;
			this->label26->Location = System::Drawing::Point(255, 233);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(13, 18);
			this->label26->TabIndex = 11;
			this->label26->Text = L" ";
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->label27->Font = (gcnew System::Drawing::Font(L"Century", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label27->ForeColor = System::Drawing::Color::Black;
			this->label27->Location = System::Drawing::Point(255, 182);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(16, 21);
			this->label27->TabIndex = 10;
			this->label27->Text = L" ";
			// 
			// label28
			// 
			this->label28->AutoSize = true;
			this->label28->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->label28->Font = (gcnew System::Drawing::Font(L"Century", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label28->ForeColor = System::Drawing::Color::Black;
			this->label28->Location = System::Drawing::Point(255, 120);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(13, 18);
			this->label28->TabIndex = 9;
			this->label28->Text = L" ";
			// 
			// label29
			// 
			this->label29->AutoSize = true;
			this->label29->Font = (gcnew System::Drawing::Font(L"Century", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label29->ForeColor = System::Drawing::Color::Black;
			this->label29->Location = System::Drawing::Point(255, 68);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(13, 18);
			this->label29->TabIndex = 8;
			this->label29->Text = L" ";
			// 
			// label30
			// 
			this->label30->AutoSize = true;
			this->label30->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->label30->Font = (gcnew System::Drawing::Font(L"Century", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label30->ForeColor = System::Drawing::Color::Black;
			this->label30->Location = System::Drawing::Point(55, 281);
			this->label30->Name = L"label30";
			this->label30->Size = System::Drawing::Size(137, 18);
			this->label30->TabIndex = 7;
			this->label30->Text = L"EXPIRE DATE :";
			// 
			// label31
			// 
			this->label31->AutoSize = true;
			this->label31->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->label31->Font = (gcnew System::Drawing::Font(L"Century", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label31->ForeColor = System::Drawing::Color::Black;
			this->label31->Location = System::Drawing::Point(55, 327);
			this->label31->Name = L"label31";
			this->label31->Size = System::Drawing::Size(176, 18);
			this->label31->TabIndex = 6;
			this->label31->Text = L"SUPPLIER\'S NAME :";
			// 
			// label32
			// 
			this->label32->AutoSize = true;
			this->label32->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->label32->Font = (gcnew System::Drawing::Font(L"Century", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label32->ForeColor = System::Drawing::Color::Black;
			this->label32->Location = System::Drawing::Point(55, 232);
			this->label32->Name = L"label32";
			this->label32->Size = System::Drawing::Size(72, 18);
			this->label32->TabIndex = 4;
			this->label32->Text = L"PRICE :";
			// 
			// label33
			// 
			this->label33->AutoSize = true;
			this->label33->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->label33->Font = (gcnew System::Drawing::Font(L"Century", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label33->ForeColor = System::Drawing::Color::Black;
			this->label33->Location = System::Drawing::Point(55, 330);
			this->label33->Name = L"label33";
			this->label33->Size = System::Drawing::Size(0, 18);
			this->label33->TabIndex = 3;
			// 
			// label34
			// 
			this->label34->AutoSize = true;
			this->label34->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->label34->Font = (gcnew System::Drawing::Font(L"Century", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label34->ForeColor = System::Drawing::Color::Black;
			this->label34->Location = System::Drawing::Point(55, 181);
			this->label34->Name = L"label34";
			this->label34->Size = System::Drawing::Size(77, 18);
			this->label34->TabIndex = 2;
			this->label34->Text = L"STOCK :";
			// 
			// label35
			// 
			this->label35->AutoSize = true;
			this->label35->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->label35->Font = (gcnew System::Drawing::Font(L"Century", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label35->ForeColor = System::Drawing::Color::Black;
			this->label35->Location = System::Drawing::Point(55, 119);
			this->label35->Name = L"label35";
			this->label35->Size = System::Drawing::Size(70, 18);
			this->label35->TabIndex = 1;
			this->label35->Text = L"NAME :";
			// 
			// label36
			// 
			this->label36->AutoSize = true;
			this->label36->Font = (gcnew System::Drawing::Font(L"Century", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label36->ForeColor = System::Drawing::Color::Black;
			this->label36->Location = System::Drawing::Point(55, 67);
			this->label36->Name = L"label36";
			this->label36->Size = System::Drawing::Size(38, 18);
			this->label36->TabIndex = 0;
			this->label36->Text = L"ID :";
			// 
			// back
			// 
			this->back->BackColor = System::Drawing::Color::Transparent;
			this->back->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"back.BackgroundImage")));
			this->back->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->back->Cursor = System::Windows::Forms::Cursors::Hand;
			this->back->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->back->Location = System::Drawing::Point(28, 36);
			this->back->Name = L"back";
			this->back->Size = System::Drawing::Size(54, 37);
			this->back->TabIndex = 2;
			this->back->UseVisualStyleBackColor = false;
			this->back->Click += gcnew System::EventHandler(this, &MyForm::button8_Click);
			// 
			// namemedtxt
			// 
			this->namemedtxt->Location = System::Drawing::Point(123, 93);
			this->namemedtxt->Name = L"namemedtxt";
			this->namemedtxt->Size = System::Drawing::Size(111, 22);
			this->namemedtxt->TabIndex = 1;
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label21->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label21->ForeColor = System::Drawing::Color::Black;
			this->label21->Location = System::Drawing::Point(54, 96);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(59, 19);
			this->label21->TabIndex = 0;
			this->label21->Text = L"NAME";
			// 
			// productsearchid
			// 
			this->productsearchid->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->productsearchid->BackColor = System::Drawing::SystemColors::Control;
			this->productsearchid->Controls->Add(this->button8);
			this->productsearchid->Controls->Add(this->showproduct);
			this->productsearchid->Controls->Add(this->button7);
			this->productsearchid->Controls->Add(this->label15);
			this->productsearchid->Controls->Add(this->barsearch);
			this->productsearchid->ForeColor = System::Drawing::Color::Transparent;
			this->productsearchid->Location = System::Drawing::Point(322, 69);
			this->productsearchid->Name = L"productsearchid";
			this->productsearchid->Size = System::Drawing::Size(1147, 623);
			this->productsearchid->TabIndex = 26;
			// 
			// button8
			// 
			this->button8->BackColor = System::Drawing::Color::Transparent;
			this->button8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button8.BackgroundImage")));
			this->button8->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button8->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button8->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button8->Location = System::Drawing::Point(21, 19);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(61, 32);
			this->button8->TabIndex = 4;
			this->button8->UseVisualStyleBackColor = false;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm::button8_Click_1);
			// 
			// showproduct
			// 
			this->showproduct->Controls->Add(this->meddate);
			this->showproduct->Controls->Add(this->medsuppliername);
			this->showproduct->Controls->Add(this->medprice);
			this->showproduct->Controls->Add(this->medstock);
			this->showproduct->Controls->Add(this->medname);
			this->showproduct->Controls->Add(this->medid);
			this->showproduct->Controls->Add(this->label23);
			this->showproduct->Controls->Add(this->label22);
			this->showproduct->Controls->Add(this->label20);
			this->showproduct->Controls->Add(this->label19);
			this->showproduct->Controls->Add(this->label18);
			this->showproduct->Controls->Add(this->label17);
			this->showproduct->Controls->Add(this->label16);
			this->showproduct->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->showproduct->Location = System::Drawing::Point(249, 109);
			this->showproduct->Name = L"showproduct";
			this->showproduct->Size = System::Drawing::Size(644, 403);
			this->showproduct->TabIndex = 3;
			// 
			// meddate
			// 
			this->meddate->AutoSize = true;
			this->meddate->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->meddate->Font = (gcnew System::Drawing::Font(L"Century", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->meddate->ForeColor = System::Drawing::Color::Black;
			this->meddate->Location = System::Drawing::Point(254, 278);
			this->meddate->Name = L"meddate";
			this->meddate->Size = System::Drawing::Size(13, 18);
			this->meddate->TabIndex = 13;
			this->meddate->Text = L" ";
			this->meddate->Click += gcnew System::EventHandler(this, &MyForm::label21_Click);
			// 
			// medsuppliername
			// 
			this->medsuppliername->AutoSize = true;
			this->medsuppliername->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->medsuppliername->Font = (gcnew System::Drawing::Font(L"Century", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->medsuppliername->ForeColor = System::Drawing::Color::Black;
			this->medsuppliername->Location = System::Drawing::Point(254, 324);
			this->medsuppliername->Name = L"medsuppliername";
			this->medsuppliername->Size = System::Drawing::Size(13, 18);
			this->medsuppliername->TabIndex = 12;
			this->medsuppliername->Text = L" ";
			this->medsuppliername->Click += gcnew System::EventHandler(this, &MyForm::label24_Click);
			// 
			// medprice
			// 
			this->medprice->AutoSize = true;
			this->medprice->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->medprice->Font = (gcnew System::Drawing::Font(L"Century", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->medprice->ForeColor = System::Drawing::Color::Black;
			this->medprice->Location = System::Drawing::Point(254, 229);
			this->medprice->Name = L"medprice";
			this->medprice->Size = System::Drawing::Size(13, 18);
			this->medprice->TabIndex = 11;
			this->medprice->Text = L" ";
			this->medprice->Click += gcnew System::EventHandler(this, &MyForm::label25_Click);
			// 
			// medstock
			// 
			this->medstock->AutoSize = true;
			this->medstock->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->medstock->Font = (gcnew System::Drawing::Font(L"Century", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->medstock->ForeColor = System::Drawing::Color::Black;
			this->medstock->Location = System::Drawing::Point(254, 178);
			this->medstock->Name = L"medstock";
			this->medstock->Size = System::Drawing::Size(16, 21);
			this->medstock->TabIndex = 10;
			this->medstock->Text = L" ";
			this->medstock->Click += gcnew System::EventHandler(this, &MyForm::label26_Click);
			// 
			// medname
			// 
			this->medname->AutoSize = true;
			this->medname->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->medname->Font = (gcnew System::Drawing::Font(L"Century", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->medname->ForeColor = System::Drawing::Color::Black;
			this->medname->Location = System::Drawing::Point(254, 116);
			this->medname->Name = L"medname";
			this->medname->Size = System::Drawing::Size(13, 18);
			this->medname->TabIndex = 9;
			this->medname->Text = L" ";
			this->medname->Click += gcnew System::EventHandler(this, &MyForm::label27_Click);
			// 
			// medid
			// 
			this->medid->AutoSize = true;
			this->medid->Font = (gcnew System::Drawing::Font(L"Century", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->medid->ForeColor = System::Drawing::Color::Black;
			this->medid->Location = System::Drawing::Point(254, 64);
			this->medid->Name = L"medid";
			this->medid->Size = System::Drawing::Size(13, 18);
			this->medid->TabIndex = 8;
			this->medid->Text = L" ";
			this->medid->Click += gcnew System::EventHandler(this, &MyForm::label28_Click);
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->label23->Font = (gcnew System::Drawing::Font(L"Century", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label23->ForeColor = System::Drawing::Color::Black;
			this->label23->Location = System::Drawing::Point(55, 281);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(137, 18);
			this->label23->TabIndex = 7;
			this->label23->Text = L"EXPIRE DATE :";
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->label22->Font = (gcnew System::Drawing::Font(L"Century", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label22->ForeColor = System::Drawing::Color::Black;
			this->label22->Location = System::Drawing::Point(55, 327);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(176, 18);
			this->label22->TabIndex = 6;
			this->label22->Text = L"SUPPLIER\'S NAME :";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->label20->Font = (gcnew System::Drawing::Font(L"Century", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label20->ForeColor = System::Drawing::Color::Black;
			this->label20->Location = System::Drawing::Point(55, 232);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(72, 18);
			this->label20->TabIndex = 4;
			this->label20->Text = L"PRICE :";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->label19->Font = (gcnew System::Drawing::Font(L"Century", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label19->ForeColor = System::Drawing::Color::Black;
			this->label19->Location = System::Drawing::Point(55, 330);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(0, 18);
			this->label19->TabIndex = 3;
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->label18->Font = (gcnew System::Drawing::Font(L"Century", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label18->ForeColor = System::Drawing::Color::Black;
			this->label18->Location = System::Drawing::Point(55, 181);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(77, 18);
			this->label18->TabIndex = 2;
			this->label18->Text = L"STOCK :";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->label17->Font = (gcnew System::Drawing::Font(L"Century", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label17->ForeColor = System::Drawing::Color::Black;
			this->label17->Location = System::Drawing::Point(55, 119);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(70, 18);
			this->label17->TabIndex = 1;
			this->label17->Text = L"NAME :";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Font = (gcnew System::Drawing::Font(L"Century", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label16->ForeColor = System::Drawing::Color::Black;
			this->label16->Location = System::Drawing::Point(55, 67);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(38, 18);
			this->label16->TabIndex = 0;
			this->label16->Text = L"ID :";
			// 
			// button7
			// 
			this->button7->BackColor = System::Drawing::Color::Transparent;
			this->button7->FlatAppearance->BorderColor = System::Drawing::SystemColors::Control;
			this->button7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button7->ForeColor = System::Drawing::Color::Black;
			this->button7->Location = System::Drawing::Point(127, 108);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(102, 29);
			this->button7->TabIndex = 2;
			this->button7->Text = L"SEARCH";
			this->button7->UseVisualStyleBackColor = false;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->BackColor = System::Drawing::SystemColors::Control;
			this->label15->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label15->ForeColor = System::Drawing::Color::Black;
			this->label15->Location = System::Drawing::Point(66, 66);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(31, 21);
			this->label15->TabIndex = 1;
			this->label15->Text = L"ID";
			// 
			// barsearch
			// 
			this->barsearch->Location = System::Drawing::Point(116, 65);
			this->barsearch->Name = L"barsearch";
			this->barsearch->Size = System::Drawing::Size(127, 22);
			this->barsearch->TabIndex = 0;
			this->barsearch->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// deletepro
			// 
			this->deletepro->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->deletepro->BackColor = System::Drawing::SystemColors::Control;
			this->deletepro->Controls->Add(this->button10);
			this->deletepro->Controls->Add(this->button11);
			this->deletepro->Controls->Add(this->button12);
			this->deletepro->ForeColor = System::Drawing::Color::Transparent;
			this->deletepro->Location = System::Drawing::Point(322, 69);
			this->deletepro->Name = L"deletepro";
			this->deletepro->Size = System::Drawing::Size(1147, 623);
			this->deletepro->TabIndex = 5;
			// 
			// button10
			// 
			this->button10->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->button10->BackColor = System::Drawing::Color::White;
			this->button10->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button10->FlatAppearance->BorderSize = 0;
			this->button10->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button10->Font = (gcnew System::Drawing::Font(L"Cooper Black", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button10->ForeColor = System::Drawing::SystemColors::Desktop;
			this->button10->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button10->Location = System::Drawing::Point(328, 208);
			this->button10->Margin = System::Windows::Forms::Padding(4);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(490, 58);
			this->button10->TabIndex = 10;
			this->button10->Text = L"DELETE CUSTOMER";
			this->button10->UseVisualStyleBackColor = false;
			this->button10->Click += gcnew System::EventHandler(this, &MyForm::button10_Click);
			// 
			// button11
			// 
			this->button11->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->button11->BackColor = System::Drawing::Color::White;
			this->button11->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button11->FlatAppearance->BorderSize = 0;
			this->button11->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button11->Font = (gcnew System::Drawing::Font(L"Cooper Black", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button11->ForeColor = System::Drawing::SystemColors::Desktop;
			this->button11->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button11->Location = System::Drawing::Point(328, 274);
			this->button11->Margin = System::Windows::Forms::Padding(4);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(490, 64);
			this->button11->TabIndex = 9;
			this->button11->Text = L"DELETE SUPPLIER";
			this->button11->UseVisualStyleBackColor = false;
			this->button11->Click += gcnew System::EventHandler(this, &MyForm::button11_Click);
			// 
			// button12
			// 
			this->button12->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->button12->BackColor = System::Drawing::Color::White;
			this->button12->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button12->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button12->FlatAppearance->BorderSize = 0;
			this->button12->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button12->Font = (gcnew System::Drawing::Font(L"Cooper Black", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button12->ForeColor = System::Drawing::SystemColors::Desktop;
			this->button12->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button12->Location = System::Drawing::Point(328, 346);
			this->button12->Margin = System::Windows::Forms::Padding(4);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(490, 72);
			this->button12->TabIndex = 8;
			this->button12->Text = L"DELETE PRODUCT";
			this->button12->UseVisualStyleBackColor = false;
			this->button12->Click += gcnew System::EventHandler(this, &MyForm::button12_Click);
			// 
			// deleteproduct
			// 
			this->deleteproduct->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->deleteproduct->BackColor = System::Drawing::SystemColors::Control;
			this->deleteproduct->Controls->Add(this->button13);
			this->deleteproduct->Controls->Add(this->button14);
			this->deleteproduct->Location = System::Drawing::Point(322, 69);
			this->deleteproduct->Name = L"deleteproduct";
			this->deleteproduct->Size = System::Drawing::Size(1147, 623);
			this->deleteproduct->TabIndex = 27;
			// 
			// button13
			// 
			this->button13->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->button13->BackColor = System::Drawing::Color::White;
			this->button13->FlatAppearance->BorderSize = 0;
			this->button13->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button13->Font = (gcnew System::Drawing::Font(L"Cooper Black", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button13->ForeColor = System::Drawing::SystemColors::Desktop;
			this->button13->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button13->Location = System::Drawing::Point(331, 317);
			this->button13->Margin = System::Windows::Forms::Padding(4);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(488, 72);
			this->button13->TabIndex = 14;
			this->button13->Text = L"DELETE PRODUCT BY NAME";
			this->button13->UseVisualStyleBackColor = false;
			this->button13->Click += gcnew System::EventHandler(this, &MyForm::button13_Click);
			// 
			// button14
			// 
			this->button14->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->button14->BackColor = System::Drawing::Color::White;
			this->button14->FlatAppearance->BorderSize = 0;
			this->button14->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button14->Font = (gcnew System::Drawing::Font(L"Cooper Black", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button14->ForeColor = System::Drawing::SystemColors::Desktop;
			this->button14->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button14->Location = System::Drawing::Point(329, 233);
			this->button14->Margin = System::Windows::Forms::Padding(4);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(488, 68);
			this->button14->TabIndex = 15;
			this->button14->Text = L"DELETE PRODUCT BY ID";
			this->button14->UseVisualStyleBackColor = false;
			this->button14->Click += gcnew System::EventHandler(this, &MyForm::button14_Click);
			// 
			// searchcustp
			// 
			this->searchcustp->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->searchcustp->BackColor = System::Drawing::SystemColors::Control;
			this->searchcustp->Controls->Add(this->button15);
			this->searchcustp->Controls->Add(this->button16);
			this->searchcustp->ForeColor = System::Drawing::Color::Transparent;
			this->searchcustp->Location = System::Drawing::Point(322, 69);
			this->searchcustp->Name = L"searchcustp";
			this->searchcustp->Size = System::Drawing::Size(1147, 623);
			this->searchcustp->TabIndex = 28;
			this->searchcustp->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::searchcustp_Paint);
			// 
			// button15
			// 
			this->button15->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->button15->BackColor = System::Drawing::Color::White;
			this->button15->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button15->FlatAppearance->BorderSize = 0;
			this->button15->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button15->Font = (gcnew System::Drawing::Font(L"Cooper Black", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button15->ForeColor = System::Drawing::SystemColors::Desktop;
			this->button15->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button15->Location = System::Drawing::Point(329, 317);
			this->button15->Margin = System::Windows::Forms::Padding(4);
			this->button15->Name = L"button15";
			this->button15->Size = System::Drawing::Size(488, 78);
			this->button15->TabIndex = 15;
			this->button15->Text = L"SEARCH FOR CUSTOMER BY PHONE";
			this->button15->UseVisualStyleBackColor = false;
			this->button15->Click += gcnew System::EventHandler(this, &MyForm::button15_Click);
			// 
			// button16
			// 
			this->button16->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->button16->BackColor = System::Drawing::Color::White;
			this->button16->FlatAppearance->BorderSize = 0;
			this->button16->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button16->Font = (gcnew System::Drawing::Font(L"Cooper Black", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button16->ForeColor = System::Drawing::SystemColors::Desktop;
			this->button16->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button16->Location = System::Drawing::Point(329, 228);
			this->button16->Margin = System::Windows::Forms::Padding(4);
			this->button16->Name = L"button16";
			this->button16->Size = System::Drawing::Size(488, 72);
			this->button16->TabIndex = 16;
			this->button16->Text = L"SEARCH FOR CUSTOMER BY ID";
			this->button16->UseVisualStyleBackColor = false;
			this->button16->Click += gcnew System::EventHandler(this, &MyForm::button16_Click);
			// 
			// searchcustidp
			// 
			this->searchcustidp->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->searchcustidp->BackColor = System::Drawing::SystemColors::Control;
			this->searchcustidp->Controls->Add(this->button17);
			this->searchcustidp->Controls->Add(this->panel3);
			this->searchcustidp->Controls->Add(this->button18);
			this->searchcustidp->Controls->Add(this->label50);
			this->searchcustidp->Controls->Add(this->textBox1);
			this->searchcustidp->ForeColor = System::Drawing::Color::Transparent;
			this->searchcustidp->Location = System::Drawing::Point(322, 69);
			this->searchcustidp->Name = L"searchcustidp";
			this->searchcustidp->Size = System::Drawing::Size(1147, 623);
			this->searchcustidp->TabIndex = 29;
			this->searchcustidp->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::searchcustidp_Paint);
			// 
			// button17
			// 
			this->button17->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button17.BackgroundImage")));
			this->button17->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button17->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button17->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button17->Location = System::Drawing::Point(21, 19);
			this->button17->Name = L"button17";
			this->button17->Size = System::Drawing::Size(61, 32);
			this->button17->TabIndex = 4;
			this->button17->UseVisualStyleBackColor = true;
			this->button17->Click += gcnew System::EventHandler(this, &MyForm::button17_Click);
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->label52);
			this->panel3->Controls->Add(this->label51);
			this->panel3->Controls->Add(this->label37);
			this->panel3->Controls->Add(this->label38);
			this->panel3->Controls->Add(this->label39);
			this->panel3->Controls->Add(this->label40);
			this->panel3->Controls->Add(this->label41);
			this->panel3->Controls->Add(this->label42);
			this->panel3->Controls->Add(this->label43);
			this->panel3->Controls->Add(this->label44);
			this->panel3->Controls->Add(this->label45);
			this->panel3->Controls->Add(this->label46);
			this->panel3->Controls->Add(this->label47);
			this->panel3->Controls->Add(this->label48);
			this->panel3->Controls->Add(this->label49);
			this->panel3->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->panel3->Location = System::Drawing::Point(249, 108);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(837, 505);
			this->panel3->TabIndex = 3;
			this->panel3->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel3_Paint_1);
			// 
			// label52
			// 
			this->label52->AutoSize = true;
			this->label52->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->label52->Font = (gcnew System::Drawing::Font(L"Century", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label52->ForeColor = System::Drawing::Color::Black;
			this->label52->Location = System::Drawing::Point(297, 439);
			this->label52->Name = L"label52";
			this->label52->Size = System::Drawing::Size(0, 18);
			this->label52->TabIndex = 15;
			// 
			// label51
			// 
			this->label51->AutoSize = true;
			this->label51->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->label51->Font = (gcnew System::Drawing::Font(L"Century", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label51->ForeColor = System::Drawing::Color::Black;
			this->label51->Location = System::Drawing::Point(55, 422);
			this->label51->Name = L"label51";
			this->label51->Size = System::Drawing::Size(212, 36);
			this->label51->TabIndex = 14;
			this->label51->Text = L"VALUE OF \r\nPURCHASES PER WEEK";
			// 
			// label37
			// 
			this->label37->AutoSize = true;
			this->label37->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->label37->Font = (gcnew System::Drawing::Font(L"Century", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label37->ForeColor = System::Drawing::Color::Black;
			this->label37->Location = System::Drawing::Point(297, 325);
			this->label37->Name = L"label37";
			this->label37->Size = System::Drawing::Size(0, 18);
			this->label37->TabIndex = 13;
			// 
			// label38
			// 
			this->label38->AutoSize = true;
			this->label38->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->label38->Font = (gcnew System::Drawing::Font(L"Century", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label38->ForeColor = System::Drawing::Color::Black;
			this->label38->Location = System::Drawing::Point(296, 379);
			this->label38->Name = L"label38";
			this->label38->Size = System::Drawing::Size(0, 18);
			this->label38->TabIndex = 12;
			// 
			// label39
			// 
			this->label39->AutoSize = true;
			this->label39->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->label39->Font = (gcnew System::Drawing::Font(L"Century", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label39->ForeColor = System::Drawing::Color::Black;
			this->label39->Location = System::Drawing::Point(292, 250);
			this->label39->Name = L"label39";
			this->label39->Size = System::Drawing::Size(0, 18);
			this->label39->TabIndex = 11;
			// 
			// label40
			// 
			this->label40->AutoSize = true;
			this->label40->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->label40->Font = (gcnew System::Drawing::Font(L"Century", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label40->ForeColor = System::Drawing::Color::Black;
			this->label40->Location = System::Drawing::Point(292, 183);
			this->label40->Name = L"label40";
			this->label40->Size = System::Drawing::Size(0, 21);
			this->label40->TabIndex = 10;
			// 
			// label41
			// 
			this->label41->AutoSize = true;
			this->label41->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->label41->Font = (gcnew System::Drawing::Font(L"Century", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label41->ForeColor = System::Drawing::Color::Black;
			this->label41->Location = System::Drawing::Point(292, 124);
			this->label41->Name = L"label41";
			this->label41->Size = System::Drawing::Size(0, 18);
			this->label41->TabIndex = 9;
			// 
			// label42
			// 
			this->label42->AutoSize = true;
			this->label42->Font = (gcnew System::Drawing::Font(L"Century", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label42->ForeColor = System::Drawing::Color::Black;
			this->label42->Location = System::Drawing::Point(292, 68);
			this->label42->Name = L"label42";
			this->label42->Size = System::Drawing::Size(0, 18);
			this->label42->TabIndex = 8;
			// 
			// label43
			// 
			this->label43->AutoSize = true;
			this->label43->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->label43->Font = (gcnew System::Drawing::Font(L"Century", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label43->ForeColor = System::Drawing::Color::Black;
			this->label43->Location = System::Drawing::Point(55, 316);
			this->label43->Name = L"label43";
			this->label43->Size = System::Drawing::Size(98, 36);
			this->label43->TabIndex = 7;
			this->label43->Text = L"DATE OF\r\nLAST BILL";
			this->label43->Click += gcnew System::EventHandler(this, &MyForm::label43_Click);
			// 
			// label44
			// 
			this->label44->AutoSize = true;
			this->label44->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->label44->Font = (gcnew System::Drawing::Font(L"Century", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label44->ForeColor = System::Drawing::Color::Black;
			this->label44->Location = System::Drawing::Point(55, 381);
			this->label44->Name = L"label44";
			this->label44->Size = System::Drawing::Size(114, 18);
			this->label44->TabIndex = 6;
			this->label44->Text = L"BILL VALUE";
			// 
			// label45
			// 
			this->label45->AutoSize = true;
			this->label45->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->label45->Font = (gcnew System::Drawing::Font(L"Century", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label45->ForeColor = System::Drawing::Color::Black;
			this->label45->Location = System::Drawing::Point(55, 246);
			this->label45->Name = L"label45";
			this->label45->Size = System::Drawing::Size(117, 36);
			this->label45->TabIndex = 4;
			this->label45->Text = L"PURCHASED\r\nPRODUCTS\r\n";
			// 
			// label46
			// 
			this->label46->AutoSize = true;
			this->label46->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->label46->Font = (gcnew System::Drawing::Font(L"Century", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label46->ForeColor = System::Drawing::Color::Black;
			this->label46->Location = System::Drawing::Point(55, 379);
			this->label46->Name = L"label46";
			this->label46->Size = System::Drawing::Size(0, 18);
			this->label46->TabIndex = 3;
			// 
			// label47
			// 
			this->label47->AutoSize = true;
			this->label47->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->label47->Font = (gcnew System::Drawing::Font(L"Century", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label47->ForeColor = System::Drawing::Color::Black;
			this->label47->Location = System::Drawing::Point(55, 181);
			this->label47->Name = L"label47";
			this->label47->Size = System::Drawing::Size(67, 18);
			this->label47->TabIndex = 2;
			this->label47->Text = L"Phone :";
			// 
			// label48
			// 
			this->label48->AutoSize = true;
			this->label48->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->label48->Font = (gcnew System::Drawing::Font(L"Century", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label48->ForeColor = System::Drawing::Color::Black;
			this->label48->Location = System::Drawing::Point(55, 119);
			this->label48->Name = L"label48";
			this->label48->Size = System::Drawing::Size(70, 18);
			this->label48->TabIndex = 1;
			this->label48->Text = L"NAME :";
			// 
			// label49
			// 
			this->label49->AutoSize = true;
			this->label49->Font = (gcnew System::Drawing::Font(L"Century", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label49->ForeColor = System::Drawing::Color::Black;
			this->label49->Location = System::Drawing::Point(55, 67);
			this->label49->Name = L"label49";
			this->label49->Size = System::Drawing::Size(38, 18);
			this->label49->TabIndex = 0;
			this->label49->Text = L"ID :";
			// 
			// button18
			// 
			this->button18->BackColor = System::Drawing::Color::Transparent;
			this->button18->FlatAppearance->BorderColor = System::Drawing::SystemColors::Control;
			this->button18->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button18->ForeColor = System::Drawing::Color::Black;
			this->button18->Location = System::Drawing::Point(127, 108);
			this->button18->Name = L"button18";
			this->button18->Size = System::Drawing::Size(102, 29);
			this->button18->TabIndex = 2;
			this->button18->Text = L"SEARCH";
			this->button18->UseVisualStyleBackColor = false;
			this->button18->Click += gcnew System::EventHandler(this, &MyForm::button18_Click);
			// 
			// label50
			// 
			this->label50->AutoSize = true;
			this->label50->BackColor = System::Drawing::SystemColors::Control;
			this->label50->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label50->ForeColor = System::Drawing::Color::Black;
			this->label50->Location = System::Drawing::Point(66, 66);
			this->label50->Name = L"label50";
			this->label50->Size = System::Drawing::Size(31, 21);
			this->label50->TabIndex = 1;
			this->label50->Text = L"ID";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(116, 65);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(127, 22);
			this->textBox1->TabIndex = 0;
			// 
			// updatepanel
			// 
			this->updatepanel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->updatepanel->BackColor = System::Drawing::SystemColors::Control;
			this->updatepanel->Controls->Add(this->button20);
			this->updatepanel->Controls->Add(this->button19);
			this->updatepanel->Location = System::Drawing::Point(322, 69);
			this->updatepanel->Name = L"updatepanel";
			this->updatepanel->Size = System::Drawing::Size(1147, 623);
			this->updatepanel->TabIndex = 0;
			// 
			// button20
			// 
			this->button20->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->button20->BackColor = System::Drawing::Color::White;
			this->button20->Font = (gcnew System::Drawing::Font(L"Cooper Black", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button20->ForeColor = System::Drawing::SystemColors::Desktop;
			this->button20->Location = System::Drawing::Point(331, 324);
			this->button20->Name = L"button20";
			this->button20->Size = System::Drawing::Size(389, 76);
			this->button20->TabIndex = 1;
			this->button20->Text = L"UPDATE SUPPLIER";
			this->button20->UseVisualStyleBackColor = false;
			this->button20->Click += gcnew System::EventHandler(this, &MyForm::button20_Click);
			// 
			// button19
			// 
			this->button19->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->button19->BackColor = System::Drawing::Color::White;
			this->button19->Font = (gcnew System::Drawing::Font(L"Cooper Black", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button19->ForeColor = System::Drawing::SystemColors::Desktop;
			this->button19->Location = System::Drawing::Point(331, 225);
			this->button19->Name = L"button19";
			this->button19->Size = System::Drawing::Size(389, 75);
			this->button19->TabIndex = 0;
			this->button19->Text = L"UPDATE CUSTOMER";
			this->button19->UseVisualStyleBackColor = false;
			this->button19->Click += gcnew System::EventHandler(this, &MyForm::button19_Click);
			// 
			// updatecust
			// 
			this->updatecust->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->updatecust->BackColor = System::Drawing::SystemColors::Control;
			this->updatecust->Controls->Add(this->button22);
			this->updatecust->Controls->Add(this->button23);
			this->updatecust->Location = System::Drawing::Point(322, 69);
			this->updatecust->Name = L"updatecust";
			this->updatecust->Size = System::Drawing::Size(1147, 623);
			this->updatecust->TabIndex = 6;
			// 
			// button22
			// 
			this->button22->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->button22->BackColor = System::Drawing::Color::White;
			this->button22->FlatAppearance->BorderSize = 0;
			this->button22->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button22->Font = (gcnew System::Drawing::Font(L"Cooper Black", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button22->ForeColor = System::Drawing::SystemColors::Desktop;
			this->button22->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button22->Location = System::Drawing::Point(329, 317);
			this->button22->Margin = System::Windows::Forms::Padding(4);
			this->button22->Name = L"button22";
			this->button22->Size = System::Drawing::Size(488, 72);
			this->button22->TabIndex = 13;
			this->button22->Text = L"UPDATE CUSTOMER BY PHONE";
			this->button22->UseVisualStyleBackColor = false;
			this->button22->Click += gcnew System::EventHandler(this, &MyForm::button22_Click_1);
			// 
			// button23
			// 
			this->button23->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->button23->BackColor = System::Drawing::Color::White;
			this->button23->FlatAppearance->BorderSize = 0;
			this->button23->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button23->Font = (gcnew System::Drawing::Font(L"Cooper Black", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button23->ForeColor = System::Drawing::SystemColors::Desktop;
			this->button23->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button23->Location = System::Drawing::Point(329, 233);
			this->button23->Margin = System::Windows::Forms::Padding(4);
			this->button23->Name = L"button23";
			this->button23->Size = System::Drawing::Size(488, 68);
			this->button23->TabIndex = 14;
			this->button23->Text = L"UPDATE CUSTOMER BY ID";
			this->button23->UseVisualStyleBackColor = false;
			this->button23->Click += gcnew System::EventHandler(this, &MyForm::button23_Click);
			// 
			// updatesuppid
			// 
			this->updatesuppid->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->updatesuppid->BackColor = System::Drawing::SystemColors::Control;
			this->updatesuppid->Controls->Add(this->button60);
			this->updatesuppid->Controls->Add(this->label99);
			this->updatesuppid->Controls->Add(this->label97);
			this->updatesuppid->Controls->Add(this->button46);
			this->updatesuppid->Controls->Add(this->textBox17);
			this->updatesuppid->Controls->Add(this->button47);
			this->updatesuppid->Controls->Add(this->label93);
			this->updatesuppid->Controls->Add(this->textBox15);
			this->updatesuppid->Location = System::Drawing::Point(322, 69);
			this->updatesuppid->Name = L"updatesuppid";
			this->updatesuppid->Size = System::Drawing::Size(1147, 623);
			this->updatesuppid->TabIndex = 6;
			// 
			// button60
			// 
			this->button60->BackColor = System::Drawing::Color::Transparent;
			this->button60->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button60.BackgroundImage")));
			this->button60->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button60->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button60->ForeColor = System::Drawing::Color::Transparent;
			this->button60->Location = System::Drawing::Point(12, 9);
			this->button60->Name = L"button60";
			this->button60->Size = System::Drawing::Size(58, 32);
			this->button60->TabIndex = 37;
			this->button60->UseVisualStyleBackColor = false;
			this->button60->Click += gcnew System::EventHandler(this, &MyForm::button60_Click);
			// 
			// label99
			// 
			this->label99->AutoSize = true;
			this->label99->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label99->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->label99->Location = System::Drawing::Point(227, 43);
			this->label99->Name = L"label99";
			this->label99->Size = System::Drawing::Size(0, 22);
			this->label99->TabIndex = 15;
			// 
			// label97
			// 
			this->label97->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label97->AutoSize = true;
			this->label97->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label97->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->label97->Location = System::Drawing::Point(244, 349);
			this->label97->Name = L"label97";
			this->label97->Size = System::Drawing::Size(0, 20);
			this->label97->TabIndex = 14;
			// 
			// button46
			// 
			this->button46->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->button46->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->button46->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button46->Location = System::Drawing::Point(763, 294);
			this->button46->Name = L"button46";
			this->button46->Size = System::Drawing::Size(163, 45);
			this->button46->TabIndex = 12;
			this->button46->Text = L"UPDATE";
			this->button46->UseVisualStyleBackColor = false;
			this->button46->Click += gcnew System::EventHandler(this, &MyForm::button46_Click);
			// 
			// textBox17
			// 
			this->textBox17->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->textBox17->BackColor = System::Drawing::Color::LightGray;
			this->textBox17->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox17->Location = System::Drawing::Point(243, 294);
			this->textBox17->Multiline = true;
			this->textBox17->Name = L"textBox17";
			this->textBox17->Size = System::Drawing::Size(503, 46);
			this->textBox17->TabIndex = 11;
			this->textBox17->Text = L"New Product ";
			this->textBox17->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// button47
			// 
			this->button47->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button47->ForeColor = System::Drawing::Color::Black;
			this->button47->Location = System::Drawing::Point(94, 106);
			this->button47->Name = L"button47";
			this->button47->Size = System::Drawing::Size(105, 36);
			this->button47->TabIndex = 10;
			this->button47->Text = L"SEARCH";
			this->button47->UseVisualStyleBackColor = true;
			this->button47->Click += gcnew System::EventHandler(this, &MyForm::button47_Click);
			// 
			// label93
			// 
			this->label93->AutoSize = true;
			this->label93->Font = (gcnew System::Drawing::Font(L"Century", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label93->ForeColor = System::Drawing::Color::Black;
			this->label93->Location = System::Drawing::Point(26, 54);
			this->label93->Name = L"label93";
			this->label93->Size = System::Drawing::Size(56, 39);
			this->label93->TabIndex = 5;
			this->label93->Text = L"ID";
			// 
			// textBox15
			// 
			this->textBox15->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->textBox15->Location = System::Drawing::Point(94, 68);
			this->textBox15->Name = L"textBox15";
			this->textBox15->Size = System::Drawing::Size(135, 22);
			this->textBox15->TabIndex = 4;
			// 
			// searchcustphone
			// 
			this->searchcustphone->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->searchcustphone->BackColor = System::Drawing::SystemColors::Control;
			this->searchcustphone->Controls->Add(this->button25);
			this->searchcustphone->Controls->Add(this->panel12);
			this->searchcustphone->Controls->Add(this->button26);
			this->searchcustphone->Controls->Add(this->label68);
			this->searchcustphone->Controls->Add(this->textBox6);
			this->searchcustphone->ForeColor = System::Drawing::Color::Transparent;
			this->searchcustphone->Location = System::Drawing::Point(320, 69);
			this->searchcustphone->Name = L"searchcustphone";
			this->searchcustphone->Size = System::Drawing::Size(1147, 623);
			this->searchcustphone->TabIndex = 30;
			this->searchcustphone->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::updatecustphone_Paint);
			// 
			// button25
			// 
			this->button25->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button25.BackgroundImage")));
			this->button25->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button25->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button25->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button25->Location = System::Drawing::Point(21, 19);
			this->button25->Name = L"button25";
			this->button25->Size = System::Drawing::Size(61, 32);
			this->button25->TabIndex = 4;
			this->button25->UseVisualStyleBackColor = true;
			this->button25->Click += gcnew System::EventHandler(this, &MyForm::button25_Click);
			// 
			// panel12
			// 
			this->panel12->Controls->Add(this->label53);
			this->panel12->Controls->Add(this->label54);
			this->panel12->Controls->Add(this->label55);
			this->panel12->Controls->Add(this->label56);
			this->panel12->Controls->Add(this->label57);
			this->panel12->Controls->Add(this->label58);
			this->panel12->Controls->Add(this->label59);
			this->panel12->Controls->Add(this->label60);
			this->panel12->Controls->Add(this->label61);
			this->panel12->Controls->Add(this->label62);
			this->panel12->Controls->Add(this->label63);
			this->panel12->Controls->Add(this->label64);
			this->panel12->Controls->Add(this->label65);
			this->panel12->Controls->Add(this->label66);
			this->panel12->Controls->Add(this->label67);
			this->panel12->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->panel12->Location = System::Drawing::Point(249, 108);
			this->panel12->Name = L"panel12";
			this->panel12->Size = System::Drawing::Size(837, 505);
			this->panel12->TabIndex = 3;
			// 
			// label53
			// 
			this->label53->AutoSize = true;
			this->label53->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->label53->Font = (gcnew System::Drawing::Font(L"Century", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label53->ForeColor = System::Drawing::Color::Black;
			this->label53->Location = System::Drawing::Point(297, 439);
			this->label53->Name = L"label53";
			this->label53->Size = System::Drawing::Size(0, 18);
			this->label53->TabIndex = 15;
			// 
			// label54
			// 
			this->label54->AutoSize = true;
			this->label54->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->label54->Font = (gcnew System::Drawing::Font(L"Century", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label54->ForeColor = System::Drawing::Color::Black;
			this->label54->Location = System::Drawing::Point(55, 422);
			this->label54->Name = L"label54";
			this->label54->Size = System::Drawing::Size(212, 36);
			this->label54->TabIndex = 14;
			this->label54->Text = L"VALUE OF \r\nPURCHASES PER WEEK";
			// 
			// label55
			// 
			this->label55->AutoSize = true;
			this->label55->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->label55->Font = (gcnew System::Drawing::Font(L"Century", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label55->ForeColor = System::Drawing::Color::Black;
			this->label55->Location = System::Drawing::Point(297, 325);
			this->label55->Name = L"label55";
			this->label55->Size = System::Drawing::Size(0, 18);
			this->label55->TabIndex = 13;
			// 
			// label56
			// 
			this->label56->AutoSize = true;
			this->label56->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->label56->Font = (gcnew System::Drawing::Font(L"Century", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label56->ForeColor = System::Drawing::Color::Black;
			this->label56->Location = System::Drawing::Point(296, 379);
			this->label56->Name = L"label56";
			this->label56->Size = System::Drawing::Size(0, 18);
			this->label56->TabIndex = 12;
			// 
			// label57
			// 
			this->label57->AutoSize = true;
			this->label57->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->label57->Font = (gcnew System::Drawing::Font(L"Century", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label57->ForeColor = System::Drawing::Color::Black;
			this->label57->Location = System::Drawing::Point(292, 250);
			this->label57->Name = L"label57";
			this->label57->Size = System::Drawing::Size(0, 18);
			this->label57->TabIndex = 11;
			// 
			// label58
			// 
			this->label58->AutoSize = true;
			this->label58->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->label58->Font = (gcnew System::Drawing::Font(L"Century", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label58->ForeColor = System::Drawing::Color::Black;
			this->label58->Location = System::Drawing::Point(292, 183);
			this->label58->Name = L"label58";
			this->label58->Size = System::Drawing::Size(0, 21);
			this->label58->TabIndex = 10;
			// 
			// label59
			// 
			this->label59->AutoSize = true;
			this->label59->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->label59->Font = (gcnew System::Drawing::Font(L"Century", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label59->ForeColor = System::Drawing::Color::Black;
			this->label59->Location = System::Drawing::Point(292, 124);
			this->label59->Name = L"label59";
			this->label59->Size = System::Drawing::Size(0, 18);
			this->label59->TabIndex = 9;
			// 
			// label60
			// 
			this->label60->AutoSize = true;
			this->label60->Font = (gcnew System::Drawing::Font(L"Century", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label60->ForeColor = System::Drawing::Color::Black;
			this->label60->Location = System::Drawing::Point(292, 68);
			this->label60->Name = L"label60";
			this->label60->Size = System::Drawing::Size(0, 18);
			this->label60->TabIndex = 8;
			// 
			// label61
			// 
			this->label61->AutoSize = true;
			this->label61->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->label61->Font = (gcnew System::Drawing::Font(L"Century", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label61->ForeColor = System::Drawing::Color::Black;
			this->label61->Location = System::Drawing::Point(55, 316);
			this->label61->Name = L"label61";
			this->label61->Size = System::Drawing::Size(98, 36);
			this->label61->TabIndex = 7;
			this->label61->Text = L"DATE OF\r\nLAST BILL";
			// 
			// label62
			// 
			this->label62->AutoSize = true;
			this->label62->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->label62->Font = (gcnew System::Drawing::Font(L"Century", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label62->ForeColor = System::Drawing::Color::Black;
			this->label62->Location = System::Drawing::Point(55, 381);
			this->label62->Name = L"label62";
			this->label62->Size = System::Drawing::Size(114, 18);
			this->label62->TabIndex = 6;
			this->label62->Text = L"BILL VALUE";
			// 
			// label63
			// 
			this->label63->AutoSize = true;
			this->label63->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->label63->Font = (gcnew System::Drawing::Font(L"Century", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label63->ForeColor = System::Drawing::Color::Black;
			this->label63->Location = System::Drawing::Point(55, 246);
			this->label63->Name = L"label63";
			this->label63->Size = System::Drawing::Size(117, 36);
			this->label63->TabIndex = 4;
			this->label63->Text = L"PURCHASED\r\nPRODUCTS\r\n";
			// 
			// label64
			// 
			this->label64->AutoSize = true;
			this->label64->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->label64->Font = (gcnew System::Drawing::Font(L"Century", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label64->ForeColor = System::Drawing::Color::Black;
			this->label64->Location = System::Drawing::Point(55, 379);
			this->label64->Name = L"label64";
			this->label64->Size = System::Drawing::Size(0, 18);
			this->label64->TabIndex = 3;
			// 
			// label65
			// 
			this->label65->AutoSize = true;
			this->label65->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->label65->Font = (gcnew System::Drawing::Font(L"Century", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label65->ForeColor = System::Drawing::Color::Black;
			this->label65->Location = System::Drawing::Point(55, 181);
			this->label65->Name = L"label65";
			this->label65->Size = System::Drawing::Size(67, 18);
			this->label65->TabIndex = 2;
			this->label65->Text = L"Phone :";
			// 
			// label66
			// 
			this->label66->AutoSize = true;
			this->label66->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->label66->Font = (gcnew System::Drawing::Font(L"Century", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label66->ForeColor = System::Drawing::Color::Black;
			this->label66->Location = System::Drawing::Point(55, 119);
			this->label66->Name = L"label66";
			this->label66->Size = System::Drawing::Size(70, 18);
			this->label66->TabIndex = 1;
			this->label66->Text = L"NAME :";
			// 
			// label67
			// 
			this->label67->AutoSize = true;
			this->label67->Font = (gcnew System::Drawing::Font(L"Century", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label67->ForeColor = System::Drawing::Color::Black;
			this->label67->Location = System::Drawing::Point(55, 67);
			this->label67->Name = L"label67";
			this->label67->Size = System::Drawing::Size(38, 18);
			this->label67->TabIndex = 0;
			this->label67->Text = L"ID :";
			// 
			// button26
			// 
			this->button26->BackColor = System::Drawing::Color::Transparent;
			this->button26->FlatAppearance->BorderColor = System::Drawing::SystemColors::Control;
			this->button26->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button26->ForeColor = System::Drawing::Color::Black;
			this->button26->Location = System::Drawing::Point(127, 108);
			this->button26->Name = L"button26";
			this->button26->Size = System::Drawing::Size(102, 29);
			this->button26->TabIndex = 2;
			this->button26->Text = L"SEARCH";
			this->button26->UseVisualStyleBackColor = false;
			this->button26->Click += gcnew System::EventHandler(this, &MyForm::button26_Click);
			// 
			// label68
			// 
			this->label68->AutoSize = true;
			this->label68->BackColor = System::Drawing::SystemColors::Control;
			this->label68->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label68->ForeColor = System::Drawing::Color::Black;
			this->label68->Location = System::Drawing::Point(61, 66);
			this->label68->Name = L"label68";
			this->label68->Size = System::Drawing::Size(71, 21);
			this->label68->TabIndex = 1;
			this->label68->Text = L"PHONE";
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(143, 65);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(127, 22);
			this->textBox6->TabIndex = 0;
			// 
			// searchsupp
			// 
			this->searchsupp->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->searchsupp->BackColor = System::Drawing::SystemColors::Control;
			this->searchsupp->Controls->Add(this->button27);
			this->searchsupp->Controls->Add(this->button28);
			this->searchsupp->ForeColor = System::Drawing::Color::Transparent;
			this->searchsupp->Location = System::Drawing::Point(322, 69);
			this->searchsupp->Name = L"searchsupp";
			this->searchsupp->Size = System::Drawing::Size(1147, 623);
			this->searchsupp->TabIndex = 31;
			// 
			// button27
			// 
			this->button27->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->button27->BackColor = System::Drawing::Color::White;
			this->button27->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button27->FlatAppearance->BorderSize = 0;
			this->button27->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button27->Font = (gcnew System::Drawing::Font(L"Cooper Black", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button27->ForeColor = System::Drawing::SystemColors::Desktop;
			this->button27->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button27->Location = System::Drawing::Point(329, 317);
			this->button27->Margin = System::Windows::Forms::Padding(4);
			this->button27->Name = L"button27";
			this->button27->Size = System::Drawing::Size(488, 78);
			this->button27->TabIndex = 15;
			this->button27->Text = L"SEARCH FOR SUPPLIER BY NAME";
			this->button27->UseVisualStyleBackColor = false;
			this->button27->Click += gcnew System::EventHandler(this, &MyForm::button27_Click);
			// 
			// button28
			// 
			this->button28->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->button28->BackColor = System::Drawing::Color::White;
			this->button28->FlatAppearance->BorderSize = 0;
			this->button28->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button28->Font = (gcnew System::Drawing::Font(L"Cooper Black", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button28->ForeColor = System::Drawing::SystemColors::Desktop;
			this->button28->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button28->Location = System::Drawing::Point(329, 228);
			this->button28->Margin = System::Windows::Forms::Padding(4);
			this->button28->Name = L"button28";
			this->button28->Size = System::Drawing::Size(488, 72);
			this->button28->TabIndex = 16;
			this->button28->Text = L"SEARCH FOR SUPPLIER BY ID";
			this->button28->UseVisualStyleBackColor = false;
			this->button28->Click += gcnew System::EventHandler(this, &MyForm::button28_Click);
			// 
			// searchsupplierid
			// 
			this->searchsupplierid->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->searchsupplierid->BackColor = System::Drawing::SystemColors::Control;
			this->searchsupplierid->Controls->Add(this->button29);
			this->searchsupplierid->Controls->Add(this->panel14);
			this->searchsupplierid->Controls->Add(this->button30);
			this->searchsupplierid->Controls->Add(this->label84);
			this->searchsupplierid->Controls->Add(this->textBox7);
			this->searchsupplierid->ForeColor = System::Drawing::Color::Transparent;
			this->searchsupplierid->Location = System::Drawing::Point(322, 69);
			this->searchsupplierid->Name = L"searchsupplierid";
			this->searchsupplierid->Size = System::Drawing::Size(1147, 623);
			this->searchsupplierid->TabIndex = 32;
			// 
			// button29
			// 
			this->button29->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button29.BackgroundImage")));
			this->button29->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button29->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button29->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button29->Location = System::Drawing::Point(12, 9);
			this->button29->Name = L"button29";
			this->button29->Size = System::Drawing::Size(61, 32);
			this->button29->TabIndex = 5;
			this->button29->UseVisualStyleBackColor = true;
			this->button29->Click += gcnew System::EventHandler(this, &MyForm::button29_Click);
			// 
			// panel14
			// 
			this->panel14->Controls->Add(this->label73);
			this->panel14->Controls->Add(this->label74);
			this->panel14->Controls->Add(this->label75);
			this->panel14->Controls->Add(this->label76);
			this->panel14->Controls->Add(this->label79);
			this->panel14->Controls->Add(this->label81);
			this->panel14->Controls->Add(this->label82);
			this->panel14->Controls->Add(this->label83);
			this->panel14->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->panel14->Location = System::Drawing::Point(249, 108);
			this->panel14->Name = L"panel14";
			this->panel14->Size = System::Drawing::Size(837, 505);
			this->panel14->TabIndex = 3;
			// 
			// label73
			// 
			this->label73->AutoSize = true;
			this->label73->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->label73->Font = (gcnew System::Drawing::Font(L"Century", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label73->ForeColor = System::Drawing::Color::Black;
			this->label73->Location = System::Drawing::Point(292, 246);
			this->label73->Name = L"label73";
			this->label73->Size = System::Drawing::Size(0, 18);
			this->label73->TabIndex = 11;
			// 
			// label74
			// 
			this->label74->AutoSize = true;
			this->label74->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->label74->Font = (gcnew System::Drawing::Font(L"Century", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label74->ForeColor = System::Drawing::Color::Black;
			this->label74->Location = System::Drawing::Point(292, 183);
			this->label74->Name = L"label74";
			this->label74->Size = System::Drawing::Size(0, 21);
			this->label74->TabIndex = 10;
			// 
			// label75
			// 
			this->label75->AutoSize = true;
			this->label75->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->label75->Font = (gcnew System::Drawing::Font(L"Century", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label75->ForeColor = System::Drawing::Color::Black;
			this->label75->Location = System::Drawing::Point(292, 124);
			this->label75->Name = L"label75";
			this->label75->Size = System::Drawing::Size(0, 18);
			this->label75->TabIndex = 9;
			// 
			// label76
			// 
			this->label76->AutoSize = true;
			this->label76->Font = (gcnew System::Drawing::Font(L"Century", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label76->ForeColor = System::Drawing::Color::Black;
			this->label76->Location = System::Drawing::Point(292, 68);
			this->label76->Name = L"label76";
			this->label76->Size = System::Drawing::Size(0, 18);
			this->label76->TabIndex = 8;
			// 
			// label79
			// 
			this->label79->AutoSize = true;
			this->label79->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->label79->Font = (gcnew System::Drawing::Font(L"Century", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label79->ForeColor = System::Drawing::Color::Black;
			this->label79->Location = System::Drawing::Point(55, 246);
			this->label79->Name = L"label79";
			this->label79->Size = System::Drawing::Size(206, 18);
			this->label79->TabIndex = 4;
			this->label79->Text = L"SUPPLIED PRODUCTS: ";
			// 
			// label81
			// 
			this->label81->AutoSize = true;
			this->label81->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->label81->Font = (gcnew System::Drawing::Font(L"Century", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label81->ForeColor = System::Drawing::Color::Black;
			this->label81->Location = System::Drawing::Point(55, 181);
			this->label81->Name = L"label81";
			this->label81->Size = System::Drawing::Size(67, 18);
			this->label81->TabIndex = 2;
			this->label81->Text = L"Phone :";
			// 
			// label82
			// 
			this->label82->AutoSize = true;
			this->label82->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->label82->Font = (gcnew System::Drawing::Font(L"Century", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label82->ForeColor = System::Drawing::Color::Black;
			this->label82->Location = System::Drawing::Point(55, 119);
			this->label82->Name = L"label82";
			this->label82->Size = System::Drawing::Size(70, 18);
			this->label82->TabIndex = 1;
			this->label82->Text = L"NAME :";
			// 
			// label83
			// 
			this->label83->AutoSize = true;
			this->label83->Font = (gcnew System::Drawing::Font(L"Century", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label83->ForeColor = System::Drawing::Color::Black;
			this->label83->Location = System::Drawing::Point(55, 67);
			this->label83->Name = L"label83";
			this->label83->Size = System::Drawing::Size(38, 18);
			this->label83->TabIndex = 0;
			this->label83->Text = L"ID :";
			// 
			// button30
			// 
			this->button30->BackColor = System::Drawing::Color::Transparent;
			this->button30->FlatAppearance->BorderColor = System::Drawing::SystemColors::Control;
			this->button30->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button30->ForeColor = System::Drawing::Color::Black;
			this->button30->Location = System::Drawing::Point(127, 108);
			this->button30->Name = L"button30";
			this->button30->Size = System::Drawing::Size(102, 29);
			this->button30->TabIndex = 2;
			this->button30->Text = L"SEARCH";
			this->button30->UseVisualStyleBackColor = false;
			this->button30->Click += gcnew System::EventHandler(this, &MyForm::button30_Click);
			// 
			// label84
			// 
			this->label84->AutoSize = true;
			this->label84->BackColor = System::Drawing::SystemColors::Control;
			this->label84->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label84->ForeColor = System::Drawing::Color::Black;
			this->label84->Location = System::Drawing::Point(66, 66);
			this->label84->Name = L"label84";
			this->label84->Size = System::Drawing::Size(31, 21);
			this->label84->TabIndex = 1;
			this->label84->Text = L"ID";
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(116, 65);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(127, 22);
			this->textBox7->TabIndex = 0;
			// 
			// searchsuppliername
			// 
			this->searchsuppliername->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->searchsuppliername->BackColor = System::Drawing::SystemColors::Control;
			this->searchsuppliername->Controls->Add(this->button31);
			this->searchsuppliername->Controls->Add(this->panel16);
			this->searchsuppliername->Controls->Add(this->button32);
			this->searchsuppliername->Controls->Add(this->label86);
			this->searchsuppliername->Controls->Add(this->textBox8);
			this->searchsuppliername->ForeColor = System::Drawing::Color::Transparent;
			this->searchsuppliername->Location = System::Drawing::Point(322, 69);
			this->searchsuppliername->Name = L"searchsuppliername";
			this->searchsuppliername->Size = System::Drawing::Size(1147, 623);
			this->searchsuppliername->TabIndex = 33;
			// 
			// button31
			// 
			this->button31->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button31.BackgroundImage")));
			this->button31->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button31->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button31->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button31->Location = System::Drawing::Point(21, 19);
			this->button31->Name = L"button31";
			this->button31->Size = System::Drawing::Size(61, 32);
			this->button31->TabIndex = 4;
			this->button31->UseVisualStyleBackColor = true;
			this->button31->Click += gcnew System::EventHandler(this, &MyForm::button31_Click);
			// 
			// panel16
			// 
			this->panel16->Controls->Add(this->label69);
			this->panel16->Controls->Add(this->label70);
			this->panel16->Controls->Add(this->label71);
			this->panel16->Controls->Add(this->label72);
			this->panel16->Controls->Add(this->label77);
			this->panel16->Controls->Add(this->label78);
			this->panel16->Controls->Add(this->label80);
			this->panel16->Controls->Add(this->label85);
			this->panel16->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->panel16->Location = System::Drawing::Point(249, 108);
			this->panel16->Name = L"panel16";
			this->panel16->Size = System::Drawing::Size(837, 505);
			this->panel16->TabIndex = 3;
			this->panel16->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel16_Paint);
			// 
			// label69
			// 
			this->label69->AutoSize = true;
			this->label69->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->label69->Font = (gcnew System::Drawing::Font(L"Century", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label69->ForeColor = System::Drawing::Color::Black;
			this->label69->Location = System::Drawing::Point(292, 250);
			this->label69->Name = L"label69";
			this->label69->Size = System::Drawing::Size(0, 18);
			this->label69->TabIndex = 11;
			// 
			// label70
			// 
			this->label70->AutoSize = true;
			this->label70->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->label70->Font = (gcnew System::Drawing::Font(L"Century", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label70->ForeColor = System::Drawing::Color::Black;
			this->label70->Location = System::Drawing::Point(292, 182);
			this->label70->Name = L"label70";
			this->label70->Size = System::Drawing::Size(0, 21);
			this->label70->TabIndex = 10;
			// 
			// label71
			// 
			this->label71->AutoSize = true;
			this->label71->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->label71->Font = (gcnew System::Drawing::Font(L"Century", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label71->ForeColor = System::Drawing::Color::Black;
			this->label71->Location = System::Drawing::Point(292, 116);
			this->label71->Name = L"label71";
			this->label71->Size = System::Drawing::Size(0, 18);
			this->label71->TabIndex = 9;
			// 
			// label72
			// 
			this->label72->AutoSize = true;
			this->label72->Font = (gcnew System::Drawing::Font(L"Century", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label72->ForeColor = System::Drawing::Color::Black;
			this->label72->Location = System::Drawing::Point(292, 68);
			this->label72->Name = L"label72";
			this->label72->Size = System::Drawing::Size(0, 18);
			this->label72->TabIndex = 8;
			// 
			// label77
			// 
			this->label77->AutoSize = true;
			this->label77->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->label77->Font = (gcnew System::Drawing::Font(L"Century", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label77->ForeColor = System::Drawing::Color::Black;
			this->label77->Location = System::Drawing::Point(55, 246);
			this->label77->Name = L"label77";
			this->label77->Size = System::Drawing::Size(206, 18);
			this->label77->TabIndex = 4;
			this->label77->Text = L"SUPPLIED PRODUCTS: ";
			// 
			// label78
			// 
			this->label78->AutoSize = true;
			this->label78->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->label78->Font = (gcnew System::Drawing::Font(L"Century", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label78->ForeColor = System::Drawing::Color::Black;
			this->label78->Location = System::Drawing::Point(55, 181);
			this->label78->Name = L"label78";
			this->label78->Size = System::Drawing::Size(67, 18);
			this->label78->TabIndex = 2;
			this->label78->Text = L"Phone :";
			// 
			// label80
			// 
			this->label80->AutoSize = true;
			this->label80->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->label80->Font = (gcnew System::Drawing::Font(L"Century", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label80->ForeColor = System::Drawing::Color::Black;
			this->label80->Location = System::Drawing::Point(55, 119);
			this->label80->Name = L"label80";
			this->label80->Size = System::Drawing::Size(70, 18);
			this->label80->TabIndex = 1;
			this->label80->Text = L"NAME :";
			// 
			// label85
			// 
			this->label85->AutoSize = true;
			this->label85->Font = (gcnew System::Drawing::Font(L"Century", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label85->ForeColor = System::Drawing::Color::Black;
			this->label85->Location = System::Drawing::Point(55, 67);
			this->label85->Name = L"label85";
			this->label85->Size = System::Drawing::Size(38, 18);
			this->label85->TabIndex = 0;
			this->label85->Text = L"ID :";
			// 
			// button32
			// 
			this->button32->BackColor = System::Drawing::Color::Transparent;
			this->button32->FlatAppearance->BorderColor = System::Drawing::SystemColors::Control;
			this->button32->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button32->ForeColor = System::Drawing::Color::Black;
			this->button32->Location = System::Drawing::Point(127, 108);
			this->button32->Name = L"button32";
			this->button32->Size = System::Drawing::Size(102, 29);
			this->button32->TabIndex = 2;
			this->button32->Text = L"SEARCH";
			this->button32->UseVisualStyleBackColor = false;
			this->button32->Click += gcnew System::EventHandler(this, &MyForm::button32_Click);
			// 
			// label86
			// 
			this->label86->AutoSize = true;
			this->label86->BackColor = System::Drawing::SystemColors::Control;
			this->label86->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label86->ForeColor = System::Drawing::Color::Black;
			this->label86->Location = System::Drawing::Point(48, 65);
			this->label86->Name = L"label86";
			this->label86->Size = System::Drawing::Size(59, 21);
			this->label86->TabIndex = 1;
			this->label86->Text = L"NAME";
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(116, 65);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(127, 22);
			this->textBox8->TabIndex = 0;
			// 
			// addsupplier
			// 
			this->addsupplier->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->addsupplier->BackColor = System::Drawing::SystemColors::Control;
			this->addsupplier->Controls->Add(this->supplierproducts);
			this->addsupplier->Controls->Add(this->button57);
			this->addsupplier->Controls->Add(this->label122);
			this->addsupplier->Controls->Add(this->textBox23);
			this->addsupplier->Controls->Add(this->textBox21);
			this->addsupplier->Controls->Add(this->label121);
			this->addsupplier->Controls->Add(this->label120);
			this->addsupplier->Controls->Add(this->label119);
			this->addsupplier->Location = System::Drawing::Point(322, 69);
			this->addsupplier->Name = L"addsupplier";
			this->addsupplier->Size = System::Drawing::Size(1147, 623);
			this->addsupplier->TabIndex = 7;
			this->addsupplier->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::addsupplier_Paint);
			// 
			// supplierproducts
			// 
			this->supplierproducts->Location = System::Drawing::Point(344, 304);
			this->supplierproducts->Name = L"supplierproducts";
			this->supplierproducts->Size = System::Drawing::Size(159, 54);
			this->supplierproducts->TabIndex = 8;
			this->supplierproducts->Text = L"";
			// 
			// button57
			// 
			this->button57->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button57->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button57->Location = System::Drawing::Point(472, 406);
			this->button57->Name = L"button57";
			this->button57->Size = System::Drawing::Size(82, 25);
			this->button57->TabIndex = 7;
			this->button57->Text = L"ADD";
			this->button57->UseVisualStyleBackColor = true;
			this->button57->Click += gcnew System::EventHandler(this, &MyForm::button57_Click);
			// 
			// label122
			// 
			this->label122->AutoSize = true;
			this->label122->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label122->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->label122->Location = System::Drawing::Point(218, 212);
			this->label122->Name = L"label122";
			this->label122->Size = System::Drawing::Size(0, 20);
			this->label122->TabIndex = 6;
			// 
			// textBox23
			// 
			this->textBox23->Location = System::Drawing::Point(344, 250);
			this->textBox23->Name = L"textBox23";
			this->textBox23->Size = System::Drawing::Size(77, 22);
			this->textBox23->TabIndex = 5;
			// 
			// textBox21
			// 
			this->textBox21->Location = System::Drawing::Point(344, 189);
			this->textBox21->Name = L"textBox21";
			this->textBox21->Size = System::Drawing::Size(77, 22);
			this->textBox21->TabIndex = 3;
			// 
			// label121
			// 
			this->label121->AutoSize = true;
			this->label121->Font = (gcnew System::Drawing::Font(L"Century", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label121->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label121->Location = System::Drawing::Point(214, 306);
			this->label121->Name = L"label121";
			this->label121->Size = System::Drawing::Size(107, 42);
			this->label121->TabIndex = 2;
			this->label121->Text = L"SUPPLIED\r\nPRODUCTS\r\n";
			// 
			// label120
			// 
			this->label120->AutoSize = true;
			this->label120->Font = (gcnew System::Drawing::Font(L"Century", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label120->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label120->Location = System::Drawing::Point(214, 249);
			this->label120->Name = L"label120";
			this->label120->Size = System::Drawing::Size(59, 21);
			this->label120->TabIndex = 1;
			this->label120->Text = L"Phone";
			// 
			// label119
			// 
			this->label119->AutoSize = true;
			this->label119->Font = (gcnew System::Drawing::Font(L"Century", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label119->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label119->Location = System::Drawing::Point(214, 188);
			this->label119->Name = L"label119";
			this->label119->Size = System::Drawing::Size(64, 21);
			this->label119->TabIndex = 0;
			this->label119->Text = L"NAME";
			// 
			// fullreport
			// 
			this->fullreport->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->fullreport->BackColor = System::Drawing::SystemColors::Control;
			this->fullreport->Controls->Add(this->button56);
			this->fullreport->Controls->Add(this->listView1);
			this->fullreport->Location = System::Drawing::Point(322, 69);
			this->fullreport->Name = L"fullreport";
			this->fullreport->Size = System::Drawing::Size(1147, 623);
			this->fullreport->TabIndex = 8;
			// 
			// button56
			// 
			this->button56->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->button56->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button56->ForeColor = System::Drawing::Color::Black;
			this->button56->Location = System::Drawing::Point(510, 482);
			this->button56->Name = L"button56";
			this->button56->Size = System::Drawing::Size(105, 31);
			this->button56->TabIndex = 1;
			this->button56->Text = L"VIEW";
			this->button56->UseVisualStyleBackColor = true;
			this->button56->Click += gcnew System::EventHandler(this, &MyForm::button56_Click);
			// 
			// listView1
			// 
			this->listView1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->listView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(3) {
				this->columnHeader1, this->columnHeader2,
					this->columnHeader3
			});
			this->listView1->FullRowSelect = true;
			this->listView1->GridLines = true;
			this->listView1->HideSelection = false;
			this->listView1->Location = System::Drawing::Point(147, 29);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(853, 428);
			this->listView1->TabIndex = 0;
			this->listView1->UseCompatibleStateImageBehavior = false;
			this->listView1->View = System::Windows::Forms::View::Details;
			this->listView1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::listView1_SelectedIndexChanged);
			// 
			// columnHeader1
			// 
			this->columnHeader1->Text = L"NAME";
			this->columnHeader1->Width = 160;
			// 
			// columnHeader2
			// 
			this->columnHeader2->Text = L"STOCK";
			this->columnHeader2->Width = 80;
			// 
			// columnHeader3
			// 
			this->columnHeader3->Text = L"RECOMMENDATIONS";
			this->columnHeader3->Width = 200;
			// 
			// deletecust
			// 
			this->deletecust->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->deletecust->BackColor = System::Drawing::SystemColors::Control;
			this->deletecust->Controls->Add(this->button34);
			this->deletecust->Controls->Add(this->button33);
			this->deletecust->Cursor = System::Windows::Forms::Cursors::Hand;
			this->deletecust->Location = System::Drawing::Point(322, 69);
			this->deletecust->Name = L"deletecust";
			this->deletecust->Size = System::Drawing::Size(1147, 623);
			this->deletecust->TabIndex = 8;
			// 
			// button34
			// 
			this->button34->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->button34->BackColor = System::Drawing::Color::White;
			this->button34->Font = (gcnew System::Drawing::Font(L"Cooper Black", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button34->ForeColor = System::Drawing::SystemColors::Desktop;
			this->button34->Location = System::Drawing::Point(331, 316);
			this->button34->Name = L"button34";
			this->button34->Size = System::Drawing::Size(449, 59);
			this->button34->TabIndex = 1;
			this->button34->Text = L"delete customer by phone";
			this->button34->UseVisualStyleBackColor = false;
			this->button34->Click += gcnew System::EventHandler(this, &MyForm::button34_Click);
			// 
			// button33
			// 
			this->button33->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->button33->BackColor = System::Drawing::Color::White;
			this->button33->Font = (gcnew System::Drawing::Font(L"Cooper Black", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button33->ForeColor = System::Drawing::SystemColors::Desktop;
			this->button33->Location = System::Drawing::Point(331, 235);
			this->button33->Name = L"button33";
			this->button33->Size = System::Drawing::Size(449, 65);
			this->button33->TabIndex = 0;
			this->button33->Text = L"delete customer by id";
			this->button33->UseVisualStyleBackColor = false;
			this->button33->Click += gcnew System::EventHandler(this, &MyForm::button33_Click);
			// 
			// deletesup
			// 
			this->deletesup->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->deletesup->BackColor = System::Drawing::SystemColors::Control;
			this->deletesup->Controls->Add(this->button35);
			this->deletesup->Controls->Add(this->button36);
			this->deletesup->Location = System::Drawing::Point(322, 69);
			this->deletesup->Name = L"deletesup";
			this->deletesup->Size = System::Drawing::Size(1147, 623);
			this->deletesup->TabIndex = 9;
			this->deletesup->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::deletesup_Paint);
			// 
			// button35
			// 
			this->button35->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->button35->BackColor = System::Drawing::Color::White;
			this->button35->Font = (gcnew System::Drawing::Font(L"Cooper Black", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button35->ForeColor = System::Drawing::SystemColors::Desktop;
			this->button35->Location = System::Drawing::Point(346, 313);
			this->button35->Name = L"button35";
			this->button35->Size = System::Drawing::Size(455, 59);
			this->button35->TabIndex = 3;
			this->button35->Text = L"delete supplier by name";
			this->button35->UseVisualStyleBackColor = false;
			this->button35->Click += gcnew System::EventHandler(this, &MyForm::button35_Click_1);
			// 
			// button36
			// 
			this->button36->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->button36->BackColor = System::Drawing::Color::White;
			this->button36->Font = (gcnew System::Drawing::Font(L"Cooper Black", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button36->ForeColor = System::Drawing::SystemColors::Desktop;
			this->button36->Location = System::Drawing::Point(346, 231);
			this->button36->Name = L"button36";
			this->button36->Size = System::Drawing::Size(455, 65);
			this->button36->TabIndex = 2;
			this->button36->Text = L"delete supplier by id";
			this->button36->UseVisualStyleBackColor = false;
			this->button36->Click += gcnew System::EventHandler(this, &MyForm::button36_Click_1);
			// 
			// deletecustid
			// 
			this->deletecustid->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->deletecustid->BackColor = System::Drawing::SystemColors::Control;
			this->deletecustid->Controls->Add(this->button67);
			this->deletecustid->Controls->Add(this->label126);
			this->deletecustid->Controls->Add(this->button37);
			this->deletecustid->Controls->Add(this->label87);
			this->deletecustid->Controls->Add(this->textBox9);
			this->deletecustid->Location = System::Drawing::Point(322, 69);
			this->deletecustid->Name = L"deletecustid";
			this->deletecustid->Size = System::Drawing::Size(1147, 623);
			this->deletecustid->TabIndex = 9;
			this->deletecustid->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::deletecustid_Paint);
			// 
			// button67
			// 
			this->button67->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button67.BackgroundImage")));
			this->button67->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button67->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button67->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button67->Location = System::Drawing::Point(12, 22);
			this->button67->Name = L"button67";
			this->button67->Size = System::Drawing::Size(61, 32);
			this->button67->TabIndex = 15;
			this->button67->UseVisualStyleBackColor = true;
			this->button67->Click += gcnew System::EventHandler(this, &MyForm::button67_Click);
			// 
			// label126
			// 
			this->label126->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label126->AutoSize = true;
			this->label126->ForeColor = System::Drawing::Color::Red;
			this->label126->Location = System::Drawing::Point(689, 290);
			this->label126->Name = L"label126";
			this->label126->Size = System::Drawing::Size(0, 16);
			this->label126->TabIndex = 14;
			// 
			// button37
			// 
			this->button37->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button37->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button37->ForeColor = System::Drawing::Color::Black;
			this->button37->Location = System::Drawing::Point(515, 328);
			this->button37->Name = L"button37";
			this->button37->Size = System::Drawing::Size(97, 28);
			this->button37->TabIndex = 13;
			this->button37->Text = L"DELETE";
			this->button37->UseVisualStyleBackColor = true;
			this->button37->Click += gcnew System::EventHandler(this, &MyForm::button37_Click_2);
			// 
			// label87
			// 
			this->label87->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->label87->AutoEllipsis = true;
			this->label87->AutoSize = true;
			this->label87->BackColor = System::Drawing::Color::Transparent;
			this->label87->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label87->ForeColor = System::Drawing::Color::Black;
			this->label87->Location = System::Drawing::Point(468, 287);
			this->label87->Name = L"label87";
			this->label87->Size = System::Drawing::Size(31, 21);
			this->label87->TabIndex = 12;
			this->label87->Text = L"ID";
			this->label87->Click += gcnew System::EventHandler(this, &MyForm::label87_Click_1);
			// 
			// textBox9
			// 
			this->textBox9->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->textBox9->Location = System::Drawing::Point(522, 288);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(156, 22);
			this->textBox9->TabIndex = 11;
			// 
			// deletecustphone
			// 
			this->deletecustphone->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->deletecustphone->BackColor = System::Drawing::SystemColors::Control;
			this->deletecustphone->Controls->Add(this->button66);
			this->deletecustphone->Controls->Add(this->label127);
			this->deletecustphone->Controls->Add(this->button38);
			this->deletecustphone->Controls->Add(this->label88);
			this->deletecustphone->Controls->Add(this->textBox10);
			this->deletecustphone->Location = System::Drawing::Point(322, 69);
			this->deletecustphone->Name = L"deletecustphone";
			this->deletecustphone->Size = System::Drawing::Size(1147, 623);
			this->deletecustphone->TabIndex = 9;
			this->deletecustphone->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::deletecustphone_Paint);
			// 
			// button66
			// 
			this->button66->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button66.BackgroundImage")));
			this->button66->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button66->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button66->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button66->Location = System::Drawing::Point(26, 22);
			this->button66->Name = L"button66";
			this->button66->Size = System::Drawing::Size(61, 32);
			this->button66->TabIndex = 18;
			this->button66->UseVisualStyleBackColor = true;
			this->button66->Click += gcnew System::EventHandler(this, &MyForm::button66_Click);
			// 
			// label127
			// 
			this->label127->AutoSize = true;
			this->label127->BackColor = System::Drawing::Color::Transparent;
			this->label127->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label127->ForeColor = System::Drawing::Color::Red;
			this->label127->Location = System::Drawing::Point(684, 270);
			this->label127->Name = L"label127";
			this->label127->Size = System::Drawing::Size(0, 16);
			this->label127->TabIndex = 17;
			// 
			// button38
			// 
			this->button38->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button38->AutoSize = true;
			this->button38->BackColor = System::Drawing::Color::Transparent;
			this->button38->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button38->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button38->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button38->Location = System::Drawing::Point(518, 304);
			this->button38->Name = L"button38";
			this->button38->Size = System::Drawing::Size(119, 32);
			this->button38->TabIndex = 16;
			this->button38->Text = L"DELETE";
			this->button38->UseVisualStyleBackColor = false;
			this->button38->Click += gcnew System::EventHandler(this, &MyForm::button38_Click);
			// 
			// label88
			// 
			this->label88->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->label88->AutoEllipsis = true;
			this->label88->AutoSize = true;
			this->label88->BackColor = System::Drawing::Color::Transparent;
			this->label88->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label88->ForeColor = System::Drawing::Color::Black;
			this->label88->Location = System::Drawing::Point(442, 264);
			this->label88->Name = L"label88";
			this->label88->Size = System::Drawing::Size(71, 21);
			this->label88->TabIndex = 15;
			this->label88->Text = L"PHONE";
			// 
			// textBox10
			// 
			this->textBox10->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->textBox10->Location = System::Drawing::Point(522, 265);
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(156, 22);
			this->textBox10->TabIndex = 14;
			// 
			// deletesupplierid
			// 
			this->deletesupplierid->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->deletesupplierid->BackColor = System::Drawing::SystemColors::Control;
			this->deletesupplierid->Controls->Add(this->button62);
			this->deletesupplierid->Controls->Add(this->label118);
			this->deletesupplierid->Controls->Add(this->button39);
			this->deletesupplierid->Controls->Add(this->label89);
			this->deletesupplierid->Controls->Add(this->textBox11);
			this->deletesupplierid->Location = System::Drawing::Point(322, 69);
			this->deletesupplierid->Name = L"deletesupplierid";
			this->deletesupplierid->Size = System::Drawing::Size(1147, 623);
			this->deletesupplierid->TabIndex = 9;
			// 
			// button62
			// 
			this->button62->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button62.BackgroundImage")));
			this->button62->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button62->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button62->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button62->Location = System::Drawing::Point(26, 22);
			this->button62->Name = L"button62";
			this->button62->Size = System::Drawing::Size(61, 32);
			this->button62->TabIndex = 18;
			this->button62->UseVisualStyleBackColor = true;
			this->button62->Click += gcnew System::EventHandler(this, &MyForm::button62_Click);
			// 
			// label118
			// 
			this->label118->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label118->AutoSize = true;
			this->label118->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label118->ForeColor = System::Drawing::Color::Black;
			this->label118->Location = System::Drawing::Point(688, 260);
			this->label118->Name = L"label118";
			this->label118->Size = System::Drawing::Size(0, 20);
			this->label118->TabIndex = 17;
			// 
			// button39
			// 
			this->button39->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button39->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button39->ForeColor = System::Drawing::Color::Black;
			this->button39->Location = System::Drawing::Point(522, 307);
			this->button39->Name = L"button39";
			this->button39->Size = System::Drawing::Size(102, 27);
			this->button39->TabIndex = 16;
			this->button39->Text = L"DELETE";
			this->button39->UseVisualStyleBackColor = true;
			this->button39->Click += gcnew System::EventHandler(this, &MyForm::button39_Click);
			// 
			// label89
			// 
			this->label89->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->label89->AutoEllipsis = true;
			this->label89->AutoSize = true;
			this->label89->BackColor = System::Drawing::Color::Transparent;
			this->label89->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label89->ForeColor = System::Drawing::Color::Black;
			this->label89->Location = System::Drawing::Point(467, 255);
			this->label89->Name = L"label89";
			this->label89->Size = System::Drawing::Size(31, 21);
			this->label89->TabIndex = 15;
			this->label89->Text = L"ID";
			// 
			// textBox11
			// 
			this->textBox11->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->textBox11->Location = System::Drawing::Point(522, 257);
			this->textBox11->Name = L"textBox11";
			this->textBox11->Size = System::Drawing::Size(156, 22);
			this->textBox11->TabIndex = 14;
			// 
			// deletesuppliername
			// 
			this->deletesuppliername->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->deletesuppliername->BackColor = System::Drawing::SystemColors::Control;
			this->deletesuppliername->Controls->Add(this->button63);
			this->deletesuppliername->Controls->Add(this->label123);
			this->deletesuppliername->Controls->Add(this->button40);
			this->deletesuppliername->Controls->Add(this->label90);
			this->deletesuppliername->Controls->Add(this->textBox12);
			this->deletesuppliername->Location = System::Drawing::Point(322, 69);
			this->deletesuppliername->Name = L"deletesuppliername";
			this->deletesuppliername->Size = System::Drawing::Size(1147, 623);
			this->deletesuppliername->TabIndex = 9;
			// 
			// button63
			// 
			this->button63->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button63.BackgroundImage")));
			this->button63->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button63->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button63->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button63->Location = System::Drawing::Point(26, 22);
			this->button63->Name = L"button63";
			this->button63->Size = System::Drawing::Size(61, 32);
			this->button63->TabIndex = 18;
			this->button63->UseVisualStyleBackColor = true;
			this->button63->Click += gcnew System::EventHandler(this, &MyForm::button63_Click);
			// 
			// label123
			// 
			this->label123->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label123->AutoSize = true;
			this->label123->BackColor = System::Drawing::Color::Transparent;
			this->label123->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label123->ForeColor = System::Drawing::Color::Red;
			this->label123->Location = System::Drawing::Point(692, 267);
			this->label123->Name = L"label123";
			this->label123->Size = System::Drawing::Size(0, 20);
			this->label123->TabIndex = 17;
			this->label123->Click += gcnew System::EventHandler(this, &MyForm::label123_Click);
			// 
			// button40
			// 
			this->button40->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button40->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button40->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button40->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button40->Location = System::Drawing::Point(506, 309);
			this->button40->Name = L"button40";
			this->button40->Size = System::Drawing::Size(92, 31);
			this->button40->TabIndex = 16;
			this->button40->Text = L"DELETE";
			this->button40->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button40->UseVisualStyleBackColor = true;
			this->button40->Click += gcnew System::EventHandler(this, &MyForm::button40_Click);
			// 
			// label90
			// 
			this->label90->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->label90->AutoEllipsis = true;
			this->label90->AutoSize = true;
			this->label90->BackColor = System::Drawing::Color::Transparent;
			this->label90->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label90->ForeColor = System::Drawing::Color::Black;
			this->label90->Location = System::Drawing::Point(449, 266);
			this->label90->Name = L"label90";
			this->label90->Size = System::Drawing::Size(59, 21);
			this->label90->TabIndex = 15;
			this->label90->Text = L"NAME";
			// 
			// textBox12
			// 
			this->textBox12->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->textBox12->Location = System::Drawing::Point(522, 265);
			this->textBox12->Name = L"textBox12";
			this->textBox12->Size = System::Drawing::Size(156, 22);
			this->textBox12->TabIndex = 14;
			// 
			// deleteproductname
			// 
			this->deleteproductname->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->deleteproductname->BackColor = System::Drawing::SystemColors::Control;
			this->deleteproductname->Controls->Add(this->button64);
			this->deleteproductname->Controls->Add(this->label125);
			this->deleteproductname->Controls->Add(this->button42);
			this->deleteproductname->Controls->Add(this->label92);
			this->deleteproductname->Controls->Add(this->textBox14);
			this->deleteproductname->Location = System::Drawing::Point(322, 69);
			this->deleteproductname->Name = L"deleteproductname";
			this->deleteproductname->Size = System::Drawing::Size(1147, 623);
			this->deleteproductname->TabIndex = 34;
			// 
			// button64
			// 
			this->button64->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button64.BackgroundImage")));
			this->button64->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button64->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button64->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button64->Location = System::Drawing::Point(21, 19);
			this->button64->Name = L"button64";
			this->button64->Size = System::Drawing::Size(61, 32);
			this->button64->TabIndex = 18;
			this->button64->UseVisualStyleBackColor = true;
			this->button64->Click += gcnew System::EventHandler(this, &MyForm::button64_Click);
			// 
			// label125
			// 
			this->label125->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label125->AutoSize = true;
			this->label125->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label125->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->label125->Location = System::Drawing::Point(689, 268);
			this->label125->Name = L"label125";
			this->label125->Size = System::Drawing::Size(0, 18);
			this->label125->TabIndex = 17;
			// 
			// button42
			// 
			this->button42->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button42->BackColor = System::Drawing::Color::Transparent;
			this->button42->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button42->Location = System::Drawing::Point(525, 299);
			this->button42->Name = L"button42";
			this->button42->Size = System::Drawing::Size(90, 37);
			this->button42->TabIndex = 16;
			this->button42->Text = L"DELETE";
			this->button42->UseVisualStyleBackColor = false;
			this->button42->Click += gcnew System::EventHandler(this, &MyForm::button42_Click_1);
			// 
			// label92
			// 
			this->label92->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->label92->AutoEllipsis = true;
			this->label92->AutoSize = true;
			this->label92->BackColor = System::Drawing::Color::Transparent;
			this->label92->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label92->ForeColor = System::Drawing::Color::Black;
			this->label92->Location = System::Drawing::Point(456, 266);
			this->label92->Name = L"label92";
			this->label92->Size = System::Drawing::Size(59, 21);
			this->label92->TabIndex = 15;
			this->label92->Text = L"NAME";
			// 
			// textBox14
			// 
			this->textBox14->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->textBox14->Location = System::Drawing::Point(522, 265);
			this->textBox14->Name = L"textBox14";
			this->textBox14->Size = System::Drawing::Size(156, 22);
			this->textBox14->TabIndex = 14;
			// 
			// deleteproductid
			// 
			this->deleteproductid->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->deleteproductid->BackColor = System::Drawing::SystemColors::Control;
			this->deleteproductid->Controls->Add(this->button65);
			this->deleteproductid->Controls->Add(this->label124);
			this->deleteproductid->Controls->Add(this->button41);
			this->deleteproductid->Controls->Add(this->label91);
			this->deleteproductid->Controls->Add(this->textBox13);
			this->deleteproductid->Location = System::Drawing::Point(322, 69);
			this->deleteproductid->Name = L"deleteproductid";
			this->deleteproductid->Size = System::Drawing::Size(1147, 623);
			this->deleteproductid->TabIndex = 35;
			// 
			// button65
			// 
			this->button65->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button65.BackgroundImage")));
			this->button65->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button65->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button65->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button65->Location = System::Drawing::Point(28, 19);
			this->button65->Name = L"button65";
			this->button65->Size = System::Drawing::Size(61, 32);
			this->button65->TabIndex = 18;
			this->button65->UseVisualStyleBackColor = true;
			this->button65->Click += gcnew System::EventHandler(this, &MyForm::button65_Click);
			// 
			// label124
			// 
			this->label124->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label124->AutoSize = true;
			this->label124->BackColor = System::Drawing::Color::Transparent;
			this->label124->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label124->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->label124->Location = System::Drawing::Point(698, 268);
			this->label124->Name = L"label124";
			this->label124->Size = System::Drawing::Size(0, 18);
			this->label124->TabIndex = 17;
			// 
			// button41
			// 
			this->button41->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button41->BackColor = System::Drawing::Color::Transparent;
			this->button41->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button41->ForeColor = System::Drawing::Color::Black;
			this->button41->Location = System::Drawing::Point(525, 302);
			this->button41->Name = L"button41";
			this->button41->Size = System::Drawing::Size(90, 31);
			this->button41->TabIndex = 16;
			this->button41->Text = L"DELETE";
			this->button41->UseVisualStyleBackColor = false;
			this->button41->Click += gcnew System::EventHandler(this, &MyForm::button41_Click);
			// 
			// label91
			// 
			this->label91->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->label91->AutoEllipsis = true;
			this->label91->AutoSize = true;
			this->label91->BackColor = System::Drawing::Color::Transparent;
			this->label91->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label91->ForeColor = System::Drawing::Color::Black;
			this->label91->Location = System::Drawing::Point(468, 266);
			this->label91->Name = L"label91";
			this->label91->Size = System::Drawing::Size(31, 21);
			this->label91->TabIndex = 15;
			this->label91->Text = L"ID";
			// 
			// textBox13
			// 
			this->textBox13->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->textBox13->Location = System::Drawing::Point(522, 265);
			this->textBox13->Name = L"textBox13";
			this->textBox13->Size = System::Drawing::Size(156, 22);
			this->textBox13->TabIndex = 14;
			// 
			// updatesupp
			// 
			this->updatesupp->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->updatesupp->BackColor = System::Drawing::SystemColors::Control;
			this->updatesupp->Controls->Add(this->button43);
			this->updatesupp->Controls->Add(this->button44);
			this->updatesupp->Location = System::Drawing::Point(322, 69);
			this->updatesupp->Name = L"updatesupp";
			this->updatesupp->Size = System::Drawing::Size(1147, 623);
			this->updatesupp->TabIndex = 6;
			// 
			// button43
			// 
			this->button43->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->button43->BackColor = System::Drawing::Color::White;
			this->button43->FlatAppearance->BorderSize = 0;
			this->button43->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button43->Font = (gcnew System::Drawing::Font(L"Cooper Black", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button43->ForeColor = System::Drawing::SystemColors::Desktop;
			this->button43->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button43->Location = System::Drawing::Point(329, 317);
			this->button43->Margin = System::Windows::Forms::Padding(4);
			this->button43->Name = L"button43";
			this->button43->Size = System::Drawing::Size(488, 72);
			this->button43->TabIndex = 11;
			this->button43->Text = L"UPDATE SUPPLIER BY NAME";
			this->button43->UseVisualStyleBackColor = false;
			this->button43->Click += gcnew System::EventHandler(this, &MyForm::button43_Click);
			// 
			// button44
			// 
			this->button44->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->button44->BackColor = System::Drawing::Color::White;
			this->button44->FlatAppearance->BorderSize = 0;
			this->button44->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button44->Font = (gcnew System::Drawing::Font(L"Cooper Black", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button44->ForeColor = System::Drawing::SystemColors::Desktop;
			this->button44->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button44->Location = System::Drawing::Point(329, 233);
			this->button44->Margin = System::Windows::Forms::Padding(4);
			this->button44->Name = L"button44";
			this->button44->Size = System::Drawing::Size(488, 68);
			this->button44->TabIndex = 12;
			this->button44->Text = L"UPDATE SUPPLIER BY ID";
			this->button44->UseVisualStyleBackColor = false;
			this->button44->Click += gcnew System::EventHandler(this, &MyForm::button44_Click);
			// 
			// updatesuppname
			// 
			this->updatesuppname->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->updatesuppname->BackColor = System::Drawing::SystemColors::Control;
			this->updatesuppname->Controls->Add(this->button61);
			this->updatesuppname->Controls->Add(this->label96);
			this->updatesuppname->Controls->Add(this->label95);
			this->updatesuppname->Controls->Add(this->button21);
			this->updatesuppname->Controls->Add(this->textBox5);
			this->updatesuppname->Controls->Add(this->button45);
			this->updatesuppname->Controls->Add(this->textBox16);
			this->updatesuppname->Controls->Add(this->label94);
			this->updatesuppname->Location = System::Drawing::Point(322, 69);
			this->updatesuppname->Name = L"updatesuppname";
			this->updatesuppname->Size = System::Drawing::Size(1147, 623);
			this->updatesuppname->TabIndex = 13;
			// 
			// button61
			// 
			this->button61->BackColor = System::Drawing::Color::Transparent;
			this->button61->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button61.BackgroundImage")));
			this->button61->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button61->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button61->ForeColor = System::Drawing::Color::Transparent;
			this->button61->Location = System::Drawing::Point(9, 6);
			this->button61->Name = L"button61";
			this->button61->Size = System::Drawing::Size(58, 32);
			this->button61->TabIndex = 38;
			this->button61->UseVisualStyleBackColor = false;
			this->button61->Click += gcnew System::EventHandler(this, &MyForm::button61_Click);
			// 
			// label96
			// 
			this->label96->AutoSize = true;
			this->label96->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label96->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->label96->Location = System::Drawing::Point(253, 318);
			this->label96->Name = L"label96";
			this->label96->Size = System::Drawing::Size(0, 18);
			this->label96->TabIndex = 7;
			// 
			// label95
			// 
			this->label95->AutoSize = true;
			this->label95->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label95->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->label95->Location = System::Drawing::Point(283, 50);
			this->label95->Name = L"label95";
			this->label95->Size = System::Drawing::Size(0, 16);
			this->label95->TabIndex = 6;
			// 
			// button21
			// 
			this->button21->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->button21->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->button21->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button21->Location = System::Drawing::Point(772, 263);
			this->button21->Name = L"button21";
			this->button21->Size = System::Drawing::Size(163, 45);
			this->button21->TabIndex = 5;
			this->button21->Text = L"UPDATE";
			this->button21->UseVisualStyleBackColor = false;
			this->button21->Click += gcnew System::EventHandler(this, &MyForm::button21_Click_1);
			// 
			// textBox5
			// 
			this->textBox5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->textBox5->BackColor = System::Drawing::Color::LightGray;
			this->textBox5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox5->Location = System::Drawing::Point(252, 263);
			this->textBox5->Multiline = true;
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(503, 46);
			this->textBox5->TabIndex = 4;
			this->textBox5->Text = L"New Product ";
			this->textBox5->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// button45
			// 
			this->button45->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button45->ForeColor = System::Drawing::Color::Black;
			this->button45->Location = System::Drawing::Point(108, 94);
			this->button45->Name = L"button45";
			this->button45->Size = System::Drawing::Size(109, 39);
			this->button45->TabIndex = 2;
			this->button45->Text = L"SEARCH";
			this->button45->UseVisualStyleBackColor = true;
			this->button45->Click += gcnew System::EventHandler(this, &MyForm::button45_Click);
			// 
			// textBox16
			// 
			this->textBox16->Location = System::Drawing::Point(103, 56);
			this->textBox16->Name = L"textBox16";
			this->textBox16->Size = System::Drawing::Size(174, 22);
			this->textBox16->TabIndex = 1;
			// 
			// label94
			// 
			this->label94->AutoSize = true;
			this->label94->Font = (gcnew System::Drawing::Font(L"Century", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label94->ForeColor = System::Drawing::Color::Black;
			this->label94->Location = System::Drawing::Point(37, 54);
			this->label94->Name = L"label94";
			this->label94->Size = System::Drawing::Size(60, 22);
			this->label94->TabIndex = 0;
			this->label94->Text = L"Name";
			// 
			// updatecustomerphone
			// 
			this->updatecustomerphone->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->updatecustomerphone->BackColor = System::Drawing::SystemColors::Control;
			this->updatecustomerphone->Controls->Add(this->button58);
			this->updatecustomerphone->Controls->Add(this->label117);
			this->updatecustomerphone->Controls->Add(this->label108);
			this->updatecustomerphone->Controls->Add(this->label109);
			this->updatecustomerphone->Controls->Add(this->label110);
			this->updatecustomerphone->Controls->Add(this->label111);
			this->updatecustomerphone->Controls->Add(this->label112);
			this->updatecustomerphone->Controls->Add(this->button51);
			this->updatecustomerphone->Controls->Add(this->button52);
			this->updatecustomerphone->Controls->Add(this->button53);
			this->updatecustomerphone->Controls->Add(this->maskedTextBox2);
			this->updatecustomerphone->Controls->Add(this->textBox3);
			this->updatecustomerphone->Controls->Add(this->label113);
			this->updatecustomerphone->Controls->Add(this->textBox19);
			this->updatecustomerphone->Controls->Add(this->label114);
			this->updatecustomerphone->Controls->Add(this->label115);
			this->updatecustomerphone->Controls->Add(this->button54);
			this->updatecustomerphone->Controls->Add(this->textBox20);
			this->updatecustomerphone->Controls->Add(this->label116);
			this->updatecustomerphone->Location = System::Drawing::Point(322, 69);
			this->updatecustomerphone->Name = L"updatecustomerphone";
			this->updatecustomerphone->Size = System::Drawing::Size(1147, 623);
			this->updatecustomerphone->TabIndex = 36;
			// 
			// button58
			// 
			this->button58->BackColor = System::Drawing::Color::Transparent;
			this->button58->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button58.BackgroundImage")));
			this->button58->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button58->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button58->ForeColor = System::Drawing::Color::Transparent;
			this->button58->Location = System::Drawing::Point(12, 9);
			this->button58->Name = L"button58";
			this->button58->Size = System::Drawing::Size(58, 32);
			this->button58->TabIndex = 36;
			this->button58->UseVisualStyleBackColor = false;
			this->button58->Click += gcnew System::EventHandler(this, &MyForm::button58_Click);
			// 
			// label117
			// 
			this->label117->AutoSize = true;
			this->label117->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label117->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->label117->Location = System::Drawing::Point(198, 52);
			this->label117->Name = L"label117";
			this->label117->Size = System::Drawing::Size(0, 20);
			this->label117->TabIndex = 35;
			// 
			// label108
			// 
			this->label108->AutoSize = true;
			this->label108->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label108->ForeColor = System::Drawing::Color::Black;
			this->label108->Location = System::Drawing::Point(553, 440);
			this->label108->Name = L"label108";
			this->label108->Size = System::Drawing::Size(0, 20);
			this->label108->TabIndex = 34;
			// 
			// label109
			// 
			this->label109->AutoSize = true;
			this->label109->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label109->ForeColor = System::Drawing::Color::Black;
			this->label109->Location = System::Drawing::Point(552, 356);
			this->label109->Name = L"label109";
			this->label109->Size = System::Drawing::Size(0, 20);
			this->label109->TabIndex = 33;
			// 
			// label110
			// 
			this->label110->AutoSize = true;
			this->label110->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label110->ForeColor = System::Drawing::Color::Black;
			this->label110->Location = System::Drawing::Point(552, 263);
			this->label110->Name = L"label110";
			this->label110->Size = System::Drawing::Size(0, 20);
			this->label110->TabIndex = 32;
			// 
			// label111
			// 
			this->label111->AutoSize = true;
			this->label111->ForeColor = System::Drawing::Color::Red;
			this->label111->Location = System::Drawing::Point(260, 269);
			this->label111->Name = L"label111";
			this->label111->Size = System::Drawing::Size(194, 32);
			this->label111->TabIndex = 31;
			this->label111->Text = L"Date Format:: \r\nDay Month Date hh:mm:ss Year";
			// 
			// label112
			// 
			this->label112->AutoSize = true;
			this->label112->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label112->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->label112->Location = System::Drawing::Point(292, 120);
			this->label112->Name = L"label112";
			this->label112->Size = System::Drawing::Size(0, 18);
			this->label112->TabIndex = 30;
			// 
			// button51
			// 
			this->button51->BackColor = System::Drawing::Color::MidnightBlue;
			this->button51->ForeColor = System::Drawing::Color::White;
			this->button51->Location = System::Drawing::Point(808, 407);
			this->button51->Name = L"button51";
			this->button51->Size = System::Drawing::Size(83, 28);
			this->button51->TabIndex = 29;
			this->button51->Text = L"UPDATE";
			this->button51->UseVisualStyleBackColor = false;
			this->button51->Click += gcnew System::EventHandler(this, &MyForm::button51_Click);
			// 
			// button52
			// 
			this->button52->BackColor = System::Drawing::Color::MidnightBlue;
			this->button52->ForeColor = System::Drawing::Color::White;
			this->button52->Location = System::Drawing::Point(808, 325);
			this->button52->Name = L"button52";
			this->button52->Size = System::Drawing::Size(83, 28);
			this->button52->TabIndex = 28;
			this->button52->Text = L"UPDATE";
			this->button52->UseVisualStyleBackColor = false;
			this->button52->Click += gcnew System::EventHandler(this, &MyForm::button52_Click);
			// 
			// button53
			// 
			this->button53->BackColor = System::Drawing::Color::MidnightBlue;
			this->button53->ForeColor = System::Drawing::Color::White;
			this->button53->Location = System::Drawing::Point(808, 232);
			this->button53->Name = L"button53";
			this->button53->Size = System::Drawing::Size(83, 28);
			this->button53->TabIndex = 27;
			this->button53->Text = L"UPDATE";
			this->button53->UseVisualStyleBackColor = false;
			this->button53->Click += gcnew System::EventHandler(this, &MyForm::button53_Click);
			// 
			// maskedTextBox2
			// 
			this->maskedTextBox2->Location = System::Drawing::Point(552, 235);
			this->maskedTextBox2->Mask = L"aaa aaa 00 00:00:00 0000";
			this->maskedTextBox2->Name = L"maskedTextBox2";
			this->maskedTextBox2->Size = System::Drawing::Size(239, 22);
			this->maskedTextBox2->TabIndex = 26;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(552, 410);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(239, 22);
			this->textBox3->TabIndex = 25;
			// 
			// label113
			// 
			this->label113->AutoSize = true;
			this->label113->Font = (gcnew System::Drawing::Font(L"Century", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label113->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label113->Location = System::Drawing::Point(259, 404);
			this->label113->Name = L"label113";
			this->label113->Size = System::Drawing::Size(260, 46);
			this->label113->TabIndex = 24;
			this->label113->Text = L"PRICE OF PURCHASES\r\n PER WEEK";
			// 
			// textBox19
			// 
			this->textBox19->Location = System::Drawing::Point(552, 327);
			this->textBox19->Name = L"textBox19";
			this->textBox19->Size = System::Drawing::Size(239, 22);
			this->textBox19->TabIndex = 23;
			// 
			// label114
			// 
			this->label114->AutoSize = true;
			this->label114->Font = (gcnew System::Drawing::Font(L"Century", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label114->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label114->Location = System::Drawing::Point(259, 326);
			this->label114->Name = L"label114";
			this->label114->Size = System::Drawing::Size(209, 23);
			this->label114->TabIndex = 22;
			this->label114->Text = L"LAST BILL VALUE";
			// 
			// label115
			// 
			this->label115->AutoSize = true;
			this->label115->Font = (gcnew System::Drawing::Font(L"Century", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label115->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label115->Location = System::Drawing::Point(255, 237);
			this->label115->Name = L"label115";
			this->label115->Size = System::Drawing::Size(194, 23);
			this->label115->TabIndex = 21;
			this->label115->Text = L"LAST BILL DATE";
			// 
			// button54
			// 
			this->button54->BackColor = System::Drawing::Color::Transparent;
			this->button54->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->button54->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button54->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button54->Location = System::Drawing::Point(90, 99);
			this->button54->Name = L"button54";
			this->button54->Size = System::Drawing::Size(68, 31);
			this->button54->TabIndex = 20;
			this->button54->Text = L"Search";
			this->button54->UseVisualStyleBackColor = false;
			this->button54->Click += gcnew System::EventHandler(this, &MyForm::button54_Click);
			// 
			// textBox20
			// 
			this->textBox20->Location = System::Drawing::Point(97, 66);
			this->textBox20->Name = L"textBox20";
			this->textBox20->Size = System::Drawing::Size(101, 22);
			this->textBox20->TabIndex = 19;
			// 
			// label116
			// 
			this->label116->AutoSize = true;
			this->label116->Font = (gcnew System::Drawing::Font(L"Century", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label116->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label116->Location = System::Drawing::Point(17, 64);
			this->label116->Name = L"label116";
			this->label116->Size = System::Drawing::Size(74, 21);
			this->label116->TabIndex = 18;
			this->label116->Text = L"PHONE";
			// 
			// updatecustomerid
			// 
			this->updatecustomerid->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->updatecustomerid->BackColor = System::Drawing::SystemColors::Control;
			this->updatecustomerid->Controls->Add(this->button59);
			this->updatecustomerid->Controls->Add(this->label107);
			this->updatecustomerid->Controls->Add(this->label106);
			this->updatecustomerid->Controls->Add(this->label105);
			this->updatecustomerid->Controls->Add(this->label104);
			this->updatecustomerid->Controls->Add(this->label103);
			this->updatecustomerid->Controls->Add(this->button50);
			this->updatecustomerid->Controls->Add(this->button49);
			this->updatecustomerid->Controls->Add(this->button48);
			this->updatecustomerid->Controls->Add(this->maskedTextBox1);
			this->updatecustomerid->Controls->Add(this->textBox18);
			this->updatecustomerid->Controls->Add(this->label102);
			this->updatecustomerid->Controls->Add(this->textBox4);
			this->updatecustomerid->Controls->Add(this->label101);
			this->updatecustomerid->Controls->Add(this->label100);
			this->updatecustomerid->Controls->Add(this->button24);
			this->updatecustomerid->Controls->Add(this->textBox2);
			this->updatecustomerid->Controls->Add(this->label98);
			this->updatecustomerid->Location = System::Drawing::Point(322, 69);
			this->updatecustomerid->Name = L"updatecustomerid";
			this->updatecustomerid->Size = System::Drawing::Size(1147, 623);
			this->updatecustomerid->TabIndex = 37;
			// 
			// button59
			// 
			this->button59->BackColor = System::Drawing::Color::Transparent;
			this->button59->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button59.BackgroundImage")));
			this->button59->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button59->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button59->ForeColor = System::Drawing::Color::Transparent;
			this->button59->Location = System::Drawing::Point(12, 9);
			this->button59->Name = L"button59";
			this->button59->Size = System::Drawing::Size(58, 32);
			this->button59->TabIndex = 37;
			this->button59->UseVisualStyleBackColor = false;
			this->button59->Click += gcnew System::EventHandler(this, &MyForm::button59_Click);
			// 
			// label107
			// 
			this->label107->AutoSize = true;
			this->label107->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label107->ForeColor = System::Drawing::Color::Black;
			this->label107->Location = System::Drawing::Point(542, 402);
			this->label107->Name = L"label107";
			this->label107->Size = System::Drawing::Size(0, 20);
			this->label107->TabIndex = 17;
			// 
			// label106
			// 
			this->label106->AutoSize = true;
			this->label106->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label106->ForeColor = System::Drawing::Color::Black;
			this->label106->Location = System::Drawing::Point(541, 318);
			this->label106->Name = L"label106";
			this->label106->Size = System::Drawing::Size(0, 20);
			this->label106->TabIndex = 16;
			// 
			// label105
			// 
			this->label105->AutoSize = true;
			this->label105->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label105->ForeColor = System::Drawing::Color::Black;
			this->label105->Location = System::Drawing::Point(541, 225);
			this->label105->Name = L"label105";
			this->label105->Size = System::Drawing::Size(0, 20);
			this->label105->TabIndex = 15;
			// 
			// label104
			// 
			this->label104->AutoSize = true;
			this->label104->ForeColor = System::Drawing::Color::Red;
			this->label104->Location = System::Drawing::Point(249, 231);
			this->label104->Name = L"label104";
			this->label104->Size = System::Drawing::Size(194, 32);
			this->label104->TabIndex = 14;
			this->label104->Text = L"Date Format:: \r\nDay Month Date hh:mm:ss Year";
			// 
			// label103
			// 
			this->label103->AutoSize = true;
			this->label103->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label103->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->label103->Location = System::Drawing::Point(171, 36);
			this->label103->Name = L"label103";
			this->label103->Size = System::Drawing::Size(0, 18);
			this->label103->TabIndex = 13;
			// 
			// button50
			// 
			this->button50->BackColor = System::Drawing::Color::MidnightBlue;
			this->button50->ForeColor = System::Drawing::Color::White;
			this->button50->Location = System::Drawing::Point(797, 369);
			this->button50->Name = L"button50";
			this->button50->Size = System::Drawing::Size(83, 28);
			this->button50->TabIndex = 12;
			this->button50->Text = L"UPDATE";
			this->button50->UseVisualStyleBackColor = false;
			this->button50->Click += gcnew System::EventHandler(this, &MyForm::button50_Click);
			// 
			// button49
			// 
			this->button49->BackColor = System::Drawing::Color::MidnightBlue;
			this->button49->ForeColor = System::Drawing::Color::White;
			this->button49->Location = System::Drawing::Point(797, 287);
			this->button49->Name = L"button49";
			this->button49->Size = System::Drawing::Size(83, 28);
			this->button49->TabIndex = 11;
			this->button49->Text = L"UPDATE";
			this->button49->UseVisualStyleBackColor = false;
			this->button49->Click += gcnew System::EventHandler(this, &MyForm::button49_Click);
			// 
			// button48
			// 
			this->button48->BackColor = System::Drawing::Color::MidnightBlue;
			this->button48->ForeColor = System::Drawing::Color::White;
			this->button48->Location = System::Drawing::Point(797, 194);
			this->button48->Name = L"button48";
			this->button48->Size = System::Drawing::Size(83, 28);
			this->button48->TabIndex = 10;
			this->button48->Text = L"UPDATE";
			this->button48->UseVisualStyleBackColor = false;
			this->button48->Click += gcnew System::EventHandler(this, &MyForm::button48_Click);
			// 
			// maskedTextBox1
			// 
			this->maskedTextBox1->Location = System::Drawing::Point(541, 197);
			this->maskedTextBox1->Mask = L"aaa aaa 00 00:00:00 0000";
			this->maskedTextBox1->Name = L"maskedTextBox1";
			this->maskedTextBox1->Size = System::Drawing::Size(239, 22);
			this->maskedTextBox1->TabIndex = 9;
			// 
			// textBox18
			// 
			this->textBox18->Location = System::Drawing::Point(541, 372);
			this->textBox18->Name = L"textBox18";
			this->textBox18->Size = System::Drawing::Size(239, 22);
			this->textBox18->TabIndex = 8;
			// 
			// label102
			// 
			this->label102->AutoSize = true;
			this->label102->Font = (gcnew System::Drawing::Font(L"Century", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label102->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label102->Location = System::Drawing::Point(248, 366);
			this->label102->Name = L"label102";
			this->label102->Size = System::Drawing::Size(260, 46);
			this->label102->TabIndex = 7;
			this->label102->Text = L"PRICE OF PURCHASES\r\n PER WEEK";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(541, 289);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(239, 22);
			this->textBox4->TabIndex = 6;
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox4_TextChanged);
			// 
			// label101
			// 
			this->label101->AutoSize = true;
			this->label101->Font = (gcnew System::Drawing::Font(L"Century", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label101->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label101->Location = System::Drawing::Point(248, 288);
			this->label101->Name = L"label101";
			this->label101->Size = System::Drawing::Size(209, 23);
			this->label101->TabIndex = 5;
			this->label101->Text = L"LAST BILL VALUE";
			// 
			// label100
			// 
			this->label100->AutoSize = true;
			this->label100->Font = (gcnew System::Drawing::Font(L"Century", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label100->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label100->Location = System::Drawing::Point(244, 199);
			this->label100->Name = L"label100";
			this->label100->Size = System::Drawing::Size(194, 23);
			this->label100->TabIndex = 3;
			this->label100->Text = L"LAST BILL DATE";
			// 
			// button24
			// 
			this->button24->BackColor = System::Drawing::Color::Transparent;
			this->button24->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->button24->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button24->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button24->Location = System::Drawing::Point(90, 99);
			this->button24->Name = L"button24";
			this->button24->Size = System::Drawing::Size(68, 31);
			this->button24->TabIndex = 2;
			this->button24->Text = L"Search";
			this->button24->UseVisualStyleBackColor = false;
			this->button24->Click += gcnew System::EventHandler(this, &MyForm::button24_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(97, 66);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(101, 22);
			this->textBox2->TabIndex = 1;
			// 
			// label98
			// 
			this->label98->AutoSize = true;
			this->label98->Font = (gcnew System::Drawing::Font(L"Century", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label98->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label98->Location = System::Drawing::Point(57, 67);
			this->label98->Name = L"label98";
			this->label98->Size = System::Drawing::Size(30, 21);
			this->label98->TabIndex = 0;
			this->label98->Text = L"ID";
			// 
			// MyForm
			// 
			this->AllowDrop = true;
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->BackColor = System::Drawing::Color::Gray;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->ClientSize = System::Drawing::Size(1543, 719);
			this->ControlBox = false;
			this->Controls->Add(this->home);
			this->Controls->Add(this->updatepanel);
			this->Controls->Add(this->deletesup);
			this->Controls->Add(this->updatesuppname);
			this->Controls->Add(this->deletecust);
			this->Controls->Add(this->searchsupp);
			this->Controls->Add(this->updatecust);
			this->Controls->Add(this->addmed);
			this->Controls->Add(this->fullreport);
			this->Controls->Add(this->searchp);
			this->Controls->Add(this->searchproduct);
			this->Controls->Add(this->searchname);
			this->Controls->Add(this->updatecustomerid);
			this->Controls->Add(this->productsearchid);
			this->Controls->Add(this->searchcustp);
			this->Controls->Add(this->searchcustidp);
			this->Controls->Add(this->searchcustphone);
			this->Controls->Add(this->deletesupplierid);
			this->Controls->Add(this->deleteproduct);
			this->Controls->Add(this->deleteproductname);
			this->Controls->Add(this->deleteproductid);
			this->Controls->Add(this->deletepro);
			this->Controls->Add(this->deletecustid);
			this->Controls->Add(this->searchsupplierid);
			this->Controls->Add(this->deletesuppliername);
			this->Controls->Add(this->searchsuppliername);
			this->Controls->Add(this->addsupplier);
			this->Controls->Add(this->deletecustphone);
			this->Controls->Add(this->updatecustomerphone);
			this->Controls->Add(this->newcust);
			this->Controls->Add(this->updatesuppid);
			this->Controls->Add(this->newadd);
			this->Controls->Add(this->updatesupp);
			this->Controls->Add(this->options);
			this->Controls->Add(this->welcome1);
			this->ForeColor = System::Drawing::Color::Ivory;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MyForm";
			this->Text = L"Medical System";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::mouse_Down);
			this->welcome1->ResumeLayout(false);
			this->welcome1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			this->options->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			this->newadd->ResumeLayout(false);
			this->addmed->ResumeLayout(false);
			this->addmed->PerformLayout();
			this->newcust->ResumeLayout(false);
			this->newcust->PerformLayout();
			this->searchp->ResumeLayout(false);
			this->searchproduct->ResumeLayout(false);
			this->searchname->ResumeLayout(false);
			this->searchname->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->productsearchid->ResumeLayout(false);
			this->productsearchid->PerformLayout();
			this->showproduct->ResumeLayout(false);
			this->showproduct->PerformLayout();
			this->deletepro->ResumeLayout(false);
			this->deleteproduct->ResumeLayout(false);
			this->searchcustp->ResumeLayout(false);
			this->searchcustidp->ResumeLayout(false);
			this->searchcustidp->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->updatepanel->ResumeLayout(false);
			this->updatecust->ResumeLayout(false);
			this->updatesuppid->ResumeLayout(false);
			this->updatesuppid->PerformLayout();
			this->searchcustphone->ResumeLayout(false);
			this->searchcustphone->PerformLayout();
			this->panel12->ResumeLayout(false);
			this->panel12->PerformLayout();
			this->searchsupp->ResumeLayout(false);
			this->searchsupplierid->ResumeLayout(false);
			this->searchsupplierid->PerformLayout();
			this->panel14->ResumeLayout(false);
			this->panel14->PerformLayout();
			this->searchsuppliername->ResumeLayout(false);
			this->searchsuppliername->PerformLayout();
			this->panel16->ResumeLayout(false);
			this->panel16->PerformLayout();
			this->addsupplier->ResumeLayout(false);
			this->addsupplier->PerformLayout();
			this->fullreport->ResumeLayout(false);
			this->deletecust->ResumeLayout(false);
			this->deletesup->ResumeLayout(false);
			this->deletecustid->ResumeLayout(false);
			this->deletecustid->PerformLayout();
			this->deletecustphone->ResumeLayout(false);
			this->deletecustphone->PerformLayout();
			this->deletesupplierid->ResumeLayout(false);
			this->deletesupplierid->PerformLayout();
			this->deletesuppliername->ResumeLayout(false);
			this->deletesuppliername->PerformLayout();
			this->deleteproductname->ResumeLayout(false);
			this->deleteproductname->PerformLayout();
			this->deleteproductid->ResumeLayout(false);
			this->deleteproductid->PerformLayout();
			this->updatesupp->ResumeLayout(false);
			this->updatesuppname->ResumeLayout(false);
			this->updatesuppname->PerformLayout();
			this->updatecustomerphone->ResumeLayout(false);
			this->updatecustomerphone->PerformLayout();
			this->updatecustomerid->ResumeLayout(false);
			this->updatecustomerid->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		newadd->BringToFront();



	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void pictureBox2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		updatepanel->BringToFront();
	}
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
		fullreport->BringToFront();
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		searchp->BringToFront();
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		deletepro->BringToFront();
	}
	private: System::Void panel2_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}

	private: System::Void pictureBox7_Click(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label3_Click_1(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void panel3_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox2_Click_1(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
	}
	private: System::Void pictureBox1_Click_1(System::Object^ sender, System::EventArgs^ e) {
		x++;
		if (x % 2 != 0)
		{
			this->WindowState = FormWindowState::Maximized;
		}
		else
		{
			this->WindowState = FormWindowState::Normal;
		}
	}
	private: System::Void pictureBox3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox3_Click_1(System::Object^ sender, System::EventArgs^ e) {
		this->WindowState = FormWindowState::Minimized;
	}
	private: System::Void button3_Click_1(System::Object^ sender, System::EventArgs^ e) {


	}
	private: System::Void button1_Click_2(System::Object^ sender, System::EventArgs^ e) {



	}
	private: System::Void panel1_Paint_1(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void panel2_Paint_1(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}

	private: System::Void button2_Click_1(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void flowLayoutPanel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void newadd_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void medadd_Click(System::Object^ sender, System::EventArgs^ e) {
		addmed->BringToFront();
	}
	private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void maskedTextBox1_MaskInputRejected(System::Object^ sender, System::Windows::Forms::MaskInputRejectedEventArgs^ e) {
	}
	private: System::Void addmed_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void maskedTextBox1_MaskInputRejected_1(System::Object^ sender, System::Windows::Forms::MaskInputRejectedEventArgs^ e) {
	}
	private: System::Void button2_Click_2(System::Object^ sender, System::EventArgs^ e) {
		msclr::interop::marshal_context context;
		if (namemed->Text == "" || stockmed->Text == "" || datemed->Text == "  /  /    " || pricemed->Text == "" || suppliernamemed->Text == "" || datemed->Text == "//    ")
		{
			MessageBox::Show(" Please enter a value in all boxes");

		}
		else
		{
			string tmp = context.marshal_as<std::string>(stockmed->Text);
			bool a = false;
			for (int i = 0; i < tmp.length(); i++)
			{
				if (!isdigit(tmp[i]))
				{
					a = true;
				}
			}
			int count = 0;
			string tmp1 = context.marshal_as<std::string>(pricemed->Text);
			for (int i = 0; i < tmp1.length(); i++)
			{
				if (!isdigit(tmp1[i]))
				{
					count++;
				}
			}
			if (count > 1)
			{
				a = true;
			}
			string tmp2 = context.marshal_as<std::string>(datemed->Text);
			for (int i = 0; i < 10; i++)
			{
				if (tmp2[i] == ' ')
				{
					a = true;
				}
			}
			if (!a)
			{
				int f = mednum;

				bool boo = false;
				label7->Text = "";
				med[f].name = context.marshal_as<std::string>(namemed->Text);
				med[f].stock = stoi(context.marshal_as<std::string>(stockmed->Text));
				med[f].price = context.marshal_as<std::string>(pricemed->Text);
				med[f].date = context.marshal_as<std::string>(datemed->Text);
				med[f].SupplierName = context.marshal_as<std::string>(suppliernamemed->Text);
				for (int i = 0; i < med[f].name.length(); i++)
				{
					if (isdigit(med[f].name[i]))
					{
						label7->Text = "Product Name does not contain numbers!";
						boo = true;
						break;
					}
				}
				for (int i = 0; i < mednum; i++)
				{

					if (med[i].name == med[f].name)
					{

						label7->Text = "This Product already exists";
						boo = true;

					}
				}
				if (!boo)
				{
					label7->Text = "Added successfully";
					if (f == 0)
					{
						med[f].id = 1;
					}
					else
					{
						med[f].id = med[f - 1].id + 1;
					}

				//	f++;
					mednum++;
				}
			}
			else
			{
				MessageBox::Show(" Please enter a valid value in all boxes");
			}



		}

	}
	private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void mouse_Down(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {

		dragging = true;
		offset.X = e->X;
		offset.Y = e->Y;



	}
	private: System::Void custadd_Click(System::Object^ sender, System::EventArgs^ e) {
		newcust->BringToFront();
	}

	private: System::Void button1_Click_3(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void button1_Click_4(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox4_Click(System::Object^ sender, System::EventArgs^ e) {
		home->BringToFront();
	}
	private: System::Void button1_Click_5(System::Object^ sender, System::EventArgs^ e) {
		newadd->BringToFront();
	}
	private: System::Void button1cust_Click(System::Object^ sender, System::EventArgs^ e) {
		msclr::interop::marshal_context context;
		if (custname->Text == "" || custphone->Text == "" || billdate->Text == "          :  :       " || billvalue->Text == "" || purchasedproducts->Text == "")
		{
			MessageBox::Show(" Please enter a value in all boxes");

		}
		else
		{

			int f = custnum;
			string bill;
			bool fs = false;
			label8->Text = "";
			cust[f].name = context.marshal_as<std::string>(custname->Text);
			cust[f].phone = context.marshal_as<std::string>(custphone->Text);
			bill = context.marshal_as<std::string>(billvalue->Text);
			cust[f].date = context.marshal_as<std::string>(billdate->Text);
			string cut = context.marshal_as<std::string>(purchasedproducts->Text);
			int idx = 0;
			int count = 0; // number of medicines
			int start1 = 0;
			int newline = 0;
			int letterc = 0;                                       
			bool medname = false;
			for (int i = 0; i < cut.length(); i++)
			{
				if (isdigit(cut[i]))
				{
					medname = true;
					break;
				}
				if (cut[i] == '\n' && isalpha(cut[i - 1]) != 0)
				{
					newline++;
					for (int j = start1; j < i; j++)
					{
						cust[f].custproducts[idx] += cut[j];
						letterc++;
					}
					cust[f].num++;
					idx++;
					start1 = i + 1;
				}
			}

			cust[f].num++;
			if ((cut.length() - (letterc + newline)) > 0)
			{
				for (int q = start1; q < cut.length(); q++)
				{
					cust[f].custproducts[idx] += cut[q];
				}
			}
			if (medname)
			{
				MessageBox::Show(" Purchased Products do not contain numbers!");
				fs = true;
			}
			for (int i = 0; i < custnum; i++)
			{
				if (medname)
				{
					break;
				}

				if (cust[i].name == cust[f].name)
				{
					label8->Text = "This customer already exists";
					fs = true;



				}
			}
			bool add = false; // to know if bill value is valid or not
			for (int i = 0; i < bill.length(); i++)
			{
				if (!isdigit(bill[i]))
				{
					if (bill[i] == '.')
					{
						count++;
					}
					else
					{
						MessageBox::Show("Pls enter a valid price");
						fs = true;
						add = true;
						break;
					}
				}
			}
			if (count > 1)
			{
				MessageBox::Show("Pls enter a valid price");
				add = true;
				fs = true;
			}

			if (!add)
			{
				double realprice;
				if (stod(bill) > 500)
				{
                   realprice = (stod(bill) * 5) / 100;
				}
				else
				{
					realprice = stod(bill);
				}
				
				cust[f].Billvalue = std::to_string(realprice);
				cust[f].TotalPriceofweek = cust[f].Billvalue;
			}


			if (!fs)
			{

				label8->Text = "Added successfully";
				custname->Text = "";
				custphone->Text = "";
				purchasedproducts->Text = "";
				billdate->Text = "";
				billvalue->Text = "";

				if (f == 0)
				{
					cust[f].id = 1; //if its first customer
				}
				else
				{
					cust[f].id = cust[f - 1].id + 1; //else take id of previous customer
				}
				for (int pp = 0; pp < mednum; pp++)
				{
					for (int jj = 0; jj <= idx; jj++)
					{
						if (med[pp].name == cust[f].custproducts[jj])
						{
							med[pp].stock--;
						}
					}
				}

				//f++;
				custnum++;

			}

		}
		/*else
		{
			MessageBox::Show(" Please enter a valid value in all boxes");
		}*/




	}
	private: System::Void purchasedproducts_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void newcust_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void pricemed_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click_6(System::Object^ sender, System::EventArgs^ e) {
		searchproduct->BringToFront();
	}
	private: System::Void button5_Click_1(System::Object^ sender, System::EventArgs^ e) {
		productsearchid->BringToFront();
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
		if (barsearch->Text == "")
		{
			MessageBox::Show("Please enter a value");

		}
		else
		{
			msclr::interop::marshal_context context;
			bool entry, verified;

			verified = false;
			entry = false;
			string id;
			id = context.marshal_as<std::string>(barsearch->Text);
			if (id[0] == 'M' || id[0] == 'm')
			{
				for (int i = 1; i < id.length(); i++)
				{
					if (!isdigit(id[i]))
					{
						verified = true;
					}
				}

				if (!verified)
				{
					int k = stoi(id.substr(1));
					string c = id.substr(0, 1);
					for (int i = 0; i < mednum; i++)
					{
						if (med[i].id == k && (c == "M" || c == "m"))
						{
							entry = true;
							string tmp = std::to_string(med[i].id);
							String^ medid1 = gcnew String(tmp.c_str());
							medid->Text = "M" + medid1;
							tmp = med[i].name;
							String^ medname1 = gcnew String(tmp.c_str());
							medname->Text = medname1;
							tmp = std::to_string(med[i].stock);
							String^ medstock1 = gcnew String(tmp.c_str());
							medstock->Text = medstock1;
							tmp = med[i].price;
							String^ medprice1 = gcnew String(tmp.c_str());
							medprice->Text = medprice1;
							tmp = med[i].date;
							String^ medexpiredate1 = gcnew String(tmp.c_str());
							meddate->Text = medexpiredate1;
							tmp = med[i].SupplierName;
							String^ medsuppliername1 = gcnew String(tmp.c_str());
							medsuppliername->Text = medsuppliername1;


						}
					}
					if (!entry)
					{
						MessageBox::Show("RECORDS NOT FOUND");
						medid->Text = "";
						medname->Text = "";
						medstock->Text = "";
						medprice->Text = "";
						meddate->Text = "";
						medsuppliername->Text = "";

					}


				}
				else
				{
					MessageBox::Show("RECORDS NOT FOUND");

				}





			}
			else
			{
				MessageBox::Show("RECORDS NOT FOUND");
			}

		}
	}
	private: System::Void label28_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label24_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label25_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label26_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label27_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label21_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
		searchname->BringToFront();
	}
	private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {
		searchproduct->BringToFront();
	}
	private: System::Void button8_Click_1(System::Object^ sender, System::EventArgs^ e) {
		searchproduct->BringToFront();
	}
	private: System::Void button9_Click(System::Object^ sender, System::EventArgs^ e) {
		if (namemedtxt->Text == "")
		{
			MessageBox::Show("Please enter a value");

		}
		else
		{
			msclr::interop::marshal_context context;
			bool entry, verified;

			verified = false;
			entry = false;
			string name;
			name = context.marshal_as<std::string>(namemedtxt->Text);

			for (int i = 0; i < mednum; i++)
			{
				if (med[i].name == name)
				{
					entry = true;
					string tmp = std::to_string(med[i].id);
					String^ medid1 = gcnew String(tmp.c_str());
					label29->Text = "M" + medid1;
					tmp = med[i].name;
					String^ medname1 = gcnew String(tmp.c_str());
					label28->Text = medname1;
					tmp = std::to_string(med[i].stock);
					String^ medstock1 = gcnew String(tmp.c_str());
					label27->Text = medstock1;
					tmp = med[i].price;
					String^ medprice1 = gcnew String(tmp.c_str());
					label26->Text = medprice1;
					tmp = med[i].date;
					String^ medexpiredate1 = gcnew String(tmp.c_str());
					label24->Text = medexpiredate1;
					tmp = med[i].SupplierName;
					String^ medsuppliername1 = gcnew String(tmp.c_str());
					label25->Text = medsuppliername1;


				}
			}
			if (!entry)
			{
				MessageBox::Show("RECORDS NOT FOUND");
				label29->Text = "";
				label28->Text = "";
				label27->Text = "";
				label26->Text = "";
				label24->Text = "";
				label25->Text = "";

			}


		}

	}
	private: System::Void searchname_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
		   bool dragging;
		   Point offset;
	private: System::Void welcome1_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {

		if (dragging)
		{
			Point currentScreenPosition = PointToScreen(Point(e->X, e->Y));
			Location = Point(currentScreenPosition.X - offset.X, currentScreenPosition.Y - offset.Y);
		}
	}
	private: System::Void welcome1_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		dragging = false;
	}

	private: System::Void welcome1_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		dragging = true;
		offset.X = e->X;
		offset.Y = e->Y;
	}
	private: System::Void button13_Click(System::Object^ sender, System::EventArgs^ e) {
		deleteproductname->BringToFront();
	}
	private: System::Void button12_Click(System::Object^ sender, System::EventArgs^ e) {
		deleteproduct->BringToFront();
	}
	private: System::Void button4_Click_1(System::Object^ sender, System::EventArgs^ e) {
		searchcustp->BringToFront();
	}
	private: System::Void searchcustp_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void button16_Click(System::Object^ sender, System::EventArgs^ e) {
		searchcustidp->BringToFront();
	}
	private: System::Void button15_Click(System::Object^ sender, System::EventArgs^ e) {
		searchcustphone->BringToFront();			//searchcustphonep->BringToFront();
	}
	private: System::Void label43_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button18_Click(System::Object^ sender, System::EventArgs^ e) {

		if (textBox1->Text == "")
		{
			MessageBox::Show("Please enter a value");

		}
		else
		{
			msclr::interop::marshal_context context;
			bool entry, verified;

			verified = false;
			entry = false;
			string id;
			id = context.marshal_as<std::string>(textBox1->Text);
			if ((id[0] == 'u' || id[0] == 'U') && id.length() > 1)
			{
				for (int i = 1; i < id.length(); i++)
				{
					if (!isdigit(id[i]))
					{
						verified = true;
					}
				}

				if (!verified)
				{
					int k = stoi(id.substr(1));
					string c = id.substr(0, 1);
					for (int i = 0; i < custnum; i++)
					{
						if (cust[i].id == k && (c == "U" || c == "u"))
						{
							entry = true;
							string tmp = std::to_string(cust[i].id);
							String^ custid1 = gcnew String(tmp.c_str());
							label42->Text = "M" + custid1;
							tmp = cust[i].name;
							String^ custname1 = gcnew String(tmp.c_str());
							label41->Text = custname1;
							tmp = cust[i].phone;
							String^ custphone1 = gcnew String(tmp.c_str());
							label40->Text = custphone1;
							tmp = "";
							for (int j = 0; j < cust[i].num; j++)
							{
								if (j == cust[i].num - 1)
								{
									tmp += cust[i].custproducts[j];

								}
								else
								{
									tmp += cust[i].custproducts[j] + ',';
								}


							}

							String^ custproducts1 = gcnew String(tmp.c_str());
							label39->Text = custproducts1;
							tmp = cust[i].date;
							String^ custdate1 = gcnew String(tmp.c_str());
							label37->Text = custdate1;
							tmp = cust[i].Billvalue;
							String^ billvalue1 = gcnew String(tmp.c_str());
							label38->Text = billvalue1;
							tmp = cust[i].TotalPriceofweek;
							String^ weekprice = gcnew String(tmp.c_str());
							label52->Text = weekprice;
						}
					}
					if (!entry)
					{
						MessageBox::Show("RECORDS NOT FOUND");
						medid->Text = "";
						medname->Text = "";
						medstock->Text = "";
						medprice->Text = "";
						meddate->Text = "";
						medsuppliername->Text = "";

					}


				}
				else
				{
					MessageBox::Show("RECORDS NOT FOUND");

				}





			}
			else
			{
				MessageBox::Show("RECORDS NOT FOUND");
			}

		}

	}
	private: System::Void panel3_Paint_1(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void pictureBox2_Click_2(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
	}
	private: System::Void panel4_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void panel5_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void button19_Click(System::Object^ sender, System::EventArgs^ e) {
		updatecust->BringToFront();
	}
	private: System::Void panel10_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void button20_Click(System::Object^ sender, System::EventArgs^ e) {
		updatesupp->BringToFront();
	}
	private: System::Void button3_Click_2(System::Object^ sender, System::EventArgs^ e) {
		searchsupp->BringToFront();
	}
	private: System::Void button28_Click(System::Object^ sender, System::EventArgs^ e) {
		searchsupplierid->BringToFront();
	}
	private: System::Void button27_Click(System::Object^ sender, System::EventArgs^ e) {
		searchsuppliername->BringToFront();
	}
	private: System::Void button22_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void suppadd_Click(System::Object^ sender, System::EventArgs^ e) {
		addsupplier->BringToFront();
	}
	private: System::Void button10_Click(System::Object^ sender, System::EventArgs^ e) {
		deletecust->BringToFront();
	}
	private: System::Void button33_Click(System::Object^ sender, System::EventArgs^ e) {
		deletecustid->BringToFront();
	}
	private: System::Void button34_Click(System::Object^ sender, System::EventArgs^ e) {
		deletecustphone->BringToFront();
	}
	private: System::Void button11_Click(System::Object^ sender, System::EventArgs^ e) {
		deletesup->BringToFront();
	}
	private: System::Void button35_Click(System::Object^ sender, System::EventArgs^ e) {
		deletesupplierid->BringToFront();
	}
	private: System::Void button36_Click(System::Object^ sender, System::EventArgs^ e) {
		deletesuppliername->BringToFront();
	}
	private: System::Void button14_Click(System::Object^ sender, System::EventArgs^ e) {
		deleteproductid->BringToFront();
	}
	private: System::Void label87_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button37_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label88_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void deletecustid_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void button42_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox14_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label92_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void deletecustphone_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void label87_Click_1(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void deletesup_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void button36_Click_1(System::Object^ sender, System::EventArgs^ e) {
		deletesupplierid->BringToFront();
	}
	private: System::Void button35_Click_1(System::Object^ sender, System::EventArgs^ e) {
		deletesuppliername->BringToFront();
	}
	private: System::Void button21_Click(System::Object^ sender, System::EventArgs^ e) {

	}
private: System::Void button44_Click(System::Object^ sender, System::EventArgs^ e) {
	updatesuppid->BringToFront();
}
private: System::Void button43_Click(System::Object^ sender, System::EventArgs^ e) {
	updatesuppname->BringToFront();
}
private: System::Void button45_Click(System::Object^ sender, System::EventArgs^ e) {
	label95->Text = "";
	msclr::interop::marshal_context context;
	string name;
	
	if (textBox16->Text == "")
	{
		MessageBox::Show("Please Enter a value");

	}
	else
	{
		name = context.marshal_as<std::string>(textBox16->Text);
		bool found;
	for (int i = 0; i < suppnum; i++)
	{
		if (supp[i].name == name)
		{
			suppidx = i;
			found = true;
			label95->Text = "Records found!";
		}
	}
	if(!found)
	{
         MessageBox::Show("Records not found");
	}
	}
	






}
private: System::Void button21_Click_1(System::Object^ sender, System::EventArgs^ e) {
	label96->Text = "";
	if (textBox5->Text == "")
	{
		MessageBox::Show("Please enter a value");
	}
	else
	{
		bool notalpha = false;
		msclr::interop::marshal_context context; //used to be able to convert from System string to string
		string name;
		name = context.marshal_as<std::string>(textBox5->Text);
		for (int i = 0; i < name.length(); i++)
		{
			if (isalpha(name[i]) == 0)
			{
				notalpha = true;
			}
		}
		if (notalpha)
		{
			MessageBox::Show("Invalid Products name!");
		}
		else
		{
			supp[suppidx].suppproducts[supp[suppidx].num] = name;
			supp[suppidx].num++;
			label96->Text = "Successfully Updated!";
		}
	}

	

}
private: System::Void button47_Click(System::Object^ sender, System::EventArgs^ e) {
	label99->Text = "";
	bool found = false;
		bool notdigit = false;
	string id;
	if (textBox15->Text == "")
	{
		MessageBox::Show("Please enter a value");
	}
	else
	{
		msclr::interop::marshal_context context;
		
		id = context.marshal_as<std::string>(textBox15->Text);
		if ((id[0] == 'S' || id[0] == 's') && id.length() > 1)
		{
        for (int i = 1; i < id.length(); i++)
		{
			if (!isdigit(id[i]))
			{
				notdigit = true;
				break;
			}
		}
		}
		else
		{
			notdigit = true;
		}

		if(notdigit)
		{

			MessageBox::Show("Records not Found!");


		}
		else
		{
			for (int j = 0; j < suppnum; j++)
			{
				if (supp[j].id == stoi(id.substr(1)))
				{
					suppidxid = j;
					label99->Text = "FOUND";
					found = true;
				
				}
			}
			
		}
		if (!found)
			{
				label99->Text = "NOT FOUND!";
			}
		
		
	}

}
private: System::Void button46_Click(System::Object^ sender, System::EventArgs^ e) {
	label97->Text = "";
	if (textBox17->Text == "")
	{
		MessageBox::Show("Please enter a value");
	}
	else
	{
		bool notalpha = false;
		msclr::interop::marshal_context context; //used to be able to convert from System string to string
		string name;
		name = context.marshal_as<std::string>(textBox17->Text);
		for (int i = 0; i < name.length(); i++)
		{
			if (isalpha(name[i]) == 0)
			{
				notalpha = true;
			}
		}
		if (notalpha)
		{
			MessageBox::Show("Invalid Products name!");
		}
		else
		{
			supp[suppidxid].suppproducts[supp[suppidxid].num] = name;
			supp[suppidxid].num++;
			label97->Text = "Successfully Updated!";
		}
	}






}
private: System::Void button23_Click(System::Object^ sender, System::EventArgs^ e) {
	updatecustomerid->BringToFront();
}
private: System::Void button22_Click_1(System::Object^ sender, System::EventArgs^ e) {
	updatecustomerphone->BringToFront();
}
private: System::Void textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button50_Click(System::Object^ sender, System::EventArgs^ e) {
	label107->Text = "";
	int count = 0;
	bool notvalid = false;
	if (textBox18->Text == "")
	{
		MessageBox::Show("Pls enter a value");
	}
	else
	{
		string price;
		msclr::interop::marshal_context context;
		price = context.marshal_as<std::string>(textBox18->Text);
		for (int i = 0; i < price.length(); i++)
		{
			if (!isdigit(price[i]))
			{
				if (price[i] == '.')
				{
					count++;
				}
				else
				{
					notvalid = true;
					MessageBox::Show("Pls enter a valid price");
					break;
				}
			}
		}
		if (count > 1)
		{
			MessageBox::Show("Pls enter a valid price");
		}
		else
		{
			if (!notvalid)
			{
               cust[custidxid].TotalPriceofweek = price;
               label107->Text = "SUCCESS";
			}
				
		}
	}




}
private: System::Void button24_Click(System::Object^ sender, System::EventArgs^ e) {
	label103->Text = "";
	string id;
	    bool found = false;
		bool notdigit = false;
	if (textBox2->Text == "")
	{
		MessageBox::Show("Pls enter a value");
	}
	else
	{
		msclr::interop::marshal_context context;

		id = context.marshal_as<std::string>(textBox2->Text);
		if ((id[0] == 'U' || id[0] == 'u') && id.length() > 1)
		{
			for (int i = 1; i < id.length(); i++)
			{
				if (!isdigit(id[i]))
				{
					notdigit = true;
					break;
				}
			}
		}
		else
		{
			notdigit = true;
		}

		if (notdigit)
		{

			MessageBox::Show("Records not Found!");


		}
		else
		{
			for (int j = 0; j < custnum; j++)
			{
				if (cust[j].id == stoi(id.substr(1)))
				{
					custidxid = j;
					label103->Text = "FOUND";
					found = true;

				}
			}

		}
		if (!found)
		{
			label103->Text = "NOT FOUND!";
		}


	}
}
private: System::Void button48_Click(System::Object^ sender, System::EventArgs^ e) {
	label105->Text = "";
	if (maskedTextBox1->Text == "")
	{
		MessageBox::Show("Pls enter a value");
	}
	else
	{
		string date;
		msclr::interop::marshal_context context;

		date = context.marshal_as<std::string>(maskedTextBox1->Text);
		cust[custidxid].date = date; 
		label105->Text = "SUCCESS";
	}
}
private: System::Void button49_Click(System::Object^ sender, System::EventArgs^ e) {
	label106->Text = "";
	int count = 0;
	bool notvalid = false;
	if (textBox4->Text == "")
	{
		MessageBox::Show("Pls enter a value");
	}
	else
	{
		string price;
		msclr::interop::marshal_context context;
		price = context.marshal_as<std::string>(textBox4->Text);
		for (int i = 0; i < price.length(); i++)
		{
			if (!isdigit(price[i]))
			{
				if (price[i] == '.')
				{
					count++;
				}
				else
				{
					notvalid = true;
					MessageBox::Show("Pls enter a valid price");
					break;
				}
			}
		}
		if (count > 1)
		{
			MessageBox::Show("Pls enter a valid price");
		}
		else
		{
			if (!notvalid)
			{
         cust[custidxid].Billvalue = price;
         label106->Text = "SUCCESS";

			}
			
		}
	}
}
private: System::Void button54_Click(System::Object^ sender, System::EventArgs^ e) {
	label117->Text = "";
	if (textBox20->Text == "")
	{
		MessageBox::Show("Pls enter a value");
	}
	else
	{

		string phone;
		msclr::interop::marshal_context context;
		phone = context.marshal_as<std::string>(textBox20->Text);
		bool found = false;
		for (int i = 0; i < custnum; i++)
		{
			if (cust[i].phone == phone)
			{
				custidxphone = i;
				label117->Text = "FOUND";
				found = true;
			}
		}
		if (!found)
		{
			label117->Text = "NOT FOUND";
		}

	}












}
private: System::Void button53_Click(System::Object^ sender, System::EventArgs^ e) {


	label110->Text = "";
	if (maskedTextBox2->Text == "")
	{
		MessageBox::Show("Pls enter a value");
	}
	else
	{
		string date;
		msclr::interop::marshal_context context;

		date = context.marshal_as<std::string>(maskedTextBox2->Text);
		cust[custidxphone].date = date;
		label110->Text = "SUCCESS";
	}





}
private: System::Void button55_Click(System::Object^ sender, System::EventArgs^ e) {
	pause++;
	if (pause % 2 != 0)
	{
		player->Play();

	}
	else
	{
		player->Stop();
	}
}
private: System::Void button52_Click(System::Object^ sender, System::EventArgs^ e) {
	label109->Text = "";
	int count = 0;
	bool notvalid = false;
	if (textBox19->Text == "")
	{
		MessageBox::Show("Pls enter a value");
	}
	else
	{
		string price;
		msclr::interop::marshal_context context;
		price = context.marshal_as<std::string>(textBox19->Text);
		for (int i = 0; i < price.length(); i++)
		{
			if (!isdigit(price[i]))
			{
				if (price[i] == '.')
				{
					count++;
				}
				else
				{
					notvalid = true;
					MessageBox::Show("Pls enter a valid price");
					break;
				}
			}
		}
		if (count > 1)
		{
			MessageBox::Show("Pls enter a valid price");
		}
		else
		{
			if (!notvalid)
			{
				cust[custidxphone].Billvalue = price;
				label109->Text = "SUCCESS";

			}

		}
	}




}
private: System::Void button51_Click(System::Object^ sender, System::EventArgs^ e) {
	label108->Text = "";
	int count = 0;
	bool notvalid = false;
	if (textBox3->Text == "")
	{
		MessageBox::Show("Pls enter a value");
	}
	else
	{
		string price;
		msclr::interop::marshal_context context;
		price = context.marshal_as<std::string>(textBox3->Text);
		for (int i = 0; i < price.length(); i++)
		{
			if (!isdigit(price[i]))
			{
				if (price[i] == '.')
				{
					count++;
				}
				else
				{
					notvalid = true;
					MessageBox::Show("Pls enter a valid price");
					break;
				}
			}
		}
		if (count > 1)
		{
			MessageBox::Show("Pls enter a valid price");
		}
		else
		{
			if (!notvalid)
			{
				cust[custidxphone].TotalPriceofweek = price;
				label108->Text = "SUCCESS";
			}

		}
	}



}
private: System::Void listView1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button56_Click(System::Object^ sender, System::EventArgs^ e) {
	int idx = 0;
	msclr::interop::marshal_context context;
	for (int i = 0; i < mednum; i++)
	{
		string name = med[i].name;
		string stock = std::to_string(med[i].stock);
		listView1->Items->Add(gcnew String(name.c_str()));
		listView1->Items[idx]->SubItems->Add(gcnew String(stock.c_str()));
		if (med[i].stock < 5)
		{
			listView1->Items[idx]->SubItems->Add("RECOMMENDED PRODUCT");
		}
		idx++;
	}





}
private: System::Void button39_Click(System::Object^ sender, System::EventArgs^ e) {
	msclr::interop::marshal_context context;
	label118->Text = "";
	bool valid = true;
	if (textBox11->Text == "")
	{
		MessageBox::Show("Pleaase enter a value");
	}
	else
	{
		string id;
		id = context.marshal_as<std::string>(textBox11->Text);
		if (id.length() > 1)
		{
			if (id[0] == 's' || id[0] == 'S')
			{
				for (int i = 1; i < id.length(); i++)
				{
					if (!isdigit(id[i]))
					{
						valid = false;
						break;
					}
				}
				if (valid)
				{
					int num = stoi(id.substr(1));
					int res = 0;
					bool found = false;
					for (int j = 0; j < suppnum; j++)
					{
						if (supp[j].id == num)
						{
							found = true;
							res = j;
							label118->Text = "DELETED SUCCESSFULLY";
							break;
						}
					}
					if (found)
					{
						for (int idx = res; idx < suppnum; idx++)
						{
							supp[idx].id = supp[idx + 1].id;
							supp[idx].name = supp[idx + 1].name;
							supp[idx].phone = supp[idx + 1].phone;
							supp[idx].num = supp[idx + 1].num;
							for (int s = 0; s < supp[idx].num; s++)
							{
								supp[idx].suppproducts[s] = supp[idx + 1].suppproducts[s];
							}
							
					    }
						suppnum--;
					}
					else
					{
						label118->Text = "NOT FOUND";
					}
				}
			}
			else
			{
				label118->Text = "NOT FOUND";
			}
		}
		else
		{
			label118->Text = "NOT FOUND";
		}
	}




}
private: System::Void addsupplier_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void button57_Click(System::Object^ sender, System::EventArgs^ e) {
	if (textBox21->Text == "" || textBox23->Text == "" || supplierproducts->Text == "")
	{
		MessageBox::Show("Pleaase enter a value");
	}
	else
	{
		msclr::interop::marshal_context context;

    int f = suppnum;
	bool fs = false;
	supp[f].name = context.marshal_as<std::string>(textBox21->Text);
	supp[f].phone = context.marshal_as<std::string>(textBox23->Text);
	string cut  = context.marshal_as<std::string>(supplierproducts->Text);
	int idx = 0;
	int count = 0; // number of medicines
	int start1 = 0;
	int newline = 0;
	int letterc = 0;
	bool medname = false;
	for (int i = 0; i < cut.length(); i++)
	{
		if (isdigit(cut[i]))
		{
			medname = true;
			break;
		}
		if (cut[i] == '\n' && isalpha(cut[i - 1]) != 0)
		{
			newline++;
			for (int j = start1; j < i; j++)
			{
				supp[f].suppproducts[idx] += cut[j];
				letterc++;
			}
			supp[f].num++;
			idx++;
			start1 = i + 1;
		}
	}

	supp[f].num++;
	if ((cut.length() - (letterc + newline)) > 0)
	{
		for (int q = start1; q < cut.length(); q++)
		{
			supp[f].suppproducts[idx] += cut[q];
		}
	}
	if (medname)
	{
		MessageBox::Show(" Purchased Products do not contain numbers!");
		fs = true;
	}
	for (int i = 0; i < suppnum; i++)
	{
		if (medname)
		{
			break;
		}

		if (supp[i].name == supp[f].name)
		{
			label122->Text = "This customer already exists";
			fs = true;



		}
	}
	if (!fs)
	{

		label122->Text = "Added successfully";
		textBox21->Text = "";
		textBox23->Text = "";
		supplierproducts->Text = "";

		if (f == 0)
		{
			supp[f].id = 1; //if its first customer
		}
		else
		{
			supp[f].id = supp[f - 1].id + 1; //else take id of previous customer
		}
		for (int pp = 0; pp < mednum; pp++)
		{
			for (int jj = 0; jj <= idx; jj++)
			{
				if (med[pp].name == supp[f].suppproducts[jj])
				{
					med[pp].stock++;
				}
			}
		}

		//f++;
		suppnum++;

	}
	}
	




















}
private: System::Void button32_Click(System::Object^ sender, System::EventArgs^ e) {
	if (textBox8->Text == "")
	{
		MessageBox::Show("Please enter a value");

	}
	else
	{
		msclr::interop::marshal_context context;
		bool entry, verified;

		verified = false;
		entry = false;
		string name;
		name = context.marshal_as<std::string>(textBox8->Text);

		for (int i = 0; i < suppnum; i++)
		{
			if (supp[i].name == name)
			{
				entry = true;
				string tmp = std::to_string(supp[i].id);
				String^ suppid1 = gcnew String(tmp.c_str());
				label72->Text = "S" + suppid1;
				tmp = supp[i].name;
				String^ suppname1 = gcnew String(supp[i].name.c_str());
				label71->Text = suppname1;
				tmp = supp[i].phone;
				String^ suppphone1 = gcnew String(tmp.c_str());
				label70->Text = suppphone1;
				tmp = "";
				for (int j = 0; j < supp[i].num; j++)
				{
					if (j == supp[i].num - 1)
					{
						tmp += supp[i].suppproducts[j];

					}
					else
					{
						tmp += supp[i].suppproducts[j] + ',';
					}


				}
				String^ txt = gcnew String(tmp.c_str());
				label69->Text = txt;
			}
		}
		if (!entry)
		{
			MessageBox::Show("RECORDS NOT FOUND");
			label29->Text = "";
			label28->Text = "";
			label27->Text = "";
			label26->Text = "";
			label24->Text = "";
			label25->Text = "";

		}


	}











}
private: System::Void button26_Click(System::Object^ sender, System::EventArgs^ e) {
	if (textBox6->Text == "")
	{
		MessageBox::Show("Please enter a value");

	}
	else
	{
		msclr::interop::marshal_context context;
		bool entry, verified;
		int res = 0;
		verified = false;
		entry = false;
		string phone;
		phone = context.marshal_as<std::string>(textBox6->Text);
		
			for (int i = 0; i < custnum; i++) {

				if (cust[i].phone == phone) {
					entry = true;
					string tmp;
					tmp = std::to_string(cust[i].id);
					String^ custid1 = gcnew String(tmp.c_str());
					label60->Text = "U" + custid1;
					tmp = cust[i].name;
					String^ custname1 = gcnew String(tmp.c_str());
					label59->Text = custname1;
					tmp = cust[i].phone;
					String^ custphone1 = gcnew String(tmp.c_str());
					label58->Text = custphone1;
					tmp = "";
					for (int j = 0; j < cust[i].num; j++)
					{
						if (j == cust[i].num - 1)
						{
							tmp += cust[i].custproducts[j];

						}
						else
						{
							tmp += cust[i].custproducts[j] + ',';
						}


					}

					String^ custproducts1 = gcnew String(tmp.c_str());
					label57->Text = custproducts1;
					tmp = cust[i].date;
					String^ custdate1 = gcnew String(tmp.c_str());
					label55->Text = custdate1;
					tmp = cust[i].Billvalue;
					String^ billvalue1 = gcnew String(tmp.c_str());
					label56->Text = billvalue1;
					tmp = cust[i].TotalPriceofweek;
					String^ weekprice = gcnew String(tmp.c_str());
					label53->Text = weekprice;
				}
			}
		



		if (!entry)
		{
			MessageBox::Show("RECORDS NOT FOUND");
			medid->Text = "";
			medname->Text = "";
			medstock->Text = "";
			medprice->Text = "";
			meddate->Text = "";
			medsuppliername->Text = "";

		}


	}




}
private: System::Void updatecustphone_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void button58_Click(System::Object^ sender, System::EventArgs^ e) {

	updatecust->BringToFront();
}
private: System::Void button59_Click(System::Object^ sender, System::EventArgs^ e) {
	updatecust->BringToFront();
}
private: System::Void button60_Click(System::Object^ sender, System::EventArgs^ e) {
	updatesupp->BringToFront();
}
private: System::Void button61_Click(System::Object^ sender, System::EventArgs^ e) {
	updatesupp->BringToFront();

}
private: System::Void button25_Click(System::Object^ sender, System::EventArgs^ e) {
	searchcustp->BringToFront();
}
private: System::Void button17_Click(System::Object^ sender, System::EventArgs^ e) {
	searchcustp->BringToFront();

}
private: System::Void searchcustidp_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void button40_Click(System::Object^ sender, System::EventArgs^ e) {

	label123->Text = "";
	bool valid = true;
	int res = 0;
	if (textBox12->Text == "")
	{
		MessageBox::Show("Pleaase enter a value");
	}
	else
	{
		bool found;
		bool notalpha = false;
		msclr::interop::marshal_context context; //used to be able to convert from System string to string
		string name;
		name = context.marshal_as<std::string>(textBox12->Text);
		for (int i = 0; i < name.length(); i++)
		{
			if (isalpha(name[i]) == 0)
			{
				notalpha = true;
			}

		}
		if (notalpha)
		{
			MessageBox::Show("Invalid Supplier's name!");
		}
		else {
			for (int i = 0; i < suppnum; i++) {
				if (supp[i].name == name) {
					found = true;
					res = i;
					label123->Text = "DELETED SUCCESSFULLY";
					break;
				}
			}
		}
		if (found) {
			for (int idx = res; idx < suppnum; idx++)
			{
				supp[idx].id = supp[idx + 1].id;
				supp[idx].name = supp[idx + 1].name;
				supp[idx].phone = supp[idx + 1].phone;
				supp[idx].num = supp[idx + 1].num;
				for (int s = 0; s < supp[idx].num; s++)
				{
					supp[idx].suppproducts[s] = supp[idx + 1].suppproducts[s];
				}

			}
			suppnum--;
		}
		else {
			MessageBox::Show("Invalid Supplier's name!");
		}



	}







}
private: System::Void label123_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button41_Click(System::Object^ sender, System::EventArgs^ e) {
	msclr::interop::marshal_context context;
	label124->Text = "";
	bool valid = true;
	if (textBox13->Text == "")
	{
		MessageBox::Show("Pleaase enter a value");
	}
	else
	{
		string id;
		id = context.marshal_as<std::string>(textBox13->Text);
		if (id.length() > 1)
		{
			if (id[0] == 'm' || id[0] == 'M')
			{
				for (int i = 1; i < id.length(); i++)
				{
					if (!isdigit(id[i]))
					{
						valid = false;
						break;
					}
				}
				if (valid)
				{
					int num = stoi(id.substr(1));
					int res = 0;
					bool found = false;
					for (int j = 0; j < mednum; j++)
					{
						if (med[j].id == num)
						{
							found = true;
							res = j;
							label124->Text = "DELETED SUCCESSFULLY";
							break;
						}
					}
					if (found)
					{
						for (int idx = res; idx < mednum; idx++)
						{
							med[idx].id = med[idx + 1].id;
							med[idx].stock = med[idx + 1].stock;
							med[idx].name = med[idx + 1].name;
							med[idx].SupplierName = med[idx + 1].SupplierName;
							med[idx].price = med[idx + 1].price;
							med[idx].date = med[idx + 1].date;

						}
						mednum--;
					}
					else
					{
						label124->Text = "NOT FOUND";
					}
				}
			}
			else
			{
				label124->Text = "NOT FOUND";
			}
		}
		else
		{
			label124->Text = "NOT FOUND";
		}
	}
}
private: System::Void button42_Click_1(System::Object^ sender, System::EventArgs^ e) {
	label125->Text = "";
	bool valid = true;
	int res = 0;
	if (textBox14->Text == "")
	{
		MessageBox::Show("Pleaase enter a value");
	}
	else
	{
		bool found;
		bool notalpha = false;
		msclr::interop::marshal_context context; //used to be able to convert from System string to string
		string name;
		name = context.marshal_as<std::string>(textBox14->Text);
		for (int i = 0; i < name.length(); i++)
		{
			if (isalpha(name[i]) == 0)
			{
				notalpha = true;
			}

		}
		if (notalpha)
		{
			MessageBox::Show("Invalid Product's name!");
		}
		else {
			for (int i = 0; i < mednum; i++) {
				if (med[i].name == name) {
					found = true;
					res = i;
					label125->Text = "DELETED SUCCESSFULLY";
					break;
				}
			}
		}
		if (found) {
			for (int idx = res; idx < mednum; idx++)
			{
				med[idx].id = med[idx + 1].id;
				med[idx].stock = med[idx + 1].stock;
				med[idx].name = med[idx + 1].name;
				med[idx].SupplierName = med[idx + 1].SupplierName;
				med[idx].price = med[idx + 1].price;
				med[idx].date = med[idx + 1].date;

			}
			mednum--;
		}
		else {
			MessageBox::Show("NOT FOUND!");
		}



	}
}
private: System::Void button38_Click(System::Object^ sender, System::EventArgs^ e) {
	if (textBox10->Text == "")
	{
		MessageBox::Show("Please enter a value");

	}
	else
	{
		msclr::interop::marshal_context context;
		bool entry, verified;
		int res = 0;
		bool found = false;
		string phone;
		phone = context.marshal_as<std::string>(textBox10->Text);

		for (int j = 0; j < custnum; j++)
		{
			if (cust[j].phone == phone)
			{
				found = true;
				res = j;
				label127->Text = "DELETED SUCCESSFULLY";
				break;
			}
		}
		if (found)
		{
			for (int idx = res; idx < custnum; idx++)
			{
				cust[idx].id = cust[idx + 1].id;
				cust[idx].name = cust[idx + 1].name;
				cust[idx].phone = cust[idx + 1].phone;
				cust[idx].num = cust[idx + 1].num;
				for (int s = 0; s < cust[idx].num; s++)
				{
					cust[idx].custproducts[s] = cust[idx + 1].custproducts[s];
				}

			}
			custnum--;
		}
		else
		{
			label127->Text = "NOT FOUND";
		}
	}


















}
private: System::Void button37_Click_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button37_Click_2(System::Object^ sender, System::EventArgs^ e) {
	msclr::interop::marshal_context context;
	label126->Text = "";
	bool valid = true;
	if (textBox9->Text == "")
	{
		MessageBox::Show("Pleaase enter a value");
	}
	else
	{
		string id;
		id = context.marshal_as<std::string>(textBox9->Text);
		if (id.length() > 1)
		{
			if (id[0] == 'u' || id[0] == 'U')
			{
				for (int i = 1; i < id.length(); i++)
				{
					if (!isdigit(id[i]))
					{
						valid = false;
						break;
					}
				}
				if (valid)
				{
					int num = stoi(id.substr(1));
					int res = 0;
					bool found = false;
					for (int j = 0; j < custnum; j++)
					{
						if (cust[j].id == num)
						{
							found = true;
							res = j;
							label126->Text = "DELETED SUCCESSFULLY";
							break;
						}
					}
					if (found)
					{
						for (int idx = res; idx < custnum; idx++)
						{
							cust[idx].id = cust[idx + 1].id;
							cust[idx].name = cust[idx + 1].name;
							cust[idx].phone = cust[idx + 1].phone;
							cust[idx].num = cust[idx + 1].num;
							for (int s = 0; s < cust[idx].num; s++)
							{
								cust[idx].custproducts[s] = cust[idx + 1].custproducts[s];
							}

						}
						custnum--;
					}
					else
					{
						label126->Text = "NOT FOUND";
					}
				}
			}
			else
			{
				label126->Text = "NOT FOUND";
			}
		}
		else
		{
			label126->Text = "NOT FOUND";
		}
	}
}
private: System::Void button30_Click(System::Object^ sender, System::EventArgs^ e) {
	if (textBox7->Text == "")
	{
		MessageBox::Show("Please enter a value");

	}
	else
	{
		msclr::interop::marshal_context context;
		bool entry, verified;

		verified = false;
		entry = false;
		string id;
		id = context.marshal_as<std::string>(textBox7->Text);
		if ((id[0] == 's' || id[0] == 'S') && id.length() > 1)
		{
			for (int i = 1; i < id.length(); i++)
			{
				if (!isdigit(id[i]))
				{
					verified = true;
				}
			}

			if (!verified)
			{
				int k = stoi(id.substr(1));
				string c = id.substr(0, 1);
				for (int i = 0; i < suppnum; i++)
				{
					if (supp[i].id == k && (c == "s" || c == "S"))
					{
						entry = true;
						string tmp = std::to_string(supp[i].id);
						String^ suppid1 = gcnew String(tmp.c_str());
						label76->Text = "S" + suppid1;
						tmp = supp[i].name;
						String^ suppname1 = gcnew String(tmp.c_str());
						label75->Text = suppname1;
						tmp = supp[i].phone;
						String^ suppphone1 = gcnew String(tmp.c_str());
						label74->Text = suppphone1;
						tmp = "";
						for (int j = 0; j < supp[i].num; j++)
						{
							if (j == supp[i].num - 1)
							{
								tmp += supp[i].suppproducts[j];

							}
							else
							{
								tmp += supp[i].suppproducts[j] + ',';
							}


						}
						String^ suppproducts1 = gcnew String(tmp.c_str());
						label73->Text = suppproducts1;


					}
				}
				if (!entry)
				{
					MessageBox::Show("RECORDS NOT FOUND");
				}


			}
			else
			{
				MessageBox::Show("RECORDS NOT FOUND");

			}





		}
		else
		{
			MessageBox::Show("RECORDS NOT FOUND");
		}

	}
















}
private: System::Void button31_Click(System::Object^ sender, System::EventArgs^ e) {
	searchsupp->BringToFront();
}
private: System::Void button29_Click(System::Object^ sender, System::EventArgs^ e) {
	searchsupp->BringToFront();
}
private: System::Void button62_Click(System::Object^ sender, System::EventArgs^ e) {
	deletesup->BringToFront();
}
private: System::Void button63_Click(System::Object^ sender, System::EventArgs^ e) {
	deletesup->BringToFront();
}
private: System::Void button64_Click(System::Object^ sender, System::EventArgs^ e) {
	deleteproduct->BringToFront();


}
private: System::Void button65_Click(System::Object^ sender, System::EventArgs^ e) {
	deleteproduct->BringToFront();
}
private: System::Void button67_Click(System::Object^ sender, System::EventArgs^ e) {
	deletecust->BringToFront();
}
private: System::Void button66_Click(System::Object^ sender, System::EventArgs^ e) {
	deletecust->BringToFront();
}
private: System::Void panel16_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
};
}
