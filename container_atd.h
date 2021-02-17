#pragma once
#ifndef __container_atd__
#define __container_atd__
#include "matr_atd.h"

namespace simple_matrix
{
	struct node
	{
		matr* m;
		node* next;
	};

	struct container
	{
		long size;
		node* head;
	};
} // end simple_matrix namespace
#endif