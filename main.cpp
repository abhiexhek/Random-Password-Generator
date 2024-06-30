#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

//selectArray is a utility function that is used to
//randomly generate an integer in the range 1 to 4 (both inclusive)
int selectArray()
{
    int i = rand() % 4 + 1;
    return i;
}

//getKey is another utility function that is used to randomly generate
//an integer in the range of 0 to max - 1 (both inclusive)
int getKey(int max)
{
    int key = rand() % max;
    return key;
}

void generate_password(int length)
{
    //Initializing result string password as NULL.
    string password = "";

    //string whose characters will be used to build a password
    string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    string s_symbol = "!@#$%&";
    string number = "0123456789";

    //initializing local variables
    int key, count_alphabet = 0, count_ALPHABET = 0, count_number = 0, count_s_symbol = 0;

    //Count will store the length of the password being created,
    //initially this will be zero(0)
    int count = 0;
    while (count < length)
    {
        int k = selectArray();

        if (count == 0)
        {
            k = k % 2 + 1; // Ensure the first character is a letter (1 or 2)
        }
        switch (k)
        {
        case 1:
            if ((count_alphabet == 2) && (count_number == 0 || count_ALPHABET == 0 || count_s_symbol == 0))
                break;
            key = getKey(alphabet.length());
            password = password + alphabet[key];
            count_alphabet++;
            count++;
            break;

        case 2:
            if ((count_ALPHABET == 2) && (count_number == 0 || count_alphabet == 0 || count_s_symbol == 0))
                break;
            key = getKey(ALPHABET.length());
            password = password + ALPHABET[key];
            count_ALPHABET++;
            count++;
            break;

        case 3:
            if ((count_number == 1) && (count_alphabet == 0 || count_ALPHABET == 0 || count_s_symbol == 0))
                break;
            key = getKey(number.length());
            password = password + number[key];
            count_number++;
            count++;
            break;

        case 4:
            if ((count_s_symbol == 1) && (count_alphabet == 0 || count_ALPHABET == 0 || count_number == 0))
                break;
            key = getKey(s_symbol.length());
            password = password + s_symbol[key];
            count_s_symbol++;
            count++;
            break;
        }
    }

    cout << "\n---------------------------\n";
    cout << "          Password          \n";
    cout << password;
    cout << "\n\nPress Enter to continue \n";
    cin.ignore();
    cin.get();
}

int main()
{
    srand(time(NULL));
    int option, length;
    //Menu
    do
    {
        cout << "\n--------------------------\n";
        cout << "  Random Password Generator\n";
        cout << "---------------------------\n\n";
        cout << "    1. Generate Password\n";
        cout << "    2. Exit\n\n";
        cout << "Press key 1 to Generate Password and key 2 to exit: ";
        cin >> option;

        switch (option)
        {
        case 1:
            cout << "Enter Length: ";
            cin >> length;

            if (length < 7)
            {
                cout << "\nError: Password Length Should be at least 7\n";
                cout << "Press Enter to try again \n";
                cin.ignore();
                cin.get();
            }
            else if (length > 100)
            {
                cout << "\nError: Maximum length of password should be 100\n";
                cout << "Press Enter to try again \n";
                cin.ignore();
                cin.get();
            }
            else
            {
                generate_password(length);
            }
            break;

        default:
            if (option != 2)
            {
                cout << "Invalid choice\n";
                cout << "Please Press ( 1 ) to generate password and  ( 2 ) to exit.\n";
                cout << "Press Enter to try again \n";
                cin.ignore();
                cin.get();
            }
            break;
        }

    } while (option != 2);
    return 0;
}
