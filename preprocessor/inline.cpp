#include <iostream>
inline unsigned long Square(unsigned long a) { return a * a; }
inline unsigned long Cube(unsigned long a) { return a * a * a; }
using namespace std;

int main()
{
    unsigned long x=1 ;
    for (;;)
    {
        cout << "Enter a number (0 to quit): ";
        cin >> x;
        if (x == 0)
        break;
        cout << "You entered: " << x;
        cout << ".  Square(" << x << "): ";
        cout  << Square(x);
        cout<< ". Cube(" << x << "): ";
        cout << Cube(x) << "." << endl;
    }
}