//Listing 9.9
// Returning multiple values from a function
// using references

#include <iostream.h>

typedef unsigned short USHORT;
enum ERR_CODE { SUCCESS, ERROR };

ERR_CODE Factor(USHORT, USHORT&, USHORT&);

int main()
{
    USHORT number, squared, cubed;
    ERR_CODE result;

    cout << "Enter a number (0 - 20): ";
    cin >> number;

    result = Factor(number, squared, cubed);

    if (result == SUCCESS)
    {
        cout << "number: " << number << "\n";
        cout << "square: " << squared << "\n";
        cout << "cubed: "  << cubed   << "\n";
    }
    else
        cout << "Error encountered!!\n";
    return 0;
    }

    ERR_CODE Factor(USHORT n, USHORT &rSquared, USHORT &rCubed)
    {
        if (n > 20)
            return ERROR;   // simple error code
        else
        {
            rSquared = n*n;
            rCubed = n*n*n;
            return SUCCESS;
        }
}