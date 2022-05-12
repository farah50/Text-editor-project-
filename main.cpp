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
void FreqWord();
void firstUpper();



int choice;
fstream myFile;
fstream myFile2;
fstream targetFile; 
vector<string> lines;
vector<string> lines2;
vector<string> wordvector;
vector<char> inside;
char text[100] , text2[100], name[100], name2[100], text0;
string readWord, userWord, targetFileName;


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
    myFile2.close();
    myFile.close();
    myFile.open(name , ios::app);
    myFile2.open(name2 ,  fstream::in | fstream::out );
    myFile << "\n";
    while(!myFile2.eof()) {
        myFile2 >> text2;
        myFile << " ";
        myFile << text2;
    }
    myFile.close();
    myFile2.close();
        cout << "The files merged successfully.\n" ;
}
void searchForWord(){

   string word ;
    cout << "Please enter the word you want to search for. \n";
    cin >> word;
    int i = 0;
    while(i < word.size()){
        word[i] = tolower(word[i]);
        i ++;
    }
   myFile.close();
   myFile.open(name , fstream::in | fstream::out);
    while (!myFile.eof()){
        myFile.getline(text , 100 , '\n');
        lines.push_back(string(text));
    }
    for(int i = 0 ; i < lines.size(); i ++) {
        for (int j = 0; j < lines[i].size(); j++) {
            lines[i][j] = tolower(lines[i][j]);
        }
    }
    bool k = true;
    for(int i = 0 ; i < lines.size(); i ++) {
        if (lines[i].find(word) != string::npos) {
            cout << "Word was found in the file. \n";
            k = false;
            break;
        }
    }

    if(k){
        cout << "Word was not found in the file. \n";
    }
}

void TurnToUpper(){

   
    cout << "Please enter the file name : ";
    cin >> name;

    cout << "Please enter the target file name: ";
    cin >> targetFileName;

    myFile.open(name,ios::in);
    targetFile.open(targetFileName, ios::out);

    if(myFile){
        while(myFile.get(text0)){
            
            inside.push_back(toupper(text0));
        
        for(int i=0 ; i<inside.size()-1 ; ++i){
            targetFile.put(inside[i]);
        }
    }
        myFile.close();
        targetFile.close();
        cout << "The file turned to uppercase successfully\n";
    }
    else{
        cout << " Can't open file.";
    }

}


void TurnToLower(){

    cout << "Please enter the file name : ";
    cin >> name;

    cout << "Please enter the target file name: ";
    cin >> targetFileName;

    myFile.open(name,ios::in);
    targetFile.open(targetFileName, ios::out);

    if(myFile){
        while(myFile.get(text0)){
            
            inside.push_back(toupper(text0));
        
        for(int i=0 ; i<inside.size()-1 ; ++i){
            targetFile.put(inside[i]);
            }
       }
        myFile.close();
        targetFile.close();
        cout << "The file turned to uppercase successfully\n";
    }
    else{
        cout << " Can't open file.";
    }

}

void FreqWord(){
  
  cout << "Please enter the file name : ";
  cin >> name; 

  myFile.open(name,ios::in);
  
while(myFile >> readWord){    

   wordvector.push_back(readWord);
}

while(true){

   int counter = 0;

   cout <<"Please enter the word you want to check occurrences of: ";
   cin >> userWord;

   for(int i = 0; i < wordvector.size(); i++){

    if( userWord == wordvector[i]){
        counter++;
    }
        
   }
   cout <<"The word " << userWord << " was found: " << counter << " times" << endl;
   break; 
}
}

void firstUpper(){

    bool newSentence = true;

    cout << "Please enter the file name: " ;
    cin >> name;

    cout << "Please enter the target file name: " ;
    cin >> targetFileName;   

    targetFile.open(targetFileName, ios::out);  
    myFile.open(name, ios::in);

    if (myFile) {
        while (myFile.get(text0)) {
            if (text0 == ' ') {        // To check if there is a distance or not
                newSentence = true;
            }
            if (isalpha(text0)) { 
                if (newSentence) {
                    text0 = toupper(text0);
                        newSentence = false;   //To make the other letter of the word lowercase
                }
                else {
                    text0= tolower(text0);
                }
            }
            targetFile.put(text0);  
        }
        myFile.close();
        targetFile.close();   
    }
    else {
        cout << "Cannot open file(s)." << endl;
}

    cout << "\nFile conversion successfully." << endl;

}

