#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>

void fullscreen (void);
void gotoxy (int, int);
void color (int);
void show_list (int, int);
void first_screen (void);
void password (void);
void main_menu (void);
void view_product (void);
void add_product (void);
void delete_product (void);
void edit_product (void);
void close_menu (void);

char PASSWORD [10] = {"0000"}; // password
int product_size = 0; // initialize product_size 

FILE *fp, *ft; // list of global files that can be accessed from anywhere in program

struct order
{
	char ID [3];
	char date [9];
	char website [11];
	char product [17];
	char price [9];
	char guarantee [13];
	char delivery [9];
	char refund [9];
	char sales [10];
	char profit [10];
	char rate [8];
	char account [27];
}; 
struct order order;

main ()
{
	Sleep(100);
	fullscreen();
	Sleep(100);
	first_screen();
}

void fullscreen (void) // this function makes the program fullscreen
{
	keybd_event(VK_MENU,0x38,0,0);
	keybd_event(VK_RETURN,0x1c,0,0);
	keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
	keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
}

void gotoxy (int x, int y)
{
	COORD pos = {x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void color (int x) // this function colors the text
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, x);
}

void show_list (int k, int product_size) // this function draws rows and columns lines
{
	for (int x = 1; x < 160; x++) // loop for draw the row lines
	{
		gotoxy(x+8,5+k); color(8); printf("-");
	}
			
	for (int y = 5; y < product_size + 6; y++) // loop for draw the column lines
	{
		color(8);
		gotoxy(8,y+k); printf("|");
		gotoxy(13,y+k); printf("|");
		gotoxy(24,y+k); printf("|");
		gotoxy(37,y+k); printf("|");
		gotoxy(56,y+k); printf("|");
		gotoxy(67,y+k); printf("|");
		gotoxy(82,y+k); printf("|");
		gotoxy(93,y+k); printf("|");
		gotoxy(104,y+k); printf("|");
		gotoxy(116,y+k); printf("|");
		gotoxy(128,y+k); printf("|");
		gotoxy(138,y+k); printf("|");
		gotoxy(167,y+k); printf("|");
	}
	
	color(15);
	gotoxy(10,4+k); printf("ID"); // show column headers
	gotoxy(17,4+k); printf("Date");
	gotoxy(27,4+k); printf("Web Site");
	gotoxy(43,4+k); printf("Products");
	gotoxy(59,4+k); printf("Price");
	gotoxy(71,4+k); printf("Guaranty");
	gotoxy(84,4+k); printf("Delivery");
	gotoxy(96,4+k); printf("Refund");
	gotoxy(108,4+k); printf("Sales");
	gotoxy(119,4+k); printf("Profit");
	gotoxy(131,4+k); printf("1 $ ? ");
	gotoxy(147,4+k); printf("Mail Account");
}

void first_screen (void) // this function shows an animation and password entry screen
{	
	color(15);
	gotoxy(49,4); printf("*");
	gotoxy(47,5); printf("* * *");
	gotoxy(48,6); printf("* *");
	
	int z = 1;
	int counter = 1;
	int colors = 8; // text color
	
	for (int x = 49, y = 7; x > 0, y < 31; x--, y++)	//
	{
		gotoxy(x,y);									//
		
		Sleep(80);										//

		for (int t = 0; t < z; t++)						//
		{
			if (colors > 15)							//
				colors = 8;
			color(colors);								//		animation
			printf("^ ");
			colors++;									//		part
		}
														//
		if (counter % 6 == 0)
		{												//
			z -= 2;
			x += 2;										//
		}
														//
		counter ++;
		z++;											//
	}
	
	gotoxy(35,32); color(15); printf("M E R R Y   X M A S   2 0 1 7");
	gotoxy(46,35); color(8); printf("by HKG.");
	gotoxy(75,24); color(8); printf("Press ESC to exit..");
	gotoxy(75,18); color(7); printf("Welcome, ");
	color(159); printf(" Mr. Huseyin Eren Guler ");
	gotoxy(75,20); color(7); printf("Password: ");
	
	password(); // call function (this function retrieves the password from the user and checks the authenticity)
}

void password (void) // this function retrieves the password from the user and checks the authenticity
{
	char ch;
	char pass[10]; // declaration of array for comparison
	int x = 0;
	
	while (ch != 13) // meaning of 13 is "enter"
	{
		ch = getch();
		
		if (ch == 27) // meaning of 27 is "ESC"
		{
			system("cls"); close_menu(); // clean screen and call function, program ends
		}
		
		if (ch != 13 && ch != 8) // meaning of 8 is backspace
		{
			putch('*');
			pass[x] = ch;
			x++;
		}	
	}
	
	pass[x] = '\0'; // we reported that we were at the end of the array
	
	gotoxy(75,22);
	
	if (strcmp(pass, PASSWORD) == 0) // the accuracy of the entered password is checked (true --> return 0)
		printf("You Have Successfully Entered ");
	else
		printf("Invalid Password ");
	
	for (int x = 1; x < 4; x++)
	{
		Sleep(1000); printf(">");
	}
	
	Sleep(1000); system("cls"); // clean screen
	
	if (strcmp(pass, PASSWORD) == 0)
		main_menu(); // password is true, we successfully entered and call main_menu function
	else
		first_screen(); // password is false, call first_screen function, again
}

void main_menu (void)
{	
	gotoxy(3,1); color(4);
	for (int x = 0; x < 72; x++)
		printf("\xDB");
	color(15); printf("  M A I N   M E N U  "); color(4); // print title
	for (int x = 0; x < 73; x++)
		printf("\xDB");
	
	view_product(); // call view_product function (this function shows product list)
	
	color(7);
	gotoxy(19,product_size+9); printf("1) ADD PRODUCT");
	gotoxy(54,product_size+9); printf("2) EDIT PRODUCT");
	gotoxy(90,product_size+9); printf("3) DELETE PRODUCT");
	gotoxy(128,product_size+9); printf("ESC) CLOSE APPLICATION");
	
	switch (getch())
	{
		case '1':
			system("cls"); add_product(); // clean screen and call add_product function
			break;
		case '2':
			system("cls"); edit_product(); // clean screen and call edit_product function
			break;
		case '3':
			system("cls"); delete_product(); // clean screen and call delete_product function
			break;
		default:
			system("cls"); close_menu(); // clean screen and call close_menu function
			break;
	}
}

void view_product (void) // this function shows product list
{
	int y = 6; // column number
	product_size = 0;
	
	fp = fopen("Deneme1.txt","rb"); // txt file opens for reading in binary mode
	while (fread (&order, sizeof(order), 1, fp) == 1) // while loop to read text and print details
	{
		color(15);
		gotoxy(10,y); printf("%s", order.ID); // product details are printed sequentially
		gotoxy(15,y); printf("%s", order.date);
		gotoxy(26,y); printf("%s", order.website);
		gotoxy(39,y); printf("%s", order.product);
		gotoxy(58,y); printf("%s", order.price);
		gotoxy(69,y); printf("%s", order.guarantee);
		gotoxy(84,y); printf("%s", order.delivery);
		gotoxy(95,y); printf("%s", order.refund);
		gotoxy(106,y); printf("%s", order.sales);
		gotoxy(118,y); printf("%s", order.profit);
		gotoxy(130,y); printf("%s", order.rate);
		gotoxy(140,y); printf("%s", order.account);
		
		product_size++; // increment product_size
		y++; // increment column value
	}
	
	fclose(fp); // close file
	show_list(0,product_size); // call function (this function draws rows and columns lines)
	
	for (int y = 0; y < product_size; y++) // loop to print sequence numbers
	{
		gotoxy(4,y+6); color(12); printf("%d)", y+1 );
	}
}

void add_product (void) // this function adds product
{
	gotoxy(3,1); color(4);
	for (int x = 0; x < 70; x++)
		printf("\xDB");
	color(15); printf("  A D D   P R O D U C T  "); color(4); // print title
	for (int x = 0; x < 71; x++)
		printf("\xDB");
	
	show_list(0,3); // call function (this function draws rows and columns lines)
	
	gotoxy(4,6); color(12); printf("Ex."); // sample product details are printed
	gotoxy(4,8); printf("Add");
	gotoxy(10,6); color(15); printf("15");
	gotoxy(15,6); printf("11.11.16");
	gotoxy(26,6); printf("Aliexpress");
	gotoxy(39,6); printf("Xiaomi Mi Band 2");
	gotoxy(58,6); printf("26.00 $ ");
	gotoxy(69,6); printf("10.01.17 #60");
	gotoxy(84,6); printf("04.12.16");
	gotoxy(95,6); printf("26.00 $ ");
	gotoxy(106,6); printf("125.00 TL");
	gotoxy(118,6); printf("38.68 TL ");
	gotoxy(130,6); printf("3.32 TL");
	gotoxy(140,6); printf("huseyinkuzey1997@gmail.com");

	gotoxy(10,8); gets(order.ID); // product details gets from user
	gotoxy(15,8); gets(order.date);
	gotoxy(26,8); gets(order.website);
	gotoxy(39,8); gets(order.product);
	gotoxy(58,8); gets(order.price);
	gotoxy(69,8); gets(order.guarantee);
	gotoxy(84,8); gets(order.delivery);
	gotoxy(95,8); gets(order.refund);
	gotoxy(106,8); gets(order.sales);
	gotoxy(118,8); gets(order.profit);
	gotoxy(130,8); gets(order.rate);
	gotoxy(140,8); gets(order.account);
	
	fp = fopen("Deneme1.txt","ab+"); // txt file opens for both reading and appending in binary mode
	fseek(fp, 0, SEEK_END); // the new file location is the end of the file
	fwrite(&order, sizeof(order), 1, fp); // write to txt
	fclose(fp); // close file
	
	gotoxy(14,11); color(7); printf("Successfully Completed ");
	for (int x = 0; x < 3; x++)
	{
		Sleep(1000); printf(">");
	}
	
	Sleep(1000); system("cls"); main_menu(); // clean screen and call main_menu function
}

void delete_product (void) // this function deletes product
{
	gotoxy(3,1); color(4);
	for (int x = 0; x < 67; x++)
		printf("\xDB");
	color(15); printf("  D E L E T E   P R O D U C T  "); color(4); // print title
	for (int x = 0; x < 68; x++)
		printf("\xDB");
		
	view_product(); // shows product list
	
	int control = 0;
	char product_ID [3]; // declaration of array for comparison
	
	color(7); gotoxy(14,product_size+9); 
	printf("Enter the product ID to delete: "); scanf("%s", product_ID); // ID is retrieved from user
	
	fp = fopen("Deneme1.txt","rb+"); // txt file opens for both reading and writing in binary mode
	rewind(fp);
	
	while (fread (&order, sizeof(order), 1, fp) == 1)
	{
		if (strcmp(order.ID, product_ID) == 0) // if the ID we entered is contained in the file --> return 0 (true)
		{
			show_list(product_size+7,1);
			color(15);
			gotoxy(10,product_size+13); printf("%s", order.ID); // product details are printed sequentially
			gotoxy(15,product_size+13); printf("%s", order.date);
			gotoxy(26,product_size+13); printf("%s", order.website);
			gotoxy(39,product_size+13); printf("%s", order.product);
			gotoxy(58,product_size+13); printf("%s", order.price);
			gotoxy(69,product_size+13); printf("%s", order.guarantee);
			gotoxy(84,product_size+13); printf("%s", order.delivery);
			gotoxy(95,product_size+13); printf("%s", order.refund);
			gotoxy(106,product_size+13); printf("%s", order.sales);
			gotoxy(118,product_size+13); printf("%s", order.profit);
			gotoxy(130,product_size+13); printf("%s", order.rate);
			gotoxy(140,product_size+13); printf("%s", order.account);
		
			control = 1; // this means is, if condition is executed
		}
	}
	
	if (control != 1) // if the ID we entered is not contained in the file 
	{
		printf("\n              Product not found ");
		for (int x = 0; x < 3; x++)
		{
			Sleep(1000); printf(">");
		}
		
		Sleep(1000); system("cls"); main_menu(); // clean screen and call main_menu function
	}
	
	if (control == 1) // if the ID we entered is contained in the file 
	{
		gotoxy(14,product_size+16); color(7);
		printf("Do you want to delete it ? (Y/N) ");
		
		char ch = getch();
		if (ch == 'y' || ch == 'Y') // if the user approves --> true
		{
			ft = fopen("delete_operation.txt","wb+"); // we are creating a new file and open for both reading and writing in binary mode
			rewind(fp);
			
			while (fread (&order, sizeof(order), 1, fp) == 1)	// 
			{
				if (strcmp(order.ID, product_ID) != 0)			// except for the part to be erased,
				{
					fseek(ft, 0, SEEK_CUR);						//
					fwrite(&order, sizeof(order), 1, ft);
				}												// we write all the rest to the new file
			}
	
			fclose(ft); // close file
			fclose(fp); // close file
			remove("Deneme1.txt"); // delete old file
			rename("delete_operation.txt","Deneme1.txt"); // in the name of the new file, we put the name of the old file
			fflush(stdin); // it is to flush the input buffer
			
			gotoxy(14,product_size+18);
			printf("The product is successfully deleted ");
			
			for (int x = 0; x < 3; x++)
			{
				Sleep(1000); printf(">");
			}
		}
		
		Sleep(1000); system("cls"); main_menu(); // clean screen and call main_menu function
	}
}

void edit_product (void) // this function edites product
{
	gotoxy(3,1); color(4);
	for (int x = 0; x < 69; x++)
		printf("\xDB");
	color(15); printf("  E D I T   P R O D U C T  "); color(4); // print title
	for (int x = 0; x < 70; x++)
		printf("\xDB");
		
	view_product(); // shows product list
	
	int control = 0;
	char product_ID [3]; // declaration of array for comparison
	
	color(7); gotoxy(14,product_size+9); 
	printf("Enter the product ID to edit: "); scanf("%s", product_ID); // ID is retrieved from user
	
	fp = fopen("Deneme1.txt","rb+"); // txt file opens for both reading and writing in binary mode
	rewind(fp);
	
	while (fread (&order, sizeof(order), 1, fp) == 1)
	{
		if (strcmp(order.ID, product_ID) == 0) // if the ID we entered is contained in the file --> return 0 (true)
		{
			show_list(product_size+7,2); // call function (this function draws rows and columns lines)
			color(15);
			gotoxy(10,product_size+13); printf("%s", order.ID); // product details are printed sequentially
			gotoxy(15,product_size+13); printf("%s", order.date);
			gotoxy(26,product_size+13); printf("%s", order.website);
			gotoxy(39,product_size+13); printf("%s", order.product);
			gotoxy(58,product_size+13); printf("%s", order.price);
			gotoxy(69,product_size+13); printf("%s", order.guarantee);
			gotoxy(84,product_size+13); printf("%s", order.delivery);
			gotoxy(95,product_size+13); printf("%s", order.refund);
			gotoxy(106,product_size+13); printf("%s", order.sales);
			gotoxy(118,product_size+13); printf("%s", order.profit);
			gotoxy(130,product_size+13); printf("%s", order.rate);
			gotoxy(140,product_size+13); printf("%s", order.account);
				
			gotoxy(10,product_size+14); gets(order.ID); // new product details gets from user
			gotoxy(10,product_size+14); gets(order.ID);
			gotoxy(15,product_size+14); gets(order.date);
			gotoxy(26,product_size+14); gets(order.website);
			gotoxy(39,product_size+14); gets(order.product);
			gotoxy(58,product_size+14); gets(order.price);
			gotoxy(69,product_size+14); gets(order.guarantee);
			gotoxy(84,product_size+14); gets(order.delivery);
			gotoxy(95,product_size+14); gets(order.refund);
			gotoxy(106,product_size+14); gets(order.sales);
			gotoxy(118,product_size+14); gets(order.profit);
			gotoxy(130,product_size+14); gets(order.rate);
			gotoxy(140,product_size+14); gets(order.account);
			
			fseek(fp, ftell(fp)-sizeof(order), 0);
			fwrite(&order, sizeof(order), 1, fp); // write to txt
			fclose(fp); // close file
	
			control = 1; // this means is, if condition is executed
		}
	}
	
	gotoxy(14,product_size+11); color(7);
	if (control != 1)
		printf("Product not found ");
	else if (control == 1)
		printf("\n\n\n\n\n\n\t      The product is successfully edited ");	
	
	for (int x = 0; x < 3; x++)
	{
		Sleep(1000); printf(">");
	}
	
	fflush(stdin); // it is to flush the input buffer
	
	Sleep(1000); system("cls"); main_menu();	// clean screen and call main_menu function		
}

void close_menu (void) // this function shows the closing animation
{	
	color(15);
	Sleep(50); gotoxy(32,7);  printf("               _/_/_/_/_/_/          _/_/_/_/_/_/          _/_/_/_/_/_/          _/_/_/_/_/       ");
	Sleep(50); gotoxy(32,8);  printf("            _/            _/      _/            _/      _/            _/      _/          _/ 	    ");
	Sleep(50); gotoxy(32,9);  printf("           _/                    _/            _/      _/            _/      _/            _/     ");
	Sleep(50); gotoxy(32,10); printf("          _/                    _/            _/      _/            _/      _/              _/    ");
	Sleep(50); gotoxy(32,11); printf("         _/                    _/            _/      _/            _/      _/               _/    ");
	Sleep(50); gotoxy(32,12); printf("        _/                    _/            _/      _/            _/      _/                _/    ");
	Sleep(50); gotoxy(32,13); printf("       _/    _/_/_/_/        _/            _/      _/            _/      _/                _/     ");
	Sleep(50); gotoxy(32,14); printf("      _/            _/      _/            _/      _/            _/      _/                _/      ");
	Sleep(50); gotoxy(32,15); printf("     _/            _/      _/            _/      _/            _/      _/               _/        ");
	Sleep(50); gotoxy(32,16); printf("    _/            _/      _/            _/      _/            _/      _/              _/          ");
	Sleep(50); gotoxy(32,17); printf("   _/            _/      _/            _/      _/            _/      _/             _/            ");
	Sleep(50); gotoxy(32,18); printf("    _/_/_/_/_/_/          _/_/_/_/_/_/          _/_/_/_/_/_/          _/_/_/_/_/_/_/              ");
	
	Sleep(50); gotoxy(32,21); printf("                                     _/_/_/_/_/         _/      _/           _/_/_/_/_/_/               ");
	Sleep(50); gotoxy(32,22); printf("                                  _/          _/        _/     _/         _/                            ");
	Sleep(50); gotoxy(32,23); printf("                                 _/           _/        _/    _/         _/                             ");
	Sleep(50); gotoxy(32,24); printf("                                _/            _/        _/   _/         _/                              ");
	Sleep(50); gotoxy(32,25); printf("                               _/            _/         _/  _/         _/                               ");
	Sleep(50); gotoxy(32,26); printf("                              _/_/_/_/_/_/_/            _/ _/         _/_/_/_/_/_/                      ");
	Sleep(50); gotoxy(32,27); printf("                             _/            _/            _/          _/                                 ");
	Sleep(50); gotoxy(32,28); printf("                            _/             _/           _/          _/                                  ");
	Sleep(50); gotoxy(32,29); printf("                           _/              _/          _/          _/                                   ");
	Sleep(50); gotoxy(32,30); printf("                          _/              _/          _/          _/                                    ");
	Sleep(50); gotoxy(32,31); printf("                         _/             _/           _/          _/                     _/_/  _/_/  _/_/");
	Sleep(50); gotoxy(32,32); printf("                          _/_/_/_/_/_/_/            _/            _/_/_/_/_/_/_/       _/_/  _/_/  _/_/ ");	
	
	Sleep(1000); exit(0); // program ends
}
