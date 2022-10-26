#include <iostream>
using namespace std;

int main(){
    int value; 
    // do{
    //     cout << "Enter int, -1 to quit program:  ";
    //     if(!(cin >> value)){ // if letter
    //         cout << "No letters please" << endl;
    //         cin.clear();
    //         cin.ignore(10000, '\n');
    //     }
    //     if(value != -1){
    //         cout << value << endl;
    //     }

    // }
    // while(value != -1);
    int sequence_cap = 2;
    int sequence_count = 0;
    while (sequence_count < sequence_cap)
    {
        cout << "gimme: \n";
        while(cin >> value){
            cout << value << endl;
            if(cin.fail()){
                cin.clear();
                cin.ignore(10000, '\n');
                string sentinel;
                cin >> sentinel;
            }
        }
        ++sequence_count;
    }
       
    
    
}