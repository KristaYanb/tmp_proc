#include <fstream>
#include <iostream>
#include <string>
#include "square_atd.h"
using namespace std;

namespace simple_matrix
{
	int In(square& r, ifstream& ifst) // Ввод параметров квадратной матрицы из файла
	{
		ifst >> r.size;

		if (ifst.fail())
		{
			cout << "Wrong size square!" << endl;
			
			return 0;
		}

		if (r.size < 0)
		{
			cout << "Error size square!" << endl;
			
			return 0;
		}

		int size2 = 0;
		int size3 = 0;
		int flag = 0;

		for (int i = 1; i <= r.size; i++)
		{
			if (flag == 0)
			{
				for (int j = 1; j <= r.size; j++)
				{
					if (ifst.eof() == 1)
					{
						size3 = j-1;
						flag = 1;
						break;
					}

					else
					{
						ifst >> r.mas_square[i][j];
						if (ifst.fail())
						{
							cout << "Wrong mas_square!" << endl;
							size3 = j - 1;
							flag = 1;
							flag = 1;
							break;
						}

						if (fmod(size3, r.size) == 0)
							size3 = r.size;

						else
							size3 = fmod(size3, r.size);
					}
				}
			}

			if (flag == 1)
				break;

			else
			{
				size2++;
				continue;
			}
		}

		if ((size3 != r.size) || (size2 != r.size))
		{
			size2++;
			
			for (int i = size2+1; i <= r.size; i++)
				for (int j = 1; j <= r.size; j++)
					r.mas_square[i][j] = 0;

			for (int j = size3+1; j <= r.size; j++)
				r.mas_square[size2][j] = 0;
		}
	}

	void InS(square& r, ifstream& ifst) // Ввод параметров квадратной матрицы из файла
	{
		ifst >> r.size;

		for (int i = 0; i <= r.size-1; i++)
			for (int j = 0; j <= r.size-1; j++)
				ifst >> r.mas_square[i][j];
	}

	void InSS(square& r, ifstream& ifst) // Ввод параметров квадратной матрицы из файла
	{
		ifst >> r.size;

		for (int i = 1; i <= r.size; i++)
			for (int j = 1; j <= r.size; j++)
				ifst >> r.mas_square[i][j];
	}

	void OutStroki(square& r, ofstream& ofst) // Вывод параметров квадратной матрицы в файл
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

	void OutStolb(square& r, ofstream& ofst) // Вывод параметров квадратной матрицы в файл
	{
		ofst << "It is Square matrix: Size = " << r.size << endl;
		
		for (int j = 1; j <= r.size; j++)
			for (int i = 1; i <= r.size; i++)
			{
				ofst << r.mas_square[i][j] << " ";

				if (i == r.size)
					ofst << endl;
			}
	}

	void OutOdnMas(square& r, ofstream& ofst) // Вывод параметров квадратной матрицы в файл
	{
		ofst << "It is Square matrix: Size = " << r.size << endl;

		for (int i = 1; i <= r.size; i++)
			for (int j = 1; j <= r.size; j++)
			{
				ofst << r.mas_square[i][j] << " ";
			}
		
		ofst << endl;
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