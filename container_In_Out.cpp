#include <fstream>
#include <iostream>
#include "container_atd.h"
using namespace std;

namespace simple_matrix
{
	matr* In(ifstream& ifst); // Сигнатуры требуемых внешних функций

	void In(container& c, ifstream& ifst) // Ввод содержимого контейнера из файла
	{
		while (!ifst.eof()) 
		{
			matr* curMatrix = In(ifst);

			if (curMatrix != 0)
			{
				c.size++;
				node* curNode = new node;
				curNode->m = curMatrix;

				if (c.head != NULL)
				{
					curNode->next = c.head;
					c.head = curNode;
				}

				else
				{
					curNode->next = NULL;
					c.head = curNode;
				}
			}

			else
				break;
		}
	}

	void Out(matr& s, ofstream& ofst); // Сигнатуры требуемых внешних функций

	int Summa(matr& s);

	bool Compare(matr* first, matr* second)
	{
		return Summa(*first) < Summa(*second);
	}

	void Sort(container& c)
	{
		node* left = c.head;
		node* right = c.head->next;
		node* temp = new node;

		for (int i = 0; i < c.size - 1; i++)
		{
			for (int j = i + 1; j < c.size; j++)
			{
				if (Compare(left->m, right->m))
				{
					temp->m = left->m;
					left->m = right->m;
					right->m = temp->m;
				}

				right = right->next;
			}

			left = left->next;
			right = left->next;
		}
	}

	void OutSquare(container& c, ofstream& ofst) 
	{ 
		ofst << "\nContainer contains " << c.size << " elements." << endl;
		ofst << "Only square." << endl; 

		node* curNode = c.head;
		int i = 0;

		while (curNode != NULL)
		{
			ofst << i << ": ";

			if (curNode->m->k == matr::SQUARE)
			{
				Out(*curNode->m, ofst);
				ofst << "Summa = " << Summa(*curNode->m) << endl;
			}

			else
				ofst << endl;

			curNode = curNode->next;
			i++;
		}
	}
	
	void Out(container& c, ofstream& ofst) // Вывод содержимого контейнера в файл
	{
		ofst << "Container contains " << c.size << " elements." << endl;

		node* curNode = c.head;
		int i = 0;

		while (curNode != NULL)
		{
			ofst << i << ": ";
			Out(*curNode->m, ofst);
			ofst << "Summa = " << Summa(*curNode->m) << endl;
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

	struct node* get_node(struct node* head, int offset)
	{

		struct node* retNode = head;
		int i;

		for (i = 0; i < offset; i++)
		{
			retNode = retNode->next;
		}

		return retNode;
	}

	char output_node(struct node* head, int offset, ofstream& ofst)
	{

		struct node* curNode = head;
		int i;

		for (i = 0; i < offset; i++)
		{
			curNode = curNode->next;
		}

		Out(*curNode->m, ofst);

		return 0;
	}

	void Multimethod(container& c, ofstream& ofst)
	{
		struct node* curNode;
		ofst << "\nMultimethod:\n";

		for (int i = 0; i < c.size - 1; i++)
		{
			for (int j = i + 1; j < c.size; j++)
			{
				curNode = get_node(c.head, i);
				switch (curNode->m->k)
				{
					case matr::SQUARE:
						curNode = get_node(c.head, j);
						switch (curNode->m->k)
						{
							case matr::SQUARE:
								ofst << "Square and Square." << endl;
								break;

							case matr::DIAG:
								ofst << "Square and Diag." << endl;
								break;

							case matr::NIZN_DIAG:
								ofst << "Square and Nizn_Diag." << endl;
								break;

							default:
								ofst << "Unknown type" << endl;
						}
						break;

					case matr::DIAG:
						curNode = get_node(c.head, j);
						switch (curNode->m->k)
						{
							case matr::SQUARE:
								ofst << "Diag and Square." << endl;
								break;

							case matr::DIAG:
								ofst << "Diag and Diag." << endl;
								break;

							case matr::NIZN_DIAG:
								ofst << "Diag and Nizn_Diag." << endl;
								break;

							default:
								ofst << "Unknown type" << endl;
						}
						break;

					case matr::NIZN_DIAG:
						curNode = get_node(c.head, j);
						switch (curNode->m->k)
						{
							case matr::SQUARE:
								ofst << "Nizn_Diag and Square." << endl;
								break;

							case matr::DIAG:
								ofst << "Nizn_Diag and Diag." << endl;
								break;

							case matr::NIZN_DIAG:
								ofst << "Nizn_Diag and Nizn_Diag." << endl;
								break;

							default:
								ofst << "Unknown type" << endl;
						}
						break;

					default:
						ofst << "Unknown type" << endl;
				}
				output_node(c.head, i, ofst);
				output_node(c.head, j, ofst);
			}
		}
	}
} // end simple_matrix namespace