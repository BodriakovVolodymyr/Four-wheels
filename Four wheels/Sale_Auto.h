#pragma once
#include "ArrayTemplate.h"
#include <iomanip>
using namespace std;


struct Sale_auto {
	char Brand[50] = "";
	char Model[ 50 ] = "";
	char VIN[18] = "";
	int Production_year = 0;
	double Engine_volume = 0.0;
	char Color[20] = "";
	char Body_type[30] = "";
	double Cost = 0;
	bool Saled = false;




	void addAuto() {
		cout << "Input brand of car : ";
		cin.getline(Brand, 50);
		cout << "Input model: ";
		cin.getline(Model, 50);
		cout << "Input VIN code (17 symbols): ";
		cin.getline(VIN, 18);
		cout << "Input year of production: ";
		cin >> Production_year;
		cout << "Input engine volume: ";
		cin >> Engine_volume;
		cin.ignore();
		cout << "Input car color: ";
		cin.getline(Color, 20);
		cout << "Input type of body: ";
		cin.getline(Body_type, 30);
		cout << "Input car cost in $: ";
		cin >> Cost;
	}


	void carList() {
		if (!Saled)
		{
			cout << "╔═══════════════════════════════╗" << endl;
			cout << " Brand: " << Brand << endl;
			cout << " Model: " << Model << endl;
			cout << " VIN code: " << VIN << endl;
			cout << " Year of product: " << Production_year << endl;
			cout << " Engine volume: " << fixed << setprecision(1) << Engine_volume << endl;
			cout << " Car color: " << Color << endl;
			cout << " Type of body: " << Body_type << endl;
			cout << " Price: " << Cost << "$" << endl;
			cout << "╚═══════════════════════════════╝" << endl;
			cout << endl;
		}
	}

	void Sold_car() {
			
			cout << "╔═══════════════════════════════╗" << endl;
			cout << " Brand: " << Brand << endl;
			cout << " Model: " << Model << endl;
			cout << " VIN code: " << VIN << endl;
			cout << " Year of product: " << Production_year << endl;
			cout << " Engine volume: " << fixed << setprecision(1) << Engine_volume << endl;
			cout << " Car color: " << Color << endl;
			cout << " Type of body: " << Body_type << endl;
			cout << " Price: " << Cost << "$" << endl;
			cout << "╚═══════════════════════════════╝" << endl;
			cout << endl;
			
	}
	
	


};