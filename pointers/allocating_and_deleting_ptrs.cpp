#include <iostream>

int main(){
    unsigned short local_variable = 5;
    unsigned short *p_local_var = &local_variable;
    unsigned short *p_heap = new unsigned short;

    //Check if there is still heap memory 
    if(p_heap == NULL){
        std::cout << "NO MEMORY IN HEAP" << std::endl;
        return 0;
    }
    *p_heap = 7;

    //print them all out
    std::cout << "Value of local variable: " << local_variable << std::endl;
    std::cout << "Value of pointer to local variable: " << p_local_var << std::endl;
    std::cout << "Value of pointer to heap variable: " << p_heap << std::endl;
    std::cout << std::endl;

    //print out their "values"
    std::cout << "Actual value of local variable: " << local_variable << std::endl;
    std::cout << "Dereference of pointer to local variable: " << *p_local_var << std::endl;
    std::cout << "Dereference of pointer to heap variable: " << *p_heap << std::endl;
    std::cout << std::endl;

    //delete p_heap
    delete p_heap;
    p_heap = NULL;

    //assign new to p_heap
    p_heap = new unsigned short;
    if(p_heap == NULL){
        std::cout << "NO MEMORY IN HEAP" << std::endl;
        return 0;
    }
    *p_heap = 10;

    std::cout << "*p_heap: " << *p_heap << std::endl;
}