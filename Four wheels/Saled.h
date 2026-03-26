#pragma once
#include "ArrayTemplate.h"
#include "Date.h"
#include "Sale_auto.h"
#include <ctime>
#include <iostream>
using namespace std;


struct Saled {
	char Sale_VIN[18] = "";
	char Name_manager[100] = "";
	char Name_buyer[100] = "";
	char Buyer_tel[11] = "";
	char Address[300] = "";
	char ID[11] = "";
	Date Sale_date;


	void Sale_car() {
		cout << "Enter car VIN code (17 symbols): " << endl;
		cin.getline(Sale_VIN, 18);
		cout << "Enter manager name (Last name, First name, Middle name): " << endl;
		cin.getline(Name_manager, 100);
		cout << "Enter buyer name (Last name, First name, Middle name): " << endl;
		cin.getline(Name_buyer, 100);
		cout << "Enter buyer tel. number: +38" << endl;
		cin.getline(Buyer_tel, 11);
		cout << "Enter buyer address (Country, Region, City/Vilage, Street, Bilding number): " << endl;
		cin.getline(Address, 300);
		cout << "Enter your ID code: " << endl;
		cin.getline(ID, 11);
		cout << "Enter date of sale (dd mm yyyy): " << endl;
		cin >> Sale_date.day >> Sale_date.month >> Sale_date.year;
		
	}

	void Sale_car_list() {
		cout << "╔═════════════════════════════════════════════════════════════════════╗" << endl;
		cout << " Car VIN code: " << Sale_VIN <<endl;
		cout << " Manager name: " << Name_manager <<endl;
		cout << " Buyer name: " << Name_buyer <<endl;
		cout << " Buyer tel. number: " << Buyer_tel <<endl;
		cout << " Buyer address: " << Address <<endl;
		cout << " Buyer ID: " << ID <<endl;
		cout << " Date of sale: " << Sale_date.toString("%d.%m.%Y") << endl;
		cout << "╚═════════════════════════════════════════════════════════════════════╝" << endl;

	}

	
	
};