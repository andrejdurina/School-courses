// ConsoleApplication25.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <time.h>
#include <conio.h>
#include <windows.h>
#pragma warning(disable:4996)

int random(int min, int max) 
{
		return ((rand() % (max - min + 1)) + min);
}
void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
int main()
{
	    srand(time(0));
	    int x= 1,ch,a;
		clock_t begin, end;
		float time_elapsed;
		CONSOLE_SCREEN_BUFFER_INFO info;
		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
		int w = abs((info.srWindow.Right - info.srWindow.Left + 1));
		int h = abs((info.srWindow.Top - info.srWindow.Bottom + 1));
		w /= 2;
		h /= 2;
		printf("Stlac F1 pre navod");
		while(x)
	{
		if (kbhit())                              
		{
			ch = getch();                         
			switch (ch)                         
			{
			case 0x00: ch = getch();
				switch(ch)
				{
					case 0x3B: printf("\nPo stlaceni klavesy F2 sa spusti meranie , pre skoncenie merania \n je poterbne stlacit zobrazene tlacidlo na klavesnici\npre skoncenie programu ESC,F10");
						break;
					case 0x3C: 
					 a = random('A', 'Z');
							gotoxy(w, h);
								printf("%c", a);
							begin=clock();
				
							if (kbhit())
								ch = getch();
				
							while((ch = getch()-32) != a)
							{
								if (kbhit())
								ch = getch();
							}
							end= clock();
							time_elapsed = end - begin;
							printf("\n%f", time_elapsed);
						break;
						case 0x44: x=0;           
						break;		
				}
						break;
			case 0x1B: x = 0;
				break;
			
			}
		}
	}

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
