#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <locale.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include <dos.h>


COORD pozycja;
COORD jablko;

/*FUNKCJE*/

// Sprawdza czy gracz przegra³
int gameover(COORD pozycja, COORD jablko, int n, int *tabx, int *taby)						// zwraca 1, jeœli gracz przegra³, w przeciwnym wypadku zwraca 0
{
	int tmp = 0;
	if (pozycja.X >= 1 && pozycja.X <= 80 && pozycja.Y >= 1 && pozycja.Y <= 28);			// sprawdzenie czy w¹¿ uderzy³ w œcianê
	else tmp++;

	for (int i = n - 1; i >= 1; i--)														// sprawdzenie czy w¹¿ uderzy³ w samego siebie
	{
		if (*tabx == *(tabx + i) && *taby == *(taby + i))
			tmp++;
	}
		
	if (tmp > 0)
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), jablko);
		putchar(0);
		putchar(0);

		Sleep(700);
		for (int i = n - 1; i >= 1; i--)
		{
			pozycja.X = *(tabx + i);
			pozycja.Y = *(taby + i);
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pozycja);
			Sleep(200-200/i);
			putchar(0);
			putchar(0);
		}
		return 1;
	}
	else 
		return 0;
}
// Usuwa ostatni blok wê¿a
void usun_blok(COORD *pozycja, int *zjedzone, int n, int *tabx, int *taby)
{
	int tx;
	int ty;
	if (n == 1)			// dla d³ugoœci wê¿a = 1
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *pozycja);
		putchar(0);
		putchar(0);
	}
	if (*zjedzone == 0 && n > 1)
	{
		tx = (*pozycja).X;
		ty = (*pozycja).Y;
		(*pozycja).X = *(tabx + n - 1);
		(*pozycja).Y = *(taby + n - 1);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *pozycja);
		putchar(0);
		putchar(0);
		(*pozycja).X = tx;
		(*pozycja).Y = ty;
	}
	*zjedzone = 0;
}


// WYŒWIETLANIE

// Wyœwietla cyfrê
void printf_cyfra(int y, int cyfra, COORD *pozycja)
{
	pozycja->X = y;

	switch (cyfra)
	{
	case '0':
	{
		(*pozycja).Y = 5;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *pozycja);
		printf("  %c%c%c%c%c%c  \n", 178, 178, 178, 178, 178, 178);
		(*pozycja).Y = 6;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *pozycja);
		printf("%c%c      %c%c\n", 178, 178, 178, 178);
		(*pozycja).Y = 7;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *pozycja);
		printf("%c%c      %c%c\n", 178, 178, 178, 178);
		(*pozycja).Y = 8;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *pozycja);
		printf("%c%c      %c%c\n", 178, 178, 178, 178);
		(*pozycja).Y = 9;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *pozycja);
		printf("%c%c      %c%c\n", 178, 178, 178, 178);
		(*pozycja).Y = 10;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *pozycja);
		printf("%c%c      %c%c\n", 178, 178, 178, 178);
		(*pozycja).Y = 11;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *pozycja);
		printf("  %c%c%c%c%c%c  \n", 178, 178, 178, 178, 178, 178);
	}break;
	case '1':
	{
		(*pozycja).Y = 5;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *pozycja);
		printf("    %c%c    \n", 178, 178);
		(*pozycja).Y = 6;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *pozycja);
		printf("  %c%c%c%c    \n", 178, 178, 178, 178);
		(*pozycja).Y = 7;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *pozycja);
		printf("    %c%c    \n", 178, 178);
		(*pozycja).Y = 8;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *pozycja);
		printf("    %c%c    \n", 178, 178);
		(*pozycja).Y = 9;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *pozycja);
		printf("    %c%c    \n", 178, 178);
		(*pozycja).Y = 10;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *pozycja);
		printf("    %c%c    \n", 178, 178);
		(*pozycja).Y = 11;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *pozycja);
		printf("  %c%c%c%c%c%c  \n", 178, 178, 178, 178, 178, 178);
	}break;
	case'2':
	{
		(*pozycja).Y = 5;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *pozycja);
		printf("  %c%c%c%c%c%c  \n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);
		(*pozycja).Y = 6;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *pozycja);
		printf("%c%c      %c%c\n", 178, 178, 178, 178);
		(*pozycja).Y = 7;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *pozycja);
		printf("        %c%c\n", 178, 178);
		(*pozycja).Y = 8;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *pozycja);
		printf("      %c%c   \n", 178, 178);
		(*pozycja).Y = 9;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *pozycja);
		printf("    %c%c    \n", 178, 178);
		(*pozycja).Y = 10;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *pozycja);
		printf("  %c%c      \n", 178, 178);
		(*pozycja).Y = 11;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *pozycja);
		printf("%c%c%c%c%c%c%c%c%c%c\n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);
	}break;
	case'3':
	{
		(*pozycja).Y = 5;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *pozycja);
		printf("  %c%c%c%c%c%c  \n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);
		(*pozycja).Y = 6;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *pozycja);
		printf("%c%c      %c%c\n", 178, 178, 178, 178);
		(*pozycja).Y = 7;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *pozycja);
		printf("        %c%c\n", 178, 178);
		(*pozycja).Y = 8;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *pozycja);
		printf("  %c%c%c%c%c%c  \n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);
		(*pozycja).Y = 9;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *pozycja);
		printf("        %c%c\n", 178, 178);
		(*pozycja).Y = 10;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *pozycja);
		printf("%c%c      %c%c\n", 178, 178, 178, 178);
		(*pozycja).Y = 11;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *pozycja);
		printf("  %c%c%c%c%c%c  \n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);
	}break;
	case'4':
	{
		(*pozycja).Y = 5;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *pozycja);
		printf("      %c%c  \n", 178, 178);
		(*pozycja).Y = 6;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *pozycja);
		printf("    %c%c%c%c  \n", 178, 178, 178, 178);
		(*pozycja).Y = 7;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *pozycja);
		printf("  %c%c  %c%c  \n", 178, 178, 178, 178);
		(*pozycja).Y = 8;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *pozycja);
		printf("%c%c    %c%c  \n", 178, 178, 178, 178);
		(*pozycja).Y = 9;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *pozycja);
		printf("%c%c%c%c%c%c%c%c%c%c\n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);
		(*pozycja).Y = 10;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *pozycja);
		printf("      %c%c  \n", 178, 178);
		(*pozycja).Y = 11;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *pozycja);
		printf("      %c%c  \n", 178, 178);
	}break;
	case'5':
	{
		(*pozycja).Y = 5;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *pozycja);
		printf("%c%c%c%c%c%c%c%c%c%c\n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);
		(*pozycja).Y = 6;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *pozycja);
		printf("%c%c        \n", 178, 178);
		(*pozycja).Y = 7;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *pozycja);
		printf("%c%c%c%c%c%c%c%c  \n", 178, 178, 178, 178, 178, 178, 178, 178);
		(*pozycja).Y = 8;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *pozycja);
		printf("        %c%c\n", 178, 178);
		(*pozycja).Y = 9;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *pozycja);
		printf("        %c%c\n", 178, 178);
		(*pozycja).Y = 10;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *pozycja);
		printf("%c%c      %c%c\n", 178, 178, 178, 178);
		(*pozycja).Y = 11;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *pozycja);
		printf("  %c%c%c%c%c%c  \n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);
	}break;
	case '6':
	{
		(*pozycja).Y = 5;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *pozycja);
		printf("    %c%c%c%c    \n", 178, 178, 178, 178);
		(*pozycja).Y = 6;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *pozycja);
		printf("  %c%c      \n", 178, 178);
		(*pozycja).Y = 7;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *pozycja);
		printf("%c%c        \n", 178, 178);
		(*pozycja).Y = 8;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *pozycja);
		printf("%c%c%c%c%c%c%c%c  \n", 178, 178, 178, 178, 178, 178, 178, 178);
		(*pozycja).Y = 9;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *pozycja);
		printf("%c%c      %c%c\n", 178, 178, 178, 178);
		(*pozycja).Y = 10;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *pozycja);
		printf("%c%c      %c%c\n", 178, 178, 178, 178);
		(*pozycja).Y = 11;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *pozycja);
		printf("  %c%c%c%c%c%c  \n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);
	}break;
	case'7':
	{
		(*pozycja).Y = 5;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *pozycja);
		printf("%c%c%c%c%c%c%c%c%c%c\n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);
		(*pozycja).Y = 6;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *pozycja);
		printf("        %c%c\n", 178, 178);
		(*pozycja).Y = 7;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *pozycja);
		printf("      %c%c  \n", 178, 178);
		(*pozycja).Y = 8;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *pozycja);
		printf("    %c%c    \n", 178, 178);
		(*pozycja).Y = 9;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *pozycja);
		printf("  %c%c      \n", 178, 178);
		(*pozycja).Y = 10;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *pozycja);
		printf("%c%c        \n", 178, 178);
		(*pozycja).Y = 11;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *pozycja);
		printf("%c%c        \n", 178, 178);
	}break;
	case'8':
	{
		(*pozycja).Y = 5;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *pozycja);
		printf("  %c%c%c%c%c%c  \n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);
		(*pozycja).Y = 6;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *pozycja);
		printf("%c%c      %c%c\n", 178, 178, 178, 178);
		(*pozycja).Y = 7;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *pozycja);
		printf("%c%c      %c%c\n", 178, 178, 178, 178);
		(*pozycja).Y = 8;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *pozycja);
		printf("  %c%c%c%c%c%c  \n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);
		(*pozycja).Y = 9;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *pozycja);
		printf("%c%c      %c%c\n", 178, 178, 178, 178);
		(*pozycja).Y = 10;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *pozycja);
		printf("%c%c      %c%c\n", 178, 178, 178, 178);
		(*pozycja).Y = 11;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *pozycja);
		printf("  %c%c%c%c%c%c  \n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);
	}break;
	case'9':
	{
		(*pozycja).Y = 5;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *pozycja);
		printf("  %c%c%c%c%c%c  \n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);
		(*pozycja).Y = 6;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *pozycja);
		printf("%c%c      %c%c\n", 178, 178, 178, 178);
		(*pozycja).Y = 7;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *pozycja);
		printf("%c%c      %c%c\n", 178, 178, 178, 178);
		(*pozycja).Y = 8;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *pozycja);
		printf("  %c%c%c%c%c%c%c%c\n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);
		(*pozycja).Y = 9;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *pozycja);
		printf("        %c%c\n", 178, 178);
		(*pozycja).Y = 10;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *pozycja);
		printf("      %c%c  \n", 178, 178);
		(*pozycja).Y = 11;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *pozycja);
		printf("  %c%c%c%c    \n", 178, 178, 178, 178);
	}break;
	}
}
// Wyœwitla licznik punktów
void licznik(COORD *pozycja, int n)
{
	char tab[5];
	char j; //jednosci
	char d; //dziesiatki
	char s; //setki
	int y;

	sprintf(tab, "%d", n);

	//przypisanie zmiennym j, d, s wartosci w zaleznoœci od aktualnego wyniku n
	if (n <= 9)
	{
		j = tab[0];
		d = 48;
		s = 48;
	}
	else if (n >= 10 && n <= 99)
	{
		j = tab[1];
		d = tab[0];
		s = 48;
	}
	else if (n >= 100 && n <= 999)
	{
		j = tab[2];
		d = tab[1];
		s = tab[0];
	}

	y = 108;
	printf_cyfra(y, j, &pozycja);
	y = 96;
	printf_cyfra(y, d, &pozycja);
	y = 84;
	printf_cyfra(y, s, &pozycja);

}
// Wyœwietla menu i zczytuje wybór gracza
void printf_menu(char *sterowanie)
{
	system("cls");
	printf("\n\t\t\t\t  %c%c%c%c%c%c    %c%c      %c%c    %c%c%c%c%c%c    %c%c      %c%c  %c%c%c%c%c%c%c%c%c%c\n",178,178,178,178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);
	printf("\t\t\t\t%c%c      %c%c  %c%c%c%c    %c%c  %c%c      %c%c  %c%c    %c%c    %c%c\n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);
	printf("\t\t\t\t%c%c          %c%c  %c%c  %c%c  %c%c      %c%c  %c%c  %c%c      %c%c\n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);
	printf("\t\t\t\t  %c%c%c%c%c%c    %c%c    %c%c%c%c  %c%c%c%c%c%c%c%c%c%c  %c%c%c%c        %c%c%c%c%c%c%c%c%c%c\n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);
	printf("\t\t\t\t        %c%c  %c%c      %c%c  %c%c      %c%c  %c%c  %c%c      %c%c\n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);
	printf("\t\t\t\t%c%c      %c%c  %c%c      %c%c  %c%c      %c%c  %c%c    %c%c    %c%c\n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);
	printf("\t\t\t\t  %c%c%c%c%c%c    %c%c      %c%c  %c%c      %c%c  %c%c      %c%c  %c%c%c%c%c%c%c%c%c%c\n\n\n\n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);
	printf("\t\t\t\t\t\t   1\t<- PLAY\n\n");
	printf("\t\t\t\t\t\t   2\t<- LEADERBOARD\n\n");
	printf("\t\t\t\t\t\t   0\t<- CLOSE\n\n\n");
	printf("\t\t\t\t\t\t   Your choice:\t");
	scanf("%c", sterowanie);
	system("cls");
}
// Wyœwietla napis game over
void printf_gameover(COORD *pozycja)
{
	pozycja->X = 0;
	pozycja->Y = 0;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *pozycja);
	printf("\n\n\t\t  %c%c%c%c%c%c%c%c    %c%c%c%c%c%c    %c%c      %c%c  %c%c%c%c%c%c%c%c%c%c\n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);
	printf("\t\t%c%c          %c%c      %c%c  %c%c%c%c  %c%c%c%c  %c%c\n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);
	printf("\t\t%c%c          %c%c      %c%c  %c%c  %c%c  %c%c  %c%c\n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);
	printf("\t\t%c%c    %c%c%c%c  %c%c%c%c%c%c%c%c%c%c  %c%c  %c%c  %c%c  %c%c%c%c%c%c%c%c%c%c\n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);
	printf("\t\t%c%c      %c%c  %c%c      %c%c  %c%c      %c%c  %c%c\n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);
	printf("\t\t%c%c      %c%c  %c%c      %c%c  %c%c      %c%c  %c%c\n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);
	printf("\t\t  %c%c%c%c%c%c    %c%c      %c%c  %c%c      %c%c  %c%c%c%c%c%c%c%c%c%c\n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);

	printf("\n\n");

	printf("\t\t  %c%c%c%c%c%c    %c%c      %c%c  %c%c%c%c%c%c%c%c%c%c  %c%c%c%c%c%c%c%c\n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);
	printf("\t\t%c%c      %c%c  %c%c      %c%c  %c%c          %c%c      %c%c\n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);
	printf("\t\t%c%c      %c%c  %c%c      %c%c  %c%c          %c%c      %c%c\n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);
	printf("\t\t%c%c      %c%c  %c%c      %c%c  %c%c%c%c%c%c%c%c%c%c  %c%c%c%c%c%c%c%c\n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);
	printf("\t\t%c%c      %c%c  %c%c      %c%c  %c%c          %c%c      %c%c\n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);
	printf("\t\t%c%c      %c%c    %c%c  %c%c    %c%c          %c%c      %c%c\n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);
	printf("\t\t  %c%c%c%c%c%c        %c%c      %c%c%c%c%c%c%c%c%c%c  %c%c      %c%c\n\n\n\n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);

}
// Wyœwietla planszê przed rozpoczêciem rozgrywki
void rysuj_plansze(COORD *pozycja)
{

	char c;
	c = 201;
	printf("%c", c);

	c = 205;
	for (int i = 1; i <= 80; i++)
	{
		pozycja->X = i;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *pozycja);
		printf("%c", c);
	}

	c = 187;
	printf("%c", c);

	c = 186;
	for (int i = 1; i <= 28; i++)
	{
		pozycja->X = 0;
		pozycja->Y = i;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *pozycja);
		printf("%c", c);

		pozycja->X = 81;
		pozycja->Y = i;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *pozycja);
		printf("%c\n", c);
	}

	c = 200;
	printf("%c", c);

	c = 205;
	for (int i = 1; i <= 80; i++)
	{
		pozycja->Y = 29;
		pozycja->X = i;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *pozycja);
		printf("%c", c);
	}

	c = 188;
	printf("%c", c);

	pozycja->X = 0;
	pozycja->Y = 0;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *pozycja);
}


// JAB£KO

// Rysuje kolejne jab³ko w randomowym miejscu na planszy
void rysuj_jablko(COORD *pozycja, COORD *jablko, int n, int *tabx, int *taby)
{
	int tmp = 0;
	do {
		tmp = 0;
		jablko->X = rand() % 30 + 1;
		jablko->X = jablko->X * 2 + 1;
		jablko->Y = rand() % 28 + 1;

		for (int i = n - 1; i >= 0; i--)											// zabezpieczenie przed wylosowaniem jab³ka w wê¿u
		{
			if (jablko->X == *(tabx + i) && jablko->Y == *(taby + i))
				tmp++;
		}

	} while (tmp > 0);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *jablko);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
	printf("%c%c", 219, 219);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *pozycja);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}
// Sprawdza czy zosta³o zjedzone jab³ko
void czy_jablko(COORD *pozycja, COORD *jablko, int *n, int *zjedzone, int *tabx, int *taby)
{
	int tx;
	int ty;

	if ((*pozycja).X == (*jablko).X && (*pozycja).Y == (*jablko).Y)
	{
		*n = *n + 1;
		rysuj_jablko(pozycja, jablko, *n, tabx, taby);
		zjedzone = 1;

		tx = pozycja->X;
		ty = pozycja->Y;
		licznik(pozycja, *n);
		pozycja->X = tx;
		pozycja->Y = ty;
	}
}


// REKORDY

// Wyœwietla tablicê wyników z pliku
void leaderboards(COORD *pozycja)
{
	char esc;
	char tmp[100];
	char nazwa[50];
	int lp=1;
	int wynik=0;
	int tx;
	int ty;

	tx = pozycja->X;
	ty = pozycja->Y;

	FILE *plik;
	plik = fopen("leaderboard.txt","r");
	if (plik != NULL)
	{
		pozycja->X = 53;
		pozycja->Y = 1;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *pozycja);
		printf("LEADERBOARD\n\n\n");
		pozycja->X = 45;
		pozycja->Y = 2;
		do
		{
			fscanf(plik, "%s", &tmp);
			sscanf(tmp, "%[^;] ; %d;", &nazwa, &wynik);
			pozycja->X = 45;
			pozycja->Y = pozycja->Y+2;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *pozycja);
			printf("%d.", lp);
			pozycja->X = pozycja->X + 4;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *pozycja);
			printf("%s", nazwa);
			pozycja->X = pozycja->X + 18;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *pozycja);
			printf("  %d                   ", wynik);
			lp++;
		} while (sscanf(tmp, "%[^;] ; %d", &nazwa, &wynik) > 1 && feof(plik) == 0 && lp <= 10);

		fclose(plik);
	}else printf("\n\t\t\t  The 'leaderboard.txt' file is corrupted or does not exist.\n\n\n");

	pozycja->X = 44;
	pozycja->Y = pozycja->Y + 4;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *pozycja);
	printf("Press ESC to go back to menu\n\n");
	do
	{
		esc = getch();
	} while (esc != 27);

	}
// Zapisuje wynik do pliku
void zapisz_wynik(int n, char imie[])
{
	char esc;
	char tmp[50];
	char tmp2[400];
	char nazwa[50];
	char rekordy[400];
	int ilosc = 0;
	int wynik = 0;
	int miejsce=0;
	int pozycja;
	int i = 0;

	FILE *plik;
	plik = fopen("leaderboard.txt", "r+");

	if (plik != NULL)
	{
		do
		{
			pozycja = ftell(plik);
			fscanf(plik, "%s", &tmp);
			sscanf(tmp, "%[^;] ; %d.", &nazwa, &wynik);
			miejsce++;
			ilosc++;
		} while (n<=wynik && feof(plik)==0);
		

		if (feof(plik) == 0 )
		{
			strcpy(rekordy, &tmp);
			while (feof(plik) == 0)
			{
				fscanf(plik, "%s", &tmp);
				strcat(rekordy, &tmp);
				ilosc++;
			}
		}

		if (miejsce != 1)
		{
			fseek(plik, pozycja + 1, SEEK_SET);
			fprintf(plik, "\n%s;%d.", imie, n);
		}
		else
		{
			fseek(plik, pozycja, SEEK_SET);
			fprintf(plik, "%s;%d.", imie, n);
		}

		if (ilosc-miejsce != 0)
		{
			while (i <= ilosc - miejsce && i < 10 - miejsce)
			{
				i++;
				sscanf(rekordy, "%[^.].%s", &tmp, &tmp2);
				strcpy(rekordy, &tmp2);
				fprintf(plik, "\n%s.", tmp);
			}
		}
		fclose(plik);
	}
	else printf("\n\t\t\t  The 'leaderboard.txt' file is corrupted or does not exist.\n\n\n");
}
// Sprawdza czy wynik nadaje siê do zapisania w tablicy wyników
int czy_rekord(int n)
{
	int wynik = 0;
	FILE *plik;
	plik = fopen("leaderboard.txt", "r");
	
	if (plik != NULL)
	{
		fseek(plik, -2, SEEK_END);
		fscanf(plik, "%d", &wynik);

		fclose(plik);
		if (n > wynik)
			return 1;
		else return 0;
	}
	else
	{
		printf("\n\t  The 'leaderboard.txt' file is corrupted or does not exist.\n\n\n");
		return 0;
	}
}


// MAIN

int main()
{
	// deklaracje zmiennych
	srand(time(NULL));
	unsigned char sterowanie = 224;
	unsigned char bufor = 0;
	char imie[20];
	char ctmp[20];
	char esc;
	int n = 1;
	int zjedzone = 0;
	int tmp = 0;
	int tx = 0;
	int ty = 0;
	int i;
	int powrot=1;
	int przegrana = 0;
	int rekord = 1;
	int *tabx = malloc(n * sizeof(int));
	int *taby = malloc(n * sizeof(int));
	
	// ustawienie niewidzialnoœci kursora
	{
		CONSOLE_CURSOR_INFO info;
		info.dwSize = 100;
		info.bVisible = FALSE;
		SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
	}

	do
	{
		do
		{
			printf_menu(&sterowanie);
		} while (sterowanie < 48 || sterowanie>50);							// wyœwietlanie menu i zczytanie wyboru gracza

		switch (sterowanie)
		{
		case '1'://PLAY
		{
			pozycja.X = 0;
			pozycja.Y = 0;

			// start rozgrywki
			{
				rysuj_plansze(&pozycja);
				pozycja.X = rand() % 30 + 1;
				pozycja.X = pozycja.X * 2 + 1;
				pozycja.Y = rand() % 22 + 1;
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pozycja);
				*tabx = pozycja.X;
				*taby = pozycja.Y;
				printf("%c%c", 219, 219);
				rysuj_jablko(&pozycja, &jablko, n,tabx,taby);

				tx = pozycja.X;
				ty = pozycja.Y;
				licznik(&pozycja, n);
				pozycja.X = tx;
				pozycja.Y = ty;
			}

			// przebieg rozgrywki
			do
			{
				// zabezpieczenie przed wciœniêciem innego klawisza ni¿ strza³ka
				{
					if (n == 1)
					{
						do
						{
							bufor = getch();
							bufor = getch();
						} while (bufor != 75 && bufor != 77 && bufor != 72 && bufor != 80);
						if (bufor == 75 || bufor == 77 || bufor == 72 || bufor == 80)
							sterowanie = bufor;
					}
					else
					{
						bufor = getch();
						bufor = getch();

						if (bufor == 75 || bufor == 77 || bufor == 72 || bufor == 80)
							sterowanie = bufor;
					}
				}
					
					/*
					H=72=gora
					P=80=dol
					M=77=prawo
					K=75=lewo
					*/

					switch (sterowanie)
					{
					case 75://lewo
					{
						do
						{
							usun_blok(&pozycja, &zjedzone, n, tabx, taby);									// usuniêcie ostatniego bloku

							czy_jablko(&pozycja, &jablko, &n, &zjedzone,tabx,taby);									// czynnoœci wykonywane w przypadku zjedzenia jab³ka
							tabx = realloc(tabx, n * sizeof(int));
							taby = realloc(taby, n * sizeof(int));

							pozycja.X = pozycja.X - 2;														// ustawienie wartoœci wspó³rzêdnych nowego bloku

							for (i = n - 1; i >= 1; i--)													// przesuniêcie wspó³rzêdnych w tablicach o jedn¹ pozycjê
							{
								*(tabx + i) = *(tabx + i - 1);
								*(taby + i) = *(taby + i - 1);
							}

							*tabx = pozycja.X;																// wpisanie do pierwszych miejsc w tablicach wartoœci wspó³rzêdnych nowego bloku
							*taby = pozycja.Y;

							przegrana = gameover(pozycja, jablko, n, tabx, taby);							// sprawdzenie czy w¹¿ w coœ uderzy³
							if (przegrana == 0)
							{
								SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pozycja);			// ustawienie kursora na pozycji nowego bloku i narysowanie nowego bloku
								putchar(219);
								putchar(219);
								Sleep(100);																	// gracz ma 0.1 sekundy na zmianê kierunku zanim pêtla ponownie siê wykona i w¹¿ siê poruszy
							}
						} while (przegrana == 0 && kbhit() == 0);
					}break;

					case 77://prawo
					{
						do
						{
							usun_blok(&pozycja, &zjedzone, n, tabx, taby);									// usuniêcie ostatniego bloku

							czy_jablko(&pozycja, &jablko, &n, &zjedzone, tabx, taby);						// czynnoœci wykonywane w przypadku zjedzenia jab³ka
							tabx = realloc(tabx, n * sizeof(int));
							taby = realloc(taby, n * sizeof(int));

							pozycja.X = pozycja.X + 2;														// ustawienie wartoœci wspó³rzêdnych nowego bloku

							for (i = n - 1; i >= 1; i--)													// przesuniêcie wspó³rzêdnych w tablicach o jedn¹ pozycjê
							{
								*(tabx + i) = *(tabx + i - 1);
								*(taby + i) = *(taby + i - 1);
							}

							*tabx = pozycja.X;																// wpisanie do pierwszych miejsc w tablicach wartoœci wspó³rzêdnych nowego bloku
							*taby = pozycja.Y;

							przegrana = gameover(pozycja, jablko, n, tabx, taby);							// sprawdzenie czy w¹¿ w coœ uderzy³
							if (przegrana == 0)
							{
								SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pozycja);			// ustawienie kursora na pozycji nowego bloku i narysowanie nowego bloku
								putchar(219);
								putchar(219);
								Sleep(100);																	// gracz ma 0.1 sekundy na zmianê kierunku zanim pêtla ponownie siê wykona i w¹¿ siê poruszy
							}
						} while (przegrana == 0 && kbhit() == 0);
					}break;

					case 72://gora
					{
						do
						{
							usun_blok(&pozycja, &zjedzone, n, tabx, taby);									// usuniêcie ostatniego bloku

							czy_jablko(&pozycja, &jablko, &n, &zjedzone, tabx, taby);						// czynnoœci wykonywane w przypadku zjedzenia jab³ka
							tabx = realloc(tabx, n * sizeof(int));
							taby = realloc(taby, n * sizeof(int));

							pozycja.Y = pozycja.Y - 1;														// ustawienie wartoœci wspó³rzêdnych nowego bloku

							for (i = n - 1; i >= 1; i--)													// przesuniêcie wspó³rzêdnych w tablicach o jedn¹ pozycjê
							{
								*(tabx + i) = *(tabx + i - 1);
								*(taby + i) = *(taby + i - 1);
							}

							*tabx = pozycja.X;																// wpisanie do pierwszych miejsc w tablicach wartoœci wspó³rzêdnych nowego bloku
							*taby = pozycja.Y;

							przegrana = gameover(pozycja, jablko, n, tabx, taby);							// sprawdzenie czy w¹¿ w coœ uderzy³
							if (przegrana == 0)
							{
								SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pozycja);			// ustawienie kursora na pozycji nowego bloku i narysowanie nowego bloku
								putchar(219);
								putchar(219);
								Sleep(100);																	// gracz ma 0.1 sekundy na zmianê kierunku zanim pêtla ponownie siê wykona i w¹¿ siê poruszy
							}
						} while (przegrana == 0 && kbhit() == 0);
					}break;

					case 80://dol
					{
						do
						{
							usun_blok(&pozycja, &zjedzone, n, tabx, taby);									// usuniêcie ostatniego bloku

							czy_jablko(&pozycja, &jablko, &n, &zjedzone, tabx, taby);						// czynnoœci wykonywane w przypadku zjedzenia jab³ka
							tabx = realloc(tabx, n * sizeof(int));
							taby = realloc(taby, n * sizeof(int));

							pozycja.Y = pozycja.Y + 1;														// ustawienie wartoœci wspó³rzêdnych nowego bloku

							for (i = n - 1; i >= 1; i--)													// przesuniêcie wspó³rzêdnych w tablicach o jedn¹ pozycjê
							{
								*(tabx + i) = *(tabx + i - 1);
								*(taby + i) = *(taby + i - 1);
							}

							*tabx = pozycja.X;																// wpisanie do pierwszych miejsc w tablicach wartoœci wspó³rzêdnych nowego bloku
							*taby = pozycja.Y;

							przegrana = gameover(pozycja, jablko, n, tabx, taby);							// sprawdzenie czy w¹¿ w coœ uderzy³
							if (przegrana == 0)
							{
								SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pozycja);			// ustawienie kursora na pozycji nowego bloku i narysowanie nowego bloku
								putchar(219);
								putchar(219);
								Sleep(100);																	// gracz ma 0.1 sekundy na zmianê kierunku zanim pêtla ponownie siê wykona i w¹¿ siê poruszy
							}
						} while (przegrana == 0 && kbhit() == 0);
					}
					}
			} while (przegrana == 0 && kbhit() != 0);

			printf_gameover(&pozycja);

			// ewentualne zapisanie rekordu do leaderboard
			rekord = czy_rekord(n);
			if (n > 1 && rekord==1)
			{
				printf("\n\n\n");
				pozycja.Y = 20;
				pozycja.X = 31;
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pozycja);
				CONSOLE_CURSOR_INFO info;
				info.dwSize = 15;
				info.bVisible = TRUE;
				SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
				printf("Enter your name: ");
				pozycja.Y = pozycja.Y + 3;
				pozycja.X = 31;
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pozycja);
				scanf("%s",&imie);

				info.bVisible = FALSE;
				SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);

				zapisz_wynik(n, imie);

				system("cls");
				leaderboards(&pozycja);	
			}
			else
			{
				printf("\n\n\t\t\tPress ESC to go back to menu\n\n");
				do
				{
					esc = getch();
				} while (esc != 27);
				//bufor = getch();
			}

			n = 1;
			powrot = 1;

		}break;
		case '2'://LEADERBOARD
		{
			leaderboards(&pozycja);

			getch();

		}break;
		case '0'://CLOSE
		{
			exit(0);
		}
		default: powrot = 1;
		}
	}while (powrot==1);

	system("pause");
	return 0;
}