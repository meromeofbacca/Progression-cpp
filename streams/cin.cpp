#include <iostream>
#include <string>
using namespace std;

int main()
{
   // Listing 16.4 - Using get() with no parameters
   // char ch;
   // while ( (ch = cin.get()) != EOF)
   // {
   //    cout << "ch: " << ch << endl;
   // }
   // cout << "\nDone!\n";
   // Listing 16.5 - Using get() with parameters
   // char a, b, c;
   // cout << "Enter three letters: ";
   // cin.get(a).get(b).get(c);

   // cout << "a: " << a << "\nb: " << b << "\nc: " << c << endl;
   // Listing 16.6 - Using get() with a character array
   // char stringOne[256];
   // char stringTwo[256];
   // cout << "Enter string one: ";
   // cin.get(stringOne,256); // char arr and max characters
   // cout << "stringOne: " << stringOne << endl;
   // cout << "Enter string two: ";
   // cin >> stringTwo;
   // cout << "StringTwo: " << stringTwo << endl;

   // Listing 16.7 - Using getline()
   // char stringOne[256];
   // char stringTwo[256];
   // char stringThree[256];
   // cout << "Enter string one: ";
   // cin.getline(stringOne,256);
   // cout << "stringOne: " << stringOne << endl;
   // cout << "Enter string two: ";
   // cin >> stringTwo;
   // cout << "stringTwo: " << stringTwo << endl;
   // cout << "Enter string three: ";
   // cin.getline(stringThree,256);
   // cout << "stringThree: " << stringThree << endl; 

   // Listing 16.8 - Using ignore()
   // char stringOne[255];
   // char stringTwo[255];
   // cout << "Enter string one:";
   // cin.get(stringOne,255); //leaves new line in buffer
   // cout << "String one" << stringOne << endl;

   // cout << "Enter string two: ";
   // cin.getline(stringTwo,255);
   // cout << "String two: " << stringTwo << endl;

   // cout << "\n\nNow try again...\n";

   // cout << "Enter string one: ";
   // cin.get(stringOne,255);
   // cout << "String one: " << stringOne<< endl;

   // cin.ignore(255,'\n');

   // cout << "Enter string two: ";
   // cin.getline(stringTwo,255);
   // cout << "String Two: " << stringTwo<< endl;

   // Listing 16.9 - Using peek() and putback()
   char ch;
   cout << "Enter a phrase: ";
   while ( cin.get(ch) )
   {
      if (ch == '!')
         cin.putback('$');
      else
         cout << ch;
      while (cin.peek() == '#')
         cin.ignore(1,'#');
   }
}