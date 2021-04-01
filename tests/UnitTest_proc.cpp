#include "pch.h"
#include "CppUnitTest.h"

#include "../merge_proc/matr_atd.h"
#include "../merge_proc/matr_In_Out.cpp"
#include "../merge_proc/merge_proc.cpp"
#include "../merge_proc/nizn_diag_atd.h"
#include "../merge_proc/nizn_diag_In_Out.cpp"
#include "../merge_proc/square_atd.h"
#include "../merge_proc/square_In_Out.cpp"
#include "../merge_proc/container_atd.h"
#include "../merge_proc/container_In_Out.cpp"
#include "../merge_proc/diag_atd.h"
#include "../merge_proc/diag_In_Out.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace simple_matrix;

namespace UnitTestproc
{
	TEST_CLASS(UnitTestproc)
	{
	public:

		string Read(const char* filename)
		{
			ifstream ifst(filename);
			string s;
			while (!ifst.eof())
			{
				ifst >> s;
			}
			ifst.close();
			return s;
		}

		TEST_METHOD(TestOut)
		{
			ifstream ifst("input.txt");
			ofstream ofst("output.txt");
			container c;
			Init(c);
			In(c, ifst);
			Out(c, ofst);
			string s1 = Read("output.txt");
			string s2 = Read("outMy.txt");
			Assert::AreEqual(s1, s2);
		}

		TEST_METHOD(TestOutSquare)
		{
			ifstream ifst("input.txt");
			ofstream ofst("output.txt");
			container c;
			Init(c);
			In(c, ifst);
			OutSquare(c, ofst);
			string s1 = Read("output.txt");
			string s2 = Read("outSquareMy.txt");
			Assert::AreEqual(s1, s2);
		}

		TEST_METHOD(TestOutNiznDiag)
		{
			ifstream ifst("input_nizn_diag.txt");
			ofstream ofst("output_nizn_diag.txt");
			nizn_diag actual;
			InNN(actual, ifst);
			OutStroki(actual, ofst);

			string s1 = Read("output_nizn_diag.txt");
			string s2 = Read("out_nizn_diag_My.txt");
			Assert::AreEqual(s1, s2);
		}

		TEST_METHOD(TestOutDiag)
		{
			ifstream ifst("input_diag.txt");
			ofstream ofst("output_diag.txt");
			diag actual;
			InDD(actual, ifst);
			OutStroki(actual, ofst);

			string s1 = Read("output_diag.txt");
			string s2 = Read("out_diag_My.txt");
			Assert::AreEqual(s1, s2);
		}

		TEST_METHOD(TestOutSquare2)
		{
			ifstream ifst("input_square.txt");
			ofstream ofst("output_square.txt");
			square actual;
			InSS(actual, ifst);
			OutStroki(actual, ofst);

			string s1 = Read("output_square.txt");
			string s2 = Read("out_square_My.txt");
			Assert::AreEqual(s1, s2);
		}

		TEST_METHOD(TestSort)
		{
			ifstream ifst("input.txt");
			ofstream ofst("output.txt");
			container c;
			Init(c);
			In(c, ifst);
			sort(c);
			Out(c, ofst);
			string s1 = Read("output.txt");
			string s2 = Read("outSortMy.txt");
			Assert::AreEqual(s1, s2);
		}

		TEST_METHOD(TestClear)
		{
			ifstream ifst("input.txt");
			ofstream ofst("output.txt");
			container c;
			Init(c);
			In(c, ifst);
			Out(c, ofst);
			Clear(c);
			Out(c, ofst);
			string s1 = Read("output.txt");
			string s2 = Read("outClear.txt");
			Assert::AreEqual(s1, s2);
		}

		TEST_METHOD(TestInit)
		{
			ifstream ifst("input.txt");
			container c;
			Init(c);
			int a = c.size;
			Assert::AreEqual(0, a);
			Assert::IsNull(c.head);
		}

		TEST_METHOD(SummaSquare)
		{
			square* s = new square;
			s->size = 10;

			for (int i = 1; i <= s->size; i++)
				for (int j = 1; j <= s->size; j++)
					s->mas_square[i][j] = 1;

			int actual = Summa(*s);
			Assert::AreEqual(100, actual);

			square* s2 = new square;
			s2->size = 9;

			for (int i = 1; i <= s2->size; i++)
				for (int j = 1; j <= s2->size; j++)
					s2->mas_square[i][j] = 1;

			int actual2 = Summa(*s2);
			Assert::AreEqual(81, actual2);

			square* s3 = new square;
			s3->size = 8;

			for (int i = 1; i <= s3->size; i++)
				for (int j = 1; j <= s3->size; j++)
					s3->mas_square[i][j] = 1;

			int actual3 = Summa(*s3);
			Assert::AreEqual(64, actual3);
		}

		TEST_METHOD(SummaDiag)
		{
			diag* s = new diag;
			s->size = 20;

			for (int i = 1; i <= s->size; i++)
					s->mas_diag[i] = 1;

			int actual = Summa(*s);
			Assert::AreEqual(20, actual);

			diag* s2 = new diag;
			s2->size = 19;

			for (int i = 1; i <= s2->size; i++)
				s2->mas_diag[i] = 1;

			int actual2 = Summa(*s2);
			Assert::AreEqual(19, actual2);

			diag* s3 = new diag;
			s3->size = 18;

			for (int i = 1; i <= s3->size; i++)
				s3->mas_diag[i] = 1;

			int actual3 = Summa(*s3);
			Assert::AreEqual(18, actual3);
		}

		TEST_METHOD(SummaNiznDiag)
		{
			nizn_diag* s = new nizn_diag;
			s->size = 9;

			int count1 = s->size;
			int count = 0;
			while (count1 != 0)
			{
				count = count + count1;
				count1 = count1 - 1;
			}

			for (int i = 1; i <= count; i++)
				s->mas_nizn_diag[i] = 1;

			int actual = Summa(*s);
			Assert::AreEqual(45, actual);

			nizn_diag* s2 = new nizn_diag;
			s2->size = 8;

			int count1_2 = s2->size;
			int count_2 = 0;
			while (count1_2 != 0)
			{
				count_2 = count_2 + count1_2;
				count1_2 = count1_2 - 1;
			}

			for (int i = 1; i <= count_2; i++)
				s2->mas_nizn_diag[i] = 1;

			int actual2 = Summa(*s2);
			Assert::AreEqual(36, actual2);

			nizn_diag* s3 = new nizn_diag;
			s3->size = 7;

			int count1_3 = s3->size;
			int count_3 = 0;
			while (count1_3 != 0)
			{
				count_3 = count_3 + count1_3;
				count1_3 = count1_3 - 1;
			}

			for (int i = 1; i <= count_3; i++)
				s3->mas_nizn_diag[i] = 1;

			int actual3 = Summa(*s3);
			Assert::AreEqual(28, actual3);
		}

		TEST_METHOD(TestInSquare)
		{
			ifstream ifst("input_square.txt");
			square actual;
			InS(actual,ifst);

			square* sd = new square;
			sd->size = 2;
			int k = 1;
			for (int i = 0; i <= sd->size-1; i++)
				for (int j = 0; j <= sd->size - 1; j++)
				{
					sd->mas_square[i][j] = k;
					k++;
				}
			Assert::AreEqual(sd->size, actual.size);
			Assert::AreEqual(sd->mas_square[0][0], actual.mas_square[0][0]);
			Assert::AreEqual(sd->mas_square[0][1], actual.mas_square[0][1]);
			Assert::AreEqual(sd->mas_square[1][0], actual.mas_square[1][0]);
			Assert::AreEqual(sd->mas_square[1][1], actual.mas_square[1][1]);
		}

		TEST_METHOD(TestInDiag)
		{
			ifstream ifst("input_diag.txt");
			diag actual;
			InD(actual, ifst);

			diag* sd = new diag;
			sd->size = 2;
			int j = 1;
			for (int i = 0; i <= sd->size - 1; i++)
			{
				sd->mas_diag[i] = j;
				j++;
			}
			Assert::AreEqual(sd->size, actual.size);
			Assert::AreEqual(sd->mas_diag[0], actual.mas_diag[0]);
			Assert::AreEqual(sd->mas_diag[1], actual.mas_diag[1]);
		}

		TEST_METHOD(TestInNiznDiag)
		{
			ifstream ifst("input_nizn_diag.txt");
			nizn_diag actual;
			InN(actual, ifst);

			nizn_diag* sd = new nizn_diag;
			sd->size = 2;
			int count1 = sd->size;
			int count = 0;
			while (count1 != 0)
			{
				count = count + count1;
				count1 = count1 - 1;
			}

			int j = 1;
			for (int i = 0; i <= count - 1; i++)
			{
				sd->mas_nizn_diag[i] = j;
				j++;
			}
			Assert::AreEqual(sd->size, actual.size);
			Assert::AreEqual(sd->mas_nizn_diag[0], actual.mas_nizn_diag[0]);
			Assert::AreEqual(sd->mas_nizn_diag[1], actual.mas_nizn_diag[1]);
			Assert::AreEqual(sd->mas_nizn_diag[2], actual.mas_nizn_diag[2]);
		}

		
	};
}
