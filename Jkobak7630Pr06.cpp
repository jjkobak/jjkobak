/*	J. Kobak	EGR111		CA011		21 April 2020
	This program loads a series of values in a 5 by 6 array and reduces the array to row/echelon 
	form and then backsolves the equations to find the roots. The back solving is done by 
	multiplying every single row by the recriprocal of the number in the first column in the first 
	row. Then the program subtracts each preceding row by the first row. This cycle repeats but now
	the second row becomes "the first row" and the second column becomes "the first column". This
	process repeats until there is a diagonal line of 1s in the matrix with zeros on the left of the
	diagonal and non zero numbers on the right. The roots were found by back solving the system of
	equations. The roots will be displayed below the table for the original array and the reduced 
	array. 
*/
	 

// Preprocessor Directives
using namespace std;
#include<iostream>
#include<iomanip>
#include<fstream>
#include<Windows.h>

// User-defined function declarations
void readit();
void calcit(float[5][6], float[5][6], float[5][6]);
void writeit(float[5][6], float[5][6], float[5]); 

// Declaration and definition of the main()
int main()
{
	// Cascaded function call to readit()
	readit();
	
	return 0;
	
}   

// Definition of function readit();
void readit()
{
	// Declaration of local variables
	float origarray[5][6], reducedarray[5][6], maniparray[5][6];
	
	// Declaration of ifstream infile
	ifstream infile("C:\\EGR111\\rowechelon.txt");
	
	// Input filestream error trap
	if(!infile)
	{
		cout << "There is no file or there is another problem. correct the problem and try again!";
		Sleep(2000);
		system("CLS");
		exit(0);
	}
	
	// Read from the file into the array
	for(int i = 0; i < 5; i++)
		for(int j = 0; j < 6; j++)
		{
			infile >> origarray[i][j];
			reducedarray[i][j] = origarray[i][j];
			maniparray[i][j] = origarray[i][j];
		}
		
	// Cascaded function call to calcit()
	calcit(origarray, reducedarray, maniparray);
}

// Definition of caclit()
void  calcit(float origarray[5][6], float reducedarray[5][6], float maniparray[5][6])
{
	// Local variable declarations
	float root[5];
		
// Outer most loop reducing matrix UP TO the last row
for(int maxx = 0; maxx < 4; maxx++)
{
	// loop multiplying each row by the recriprocal of the first number in that row
	for(int i = maxx; i < 5; i++) 
	{
			
		for(int j = maxx; j < 6; j++)
		{
			 reducedarray[i][j] = reducedarray[i][j] * 1 / maniparray[i][maxx];
		}
	}
	
	// Subtracting the preceding row by the current row
	for(int i = maxx + 1; i < 5; i++) 
	{
		
		for(int j = maxx; j < 6; j++)
		{
			reducedarray[i][j] = reducedarray[i][j] - reducedarray[maxx][j];
			maniparray[i][j] = reducedarray[i][j];
		}
	}
}
	// Last loop calculating the final root
	for(int i = 4; i < 5; i++) 
	{
			
		for(int j = 4; j < 6; j++)
		{
			 reducedarray[i][j] = reducedarray[i][j] * 1 / maniparray[i][4];
		}
	}
 
 	// Root Calculation block
	root[5] = reducedarray[4][5];
	root[4] = reducedarray[3][5] - reducedarray[3][4] * root[5];
	root[3] = reducedarray[2][5] - reducedarray[2][4] * root[5] - reducedarray[2][3] * root[4];
	root[2] = reducedarray[1][5] - reducedarray[1][4] * root[5] - reducedarray[1][3] * root[4]
			- reducedarray[1][2] * root[3];
	root[1] = reducedarray[0][5] - reducedarray[0][4] * root[5] - reducedarray[0][3] * root[4] 
			- reducedarray[0][2] * root[3]- reducedarray[0][1] * root[2];
	
	// Cascaded function call to writeit()
	writeit(origarray, reducedarray, root);
}

// Definition of function writeit()
void writeit(float origarray[5][6], float reducedarray[5][6], float root[5])
{
	// Local variable declaration
	char hex;
	
	// Original Array Table
	cout << "Original Array" << endl << fixed << setprecision(2);
	
		for(int i = 0; i < 5; i++)
		{
			for(int j = 0; j < 6; j++)
			{
				cout << setw(8) << origarray[i][j];
			}
			
			cout << endl << endl;
		}
	
	// Reduced array table	
	cout << "Reduced Array" << endl << fixed << setprecision(2);
	
		for(int i = 0; i < 5; i++)
		{
			for(int j = 0; j < 6; j++)
			{
				cout << setw(8) << reducedarray[i][j];
			}
			
			cout << endl << endl;
		} 
	
	// Roots List
	for(int i = 5; i > 0; i--)
	{
		hex = 'Z' - (5-i);
		cout << "Root for variable " << hex << " is: " << root[i] << endl;
	}
}	
		            
