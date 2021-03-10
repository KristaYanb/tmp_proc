#pragma once
#ifndef __nizn_diag_atd__
#define __nizn_diag_atd__

namespace simple_matrix
{
	struct nizn_diag // квадратная матрица
	{
		int size; // размерность
		int mas_nizn_diag[50]; //одномерный массив
		enum key2 { STROKI, STOLB, ODN_MASS };
		key2 k2;
	};
} // end simple_matrix namespace
#endif