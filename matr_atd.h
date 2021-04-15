#pragma once
#ifndef __matr_atd__
#define __matr_atd__
#include "square_atd.h"
#include "diag_atd.h"
#include "nizn_diag_atd.h"

namespace simple_matrix
{
	struct matr // ���������, ���������� ��� �������
	{
		int size;
		//enum key { SQUARE, DIAG, NIZN_DIAG }; // �������� ������ ��� ������ �� ������
		enum key { SQUARE, DIAG };
		key k; // ����

		union  // ������������ ������������
		{ // ���������� ���������
			square s;
			diag d;
			//nizn_diag n;
		};
	};
} // end simple_matrix namespace
#endif
