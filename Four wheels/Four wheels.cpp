
#include <iostream>
#include <cstdlib>
#include "ArrayTemplate.h"
#include "Sale_Auto.h"
#include "Saled.h"
#include <cstring>



int main()
{
	system("chcp 65001");
	system("cls");
	int N = 0;
	Sale_auto* arr = nullptr;
	
	Saled* arrSaled = nullptr;
	int sizeSaled = 0;
	int menu = 0;


	FILE* Saled_Auto_file = nullptr;
	
	fopen_s(&Saled_Auto_file, "Saled_Auto.txt", "r");
	
	if (Saled_Auto_file != nullptr)
	{
		Sale_auto temp;
		
		while (fscanf_s(Saled_Auto_file, "%s %s %s %d %lf %s %s %lf %d",
			temp.Brand, 50, temp.Model, 50, temp.VIN, 18, &temp.Production_year,
			&temp.Engine_volume, temp.Color, 20, temp.Body_type, 30, &temp.Cost, &temp.Saled
		) == 9)
		{
			addItemBack(arr, N, temp);
		}
		
		fclose(Saled_Auto_file);
		cout << "\t\t\t\t\t\t╔═══════════════════════════════╗\n";
		cout << "\t\t\t\t\t\t║      WELLCOME BACK  👋🏼😉      ║\n";
		cout << "\t\t\t\t\t\t╚═══════════════════════════════╝\n";
		pause();
	}
	else {


	};





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
				cout << "\t\t\t\t\t\t║   INVALID BUYER TEL. NUMBER!  ║\n";
				cout << "\t\t\t\t\t\t╚═══════════════════════════════╝\n";
				pause();
				break;
			}
			else if (strlen(tmp.ID) != 10)
			{
				cout << "\t\t\t\t\t\t╔═══════════════════════════════╗\n";
				cout << "\t\t\t\t\t\t║    INVALID BUYER ID NUMBER!   ║\n";
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
							cout << "\t\t\t\t\t\t║   Sorry,car is already sold!  ║\n";
							cout << "\t\t\t\t\t\t╚═══════════════════════════════╝\n";
						}
						else {
							arr[i].Saled = true;
							addItemBack(arrSaled, sizeSaled, tmp);
							cout << "\t\t\t\t\t\t╔═══════════════════════════════╗\n";
							cout << "\t\t\t\t\t\t║      🎉Congratulations🎉      ║\n";
							cout << "\t\t\t\t\t\t║    🎊Car successful sold🎊    ║\n";
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

	Saled_Auto_file = nullptr;
	fopen_s(&Saled_Auto_file, "Saled_Auto.txt", "w");
	if (Saled_Auto_file == nullptr)
	{
		cout << "Error to write Sale Auto file";
		return 1;
	}
	else
	{
		for (int i = 0; i < N; i++)
		{
			fprintf(Saled_Auto_file, "%s %s %s %d %lf %s %s %lf %d\n",
				arr[i].Brand, arr[i].Model, arr[i].VIN, arr[i].Production_year,
				arr[i].Engine_volume,arr[i].Color, arr[i].Body_type, arr[i].Cost, arr[i].Saled);
		}
		fclose(Saled_Auto_file);

	}




	
	return 0;
}