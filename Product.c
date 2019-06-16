#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
char name[100], color[100];
int price[100];
//void addProduct(int *needUse, char name[100]);
//void outProduct(int *needUse, char name[100]);
void TextColor1(int x) {
	HANDLE colour;
	colour = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(colour, x);
}

void addProduct(int price[100], char name[100], char color[100]) {
	TextColor1(9);
	printf("\tName Product: ");
	TextColor1(7);
	gets(name);
	TextColor1(9);
	printf("\tColor: ");
	TextColor1(7);
	gets(color);
	TextColor1(9);
	printf("Price: ");
	TextColor1(7);
	scanf("%d", &price);
}

void outProduct(int price[100], char name[100], char color[100]) {
	TextColor1(14);
	printf("\n\t   %s \t   %d  %s, Black \n\n", name, price, color);
}

void product() {
	TextColor1(11);
	printf("\n\t   * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	TextColor1(9);
	printf("\n\t\t\t You chose Ordinary laptop. \n\n");
	printf("\t\t\tPlease choose your laptop(s): \n\n");
	TextColor1(12);
	printf("\t\t\t      Price \t\tColor");
	TextColor1(14);
	printf("\n\t   1. Inspiron\t   10.000.000 VND  Red, blue, black \n");
	printf("\n\t   2. Inspiron Duo 15.000.000 VND  Blue, Black \n");
	printf("\n\t   3. XPS \t   20.000.000 VND  Gold-rose, Silver, Black \n\n");
	outProduct(price, name, color);
	TextColor1(5);
	printf("\t\t\t ============================ \n");
	TextColor1(11);
	printf("\n\t   * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	TextColor1(14);
	printf("\n\t Your choice is: ");
}
