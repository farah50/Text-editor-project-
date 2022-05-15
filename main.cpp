// FCAI – Programming 1 – 2022 - Assignment 4
// Program Name: Text Editor.cpp
// Last Modification Date: 16/5/2022
// Author1 and ID and Group: Sara Tamer Bihery - 20210155 - S25
// Author2 and ID and Group: Farah Mohamed Mohamed El-Sayed - 20210288 - S25
// Author3 and ID and Group: Rawnaa Mustafa Hussien  - 20210137 - S25
// Teaching Assistant: Mahmoud Fateaha
// Purpose: Edit an existing or new text file.

#include <iostream>
#include "MyHeaderFile.h"

using namespace std;

int main(){

//    infinite loop to display the menu and let the user choose his process
    bool x = true;
    while (x) {
        choice = menuDisplay();

        switch (choice){
            case 1 :
                add_text();
                break;
            case 2:
                displayContent();
                break;
            case 3:
                cout<<"enter the name of file you want to empty:";
                cin>> name_file;
                empty_file(name_file);
                break;
            case 4 :
                encryption();
                break;
            case 5 :
                decryption();
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
            case 11:
                FreqWord();
                break;
            case 12:
                TurnToUpper();
                break;
            case 13:
                TurnToLower();
                break;
            case 14:
                firstUpper();
                break;
            case 15:
                myFile.close();
            case 16 :
                x = false;
        }
    }
}
