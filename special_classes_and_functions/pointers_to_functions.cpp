#include <iostream>

using namespace std;
typedef void (*VPF)(int&, int&);

void Square(int&, int&);
void Cube(int&, int&);
void Swap(int&, int&);
void GetVals(int&, int&);
void PrintVals(VPF, int&, int&);
enum BOOL { FALSE, TRUE };

int main(){
    int MAX_ARRAY = 5;
    VPF pFunc;
    BOOL fQuit = FALSE;
    
    int valOne = 1, valTwo = 2;
    int choice;
    for(int i = 0; i < MAX_ARRAY; i++)
    {
        cout << "(0)Quit, (1)ChangeValues, (2)Square, (3)Cube, (4)Swap: \n";
        cin >> choice;
        switch (choice)
        {
            case 1: pFunc = GetVals; break;
            case 2: pFunc = Square; break;
            case 3: pFunc = Cube; break;
            case 4: pFunc = Swap; break;
            
            default: fQuit = TRUE;
                break;
        }
        if (fQuit) break;

        PrintVals(pFunc, valOne, valTwo);
    }
}

void PrintVals(VPF pFunc, int& x, int& y)
{
    cout << "x: " << x << " y: " << y << endl;
    pFunc(x,y);
    cout << "x: " << x << " y: " << y << endl;
}

void Square (int & rX, int & rY)
{
    rX *= rX;
    rY *= rY;
}

void Cube (int & rX, int & rY)
{
    int tmp;

    tmp = rX;
    rX *= rX;
    rX = rX * tmp;

    tmp = rY;
    rY *= rY;
    rY = rY * tmp;
}

void Swap(int & rX, int & rY)
{
    int temp;
    temp = rX;
    rX = rY;
    rY = temp;
}

void GetVals (int & rValOne, int & rValTwo)
{
    cout << "New value for ValOne: ";
    cin >> rValOne;
    cout << "New value for ValTwo: ";
    cin >> rValTwo;
}