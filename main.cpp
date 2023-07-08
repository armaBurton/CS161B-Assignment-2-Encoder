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
    cout << MAXLENGTH << " " << NAMELENGTH << " " << TIME << endl;
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
    char tempFlag;
    bool loopState;
    cout << '\n'
         << "Enter your last name: ";
    cin.ignore();
    cin.get(lName, NAMELENGTH, '\n');
    cout << '\n'
         << "Enter your first name: ";
    cin.ignore();
    cin.get(fName, NAMELENGTH, '\n');
    cin.ignore();
    do{
        loopState = true;
        cout << "Is your assignment late (y/n)? ";
        cin.get(tempFlag);

        switch (tempFlag)
        {
            case 'y':
            case 'Y':
                loopState = false;
                cout << loopState;
                break;
            case 'n':
            case 'N':
                loopState = false;
                cout << loopState;
                break;
            
            default:
                cout << "You have chosen poorly.\n";
                cin.clear();
                // cin.ignore();
                break;
        }
    }while (loopState);
    cin.ignore();
    cout << endl;
}

void readInput(char parsedId[], char fileName[]){}

void readTime(char strTime[]){}