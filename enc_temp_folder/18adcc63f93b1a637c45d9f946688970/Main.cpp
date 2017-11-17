#pragma once
#include "Includes.h"



int main()
{
	int zahl;
	unsigned int length;

	srand(time(0));

	int random = rand() % 4000;

	cout << "Filename: ";
	string filename = "test";
	//cin >> filename;

	ifstream f(filename);
	f >> length;
	PrioQueue schlange(length);

	unsigned int index = 0;
	while (!f.eof() && index <= length)
	{
		f >> zahl;
		schlange.insert(zahl);
	}
	cout << "Eingelesen: " << index << endl;

	int ende, start = clock();
	////////////////////////////
	ende = ((clock() - start) * 1000) / CLOCKS_PER_SEC;

	ofstream ausgabe("out.txt");
	for (size_t i = 0; i < length; i++)
	{
		ausgabe << schlange.extractMax() << endl;
	}
	ausgabe.close();

	cout << "Time to finished: " << ende << "ms" << endl;

}