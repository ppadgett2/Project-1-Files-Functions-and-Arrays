// Name: Parker Padgett
// Assignment: Files, Functions, and Arrays
// Description: From an input file, put class names into an array and then output the names in order as well as reverse order to the screen and an output file.
// Date: 1/12/22

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <cctype>
#include <fstream>

using namespace std;

// Constants
const int ARRAY_SIZE = 50;

// Function declaration
void inputCheck(ifstream& inFile);
int getData(ifstream& inFile, string classNames[]);
void output(string classNames[], int counter, ofstream& outFile);
void outputReverse(string classNames[], int counter, ofstream& outFile);
void closeFile(ifstream& inFile, ofstream& outFile);

int main()
{
	// Variable Declaration
	ifstream inFile;
	ofstream outFile;
	string classNames[ARRAY_SIZE]; // Array declaration
	int i;
	int counter = 0;

	// Opening the input and output file
	inFile.open("classes.txt");
	outFile.open("classesOutput.txt");

	// Check to make sure input file is found
	inputCheck(inFile);

	// Input names into array from input file using getline
	counter = getData(inFile, classNames);

	// Output to screen and to output file
	cout << "Class names in order:" << endl << endl;
	outFile << "Class names in order:" << endl << endl;
	output(classNames, counter, outFile);

	// Making output look better
	cout << endl << endl;
	outFile << endl << endl;

	// Output to screen and output file in reverse order
	cout << "Class names in reverse order:" << endl << endl;
	outFile << "Class names in reverse order:" << endl << endl;
	outputReverse(classNames, counter, outFile);

	// Close files
	closeFile(inFile, outFile);

	return 0;
}

void inputCheck(ifstream& inFile)
{
	if (inFile)
		cout << "Input file found!" << endl << endl << endl;
	else
	{
		cout << "Input file not found!" << endl << endl << endl;
		exit(1);
	}
}

int getData(ifstream& inFile, string classNames[])
{
	int counter = 0;
	while (!inFile.eof())
	{
		getline(inFile, classNames[counter]);
		counter++;
	}
	return counter;
}

void output(string classNames[], int counter, ofstream& outFile)
{
	// Output to screen
	for (int i = 0; i < counter; i++)
		cout << "Class Name: " << classNames[i] << endl;

	// Output to output file
	for (int i = 0; i < counter; i++)
		outFile << "Class Name: " << classNames[i] << endl;
}

void outputReverse(string classNames[], int counter, ofstream& outFile)
{
	// Output to screen
	for (int i = counter - 1; i >= 0; i--)
		cout << "Class Name: " << classNames[i] << endl;

	// Output to output file
	for (int i = counter - 1; i >= 0; i--)
		outFile << "Class Name: " << classNames[i] << endl;
}

void closeFile(ifstream& inFile, ofstream& outFile)
{
	inFile.close();
	outFile.close();
}