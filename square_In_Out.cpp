#include <fstream>
#include "square_atd.h"
using namespace std;

namespace simple_matrix
{
	void In(square& r, ifstream& ifst) // ���� ���������� ���������� ������� �� �����
	{
		ifst >> r.size;
		for (int i = 1; i <= r.size; i++)
			for (int j = 1; j <= r.size; j++)
				ifst >> r.mas_square[i][j];
	}

	void Out(square& r, ofstream& ofst) // ����� ���������� ���������� ������� � ����
	{
		ofst << "It is Square matrix: Size = " << r.size << endl;
		for (int i = 1; i <= r.size; i++)
			for (int j = 1; j <= r.size; j++)
			{
				ofst << r.mas_square[i][j] << " ";
				if (j == r.size)
					ofst << endl;
			}
	}

	int Summa(square& r)
	{
		int summa = 0;
		for (int i = 1; i <= r.size; i++)
			for (int j = 1; j <= r.size; j++)
				summa = summa + r.mas_square[i][j];
		return summa;
	}
} // end simple_matrix namespace