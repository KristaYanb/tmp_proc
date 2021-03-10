#include <fstream>
#include "matr_atd.h"
using namespace std;

namespace simple_matrix
{
	// Сигнатуры требуемых внешних функций
	void In(square& r, ifstream& ist);
	void In(diag& t, ifstream& ist);
	void In(nizn_diag& n, ifstream& ist);

	matr* In(ifstream& ifst) // Ввод параметров обобщенной матрицы из файла
	{
		matr* sp;
		int k;
		ifst >> k;

		int k2;
		ifst >> k2;

		switch (k) 
		{
		case 1:
			switch (k2)
			{
			case 0:
				sp = new matr;
				sp->k = matr::key::SQUARE;
				sp->k2 = matr::key2::STROKI;
				In(sp->s, ifst);
				return sp;
			case 1:
				sp = new matr;
				sp->k = matr::key::SQUARE;
				sp->k2 = matr::key2::STOLB;
				In(sp->s, ifst);
				return sp;
			case 2:
				sp = new matr;
				sp->k = matr::key::SQUARE;
				sp->k2 = matr::key2::ODN_MASS;
				In(sp->s, ifst);
				return sp;
			default:
				return 0;
			}
		case 2:
			switch (k2)
			{
			case 0:
				sp = new matr;
				sp->k = matr::key::DIAG;
				sp->k2 = matr::key2::STROKI;
				In(sp->d, ifst);
				return sp;
			case 1:
				sp = new matr;
				sp->k = matr::key::DIAG;
				sp->k2 = matr::key2::STOLB;
				In(sp->d, ifst);
				return sp;
			case 2:
				sp = new matr;
				sp->k = matr::key::DIAG;
				sp->k2 = matr::key2::ODN_MASS;
				In(sp->d, ifst);
				return sp;
			default:
				return 0;
			}
		default:
			return 0;
		}
	}

	// Сигнатуры требуемых внешних функций
	void Out1(square& r, ofstream& ofst);
	void Out2(square& r, ofstream& ofst);
	void Out3(square& r, ofstream& ofst);
	void Out1(diag& t, ofstream& ofst);
	void Out2(diag& t, ofstream& ofst);
	void Out3(diag& t, ofstream& ofst);

	void Out(matr& s, ofstream& ofst) // Вывод параметров текущей матрицы в поток
	{
		switch (s.k) {
		case matr::key::SQUARE:
			switch (s.k2)
			{
			case matr::key2::STROKI:
				ofst << "STROKI " << s.k2 << endl;
				Out1(s.s, ofst);
				break;
			case matr::key2::STOLB:
				ofst << "STOLB " << s.k2 << endl;
				Out2(s.s,  ofst);
				break;
			case matr::key2::ODN_MASS:
				ofst << "ODN_MASS " << s.k2 << endl;
				Out3(s.s, ofst);
				break;
			}
			break;
		
		case matr::key::DIAG:
			switch (s.k2)
			{
			case matr::key2::STROKI:
				ofst << "STROKI " << s.k2 << endl;
				Out1(s.d, ofst);
				break;
			case matr::key2::STOLB:
				ofst << "STOLB " << s.k2 << endl;
				Out2(s.d, ofst);
				break;
			case matr::key2::ODN_MASS:
				ofst << "ODN_MASS " << s.k2 << endl;
				Out3(s.d, ofst);
				break;
			}
			break;
		case matr::key::NIZN_DIAG:
			Out(s.n, ofst);
			break;
		default:
			ofst << "Incorrect matrix!" << endl;
		}
	}
} // end simple_matrix namespace