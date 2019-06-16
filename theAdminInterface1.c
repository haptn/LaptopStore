#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include "theBestSeller.c"
#include "display.c"
#include "Product.c"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void TextColor3(int x) {
	HANDLE colour;
	colour = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(colour, x);
}

void exitFirst();
void exitAdmin();
int mainVan()
{
	int choice, needUse;
	char str[100];
	char cont;
//	do{								// Ha removed here.
//		homeScreen();
//	 	choice = getChoice1();
//	 	system("cls");
//		switch(choice)
//		{
//		case 1:
			inputAdmin();
			BACK:
			admin();
			choice = getChoice1();
			system("cls");
			switch(choice) {
				case 1:
					addAdmin();
					system("cls");
					break;
				case 2:
					addProduct(price, name, color);
					system("cls");
					goto BACK;
					break;
				case 3:
					do {
						sale();
						choice = getChoice2();
						system("cls");
						switch(choice) {
							case 1:
								bestSellerInWeek();
								break;
							case 2:
								bestSellerInMonth();
								break;
							case 3:
								salesInMonth();
								break;
							case 4:
								// back();				// Ha removed here.
								goto BACK;				// Ha changed here.
								system("cls");
								break;
						}
						cont = getch();
						system("cls");
					} while(cont != 27);
					break;
			}
//		break;
//		case 2:
//			break;
//		case 3:
			exitFirst();
			exit(0);
//			break;
//		}
		printf("\n\tPress any to continue. ESC to exit!");
		cont = getch();
//	} while(cont != 27);
	return 0;
}

//void addProduct(int *needUse, char name[100]){
//	int i;
//	printf("Input add number of product: ");
//	scanf("%d", needUse);
//	for(i = 4; i < *needUse; i++)
//	{
//		fflush(stdin);
//		gets(name[i]);
//	}
//}

void exitFirst() {
	TextColor3(7);
	printf("\t _____________________________________________________________________\n\t|");
	TextColor3(12);
	printf("                        Nhat Thi's Laptop Store                      ");
	TextColor3(7);
	printf("|\n\t|                                                                     |\n\t|");
	TextColor3(11);
	printf("   Thank you for visiting our page! It's our pleasure to serve you!  ");
	TextColor3(7);
	printf("|\n\t|                                                                     |\n\t|");
	TextColor3(11);
	printf("   See you again.                                                    ");
	TextColor3(7);
	printf("|\n\t|_____________________________________________________________________|\n");
}

void exitAdmin() {
	TextColor3(7);
	printf("\t _____________________________________________________________________\n\t|");
	TextColor3(12);
	printf("                        Nhat Thi's Laptop Store                      ");
	TextColor3(7);
	printf("|\n\t|                                                                     |\n\t|");
	TextColor3(11);
	printf("\tHave a nice day!                                              ");
	TextColor3(7);
	printf("|\n\t|_____________________________________________________________________|\n");
}
