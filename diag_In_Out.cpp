#include <fstream>
#include "diag_atd.h"
using namespace std;

namespace simple_matrix
{
	void In(diag& t, ifstream& ifst) // Ввод параметров диагональной матрицы из файла
	{
		ifst >> t.size;
		for (int i = 1; i <= t.size; i++)
			ifst >> t.mas_diag[i];
	}

	void Out(diag& t, ofstream& ofst) // Вывод параметров диагональной матрицы в файл
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
} // end simple_matrix namespace