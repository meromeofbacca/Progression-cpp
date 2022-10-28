#include <iostream>
using namespace std;

int main(){
    int value; 
    int sequence_cap = 2;
    int sequence_count = 0;
    while (sequence_count < sequence_cap)
    {
        cout << "Enter int sequence, q to end sequence:  ";
        while(cin >> value){
            cout << "Your sequence is: " << value << endl;
        }
        if(cin.fail()){
            cin.clear();
            cin.ignore(10000, '\n');
        }
        ++sequence_count;
    }    
}
