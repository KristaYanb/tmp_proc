#pragma once
#ifndef __square_atd__
#define __square_atd__

namespace simple_matrix
{
	struct square // ���������� �������
	{
		int size; // �����������
		int mas_square[10][10]; //��������� ������
		enum key2 { STROKI, STOLB, ODN_MASS };
		key2 k2;
	};
} // end simple_matrix namespace
#endif
