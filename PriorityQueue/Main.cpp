#pragma once
#include "Includes.h"



int main()
{
	int zahl;
	unsigned int lenght;

	srand(time(0));

	int random = rand() % 4000;

	//cout << "Filename: ";
	string filename = "test";
	//cin >> filename;

	ifstream f(filename);
	f >> lenght;
	PrioQueue schlange(lenght);
	int *bufInt = new int[lenght];
	int *bufInt2 = new int[lenght];

	unsigned int index = 0;
	while (!f.eof() && index < lenght)
	{
		f >> zahl;
		bufInt[index++] = zahl;
	}


	cout << "Starte insert" << endl;
	int ende, start = clock();
	for (size_t i = 0; i < index; i++)
	{
		schlange.insert(bufInt[i]);
	}

	ende = clock() - start;

	cout << "UpHeap: " << ende << "ms" << endl;
	cout << "------------------------------" << endl;
	start = clock();

	cout << "Starte extractMax()" << endl;
	for (size_t i = 0; i < index; i++)
	{
		bufInt[i] = schlange.extractMax();
	}
	ende = clock() - start;
	cout << "DownHeap: " << ende << "ms" << endl;
	cout << "------------------------------" << endl;

	cout << "Schreibe in Datei" << endl;
	ofstream ausgabe("out.txt");
	for (size_t i = 0; i < index; i++)
	{
		ausgabe << bufInt[i] << endl;
	}
	ausgabe.close();
	cout << "------------------------------" << endl;

	cout << "Fuehre update() durch" << endl;
	start = clock();
	schlange.update(6, -3);
	ende = clock() - start;

	cout << "update: " << ende << "ms" << endl;
	cout << "------------------------------" << endl;

	for (size_t i = 0; i < index; i++)
	{
		bufInt2[i] = schlange.extractMax();
	}
	
	cout << "Schreibe geupdatete Version in Datei" << endl;
	ofstream ausgabe2("out_update.txt");
	for (size_t i = 0; i < index; i++)
	{
		ausgabe2 << bufInt2[i] << endl;
	}
	ausgabe2.close();

	schlange.remove(3);

	for (size_t i = 0; i < lenght; i++)
	{
		cout << schlange.extractMax() << endl;
	}
}