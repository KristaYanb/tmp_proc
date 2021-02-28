#include <fstream>
#include "matr_atd.h"
using namespace std;

namespace simple_matrix
{
	// ��������� ��������� ������� �������
	void In(square& r, ifstream& ist);
	void In(diag& t, ifstream& ist);

	int Summa(square& r);
	int Summa(diag& t);

	matr* In(ifstream& ifst) // ���� ���������� ���������� ������� �� �����
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
		default: 
			return -1;
		}
	}

	// ��������� ��������� ������� �������
	void Out(square& r, ofstream& ofst);
	void Out(diag& t, ofstream& ofst);
	

	void Out(matr& s, ofstream& ofst) // ����� ���������� ������� ������� � �����
	{
		switch (s.k) {
		case matr::key::SQUARE:
			Out(s.s, ofst);
			break;
		case matr::key::DIAG:
			Out(s.d, ofst);
			break;
		default:
			ofst << "Incorrect matrix!" << endl;
		}
	}
} // end simple_matrix namespace