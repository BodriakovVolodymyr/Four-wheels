#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//Заповненнч масиву випадковими числами від А до Б

template <typename Type>
void randArray(Type arr[], int size, int A = 0, int B = 10) {
	for (int i = 0; i < size; i++)
		arr[i] = rand() % (B - A + 1) + A;
}


//Виведення

template <typename Type>
void printArray(Type arr[], int size, int Wcout = 4)
{
	for (int i = 0; i < size; i++)
	{
		cout.width(Wcout);
		cout << arr[i];
	}
	cout << endl;
}

//Find index min and max element of masive


template <typename T>
int indexMaxElement(T arr[], int size)
{
	T max = arr [0];
	int index = 0;
	for (int i = 1; i < size; i++)
	{
		if (arr[i] > max)
			max = arr[i];
			index = i;
	}
	return index;
}
template <typename T>
int indexMinElement(T arr[], int size)
{
	T min = arr[0];
	int index = 0;
	for (int i = 1; i < size; i++)
	{
		if (arr[i] < min)
			min = arr[i];
		index = i;
	}
	return index;
}
	//TASK4~~~~~~~~~~~~~~~~~~~~~~~

// Знаходження суми всіх елементів масиву

template <typename T>
T sumArray(T arr[], int size)
{
	T sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += i;
	}
	return sum;
}

//TASK5~~~~~~~~~~~~~~~~~~~~~~~


//Функція для знаходження елемента масиву із заданим значенням value
template <typename Type>
int search(Type arr[], int size, Type value) {
	int index = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i] == value) {
			return i;
		}
		return -1;
	}
}

//Homework 03.03~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


//Task2~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

template <typename T>
void smoothArray(T arr[], const int size) {
	for (int i = 0; i < size; i++)
	{
		if (i == size - 1)
		{
			arr[i] = arr[i];
		}
		else {
			arr[i] = (arr[i] + arr[i + 1]) / 2;
		}
	}

}

//Task3~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


template <typename T>
double averageMoreM(T arr[], const int size, T m) {
	double arithmetic_mean = 0;
	int count = 0;
	
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > m)
		{
			arithmetic_mean += arr[i];
			count++;
		}
	}
	if (count == 0)
		return 0;
	else
	return arithmetic_mean / count;

}

//09.03.2026~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//функція яка додає новий елемент в кінець масиву
template <typename T>
void addItemBack(T*& arr, int& size, T value)
{
	//створюємо масив на +1клітинку більше
	T* tmp = new T[size + 1];
	//переносимо дані з старого масиву до новго
	for (int i = 0; i < size; i++) {
		tmp[i] = arr[i];
	}
	//видалення старого масиву
	if (arr != nullptr) delete[] arr;

	//додати новий елемент в кінець

	tmp[size] = value;
	
	//переприв'язуємо показчик на нову адресу

	arr = tmp;

	//оновлюємо розмір масиву
	size++;
	
}

template <typename T>

void addItemStart(T*& arr, int& size, T value) {

	//1 - Створюємо масив +1 клітинку більше

	T* tmp = new T[size + 1];

	//2 - Переносимо дані зі старого масиву до нового

	for (int i = 0; i < size; i++) {

		tmp[i + 1] = arr[i];

	}

	//3 - Видаляємо старий масив

	if (arr != nullptr) delete[] arr;

	//4 - Додаємо новий елемент в початок

	tmp[0] = value;

	// 5.1 - Перепривʼязуємо покажчик на нову адресу

	arr = tmp;

	//5.2 - Оновлюємо розмір масиву

	size++;

}

template <typename T>

void deleteItem(T*& arr, int &size, T index) 

{
	T* tmp = new T[size -1];
	int j = 0;
	for (int i = 0; i < size; i++)
	{
		if (i != index)
		{
			tmp[j++] = arr[i];

		}
	}
	if (arr != nullptr)
		{
			delete[]arr;

		}
	
	arr = tmp; 
	size--;

}


template <typename T>

int amountEven(T* arr, int size) {

	int amount = 0;

	for (int i = 0; i < size; i++) {

		if (arr[i] % 2 == 0) {

			amount++;

		}

	}

	return amount;

}


template <typename T>

void createEvenArray(T* arr, int size, T*& even, int& sizeEven) {

	sizeEven = amountEven(arr, size);

	if (sizeEven == 0) {

		return;

	}

	else {

		even = new T[sizeEven];

		int j = 0;

		for (int i = 0; i < size; i++) {

			if (arr[i] % 2 == 0) {

				even[j++] = arr[i];

			}

		}

	}

}


//Homework 09.03  Task4~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


template <typename T>

void createArrayBetween(T* arr, int size, int from, int to, T*& sub_arr, int& sub_size)
{
	if (from > to || from < 0 || to >= size)
	{
		sub_arr = nullptr;
		sub_size = 0;
		return;
	}
	sub_size = to - from +1;
	
		sub_arr = new T[sub_size];
		int j = 0;
		for (int i = from; i < to + 1; i++)
			sub_arr[j++] = arr[i];
	
}

//  функцію, яка визначає кількість елементів масиву за критерієм:
template <typename T>
int myCountIf(T* arr, int size, bool (*fP)(T))
{
	int amount = 0;
	for (int i = 0; i < size; i++)
	{
		if (fP(arr[i]) == true)
		{
			amount++;
		}

	}
	return amount;
}

//Task2~~~~~~~~~~~~~~~~
//функцію, яка визначає суму елементів масиву за критерієм
template <typename T>
T mySumIf(T* arr, int size, bool (*fP)(T))
{
	T sum = 0;
	for (int i = 0; i < size; i++)
	{
		if (fP(arr[i]) == true)
			sum += arr[i];

	}
	return sum;
}


//Task3~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//функцію, яка знаходить Індекс першого елемента масиву за критерієм :

template <typename T>
int myFindIf(T* arr, int size, bool (*fP)(T))
{
	int index = -1;
	for (int i = 0; i < size; i++)
	{
		if (fP(arr[i]) == true)
		{
			index = i;
			break;
		}
	}
	return index;
}


//Task4~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//функцію, яка в масиві замінює елементи за критерієм на значення value
template <typename T>
void myReplaceIf(T* arr, int size, bool (*fP)(T), T value)
{
	for (int i = 0; i < size;i++)
		if (fP(arr[i]) == true)
		{
			arr[i] = value;

		}
	
}


//Task5~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//функцію, яка в масиві видаляє елементи за критерієм


template <typename T>
void myRemoveIf(T*& arr, int& size, bool (*fP)(T))
{
	for (int i = 0; i < size; i++)
		if (fP(arr[i]) == true)
		{
			deleteItem(arr, size, i);
			i--;
		}

}


//функцію, яка знаходить Індекс останнього елемента масиву за критерієм

template <typename T>
int myFindLast_if(T* arr, int size, bool (*fP)(T))
{
	int index = -1;
	for (int i = 0; i < size; i++)
	{
		if (fP(arr[i]) == true)
		{
			index = i;
			
		}
	}
	return index;
}


// функцію сортування масиву

template <typename T>
void mySort(T* arr, int size, bool (*cmp)(T, T))
{
	//BABBLE SORTING ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (cmp(arr[j], arr[j + 1])==true)
			{
				T temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}


}



template <typename T>
void carFind(T* arr, int N, const char* user) {
	bool status = false;
	for (int i = 0; i < N; i++)
	{
		if (arr[i].Saled == false) {
			if (_stricmp(arr[i].Brand, user) == 0)
			{
				cout << "╔═════════════════════════════════════════════════════════════════════╗" << endl;
				cout << "║                        THE CAR IS AVAILABLE!                        ║" << endl;
				cout << "╚═════════════════════════════════════════════════════════════════════╝" << endl;

				arr[i].carList();
				status = true;
			}
			else if (_stricmp(arr[i].Model, user) == 0)
			{
				cout << "╔═════════════════════════════════════════════════════════════════════╗" << endl;
				cout << "║                        THE CAR IS AVAILABLE!                        ║" << endl;
				cout << "╚═════════════════════════════════════════════════════════════════════╝" << endl;

				arr[i].carList();
				status = true;
			}
		}
		else if (arr[i].Saled == true){
			if (_stricmp(arr[i].Brand, user) == 0)
			{
				arr[i].Saled = false;
				cout << "╔═════════════════════════════════════════════════════════════════════╗" << endl;
				cout << "║                              CAR SOLD!                              ║" << endl;
				cout << "╚═════════════════════════════════════════════════════════════════════╝" << endl;

				arr[i].carList();

				status = true;
				arr[i].Saled = true;
			}
			else if (_stricmp(arr[i].Model, user) == 0)
			{
				arr[i].Saled = false;
				cout << "╔═════════════════════════════════════════════════════════════════════╗" << endl;
				cout << "║                              CAR SOLD!                              ║" << endl;
				cout << "╚═════════════════════════════════════════════════════════════════════╝" << endl;

				arr[i].carList();

				status = true;
				arr[i].Saled = true;
			}
		
		}
	}
	if (!status)
	{
		cout << "\t\t\t\t\t\t╔═══════════════════════════════╗\n";
		cout << "\t\t\t\t\t\t║         CAR NOT FOUND         ║\n";
		cout << "\t\t\t\t\t\t╚═══════════════════════════════╝\n";
	}
}


void pause()
{
	cout  << "PRESS ENTHER TO GO MENU";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.get();
}
