#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;
const double CHOCOLATE = 1.25;
const double STRAWBERRY = 1.20;
const double VANILLA = 1.15;
const int NO_OF_ICES = 3;
const int N = 4;

struct IceCream
{
	string type;
	double price;
	double weeklyCollection[4];
};

struct salesPersonRecord
{
	string Id;
	string name;
	double weeklyCollection[4];	
};

void display_menu();
void display_avaiable_ices(IceCream []);
void order();
void sales();
void back_to_menue();

int main()
{
	IceCream ice[4]=	{{"Cup",	3.5},
						{"Cone",	2.8},
						{"Waffle",	5.5}};
						
	salesPersonRecord salesPersonList[6]=	{{"12345", "Aiman", 0.0},
											 {"12346", "Alif", 0.0},
											 {"12347", "Haziq", 0.0},
											 {"12348", "Azim", 0.0},
											 {"12349", "Aizat", 0.0}};
							  
	int choice;

	do{
		display_menu();
		cout << endl << "Please enter a number of your choice from the menu: ";
		cin >> choice;

		switch (choice){
			case 0: break;
		
			case 1:	system("cls");
					display_avaiable_ices(ice);
					back_to_menue();
					break;
				
			case 2:	system("cls");
					order();
					back_to_menue();
					break;
					
			case 3:	system("cls");
					sales();
					back_to_menue();
					break;
			
			default:
			cout << endl << "Error! You have input an incorrect value." << endl << endl;
			cout << "Please enter your choice from the numbers 1-4: ";
			cin >> choice;
		}
		
	}while (choice != 0);

	return 0;
}

void display_menu()
{
	cout << "+----------------------------------+" << endl;
	cout << "|                                  |" << endl;
	cout << "|         Ice Cream System         |" << endl;
	cout << "|     (Created By Group Dhawi)     |" << endl;
	cout << "|                                  |" << endl;
	cout << "+----------------------------------+" << endl;
	cout << "|                                  |" << endl;
	cout << "|   (1) View available ice cream   |" << endl;
	cout << "|   (2) Buy ice cream              |" << endl;
	cout << "|   (3) Sales                      |" << endl;
	cout << "|   (0) Exit                       |" << endl;
	cout << "+----------------------------------+" << endl;
	
}
void display_avaiable_ices(IceCream ice[])
{
	cout << "\nHere are all the available ice cream:\n" << endl;

	cout << "+-----------------------------------------------------------------------------------------------------+" << endl;
	cout << "| No.  |Name           |Price                                                                         |" << endl;
	cout << "+-----------------------------------------------------------------------------------------------------+" << endl;

	for(int i = 0; i < NO_OF_ICES; i++)
	{
		cout << "|  " << i+1 << "   " << left << setw(12)<< ice[i].type << " "; 
		cout << " " << " " << " ";
		cout << " " << setw(78) << ice[i].price << "|" << endl;
		if(i < 3)
		{
			cout << "|" << right << setw(102) << "|"<< endl;
		}
	}
	cout << "+-----------------------------------------------------------------------------------------------------+" << endl;
}
void order()
{
char choice;
int iceCreamScoops;
double icescreamscoopsTotal;

int cream;
char flavor;
string flavorName;
int scoops;
double Cost;
double creamCost = 0.10;
double creamTotal;

int hot;
double hotCost = 0.20;
double hotTotal;

int sprinkles;
double sprinklesCost = 0.15;
double sprinklesTotal;

    
cout << fixed << showpoint << setprecision(2);
cout << "Welcome to our Ice Cream Shop!" << endl;
cout << "Would you like some Vanilla, Strawberry, or Chocolate ice cream? \n";
cout << "Vanilla - RM1.15" << endl;
cout << "Strawberry - RM1.20" << endl;
cout << "Chocolate - RM1.25" << endl;
cout << "What's your choice? ";
cin >> flavor;

if(flavor == 'C' || flavor == 'c')
{
flavorName = "Chocolate";
Cost = CHOCOLATE;
}

else if (flavor == 'S' || flavor == 's')
{
flavorName = "StrawBerry";
Cost = STRAWBERRY;
}

else if (flavor == 'V' || flavor == 'v')
{
flavorName = "Vanilla";
Cost = VANILLA;
}
cout << "How many scoops of ice cream do you want? ";
cin >> iceCreamScoops;

cout << "Would you like some whipped cream? RM0.10 per scoop (Y or N): ";
cin >> choice;
if(choice == 'Y' || choice == 'y')
{
creamTotal = iceCreamScoops * creamCost;
cout << "Total for Whipped Cream: RM" << creamTotal << endl;
}
else
creamTotal = 0.0;

cout << "Would you like some Hot Chocolate? RM0.20 per scoop (Y or N): ";
cin >> choice;
if(choice == 'Y' || choice == 'y')
{
hotTotal = iceCreamScoops * hotCost;
cout << "Total for Hot Chocolate? RM" << hotTotal << endl;
}
else
hotTotal = 0.0;

cout << "Would you like some Sprinkles? RM0.15 per scoop (Y or N): ";
cin >> choice;
if(choice == 'Y' || choice == 'y')
{
sprinklesTotal = iceCreamScoops * sprinklesCost;
cout << "Total for Sprinkles? RM" << sprinklesTotal << endl;
}
else
sprinklesTotal = 0.0;

icescreamscoopsTotal = creamTotal + hotTotal + sprinklesTotal + (iceCreamScoops*Cost);
cout << "Total for " << flavorName << " Ice Cream: RM" << icescreamscoopsTotal << ". Thank you very much for shopping in our shop." << endl;

}
void sales()
{
	string staff[N] = { "Ali","Siti","Abu","Muiz"};
	int work[N];
	int i = 0;
	char ch;
	do
	{
		cout << "Please, enter daiy collection of ice cream sold by " << staff[i] << ":RM ";
		cin >> work[i];
		if (i == N-1)
		{
			int n = work[0];
			int max_num = 0;
			for (int j = 1; j<N; j++)
			{
				if (work[j] > n)
				{
					n = work[j];
					max_num = j;
				}
			}
			cout << "The highest collection of sold ice cream is RM " 
				 << n << " and it was sold by " << staff[max_num];
			n = work[0];
			int min_num = 0;
			for (int j = 1; j != N; j++)
			{
				if (work[j] < n)
				{
					n = work[j];
					min_num = j;
				}
			}
			cout << "\nThe least collection of sold ice cream is RM " 
				 << n << " and it was sold by " << staff[min_num];
			char c;
			do
			{
				cout << "\nDo you want to search the collection of sold ice cream by the staff - y/n(Yes or No):";
				cin >> c;
				string name;
				bool find = false;
				if (c == 'y'||c=='Y')
				{
					cout << "Please,enter staff name: ";
					cin >> name;
					int count;
					for (int j = 0; j < 5; j++)
					{
						if (staff[j] == name)
						{
							count = work[j];
							find = true;
						}
					}
					if (!find)cout << name << " does not exist!";
					else
					{
						cout << name << " collection is RM " << count;
					}
				}
			} while (c != 'n'&&c!='N');
		}	
		i++;
	} while (i < N);
}
void back_to_menue()
{
	char back_input;
	cout <<"\n\nPlease enter 'B' to go back to the menu: ";
	cin >> back_input;

	while(back_input != 'B')
	{
		cout << endl << "Error! You have input an incorrect value." << endl << endl;
		cout << "Please enter 'B' to go back: ";
		cin >> back_input;
	}

		system("cls");
}
