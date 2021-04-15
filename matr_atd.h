#pragma once
#ifndef __matr_atd__
#define __matr_atd__
#include "square_atd.h"
#include "diag_atd.h"
#include "nizn_diag_atd.h"

namespace simple_matrix
{
	struct matr // структура, обобщающая все матрицы
	{
		int size;
		//enum key { SQUARE, DIAG, NIZN_DIAG }; // значения ключей для каждой из матриц
		enum key { SQUARE, DIAG };
		key k; // ключ

		union  // используемые альтернативы
		{ // используем включение
			square s;
			diag d;
			//nizn_diag n;
		};
	};
} // end simple_matrix namespace
#endif
