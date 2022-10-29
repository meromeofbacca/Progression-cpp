#include <iostream>
#define PI (3.15)
#define SQUARE(x) ((x)*(x))
#define SMALLER(x,y) ((x) < (y))
using namespace std;

int main(){
    cout << PI << endl;
    cout << SQUARE(4) << endl;
    cout << SMALLER(4,50) << endl;
    cout << SMALLER(90,5) << endl;
}