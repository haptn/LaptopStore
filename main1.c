
/* Project train C - A program to Manage Nhat Thi's Laptop Shop
   Written by Pham Thi Ngoc Ha & Vu Lam Bao Van */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include "the1stInterface1.c"
#include "theAdminInterface1.c"
#include "theCustomerInterface1.c"

int main()
{
	int choice, lapchoice, ordichoice, bizchoice, gamechoice, goFast;
	int check = 0;
	int runAdminInterface;
	
//	system("color E");  // Text color: Light yellow ; Background color: Black.
//	do
//	{
//		system("cls");
		// First Interface
		homeScreen();
		choice = getChoiceFirstInterface();		
		switch (choice)
		{
			case 1: // Admin Interface
				runAdminInterface = mainVan();
				break;
				
			case 2: //Customer Interface
				printProductMenu();
				goFast = chooseForFast();
				if (goFast == 0)
				{
					lapchoice = getLaptopType();
					switch (lapchoice)
					{
						case 1: // Ordinary Laptop Interface
							printOrdinaryLaptopMenu();
							ordichoice = getOrdinaryLaptop();
							takeCustomersRequirements();
							break;
							
						case 2: // Business Laptop Interface
							printBusinessLaptopMenu();
							bizchoice = getBusinessLaptop();
							takeCustomersRequirements();
							break;
							
						case 3: // Gaming Laptop Interface
							printGamingLaptopMenu();
							gamechoice = getGamingLaptop();
							takeCustomersRequirements();
							break;
					}
					exitForCustomer();		// There are some bugs here. You have to 'Enter' few times to move to the Exit Interfaces.
				}
				else
				{
					searchProduct();
				}
				break;
				
			case 3: // Exit
				exitFirst();
				break;
		}
		getch();
//	} while (choice != 1 && choice != 3 && check == 0);
	
	return 0;
}
