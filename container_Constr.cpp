#include "container_atd.h"
#include "shape_atd.h"
namespace simple_shapes {
	// ������������� ����������
	void Init(container& c) { c.len = 0; }
	// ������� ���������� �� ���������
	// (������������ ������)
	void Clear(container& c) {
		for (int i = 0; i < c.len; i++) {
			delete c.cont[i];
		}
		c.len = 0;
	}
} // end simple_shapes namespace