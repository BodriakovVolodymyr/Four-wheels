
#include <iostream>
#include <cstdlib>
#include "ArrayTemplate.h"
#include "Sale_Auto.h"
#include "Saled.h"
#include <cstring>



int main()
{
	system("chcp 65001");
	int N = 5;
	Sale_auto* arr = new Sale_auto[N]{
		{"Volkswagen","Tiguan","1N4AL3AP0FC224651",2019,2.0,"Crossover",17700.00},
		{"Honda","Accord","2G1FC1EV5A9000507",2017,3.5,"Sedan",16500.00},
		{"Ford","Focus","2G4GK5EX5F9180596",2014,1.6,"Wagon",8300.00},
		{"Audi","A5","2G4WS52JX31277962",2011,1.8,"Hatchback",12699.00},
		{"Mercedes-Benz","E220","1C4BJWDG3FL524623",2018,2.0,"Coupe",37999.00},
	};
	Saled* arrSaled = nullptr;
	int sizeSaled = 0;
	int menu = 0;


	do {
		system("cls");
		cout << "\t\t\t\t\t\t                 🚗\n";
		cout << "\t\t\t\t\t\t╔═══════════════════════════════╗\n";
		cout << "\t\t\t\t\t\t║          CAR MANAGER          ║\n";
		cout << "\t\t\t\t\t\t║═══════════════════════════════║\n";
		cout << "\t\t\t\t\t\t║1. Add new car for sale        ║\n";
		cout << "\t\t\t\t\t\t║2. Show car list               ║\n";
		cout << "\t\t\t\t\t\t║3. Sale car                    ║\n";
		cout << "\t\t\t\t\t\t║4. Show saled car info         ║\n";
		cout << "\t\t\t\t\t\t║5. Find car                    ║\n";
		cout << "\t\t\t\t\t\t║0. Exit                        ║\n";
		cout << "\t\t\t\t\t\t╚═══════════════════════════════╝\n";
		cout << "\t\t\t\t\t\t Choose option: ";
		cout << endl;
		cin >> menu;


		switch (menu) {
		case 0:
			system("cls");
			cout << "\t\t\t\t\t\t╔═══════════════════════════════╗\n";
			cout << "\t\t\t\t\t\t║     🚗💨 Have a good day!     ║\n";
			cout << "\t\t\t\t\t\t╚═══════════════════════════════╝\n"; break;
		case 1: {
			system("cls");
			Sale_auto tmp;
			cin.ignore();
			tmp.addAuto();
			if (strlen(tmp.VIN) != 17)
			{
				cout << "\t\t\t\t\t\t╔═══════════════════════════════╗\n";
				cout << "\t\t\t\t\t\t║       INVALID VIN CODE!       ║\n";
				cout << "\t\t\t\t\t\t╚═══════════════════════════════╝\n";
				pause();
				break;
			}
			addItemBack(arr, N, tmp);
			cout << "\t\t\t\t\t\t╔═══════════════════════════════╗\n";
			cout << "\t\t\t\t\t\t║  CAR SUCCESSFULL ADD IN BASE  ║\n";
			cout << "\t\t\t\t\t\t╚═══════════════════════════════╝\n";
			pause();
		}break;
		case 2: {
			system("cls");
			for (int i = 0; i < N; i++)
			{
				arr[i].carList();
			}
			pause();
			
		}break;
		case 3: {
			system("cls");
			Saled tmp;
			cin.ignore();
			tmp.Sale_car();
			bool found = false;
			if (strlen(tmp.Buyer_tel) != 10)
			{
				cout << "\t\t\t\t\t\t╔═══════════════════════════════╗\n";
				cout << "\t\t\t\t\t\t║   INVALID BYER TEL. NUMBER!   ║\n";
				cout << "\t\t\t\t\t\t╚═══════════════════════════════╝\n";
				pause();
				break;
			}
			else if (strlen(tmp.ID) != 10)
			{
				cout << "\t\t\t\t\t\t╔═══════════════════════════════╗\n";
				cout << "\t\t\t\t\t\t║    INVALID BYER ID NUMBER!    ║\n";
				cout << "\t\t\t\t\t\t╚═══════════════════════════════╝\n";
				pause();
				break;
			}
			else if (strlen(tmp.Sale_VIN) != 17)
			{
				cout << "\t\t\t\t\t\t╔═══════════════════════════════╗\n";
				cout << "\t\t\t\t\t\t║       INVALID VIN CODE!       ║\n";
				cout << "\t\t\t\t\t\t╚═══════════════════════════════╝\n";
				pause();
				break;
			}
			else {
				for (int i = 0; i < N; i++)
				{


					if (strcmp(arr[i].VIN, tmp.Sale_VIN) == 0)
					{
						found = true;
						if (arr[i].Saled)
						{
							cout << "\t\t\t\t\t\t╔═══════════════════════════════╗\n";
							cout << "\t\t\t\t\t\t║   Sorry,car is alredy sold!   ║\n";
							cout << "\t\t\t\t\t\t╚═══════════════════════════════╝\n";
						}
						else {
							arr[i].Saled = true;
							addItemBack(arrSaled, sizeSaled, tmp);
							cout << "\t\t\t\t\t\t╔═══════════════════════════════╗\n";
							cout << "\t\t\t\t\t\t║      🎉Congradulations🎉      ║\n";
							cout << "\t\t\t\t\t\t║   🎊Car successfull sold🎊    ║\n";
							cout << "\t\t\t\t\t\t╚═══════════════════════════════╝\n";
						}
						break;

					}

				}
				if (!found)
				{
					cout << "\t\t\t\t\t\t╔═══════════════════════════════╗\n";
					cout << "\t\t\t\t\t\t║     CAR NOT FIND IN BASE!     ║\n";
					cout << "\t\t\t\t\t\t╚═══════════════════════════════╝\n";
				}
			}
			pause();
		}break;
		case 4: {
			system("cls");
			if (sizeSaled == 0)
			{
				cout << "\t\t\t\t\t\t╔═══════════════════════════════╗\n";
				cout << "\t\t\t\t\t\t║    SALED CAR LIST IS EMPTY    ║\n";
				cout << "\t\t\t\t\t\t╚═══════════════════════════════╝\n";
			}
			else {

				for (int i = 0; i < sizeSaled; i++)
				{					
						cout << "\t\t\t\t\t\t╔═══════════════════════════════╗\n";
						cout << "\t\t\t\t\t\t║              CAR              ║\n";
						cout << "\t\t\t\t\t\t╚═══════════════════════════════╝\n";
						
						for (int j = 0; j < N; j++)
						{
							if (strcmp(arr[j].VIN, arrSaled[i].Sale_VIN) == 0)
							{
								arr[j].Sold_car();
								break;
							}
						}

						cout << "\t\t\t\t\t\t╔═══════════════════════════════╗\n";
						cout << "\t\t\t\t\t\t║            SOLD BY            ║\n";
						cout << "\t\t\t\t\t\t╚═══════════════════════════════╝\n";

						arrSaled[i].Sale_car_list();
					}
				
				
			}
			pause();
		}break;
		case 5: {
			system("cls");
			char find_car[50] = "";
			cout << "Enter brand or model car for find in base: ";
			cin.ignore();
			cin.getline(find_car, 50);

			carFind(arr, N, find_car);
			pause();
		}break;
		}
	} while (menu != 0);

	return 0;
}