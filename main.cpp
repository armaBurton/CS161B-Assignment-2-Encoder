// NOTE: This template is to be used for partner practice ONLY! You must
// use the required Algorithmic Design Document for all Assignments.
/******************************************************************************
    # Author:           Arma Burton
    # Assignment:       002 Encoder
    # Date:             July 9, 2023
    # Description:      This program inputs values from the user and computes
                        the cost and tip.
    # Input:            int, char, double, string
    # Output:           string, int, double
    # Sources:          user input
#******************************************************************************/
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

/*
    Name:   main()
    Desc:   This function reads menu input from the user
            If the menu option is e then it calls the encode function
                and passes the string encodedFileName
            If the menu option is q then it quits the program
    input:  char
    output: prompt
    return: int
*/
int main()
{
    char encodedFileName[MAXLENGTH];
    char menuOption;

    welcome();

    while (tolower(menuOption) != 3)
    {
        // display menu
        displayMenu();

        // read user menu input
        readOption(menuOption);
        switch (tolower(menuOption))
        {
        case 'q':
            return 0;
            break;
        case 'e':
            // begin main portion of program
            encode(encodedFileName);
            cin.clear();
            break;
        default:
            // if 'e' or 'q' are not chosen
            cout << endl
                 << "You have chosen poorly.\n\n";
            cin.clear();
            cin.ignore();
            break;
        }
    }

    system("pause");
    return 0;
}

/*
    Name:   welcome()
    Desc:   welcomes the user
    input:  none
    output: none
    return: void
*/
void welcome()
{
    cout << "Welcome to my fileName encoding program!!\n\n";
}

/*
    Name:   displayMenu()
    Desc:   displays the menu
    input:  none
    output: none
    return: void
*/
void displayMenu()
{
    cout << "Please pick an option below:\n"
         << "(e) Encode a file name\n"
         << "(q) Quit\n";
}

/*
    Name:   readOption()
    Desc:   reads character from user
    input:  char
    output: prompt
    return: void
*/
void readOption(char &option)
{
    cout << ">> ";
    cin.get(option);
}

/*
    Name:   encode()
    Desc:   controller function for building encoded file name
    input:  none
    output: prompt, char
    return: void
*/
void encode(char encodedFileName[])
{
    char fName[NAMELENGTH],
        lName[NAMELENGTH],
        fileName[MAXLENGTH],
        parsedID[FIVE],
        subTime[TIME],
        tempTime[TIME];
    bool lateFlag;

    // Prompt user for first name, last name and
    // wether or not the assignment was late
    readInput(fName, lName, lateFlag);

    // Prompt user for ID and file name
    readInput(parsedID, fileName);

    // Prompt user for time on 24hour format
    readTime(subTime);

    // Following code creates the encoded filename
    strcpy(encodedFileName, lName);
    strcat(encodedFileName, "_");
    strcat(encodedFileName, fName);
    strcat(encodedFileName, "_");

    // if lateFlag is true then concat "LATE_" to encodedFileName
    if (lateFlag)
    {
        strcat(encodedFileName, "LATE_");
    }
    strcat(encodedFileName, parsedID);
    strcat(encodedFileName, "_");

    // this for loop removes the ':' from the time array
    for (int i = 0, j = 0; i < strlen(subTime); i++, j++)
    {
        if (subTime[i] == ':')
        {
            i++;
        }
        tempTime[j] = subTime[i];
    }
    strcat(encodedFileName, tempTime);
    strcat(encodedFileName, "_");
    strcat(encodedFileName, fileName);
    // Preceding code created the encoded filename

    cout << "Your encoded file name is: " << encodedFileName << endl
         << endl;
}

/*
    Name:   readInput()
    Desc:   reads the first and last name from the user
            itterates through each name to and makes
                the characters lowercase
            colletes late flag
    input:  char[], bool
    output: none
    return: void
*/
void readInput(char fName[], char lName[], bool &lateFlag)
{
    char tempFlag;
    int length;
    bool loopState;

    // input last name
    cout << '\n'
         << "Enter your last name: ";
    cin.ignore();
    cin.get(lName, NAMELENGTH, '\n');
    length = strlen(lName);
    for (int i = 0; i < length; i++)
    {
        lName[i] = tolower(lName[i]);
    }
    // input first name
    cout << '\n'
         << "Enter your first name: ";
    cin.ignore();
    cin.get(fName, NAMELENGTH, '\n');
    length = strlen(fName);
    for (int i = 0; i < length; i++)
    {
        fName[i] = tolower(fName[i]);
    }
    cin.ignore();

    // is assignment late?
    do
    {
        loopState = true;
        cout << "\nIs your assignment late (y/n)? ";
        cin.get(tempFlag);

        switch (tempFlag)
        {
        case 'y':
        case 'Y':
            // if assisngment is late set lateFlag = true;
            loopState = false;
            lateFlag = true;
            break;
        case 'n':
        case 'N':
            // if assisngment is late set lateFlag = false;
            lateFlag = false;
            loopState = false;
            break;
        default:
            // you have chosen poorly
            cout << "You have chosen poorly.\n";
            cin.clear();
            break;
        }
    } while (loopState);

    cin.ignore();
    cout << endl;
}

/*
    Name:   readInput()
    Desc:   reads ID and file name input from the user
            performs error validation
    input:  char
    output: prompt
    return: void
*/
void readInput(char parsedId[], char fileName[])
{
    char tempId[12];
    bool loopState;

    do
    {
        loopState = false;

        // input student id
        cout << "Enter you Student-ID (format: 666-66-6666): ";
        cin.get(tempId, 12, '\n');

        if (strlen(tempId) != 11)
        {
            // if the student id length does not equal 11 then
            // set loop state true and reset memory
            loopState = true;
            memset(tempId, 0, sizeof(tempId));
        }
        else
        {
            // if the length is correct copy the last for characters
            // of tempID into parsedID
            strncpy(parsedId, tempId + 7, 4);

            for (int i = 0; i < strlen(parsedId); i++)
            {
                if (isdigit(parsedId[i]) == 0)
                {
                    // if parsedId[i] is not a number set loopState to true
                    loopState = true;
                }
            }
        }

        // if loopState is true You have chosen poorly,
        if (loopState)
        {
            cout << "\nYou have chosen poorly.\n\n";
            cin.ignore();
        }

        // function loops if loopState is true
    } while (loopState);
    cin.ignore();
    cout << endl;

    // get filename from user
    cout << "Enter the file name: ";
    cin.get(fileName, NAMELENGTH, '\n');
    cin.ignore();
    cout << endl;
}

/*
    Name:   readTime()
    Desc:   reads time input from the user
            performs validation on time input
            reformats time if needed
    input:  char
    output: prompt
    return: void
*/
void readTime(char strTime[])
{
    // regex for checking if user input conforms to 00:00 - 23:59
    const regex pattern("([01]?[0-9]|2[0-3]):[0-5][0-9]");
    bool loopState;

    do
    {
        loopState = true;
        cout << "Enter the time submitted (military time - ex: 18:24 for 6:24pm): ";
        cin.get(strTime, TIME, '\n');
        cin.ignore();

        if (strTime[1] == ':')
        {
            char temp[6];
            sprintf(temp, "0%s", strTime);
            strcpy(strTime, temp);
        }

        cout << endl;
        // check user input, if format is corect set loopState to false
        if (regex_match(strTime, pattern))
        {
            loopState = false;
        }
        else
        {
            cout << "InValid time format.\n\n";
        }
        // function resets if loopState is true
    } while (loopState);
}