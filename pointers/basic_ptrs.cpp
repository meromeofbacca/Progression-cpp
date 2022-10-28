#include <iostream>

int main(){
    int x = 10;
    int *pX = &x;

    std::cout << "This is the value of x: " << x << std::endl;
    std::cout << "This is the value of pX: " << pX << std::endl;
    std::cout << "This is the address of x: " << &x << std::endl;
    std::cout << "This is the dereference of pX: " << *pX << std::endl;
    std::cout << "This is the address of pX: " << &pX << std::endl;
}