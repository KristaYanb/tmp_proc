#include <iostream>
#include <fstream>
#include "container_atd.h"
using namespace std;

namespace simple_matrix
{
	// Сигнатуры требуемых внешних функций
	void Init(container& c);
	void Clear(container& c);
	void In(container& c, ifstream& ifst);
	void Sort(container& c);
	void OutSquare(container& c, ofstream& ofst);
	void Out(container& c, ofstream& ofst);
}
using namespace simple_matrix;

int main(int argc, char* argv[])
{
	if (argc != 3) 
	{
		cout << "incorrect command line! "
			"Waited: command infile outfile" << endl;

		exit(1);
	}

	ifstream ifst(argv[1]); //проверка наличия файла	
	if (!ifst)
	{
		cout << "No input file found!" << endl;
		return 0;
	}

	char ch; //проверка файла на пустоту
	FILE* f = fopen(argv[1], "r");
	if (fscanf(f, "%c", &ch) == EOF)
	{
		cout << "Input file is Empty" << endl;

		return 1;
	}
	fclose(f);

	ofstream ofst(argv[2]);

	cout << "Start" << endl;
	container c;
	Init(c);
	In(c, ifst);

	ofst << "Filled container. " << endl;
	Out(c, ofst);

	Sort(c);
	ofst << "\nSorted container. " << endl;
	Out(c, ofst);
	
	ofst << "\nFiltered container." << endl;
	OutSquare(c, ofst);

	Clear(c);
	ofst << "\nEmpty container. " << endl;

	OutSquare(c, ofst);
	cout << "Stop" << endl;

	return 0;
}