#pragma once
#ifndef __diag_atd__
#define __diag_atd__

namespace simple_matrix
{
	struct diag // диагональная матрица
	{
		int size; // размерность
		int mas_diag[20]; //одномерный массив
		enum key2 { STROKI, STOLB, ODN_MASS };
		key2 k2;
	};
} // end simple_matrix namespace
#endif