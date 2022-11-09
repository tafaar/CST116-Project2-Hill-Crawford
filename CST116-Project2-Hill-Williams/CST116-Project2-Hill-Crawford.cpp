// cst-116-Project2-Hill.cpp : Aaron Hill and Lloyd Crawford
//

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int GetData();
void DisplayMenu(int& menuChoice);
void ProcessMenuChoice(int menuChoice, int& number);
void IsPosNeg(int menuChoice);
void IsOddEven(int menuChoice);
int FindNumDigits(int menuChoice);
int FindDigitAtPosition(int menuChoice);
void DisplayAdditionTable();
void DisplayMultiplicationTable();


int menuChoice = 1;
int number;
int length = 0;

int main()
{
    number = GetData();

    while (menuChoice != 0) {

        DisplayMenu(menuChoice);
        ProcessMenuChoice(menuChoice, number);
        cout << endl;

        if (menuChoice != 0 && menuChoice != 1) {
            system("pause");
        }

    }

    return 0;
}

void DisplayMenu(int& menuChoice) {

    cout <<
        "\nThe number you entered is " << number << "\n" <<
        "\nWhat would you like to do?" <<
        "\n0 - Exit application" <<
        "\n1 - Enter a new number" <<
        "\n2 - Check if the number is positive or negative" <<
        "\n3 - Check if the number is odd or even" <<
        "\n4 - Find the length of this digit" <<
        "\n5 - Find a number at a specific position" <<
        "\n6 - Display an addition table" <<
        "\n7 - Display a multiplication table\n" <<
        endl;

    do { cin >> menuChoice; } while (menuChoice < 0 || menuChoice > 7);

}

void ProcessMenuChoice(int menuChoice, int& number) {

    // Just a bunch of switch statements for each menu choice. The number can be directly edited as it is passed by reference.

    switch (menuChoice) {

    case 0:

        cout << "\nGoodbye!\n" << endl;

        break;

    case 1:

        number = GetData();
        break;

    case 2:

        IsPosNeg(number);
        break;

    case 3:

        IsOddEven(number);
        break;

    case 4:

        cout << "\nThe number " << number << " is " << FindNumDigits(number) << " digits long.\n" << endl;
        break;

    case 5:
        cout << "\nFound the number " << FindDigitAtPosition(number) << "\n" << endl;
        break;

    case 6:
        DisplayAdditionTable();
        break;

    case 7:
        DisplayMultiplicationTable();
        break;

    default:
        cout << "\nInvalid selection.\n" << endl;
    }

}

int GetData() {

    long int number = 0;
    bool validInput = false;

    cout << "Enter a number equal to or between -1000000 and 1000000." << endl;

    // Self-explanatory. Until the user puts in a number between -1mil and 1mil, keep asking for a number. Return that number on success.

    while (!validInput) {

        cin >> number;

        if (number > 1000000 || number < -1000000) {

            cout << "ERROR: Invalid number, try again." << endl;

        }
        else {
            validInput = true;
        }

    }

    return number;
}

void IsPosNeg(int value) {

    // Check if the number is greater than, less than, or equal to zero.

    if (value < 0) {
        cout << "\n" << number << " is negative.";
    }
    else if (value > 0) {
        cout << "\n" << number << " is positive.";
    }
    else {
        cout << "\nThis number is 0.";
    }

    cout << endl;
}

void IsOddEven(int menuChoice) {

    // Check if the number is zero or divisible by 2. If not, the number must be odd.

    if (menuChoice == 0) {
        cout << "\nThis number is 0.";
    }
    else if (menuChoice % 2 == 0) {
        cout << "\n" << number << " is even.";
    }
    else {
        cout << "\n" << number << " is odd.";
    }

    cout << endl;
}

int FindNumDigits(int value) {

    int choiceLength;

    string choiceString = to_string(value);

    choiceLength = choiceString.length();

    // When converting the number to a string, the potential negative sign will be included. 
    // To account for this, subtract one from the length if the first character is -.
    // Could have just checked if the number was less than 0, but this is more readable.

    if (choiceString[0] == '-') {
        choiceLength--;
    }

    return choiceLength;
}

int FindDigitAtPosition(int value) {

    int found;
    int input;
    bool validSearch = false;

    cout << "\nEnter a number to find a digit at that position: " << endl;

    do {

        cin >> input;

        // Position must be greater than 0 but equal to or less than the length of the number.

        if (input < 1 || input > FindNumDigits(value)) {
            validSearch = false;
        }
        else {

            // Once a valid number is given, convert the character back to an int and return it.

            validSearch = true;

            string numString = to_string(value);

            if (value < 0) input++;

            found = (int)numString[input - 1] - 48;

        }

        if (!validSearch) cout << "\nERROR: Invalid position, try again." << endl;

    } while (!validSearch);

    return found;

}

void DisplayAdditionTable() {

    cout << "\nADDITION TABLE\n" << endl;

    cout << left;

    // Loop from 0-10 * 10. Add the row and column number, then display.

    for (int i = 0; i < 11; i++) {

        for (int j = 0; j < 11; j++) {

            cout << setw(5) << i + j;

        }
        cout << "\n";
    }

    cout << "\n---------------------------------------------------------\n" << endl;

}

void DisplayMultiplicationTable() {

    cout << "\nMULTIPLICATION TABLE\n" << endl;

    cout << left;

    // Loop from 0-10 * 10. Multiply the row and column number, then display.

    for (int i = 0; i < 11; i++) {

        for (int j = 0; j < 11; j++) {

            if (i == 0 && j == 0) {
                cout << setw(5) << 0; // Special case for the top left corner of the table.
            }
            else {
                cout << setw(5) << ((i == 0) ? 1 : i) * ((j == 0) ? 1 : j); // To prevent the first row and column from showing up as 0's, force 0's to be 1's.
            }
        }
        cout << "\n";
    }

    cout << "\n---------------------------------------------------------\n" << endl;

}