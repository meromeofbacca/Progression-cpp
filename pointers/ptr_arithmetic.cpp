#include <stdio.h>
#include <iostream>
//create struct people
struct Person
{
    char name[64];
    int age;
};

int main()
{
    struct Person people[100];
    struct Person *p_Person = &people[0];  

    for(int i = 0; i < sizeof(people)/sizeof(people[0]); ++i){
        p_Person->age = i*i;
        p_Person+=1;
    }

    p_Person = &people[0];
    for(int i = 0; i < sizeof(people)/sizeof(people[0]); ++i){
        std::cout << "Age of person " << i+1 << ": " << p_Person->age << std::endl;
        p_Person += 1;
    }
}