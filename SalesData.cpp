#include <iostream>
#include <fstream>


using namespace std;

int main()
{
	int week;
	ofstream outfile;
	
	outfile.open("SalesData.txt");
	
	if(!outfile){
		cout << "Cannot open the input file."
			 << endl;
		return 1;
	}

	do{
		cout << "Enter week (1-4): ";
		cin >> week;
		cout << endl;
	
		while (week <= 0 || week >= 5){
			cout << "Invalid input!" << endl;
			cout << "Enter week (1-4): ";
			cin >> week;
			cout << endl;	
		}
	
		outfile << week << " ";
	
}
	outfile.close();
return 0;
}

