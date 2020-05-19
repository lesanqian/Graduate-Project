#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <cmath>
#include <cstring>
#include"test.h"

using namespace std;


int main()
{
	test A;
	int choice, choice2;
	while (true)
	{
		choice = A.menu();
		system("cls");
		A.number_of_problem();
		if (choice == 1)
		{
			A.AddSub(choice);
			A.Rename();
			A.back();
		}
		else if (choice == 2)
		{
			choice2 = A.menu2();
			system("cls");
			if (choice2 == 1)
			{
				A.AddSub(choice);

			}
			else if (choice2 == 2)
			{
				A.Mul_Div(choice, 2);
			}
			else if (choice2 == 3)
			{
				A.Mul_Div(choice, 3);
			}
			else if (choice2 == 4)
			{
				A.Mul_Div(choice, 4);
			}
			A.Rename1();
			A.back();

		}
		else if (choice == 3)
		{
			choice2 = A.menu2();
			system("cls");
			if (choice2 == 1)
			{
				A.AddSub(choice);
				A.back();
			}
			else if (choice2 == 2)
			{
				A.Mul_Div(choice, 2);
				A.back();
			}
			else if (choice2 == 3)
			{
				A.Mul_Div(choice, 3);
				A.back();
			}
			else if (choice2 == 4)
			{
				A.Mul_Div(choice, 4);
				A.back();
			}
			A.Rename2();
			A.back();
		}
		else if (choice == 4)
		{
			choice2 = A.menu2();
			system("cls");
			if (choice2 == 1)
			{
				A.FloatCount(1);
			}
			if (choice2 == 2)
			{
				A.FloatCount(2);
			}
			else if (choice2 == 3)
			{
				A.Print(3);
			}
			else if (choice2 == 4)
			{
				A.Print(4);
			}
			A.Rename3();
			A.back();
		}
		else if (choice == 0)
			break;
	}
	system("cls");
	return 0;
}

