// ConsoleApplication19.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#pragma warning(disable:4996)

int main()
{
	int a, vysledok;
	scanf("%d", &a);
	_asm
	{ MOV EAX, a;
	CMP EAX, 15
	JG l0;
	CMP EAX, 10;
	JC l1;
	JG l2;
l0 :
	MOV vysledok, EAX
		jmp end
l1 :
	MOV vysledok, EAX;
	jmp end;
l2 :
	ADD EAX, 55d;
	MOV vysledok, EAX;
end:
	}
	if (vysledok > 15)
		printf("Zadane cislo nieje z pozadovaneho intervalu 0-15\n");
	else if (vysledok < 10)
		printf("\nVysledok %d", vysledok);
	else
		printf("\nVysledok %c", vysledok);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
