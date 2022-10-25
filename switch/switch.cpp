#include <iostream>

int main(){
    int digit = 0;
    std::string digit_name;
    
    do{
        std::cout << "Enter a digit from 0-9 \n";
        std::cin >> digit;
    }
    while(digit < 0 || digit > 9); //out of range 

    switch(digit){
        case 1: digit_name = "one"; break;
        case 2: digit_name = "two"; break;
        case 3: digit_name = "three"; break;
        case 4: digit_name = "four"; break;
        case 5: digit_name = "five"; break;
        case 6: digit_name = "six"; break;
        case 7: digit_name = "seven"; break;
        case 8: digit_name = "eight"; break;
        case 9: digit_name = "nine"; break;
    }

    printf("Your digit is: %s\n", digit_name.c_str());
}