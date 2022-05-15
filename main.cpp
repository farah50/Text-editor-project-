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
void add_text();
void display_content();
void empty_file(string& name_file);
void encryption();
void decryption();



int choice;
fstream myFile;
fstream myFile2;
fstream targetFile; 
vector<string> lines;
vector<string> lines2;
vector<string> wordvector;
vector<char> inside;
char text[100] , text2[100], name[100], name2[100], text0;
string readWord, userWord, targetFileName, word;


int main(){

    bool x = true;

    while (x) {
       choice = menuDisplay();

        switch (choice){
            case 1 :
                add_text();
                break;
            case 2:
                display_ontent();
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
                cout<< "Good bye ^-^"
                x = false;
        }
    }
}
int menuDisplay() {

    cout << " +----------------------------------------------------------+\n"
            " +     Welcome, Please choose one option of the following   +\n"
            " +----------------------------------------------------------+\n"
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
          
    bool newSentence = true;

    cout << "Please enter the file name: " ;
    cin >> name;

    cout << "Please enter the target file name: " ;
    cin >> targetFileName;   

    targetFile.open(targetFileName, ios::out);  
    myFile.open(name, ios::in);

    if (myFile) {
        while (myFile.get(text0)) {
            if (text0 == ' ') {
                newSentence = true;
            }
            if (isalpha(text0)) {
                if (newSentence) {
                    text0 = toupper(text0);
                }
            }
            targetFile.put(text0);  
        }
        myFile.close();
        targetFile.close();   
    }
    else {
        cout << "Can't open file, please try again." << endl;
}
    cout << "\nThe file turned to uppercase successfully." << endl;

}


void TurnToLower(){
          
    bool newSentence = true;

    cout << "Please enter the file name: " ;
    cin >> name;

    cout << "Please enter the target file name: " ;
    cin >> targetFileName;   

    targetFile.open(targetFileName, ios::out);  
    myFile.open(name, ios::in);

    if (myFile) {
        while (myFile.get(text0)) {
            if (text0 == ' ') {       // To check if there is a distance or not
                newSentence = true;
            }
            if (isalpha(text0)) {
                if (newSentence) {
                    text0 = tolower(text0);   
                }
            }
            targetFile.put(text0);  
        }
        myFile.close();
        targetFile.close();   
    }
    else {
        cout << "Can't open file, please try again." << endl;
}
    cout << "\nThe file turned to lowercase successfully." << endl;
}

void FreqWord(){
  
  cout << "Please enter the file name : ";
  cin >> name; 

  myFile.open(name,ios::in);
  
while(myFile >> readWord){    

   wordvector.push_back(readWord);
    for(int i = 0 ; i < wordvector.size(); i ++) {
        for (int j = 0; j < wordvector[i].size(); j++) {
            wordvector[i][j] = tolower(wordvector[i][j]);
        }
    }
}

while(true){

   int counter = 0;

   cout <<"Please enter the word you want to check occurrences of: ";
   cin >> userWord;

   for(int i = 0; i < wordvector.size(); i++){
    userWord[i] = tolower(userWord[i]);
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
        cout << "Can't open file, please try again." << endl;
}

    cout << "\nFile conversion successfully." << endl;

}
void add_text (){
    string name_file;
    cout<<"enter the name of file you want to add to :";
    cin>>name_file;


    fstream myFile(name_file.c_str(), ios::app);

    string line;

    cout<<"enter the message you want to add:";
    cin.get();
    getline(cin , line);

        if (!cin.eof()) {
            myFile << line << '\n';
        }



    myFile.close();

    cin.clear();
}
void display_content() {
    string name_file;
    cout<<"enter the name of file you want to display:";
    cin>>name_file;

    fstream myFile(name_file.c_str(), ios::in);

    char str[10000];



    while (myFile.getline(str, 10000)) {
        cout << str << endl;
    }



    myFile.close();

}

void empty_file(string& name_file) {


    fstream myFile(name_file.c_str(), ios::out);

    myFile.close();

}

void encryption() {
    cout<<"enter the name of file you want to encrypt. \n";
    cin >> name_file;
    fstream myFile(name_file, ios::in );
    string file_content = "";
    string encrypt="";
    char line[1000];

    while (myFile.getline(line, 1000, '\n')) {
        file_content += line ;
        file_content += '\n';
    }
    myFile.close();
    myFile.open(name_file,  ios::out);
    char c;
    for (int i = 0 ; i < file_content.size(); i++){
        if(file_content[i] == '\n'){
             c = '\n';
            encrypt +=c;

        }
        else{
            c = file_content[i] + 1;
            encrypt +=c;
        }
    }
    myFile << encrypt;
    myFile.close();
}
void decryption(){
    string name_file;
    cout<<"enter the name of file you want to decrypt\n";
    cin >> name_file;
    fstream myFile(name_file, ios::in );
    string file_content = "";
    string decrypt="";
    char line[1000];

    while (myFile.getline(line, 1000, '\n')) {
        file_content += line ;
        file_content += '\n';
    }
    myFile.close();
    myFile.open(name_file,  ios::out);

    char c;
    for (int i = 0 ; i < file_content.size(); i++){
        if(file_content[i] == '\n'){
            c = '\n';
            decrypt += c;

        }
        else{
            c = file_content[i] - 1;
            decrypt += c;
        }
    }
    myFile << decrypt;
    myFile.close();
}


