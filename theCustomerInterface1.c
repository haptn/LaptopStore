#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

// The Customer Interface

struct buyLaptop
{
	char customerName[50];
	char customerPhoneNum[15];
	int productQuantity;	// Numbers of product available in storage.	// Why I can't declare "int buyingNumber = 10;" here?
	char productType[20];
	char productName[15];
	double price;
	int buyingNumber;		// Numbers of product customer bought.		// Why I can't declare "int buyingNumber = 0;" here?
	char requirement[500];	// Customer requirements.
} buyLaptop;

void TextColor4(int x)
{
	HANDLE colour;
	colour = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(colour, x);
}

int chooseForFast();
void searchProduct();

void printProductMenu()
{
	char filename[20] = "BuyingActivities.txt";
	int countPhoneNum, i;
	char a;
	char phone[i];
	
	printf("\n \t \t \t \t \t \t \t * * * * * * * * * * * * * * * * * * * * * * * * * * \n");
	printf("\t \t \t \t \t \t \t \t Welcome to Nhat Thi's Laptop Store \n \n");
	printf("\t \t \t \t \t Your name is: ");
	
	FILE *f = fopen(filename, "a");
	fflush(stdin);
	gets(buyLaptop.customerName);
	fprintf(f, "\n \n%s | ", buyLaptop.customerName);
//	printf("\t \t \t \t \t Your phone number is (Please do not add space between each digit): ");
//	gets(phone);
//	do
//	{
//		fflush(stdin);
//		countPhoneNum = scanf("%s%c", &phone, &a);
//		if (i < 10 || i > 11 || countPhoneNum != 2 || a != '\n' || strcmp(phone, "0123456789") == 0 || strcmp(phone, "01234567890") == 0 || strcmp(phone, "0987654321") == 0)
//		{
//			printf("\t \t \t \t \t \t    Please input your phone number again: ");
//		}
//	} while (i < 10 || i > 11 || countPhoneNum != 2 || a != '\n' || strcmp(phone, "0123456789") == 0 || strcmp(phone, "01234567890") == 0 || strcmp(phone, "0987654321") == 0);
//	
//	strcpy(buyLaptop.customerPhoneNum, phone);

	printf("\t \t \t \t \t Your phone number is: ");
	gets(buyLaptop.customerPhoneNum);
	fprintf(f, "%s | ", buyLaptop.customerPhoneNum);
	fclose(f);
	
	printf("\t \t \t \t \t Welcome [%s]! \n \n", buyLaptop.customerName);
	printf("\t \t \t \t \t \t    In Nhat Thi's Laptop Store, we sell only Dell's product range. \n");
	printf("\t \t \t \t \t \t      1. Ordinary laptop \n");
	printf("\t \t \t \t \t \t      2. Business laptop \n");
	printf("\t \t \t \t \t \t      3. Gaming laptop \n");
	
//	int goFast = chooseForFast();
//	searchProduct();
}

void buyMore()
{	
	FILE *f = fopen("BuyingActivities.txt", "a");
	fflush(stdin);
	fprintf(f, "\n%s | ", buyLaptop.customerName);
	fprintf(f, "%s | ", buyLaptop.customerPhoneNum);
	fclose(f);
	
	printf("\n \t \t \t \t \t \t \t * * * * * * * * * * * * * * * * * * * * * * * * * * \n");
	printf("\n \t \t \t \t \t \t    In Nhat Thi's Laptop Store, we sell only Dell's product range. \n");
	printf("\t \t \t \t \t \t      1. Ordinary laptop \n");
	printf("\t \t \t \t \t \t      2. Business laptop \n");
	printf("\t \t \t \t \t \t      3. Gaming laptop \n");
	
//	int goFast = chooseForFast();
	searchProduct();
}

void printOrdinaryLaptopMenu();
void printBusinessLaptopMenu();
void printGamingLaptopMenu();

int chooseForFast()
{
	int goFast;
	
	printf("\n \t \t \t \t \t \t    Do you want to search for fast or you want to go step-by-step?");
	printf("\n \t \t \t \t \t \t    (Search = '1', Step-by-step = '0') ");
	scanf("%d", &goFast);
	
	return goFast;
}

void searchProduct()
{
	int goFast, lapchoice;
	char findProduct[50];
	
	GO_FAST:
	if (chooseForFast() == 1 || goFast == 1)
	{
		fflush(stdin);
		printf("\n \t \t \t \t \t \t    What product you are finding? ");
		gets(findProduct);
		strlwr(findProduct); 	// To lower all characters in the string.
		
		if (strcmp(findProduct, "inspiron") == 0 || strcmp(findProduct, "inspiron duo") == 0  || strcmp(findProduct, "xps") == 0)
		{
			printOrdinaryLaptopMenu();
		}
		else if (strcmp(findProduct, "vostro") == 0 || strcmp(findProduct, "latitude") == 0)
		{
			printBusinessLaptopMenu();
		}
		else if (strcmp(findProduct, "alienware") == 0)
		{
			printGamingLaptopMenu();
		}
		else
		{
			printf("\n \t \t \t \t \t Sorry! We cannot find the product related to what you typed. Please choose '0' to go step-by-step. ");  // Show this when data can't be found.
			fflush(stdin);
			scanf("%d", &goFast);
			goto GO_FAST;
		}
	}
	else if (chooseForFast() == 0 || goFast == 0)
	{
		lapchoice = getLaptopType();
	}
	else
	{
		printf("\n \t \t \t \t \t \t    Unavailable! Please choose again! ");
		fflush(stdin);
		scanf("%d", &goFast);
		goto GO_FAST;
	}
}

int getLaptopType()
{
	int lapchoice, countlap;
	char a;
	
	printf("\n \t \t \t \t \t \t    Please choose the one type as your purpose: ");
	FILE *f = fopen("BuyingActivities.txt", "a");
	do
	{
		fflush(stdin);
		countlap = scanf("%d%c", &lapchoice, &a);
		if (lapchoice < 1 || lapchoice > 3 || countlap != 2 || a != '\n')
		{
			printf("\n \t \t \t \t \t \t    Unavailable! Please choose again!");
			printf("\n \t \t \t \t \t \t    Please choose the one as your purpose: ");
		}
	} while (lapchoice < 1 || lapchoice > 3 || countlap != 2 || a != '\n');
	
	switch (lapchoice)
	{
		case 1:
			strcpy(buyLaptop.productType, "Ordinary");
			fprintf(f, "%s | ", buyLaptop.productType);
			break;
		
		case 2:
			strcpy(buyLaptop.productType, "Business");
			fprintf(f, "%s | ", buyLaptop.productType);
			break;
			
		case 3:
			strcpy(buyLaptop.productType, "Gaming");
			fprintf(f, "%s | ", buyLaptop.productType);
			break;	
	}
	
	fclose(f);
	
	return lapchoice;
}

// Ordinary Laptop Interface
void printOrdinaryLaptopMenu()
{
	printf("\n \n \t \t \t \t \t \t \t * * * * * * * * * * * * * * * * * * * * * * * * * * \n");
	printf("\n \t \t \t \t \t You chose Ordinary laptop. \n \n");
	
	printf("\n \t \t \t \t \t \t    Please choose your laptop(s): \n");
	printf("\t \t \t \t \t \t \t \t \t \tPrice \t \t      Color \n");
	printf("\n \t \t \t \t \t \t      1. Inspiron \t    10.000.000 VND \t Red, blue, black \n");
	printf("\n \t \t \t \t \t \t      2. Inspiron Duo	    15.000.000 VND \t Blue, Black \n");
	printf("\n \t \t \t \t \t \t      3. XPS \t \t    20.000.000 VND	 Gold-rose, Silver, Black \n");
	printf("\t \t \t \t \t \t    ============================ \n");
	printf("\t \t \t \t \t \t    Your choice is: ");
}

int getOrdinaryLaptop()
{
	int ordichoice, countordi;
	char b;
	
	FILE *f = fopen("BuyingActivities.txt", "a");
	do
	{			
		fflush(stdin);
		countordi = scanf("%d%c", &ordichoice, &b);
		if (ordichoice < 1 || ordichoice > 3 || countordi != 2 || b != '\n')
		{
			printf("\n \t \t \t \t \t \t    Unavailable! Please choose one from the list above! \n");
			printf("\n \t \t \t \t \t \t    Your choice is: ");
		}
	} while (ordichoice < 1 || ordichoice > 3 || countordi != 2 || b != '\n');
	
	switch (ordichoice)
	{
		case 1:
			strcpy(buyLaptop.productName, "Inspiron");
			fprintf(f, "%s | ", buyLaptop.productName);
			break;
		
		case 2:
			strcpy(buyLaptop.productName, "Inspiron Duo");
			fprintf(f, "%s | ", buyLaptop.productName);
			break;
			
		case 3:
			strcpy(buyLaptop.productName, "XPS");
			fprintf(f, "%s | ", buyLaptop.productName);
			break;	
	}
	
	fclose(f);
	
	return ordichoice;
}

// Business Laptop Interface
void printBusinessLaptopMenu()
{
	printf("\n \n \t \t \t \t \t You chose Business laptop. \n");
	
	printf("\n \t \t \t \t \t \t    Please choose your laptop(s): \n");
	printf("\t \t \t \t \t \t \t \t \t \tPrice \t \t      Color \n");
	printf("\n \t \t \t \t \t \t      1. Vostro \t    13.000.000 VND \t Gold, Silver, Black \n");
	printf("\n \t \t \t \t \t \t      2. Latitude \t    20.000.000 VND \t Silver, Black \n");
	printf("\t \t \t \t \t \t    ============================ \n");
	printf("\t \t \t \t \t \t    Your choice is: ");
}

int getBusinessLaptop()
{
	int bizchoice, countbiz;
	char d;
	
	FILE *f = fopen("BuyingActivities.txt", "a");
	do
	{			
		fflush(stdin);
		countbiz = scanf("%d%c", &bizchoice, &d);
		if (bizchoice < 1 || bizchoice > 2 || countbiz != 2 || d != '\n')
		{
			printf("\n \t \t \t \t \t \t    Unavailable! Please choose one from the list above! \n");
			printf("\n \t \t \t \t \t \t    Your choice is: ");
		}
	} while (bizchoice < 1 || bizchoice > 2 || countbiz != 2 || d != '\n');
	
	switch (bizchoice)
	{
		case 1:
			strcpy(buyLaptop.productName, "Vostro");
			fprintf(f, "%s | ", buyLaptop.productName);
			break;
		
		case 2:
			strcpy(buyLaptop.productName, "Latitude");
			fprintf(f, "%s | ", buyLaptop.productName);
			break;
	}
	
	fclose(f);
	
	return bizchoice;
}

// Gaming Laptop Interface
void printGamingLaptopMenu()
{
	printf("\n \n \t \t \t \t \t \t \t * * * * * * * * * * * * * * * * * * * * * * * * * * \n");
	printf("\n \t \t \t \t \t You chose Gaming laptop. \n \n");
	
	printf("\n \t \t \t \t \t \t    Please choose your laptop(s): \n");
	printf("\t \t \t \t \t \t \t \t \t \tPrice \t \t Light's Color \n");
	printf("\n \t \t \t \t \t \t      1. Alienware \t    26.000.000 VND \t   Red, Blue \n");
	printf("\t \t \t \t \t \t    ============================ \n");
	printf("\t \t \t \t \t \t    Your choice is: ");
}

int getGamingLaptop()
{
	int gamechoice, countgame;
	char e;
	
	FILE *f = fopen("BuyingActivities.txt", "a");
	do
	{			
		fflush(stdin);
		countgame = scanf("%d%c", &gamechoice, &e);
		if (gamechoice != 1 || countgame != 2 || e != '\n')
		{
			printf("\n \t \t \t \t \t \t    Unavailable! Please choose one from the list above! \n");
			printf("\n \t \t \t \t \t \t    Your choice is: ");
		}
	} while (gamechoice != 1 || countgame != 2 || e != '\n');
	
	if (gamechoice == 1)
	{
		strcpy(buyLaptop.productName, "Alienware");
		fprintf(f, "%s | ", buyLaptop.productName);
		buyLaptop.buyingNumber++;
	}
	
	fclose(f);
	
	return gamechoice;
}

void takeCustomersRequirements();
void takeBill_Warranty();

// This Function is for solving the Function "takeCustomersRequirements()"
void BuyAgain()
{
	char continuing;
	fflush(stdin);
	printf("\n \t \t \t \t \t Do you want to buy anything else? (Yes = 'Y'; No = 'N') ");
	CONTINUE: fflush(stdin);
	scanf("%c", &continuing);
	
	if (continuing == 'Y' || continuing == 'y')
	{ 
		buyMore();
		switch (getLaptopType())
		{
			case 1:
				printOrdinaryLaptopMenu();
				getOrdinaryLaptop();
				break;
			
			case 2:
				printBusinessLaptopMenu();
				getBusinessLaptop();
				break;
				
			case 3:
				printGamingLaptopMenu();
				getGamingLaptop();
				break;
		}
		takeCustomersRequirements();
	}
	else if (continuing == 'N' || continuing == 'n')
	{
		printf("\n \t \t \t \t \t Thank you. Please 'Enter' to check your bill below. \n");
		getch();
		takeBill_Warranty();
	}
	else 
	{
		printf("\n \t \t \t \t \t Sorry! We didn't understand. Please choose again! ");
		goto CONTINUE;
	}
}

// Take Customer's Requirements
void takeCustomersRequirements()
{
	char getRequirements;
	
	printf("\n \t \t \t \t \t Do you have any requirements (color, monitor size, configuration)? (Yes = 'Y'; No = 'N') ");
	REQUIRE: fflush(stdin);
	scanf("%c", &getRequirements);
	
	if (getRequirements == 'Y' || getRequirements == 'y')
	{
		fflush(stdin);
		printf("\n \t \t \t \t \t Please require here: ");
		
		FILE *f = fopen("BuyingActivities.txt", "a");
		gets(buyLaptop.requirement);
		fprintf(f, "%s | ", buyLaptop.requirement);
		fclose(f);
		
		printf("\n \t \t \t \t \t Your requirements are received. \n");
		BuyAgain();
	}
	else if (getRequirements == 'N' || getRequirements == 'n')
	{
		BuyAgain();
	}
	else
	{
		printf("\n \t \t \t \t \t Sorry! We didn't understand. Please choose again! ");
		goto REQUIRE;
	}
}

// Bill and Warranty Interface
void takeBill_Warranty()
{
//	char changeInfo;
//	char adjustInfo[300];
	
	double price = 0;
	int buyingQuantity = 1;
	time_t t = time(NULL);			  //Source code: buiminhhuy1102 - SinhvienIT.net
	struct tm tm = *localtime(&t);	  //Source code: buiminhhuy1102 - SinhvienIT.net
	
	if (strcmp(buyLaptop.productName, "Inspiron") == 0)
	{
		price = 10000000;
	}
	else if (strcmp(buyLaptop.productName, "Latitude") == 0)
	{
		price = 13000000;
	}
	else if (strcmp(buyLaptop.productName, "Inspiron Duo") == 0)
	{
		price = 15000000;
	}
	else if (strcmp(buyLaptop.productName, "XPS") == 0 || strcmp(buyLaptop.productName, "Latitude") == 0)
	{
		price = 20000000;
	}
	else if (strcmp(buyLaptop.productName, "Alienware") == 0)
	{
		price = 26000000;
	}
	
//	switch (buyLaptop.productName)
//	{
//		case "Inspiron":
//			buyLaptop.price = 10000000;
//			break;
//		
//		case "Inspiron Duo":
//			buyLaptop.price = 15000000;
//			break;
//		
//		case "XPS":
//		case "Latitude":
//			buyLaptop.price = 20000000;
//			break;
//			
//		case "Latitude":
//			buyLaptop.price = 13000000;
//			break;
//			
//		case "Alienware":
//			buyLaptop.price = 26000000;
//			break;
//	}
	
	// Bill
	printf("\n \n \t \t \t \t \t \t \t * * * * * * * * * * * * * * * * * * * * * * * * * * \n");
	printf("\t \t \t \t \t \t \t \t       Nhat Thi's Laptop Store \n");
	printf("\t \t \t \t \t \t \t \t \t       INVOICE \n \n");
	printf("\t \t \t \t \t Your items: \n");
	printf("\t \t \t \t \t ========================================================================================== \n");
	printf("\t \t \t \t \t \t  Product \t | Quantity | \t   Price     |      Cost      |     Sold date \n");
	printf("\t \t \t \t \t ========================================================================================== \n");
	printf("\t \t \t \t \t 1. %-20s | %4d     | %8.3lf VND   | %8.3lf VND   | %6d/%d/%d", buyLaptop.productName, buyingQuantity, price, buyingQuantity * price, tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900); //Source code of time: buiminhhuy1102 - SinhvienIT.net
	printf("\n \t \t \t \t \t ========================================================================================== \n \n");

//	CHANGE_INFO: // Still confused!
//	fflush(stdin);
//	printf("\t \t \t \t \t Do you want to change any information? (Yes = 'Y'; No = 'N') ");
//	scanf("%c", &changeInfo);
	
//	if (changeInfo == 'Y' || changeInfo == 'y')
//	{
//		fflush(stdin);
//		printf("\n \t \t What do you want to adjsut? ");
//		gets(adjustInfo); // Khong nen cho nhap chuoi ngay tu dau ma hay cho chon la sua Product hay quantity hay features (color, RAM,...).
//		
//		FILE *f = fopen("BuyingActivities.txt", "a");
//		fgets(adjustInfo, 300, (FILE*)f);
//		fprintf(f, " Requirements: %s \n", requirement);
//		fclose(f);
//		printf("\n \t \t Your requirements are received. \n");
//	}
//	else if (changeInfo == 'N' || changeInfo == 'n')
//	{
//		fflush(stdin);
//		BUY_MORE:
//		printf("\n \t \t Do you want to buy anything else? (Yes = 'Y'; No = 'N') ");
//		scanf("%c", &continuing);
//		
//		if (continuing == 'Y' || continuing == 'y')
//		{ // Re-test carefully!
//			buyMore(); 
//			getLaptopType();
//			switch (getLaptopType())
//			{
//				case 1:
//					printOrdinaryLaptopMenu();
//					getOrdinaryLaptop();
//					break;
//				
//				case 2:
//					printBusinessLaptopMenu();
//					getBusinessLaptop();
//					break;
//				
//				case 3:
//					printGamingLaptopMenu();
//					getGamingLaptop();
//					break;
//				
//				default:
//					printf(" Not available.");
//					break;
//			}
//			takeCustomersRequirements();
//		}
//		else if (continuing == 'N' || continuing == 'n')
//		{
//			printf("\n \t \t Thank you. Please check your bill below. \n");
//		}
//		else 
//		{
//			printf("\n \t \t Sorry! We didn't understand. Please choose again! \n");
//			goto BUY_MORE; // Xem lai tai sao bi lap 2 lan.
//		}
//	}
//	else
//	{
//		printf("\n \t \t Sorry! We didn't understand. Please choose again! \n");
//		goto CHANGE_INFO; // Xem lai tai sao bi lap 2 lan.
//	}
	
	// Warranty
	printf("\n \n \t \t \t \t \t \t \t * * * * * * * * * * * * * * * * * * * * * * * * * * \n");
	printf("\t \t \t \t \t \t This laptop has one-year warranty. This is your warranty card: \n");
	TextColor4(15);
	printf("\n \t \t \t \t \t \t  _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ");
	printf("\n \t \t \t \t \t \t | ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` ` |");
	printf("\n \t \t \t \t \t \t |                                                                 |");
//	FILE *f = fopen("BuyingActivities.txt", "r");
	printf("\n \t \t \t \t \t \t | \t Customer's name: %s \t \t", buyLaptop.customerName);
	printf("Phone Number: %s \t   |", buyLaptop.customerPhoneNum);
	printf("\n \t \t \t \t \t \t |                                                                 |");	
	
//	switch (ordichoice)
//	{
//		case 1:
//			printf("\n \t \t \t \t \t \t | \t Product: %s \t \t \t \t \t     | \n", lapname1);
//			break;
//		
//		case 2:
//			printf("\n \t \t \t \t \t \t | \t Product: %s \t \t \t \t \t     | \n", lapname2);
//			break;
//			
//		case 3:
//			printf("\n \t \t \t \t \t \t | \t Product: %s \t \t \t \t \t     | \n", lapname3);
//			break;	
//	}
//	
//	switch (bizchoice)
//	{
//		case 1:
//			printf("\n \t \t \t \t \t \t | \t Product: %s \t \t \t \t \t     | \n", lapname4);
//			break;
//		
//		case 2:
//			printf("\n \t \t \t \t \t \t | \t Product: %s \t \t \t \t \t     | \n", lapname5);
//			break;
//	}
//	
//	if (gamechoice == 1)
//	{
//		printf("\n \t \t \t \t \t \t | \t Product: %s \t \t \t \t \t     | \n", lapname6);
//	}
//	fclose(f);
	
	printf("\n \t \t \t \t \t \t | \t Date bought: %d/%d/%d \t \tDate valid: %d/%d/%d \t   |", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1901);
	printf("\n \t \t \t \t \t \t |                                                                 |");
	printf("\n \t \t \t \t \t \t |_._._._._._._._._._._._._._._._._._._._._._._._._._._._._._._._._| \n");
}

void exitForCustomer()
{
	printf("\n \n \t \t \t \t \t \t \t * * * * * * * * * * * * * * * * * * * * * * * * * * \n");
	printf("\t \t \t \t \t \t \t \t       Nhat Thi's Laptop Store \n \n");
	printf("\t \t \t \t \t Thank you for visiting our page! It's our pleasure to serve you! \n");
	printf("\t \t \t \t \t We hope you will satisfy and we wish you have good experience with your new laptop! \n");
	printf("\t \t \t \t \t See you again! \n");
}
