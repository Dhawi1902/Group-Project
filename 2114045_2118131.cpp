#include <iostream>
#include <iomanip>

using namespace std;

const int NUMBER_OF_STUDENT = 5;
const int NUMBER_OF_QUIZ = 5;

void Insert_Data(string[] , int [][NUMBER_OF_QUIZ]);
void average_marks(int [][NUMBER_OF_QUIZ], int , int , double [], double []);
void display(string[] , int [][NUMBER_OF_QUIZ], double[], double[]);
void display(string[] , int [][NUMBER_OF_QUIZ], double[]);
void highest_marks(double[5] , int, string[]);
void highest_marks(double[5] , int);
void lowest_marks(double[5] , int, string[]);
void lowest_marks(double[5] , int);
void sorting (double [], string[], int[][5]);
 
int main()
{
	string studentName[NUMBER_OF_STUDENT];
	int mark[NUMBER_OF_STUDENT][NUMBER_OF_QUIZ];
	int choice;
	double averageScore [5],averageQuiz [5];
	cout << "Insert data for 5 students: " << endl;
	Insert_Data(studentName, mark);
	
	system("cls");
	
	cout << "\n1. display average mark"
		 << "\n2. display student with highest average marks"
		 << "\n3. display quiz with highest average marks"
		 << "\n4. display student lowest average marks"
		 << "\n5. display quiz with lowest average marks"
		 << "\n6. display student list which started with the lowest average marks to the highest."
		 << "\n0. exit";
	
	average_marks( mark, NUMBER_OF_STUDENT, NUMBER_OF_QUIZ, averageScore, averageQuiz);
	
	do{
		cout << "\n\nEnter your choice: ";
		cin >> choice;
		switch (choice){
			case 0:	break;
			
			case 1: display (studentName, mark, averageScore, averageQuiz);
					break;
					
			case 2: cout << "student with highest average mark: " << endl;
					highest_marks(averageScore, NUMBER_OF_STUDENT, studentName);
					break;
					
			case 3:	cout << "quiz with highest average mark: " << endl;
					highest_marks(averageQuiz, NUMBER_OF_STUDENT);
					break;
					
			case 4: cout << "student with lowest average mark: " << endl;
					lowest_marks(averageScore, NUMBER_OF_STUDENT, studentName);
					break;
					
			case 5:	cout << "quiz with lowest average mark: " << endl;
					lowest_marks(averageQuiz, NUMBER_OF_STUDENT);
					break;
					
			case 6:	sorting (averageScore, studentName, mark);
					display (studentName, mark, averageScore);
					break;
			
			default: cout 	<< "Invalid!"
							<< "\nEnter your choice: ";
			cin >> choice;
		}
	}while(choice!=0);
	
	system ("pause");
return 0;
}

void Insert_Data(string studentName[NUMBER_OF_STUDENT] , int mark[][5])
{
	for (int i=0; i < 5; i++){
		cout << endl << "Student " << i+1 << endl << "name: ";
		cin >> studentName[i];
		for (int j=0 ; j < 5; j++){
			cout << "quiz " << j+1 << ": " ;
			cin >> mark[i][j];
			
			while( mark[i][j] > 10 || mark[i][j] < 0){
			cout << "Invalid mark!" << endl;
			cout << "quiz " << j+1 << ": " ;
			cin >> mark[i][j];
			}
		}
	}
	
	return ;
}

void average_marks(int mark[5][5], int x, int y, double averageScore[5], double averageQuiz[5])
{
	int totalStudentMark ;
	int totalQuizMark ; 
	
	for(int i=0; i < x ; i++){
		
		totalStudentMark = 0;
		totalQuizMark = 0;
		
		for(int j=0; j<y ; j++){
			
			totalStudentMark += mark[i][j];
			totalQuizMark += mark[j][i];
			
		}
		
			averageScore[i] = totalStudentMark/5.0;
			averageQuiz[i] = totalQuizMark / 5.0;	
	}
	
	return ;
}

void display(string name[NUMBER_OF_STUDENT] , int mark [][5], double averageScore[5],double averageQuiz[5]){
	
	int i, j;
	cout << "name\t\t quiz 1\t quiz 2\t quiz 3\t quiz 4\t quiz 5\t average Score" << endl;
	for (i=0; i < 5; i++){
		cout << left << setw(17) << name[i] ;
		for (j=0 ; j < 5; j++){
			cout << mark[i][j] << "\t ";
		}
		
		cout << fixed << showpoint;
		cout << setprecision(2) << averageScore[i] << endl;
	}
	
	cout << "average Quiz\t ";
	for (int i = 0 ; i < 5; i++){
				cout << fixed << showpoint;
		cout << setprecision(2) << averageQuiz[i] << "\t ";
		}
	
		cout << endl;
}

void highest_marks(double average[], int NUMBER_OF_STUDENTS , string name[5])
{
	double temp = average[0];
	int highestIndex;
	
	for (int i=0 ; i < NUMBER_OF_STUDENTS ; i++){
		if (average[i] >= temp){
			temp = average[i];
			highestIndex = i;
		}
	}
	cout << name[highestIndex] << " = " << average[highestIndex] << endl;
}

void highest_marks(double average[], int NUMBER_OF_QUIZ )
{
	double temp = average[0];
	int highestIndex;
	
	for (int i=0 ; i < NUMBER_OF_QUIZ ; i++){
		if (average[i] >= temp){
			temp = average[i];
			highestIndex = i;
		}
	}
	cout << "QUIZ " << highestIndex + 1 << " = " << average[highestIndex] << endl;
}

void lowest_marks(double average[], int NUMBER_OF_STUDENTS , string name[5])
{
	double temp = average[0];
	int lowestIndex;
	
	for (int i=0 ; i < NUMBER_OF_STUDENTS ; i++){
		if (average[i] <= temp){
			temp = average[i];
			lowestIndex = i;
		}
	}
	cout << name[lowestIndex] << " = " << average[lowestIndex] << endl;
}

void lowest_marks(double average[], int NUMBER_OF_QUIZ )
{
	double temp = average[0];
	int lowestIndex;
	
	for (int i=0 ; i < NUMBER_OF_QUIZ ; i++){
		if (average[i] <= temp){
			temp = average[i];
			lowestIndex = i;
		}
	}
	cout << "QUIZ " << lowestIndex + 1 << " = " << average[lowestIndex] << endl;
}

 void sorting (double average[], string name[], int mark[][5])
 {	
 	 for (int i = 0; i < 5; i++) {
 
    	double currentMinAvg = average[i];
    	int currentMinIndex = i;
    	int tempMark[5];
		string currentMinName = name[i];
      
      	for(int k =0; k < 5 ; k++)
      		tempMark[k] = mark [i][k];

      
    	for (int j = i + 1; j < 5; j++) {
    		if (currentMinAvg > average[j]) {
          		currentMinAvg = average[j];
          		currentMinIndex = j;
          		currentMinName = name[j];
          
          		for(int k = 0; k < 5 ; k++)
					tempMark[k] = mark [i][k];
        	
			}
    	  }

    	if (currentMinIndex != i) {
        	average[currentMinIndex] = average[i];
        	average[i] = currentMinAvg;
        	name[currentMinIndex] = name[i];
        	name[i] = currentMinName;
        
        	for(int k = 0; k < 5 ; k++){
				mark [currentMinIndex][k] = mark [i][k];
        		mark [i][k] = tempMark[k];
			}
        
      	}
    }
    
	return ;
  }
  
  void display(string name[NUMBER_OF_STUDENT] , int mark [][5], double averageScore[5])
  {
	
	int i, j;
	cout << endl;
	cout << "name\t\t quiz 1\t quiz 2\t quiz 3\t quiz 4\t quiz 5\t average Score" << endl;
	for (i=0; i < 5; i++){
		cout << left << setw(17) << name[i] ;
		for (j=0 ; j < 5; j++){
			cout << mark[i][j] << "\t ";
		}
		
		cout << fixed << showpoint;
		cout << setprecision(2) << averageScore[i] << endl;
	}

		cout << endl;
}
