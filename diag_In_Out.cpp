#include <fstream>
#include "diag_atd.h"
using namespace std;

namespace simple_matrix
{
	void In(diag& t, ifstream& ifst) // ���� ���������� ������������ ������� �� �����
	{
		ifst >> t.size;

		for (int i = 1; i <= t.size; i++)
			ifst >> t.mas_diag[i];
	}

	void Out1(diag& t, ofstream& ofst) // ����� ���������� ������������ ������� � ����
	{
		ofst << "It is Diag matrix: Size = " << t.size << endl;
		
		for (int i = 1; i <= t.size; i++)
			for (int j = 1; j <= t.size; j++)
			{
				if (i == j)
					ofst << t.mas_diag[i] << " ";
				else
					ofst << "0 ";
				if (j == t.size)
					ofst << endl;
			}
	}

	void Out2(diag& t, ofstream& ofst) // ����� ���������� ���������� ������� � ����
	{
		ofst << "It is Diag: Size = " << t.size << endl;
		for (int j = 1; j <= t.size; j++)
			for (int i = 1; i <= t.size; i++)
			{
				if (j == i)
					ofst << t.mas_diag[i] << " ";
				else
					ofst << "0 ";
				if (i == t.size)
					ofst << endl;
			}
	}

	void Out3(diag& t, ofstream& ofst) // ����� ���������� ���������� ������� � ����
	{
		ofst << "It is Diag matrix: Size = " << t.size << endl;

		for (int j = 1; j <= t.size; j++)
			for (int i = 1; i <= t.size; i++)
			{
				if (j == i)
					ofst << t.mas_diag[i] << " ";
				else
					ofst << "0 ";
			}
		ofst << endl;
	}
} // end simple_matrix namespace