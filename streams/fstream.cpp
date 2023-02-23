#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    //Listing 16.16 - Opening files for read and write.
    // char fileName[80];
    // char buffer[255];    // for user input
    // cout << "File name: ";
    // cin >> fileName;
    
    // ofstream fout(fileName);  // open for writing
    // fout << "This line written directly to the file...\n";
    // cout << "Enter text for the file: ";
    // cin.ignore(1,'\n');  // eat the newline after the file name
    // cin.getline(buffer,255);  // get the user's input
    // fout << buffer << "\n";   // and write it to the file
    // fout.close();             // close the file, ready for reopen

    // ifstream fin(fileName);    // reopen for reading
    // cout << "Here's the contents of the file:\n";
    // char ch;
    // while (fin.get(ch))
    //     cout << ch;

    // cout << "\n***End of file contents.***\n";

    // fin.close();            // always pays to be tidy

    // Listing 16.1 - Appending to the end of a file.
    char fileName[80];
    char buffer[255];
    cout << "Please enter the file name: ";
    cin >> fileName;

    ifstream fin(fileName);
    if (fin)                // already exists?
    {
        cout << "Current file contents:\n";
        char ch;
        while (fin.get(ch))
            cout << ch;
        cout << "\n***End of file contents.***\n";
    }
    fin.close();

    cout << "\nOpening " << fileName << " in append mode...\n";

    ofstream fout(fileName,ios::app);
    if (!fout)
    {
        cout << "Unable to open " << fileName << " for appending.\n";
        return(1);
    }

    cout << "\nEnter text for the file: ";
    cin.ignore(1,'\n');
    cin.getline(buffer,255);
    fout << buffer << "\n";
    fout.close();

    fin.open(fileName);  // reassign existing fin object!
    if (!fin)
    {
        cout << "Unable to open " << fileName << " for reading.\n";
        return(1);
    }
    cout << "\nHere's the contents of the file:\n";
    char ch;
    while (fin.get(ch))
        cout << ch;
    cout << "\n***End of file contents.***\n";
    fin.close();
}