// FCAI – Programming 1 – 2022 - Assignment 4
// Program Name: Text Editor.cpp
// Last Modification Date: xx/xx/xxxx
// Author1 and ID and Group: Sara Tamer Bihery - 20210155 - S25
// Author2 and ID and Group: Farah Mohamed Mohamed El-Sayed - 20210288 - S25
// Author3 and ID and Group: Rawnaa Mustafa  - 20210137 - S2
// Teaching Assistant: Mahmoud Fateaha
// Purpose: Edit an existing or new text file.

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int menuDisplay();
void loadFile(vector<string>& lines,fstream& myFile );
void loadFile2(vector<string>& lines2, fstream& myFile2);
void mergeFile();
void countChar();
void countWords();
void searchForWord();
void TurnToUpper();
void TurnToLower();


int choice;
fstream myFile;
fstream myFile2;
vector<string> lines;
vector<string> lines2;
vector<char> inside;
char text[100] , text2[100];


int main(){

    bool x = true;

    while (x) {
       choice = menuDisplay();

        switch (choice){
            case 1 :
                break;
            case 6 :
                loadFile(lines, myFile);
                loadFile2(lines2, myFile2);
                mergeFile();
                break;
            case 7 :
                loadFile(lines, myFile);
                countWords();
                break;
            case 8 :
                loadFile(lines, myFile);
                countChar();
                break;
            case 9 :
                loadFile(lines, myFile);
                cout << "The number of lines = " << lines.size()  << endl;
                break;
            case 10 :
                loadFile(lines, myFile);
                searchForWord();
                myFile.close();
                break;
            case 12:
                TurnToUpper();
                myFile.close();
                break;
            case 13:
                TurnToLower();
                myFile.close(); 
                break;
            case 15:
                myFile.close();
            case 16 :
                x = false;
        }
    }
}
int menuDisplay() {

    cout << "\n Please choose one option of the following: \n"
            "1. Add new text to the end of the file \n"
            "2. Display the content of the file\n"
            "3. Empty the file\n"
            "4. Encrypt the file content \n"
            "5. Decrypt the file content\n"
            "6. Merge another file\n"
            "7. Count the number of words in the file.\n"
            "8. Count the number of characters in the file\n"
            "9. Count the number of lines in the file\n"
            "10. Search for a word in the file\n"
            "11. Count the number of times a word exists in the file\n"
            "12. Turn the file content to upper case.\n"
            "13. Turn the file content to lower case.\n"
            "14. Turn file content to 1st caps (1st char of each word is capital) \n"
            "15. Save\n"
            "16. Exit\n";
    cin >> choice;
    return choice;
}
void loadFile(vector<string>& lines,fstream& myFile){
    char name[100] , text[100];
    cout << "Please enter the file name : \n";
    cin >> name;
    myFile.open(name , fstream::in | fstream::out);

    if (myFile){
        cout << "The file has opened successfully \n";
        while (!myFile.eof()){
            myFile.getline(text , 100 , '\n');
            lines.push_back(string(text));
        }
    }
    else {
        cout << "This file couldn't open.\n "
                "Another file will be created when saving \n";
    }
}
void loadFile2(vector<string>& lines2,fstream& myFile2){
    char name2[100] , text2[100];
    cout << "Please enter the name of the other file : \n";
    cin >> name2;
    myFile2.open(name2 , fstream::in | fstream::out);

    if (myFile2){
        cout << "The file has opened successfully \n";
        while (!myFile2.eof()){
            myFile2.getline(text2 , 100 , '\n');
            lines2.push_back(string(text2));
        }
    }
    else {
        cout << "This file couldn't open.\n "
                "Another file will be created when saving \n";
    }
}

void countChar(){
    long counter = 0 ;
    for(int i = 0 ; i < lines.size(); i ++){
        for(int j = 0 ; j < lines[i].size() ; j++){
            counter ++;
        }
    }
    cout << "The number of characters in the file = " << counter << endl;
}
void countWords(){
    long counter = 0 ;
    for(int i = 0 ; i < lines.size(); i ++){
        for(int j = 0 ; j < lines[i].size() ; j++){
            if(lines[i][j] == ' '){
                counter ++;
            }
        }
        counter ++;
    }
    cout << "The number of words in the file = " << counter  << endl;
}
void mergeFile(){
    while(!myFile2.eof()) {
        myFile2 >> text2;
        myFile << text2;
    }
    myFile.close();
    myFile2.close();
        cout << "The files merged successfully.\n" ;
}
void searchForWord(){

    char word[100] ;
    cout << "Please enter the word you want to search for. \n";
    cin >> word;
    while (true){
        if(string(text).find( word) != 0){
            cout << "Word was found in the file. \n";
            break;
        }
        else
            cout << "Word was not found in the file. \n";
    }
}

void TurnToUpper(){

    char name[100], text;

    fstream myFile;
    vector<char> inside;
    
    cout << "Enter the file name : ";
    cin >> name;
    myFile.open(name,ios::in);
    
    while(!myFile.eof() && !myFile.fail()){
        myFile.get(text);
        inside.push_back(toupper(text));
    }
    myFile.close();
    myFile.open(name,ios::out);
    for(int i=0 ; i<inside.size()-1 ; ++i){
        myFile.put(inside[i]);
    }
    cout << "The file turned to uppercase successfully\n";
    
}


void TurnToLower(){

    char name[100], text;

    fstream myFile;
    vector<char> inside;
    
    cout << "Enter the file name : ";
    cin >> name;
    myFile.open(name,ios::in);
    
    while(!myFile.eof() && !myFile.fail()){
        myFile.get(text);
        inside.push_back(tolower(text));
    }
    myFile.close();
    myFile.open(name,ios::out);
    for(int i=0 ; i<inside.size()-1 ; ++i){
        myFile.put(inside[i]);
    }
    cout << "The file turned to lowercase successfully\n";
    
}


