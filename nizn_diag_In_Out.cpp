#include <fstream>
#include <iostream>
#include "nizn_diag_atd.h"
using namespace std;

namespace simple_matrix
{
	int In(nizn_diag& n, ifstream& ifst) // ���� ���������� ������������ ������� �� �����
	{
		ifst >> n.size;

		if (ifst.fail())
		{
			cout << "Wrong size nizn_diag!" << endl;
			
			return 0;
		}

		if (n.size < 0)
		{
			cout << "Error size nizn_diag!" << endl;
			
			return 0;
		}

		int count1 = n.size;
		int count = 0;

		while (count1 != 0)
		{
			count = count + count1;
			count1 = count1 - 1;
		}

		int size2 = 0;

		for (int i = 1; i <= count; i++)
		{
			if (ifst.eof() == 1 or ifst.fail())
				break;

			else
			{
				ifst >> n.mas_nizn_diag[i];
				if (ifst.fail())
				{
					cout << "Wrong mas_nizn_diag!" << endl;
					size2++;
					break;
				}
				size2++;
			}
		}

		if (size2 != count)
		{
			for (int i = size2+1; i <= count; i++)
				n.mas_nizn_diag[i] = 0;
		}
	}

	void InN(nizn_diag& n, ifstream& ifst) // ���� ���������� ������������ ������� �� �����
	{
		ifst >> n.size;

		int count1 = n.size;
		int count = 0;

		while (count1 != 0)
		{
			count = count + count1;
			count1 = count1 - 1;
		}

		for (int i = 0; i <= count-1; i++)
			ifst >> n.mas_nizn_diag[i];
	}

	void InNN(nizn_diag& n, ifstream& ifst) // ���� ���������� ������������ ������� �� �����
	{
		ifst >> n.size;

		int count1 = n.size;
		int count = 0;

		while (count1 != 0)
		{
			count = count + count1;
			count1 = count1 - 1;
		}

		for (int i = 1; i <= count; i++)
			ifst >> n.mas_nizn_diag[i];
	}

	void OutStroki(nizn_diag& n, ofstream& ofst) // ����� ���������� ������������ ������� � ����
	{
		ofst << "It is Nizn_Diag matrix: Size = " << n.size << endl;
		
		for (int i = 1, ii = 1; i <= n.size; i++)
			for (int j = 1; j <= n.size; j++)
			{
				if (j <= i) 
					ofst << n.mas_nizn_diag[ii++] << " ";

				else
					ofst << 0 << " ";

				if (j == n.size)
					ofst << endl;
			}
	}

	void OutStolb(nizn_diag& n, ofstream& ofst) // ����� ���������� ���������� ������� � ����
	{
		ofst << "It is Nizn_Diag matrix: Size = " << n.size << endl;
		
		for (int i = 1, ii = 1; i <= n.size; i++)
			for (int j = 1; j <= n.size; j++)
			{
				if (i <= j)
					ofst << n.mas_nizn_diag[ii++] << " ";

				else
					ofst << 0 << " ";

				if (j == n.size)
					ofst << endl;
			}
	}

	void OutOdnMas(nizn_diag& n, ofstream& ofst) // ����� ���������� ���������� ������� � ����
	{
		ofst << "It is Nizn_Diag matrix: Size = " << n.size << endl;
		
		for (int i = 1, ii = 1; i <= n.size; i++)
			for (int j = 1; j <= n.size; j++)
			{
				if (j <= i)
					ofst << n.mas_nizn_diag[ii++] << " ";

				else
					ofst << 0 << " ";
			}

		ofst << endl;
	}

	int Summa(nizn_diag& n)
	{
		int count1 = n.size;
		int count = 0;

		while (count1 != 0)
		{
			count = count + count1;
			count1 = count1 - 1;
		}

		int summa = 0;

		for (int i = 1; i <= count; i++)
			summa = summa + n.mas_nizn_diag[i];

		return summa;
	}
} // end simple_matrix namespace