#include <iostream>
using namespace std;

int main(){
    int prime_count = 0;
    for(int i = 2; i <= 1000; ++i){
        bool isPrime = true;
        
        for(int j = 2; j < i/2 + 1; ++j){
            if(i%j == 0){
                isPrime = false;
                break;
            }  
        }
        
        if(isPrime){
            cout << i << endl;
            prime_count++;
        }
    }
    cout << "Prime count: " << prime_count << endl;
}