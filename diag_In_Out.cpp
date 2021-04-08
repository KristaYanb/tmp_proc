#include <fstream>
#include <iostream>
#include <typeinfo>
#include "diag_atd.h"
using namespace std;

namespace simple_matrix
{
	int In(diag& t, ifstream& ifst) // ���� ���������� ������������ ������� �� �����
	{
		ifst >> t.size;

		if (ifst.fail())
		{
			cout << "Wrong input size diag!" << endl;
			
			return 0;
		}

		if (t.size < 0)
		{
			cout << "Error size diag!" << endl;
			
			return 0;
		}

		int size2 = 0;

		for (int i = 1; i <= t.size; i++)
		{
			if (ifst.eof() == 1)
				break;

			else 
			{
				ifst >> t.mas_diag[i];
				
				if (ifst.fail())
				{
					cout << "Wrong mas_diag!" << endl;
					
					return 0;
				}
				size2++;
			}
		}

		if (size2 != t.size)
		{
			for (int i = size2+1; i <= t.size; i++)
				t.mas_diag[i] = 0;
		}
	}

	void InD(diag& t, ifstream& ifst) // ���� ���������� ������������ ������� �� �����
	{
		ifst >> t.size;
		
		for (int i = 0; i <= t.size-1; i++)
			ifst >> t.mas_diag[i];
	}

	void InDD(diag& t, ifstream& ifst) // ���� ���������� ������������ ������� �� �����
	{
		ifst >> t.size;
		
		for (int i = 1; i <= t.size; i++)
			ifst >> t.mas_diag[i];
	}

	void OutStroki(diag& t, ofstream& ofst) // ����� ���������� ������������ ������� � ����
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

	void OutStolb(diag& t, ofstream& ofst) // ����� ���������� ���������� ������� � ����
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

	void OutOdnMas(diag& t, ofstream& ofst) // ����� ���������� ���������� ������� � ����
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
	
	int Summa(diag& t)
	{ 
		int summa = 0;

		for (int i = 1; i <= t.size; i++)
			summa = summa + t.mas_diag[i];
		
		return summa;
	}
} // end simple_matrix namespace