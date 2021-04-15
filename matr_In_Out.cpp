#include <fstream>
#include "matr_atd.h"
using namespace std;

namespace simple_matrix
{
	// Сигнатуры требуемых внешних функций
	void In(square& r, ifstream& ist);
	void In(diag& t, ifstream& ist);
	//void In(nizn_diag& n, ifstream& ist);

	matr* In(ifstream& ifst) // Ввод параметров обобщенной матрицы из файла
	{
		matr* sp;
		int k;
		ifst >> k;
		switch (k) {
		case 1:
			sp = new matr;
			sp->k = matr::key::SQUARE;
			In(sp->s, ifst);
			return sp;
		case 2:
			sp = new matr;
			sp->k = matr::key::DIAG;
			In(sp->d, ifst);
			return sp;
		/*case 3:
			sp = new matr;
			sp->k = matr::key::NIZN_DIAG;
			In(sp->n, ifst);
			return sp;*/
		default:
			return 0;
		}
	}

	// Сигнатуры требуемых внешних функций
	void Out(square& r, ofstream& ofst);
	void Out(diag& t, ofstream& ofst);
	void Out(nizn_diag& n, ofstream& ist);

	void Out(matr& s, ofstream& ofst) // Вывод параметров текущей матрицы в поток
	{
		switch (s.k) {
		case matr::key::SQUARE:
			Out(s.s, ofst);
			break;
		case matr::key::DIAG:
			Out(s.d, ofst);
			break;
		/*case matr::key::NIZN_DIAG:
			Out(s.n, ofst);
			break;*/
		default:
			ofst << "Incorrect matrix!" << endl;
		}
	}
} // end simple_matrix namespace