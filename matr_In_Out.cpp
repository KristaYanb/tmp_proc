#include <fstream>
#include "matr_atd.h"
using namespace std;

namespace simple_matrix
{
	// Сигнатуры требуемых внешних функций
	void In(square& r, ifstream& ist);
	void In(diag& t, ifstream& ist);
	void In(nizn_diag& n, ifstream& ist);

	int Summa(square& r);
	int Summa(diag& t);
	int Summa(nizn_diag& n);

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
			sp = new matr;
			sp->k = matr::key::SQUARE;
			In(sp->s, ifst);
			break;
		case 2:
			sp = new matr;
			sp->k = matr::key::DIAG;
			In(sp->d, ifst);
			break;
		case 3:
			sp = new matr;
			sp->k = matr::key::NIZN_DIAG;
			In(sp->n, ifst);
			break;
		default:
			return 0;
			}

		switch (k2)
		{
		case 0:
			sp->k2 = matr::key2::STROKI;
			return sp;
		case 1:
			sp->k2 = matr::key2::STOLB;
			return sp;
		case 2:
			sp->k2 = matr::key2::ODN_MASS;
			return sp;
		default:
			return 0;
		}
	}

	int Summa(matr& s)
	{
		switch (s.k) 
		{
		case matr::key::SQUARE:
			return Summa(s.s);
		case matr::key::DIAG:
			return Summa(s.d);
		case matr::key::NIZN_DIAG:
			return Summa(s.n);
		default: 
			return -1;
		}
	}

	// Сигнатуры требуемых внешних функций
	void OutStroki(square& r, ofstream& ofst);
	void OutStolb(square& r, ofstream& ofst);
	void OutOdnMas(square& r, ofstream& ofst);
	void OutStroki(diag& t, ofstream& ofst);
	void OutStolb(diag& t, ofstream& ofst);
	void OutOdnMas(diag& t, ofstream& ofst);
	void OutStroki(nizn_diag& n, ofstream& ofst);
	void OutStolb(nizn_diag& n, ofstream& ofst);
	void OutOdnMas(nizn_diag& n, ofstream& ofst);

	void Out(matr& s, ofstream& ofst) // Вывод параметров текущей матрицы в поток
	{
		switch (s.k) {
		case matr::key::SQUARE:
			switch (s.k2)
			{
			case matr::key2::STROKI:
				ofst << "STROKI " << s.k2 << endl;
				OutStroki(s.s, ofst);
				break;
			case matr::key2::STOLB:
				ofst << "STOLB " << s.k2 << endl;
				OutStolb(s.s,  ofst);
				break;
			case matr::key2::ODN_MASS:
				ofst << "ODN_MASS " << s.k2 << endl;
				OutOdnMas(s.s, ofst);
				break;
			}
			break;
		
		case matr::key::DIAG:
			switch (s.k2)
			{
			case matr::key2::STROKI:
				ofst << "STROKI " << s.k2 << endl;
				OutStroki(s.d, ofst);
				break;
			case matr::key2::STOLB:
				ofst << "STOLB " << s.k2 << endl;
				OutStolb(s.d, ofst);
				break;
			case matr::key2::ODN_MASS:
				ofst << "ODN_MASS " << s.k2 << endl;
				OutOdnMas(s.d, ofst);
				break;
			}
			break;
		case matr::key::NIZN_DIAG:
			switch (s.k2)
			{
			case matr::key2::STROKI:
				ofst << "STROKI " << s.k2 << endl;
				OutStroki(s.n, ofst);
				break;
			case matr::key2::STOLB:
				ofst << "STOLB " << s.k2 << endl;
				OutStolb(s.n, ofst);
				break;
			case matr::key2::ODN_MASS:
				ofst << "ODN_MASS " << s.k2 << endl;
				OutOdnMas(s.n, ofst);
				break;
			}
			break;
		default:
			ofst << "Incorrect matrix!" << endl;
		}
	}
} // end simple_matrix namespace