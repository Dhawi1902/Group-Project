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
void initialize (ifstream inData, IceCream list[], int listSize);

int main()
{	
	ifstream infile;
	salesPersonRecord salesMan[NO_OF_SALES_PERSON];
	
	infile.open("SalesPerson.txt");
	
	if (infile.fail())
	{
		cout << "Cannot open the input file."
			 << endl;
		return 1;
	}
	
	initialize (infile, salesMan, NO_OF_SALES_PERSON);
	
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

