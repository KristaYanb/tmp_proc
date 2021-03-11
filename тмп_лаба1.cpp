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
	//void sort(int size, struct node* head);
	void sort(container& c);
	void OutSquare(container& c, ofstream& ofst);
	void Out(container& c, ofstream& ofst);
}
using namespace simple_matrix;

int main(int argc, char* argv[])
{
	if (argc != 3) {
		cout << "incorrect command line! "
			"Waited: command infile outfile" << endl;
		exit(1);
	}

	ifstream ifst(argv[1]);
	ofstream ofst(argv[2]);

	cout << "Start" << endl;
	container c;
	Init(c);

	In(c, ifst);
	ofst << "Filled container. " << endl;

	Out(c, ofst);
	sort(c);
	ofst << "Sorted container. " << endl;

	Out(c, ofst);

	OutSquare(c, ofst);
	Clear(c);
	ofst << "Empty container. " << endl;

	OutSquare(c, ofst);
	cout << "Stop" << endl;

	return 0;
}