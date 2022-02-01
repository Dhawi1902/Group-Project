#include<iostream>
#include<fstream>
#include<cstdlib> //neededforexit()
#include<string> //neededforthestringclass
#include<iomanip> //neededforformatting
using namespace std;

int main()
{
	string filename ="prices.dat"; //put the file name up front
	ofstream outFile;
	outFile.open(filename.c_str());
	if(outFile.fail())
	{
		cout<< "The file was not successfully opened" << endl;
		exit(1);
	}
	//settheoutputfilestreamformats
	outFile << setiosflags(ios::fixed)
	<<setiosflags(ios::showpoint)
	<<setprecision(2);
	//senddatatothefile
	outFile << "Mats " << 39.95 << endl
	<< "Bulbs " << 3.22 << endl
	<< "Fuses " << 1.08 <<endl;
	
	outFile.close();
	cout<<"The file "<<filename
	<<" has been successfully written."<<endl;
	
return 0;
}
