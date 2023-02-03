//Listing 9.8
// Returning multiple values from a function
#include <iostream>
using namespace std;
typedef unsigned short USHORT;

short Factor(USHORT, USHORT*, USHORT*);

int main()
{
    USHORT number; // or USHORT number, squared, cubed; and pass squared and cubed addresses, remove dereference
    USHORT *squared = new USHORT;
    USHORT *cubed = new USHORT;
    short error;

    cout << "Enter a number (0 - 20): ";
    cin >> number;

    error = Factor(number, squared, cubed);

    if (!error)
    {
        cout << "number: " << number << "\n";
        cout << "square: " << *squared << "\n";
        cout << "cubed: "  << *cubed   << "\n";
    }
    else
        cout << "Error encountered!!\n";
        return 0;
    }

    short Factor(USHORT n, USHORT *pSquared, USHORT *pCubed)
    {
        short Value = 0;
        if (n > 20)
            Value = 1;
        else
        {
            *pSquared = n*n;
            *pCubed = n*n*n;
            Value = 0;
        }
    return Value;
}