#include <stdio.h>
#include <stdlib.h>

void TextColor2(int x) {
	HANDLE colour;
	colour = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(colour, x);
}

void homeScreen() {
	TextColor2(10);
	printf("\t \t \t \t \t \t \t       ____________________________________________ \n");
	printf("\t \t \t \t \t \t \t      | \t \t \t \t \t       |\n \t \t \t \t \t \t \t      |");
	TextColor2(12);
	printf("     Welcome to Nhat Thi's Laptop Store     ");
	TextColor2(10);
	printf("|\n \t \t \t \t \t \t \t      | \t \t \t \t \t       |\n \t \t \t \t \t \t \t      |");
	TextColor2(9);
	printf("  Please choose a suitable number   ");
	TextColor2(10);
	printf("\t   |\n \t \t \t \t \t \t \t      | \t \t \t \t \t       |\n \t \t \t \t \t \t \t      |");
	TextColor2(14);
	printf("     1. Admin                       ");
	TextColor2(10);
	printf("\t   |\n \t \t \t \t \t \t \t      | \t \t \t \t \t       |\n \t \t \t \t \t \t \t      |");
	TextColor2(14);
	printf("     2. Customer                    ");
	TextColor2(10);
	printf("\t   |\n \t \t \t \t \t \t \t      | \t \t \t \t \t       |\n \t \t \t \t \t \t \t      |");
	TextColor2(14);
	printf("     3. Exit                        ");
	TextColor2(10);
	printf("\t   |\n \t \t \t \t \t \t \t      |____________________________________________| \n");
	TextColor2(15);
	printf("\n \t \t \t \t \t \t \t       Your choice is: ");
}

int getChoice1() {
	int choice, test;
	char c;
	do{
		fflush(stdin);
		TextColor2(15);
		printf("\n\t\tYour choice is: ");
		test = scanf("%d%c", &choice, &c);
		if(test != 2 || choice > 3 || choice < 1 || c != '\n'){
			printf("Unavailable! Please input number again!");
		}
	}while(test != 2 || choice > 3 || choice < 1 || c != '\n');
	return choice;
}

int getChoice2() {
	int choice, test;
	char c;
	do {
		fflush(stdin);
		TextColor2(15);
		printf("\n\t\tYour choice is: ");
		test = scanf("%d%c", &choice, &c);
		if(test != 2 || choice > 4 || choice < 1 || c != '\n') {
			printf("Unavailable! Please choose again!");
		}
	} while(test != 2 || choice > 4 || choice < 1 || c != '\n');
	return choice;
}

void inputAdmin() {
	char userName[] = "admin", passWord[] = "admin";
    char user[50], pass[50], chose; 
    int count = 0, i = 0;
 	TextColor2(12);
	printf("\t\t\tNhat Thi's Laptop Store\n\n");
	TextColor2(3);
	printf("\t\t\t\tUser Name: ");
	TextColor2(15);
	gets(user);
	TextColor2(3);	
	printf("\t\t\t\tPassword: ");
	TextColor2(15);
	gets(pass);
	    while(strcmp(user, userName) != 0 || strcmp(pass, passWord) != 0){
	        if(count >= 0)
			{
				TextColor2(13);
				printf("\n\t\tYour user name was wrong.\n\tPlease input again!\n");
				TextColor2(3);
				printf("\t\t\t\tUser Name: ");
				TextColor2(15);
				gets(user);
				TextColor2(3);
				printf("\t\t\t\tPassword: ");
				TextColor2(15);
				gets(pass);
		        count++;
		    }
	    }
    TextColor2(14);
	printf("\n\tWelcome [%s] \n", user);
}

void admin() {
	TextColor2(10);
	printf("\t\t ____________________________________\n\t\t|");
	TextColor2(12);
	printf("     Nhat Thi's Laptop Store        ");
	TextColor2(10);
	printf("|\n\t\t|                                    |\n\t\t|");
	TextColor2(6);
	printf("  1. Add Admin                      ");
	TextColor2(10);
	printf("|\n\t\t|                                    |\n\t\t|");
	TextColor2(6);
	printf("  2. Add Product                    ");
	TextColor2(10);
	printf("|\n\t\t|                                    |\n\t\t|");
	TextColor2(6);
	printf("  3. List of best-selling products  ");
	TextColor2(10);
	printf("|\n\t\t|____________________________________|\n");
}

void addAdmin() {
	char user[50], pass[50], chose;
	int i = 0;
	FILE* f = fopen("addAdmin.txt","a");
	TextColor2(3);
	printf("\t\t\tUser Name: ");
	TextColor2(15);
	gets(user);
	TextColor2(3);	
	printf("\t\t\tCreate a password: ");
	TextColor2(15);
	gets(pass);
	TextColor2(3);
	printf("\n\t\t\tConfirm your password: ");
	TextColor2(15);
	gets(pass);
	fprintf(f, "User Name: %s \n", user);
	fprintf(f, "Password %s", pass);
	fclose(f);
}

void sale() {
   TextColor2(15);
	printf("\t\t ____________________________________ \n\t\t|");
	TextColor2(12);
	printf("     Nhat Thi's Laptop Store        ");
	TextColor2(15);
	printf("|\n\t\t|                                    |\n\t\t|");
	TextColor2(5);
	printf("   Please choose a suitable number: ");
	TextColor2(15);
	printf("|\n\t\t|                                    |\n\t\t|");
	TextColor2(11);
	printf("      1. Best-seller in Week        ");
	TextColor2(15);
	printf("|\n\t\t|                                    |\n\t\t|");
	TextColor2(11);
	printf("      2. Best-seller in Month       ");
	TextColor2(15);
	printf("|\n\t\t|                                    |\n\t\t|");
	TextColor2(11);
	printf("      3. Sales in Month             ");
	TextColor2(15);
	printf("|\n\t\t|                                    |\n\t\t|");
	TextColor2(11);
	printf("      4. Exit                       ");
	TextColor2(15);
	printf("|\n\t\t|____________________________________|\n");
}

//void back() {			// I think it not necessary.
//	int choice;
//	char str[100];
//	char cont;
//	do {
//		homeScreen();
//	 	choice = getChoice1();
//	 	system("cls");
//		switch(choice)
//		{
//		case 1:
//			inputAdmin();
//			admin();
//			choice = getChoice1();
//			system("cls");
//			switch(choice) {
//				case 1:
//				//	addAdmin(char &name, &pass);
//					break;
//				case 2:
//				do {
//					sale();
//					choice = getChoice2();
//					system("cls");
//					switch(choice) {
//						case 1:
//							bestSellerInWeek();
//							break;
//						case 2:
//							bestSellerInMonth();
//							break;
//						case 3:
//							salesInMonth();
//							break;
//						case 4:
//							back();
//							break;
//					}
//					cont = getch();
//					system("cls");
//				} while(cont != 27);
//				break;
//				}
//		break;
//		case 3:
//			exitFirst();
//			exit(0);
//			break;
//		}
//		printf("\n\tPress any to continue. ESC to exit!");
//		cont = getch();
//	} while(cont != 27);
//}
