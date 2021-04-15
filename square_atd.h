#pragma once
#ifndef __square_atd__
#define __square_atd__

namespace simple_matrix
{
	struct square // квадратная матрица
	{
		int size; // размерность
		int mas_square[10][10]; //двумерный массив
		enum key2 { STROKI, STOLB, ODN_MASS };
		key2 k2;
	};
} // end simple_matrix namespace
#endif
