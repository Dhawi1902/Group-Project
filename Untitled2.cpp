#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

int main()
{
	string filename = "prices.dat";
	string descrip;
	double price;
	
	ifstream inFile;
	
	inFile.open(filename.c_str());
	
	if (inFile.fail()){
		cout << "\nThe file was not successfully opened"
			 << "\n Please check that the file currently exists."
			 << endl;
		exit(1);
	}
	
	inFile >> descrip >> price;
	while (inFile.good()){
		cout << descrip << ' ' << price << endl;
		inFile >> descrip >> price;
	}
	
	inFile.close();
	return 0;
}
