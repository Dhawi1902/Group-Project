#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

const int NO_OF_SALES_PERSON = 6;
const int NO_OF_WEEK = 4;
const int NO_ICE_CREAM_TYPE = 6;


struct salesPersonRecord
{
	string Id;
	double weeklyCollection[4];	
};

struct IceCream
{
	string type;
	double price;
	double weeklyCollection[4];
};

void initialize (ifstream& inData, salesPersonRecord salesMan[], int listSize);


int main()
{
	
	ofstream outfile;
	ifstream infile;
	
	salesPersonRecord salesMan[NO_OF_SALES_PERSON];
	
	IceCream list[NO_ICE_CREAM_TYPE] = {{"single cone", 1.00},
										{"double cone", 2.00},
										{"small cup", 1.50},
										{"large cup", 2.50},
										{"banana split", 4.00},
										{"waffle", 3.00}};
	
	int index;
	int week;
	int listSize = 6;
	
	infile.open("SalesPerson.txt");
	
	if (infile.fail())
	{
		cout << "Cannot open the input file."
			 << endl;
		return 1;
	}
	
	initialize (infile, salesMan, NO_OF_SALES_PERSON);
	
	infile.clear();
	infile.close();
	
	
	outfile.open("receipt.txt");
	
	outfile << "\t\t------------------  weekly Sales Report -------------------" << endl << endl;
	outfile << "ID			Week 1		Week 2		Week 3		Week 4		Total" << endl;
	outfile << "______________________________________________________________________________________________" << endl;
	
	for (index = 0; index < listSize; index++){
		outfile << left << setw(20) << salesMan[index].Id << "\t";
		
		for (week = 0; week < 4; week++){
			outfile << fixed << showpoint << setprecision(2);
			outfile << salesMan[index].weeklyCollection[week] << "\t\t";	
		}
		
		outfile << endl;
	}	
	
	outfile << endl << endl ;
	outfile << "Type			Week 1		Week 2		Week 3		Week 4		Total" << endl;
	outfile << "______________________________________________________________________________________________" << endl;
	
	for (index = 0; index < listSize; index++){
		outfile << left << setw(20) << list[index].type << "\t";
		
		for (week = 0; week < 4; week++){
			outfile << fixed << showpoint << setprecision(2);
			outfile << list[index].weeklyCollection[week] << "\t\t";	
		}
		
		outfile << endl;
		
	}	

return 0;
}

void initialize (ifstream& inData, salesPersonRecord salesMan[], int listSize)
{
	int quarter;
	for (int index = 0; index < listSize; index++)
	{
		inData >> salesMan[index].Id;
		
		for (quarter = 0; quarter < 4; quarter++)
			salesMan[index].weeklyCollection[quarter] = 0.0;
		
	}
	
	return ;
}

