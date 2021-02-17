#include <fstream>
#include "container_atd.h"
using namespace std;

namespace simple_matrix
{
	matr* In(ifstream& ifdt); // Сигнатуры требуемых внешних функций

	void In(container& c, ifstream& ifst) // Ввод содержимого контейнера из файла
	{
		while (!ifst.eof()) 
		{
			matr* curMatrix = In(ifst);
			if (curMatrix != 0) { 
				c.size++;
				node* curNode = new node;
				curNode->m = curMatrix;
				if(c.head!=NULL){
					curNode->next = c.head;
					c.head = curNode;
				}
				else {
					curNode->next = NULL;
					c.head = curNode;
				}
			}
		}
	}

	void Out(matr& s, ofstream& ofst); // Сигнатуры требуемых внешних функций

	void Out(container& c, ofstream& ofst) // Вывод содержимого контейнера в файл
	{
		ofst << "Container contains " << c.size
			<< " elements." << endl;

		node* curNode = c.head;
		int i = 0;

		while (curNode != NULL)
		{
			ofst << i << ": ";
			
			Out(*curNode->m, ofst);
			curNode = curNode->next;

			i++;
		}
	}

	void Init(container& c) // Инициализация контейнера
	{
		c.head = NULL;
		c.size = 0; 
	}

	void Clear(container& c) // Очистка контейнера от элементов (освобождение памяти)
	{
		node* curNode = c.head;

		while (curNode != NULL)
		{
			node* temp = curNode->next;
			delete curNode;
			curNode = temp;
		}
		c.head = NULL;
		c.size = 0;
	}
} // end simple_matrix namespace