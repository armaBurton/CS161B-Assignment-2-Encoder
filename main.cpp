#include <iostream>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <regex>

using namespace std;

const int MAXLENGTH = 200;
const int NAMELENGTH = 20;
const int TIME = 6;
const int FIVE = 5;

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
        switch (tolower(menuOption)){
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
         parsedID[FIVE],
         subTime[TIME],
         tempTime[TIME];
    bool lateFlag;

    readInput(fName, lName, lateFlag);
    readInput(parsedID, fileName);
    readTime(subTime);
    cout << endl;

    strcpy(encodedFileName, lName);
    strcat(encodedFileName, "_");
    strcat(encodedFileName, fName);
    strcat(encodedFileName, "_");
    if(lateFlag){
        strcat(encodedFileName, "LATE_");
    }
    strcat(encodedFileName, parsedID);
    strcat(encodedFileName, "_");
    for (int i = 0, j = 0; i < strlen(subTime); i++, j++){
        if (subTime[i] == ':'){
            i++;
        }
        tempTime[j] = subTime[i];
    }
    strcat(encodedFileName, tempTime);
    strcat(encodedFileName, "_");
    strcat(encodedFileName, fileName);

    cout << encodedFileName << endl;
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
        cout << "\nIs your assignment late (y/n)? ";
        cin.get(tempFlag);

        switch (tempFlag)
        {
            case 'y':
            case 'Y':
                loopState = false;
                lateFlag = true;
                break;
            case 'n':
            case 'N':
                lateFlag = false;
                loopState = false;
                break;
            
            default:
                cout << "You have chosen poorly.\n";
                cin.clear();
                break;
        }
    }while (loopState);

    cin.ignore();
    cout << endl;
}

void readInput(char parsedId[], char fileName[]){
    char tempId[12];
    bool loopState;

    do{
        loopState = false;

        cout << "Enter you Student-ID (format: 666-66-6666): ";
        cin.get(tempId, 12, '\n');
        cout << tempId << endl;
        strncpy(parsedId, tempId + 7, 4);
        for(int i = 0; i < strlen(parsedId);i++){
            cout << parsedId[i] << endl;
            if (isdigit(parsedId[i]) == 0){
                loopState = true;
            }
        }
        if (loopState){
            cout << "You have chosen poorly.\n";
            cin.ignore();
        }

    } while (loopState);
    cin.ignore();
    cout << endl;

    cout << "Enter the file name: ";
    cin.get(fileName, NAMELENGTH, '\n');
    cin.ignore();
    cout << endl;
}

void readTime(char strTime[]){
    const regex pattern("([01]?[0-9]|2[0-3]):[0-5][0-9]");
    bool loopState;

    do{
        loopState = true;
        cout << "Enter the time submitted (military time - ex: 18:24 for 6:24pm): ";
        cin.get(strTime, TIME, '\n');
        cin.ignore();
        cout << endl;
        if(regex_match(strTime, pattern)){
            loopState = false;
        } else {
            cout << "InValid time format.\n\n";
        }
        
    } while (loopState);

    cout << endl;
}