#pragma once
#ifndef __diag_atd__
#define __diag_atd__

namespace simple_matrix
{
	struct diag // ������������ �������
	{
		int size; // �����������
		int mas_diag[20]; //���������� ������
		enum key2 { STROKI, STOLB, ODN_MASS };
		key2 k2;
	};
} // end simple_matrix namespace
#endif