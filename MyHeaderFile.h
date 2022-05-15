#ifndef UNTITLED3_MYHEADERFILE_H
#define UNTITLED3_MYHEADERFILE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// Global variables

extern int choice;
extern fstream myFile;
extern fstream myFile2;
extern fstream targetFile;
extern vector<string> lines;
extern vector<string> lines2;
extern vector<string> wordvector;
extern vector<char> inside;
extern char text[100] , text2[100], name[100], text0 , name2[100];
extern string readWord, userWord, targetFileName , name_file;

// All functions on the program
int menuDisplay();
void loadFile(vector<string>& lines,fstream& myFile );
void loadFile2(vector<string>& lines2, fstream& myFile2);
void mergeFile();
void countChar();
void countWords();
void searchForWord();
void TurnToUpper();
void TurnToLower();
void FreqWord();
void firstUpper();
void add_text();
void empty_file(string& name_file);
void displayContent();
void encryption();
void decryption();


#endif //UNTITLED3_MYHEADERFILE_H
