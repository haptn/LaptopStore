#include <stdio.h>
#include <windows.h>

// The 1st Interface

//void TextColor1(int x)
//{
//	HANDLE color;
//	color = GetStdHandle(STD_OUTPUT_HANDLE);
//	SetConsoleTextAttribute(color, x);
//}

void printFirstInterface()		// Not in used anymore.
{
//	TextColor1(2);
	printf("\t \t \t \t \t \t \t     ___________________________________________ \n");
	printf("\t \t \t \t \t \t \t    | \t \t \t \t \t        |\n");
//	TextColor1(12);
	printf("\t \t \t \t \t \t \t    |    Welcome to Nhat Thi's Laptop Store     |\n");
	printf("\t \t \t \t \t \t \t    | \t \t \t \t \t        |\n");
	printf("\t \t \t \t \t \t \t    |      1. Admin \t \t \t        |\n");
	printf("\t \t \t \t \t \t \t    |      2. Customer \t \t \t        | \n");
	printf("\t \t \t \t \t \t \t    |      3. Exit \t \t \t \t| \n");
	printf("\t \t \t \t \t \t \t    | \t \t \t \t \t        |\n");
	printf("\t \t \t \t \t \t \t    |    Please choose a suitable number:       | \n");
	printf("\t \t \t \t \t \t \t    |___________________________________________| \n");
	printf("\t \t \t \t \t \t \t     Your choice is: ");
}

int getChoiceFirstInterface()
{
	int choice, count;
	char c;
	do
	{	fflush(stdin);
		count = scanf("%d%c", &choice, &c);
		if (choice < 1 || choice > 3 || count != 2 || c != '\n')
		{
			printf("\n \t \t \t \t \t \t \t     Unavailable! Please input number again. \n");
			printf("\t \t \t \t \t \t \t     Please choose a suitable number: ");
		}
	} while (choice < 1 || choice > 3 || count != 2 || c != '\n');
	
	return choice;
}
