#pragma once
#include "Includes.h"



int main()
{
	int zahl;
	unsigned int length;

	srand(time(0));

	int random = rand() % 4000;

	//cout << "Filename: ";
	string filename = "test3";
	//cin >> filename;

	ifstream f(filename);
	f >> length;
	PrioQueue schlange(length);
	int *bufInt = new int[length];

	unsigned int index = 0;
	while (!f.eof() && index < length)
	{
		f >> zahl;
		bufInt[index++] = zahl;
	}

	int ende, start = clock();

	
	for (size_t i = 0; i < index; i++)
	{
		schlange.insert(bufInt[i]);
	}

	ende = clock() - start;

	cout << "UpHeap: " << ende << "ms" << endl;
	cout << "------------------------------" << endl;


	

	start = clock();
	for (size_t i = 0; i < index; i++)
	{
		bufInt[i] = schlange.extractMax();
	}
	ende = clock() - start;
	cout << "DownHeap: " << ende << "ms" << endl;

	ofstream ausgabe("out.txt");
	for (size_t i = 0; i < index; i++)
	{
		ausgabe << bufInt[i] << endl;
	}
	ausgabe.close();

}