/* pm hw 1 question 4.cpp : This file contains the 'main' function. Program execution begins and ends there.
 this one was actually not so bad... but i could not do the last part, it needs better clarification, I would send you an email about it but it would be
too late already and I wouldnt receive a reply in time.
*/

#include "pch.h"
#include <iostream>

int main()
{
	// reversing a string by using a loop
	char* p4(char* string)
	{
		int i, n;
		char t;
		n = strlen(string); // finds length of string
		for (i = 0; i <= (n / 2); i++)
		{
			t = string[i];
			string[i] = string[n - i - 1];
			string[n - i - 1] = t;
		}
		return string;

	}
	void addOtherElements(int mat[][10], int element, int arbitrary, int r, int c) // prototype
		void p4b(int mat[][10], int arb, int rowsize, int colsize)
	{
		int i, j;
		for (i = 0; i < rowsize; i++)
		{
			for (j = 0; j < colsize; j++)
			{
				addOtherElements(mat, mat[i][j], arb, rowsize, colsize);
			}
		}
	}
	voice addOtherElements(int mat[][10], int elements, int arbitary, int rowsize, int colsize)
	{
		int i, j, sum;
		for (i = 0; i < rowsize; i++)
		{
			for (j = 0; j < colsize; j++)
			{
				sum = mat[i][j] + element;
				if (sum == arbitrary)
				{
					cout << "( " << element << " , " << mat[i][j] << " ) " << endl;
				}


			}

		}
	}
}