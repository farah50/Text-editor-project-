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
void saveFile();
void mergeFile();
void countChar();
int choice;
fstream myFile;
vector<string> lines;

int main(){

    bool x = true;

    while (x) {
       choice = menuDisplay();

        switch (choice){
            case 1 :
                break;
            case 6 :
                break;
            case 7 :
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
                break;
            case 16 :
                x = false;
        }
    }
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
void countChar(){
    long counter = 0 ;
    for(int i = 0 ; i < lines.size(); i ++){
        for(int j = 0 ; j < lines[i].size() ; j++){
            counter ++;
        }
    }
    cout << "The number of characters in the file = " << counter << endl;
}
