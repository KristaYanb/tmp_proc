#pragma once
#ifndef __matr_atd__
#define __matr_atd__
#include "square_atd.h"
#include "diag_atd.h"

namespace simple_matrix
{
	struct matr // ���������, ���������� ��� �������
	{
		int size;
		enum key { SQUARE, DIAG }; // �������� ������ ��� ������ �� ������
		key k; // ����
		
		enum key2 { STROKI, STOLB, ODN_MASS };
		key2 k2;

		union  // ������������ ������������
		{ // ���������� ���������
			square s;
			diag d;
		};
	};
} // end simple_matrix namespace
#endif
