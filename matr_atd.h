#pragma once
#ifndef __matr_atd__
#define __matr_atd__
#include "square_atd.h"
#include "diag_atd.h"

namespace simple_matrix
{
	struct matr // структура, обобщающая все матрицы
	{
		int size;
		enum key { SQUARE, DIAG }; // значения ключей для каждой из матриц
		key k; // ключ

		union  // используемые альтернативы
		{ // используем включение
			square s;
			diag d;
		};
	};
} // end simple_matrix namespace
#endif
