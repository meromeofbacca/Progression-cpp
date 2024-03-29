#define DemoVersion
#define DOS_VERSION 5
#include <iostream>
using namespace std;

int main()
{
    cout << "Checking on the definitions of DemoVersion, DOS_VERSION_ and WINDOWS_VERSION...\n";

    #ifdef DemoVersion
        cout << "DemoVersion defined.\n";
    #else
        cout << "DemoVersion not defined.\n";
    #endif
    #ifndef DOS_VERSION
        cout << "DOS_VERSION not defined!\n";
    #else
        cout << "DOS_VERSION defined as: " << DOS_VERSION << endl;
    #endif
    #ifdef WINDOWS_VERSION
        cout << "WINDOWS_VERSION defined!\n";
    #else
        cout << "WINDOWS_VERSION was not defined.\n";
    #endif
    cout << "Done.\n";
}