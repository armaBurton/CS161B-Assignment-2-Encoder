#include <iostream>
#include <cctype>
#include <cstdlib>
#include <cstring>

using namespace std;

void welcome();
void displayMenu();
void readOption(char &option);
void encode(char encodedFileName[]);
void readInput(char fName[], char lName[], bool &lateFlag);
void readInput(char parsedId[], char fileName[]);
void readTime(char strTime[]);

CONST INT MAXLENGTH = 200;
CONST INT NAMELENGTH = 20;

int main(){
    char menuOption;
    char encodedFileName[MAXLENGTH];

    welcome();
    while (true){
        displayMenu();
        readOption(menuOption);
        if (tolower(menuOption) == 'q'){
            return 0;
        } else if (tolower(menuOption) == 'e'){
            encode(encodedFileName);
        } else if (tolower(menuOption) != 'q' || tolower(menuOption) != 'e') {
            cout << endl << "You have chosen poorly.\n\n";
        }
        cin.ignore();
        menuOption = '\0';
    }

    system("pause");
    return 0;
}

void welcome(){
    cout << "Welcome to my fileName encoding program!!\n\n";
}

void displayMenu(){
    cout << "Please pick an option below:\n"
         << "(e) Encode a file name\n"
         << "(q) Quit\n";
}
 
void readOption(char &option){
    bool loopState = true;
    cout << ">> ";
    cin.get(option);
}

void encode(char encodedFileName[]){
    char fName[NAMELENGTH], lName[NAMELENGTH];
    bool lateFlag;
}

void readInput(char fName[], char lName[], bool &lateFlag){}

void readInput(char parsedId[], char fileName[]){}

void readTime(char strTime[]){}