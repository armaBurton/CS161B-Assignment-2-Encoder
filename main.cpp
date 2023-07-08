#include <iostream>
#include <cctype>
#include <cstdlib>
#include <cstring>

using namespace std;

const int MAXLENGTH = 200;
const int NAMELENGTH = 20;
const int TIME = 6;

void welcome();
void displayMenu();
void readOption(char &option);
void encode(char encodedFileName[]);
void readInput(char fName[], char lName[], bool &lateFlag);
void readInput(char parsedId[], char fileName[]);
void readTime(char strTime[]);

int main(){
    char encodedFileName[MAXLENGTH];
    char menuOption;
    welcome();
    while (true){

        displayMenu();
        readOption(menuOption);
        switch (tolower(menuOption))
        {
        case 'q':
            return 0;
            break;
        case 'e':
            encode(encodedFileName);
            cin.clear();
            cin.ignore();
            break;
        default:
            cout << endl << "You have chosen poorly.\n\n";
            cin.clear();
            cin.ignore();
            break;
        }
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
    char fName[NAMELENGTH], 
         lName[NAMELENGTH], 
         fileName[MAXLENGTH],
         parsedID[MAXLENGTH],
         subTime[TIME];
    bool lateFlag;

    readInput(fName, lName, lateFlag);
}

void readInput(char fName[], char lName[], bool &lateFlag){
    cout << '\n'
         << "Enter your last name: ";
    cin.get(lName, NAMELENGTH);
    cout << lName << endl;
}

void readInput(char parsedId[], char fileName[]){}

void readTime(char strTime[]){}