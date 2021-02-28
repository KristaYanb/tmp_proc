#include <fstream>
#include "nizn_diag_atd.h"
using namespace std;

namespace simple_matrix
{
	void In(nizn_diag& n, ifstream& ifst) // Ввод параметров диагональной матрицы из файла
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

	void Out(nizn_diag& n, ofstream& ofst) // Вывод параметров диагональной матрицы в файл
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
} // end simple_matrix namespace