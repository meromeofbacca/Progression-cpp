#include <iostream>
#include <iomanip>
#include <string.h>
#include <string>
using namespace std;

int main()
{
    // Listing 16.10 - Using put()
    // cout.put('H').put('e').put('l').put('l').put('o').put('\n');

    // Listing 16.11 - Using write()
    // char One[] = "One if by land";
    // int fullLength = strlen(One);
    // int tooShort = fullLength -4;
    // int tooLong = fullLength + 6;
    // cout.write(One,fullLength) << "\n";
    // cout.write(One,tooShort) << "\n";
    // cout.write(One,tooLong) << "\n";

    // Listing 16.12 - Adjusting the width of output
    // cout << "Start >";
    // cout.width(25);
    // cout << 123 << "< End\n";
    // cout << "Start >";
    // cout.width(25);
    // cout << 123<< "< Next >";
    // cout << 456 << "< End\n";
    // cout << "Start >";
    // cout.width(4);
    // cout << 123456 << "< End\n";

    // Listing 16.3 - fill()
    // cout << "Start >";
    // cout.width(25);
    // cout << 123 << "< End\n";
    // cout << "Start >";
    // cout.width(25);
    // cout.fill('*');
    // cout << 123 << "< End\n";

    // Listing 16.14 - Using setf
    // const int number = 185;
    // cout << "The number is " << number << endl;
    // cout << "The number is " << hex <<  number << endl;

    // cout.setf(ios::showbase);
    // cout << "The number is " << hex <<  number << endl;

    // cout << "The number is " ;
    // cout.width(10);
    // cout << hex << number << endl;

    // cout << "The number is " ;
    // cout.width(10);
    // cout.setf(ios::left);
    // cout << hex << number << endl;

    // cout << "The number is " ;
    // cout.width(10);
    // cout.setf(ios::internal); //doesn't seem to work
    // cout << hex << number << endl;

    // cout << "The number is:" << setw(10) << hex << number << endl;

    //Listing 16.15 - Printing with printf().
    // printf("%s","hello world\n");
    // char * s = "Hello again!\n";
    // printf("%s", s);
    // int x = 5;
    // printf("%d\n",x);

    // char * phraseTwo = "Here's some values: ";
    // char * phraseThree = " and also these: ";
    // int y = 7, z = 35;
    // long longVar = 98456;
    // float floatVar =  8.8;

    // printf("%s %d %d %s %ld %f\n",phraseTwo,y,z,phraseThree,longVar,floatVar);

    // char * phraseFour = "Formatted: ";
    // printf("%s %5d %10d  %10.5f\n",phraseFour,y,z,floatVar);

    // string myString = "HEYA";
    // printf("%s BABE\n", myString.c_str());
}