#include <stdio.h>
typedef char* ptr;
#define PTR char*

int main()
{
    ptr a, b, c;
    PTR x, y, z;
    printf("sizeof a:%zu\n" ,sizeof(a) );
    printf("sizeof b:%zu\n" ,sizeof(b) );
    printf("sizeof c:%zu\n" ,sizeof(c) );
    printf("sizeof x:%zu\n" ,sizeof(x) );
    printf("sizeof y:%zu\n" ,sizeof(y) );
    printf("sizeof z:%zu\n" ,sizeof(z) );
    return 0;
    /*
    Experiment:
    Replaced char* using typedef and #define.
    Saw that using typedef:
    ptr a, b, c; = char* a, char* b, char* c;
    
    but using #define:
    PTR x, y, z; = char* x, y, z;  
    //So x is char pointer but y and z are char variables.
    //Pointer size is 8 bytes but char types are 1 byte.


    Learned: 
    #define is for preprocessor macros: is basically a search and replace tool. 
    Can be used to define constants that are used in compile time. Constants can be used with
    #ifdef to see how code is compiled.
    Hides semantics from compiler.


    typedef is a compiler token: is a C language feature that lets you create aliases for types.
    Useful to make complicated types (structs and pointers) readable and handlable. 
    There might be situations where you must typedef a type.
    Can use forward declaration with typedef to declare a type that will be used, but isn't linked to file yet.

    Conclusion: 
    typedef is more stable than #define for search and replace.

    Sources:
    https://www.geeksforgeeks.org/typedef-versus-define-c/#:~:text=Difference%20between%20typedef%20and%20%23define,%2C%203.14%20as%20PI%2C%20etc.
    https://stackoverflow.com/questions/1666353/are-typedef-and-define-the-same-in-c

    */
}