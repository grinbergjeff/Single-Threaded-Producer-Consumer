/*
CS 311 - Project 1 [Text-File Reader]
Code by: Jeffrey Grinberg
jgrinbe1@binghamton.edu
*/
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include "time_functions.h"
using namespace std;

//Function Delcarations
void charRead(string filename);
void lineRead(string filename);

int main()
{
	//Delcaration of variables
	int mode; //User input value for which file reading mechanism will execute
	string file; // 'file' stores the user input value for which .txt file they want to be read

	//Prompt user for which file they want to be read.
	cout << "Please enter the .txt file that you want to be read (with the .txt extension): \n";
	cin >> file;
	cout << "The program will read this file: " << file << "\n";

	//Prompt user for which mode they want their file to be read in.
	cout << "Please enter which mode you want your file to be read in: \n";
	cout << "Enter '0' if you want the file to be read character-by-character \n";
	cout << "Enter '1' if you want the file to be read line-by-line \n";
	cout << "Please enter which mode you want your file to be entered in now: \n";
	cin >> mode;

	if (mode == 0)
	{
		charRead(file);
	}
	else
	{
		lineRead(file);
	}
	return 0;
}

void charRead(string filename)
{
	char symbol = 'a'; // Every character that gets read will get temporarily store into this variable.
	ifstream textfile(filename); //Opens text file to read from
	ofstream charfile("charRead.txt"); // Opens text file to write to
	//int finder = textfile.peek(); // Looks for value of character [Going to look for EOF and peek() supports EOF]
	//Insert some verification parameters
	if (textfile.is_open()) //checks if text file is open
	{
		while (textfile.good()) // Makes sure the file is working properly
		{
			symbol = textfile.get(); // Stores the character that is read to variable sym
			if (textfile.eof()) //If get() reaches the EOF, close the file and stop doing everything.
			{
				textfile.close();
				break;
			}
			cout << "Read this character: \n";
			cout << symbol << "\n";
			if (charfile.is_open())
			{
				charfile << symbol;
				cout << "Wrote the character to charRead.txt \n";
			}
			else cout << "Unable to write character to new text file (charRead.txt). \n";
			cout << "Finished writing all characters to charRead.txt \n";
		}
		textfile.close();
		charfile.close();
	}
}

void lineRead(string filename)
{
	string line; // 'line' temporarily stores the value of the line that was read
	ifstream textfile(filename); //Opens text file to read from
	ofstream linefile("LineRead.txt"); // Opens text file to write to
	//Insert some verification parameters
	if (textfile.is_open()) //checks if text file is open
	{
		while (textfile.good()) // Makes sure the file is working properly
		{
			while (getline(textfile, line)) // Output each line that is read.
			{
				cout << "Reading this line: \n";
				cout << line << "\n";
				if (linefile.is_open())
				{
					linefile << line << "\n";
					cout << "Wrote the line to LineRead.txt \n";
					//linefile.close();
				}
				else cout << "Unable to write line to new text file (LineRead.txt). \n";
			}
			textfile.close();
			linefile.close();
		}
	}
	else cout << "Unable to open original text file. \n";
}

