#include <iostream>
using namespace std;

int main(){
    int prime_count = 0;
    int ceiling;
    cout << "Enter the ceiling: ";
    cin >> ceiling;
    
    for(int i = 2; i <= ceiling; ++i){
        bool isPrime = true;
        
        for(int j = 2; j < (i + 1)/2 ; ++j){
            if(i%j == 0){
                isPrime = false;
                break;
            }  
        }
        
        if(isPrime){
            cout << endl << i;
            prime_count++;
        }
    }
    cout << endl << "Prime count: " << prime_count << endl;
}