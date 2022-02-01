#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

int main()
{
	string filename = "prices.dat";
	string line;
	
	ifstream inFile;
	
	inFile.open(filename.c_str());
	
	if (inFile.fail()){
		cout << "\nThe file was not successfully opened"
			 << "\n Please check that the file currently exists."
			 << endl;
		exit(1);
	}
	
	while(getline(inFile,line))
		cout << line << endl;
	
	inFile.close();
	return 0;
}
