#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

const int NO_OF_SALES_PERSON = 6;
const int NO_OF_WEEK = 4;
const int ICE_CREAM_TYPE = 6;


struct salesPersonRec
{
	string ID;
	double saleByQuarter[4];
	
	double totalsale;
};

void initialize(ifstream& indata, salesPersonRec list[], int listSize);
void getData (ifstream& infile, salesPersonRec list[], int listSize);
void saleByQuarter (salesPersonRec list[], int listSize, double totalByQuarter[]);
void totalSaleByPerson (salesPersonRec list[], int listSize);
void printReport (ofstream& outData, salesPersonRec list[], int listSize, double saleByQuarter[]);
void maxSaleByPerson (ofstream& outData, salesPersonRec list[], int listSize);
void maxSaleByQuarter (ofstream& outData, double saleByQuarter[]);


int main()
{
	ifstream infile;
	ofstream outfile;
	
	string inputFile;
	string outputFile;
	
	double totalSaleByQuarter[4];
	
	salesPersonRec salesPersonList[NO_OF_SALES_PERSON];
	
	cout << "Enter the salesPerson ID file name: ";
	cin >> inputFile;
	cout << endl;
	
	infile.open(inputFile.c_str());
	if (!infile)
	{
		cout << "Cannot open the input file."
			 << endl;
		return 1;
	}
	
	initialize (infile, salesPersonList, NO_OF_SALES_PERSON);
	
	infile.close();
	infile.clear();
	
	cout << "Enter the sales data file name: ";
	cin >> inputFile;
	cout << endl;

	infile.open(inputFile.c_str());
	
	if (!infile)
	{
		cout << "Cannot open the input file."
			 << endl;
		return 1;
	}

	cout << "Enter the output file name: ";
	cin >> outputFile;
	cout << endl;
	
	outfile.open(outputFile.c_str());
	outfile << fixed << showpoint
			<< setprecision (2);
	
	getData (infile, salesPersonList, NO_OF_SALES_PERSON);
	saleByQuarter (salesPersonList, NO_OF_SALES_PERSON, totalSaleByQuarter);
	totalSaleByPerson (salesPersonList, NO_OF_SALES_PERSON);
	printReport (outfile, salesPersonList, NO_OF_SALES_PERSON, totalSaleByQuarter);
	maxSaleByPerson (outfile, salesPersonList, NO_OF_SALES_PERSON);
	maxSaleByQuarter (outfile, totalSaleByQuarter);
	
	infile.close();
	outfile.close();
	
return 0;
}



void initialize(ifstream& indata, salesPersonRec list[], int listSize)
{
	int index;
	int quarter;
	
	for (index = 0; index < listSize; index++)
	{
		indata >> list[index].ID;
		
		for (quarter = 0; quarter < 4; quarter++)
			list[index].saleByQuarter[quarter] = 0.0;
		
		list[index].totalsale = 0.0;
	}
}


void getData (ifstream& infile, salesPersonRec list[], int listSize)
{
	int index, salesManIndex;
	int quarter;
	string sID;
	int month;
	double amount;
	
	infile >> sID;
	
	while (infile){
		infile >> month >> amount;
		
		for (index = 0; index < listSize; index++)
			if (sID == list[index].ID)
				salesManIndex = index;
	
	
		if ( 1 <= month && month <= 3)
			quarter = 0;
		else if ( 4 <= month && month <= 6)
			quarter = 1;
		else if ( 7 <= month && month <= 9)
			quarter = 2;
		else
			quarter = 3;
			
		if (salesManIndex < listSize)
			list[index].saleByQuarter[quarter] += amount;
		else
			cout << "Invalid salesperson's ID." << endl;
			
		infile >> sID;
	
	}
}


void saleByQuarter (salesPersonRec list[], int listSize, double totalByQuarter[])
{
	int quarter;
	int index;
	
	for(quarter = 0; quarter < 4; quarter++)
		totalByQuarter[quarter] = 0.0;
	
	for(quarter = 0; quarter < 4; quarter++)
		for (index = 0; index < listSize; index++)
			totalByQuarter[quarter] += list[index].saleByQuarter[quarter];
	
}

void totalSaleByPerson (salesPersonRec list[], int listSize)
{
	int index;
	int quarter;
	
	for (index = 0; index < listSize; index++)
		for (quarter = 0; quarter < 4; quarter ++)
			list[index].totalsale += list[index].saleByQuarter[quarter];

}


void printReport (ofstream& outfile, salesPersonRec list[], int listSize, double saleByQuarter[])
{
	int index;
	int quarter;
	
	outfile << "-------------  Annual Sales Report --------------" << endl;
	outfile << "	ID		QT1		QT2		QT3		QT4		Total" << endl;
	outfile << "_________________________________________________" << endl;
	
	for (index = 0; index < listSize; index++)
	{
		outfile << list[index].ID << "\t";
		
		for (quarter = 0; quarter < 4; quarter++)
			outfile << setw(10) << list[index].saleByQuarter[quarter];
	
		outfile << setw(10) << list[index].totalsale << endl;

	}
	
	outfile << "Total	";
	
	for (quarter = 0; quarter < 4; quarter++)
		outfile << setw(10) << saleByQuarter[quarter];
		
	outfile << endl << endl;

}

void maxSaleByPerson (ofstream& outData, salesPersonRec list[], int listSize)
{
	int index;
	int maxIndex = 0;
	
	for (index = 0; index < 4; index++){
		if (list[maxIndex].totalsale < list[index].totalsale)
			maxIndex = index;
	}
	
	outData << "Max Sale by Salesperson: Id = "
			<< list[maxIndex].ID
			<< ", Amount = $" << list[maxIndex].totalsale
			<< endl;
}

void maxSaleByQuarter (ofstream& outData, double saleByQuarter[])
{
	int quarter;
	int maxIndex = 0;
	
	for (quarter = 0; quarter < 4; quarter++){
		if (saleByQuarter[maxIndex] < saleByQuarter[quarter])
			maxIndex = quarter;
	}
	
	outData << "Max Sale by Quarter: Quarter = "
			<< maxIndex + 1
			<< ", Amount = $" << saleByQuarter[maxIndex]
			<< endl;
}
